/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ui_window.h"
#include "window.h"
#include <cmath>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include "request.h"
#include "welcome.h"
#include "endgame.h"

#define MAX_MARKETING                       30
#define MAX_INTELLIGENCE                    200
#define INCREASE_MARKETING_DEBUG            3
#define INCREASE_INTELLIGENCE_DEBUG         10
#define INCREASE_PENCILS_INVENTORY_DEBUG    1000
#define NO_PENCILS_END_GAME                 25000

bool gameclosureok = false;

Window::Window(QWidget *parent) :
  QWidget(parent),
  widget(new Ui::Window) {

    // readSettings();
    widget->setupUi(this);

    /* setting all the labels of ui objects to default values
     * while initializing user interface
     */
    updateresourcepricelabels();
    updatebalancelabel();
    updatepencillabels();
    updateresourcelabels();
    updateapmlabels();
    updatepencilpricelabel();
    toggle_buttons();

    /* ui objects that should not be visible, enabled or checked
     * in the beginning
     */
    widget->intelligence->setVisible(false);
    widget->intelligence_number->setVisible(false);
    widget->debug_balance->setVisible(false);
    widget->debug_pencils->setVisible(false);
    widget->debug_resource->setVisible(false);
    widget->marketing->setVisible(false);
    widget->upgradeapm->setEnabled(false);
    widget->debugtool->setChecked(false);
    widget->marketing->setEnabled(false);
    widget->incmarketing->setEnabled(false);
    widget->intelligence_debug_button->setVisible(false);
    widget->marketing_debug_button->setVisible(false);
    widget->pencils_inventory_debug_button->setVisible(false);
    widget->marketing_label->setVisible(false);
    widget->marketing_amount_label->setVisible(false);
    //widget->marketing_debug_button->setEnabled(false);
    //widget->intelligence_debug_button->setEnabled(false);
    toggle_buttons();

    //setup make pencile button
    QObject::connect(widget->makepencils_button,SIGNAL(clicked()),this,SLOT(make_penciles()));

    //setup material buy buttons
    QObject::connect(widget->buywood_button,SIGNAL(clicked()),this,SLOT(buy_wood()));
    QObject::connect(widget->buygraphite_button,SIGNAL(clicked()),this,SLOT(buy_graphite()));
    QObject::connect(widget->buyautopencil_button,SIGNAL(clicked()),this,SLOT(buy_autopencile()));
    QObject::connect(widget->marketing,SIGNAL(clicked()),this,SLOT(buy_marketing()));
    QObject::connect(widget->upgradeapm,SIGNAL(clicked()),this,SLOT(upgradeAPM()));
    QObject::connect(widget->incmarketing,SIGNAL(clicked()),this,SLOT(increase_marketing()));

    //setup resource price timer
    resource_price_timer = new QTimer(this);
    QObject::connect(resource_price_timer,SIGNAL(timeout()),this,SLOT(updateresourcepricelabels()));
    resource_price_timer->start(5000);

    /* calls respective slots when increase or decrease price of pencil button is clicked */
    QObject::connect(widget->price_increase_button,SIGNAL(clicked()),this,SLOT(increase_price()));
    QObject::connect(widget->price_decrease_button,SIGNAL(clicked()),this,SLOT(decrease_price()));

    /* calls respective slots when debugging is checked and debugging tools are clicked */
    QObject::connect(widget->debugtool,SIGNAL(clicked(bool)),this,SLOT(debuggingtool(bool)));
    QObject::connect(widget->debug_pencils,SIGNAL(clicked()),this,SLOT(pencil_debug()));
    QObject::connect(widget->debug_resource,SIGNAL(clicked()),this,SLOT(resource_debug()));
    QObject::connect(widget->debug_balance,SIGNAL(clicked()),this,SLOT(balance_debug()));


    /* calls produce_pencils() every second */
    autopencile_timer = new QTimer(this);
    QObject::connect(autopencile_timer,SIGNAL(timeout()),this,SLOT(produce_pencils()));
    autopencile_timer->start(1000);

    /* calls sell_penciles() every second */
    sell_timer = new QTimer(this);
    QObject::connect(sell_timer,SIGNAL(timeout()),this,SLOT(sell_penciles()));
    sell_timer->start(1000);

    /* calls unlockintelligence() every second */
    intelligence_timer = new QTimer(this);
    QObject::connect(intelligence_timer,SIGNAL(timeout()),this,SLOT(unlockintelligence()));
    intelligence_timer->start(1000);

    this->api = new Request();
    /* calls gameclosure() every */
    gameclosure_timer = new QTimer(this);
    QObject::connect(gameclosure_timer,SIGNAL(timeout()),this,SLOT(gameclosure()));
    gameclosure_timer->start(100);

}


