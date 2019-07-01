#ifndef WELCOME_H
#define WELCOME_H

#include <QMainWindow>
#include <QCloseEvent>
#include "request.h"


namespace Ui {
class Welcome;
}

/**
 * @brief The Welcome class handles every functionality of the welcome window
 */

class Welcome : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Welcome Constructor
     * @param parent
     */
    explicit Welcome(QWidget *parent = nullptr);
    ~Welcome();
    /**
     * @brief Gets resources ready to open the gameplay window
     * @param load if called by load button then it's true, false by default.
     * @return true if successful, false otherwise.
     */
    bool setNextWindow(bool load=false);

    /**
     * @brief Loads highscores on startup and when it comes back from the gameplay screen.
     */
    void loadHighScores();

private slots:
    /**
     * @brief on_play_clicked button starts a new game
     */
    void on_play_clicked();
    /**
     * @brief on_load_clicked button loads the entire state of a previous game from a .sav file
     *  (which is saved locally by the user in a previous game)
     */
    void on_load_clicked();

    /**
     * @brief Handler for "Refresh" button. It refreshes the highscores.
     */
    void on_refresh_button_clicked();

private:
    Ui::Welcome *ui;
    QWidget* next = nullptr;
    Request *api;
};

#endif // WELCOME_H
