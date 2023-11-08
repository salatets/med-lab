#pragma once
#include <QNetworkAccessManager>
#include <QObject>

class HttpClient : public QObject
{
    Q_OBJECT
public:
    HttpClient(const QHostAddress &ip);
    ;
    void get(const QString &endpoint);
    void post(const QString &endpoint, const QByteArray &data);

protected:
    virtual void processResponce(QByteArray) = 0;

private slots:
    void replyFinished(QNetworkReply *reply);

private:
    QUrl url(const QString &endpoint);

    QString ip;
    QNetworkAccessManager nam;
};