/* actions that need to be take when make pencil button is clicked */
bool Window::make_penciles(){
    toggle_buttons();
    if(productions.wood_left < 0.21 || productions.graphite_left < 0.20){
        return false;
    } else {
        productions.remove_wood(0.21);
        productions.remove_graphite(0.20);
        pencils.increase_pencil_inv();
        updatepencillabels();
        updateresourcelabels();
    }
    toggle_buttons();
    return true;
}

/* actions that need to be take when buy wood button is clicked */
bool Window::buy_wood(){
    toggle_buttons();
    if(productions.price_wood > balance.bank_balance){
        return false;
    } else {
        balance.reduce_money(productions.price_wood);
        productions.add_wood(100.0);
        updatebalancelabel();
        updateresourcelabels();
    }
    toggle_buttons();
    return true;
}

/* actions that need to be taken when buy graphite button is clicked */
bool Window::buy_graphite(){
    toggle_buttons();
    if(productions.price_graphite > balance.bank_balance){
        return false;
    } else {
        balance.reduce_money(productions.price_graphite);
        productions.add_graphite(100.0);
        updatebalancelabel();
        updateresourcelabels();
    }
    toggle_buttons();
    return true;
}

/* actions that need to be taken when increase price of pencil button is clicked */
bool Window::increase_price(){
    toggle_buttons();
    sales.increaseprice();
    updatepencilpricelabel();
    toggle_buttons();
    return true;
}

/* actions that need to be taken when decrease price of pencil button is clicked */
bool Window::decrease_price(){
    toggle_buttons();
    if(sales.price < MIN_PENCIL_PRICE){
        return false;
    } else {
        sales.decreaseprice();
        updatepencilpricelabel();
    }
    toggle_buttons();
    return true;
}

/* function to produce pencil every second using APM */
bool Window::produce_pencils(){
    toggle_buttons();
    double production_rate = apm.getNumberOfAutopenciles()*apm.getPencilsPerSecond();
    if(production_rate*WOOD_PER_PENCIL > productions.wood_left
            || production_rate*GRAPHITE_PER_PENCIL > productions.graphite_left){
        return false;
    } else {
        productions.remove_wood(production_rate*WOOD_PER_PENCIL);
        productions.remove_graphite(production_rate*GRAPHITE_PER_PENCIL);
        pencils.increase_pencil_inv(static_cast<int>(production_rate));
        updatepencillabels();
        updateresourcelabels();
    }
    toggle_buttons();
    return true;
}

/* actions that need to be taken when buy APM button is clicked */
bool Window::buy_autopencile(){
    toggle_buttons();
    if(apm.getNumberOfAutopenciles() >= MAX_APMS){
        return false;
    } else if (apm.getPriceAutopencile() > balance.bank_balance){
        return false;
    } else {
        balance.reduce_money(apm.getPriceAutopencile());
        apm.increaseautopencil();
        updateapmlabels();
        updatebalancelabel();
    }
    toggle_buttons();
    return true;
}

/* function to sell pencils every second according to public demand */
bool Window::sell_penciles(){
    toggle_buttons();
    int rate_per_sec = static_cast<int>(std::floor((sales.public_demand)*5));
    if(rate_per_sec > pencils.inventory){
        return false;
    } else {
        pencils.inventory-=rate_per_sec;
        balance.add_money(rate_per_sec*sales.price);
        updatepencillabels();
        updatebalancelabel();
    }
    toggle_buttons();
    return true;

}

/* function to unlock intelligence after total pencils produced is
   reached 300 and to generate intelligence every second */
