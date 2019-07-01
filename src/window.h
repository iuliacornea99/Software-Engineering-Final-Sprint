/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef _WINDOW_H
#define _WINDOW_H

#include "request.h"

#include <cmath>
#include <QTimer>
#include <QWidget>
#include "pencil.h"
#include "production.h"
#include "wallet.h"
#include "apm.h"
#include "sales.h"
#include <QCloseEvent>


namespace Ui {
    class Window;
}

/**
 * @brief The Window class handles every functionality of the actual game window
 */
class Window : public QWidget {
    Q_OBJECT
    
public:
    /**
     * @brief Main Window Constructor to initialize
     * user-interface
     */
    explicit Window(QWidget *parent = nullptr);

    /**
     * @brief function to check whether buttons should be
     * disabled or not
     */
    void toggle_buttons();

    /**
     * @brief set the parent window to go to upon game exit
     * @param p - to the parent widget
     */
    void setParent(QWidget *p);

    /**
     * @brief function to update bank balance in user interface
     */
    void updatebalancelabel();

    /**
     * @brief function to update wood left, graphite left in user
     * interface
     */
    void updateresourcelabels();

    /**
     * @brief function to update pencils in our inventory and total
     * pencils produced in user interface
     */
    void updatepencillabels();

    /**
     * @brief function to update APM rate, total APM and buy APM in user
     * interface
     */
    void updateapmlabels();

    /**
     * @brief function to update demand and price of pencil in user interface
     */
    void updatepencilpricelabel();

    /**
     * @brief function to set visibility and update intelligence in user interface
     */
    void updateintelligencelabel();

    /**
     * @brief function to update buy marketing button in user interface
     */
    void updateBuyMarketingLabel();

    /**
     * @brief function to update increase marketing button in user interface
     */
    void updateincreasemarketinglabel();

    /**
     * @brief function to save the current state of the program
     */
    void writeSettings();

    /**
     * @brief function to read the previous state of the program
     */
    void readSettings();

    void writeSettings(QString& fname);
    void readSettings(QString& fname);

    /**
     * @brief function to describe a close event of a program
     */
    void closeEvent(QCloseEvent *event);

    void callLoadFunction();

    /**
      Destructor of Main Window
     */
    ~Window();

//private slots:
    //void on_incmarketing_clicked();

private slots:

    /**
     * @brief actions that need to be take when make pencil
     * button is clicked
     */
    bool make_penciles();

    /**
     * @brief function to update price of graphite and wood every
     * 5 seconds in user interface
     */
    void updateresourcepricelabels();

    /**
     * @brief actions that need to be take when buy wood button is
     * clicked
     */
    bool buy_wood();

    /**
     * @brief actions that need to be taken when buy graphite button is
     * clicked
     */
    bool buy_graphite();

    /**
     * @brief function to produce pencil every second using APM
     */
    bool produce_pencils();

    /**
     * @brief actions that need to be taken when buy APM button is
     * clicked
     */
    bool buy_autopencile();

    /**
     * @brief function to sell pencils every second according to public
     * demand
     */
    bool sell_penciles();

    /**
     * @brief actions that need to be taken when increase price of pencil
     * button is clicked
     */
    bool increase_price();

    /**
     * @brief actions that need to be taken when decrease price of pencil
     * button is clicked
     */
    bool decrease_price();

    /**
     * @brief function to unlock intelligence after total pencils produced is
     * reached 300 and to generate intelligence every second
     */
    bool unlockintelligence();

    /**
     * @brief actions that need to be taken when buy marketing button is clicked
     */
    bool buy_marketing();

    /**
     * @brief actions that need to be taken when increasing marketing button is clicked
     */
    bool increase_marketing();

    /**
     * @brief actions that need to be taken when upgrade APM button is clicked
     */
    bool upgradeAPM();

    /**
     * @brief actions that need to be taken when debugging tool is checked
     */
    void debuggingtool(bool);

    /**
     * @brief debugging tool to increase the number of pencils in inventory
     * and total pencils manufactured by 1000 when pencil debugging is clicked
     */
    void pencil_debug();

    /**
     * @brief debugging tool to grant the player $1000 when balance debugging
     * button is clicked
     */
    void balance_debug();

    /**
     * @brief debugging tool to grant grant the player 10m of wood and granite
     * when resource debugging button is clicked
     */
    void resource_debug();
    
    /**
     * @brief Window::on_saveBtn_clicked
     * When you want to save to a file
     */
    void on_saveBtn_clicked();

    /**
     * @brief Window::on_loadBtn_clicked
     * Handle loading a file
     */
    void on_loadBtn_clicked();

    /**
     * @brief Window::on_exitButton_clicked
     * Go back to welcome page and stop game
     */
    void on_exitButton_clicked();

    /**
     * @brief Window::on_pencils_inventory_debug_button_clicked
     * Debug button that increases both the number of pencils in the inventory
     * and the total number of pencils ever produced by 1000
     */
    void on_pencils_inventory_debug_button_clicked();

    /**
     * @brief on_marketing_debug_button_clicked
     * Debug button that increases the amount of marketing by 3
     */
    void on_marketing_debug_button_clicked();

    /**
     * @brief on_intelligence_debug_button_clicked
     * Debug button that increase the amount of intelligence by 10
     */
    void on_intelligence_debug_button_clicked();

    /**
      * @brief: Window::gameclosure();
      * Calls end game window
      */
    void gameclosure();

private:
    Pencil pencils; /**< pencil object from pencil.h */
    Production productions; /**< production object from production.h */
    Wallet balance; /**< wallet object from wallet.h */
    APM apm; /**< APM object from apm.h */
    SALES sales; /**< sales object from sales.h */

    QTimer *resource_price_timer; /**< timer to update price of graphite and wood every 5 seconds */
    QTimer *sell_timer; /**< timer to sell pencils every second */
    QTimer *autopencile_timer; /**< timer to produce pencil every second */
    QTimer *intelligence_timer; /**< timer to generate intelligence every second */
    QTimer *gameclosure_timer; /**< timer for checking the end of the game every second */
    QWidget* parent = nullptr;

    Ui::Window *widget; /**< pointer to user interface */
    QWidget* next = nullptr;

    Request *api;

};

#endif /* _WINDOW_H */
