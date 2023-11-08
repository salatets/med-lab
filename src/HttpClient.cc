#include "HttpClient.h"
#include <QNetworkReply>
#include <iostream>

QUrl HttpClient::url(const QString &endpoint)
{
    return QUrl("https://" + ip + "/" + endpoint);
}

HttpClient::HttpClient(const QHostAddress &ip)
    : ip(ip.toString())
{
    QObject::connect(&nam, &QNetworkAccessManager::finished, this, &HttpClient::replyFinished);
}

void HttpClient::get(const QString &endpoint)
{
    nam.get(QNetworkRequest(url(endpoint)));
}

void HttpClient::post(const QString &endpoint, const QByteArray &data)
{
    nam.post(QNetworkRequest(url(endpoint)), data);
}

void HttpClient::replyFinished(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {
        std::cout << reply->errorString().toStdString() << std::endl;
    } else {
        auto status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
        if (status_code.isValid()) {
            if (int status = status_code.toInt(); status < 500 && status != 404)
                processResponce(reply->readAll());
        }
    }
    reply->deleteLater();
}