bool Window::unlockintelligence(){
    toggle_buttons();
    if (pencils.lifetime_produced < 3000 || balance.intelligence >= 200){
        return false;
    }
    balance.increaseintelligence();
    updateintelligencelabel();
    updateBuyMarketingLabel();
    toggle_buttons();
    return true;
}

/* actions that need to be taken when buy marketing button is clicked */
bool Window::buy_marketing(){
    if (balance.intelligence < 100){
        return false;
    }
    sales.buymarketing = 1;
    balance.decreaseintelligence(100);
    updateincreasemarketinglabel();
    widget->marketing->setEnabled(false);
    return true;

}

/* actions that need to be taken when increase marketing button is clicked */
bool Window::increase_marketing()
{
    toggle_buttons();
    if (balance.bank_balance < sales.marketing_price && sales.marketing < MAX_MARKETING){
        return false;
        widget->incmarketing->setEnabled(false);
    }
    sales.increasemarketing();
    balance.reduce_money(sales.marketing_price);
    updatebalancelabel();
    sales.increasingmarketingprice();
    updateincreasemarketinglabel();
    updatepencilpricelabel();
    toggle_buttons();
    return true;
}

/* actions that need to be taken when upgrade APM button is clicked */
bool Window::upgradeAPM()
{
    toggle_buttons();
    if (balance.intelligence < apm.getRequiredIntelligence()){
        return false;
    }
    apm.increase_pencils_per_second();
    balance.decreaseintelligence(apm.getRequiredIntelligence());
    updateintelligencelabel();
    updateapmlabels();
    apm.increase_required_intelligence();
    toggle_buttons();
    return true;

}

/* actions that need to be taken when debugging tool is checked */
void Window::debuggingtool(bool checked)
{
    if (checked){
        widget->debug_resource->setVisible(true);
        widget->debug_balance->setVisible(true);
        widget->debug_pencils->setVisible(true);
        widget->intelligence_debug_button->setVisible(true);
        widget->marketing_debug_button->setVisible(true);
        widget->pencils_inventory_debug_button->setVisible(true);
    }
    else{
        widget->debug_resource->setVisible(false);
        widget->debug_balance->setVisible(false);
        widget->debug_pencils->setVisible(false);
        widget->intelligence_debug_button->setVisible(false);
        widget->marketing_debug_button->setVisible(false);
        widget->pencils_inventory_debug_button->setVisible(false);
    }

}

/* debugging tool to increase the number of pencils in inventory
   and total pencils manufactured by 1000 when pencil debugging is clicked */
void Window::pencil_debug()
{
    pencils.increase_pencil_inv(1000);
    updatepencillabels();
}

/* debugging tool to grant grant the player 10m of wood and granite
   when resource debugging button is clicked */
void Window::resource_debug()
{
    productions.add_wood(1000);
    productions.add_graphite(1000);
    updateresourcelabels();
}

/* debugging tool to grant the player $1000 when balance debugging
   button is clicked */
void Window::balance_debug()
{
    balance.add_money(10000);
    updatebalancelabel();
}

/* function to check whether buttons should be disabled or not */
void Window::toggle_buttons(){
    //disable/enable "buy material buttons
    if(productions.price_graphite>balance.bank_balance){
        widget->buygraphite_button->setEnabled(false);
    } else {
        widget->buygraphite_button->setEnabled(true);
    }

    if(productions.price_wood>balance.bank_balance){
        widget->buywood_button->setEnabled(false);
    } else {
        widget->buywood_button->setEnabled(true);
    }

    if(apm.getPriceAutopencile() > balance.bank_balance
            || apm.getNumberOfAutopenciles() >= MAX_APMS){
        widget->buyautopencil_button->setEnabled(false);
    } else {
        widget->buyautopencil_button->setEnabled(true);
    }

    if(productions.wood_left < 0.21 || productions.graphite_left < 0.20){
        widget->makepencils_button->setEnabled(false);
    } else {
        widget->makepencils_button->setEnabled(true);
    }

    if (balance.bank_balance < sales.marketing_price || sales.marketing >= MAX_MARKETING || sales.buymarketing == 0){
         widget->incmarketing->setEnabled(false);
    } else {
        widget->incmarketing->setEnabled(true);
    }

    if (pencils.lifetime_produced >= 3000 || pencils.lifetime_produced >= 5000){
        if (pencils.lifetime_produced >= 3000 && pencils.lifetime_produced <= 5000 &&
            balance.intelligence >= apm.getRequiredIntelligence()
                && apm.getRequiredIntelligence() == 2.00){
                widget->upgradeapm->setEnabled(true);
        }
        else if (pencils.lifetime_produced >= 5000 && balance.intelligence >= apm.getRequiredIntelligence() &&
                 (apm.getPencilsPerSecond() == 2.00 || apm.getPencilsPerSecond() == 2.20)){
                widget->upgradeapm->setEnabled(true);
        }
        else {
            widget->upgradeapm->setEnabled(false);
        }
    }

    if (balance.intelligence >= 100 && sales.buymarketing == 0){
        widget->marketing->setEnabled(true);
    }

}

