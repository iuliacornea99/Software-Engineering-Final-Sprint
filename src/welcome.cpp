#include "welcome.h"
#include "ui_welcome.h"
#include "window.h"
#include "QFileDialog"
#include "request.h"
#include "highscore.h"

Welcome::Welcome(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);
    this->api = new Request();
    this->loadHighScores();
}

void Welcome::loadHighScores() {

    ui->highscoreTable->clear();
    ui->highscoreTable->setText("Loading...");

    QString s = "";
    std::vector<Highscore> hs = this->api->getHighscores();
    int i = 0;
    for(auto iter = hs.begin(); iter != hs.end(); iter++){
        s += QString::number(i+1) + ". ";
        s += iter->gameUser + ": ";
        s += QString::number(iter->score) + '\n';
        i++;
        if(i==10){
            break;
        }
    }

    ui->highscoreTable->clear();
    ui->highscoreTable->setText(s);
}

Welcome::~Welcome()
{
    delete this->api;
    delete ui;
}

void Welcome::on_play_clicked()
{
    if(this->setNextWindow()) {
        this->hide();
        this->next->show();
    }
}

bool Welcome::setNextWindow(bool load)
{
    Window *m;
    m = new(Window);
    m->hide();
    m->setParent(this);
    this->next = m;
    if (load) {
        QString filename = QFileDialog::getOpenFileName(this,
                                                        tr("Load Game"),
                                                        "",
                                                        tr("Pencil File (*.sav)"));

        if(filename.isNull() || filename.isEmpty()) {
            fprintf(stderr, "No file selected\n");
            return false;
        } else {
            m->readSettings(filename);
        }
    }
    return true;
}

void Welcome::on_load_clicked()
{
    if(this->setNextWindow(true)) {
        this->hide();
        this->next->show();
    }
}

void Welcome::on_refresh_button_clicked() {
    this->loadHighScores();
}
