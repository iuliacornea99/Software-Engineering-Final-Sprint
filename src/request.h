#ifndef REQUEST_H
#define REQUEST_H
#include <QtNetwork>
#include <QString>
#include <QJsonDocument>
#include <vector>
#include "highscore.h"
#include "scorepost.h"

#define SERVER_STORAGE_URL  "https://matiusulung.com/se.json"
#define GET_REQUEST_PATH    "/getscores"
#define POST_REQUEST_PATH   "/uploadscore"

/**
 * @brief The Request class handles the highscores board from the welcome page.
 */

class Request
{
private:
    QString serverUrl;

    /**
     * @brief Fetch the initial server URL.
     * @return true if successfull, false otherwise.
     */
    bool fetchServerUrl();

    /**
     * @brief Take the data from the server
     * @return Json fetch from the server
     */
    QJsonDocument fetch();
public:
    Request();
    std::vector<Highscore> getHighscores();
    QJsonDocument postScore(ScorePost postData);
    QJsonDocument postScore(int score);
};

#endif // REQUEST_H
