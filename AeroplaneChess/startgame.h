#ifndef STARTGAME_H
#define STARTGAME_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QLabel>
#include <QAction>

#include "game.h"

class StartGame : public QWidget
{
    Q_OBJECT
public:
    StartGame();
    ~StartGame();

public slots:
    void slotClose();
    void slotBegin();

protected:
    Game *m_Game;

    QVBoxLayout *m_LayoutSG;
    QLabel *m_label;
    QPushButton *m_StartG;
    QPushButton *m_CloseG;

    QRadioButton *m_play2;
    QRadioButton *m_play3;
    QRadioButton *m_play4;

    int numPlayers = 0;

};

#endif // STARTGAME_H
