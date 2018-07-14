#include "get_url.h"
#include "application_graphique.h"

#include <string>
#include <stdio.h>
#include <iostream>


using namespace std;

GetURL::GetURL() {
    manager = new QNetworkAccessManager();


}

QNetworkReply* GetURL::getReply() const {
    return reply;
}

void GetURL::get(const string & url) {
    QNetworkRequest* request = new QNetworkRequest(QUrl(QString(url.c_str())));

    manager->get(*request);

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(end(QNetworkReply*)));
}

void GetURL::end(QNetworkReply* re) {
    reply = re;
    stringReply = reply->readAll().toStdString();
    emit finTransfertSIGNAL(QString::fromStdString(stringReply));
}


GetURL::~GetURL()
{

}

