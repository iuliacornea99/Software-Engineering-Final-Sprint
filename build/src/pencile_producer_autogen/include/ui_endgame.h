/********************************************************************************
** Form generated from reading UI file 'endgame.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENDGAME_H
#define UI_ENDGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_endgame
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *startNewGame;
    QPushButton *exitgame;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *endgame)
    {
        if (endgame->objectName().isEmpty())
            endgame->setObjectName(QStringLiteral("endgame"));
        endgame->resize(795, 329);
        endgame->setStyleSheet(QStringLiteral("background-color: rgb(239, 41, 41); "));
        centralwidget = new QWidget(endgame);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 40, 781, 81));
        QFont font;
        font.setFamily(QStringLiteral("Uroob"));
        font.setPointSize(23);
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(9);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("font: 75 italic 23pt \"Uroob\";"));
        label->setAlignment(Qt::AlignCenter);
        startNewGame = new QPushButton(centralwidget);
        startNewGame->setObjectName(QStringLiteral("startNewGame"));
        startNewGame->setGeometry(QRect(310, 130, 119, 41));
        startNewGame->setStyleSheet(QStringLiteral("font: 75 italic 13pt \"Uroob\";"));
        exitgame = new QPushButton(centralwidget);
        exitgame->setObjectName(QStringLiteral("exitgame"));
        exitgame->setGeometry(QRect(310, 190, 121, 31));
        exitgame->setStyleSheet(QStringLiteral("font: 75 italic 13pt \"Uroob\";"));
        endgame->setCentralWidget(centralwidget);
        menubar = new QMenuBar(endgame);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 795, 22));
        endgame->setMenuBar(menubar);
        statusbar = new QStatusBar(endgame);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        endgame->setStatusBar(statusbar);

        retranslateUi(endgame);

        QMetaObject::connectSlotsByName(endgame);
    } // setupUi

    void retranslateUi(QMainWindow *endgame)
    {
        endgame->setWindowTitle(QApplication::translate("endgame", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("endgame", "Congratulations! You achieved your goal: 25000 pencils.", Q_NULLPTR));
        startNewGame->setText(QApplication::translate("endgame", "Start New Game", Q_NULLPTR));
        exitgame->setText(QApplication::translate("endgame", "Exit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class endgame: public Ui_endgame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENDGAME_H
