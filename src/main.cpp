/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <QApplication>
#include "welcome.h"
#include <ctime>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Welcome welcome;
    welcome.setNextWindow();
    welcome.show();
    return a.exec();
}

