#include "startgame.h"
#include <QDebug>

StartGame::StartGame()
{


    m_LayoutSG = new QVBoxLayout();

    m_label = new QLabel("Select the number of players");

    m_play2 = new QRadioButton("2 players");
    m_play3 = new QRadioButton("3 players");
    m_play4 = new QRadioButton("4 players");

    m_StartG = new QPushButton("Start Game");
    QObject::connect(m_StartG, SIGNAL(clicked()), this, SLOT(slotBegin()));

    m_CloseG = new QPushButton("Close");
    QObject::connect(m_CloseG, SIGNAL(clicked()), this, SLOT(slotClose()));

    m_LayoutSG->addWidget(m_label);
    m_LayoutSG->addWidget(m_play2);
    m_LayoutSG->addWidget(m_play3);
    m_LayoutSG->addWidget(m_play4);
    m_LayoutSG->addWidget(m_StartG);
    m_LayoutSG->addWidget(m_CloseG);

    setLayout(m_LayoutSG);
}

StartGame::~StartGame()
{

}

void StartGame::slotClose()
{
    close();
}

void StartGame::slotBegin()
{       
    close();

    if(m_play2->isChecked())
    {
        numPlayers = 2;
    }
    else if(m_play3->isChecked())
    {
        numPlayers = 3;
    }
    else if(m_play4->isChecked())
    {
        numPlayers = 4;
    }
    else
    {
        numPlayers = 4;
    }

    m_Game = new Game(numPlayers);

    m_Game->show();

}
