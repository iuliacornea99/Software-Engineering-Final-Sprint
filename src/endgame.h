#ifndef ENDGAME_H
#define ENDGAME_H

#include <QMainWindow>

namespace Ui {
class endgame;
}

/**
 * @brief The Endgame class handles everything which is appeared in the endgame
 * window.
 */
class Endgame : public QMainWindow
{
    Q_OBJECT

public:

    /**
     * @brief Default constructor.
     * @param parent - the parent window.
     */
    explicit Endgame(QWidget *parent = nullptr);

    /**
      *@brief Default destructor
      */
    ~Endgame();

    /**
     * @brief Gets resources ready to open the endgame window
     */
     void setNextWindow();

private slots:

     /**
      * @brief Handler for clicking the exit game button.
      */
     void on_exitgame_clicked();

     /**
      * @brief Handler for clicking start new game button.
      */
     void on_startNewGame_clicked();

    
private:

     /**
     * @brief The Ui namespace of the window.
     */
    Ui::endgame *ui;

    /**
     * @brief The next window.
     */
    QWidget* next = nullptr;
};

#endif // ENDGAME_H
