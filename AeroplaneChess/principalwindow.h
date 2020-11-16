#ifndef PRINCIPALWINDOW_H
#define PRINCIPALWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

#include "about.h"
#include "rules.h"
#include "game.h"
#include "startgame.h"
#include "testgamedraw.h"

class PrincipalWindow : public QMainWindow
{
    Q_OBJECT
public:
    PrincipalWindow();
    ~PrincipalWindow();

public slots:
    void runAbout();
    void runRules();
    void runGame();

protected:
    QMenu *m_menu;
    QAction *m_NewGame;
    QAction *m_Quit;
    QAction *m_About;
    QAction *m_Rules;

    QPushButton *m_QuitP;
    QPushButton *m_NewGameP;
    QLabel *m_Logo;
    QVBoxLayout *m_LayoutM;
    QWidget *m_MainW;

    About *m_WinAbout;
    Rules *m_WinRules;
    Game *m_WinGame;
    StartGame *m_WinSGame;
    TestGameDraw *m_TestGame;

};

#endif // PRINCIPALWINDOW_H
