#include "request.h"
#include <QUrl>
#include <QDebug>
#include "highscore.h"

Request::Request()
{
    serverUrl = "";
}

bool Request::fetchServerUrl(){
    QNetworkAccessManager nam;
    QUrl url(SERVER_STORAGE_URL);
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    qInfo() << "Fetching server URL...";
    QNetworkReply *reply = nam.get(request);
    while(!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray response_data = reply->readAll();

    QJsonDocument json = QJsonDocument::fromJson(response_data);
    reply->deleteLater();
    if(json.isObject()){
       QJsonObject jsonObj = json.object();
       if(jsonObj.value("link").isString()){
           serverUrl = "http://" + jsonObj.value("link").toString(); // parse the string on the way
           qInfo() << "Done";
           qInfo() << "Server URL: " + serverUrl;
       } else {
           qInfo() << "Error finding link in json object";
           return false;
       }
    } else {
        qInfo() << "Error parsing json object";
    }
    return true;
}

QJsonDocument Request::fetch(){
    if(serverUrl.isNull() || serverUrl.isEmpty()){
        // invalid url type
        fetchServerUrl(); // take the url
    }

    QNetworkAccessManager nam;
    QUrl url(serverUrl + GET_REQUEST_PATH);
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkReply *reply = nam.get(request);
    while(!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray response_data = reply->readAll();

    QJsonDocument json = QJsonDocument::fromJson(response_data);
    reply->deleteLater();
    if(json.isObject()) {
        return json;
    } else {
        QJsonDocument empty;
        return empty;
    }
}

std::vector<Highscore> Request::getHighscores(){
    std::vector<Highscore> vec;
    QJsonDocument doc = fetch();
    if(!doc.isEmpty()){
        QJsonArray arr = doc.object().value("highscores").toArray();
        for(auto iter = arr.begin(); iter != arr.end(); iter++){
            QJsonObject obj = iter->toObject();
            Highscore score;
            score.score = obj.value("score").toInt();
            score.gameUser = obj.value("game-username").toString();
            vec.push_back(score);
        }
    } else {
        fprintf(stderr, "Could not fetch JSON document\n");
    }
    return vec;
}

QJsonDocument Request::postScore(ScorePost postData){
    if(serverUrl.isNull() || serverUrl.isEmpty()){
        // invalid url type
        fetchServerUrl(); // take the url
    }

    QNetworkAccessManager nam;
    QUrl url(serverUrl + POST_REQUEST_PATH);
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
    json.insert("jacobs-id", postData.jacobsId);
    json.insert("se-token", postData.seToken);
    json.insert("game-username", postData.gameUsername);
    json.insert("score", postData.score);

    // send the json

    QNetworkReply *reply = nam.post(request, QJsonDocument(json).toJson());
    while(!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray response_data = reply->readAll();

    QJsonDocument jsonResponse = QJsonDocument::fromJson(response_data);
    reply->deleteLater();
    return jsonResponse;
}

QJsonDocument Request::postScore(int score){
    ScorePost post;
    post.getEnv();
    post.score = score;
    return postScore(post);
}
