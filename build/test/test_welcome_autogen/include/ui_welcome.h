/********************************************************************************
** Form generated from reading UI file 'welcome.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOME_H
#define UI_WELCOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Welcome
{
public:
    QWidget *centralwidget;
    QLabel *main_title;
    QLabel *description;
    QPushButton *play;
    QPushButton *load;
    QLabel *highscoreLabel;
    QLabel *highscoreTable;
    QPushButton *refresh_button;

    void setupUi(QMainWindow *Welcome)
    {
        if (Welcome->objectName().isEmpty())
            Welcome->setObjectName(QStringLiteral("Welcome"));
        Welcome->resize(1047, 657);
        Welcome->setMinimumSize(QSize(1047, 657));
        Welcome->setMaximumSize(QSize(1047, 657));
        Welcome->setAutoFillBackground(true);
        Welcome->setStyleSheet(QLatin1String("#Welcome {background-image: url(background.jpg);\n"
"} "));
        centralwidget = new QWidget(Welcome);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setStyleSheet(QStringLiteral(""));
        main_title = new QLabel(centralwidget);
        main_title->setObjectName(QStringLiteral("main_title"));
        main_title->setGeometry(QRect(370, 20, 651, 97));
        QFont font;
        font.setPointSize(60);
        font.setBold(true);
        font.setWeight(75);
        main_title->setFont(font);
        main_title->setAlignment(Qt::AlignCenter);
        description = new QLabel(centralwidget);
        description->setObjectName(QStringLiteral("description"));
        description->setGeometry(QRect(330, 170, 305, 27));
        QFont font1;
        font1.setPointSize(17);
        description->setFont(font1);
        description->setAlignment(Qt::AlignCenter);
        play = new QPushButton(centralwidget);
        play->setObjectName(QStringLiteral("play"));
        play->setGeometry(QRect(400, 240, 131, 51));
        QFont font2;
        font2.setPointSize(22);
        play->setFont(font2);
        play->setCursor(QCursor(Qt::PointingHandCursor));
        load = new QPushButton(centralwidget);
        load->setObjectName(QStringLiteral("load"));
        load->setGeometry(QRect(400, 350, 131, 51));
        load->setFont(font2);
        load->setCursor(QCursor(Qt::PointingHandCursor));
        highscoreLabel = new QLabel(centralwidget);
        highscoreLabel->setObjectName(QStringLiteral("highscoreLabel"));
        highscoreLabel->setGeometry(QRect(680, 170, 115, 27));
        highscoreLabel->setFont(font1);
        highscoreTable = new QLabel(centralwidget);
        highscoreTable->setObjectName(QStringLiteral("highscoreTable"));
        highscoreTable->setGeometry(QRect(680, 220, 281, 261));
        QFont font3;
        font3.setPointSize(15);
        highscoreTable->setFont(font3);
        highscoreTable->setFrameShape(QFrame::Box);
        highscoreTable->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        highscoreTable->setMargin(6);
        refresh_button = new QPushButton(centralwidget);
        refresh_button->setObjectName(QStringLiteral("refresh_button"));
        refresh_button->setGeometry(QRect(840, 170, 115, 27));
        refresh_button->setCursor(QCursor(Qt::PointingHandCursor));
        Welcome->setCentralWidget(centralwidget);

        retranslateUi(Welcome);

        QMetaObject::connectSlotsByName(Welcome);
    } // setupUi

    void retranslateUi(QMainWindow *Welcome)
    {
        Welcome->setWindowTitle(QApplication::translate("Welcome", "MainWindow", Q_NULLPTR));
        main_title->setText(QApplication::translate("Welcome", "Pencil Producer", Q_NULLPTR));
        description->setText(QApplication::translate("Welcome", "Simulation of a pencil factory", Q_NULLPTR));
        play->setText(QApplication::translate("Welcome", "PLAY", Q_NULLPTR));
        load->setText(QApplication::translate("Welcome", "LOAD", Q_NULLPTR));
        highscoreLabel->setText(QApplication::translate("Welcome", "Highscores", Q_NULLPTR));
        highscoreTable->setText(QString());
        refresh_button->setText(QApplication::translate("Welcome", "Refresh", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Welcome: public Ui_Welcome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOME_H
