#ifndef GET_URL_H
#define GET_URL_H

#include <iostream>
#include <string>
#include <QtNetwork>

class GetURL : public QObject {

    Q_OBJECT

    public:
        GetURL();
        ~GetURL();
        void get(const std::string &url); // creating and sending request

        QNetworkReply* getReply() const;

    public slots:
        void end(QNetworkReply* re);
    signals:
        void finTransfertSIGNAL(QString);

    private:
        QNetworkAccessManager* manager;
        QNetworkReply *reply; // hold the response sent by the server
        std::string stringReply;

};

#endif // GET_URL_H
