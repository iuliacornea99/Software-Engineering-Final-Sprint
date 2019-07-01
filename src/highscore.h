#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include <QString>

/**
 * @brief The Highscore struct that handles the score and username of each top player
 */
struct Highscore {
    int score;
    QString gameUser;
};

#endif // HIGHSCORE_H
