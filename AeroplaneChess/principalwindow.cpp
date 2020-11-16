#include "principalwindow.h"
#include <QMenuBar>
#include <QApplication>

PrincipalWindow::PrincipalWindow()
{
    m_menu = new QMenu;
    m_WinAbout = new About;
    m_WinRules = new Rules;
    m_WinSGame = new StartGame;
    m_TestGame = new TestGameDraw;

    m_menu = menuBar()->addMenu("Game");
    m_NewGame = new QAction("New Game");
    m_Quit = new QAction("Quit");

    m_menu->addAction(m_NewGame);
    QObject::connect(m_NewGame, SIGNAL(triggered(bool)),this, SLOT(runGame()));
    m_menu->addAction(m_Quit);
    QObject::connect(m_Quit, SIGNAL(triggered(bool)), qApp, SLOT(quit()));

    m_menu = menuBar()->addMenu("Help");
    m_Rules = new QAction("Rules");
    m_About = new QAction("About");

    m_menu->addAction(m_Rules);
    QObject::connect(m_Rules, SIGNAL(triggered(bool)), this, SLOT(runRules()));
    m_menu->addAction(m_About);
    QObject::connect(m_About, SIGNAL(triggered(bool)), this, SLOT(runAbout()));

    m_LayoutM = new QVBoxLayout;
    m_QuitP = new QPushButton("Quit");
    QObject::connect(m_QuitP, SIGNAL(clicked()), qApp, SLOT(quit()));
    m_NewGameP = new QPushButton("New Game");
    QObject::connect(m_NewGameP, SIGNAL(clicked()), this, SLOT(runGame()));

    m_Logo = new QLabel("Logo");
    m_Logo->setPixmap(QPixmap(":src/img/TestBoard.png"));

    m_LayoutM->addWidget(m_Logo);
    m_LayoutM->addWidget(m_NewGameP);
    m_LayoutM->addWidget(m_QuitP);

    m_MainW = new QWidget();
    m_MainW->setLayout(m_LayoutM);
    setCentralWidget(m_MainW);
}

PrincipalWindow::~PrincipalWindow()
{

}

void PrincipalWindow::runAbout()
{
    m_WinAbout->show();
}

void PrincipalWindow::runRules()
{
    m_WinRules->show();
}

void PrincipalWindow::runGame()
{
    m_WinSGame->show();
    //m_TestGame->show();
}