/* function to update price of graphite and wood every
   5 seconds in user interface */
void Window::updateresourcepricelabels(){
    toggle_buttons();
    productions.update_price();
    widget->buygraphite_button->setText(QString("Buy Graphite\n$%1 / 100.00 m").arg(productions.price_graphite));
    widget->buywood_button->setText(QString("Buy Wood\n$%1 / 100.00 m").arg(productions.price_wood));
    toggle_buttons();
}

/* destructor of main window */
Window::~Window() {
    delete this->api;
    delete widget;
}

/* function to update pencils in our inventory and total
   pencils produced in user interface */
void Window::updatepencillabels()
{
    widget->pencilinventory_int->setText(QString::number(pencils.inventory));
    widget->pencilsproduced_int->setText(QString::number(pencils.lifetime_produced));
}

/* function to update bank balance in user interface */
void Window::updatebalancelabel()
{
     widget->bankbalance_int->setText("$ " + QString::number(balance.bank_balance,'f',2));//init bank balance
}

/* function to update wood left, graphite left in user interface */
void Window::updateresourcelabels()
{
    widget->woodleft_int->setText(QString::number(productions.wood_left,'f',2));//init wood inventory
    widget->graphiteleft_int->setText(QString::number(productions.graphite_left,'f',2));//init graphite inventory
}

/* function to update APM rate, total APM and buy APM in user interface */
void Window::updateapmlabels()
{
    widget->autopencil_int->setText(QString::number(apm.getNumberOfAutopenciles()));
    widget->autopencilrate_int->setText(
                QString::number(
                    apm.getNumberOfAutopenciles()*apm.getPencilsPerSecond()*60,'f',2
                    )
                );
    widget->buyautopencil_button->setText(
                QString("Buy more\n$%1").arg(apm.getPriceAutopencile())
                );
}

/* function to update demand and price of pencil in user interface */
void Window::updatepencilpricelabel()
{
    widget->publicdemand_int->setText(QString::number(sales.public_demand,'f',2));
    widget->price_int->setText(QString::number(sales.price,'f',2));

}

/* function to set visibility and update intelligence in user interface */
void Window::updateintelligencelabel()
{
    widget->intelligence->setVisible(true);
    widget->intelligence_number->setVisible(true);
    widget->intelligence_number->setText(QString::number(balance.intelligence));
}

/* function to update buy marketing button in user interface */
void Window::updateBuyMarketingLabel()
{
    if (sales.buymarketing){
        widget->marketing->setEnabled(false);
        widget->marketing_label->setVisible(true);
        widget->marketing_amount_label->setVisible(true);
        widget->marketing_amount_label->setText(QString::number(sales.marketing));
    }
    else{
        widget->marketing->setVisible(true);
    }
}

void Window::updateincreasemarketinglabel()
{
    widget->incmarketing->setText("Buy More Marketing\n Price: "+ QString::number(sales.marketing_price));
}

