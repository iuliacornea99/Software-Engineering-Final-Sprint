/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QLabel *intelligence;
    QLabel *intelligence_number;
    QPushButton *marketing;
    QPushButton *upgradeapm;
    QCheckBox *debugtool;
    QPushButton *makepencils_button;
    QWidget *layoutWidget1;
    QHBoxLayout *autopencilrate_layout;
    QLabel *autopencilrate_label1;
    QLabel *autopencilrate_int;
    QLabel *autopencilrate_label2;
    QWidget *layoutWidget2;
    QHBoxLayout *autopencil_layout;
    QLabel *autopencil_label;
    QLabel *autopencil_int;
    QLabel *bankbalance_label;
    QPushButton *buyautopencil_button;
    QLabel *bankbalance_int;
    QPushButton *debug_pencils;
    QPushButton *debug_balance;
    QPushButton *debug_resource;
    QPushButton *incmarketing;
    QPushButton *saveBtn;
    QPushButton *loadBtn;
    QPushButton *exitButton;
    QPushButton *intelligence_debug_button;
    QPushButton *marketing_debug_button;
    QPushButton *pencils_inventory_debug_button;
    QLabel *marketing_label;
    QLabel *marketing_amount_label;
    QPushButton *buywood_button;
    QPushButton *buygraphite_button;
    QWidget *layoutWidget;
    QHBoxLayout *publicdemand_layout;
    QLabel *publicdemand_label;
    QLabel *publicdemand_int;
    QLabel *main_title;
    QWidget *layoutWidget3;
    QHBoxLayout *pencilinventory_layout;
    QLabel *pencilinventory_label;
    QLabel *pencilinventory_int;
    QWidget *layoutWidget4;
    QHBoxLayout *woodleft_layout;
    QLabel *wooleft_label;
    QLabel *woodleft_int;
    QWidget *layoutWidget5;
    QHBoxLayout *graphiteleft_layout;
    QLabel *graphiteleft_label;
    QLabel *graphiteleft_int;
    QLabel *pencilsproduced_label;
    QLabel *pencilsproduced_int;
    QLabel *price_label;
    QLabel *price_int;
    QPushButton *price_increase_button;
    QPushButton *price_decrease_button;
    QLabel *label;

    void setupUi(QWidget *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QStringLiteral("Window"));
        Window->resize(889, 716);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Window->sizePolicy().hasHeightForWidth());
        Window->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(15);
        Window->setFont(font);
        Window->setStyleSheet(QStringLiteral("background-color: rgb(202, 241, 255)"));
        intelligence = new QLabel(Window);
        intelligence->setObjectName(QStringLiteral("intelligence"));
        intelligence->setGeometry(QRect(500, 170, 106, 22));
        QFont font1;
        font1.setPointSize(14);
        intelligence->setFont(font1);
        intelligence_number = new QLabel(Window);
        intelligence_number->setObjectName(QStringLiteral("intelligence_number"));
        intelligence_number->setGeometry(QRect(620, 170, 58, 22));
        intelligence_number->setFont(font1);
        marketing = new QPushButton(Window);
        marketing->setObjectName(QStringLiteral("marketing"));
        marketing->setGeometry(QRect(680, 110, 181, 41));
        marketing->setFont(font1);
        marketing->setCursor(QCursor(Qt::PointingHandCursor));
        marketing->setStyleSheet(QStringLiteral("background-color: rgb(138, 226, 52);"));
        upgradeapm = new QPushButton(Window);
        upgradeapm->setObjectName(QStringLiteral("upgradeapm"));
        upgradeapm->setGeometry(QRect(660, 350, 131, 41));
        upgradeapm->setFont(font1);
        upgradeapm->setCursor(QCursor(Qt::PointingHandCursor));
        upgradeapm->setStyleSheet(QStringLiteral("background-color: rgb(114, 159, 207);"));
        debugtool = new QCheckBox(Window);
        debugtool->setObjectName(QStringLiteral("debugtool"));
        debugtool->setGeometry(QRect(500, 420, 175, 28));
        debugtool->setFont(font1);
        debugtool->setStyleSheet(QStringLiteral(""));
        makepencils_button = new QPushButton(Window);
        makepencils_button->setObjectName(QStringLiteral("makepencils_button"));
        makepencils_button->setGeometry(QRect(500, 20, 131, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Ubuntu"));
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(7);
        makepencils_button->setFont(font2);
        makepencils_button->setCursor(QCursor(Qt::PointingHandCursor));
        makepencils_button->setStyleSheet(QLatin1String("background-color: rgb(43, 134, 224);\n"
"font: 57 11pt \"Ubuntu\";\n"
"color: rgb(0, 0, 0)"));
        layoutWidget1 = new QWidget(Window);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(500, 290, 256, 27));
        layoutWidget1->setFont(font1);
        autopencilrate_layout = new QHBoxLayout(layoutWidget1);
        autopencilrate_layout->setObjectName(QStringLiteral("autopencilrate_layout"));
        autopencilrate_layout->setContentsMargins(0, 0, 0, 0);
        autopencilrate_label1 = new QLabel(layoutWidget1);
        autopencilrate_label1->setObjectName(QStringLiteral("autopencilrate_label1"));
        autopencilrate_label1->setFont(font1);

        autopencilrate_layout->addWidget(autopencilrate_label1);

        autopencilrate_int = new QLabel(layoutWidget1);
        autopencilrate_int->setObjectName(QStringLiteral("autopencilrate_int"));
        QFont font3;
        font3.setFamily(QStringLiteral("Ubuntu"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(7);
        autopencilrate_int->setFont(font3);
        autopencilrate_int->setStyleSheet(QStringLiteral("font: 57 12pt \"Ubuntu\";"));

        autopencilrate_layout->addWidget(autopencilrate_int);

        autopencilrate_label2 = new QLabel(layoutWidget1);
        autopencilrate_label2->setObjectName(QStringLiteral("autopencilrate_label2"));
        autopencilrate_label2->setFont(font1);

        autopencilrate_layout->addWidget(autopencilrate_label2);

        layoutWidget2 = new QWidget(Window);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(500, 250, 228, 27));
        layoutWidget2->setFont(font1);
        autopencil_layout = new QHBoxLayout(layoutWidget2);
        autopencil_layout->setObjectName(QStringLiteral("autopencil_layout"));
        autopencil_layout->setContentsMargins(0, 0, 0, 0);
        autopencil_label = new QLabel(layoutWidget2);
        autopencil_label->setObjectName(QStringLiteral("autopencil_label"));
        autopencil_label->setFont(font1);
        autopencil_label->setStyleSheet(QStringLiteral(""));

        autopencil_layout->addWidget(autopencil_label);

        autopencil_int = new QLabel(layoutWidget2);
        autopencil_int->setObjectName(QStringLiteral("autopencil_int"));
        autopencil_int->setFont(font3);
        autopencil_int->setStyleSheet(QStringLiteral("font: 57 12pt \"Ubuntu\";"));

        autopencil_layout->addWidget(autopencil_int);

        bankbalance_label = new QLabel(Window);
        bankbalance_label->setObjectName(QStringLiteral("bankbalance_label"));
        bankbalance_label->setGeometry(QRect(498, 67, 120, 22));
        bankbalance_label->setFont(font1);
        buyautopencil_button = new QPushButton(Window);
        buyautopencil_button->setObjectName(QStringLiteral("buyautopencil_button"));
        buyautopencil_button->setGeometry(QRect(500, 350, 131, 42));
        buyautopencil_button->setFont(font2);
        buyautopencil_button->setCursor(QCursor(Qt::PointingHandCursor));
        buyautopencil_button->setStyleSheet(QLatin1String("background-color: rgb(245, 121, 0);\n"
"font: 57 11pt \"Ubuntu\";\n"
"color: rgb(0, 0, 0)"));
        bankbalance_int = new QLabel(Window);
        bankbalance_int->setObjectName(QStringLiteral("bankbalance_int"));
        bankbalance_int->setGeometry(QRect(630, 70, 112, 19));
        bankbalance_int->setFont(font3);
        bankbalance_int->setStyleSheet(QStringLiteral("font: 57 12pt \"Ubuntu\";"));
        debug_pencils = new QPushButton(Window);
        debug_pencils->setObjectName(QStringLiteral("debug_pencils"));
        debug_pencils->setGeometry(QRect(500, 460, 91, 31));
        debug_pencils->setFont(font1);
        debug_pencils->setCursor(QCursor(Qt::PointingHandCursor));
        debug_pencils->setStyleSheet(QStringLiteral("background-color: rgb(114, 159, 207);"));
        debug_balance = new QPushButton(Window);
        debug_balance->setObjectName(QStringLiteral("debug_balance"));
        debug_balance->setGeometry(QRect(590, 460, 91, 31));
        debug_balance->setFont(font1);
        debug_balance->setCursor(QCursor(Qt::PointingHandCursor));
        debug_balance->setStyleSheet(QStringLiteral("background-color: rgb(173, 127, 168);"));
        debug_resource = new QPushButton(Window);
        debug_resource->setObjectName(QStringLiteral("debug_resource"));
        debug_resource->setGeometry(QRect(680, 460, 191, 31));
        debug_resource->setFont(font1);
        debug_resource->setCursor(QCursor(Qt::PointingHandCursor));
        debug_resource->setStyleSheet(QStringLiteral("background-color: rgb(233, 185, 110);"));
        incmarketing = new QPushButton(Window);
        incmarketing->setObjectName(QStringLiteral("incmarketing"));
        incmarketing->setGeometry(QRect(500, 110, 181, 41));
        incmarketing->setFont(font1);
        incmarketing->setCursor(QCursor(Qt::PointingHandCursor));
        incmarketing->setStyleSheet(QStringLiteral("background-color: rgb(114, 159, 207);"));
        saveBtn = new QPushButton(Window);
        saveBtn->setObjectName(QStringLiteral("saveBtn"));
        saveBtn->setGeometry(QRect(10, 450, 181, 31));
        saveBtn->setFont(font1);
        saveBtn->setCursor(QCursor(Qt::PointingHandCursor));
        loadBtn = new QPushButton(Window);
        loadBtn->setObjectName(QStringLiteral("loadBtn"));
        loadBtn->setGeometry(QRect(220, 450, 181, 31));
        loadBtn->setFont(font1);
        loadBtn->setCursor(QCursor(Qt::PointingHandCursor));
        exitButton = new QPushButton(Window);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(110, 510, 161, 32));
        exitButton->setCursor(QCursor(Qt::PointingHandCursor));
        exitButton->setStyleSheet(QStringLiteral("background-color: rgb(244, 66, 66)"));
        intelligence_debug_button = new QPushButton(Window);
        intelligence_debug_button->setObjectName(QStringLiteral("intelligence_debug_button"));
        intelligence_debug_button->setGeometry(QRect(500, 510, 110, 30));
        intelligence_debug_button->setFont(font1);
        intelligence_debug_button->setCursor(QCursor(Qt::PointingHandCursor));
        intelligence_debug_button->setStyleSheet(QLatin1String("background-color: rgb(221, 117, 148)\n"
""));
        marketing_debug_button = new QPushButton(Window);
        marketing_debug_button->setObjectName(QStringLiteral("marketing_debug_button"));
        marketing_debug_button->setGeometry(QRect(610, 510, 101, 30));
        marketing_debug_button->setFont(font1);
        marketing_debug_button->setCursor(QCursor(Qt::PointingHandCursor));
        marketing_debug_button->setStyleSheet(QStringLiteral("background-color: rgb(138, 226, 52)"));
        pencils_inventory_debug_button = new QPushButton(Window);
        pencils_inventory_debug_button->setObjectName(QStringLiteral("pencils_inventory_debug_button"));
        pencils_inventory_debug_button->setGeometry(QRect(710, 510, 176, 30));
        pencils_inventory_debug_button->setFont(font1);
        pencils_inventory_debug_button->setCursor(QCursor(Qt::PointingHandCursor));
        pencils_inventory_debug_button->setStyleSheet(QStringLiteral("background-color: rgb(245, 121, 0);"));
        marketing_label = new QLabel(Window);
        marketing_label->setObjectName(QStringLiteral("marketing_label"));
        marketing_label->setGeometry(QRect(500, 210, 93, 22));
        marketing_label->setFont(font1);
        marketing_amount_label = new QLabel(Window);
        marketing_amount_label->setObjectName(QStringLiteral("marketing_amount_label"));
        marketing_amount_label->setGeometry(QRect(610, 210, 67, 22));
        marketing_amount_label->setFont(font1);
        buywood_button = new QPushButton(Window);
        buywood_button->setObjectName(QStringLiteral("buywood_button"));
        buywood_button->setGeometry(QRect(10, 390, 181, 42));
        buywood_button->setFont(font2);
        buywood_button->setCursor(QCursor(Qt::PointingHandCursor));
        buywood_button->setStyleSheet(QLatin1String("background-color: rgb(143, 89, 2);\n"
"font: 57 11pt \"Ubuntu\";\n"
"color: rgb(238, 238, 236);"));
        buygraphite_button = new QPushButton(Window);
        buygraphite_button->setObjectName(QStringLiteral("buygraphite_button"));
        buygraphite_button->setGeometry(QRect(210, 390, 181, 42));
        buygraphite_button->setFont(font2);
        buygraphite_button->setCursor(QCursor(Qt::PointingHandCursor));
        buygraphite_button->setStyleSheet(QLatin1String("background-color: rgb(85, 87, 83);\n"
"font: 57 11pt \"Ubuntu\";\n"
"color: rgb(238, 238, 236);"));
        buygraphite_button->setAutoDefault(false);
        buygraphite_button->setFlat(false);
        layoutWidget = new QWidget(Window);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 110, 210, 24));
        publicdemand_layout = new QHBoxLayout(layoutWidget);
        publicdemand_layout->setObjectName(QStringLiteral("publicdemand_layout"));
        publicdemand_layout->setContentsMargins(0, 0, 0, 0);
        publicdemand_label = new QLabel(layoutWidget);
        publicdemand_label->setObjectName(QStringLiteral("publicdemand_label"));
        publicdemand_label->setFont(font1);

        publicdemand_layout->addWidget(publicdemand_label);

        publicdemand_int = new QLabel(layoutWidget);
        publicdemand_int->setObjectName(QStringLiteral("publicdemand_int"));
        publicdemand_int->setFont(font3);
        publicdemand_int->setStyleSheet(QStringLiteral("font: 57 12pt \"Ubuntu\";"));

        publicdemand_layout->addWidget(publicdemand_int);

        main_title = new QLabel(Window);
        main_title->setObjectName(QStringLiteral("main_title"));
        main_title->setGeometry(QRect(130, 10, 191, 32));
        QFont font4;
        font4.setFamily(QStringLiteral("Ubuntu"));
        font4.setPointSize(20);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(7);
        main_title->setFont(font4);
        main_title->setStyleSheet(QLatin1String("font: 58 20pt \"Ubuntu\";\n"
""));
        layoutWidget3 = new QWidget(Window);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 150, 248, 24));
        pencilinventory_layout = new QHBoxLayout(layoutWidget3);
        pencilinventory_layout->setObjectName(QStringLiteral("pencilinventory_layout"));
        pencilinventory_layout->setContentsMargins(0, 0, 0, 0);
        pencilinventory_label = new QLabel(layoutWidget3);
        pencilinventory_label->setObjectName(QStringLiteral("pencilinventory_label"));
        pencilinventory_label->setFont(font1);

        pencilinventory_layout->addWidget(pencilinventory_label);

        pencilinventory_int = new QLabel(layoutWidget3);
        pencilinventory_int->setObjectName(QStringLiteral("pencilinventory_int"));
        pencilinventory_int->setFont(font3);
        pencilinventory_int->setStyleSheet(QLatin1String("font: 57 12pt \"Ubuntu\";\n"
""));

        pencilinventory_layout->addWidget(pencilinventory_int);

        layoutWidget4 = new QWidget(Window);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 300, 181, 24));
        woodleft_layout = new QHBoxLayout(layoutWidget4);
        woodleft_layout->setSpacing(9);
        woodleft_layout->setObjectName(QStringLiteral("woodleft_layout"));
        woodleft_layout->setContentsMargins(0, 0, 0, 0);
        wooleft_label = new QLabel(layoutWidget4);
        wooleft_label->setObjectName(QStringLiteral("wooleft_label"));
        wooleft_label->setMinimumSize(QSize(16, 0));
        wooleft_label->setFont(font1);

        woodleft_layout->addWidget(wooleft_label);

        woodleft_int = new QLabel(layoutWidget4);
        woodleft_int->setObjectName(QStringLiteral("woodleft_int"));
        woodleft_int->setFont(font3);
        woodleft_int->setStyleSheet(QStringLiteral("font: 57 12pt \"Ubuntu\";"));

        woodleft_layout->addWidget(woodleft_int);

        layoutWidget5 = new QWidget(Window);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(10, 340, 181, 24));
        graphiteleft_layout = new QHBoxLayout(layoutWidget5);
        graphiteleft_layout->setObjectName(QStringLiteral("graphiteleft_layout"));
        graphiteleft_layout->setContentsMargins(0, 0, 0, 0);
        graphiteleft_label = new QLabel(layoutWidget5);
        graphiteleft_label->setObjectName(QStringLiteral("graphiteleft_label"));
        graphiteleft_label->setFont(font1);

        graphiteleft_layout->addWidget(graphiteleft_label);

        graphiteleft_int = new QLabel(layoutWidget5);
        graphiteleft_int->setObjectName(QStringLiteral("graphiteleft_int"));
        graphiteleft_int->setFont(font3);
        graphiteleft_int->setStyleSheet(QStringLiteral("font: 57 12pt \"Ubuntu\";"));

        graphiteleft_layout->addWidget(graphiteleft_int);

        pencilsproduced_label = new QLabel(Window);
        pencilsproduced_label->setObjectName(QStringLiteral("pencilsproduced_label"));
        pencilsproduced_label->setGeometry(QRect(12, 71, 230, 22));
        pencilsproduced_label->setFont(font1);
        pencilsproduced_int = new QLabel(Window);
        pencilsproduced_int->setObjectName(QStringLiteral("pencilsproduced_int"));
        pencilsproduced_int->setGeometry(QRect(250, 72, 68, 20));
        pencilsproduced_int->setFont(font3);
        pencilsproduced_int->setStyleSheet(QStringLiteral("font: 57 12pt \"Ubuntu\";"));
        price_label = new QLabel(Window);
        price_label->setObjectName(QStringLiteral("price_label"));
        price_label->setGeometry(QRect(11, 191, 127, 22));
        price_label->setFont(font1);
        price_int = new QLabel(Window);
        price_int->setObjectName(QStringLiteral("price_int"));
        price_int->setGeometry(QRect(150, 191, 47, 19));
        price_int->setFont(font3);
        price_int->setStyleSheet(QStringLiteral("font: 57 12pt \"Ubuntu\";"));
        price_increase_button = new QPushButton(Window);
        price_increase_button->setObjectName(QStringLiteral("price_increase_button"));
        price_increase_button->setGeometry(QRect(120, 220, 80, 71));
        QFont font5;
        font5.setFamily(QStringLiteral("Sans Bold"));
        font5.setPointSize(25);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(7);
        price_increase_button->setFont(font5);
        price_increase_button->setCursor(QCursor(Qt::PointingHandCursor));
        price_increase_button->setStyleSheet(QLatin1String("background-color: rgb(78, 154, 6);\n"
"font: 57 25pt \"Sans Bold\";\n"
"color: rgb(0, 0, 0)"));
        price_decrease_button = new QPushButton(Window);
        price_decrease_button->setObjectName(QStringLiteral("price_decrease_button"));
        price_decrease_button->setGeometry(QRect(9, 220, 81, 71));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(price_decrease_button->sizePolicy().hasHeightForWidth());
        price_decrease_button->setSizePolicy(sizePolicy1);
        QFont font6;
        font6.setFamily(QStringLiteral("Sans Bold"));
        font6.setPointSize(45);
        font6.setBold(false);
        font6.setItalic(false);
        font6.setWeight(7);
        price_decrease_button->setFont(font6);
        price_decrease_button->setCursor(QCursor(Qt::PointingHandCursor));
        price_decrease_button->setStyleSheet(QLatin1String("background-color: rgb(78, 154, 6);\n"
"font: 57 45pt \"Sans Bold\";\n"
"color: rgb(0, 0, 0)"));
        price_decrease_button->setIconSize(QSize(20, 20));
        label = new QLabel(Window);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 550, 921, 181));
        label->setPixmap(QPixmap(QString::fromUtf8("../attendance-clipart-pencil-3.png")));
        label->setScaledContents(true);

        retranslateUi(Window);

        buygraphite_button->setDefault(false);


        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QWidget *Window)
    {
        Window->setWindowTitle(QApplication::translate("Window", "Window", Q_NULLPTR));
        intelligence->setText(QApplication::translate("Window", "Intelligence:", Q_NULLPTR));
        intelligence_number->setText(QApplication::translate("Window", "intamt", Q_NULLPTR));
        marketing->setText(QApplication::translate("Window", "Activate Marketing", Q_NULLPTR));
        upgradeapm->setText(QApplication::translate("Window", "Upgrade APM", Q_NULLPTR));
        debugtool->setText(QApplication::translate("Window", "Debugging Tools ", Q_NULLPTR));
        makepencils_button->setText(QApplication::translate("Window", "Make Penciles", Q_NULLPTR));
        autopencilrate_label1->setText(QApplication::translate("Window", "Rate:", Q_NULLPTR));
        autopencilrate_int->setText(QApplication::translate("Window", "x amount", Q_NULLPTR));
        autopencilrate_label2->setText(QApplication::translate("Window", "pencils/minute", Q_NULLPTR));
        autopencil_label->setText(QApplication::translate("Window", "AutoPencile2000:", Q_NULLPTR));
        autopencil_int->setText(QApplication::translate("Window", "x amount", Q_NULLPTR));
        bankbalance_label->setText(QApplication::translate("Window", "Bank Balance:", Q_NULLPTR));
        buyautopencil_button->setText(QApplication::translate("Window", "Buy More APMS\n"
"$100.00", Q_NULLPTR));
        bankbalance_int->setText(QApplication::translate("Window", "x dollar amount", Q_NULLPTR));
        debug_pencils->setText(QApplication::translate("Window", "Pencils", Q_NULLPTR));
        debug_balance->setText(QApplication::translate("Window", "Balance", Q_NULLPTR));
        debug_resource->setText(QApplication::translate("Window", "Wood and Graphite", Q_NULLPTR));
        incmarketing->setText(QApplication::translate("Window", "Buy More Marketing", Q_NULLPTR));
        saveBtn->setText(QApplication::translate("Window", "Save", Q_NULLPTR));
        loadBtn->setText(QApplication::translate("Window", "Load", Q_NULLPTR));
        exitButton->setText(QApplication::translate("Window", "Exit", Q_NULLPTR));
        intelligence_debug_button->setText(QApplication::translate("Window", "Intelligence", Q_NULLPTR));
        marketing_debug_button->setText(QApplication::translate("Window", "Marketing", Q_NULLPTR));
        pencils_inventory_debug_button->setText(QApplication::translate("Window", "Pencils in Inventory", Q_NULLPTR));
        marketing_label->setText(QApplication::translate("Window", "Marketing:", Q_NULLPTR));
        marketing_amount_label->setText(QApplication::translate("Window", "0", Q_NULLPTR));
        buywood_button->setText(QApplication::translate("Window", "Buy Wood\n"
"$50.00 / 100.00 m", Q_NULLPTR));
        buygraphite_button->setText(QApplication::translate("Window", "Buy Graphite\n"
"$50.00 / 100.00 m", Q_NULLPTR));
        publicdemand_label->setText(QApplication::translate("Window", "Public Demand:", Q_NULLPTR));
        publicdemand_int->setText(QApplication::translate("Window", "x amount", Q_NULLPTR));
        main_title->setText(QApplication::translate("Window", "Pencil Producer", Q_NULLPTR));
        pencilinventory_label->setText(QApplication::translate("Window", "Pencils in Inventory:", Q_NULLPTR));
        pencilinventory_int->setText(QApplication::translate("Window", "x amount", Q_NULLPTR));
        wooleft_label->setText(QApplication::translate("Window", "Wood Left:", Q_NULLPTR));
        woodleft_int->setText(QApplication::translate("Window", "  x int", Q_NULLPTR));
        graphiteleft_label->setText(QApplication::translate("Window", "Graphite Left:", Q_NULLPTR));
        graphiteleft_int->setText(QApplication::translate("Window", "  x int", Q_NULLPTR));
        pencilsproduced_label->setText(QApplication::translate("Window", "Pencils produced (to date):", Q_NULLPTR));
        pencilsproduced_int->setText(QApplication::translate("Window", "x amount", Q_NULLPTR));
        price_label->setText(QApplication::translate("Window", "Price of Pencil:", Q_NULLPTR));
        price_int->setText(QApplication::translate("Window", "x price", Q_NULLPTR));
        price_increase_button->setText(QApplication::translate("Window", "+", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        price_decrease_button->setToolTip(QApplication::translate("Window", "<html><head/><body><p><br/></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        price_decrease_button->setText(QApplication::translate("Window", "-", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
