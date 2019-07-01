#include "endgame.h"
#include "welcome.h"
#include "window.h"
#include "ui_endgame.h"

Endgame::Endgame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::endgame) {
    ui->setupUi(this);
}

Endgame::~Endgame() {
    delete ui;
}

void Endgame::setNextWindow() {
    Window *m;
    m = new(Window);
    m->hide();
    m->setParent(this);
    this->next = m;
}

void Endgame::on_startNewGame_clicked() {
    this->setNextWindow();
    this->hide();
    this->next->show();
}

void Endgame::on_exitgame_clicked() {
    this->close();
}
