#include "parser_url.h"
#include "application_graphique.h"
#include <iostream>
#include <json/json-forwards.h>
#include <json/json.h>
#include "jsoncpp.cpp"



ParserURL::ParserURL(){}

void ParserURL::parser(std::string text_json)
{
    Json::Reader reader;
    Json::Value root;

    reader.parse(text_json, root);

    Json::Value pseudoVALUE = root["response"]["players"][0]["personaname"];
    Json::Value realnameVALUE = root["response"]["players"][0]["realname"];
    Json::Value urlProfilVALUE = root["response"]["players"][0]["profileurl"];
    Json::Value lastLogOffVALUE = root["response"]["players"][0]["lastlogoff"];
    Json::Value statusVALUE = root["response"]["players"][0]["personastate"];
    Json::Value commentPermissionVALUE = root["response"]["players"][0]["commentpermission"];
    Json::Value imageVALUE = root["response"]["players"][0]["avatarfull"];

    std::string urlProfilSTRING = urlProfilVALUE.asString();
    std::string pseudoSTRING = pseudoVALUE.asString();
    std::string realnameSTRING = realnameVALUE.asString();
    std::string lastLogOffSTRING = lastLogOffVALUE.asString();
    int a = std::atoi(lastLogOffSTRING.c_str());
    time_t b = a;
    status = statusVALUE.asInt();
    commentpermission = commentPermissionVALUE.asInt();
    std::string imageURLSTRING = imageVALUE.asString();


    pseudo = QString::fromStdString(pseudoSTRING);
    realname = QString::fromStdString(realnameSTRING);
    profilname = QString::fromStdString(urlProfilSTRING);
    lastlogoff = QString::fromStdString(ctime(&b));
    imageURL = QString::fromStdString(imageURLSTRING);
    //lastlogoff = QString::fromStdString(lastLogOffSTRING);



}

QString ParserURL::chercherPseudo()
{
    return pseudo;
}

QString ParserURL::chercherRealname()
{
    return realname;
}
QString ParserURL::chercherProfilname()
{
    return profilname;
}

QString ParserURL::chercherLastLogOff()
{
    return lastlogoff;
}
int ParserURL::chercherStatus()
{
    return status;
}
bool ParserURL::chercherCommentPermission()
{
    if (commentpermission==1)
        return true;
    else
        return false;

}
QString ParserURL::chercherURLimage()
{
    return imageURL;
}

ParserURL::~ParserURL(){}