void Window::writeSettings(QString &filename){

    /* Post the score online */
    this->api->postScore(pencils.lifetime_produced);

    QFile file(filename);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        stream << apm.getPriceAutopencile() << endl;
        stream << apm.getPencilsPerSecond() << endl;
        stream << apm.getRequiredIntelligence() << endl;
        stream << apm.getNumberOfAutopenciles() << endl;
        stream << pencils.inventory << endl;
        stream << pencils.lifetime_produced << endl;
        stream << productions.wood_left << endl;
        stream << productions.price_wood << endl;
        stream << productions.graphite_left << endl;
        stream << productions.price_graphite << endl;
        stream << sales.price << endl;
        stream << sales.marketing << endl;
        stream << sales.public_demand << endl;
        stream << sales.marketing_price << endl;
        stream << balance.bank_balance << endl;
        stream << balance.intelligence << endl;
        stream << sales.buymarketing;
    }
    file.close();
}

/* function to read the previous state of the program */
void Window::readSettings()
{
}

void Window::readSettings(QString &filename){
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly)){
        QTextStream in(&file);
        apm.setPriceAutopencile((in.readLine()).toDouble());
        apm.setPencilsPerSecond((in.readLine()).toDouble());
        apm.setRequiredIntelligence((in.readLine()).toInt());
        apm.setNumberOfAutopenciles((in.readLine()).toInt());
        pencils.inventory = (in.readLine()).toInt();
        pencils.lifetime_produced = (in.readLine()).toInt();
        productions.wood_left = (in.readLine()).toDouble();
        productions.price_wood = (in.readLine()).toDouble();
        productions.graphite_left = (in.readLine()).toDouble();
        productions.price_graphite = (in.readLine()).toDouble();
        sales.price = (in.readLine()).toDouble();
        sales.marketing = (in.readLine()).toInt();
        sales.public_demand = (in.readLine()).toDouble();
        sales.marketing_price = (in.readLine()).toDouble();
        balance.bank_balance = (in.readLine()).toDouble();
        balance.intelligence = (in.readLine()).toInt();
        sales.buymarketing = (in.readLine()).toInt();
    }
    file.close();
    updateresourcepricelabels();
    updatebalancelabel();
    updatepencillabels();
    updateresourcelabels();
    updateapmlabels();
    updatepencilpricelabel();
    toggle_buttons();
}

/* function to describe a close event of a program */
void Window::closeEvent(QCloseEvent *event)
{
    // writeSettings();
    event->accept();
}

void Window::on_saveBtn_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this,
                                                    tr("Save Game"),
                                                    "untitled.sav",
                                                    tr("Pencil File (*.sav)"));

    if(filename.isNull() || filename.isEmpty()) {
        fprintf(stderr, "File error. Not saved.\n");
        return;
    } else {
        this->writeSettings(filename);
    }
}


void Window::on_loadBtn_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Load Game"),
                                                    "",
                                                    tr("Pencil File (*.sav)"));

    if(filename.isNull() || filename.isEmpty()) {
        fprintf(stderr, "No file selected\n");
        return;
    } else {
        this->readSettings(filename);
    }
}

void Window::on_exitButton_clicked()
{
    this->hide();
    this->parent->show();
    // TODO: Make high scroes load on coming back to the start screen.
    this->close();
}

void Window::setParent(QWidget *p)
{
    this->parent = p;
}

void Window::callLoadFunction()
{
    this->on_loadBtn_clicked();
}

void Window::on_intelligence_debug_button_clicked()
{
    if(unlockintelligence()==true && balance.intelligence <= 200)
    {
        balance.intelligence += 10;
        updatebalancelabel();
    }
}


void Window::on_marketing_debug_button_clicked()
{
    toggle_buttons();
    if(sales.marketing < MAX_MARKETING && sales.buymarketing == 1)
    {
        sales.marketing += INCREASE_MARKETING_DEBUG;
        updateBuyMarketingLabel();
        widget->marketing_amount_label->setText(QString::number(sales.marketing));
    }
}

void Window::on_pencils_inventory_debug_button_clicked()
{
    pencils.increase_pencil_inv(INCREASE_PENCILS_INVENTORY_DEBUG);
    updatepencillabels();
}


void Window::gameclosure()
{
    if(pencils.lifetime_produced > NO_PENCILS_END_GAME && gameclosureok ==false)
    {
        gameclosureok = true;
        this->hide();
        Endgame *m;
        m = new(Endgame);
        m->show();
    }
}


