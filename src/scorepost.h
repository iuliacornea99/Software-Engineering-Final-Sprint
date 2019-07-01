#ifndef SCOREPOST_H
#define SCOREPOST_H
#include <QString>
#include <cstdlib>
/**
 * @brief The ScorePost struct handles all the necessary information needed to authentificate the user on the server.
 */
struct ScorePost {
    QString jacobsId;
    QString seToken;
    QString gameUsername;
    int score;

    /**
     * @brief getEnv extracts the authentification details(jacobsID, the token and username from the exportvariables executable
     */
    void getEnv() {
        if(std::getenv("JACOBS_ID") == nullptr || std::getenv("SE_TOKEN") == nullptr || std::getenv("GAME_USERNAME") == nullptr) {
            exit(EXIT_FAILURE); // fail on reading env variable
        }
        jacobsId = std::getenv("JACOBS_ID");
        seToken = std::getenv("SE_TOKEN");
        gameUsername = std::getenv("GAME_USERNAME");
    }
};

#endif // SCOREPOST_H
