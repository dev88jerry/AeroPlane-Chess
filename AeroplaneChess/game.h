#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QString>
#include <QMouseEvent>
#include <QPainter>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "wingame.h"

class Game : public QWidget
{
    Q_OBJECT
public:
    Game();
    Game(int players);
    ~Game();    
    void Dice();
    void wait();
    void nextTurn();
    bool canMove();
    void myTurn();
    void movePiece();
    void greenPiece();
    void yellowPiece();
    void redPiece();
    void bluePiece();
    void loadBoard();
    void mouseReleaseEvent(QMouseEvent *event);
    void paint(int xLoc, int yLoc);
    void paint(int playerC, int xLoc, int yLoc);
    void paint(int playerC, int xLoc, int yLoc, int pStack);
    bool winGame();
    void clearPaint(int xLoc, int yLoc);
    void collision(char col, int lastP);
    void stack();

public slots:
    void slotClose();
    void slotDice();
    void slotWin();

protected:
    WinGame *m_WinG;

    QGroupBox *m_BoardA();
    QGroupBox *m_DiceA();

    QGridLayout *m_Grid;
    QPushButton *m_Close;
    QLabel *m_DiceChange;
    QLabel *m_CurTurn;
    QLabel *m_NextTurn;
    QLabel *m_BoardImg;
    QPainter *m_Print;

    unsigned int diceRes = 0;
    bool paintDis = false;
    bool changeT = false;
    bool loadB = false;
    unsigned int playerTurn = 0;
    unsigned int numPlayers = 0;
    unsigned int ptMODnp = 0;

    int boardY[58]={0};
    int yellowLoc[58]={0};
    unsigned int xYellow = 0;
    unsigned int yYellow = 0;
    int boardG[58]={0};
    int greenLoc[58]={0};
    unsigned int xGreen = 0;
    unsigned int yGreen = 0;
    int boardR[58]={0};
    int redLoc[58]={0};
    unsigned int xRed = 0;
    unsigned int yRed = 0;
    int boardB[58]={0};
    int blueLoc[58]={0};
    unsigned int xBlue = 0;
    unsigned int yBlue = 0;

    unsigned int xc=0, yc=0;
    int xp=-1, yp=-1;

    char winner;
};

#endif // GAME_H
