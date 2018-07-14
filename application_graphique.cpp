#include "application_graphique.h"
#include "image_downloader.h"
#include "get_url.h"
#include "parser_url.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QMenu>
#include <windows.h>
#include <QPixmap>
#include <QLineEdit>

Application::Application()
{

    setPalette(QPalette(QColor(127, 127, 127)));
    setAutoFillBackground(true);

    setFixedSize(950,425);
    layoutPrincipal = new QVBoxLayout;
    layoutTableauHaut = new QGridLayout;
    texteSteamResolver = new QLabel;
    cleSteam = new QLineEdit;
    steamidAEntrer = new QLineEdit;
    layoutTableauBas = new QGridLayout;
    rechercher = new QPushButton;

    rechercher->setStyleSheet("QPushButton {color: white; background-color : grey; border-width: 211px; border-color : white;font: bold 14px; }");
    cleSteam->setFixedHeight(25);
    cleSteam->setStyleSheet("QLineEdit {color: black; border: 2px black}");
    steamidAEntrer->setText("STEAMID");
    cleSteam->setEchoMode(QLineEdit::Password);
    steamidAEntrer->setFixedHeight(25);
    steamidAEntrer->setStyleSheet("QLineEdit {color: black; border: 2px black}");
    rechercher->setFixedHeight(35);
    layoutTableauHaut->setHorizontalSpacing(22);

    image = new QPixmap("images\\steamlogo.jpg");
    m_label = new QLabel;
    m_label->setPixmap(*image);

    cleSteam->setStyleSheet("QLabel { font: 11pt;}");
    steamidAEntrer->setStyleSheet("QLabel { font: 12pt; color: grey}");

    pseudo = new QLabel;
    pseudo->setText("{PSEUDO}");
    pseudo->setStyleSheet("QLabel { font: 18pt; }");
    realname = new QLabel;
    realname->setText("{Vrai nom}");
    realname->setStyleSheet("QLabel { font: 12pt; }");
    lastConnection = new QLabel;
    lastConnection->setText("Dernière connection ->");
    lastConnection->setStyleSheet("QLabel { font: 11pt; }");
    commentaires = new QLabel;
    commentaires->setText("Commentaires désactivés");
    commentaires->setStyleSheet("QLabel { font: 11pt; color: red}");
    urlProfile = new QLabel;
    urlProfile->setText("{Url du profil}");
    urlProfile->setStyleSheet("QLabel { font: 11pt; }");
    offlineOrOnline = new QLabel;
    offlineOrOnline->setText("Hors ligne");
    offlineOrOnline->setStyleSheet("QLabel { font: 11pt;color: red }");
    rechercher->setText("Rechercher");
    null = new QLabel;


    texteSteamResolver->setText("STEAM RESOLVER");
    texteSteamResolver->setStyleSheet("QLabel { font: 55pt; }");

    layoutPrincipal->addLayout(layoutTableauHaut);
    layoutPrincipal->addLayout(layoutTableauBas);


    layoutTableauHaut->addWidget(texteSteamResolver,0,1,3,4);
    layoutTableauHaut->addWidget(cleSteam,4,0,1,2);
    layoutTableauHaut->addWidget(steamidAEntrer,4,2,1,2);
    layoutTableauHaut->addWidget(rechercher,4,4,1,1);

    layoutTableauBas->addWidget(pseudo,0,4);
    layoutTableauBas->addWidget(realname,1,4);
    layoutTableauBas->addWidget(lastConnection,4,5,2,1);
    layoutTableauBas->addWidget(commentaires,3,2);
    layoutTableauBas->addWidget(urlProfile,4,2,2,1);
    layoutTableauBas->addWidget(offlineOrOnline,3,5);
    layoutTableauBas->addWidget(m_label,0,0,7,1);

    setLayout(layoutPrincipal);

    connect(rechercher, SIGNAL(pressed()), this, SLOT(rechercherCliquer()));
    connect(&monURL, SIGNAL(finTransfertSIGNAL(QString)), this, SLOT(rechercherPARSER(QString)));
}


void Application::rechercherCliquer(){
    monURL.get("http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key="+cleSteam->text().toStdString()+"&steamids="+steamidAEntrer->text().toStdString());
}
void Application::rechercherPARSER(QString text_json)
{
    //std::string text_json = monURL.getStringReply();

    //QString text_json = ("{\"response\":{\"players\":[{\"steamid\":\"76561197960435530\",\"communityvisibilitystate\":3,\"profilestate\":1,\"personaname\":\"Robin\",\"lastlogoff\":1530866214,\"profileurl\":\"https://steamcommunity.com/id/robinwalker/\",\"personastate\":0,\"realname\":\"Robin Walker\",\"primaryclanid\":\"103582791429521412\",\"timecreated\":1063407589,\"personastateflags\":0,\"loccountrycode\":\"US\",\"locstatecode\":\"WA\",\"loccityid\":3961}]}}");
    ParserURL monParser;
    monParser.parser(text_json.toStdString());

    pseudo->setText(monParser.chercherPseudo());
    realname->setText(monParser.chercherRealname());
    urlProfile->setText(monParser.chercherProfilname());
    lastConnection->setText("Dernière connexion: "+monParser.chercherLastLogOff());
    if (monParser.chercherStatus()==0){
        offlineOrOnline->setText("Hors ligne");
        offlineOrOnline->setStyleSheet("QLabel { font: 11pt;color: red }");}
    else if(monParser.chercherStatus()==1){
        offlineOrOnline->setText("En ligne");
         offlineOrOnline->setStyleSheet("QLabel { font: 11pt;color:  blue}");}
    else if(monParser.chercherStatus()==2){
        offlineOrOnline->setText("Occupé");
        offlineOrOnline->setStyleSheet("QLabel { font: 11pt;color:  orange}");}
    else if(monParser.chercherStatus()==3){
        offlineOrOnline->setText("Absent");
        offlineOrOnline->setStyleSheet("QLabel { font: 11pt;color:  yellow}");}
    else if(monParser.chercherStatus()==4){
        offlineOrOnline->setText("Dors");
        offlineOrOnline->setStyleSheet("QLabel { font: 11pt;color:  blue}");}
    else if(monParser.chercherStatus()==5){
        offlineOrOnline->setText("Cherche à échanger");
        offlineOrOnline->setStyleSheet("QLabel { font: 11pt;color:  blue}");}
    else if(monParser.chercherStatus()==6){
        offlineOrOnline->setText("Cherche à jouer");
        offlineOrOnline->setStyleSheet("QLabel { font: 11pt;color:  blue}");}
    if(monParser.chercherCommentPermission()){
        commentaires->setText("Commentaires autorisés");
        commentaires->setStyleSheet("QLabel { font: 11pt;color: green}");}
    else{
        commentaires->setText("Commentaires désactivés");
        commentaires->setStyleSheet("QLabel { font: 11pt;color:  red}");}

    QUrl imageUrl(monParser.chercherURLimage());
    m_pImgCtrl = new FileDownloader(imageUrl, this);

    connect(m_pImgCtrl, SIGNAL (downloaded()), this, SLOT (loadImage()));
}

void Application::loadImage()
{
 QPixmap buttonImage;
 buttonImage.loadFromData(m_pImgCtrl->downloadedData());

 m_label->setPixmap(buttonImage);
}


Application::~Application()
{

}
