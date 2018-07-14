#ifndef PARSER_URL_H
#define PARSER_URL_H

#include <QtNetwork>
#include <iostream>


class ParserURL {

    public:
    ParserURL();
    ~ParserURL();

    void parser(std::string text_json);
    QString chercherPseudo();
    QString chercherRealname();
    QString chercherProfilname();
    QString chercherLastLogOff();
    int chercherStatus();
    bool chercherCommentPermission();
    QString chercherURLimage();


    private:

    QString pseudo;
    QString realname;
    QString profilname;
    QString lastlogoff;
    int status;
    int commentpermission;
    QString imageURL;
};

#endif // PARSER_URL_H
