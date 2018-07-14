#ifndef APPLICATION_GRAPHIQUE_H
#define APPLICATION_GRAPHIQUE_H

#endif // APPLICATION_GRAPHIQUE_H
#include <QWidget>
#include "get_url.h"
#include "image_downloader.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QLineEdit>

class Application : public QWidget
{
    Q_OBJECT

public:
    Application();
    ~Application();

private:

    QVBoxLayout *layoutPrincipal;
    QGridLayout *layoutTableauHaut;
    QGridLayout *layoutTableauBas;
    QLabel *texteSteamResolver;
    QLineEdit *cleSteam;
    QLineEdit *steamidAEntrer;
    QPushButton *rechercher;

    QPixmap *image;
    QLabel *m_label;

    QLabel *pseudo;
    QLabel *realname;
    QLabel *steamid;
    QLabel *offlineOrOnline;
    QLabel *lastConnection;
    QLabel *urlProfile;
    QLabel *commentaires;
    QLabel *null;

    GetURL monURL;
    FileDownloader *m_pImgCtrl;
private slots:
    void rechercherCliquer();
    void rechercherPARSER(QString);
    void loadImage();

};
