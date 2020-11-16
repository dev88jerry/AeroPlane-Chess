/*
 * for android game use gyro to "roll" dice
 * fix move piece function
 * ie still use switch case but then call moveYellow/moveGreen etc... to move piece
 * write more functions as above
 * same for loadBoard and collision
 * most of the parts which copy/paste was done
 */

#include "game.h"
#include <QDebug>
#include <string>
#include <thread>
#include <chrono>

Game::Game() {
    m_Grid = new QGridLayout();

    m_Grid -> addWidget(m_BoardA(), 0, 0);
    m_Grid -> addWidget(m_DiceA(), 0, 1);

    m_Close = new QPushButton("Close");
    QObject::connect(m_Close, SIGNAL(clicked(bool)), this, SLOT(slotClose()));

    m_Grid -> addWidget(m_Close, 1, 0, 1, 2);

    setLayout(m_Grid);
}

Game::Game(int players) {
    m_Grid = new QGridLayout();

    numPlayers = players;

    m_Grid -> addWidget(m_BoardA(), 0, 0);
    m_Grid -> addWidget(m_DiceA(), 0, 1);

    m_Close = new QPushButton("Close");
    QObject::connect(m_Close, SIGNAL(clicked(bool)), this, SLOT(slotClose()));

    m_Grid -> addWidget(m_Close, 1, 0, 1, 2);

    setLayout(m_Grid);
}

Game::~Game() {

}

void Game::Dice() {
    srand(time(0));

    diceRes = rand() % 6 + 1;

    std::string s;
    s = std::to_string(diceRes);
    QString st = QString::fromUtf8(s.c_str());

    m_DiceChange -> setText(st);
    myTurn();

    if (!winGame()) {
        if (canMove()) {
            //qDebug()<<"Moving";
        }
        nextTurn();
    }
    playerTurn++;
    if (diceRes == 6) {
        playerTurn--;
    }
    //myTurn();
}

void Game::wait() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

void Game::nextTurn() {
    int t = ptMODnp;

    switch (numPlayers) {
    case 2:
        if (t == 1) {
            m_CurTurn -> setText("Yellow");
            m_NextTurn -> setText("Green");
            if (diceRes == 6) {
                m_CurTurn -> setText("Yellow");
                m_NextTurn -> setText("Yellow");
                changeT = true;
            }
        }
        else {
            m_CurTurn -> setText("Green");
            m_NextTurn -> setText("Yellow");
            if (diceRes == 6) {
                m_CurTurn -> setText("Green");
                m_NextTurn -> setText("Green");
                changeT = true;
            }
        }
        break;

    case 3:
        if (t == 0) {
            m_CurTurn -> setText("Green");
            m_NextTurn -> setText("Red");
            if (diceRes == 6) {
                m_CurTurn -> setText("Green");
                m_NextTurn -> setText("Green");
                changeT = true;
            }
        }
        else if (t == 1) {
            m_CurTurn -> setText("Red");
            m_NextTurn -> setText("Yellow");
            if (diceRes == 6) {
                m_CurTurn -> setText("Red");
                m_NextTurn -> setText("Red");
                changeT = true;
            }
        }
        else {
            m_CurTurn -> setText("Yellow");
            m_NextTurn -> setText("Green");
            if (diceRes == 6) {
                m_CurTurn -> setText("Yellow");
                m_NextTurn -> setText("Yellow");
                changeT = true;
            }

        }
        break;

    case 4:
        if (t == 0) {
            m_CurTurn -> setText("Green");
            m_NextTurn -> setText("Red");
            if (diceRes == 6) {
                m_CurTurn -> setText("Green");
                m_NextTurn -> setText("Green");
                changeT = true;
            }
        }
        else if (t == 1) {
            m_CurTurn -> setText("Red");
            m_NextTurn -> setText("Blue");
            if (diceRes == 6) {
                m_CurTurn -> setText("Red");
                m_NextTurn -> setText("Red");
                changeT = true;
            }
        }
        else if (t == 2) {
            m_CurTurn -> setText("Blue");
            m_NextTurn -> setText("Yellow");
            if (diceRes == 6) {
                m_CurTurn -> setText("Blue");
                m_NextTurn -> setText("Blue");
                changeT = true;
            }
        }
        else {
            m_CurTurn -> setText("Yellow");
            m_NextTurn -> setText("Green");
            if (diceRes == 6) {
                m_CurTurn -> setText("Yellow");
                m_NextTurn -> setText("Yellow");
                changeT = true;
            }
        }
        break;
    }
}

bool Game::canMove() {
    bool retV = false;
    int t = ptMODnp;
    int r = diceRes;

    switch (numPlayers) {
    case 2:
        if (t == 1) {
            //green
            if (r != 6 && boardG[0] == 4) {
                retV = false;
            } else {
                retV = true;
                changeT = true;
            }
        }
        else {
            //yellow
            if (r != 6 && boardY[0] == 4) {
                retV = false;
            } else {
                retV = true;
                changeT = true;
            }
        }
        break;

    case 3:
        if (t == 0) {
            //green
            if (r != 6 && boardG[0] == 4) {
                retV = false;
            } else {
                retV = true;
                changeT = true;
            }
        }
        else if (t == 1) {
            //red
            if (r != 6 && boardR[0] == 4) {
                retV = false;
            } else {
                retV = true;
                changeT = true;
            }
        }
        else {
            //yellow
            if (r != 6 && boardY[0] == 4) {
                retV = false;
            } else {
                retV = true;
                changeT = true;
            }
        }
        break;

    case 4:
        if (t == 0) {
            //green
            if (r != 6 && boardG[0] == 4) {
                retV = false;
            } else {
                retV = true;
                changeT = true;
            }
        }
        else if (t == 1) {
            //red
            if (r != 6 && boardR[0] == 4) {
                retV = false;
            } else {
                retV = true;
                changeT = true;
            }
        }
        else if (t == 2) {
            //blue
            if (r != 6 && boardB[0] == 4) {
                retV = false;
            } else {
                retV = true;
                changeT = true;
            }
        }
        else {
            //yellow
            if (r != 6 && boardY[0] == 4) {
                retV = false;
            } else {
                retV = true;
                changeT = true;
            }
        }
        break;
    }

    return retV;
}

void Game::myTurn() {
    //qDebug() << playerTurn;
    ptMODnp = playerTurn % numPlayers;
}

void Game::movePiece() {
    int ColorTurn = ptMODnp;

    switch (numPlayers) {
    case 2:
        if (ColorTurn == 0) {
            //green
            if (boardG[0] != 0 && diceRes == 6) {
                if (changeT) {
                    if (xc > 720 && xc < 770 && yc > 80 && yc < 120) {
                        boardG[1]++;
                        int stackN = boardG[1];
                        paint(ColorTurn, 663, 80);
                        if (stackN > 1) {
                            paint(ColorTurn, 663, 80, stackN);
                        }
                        boardG[0]--;
                        paint(750, 100);
                        changeT = false;
                    }
                    else if (xc > 820 && xc < 870 && yc > 80 && yc < 120) {
                        boardG[1]++;
                        int stackN = boardG[1];
                        paint(ColorTurn, 663, 80);
                        if (stackN > 1) {
                            paint(ColorTurn, 663, 80, stackN);
                        }
                        boardG[0]--;
                        paint(850, 100);
                        changeT = false;
                    }
                    else if (xc > 720 && xc < 770 && yc > 180 && yc < 220) {
                        boardG[1]++;
                        int stackN = boardG[1];
                        paint(ColorTurn, 663, 80);
                        if (stackN > 1) {
                            paint(ColorTurn, 663, 80, stackN);
                        }
                        boardG[0]--;
                        paint(750, 200);
                        changeT = false;
                    }
                    else if (xc > 820 && xc < 870 && yc > 180 && yc < 220) {
                        boardG[1]++;
                        int stackN = boardG[1];
                        paint(ColorTurn, 663, 80);
                        if (stackN > 1) {
                            paint(ColorTurn, 663, 80, stackN);
                        }
                        boardG[0]--;
                        paint(850, 200);
                        changeT = false;
                    }
                }
            }
            else {
                if (changeT) {
                    int jump = 0;
                    for (int i = 1; i < 58; i++) {
                        if (boardG[i] != 0) {
                            xGreen = greenLoc[i] / 1000;
                            yGreen = greenLoc[i] % 1000;

                            if (xc > xGreen - 40 && xc < xGreen + 40 && yc > yGreen - 40 && yc < yGreen + 40) {
                                if (i + diceRes < 52) {
                                    jump = i + diceRes;
                                    collision('g', jump);
                                    paint(xGreen, yGreen);
                                    int x = greenLoc[i + diceRes] / 1000;
                                    int y = greenLoc[i + diceRes] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardG[i + diceRes]++;
                                    int stackN = boardG[i + diceRes];
                                    if (stackN > 1) {
                                        paint(ColorTurn, x, y, stackN);
                                    }
                                    boardG[i]--;
                                    int stackP = boardG[i];
                                    if (stackP == 1) {
                                        paint(ColorTurn, xGreen, yGreen);
                                    }
                                    else if (stackP > 1) {
                                        paint(ColorTurn, xGreen, yGreen, stackP);
                                    }
                                    changeT = false;
                                    break;
                                }
                                else if (i + diceRes >= 52 && i + diceRes < 57) {
                                    paint(xGreen, yGreen);
                                    int x = greenLoc[i + diceRes] / 1000;
                                    int y = greenLoc[i + diceRes] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardG[i + diceRes]++;
                                    int stackN = boardG[i + diceRes];
                                    if (stackN > 1) {
                                        paint(ColorTurn, x, y, stackN);
                                    }
                                    jump = i + diceRes;
                                    boardG[i]--;
                                    int stackP = boardG[i];
                                    if (stackP == 1) {
                                        paint(ColorTurn, xGreen, yGreen);
                                    }
                                    else if (stackP > 1) {
                                        paint(ColorTurn, xGreen, yGreen, stackP);
                                    }
                                    changeT = false;
                                    break;
                                }
                                else if (i + diceRes == 57) {
                                    paint(xGreen, yGreen);
                                    int x = greenLoc[57] / 1000;
                                    int y = greenLoc[57] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardG[57]++;
                                    boardG[i]--;
                                    clearPaint(x, y);
                                    if (winGame()) {
                                        qDebug() << "Win";
                                    }
                                    changeT = false;
                                    break;
                                }
                                else {
                                    int j = i + diceRes;
                                    int ret = j - 57;
                                    int fp = 57 - ret;
                                    paint(xGreen, yGreen);
                                    int x = greenLoc[fp] / 1000;
                                    int y = greenLoc[fp] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardG[fp]++;
                                    int stackN = boardG[fp];
                                    if (stackN > 1) {
                                        paint(ColorTurn, x, y, stackN);
                                    }
                                    boardG[i]--;
                                    int stackP = boardG[i];
                                    if (stackP == 1) {
                                        paint(ColorTurn, xGreen, yGreen);
                                    }
                                    else if (stackP > 1) {
                                        paint(ColorTurn, xGreen, yGreen, stackP);
                                    }
                                    changeT = false;
                                    break;
                                }
                            }
                        }
                    }
                    for (int i = 0; i < 12; i++) {
                        int j = 4 * i + 3;
                        if (jump == j) {
                            if (i == 4) {
                                j = 4 * 7 + 3;
                            }
                            else {
                                j += 4;
                            }
                            collision('g', j);
                            int x = greenLoc[jump] / 1000;
                            int y = greenLoc[jump] % 1000;
                            paint(x, y);
                            boardG[jump]--;
                            int stackP = boardG[jump];
                            if (stackP == 1) {
                                paint(ColorTurn, x, y);
                            }
                            else if (stackP > 1) {
                                paint(ColorTurn, x, y, stackP);
                            }
                            int nx = greenLoc[j] / 1000;
                            int ny = greenLoc[j] % 1000;
                            paint(ColorTurn, nx, ny);
                            boardG[j]++;
                            int stackN = boardG[j];
                            if (stackN > 1) {
                                paint(ColorTurn, nx, ny, stackN);
                            }
                            changeT = false;
                            break;
                        }
                    }
                }
            }
        }
        else {
            //yellow
            if (boardY[0] != 0 && diceRes == 6) {
                if (xc > 70 && xc < 120 && yc > 80 && yc < 120) {
                    boardY[1]++;
                    int stackN = boardY[1];
                    paint(ColorTurn, 79, 287);
                    if (stackN > 1) {
                        paint(ColorTurn, 79, 287, stackN);
                    }
                    boardY[0]--;
                    paint(100, 100);
                    changeT = false;
                }
                else if (xc > 170 && xc < 220 && yc > 80 && yc < 120) {
                    boardY[1]++;
                    int stackN = boardY[1];
                    paint(ColorTurn, 79, 287);
                    if (stackN > 1) {
                        paint(ColorTurn, 79, 287, stackN);
                    }
                    boardY[0]--;
                    paint(200, 100);
                    changeT = false;
                }
                else if (xc > 70 && xc < 120 && yc > 180 && yc < 220) {
                    boardY[1]++;
                    int stackN = boardY[1];
                    paint(ColorTurn, 79, 287);
                    if (stackN > 1) {
                        paint(ColorTurn, 79, 287, stackN);
                    }
                    boardY[0]--;
                    paint(100, 200);
                    changeT = false;
                }
                else if (xc > 170 && xc < 220 && yc > 180 && yc < 220) {
                    boardY[1]++;
                    int stackN = boardY[1];
                    paint(ColorTurn, 79, 287);
                    if (stackN > 1) {
                        paint(ColorTurn, 79, 287, stackN);
                    }
                    boardY[0]--;
                    paint(200, 200);
                    changeT = false;
                }
            }
            else {
                if (changeT) {
                    int jump = 0;
                    for (int i = 1; i < 58; i++) {
                        if (boardY[i] != 0) {
                            xYellow = yellowLoc[i] / 1000;
                            yYellow = yellowLoc[i] % 1000;

                            if (xc > xYellow - 40 && xc < xYellow + 40 && yc > yYellow - 40 && yc < yYellow + 40) {
                                if (i + diceRes < 52) {
                                    jump = i + diceRes;
                                    collision('y', jump);
                                    paint(xYellow, yYellow);
                                    int x = yellowLoc[i + diceRes] / 1000;
                                    int y = yellowLoc[i + diceRes] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardY[i + diceRes]++;
                                    int stackN = boardY[i + diceRes];
                                    if (stackN > 1) {
                                        paint(ColorTurn, x, y, stackN);
                                    }
                                    boardY[i]--;
                                    int stackP = boardY[i];
                                    if (stackP == 1) {
                                        paint(ColorTurn, xYellow, yYellow);
                                    }
                                    else if (stackP > 1) {
                                        paint(ColorTurn, xYellow, yYellow, stackP);
                                    }
                                    changeT = false;
                                    break;
                                }
                                else if (i + diceRes >= 52 && i + diceRes < 57) {
                                    paint(xYellow, yYellow);
                                    int x = yellowLoc[i + diceRes] / 1000;
                                    int y = yellowLoc[i + diceRes] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardY[i + diceRes]++;
                                    int stackN = boardY[i + diceRes];
                                    if (stackN > 1) {
                                        paint(ColorTurn, x, y, stackN);
                                    }
                                    jump = i + diceRes;
                                    boardY[i]--;
                                    int stackP = boardY[i];
                                    if (stackP == 1) {
                                        paint(ColorTurn, xYellow, yYellow);
                                    }
                                    else if (stackP > 1) {
                                        paint(ColorTurn, xYellow, yYellow, stackP);
                                    }
                                    changeT = false;
                                    break;
                                }
                                else if (i + diceRes == 57) {
                                    paint(xYellow, yYellow);
                                    int x = yellowLoc[57] / 1000;
                                    int y = yellowLoc[57] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardY[57]++;
                                    boardY[i]--;
                                    clearPaint(x, y);
                                    if (winGame()) {
                                        qDebug() << "Win";
                                    }
                                    changeT = false;
                                    break;
                                }
                                else {
                                    int j = i + diceRes;
                                    int ret = j - 57;
                                    int fp = 57 - ret;
                                    paint(xYellow, yYellow);
                                    int x = yellowLoc[fp] / 1000;
                                    int y = yellowLoc[fp] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardY[fp]++;
                                    int stackN = boardY[fp];
                                    if (stackN > 1) {
                                        paint(ColorTurn, x, y, stackN);
                                    }
                                    boardY[i]--;
                                    int stackP = boardY[i];
                                    if (stackP == 1) {
                                        paint(ColorTurn, xYellow, yYellow);
                                    }
                                    else if (stackP > 1) {
                                        paint(ColorTurn, xYellow, yYellow, stackP);
                                    }
                                    changeT = false;
                                    break;
                                }
                            }
                        }
                    }

                    for (int i = 0; i < 12; i++) {
                        int j = 4 * i + 3;
                        if (jump == j) {
                            if (i == 4) {
                                j = 4 * 7 + 3;
                            }
                            else {
                                j += 4;
                            }
                            collision('y', j);
                            int x = yellowLoc[jump] / 1000;
                            int y = yellowLoc[jump] % 1000;
                            paint(x, y);
                            boardY[jump]--;
                            int stackP = boardY[jump];
                            if (stackP == 1) {
                                paint(ColorTurn, x, y);
                            }
                            else if (stackP > 1) {
                                paint(ColorTurn, x, y, stackP);
                            }
                            int nx = yellowLoc[j] / 1000;
                            int ny = yellowLoc[j] % 1000;
                            paint(ColorTurn, nx, ny);
                            boardY[j]++;
                            int stackN = boardY[j];
                            if (stackN > 1) {
                                paint(ColorTurn, nx, ny, stackN);
                            }
                            changeT = false;
                            break;
                        }
                    }
                }
            }
        }
        break;

    case 3:
        if (ColorTurn == 0) {
            //green
            if (boardG[0] != 0 && diceRes == 6) {
                if (changeT) {
                    if (xc > 720 && xc < 770 && yc > 80 && yc < 120) {
                        boardG[1]++;
                        int stackN = boardG[1];
                        paint(ColorTurn, 663, 80);
                        if (stackN > 1) {
                            paint(ColorTurn, 663, 80, stackN);
                        }
                        boardG[0]--;
                        paint(750, 100);
                        changeT = false;
                    }
                    else if (xc > 820 && xc < 870 && yc > 80 && yc < 120) {
                        boardG[1]++;
                        int stackN = boardG[1];
                        paint(ColorTurn, 663, 80);
                        if (stackN > 1) {
                            paint(ColorTurn, 663, 80, stackN);
                        }
                        boardG[0]--;
                        paint(850, 100);
                        changeT = false;
                    }
                    else if (xc > 720 && xc < 770 && yc > 180 && yc < 220) {
                        boardG[1]++;
                        int stackN = boardG[1];
                        paint(ColorTurn, 663, 80);
                        if (stackN > 1) {
                            paint(ColorTurn, 663, 80, stackN);
                        }
                        boardG[0]--;
                        paint(750, 200);
                        changeT = false;
                    }
                    else if (xc > 820 && xc < 870 && yc > 180 && yc < 220) {
                        boardG[1]++;
                        int stackN = boardG[1];
                        paint(ColorTurn, 663, 80);
                        if (stackN > 1) {
                            paint(ColorTurn, 663, 80, stackN);
                        }
                        boardG[0]--;
                        paint(850, 200);
                        changeT = false;
                    }
                }
            }
            else {
                if (changeT) {
                    int jump = 0;
                    for (int i = 1; i < 58; i++) {
                        if (boardG[i] != 0) {
                            xGreen = greenLoc[i] / 1000;
                            yGreen = greenLoc[i] % 1000;

                            if (xc > xGreen - 40 && xc < xGreen + 40 && yc > yGreen - 40 && yc < yGreen + 40) {
                                if (i + diceRes < 52) {
                                    jump = i + diceRes;
                                    collision('g', jump);
                                    paint(xGreen, yGreen);
                                    int x = greenLoc[i + diceRes] / 1000;
                                    int y = greenLoc[i + diceRes] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardG[i + diceRes]++;
                                    int stackN = boardG[i + diceRes];
                                    if (stackN > 1) {
                                        paint(ColorTurn, x, y, stackN);
                                    }
                                    boardG[i]--;
                                    int stackP = boardG[i];
                                    if (stackP == 1) {
                                        paint(ColorTurn, xGreen, yGreen);
                                    }
                                    else if (stackP > 1) {
                                        paint(ColorTurn, xGreen, yGreen, stackP);
                                    }
                                    changeT = false;
                                    break;
                                }
                                else if (i + diceRes >= 52 && i + diceRes < 57) {
                                    paint(xGreen, yGreen);
                                    int x = greenLoc[i + diceRes] / 1000;
                                    int y = greenLoc[i + diceRes] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardG[i + diceRes]++;
                                    int stackN = boardG[i + diceRes];
                                    if (stackN > 1) {
                                        paint(ColorTurn, x, y, stackN);
                                    }
                                    jump = i + diceRes;
                                    boardG[i]--;
                                    int stackP = boardG[i];
                                    if (stackP == 1) {
                                        paint(ColorTurn, xGreen, yGreen);
                                    }
                                    else if (stackP > 1) {
                                        paint(ColorTurn, xGreen, yGreen, stackP);
                                    }
                                    changeT = false;
                                    break;
                                }
                                else if (i + diceRes == 57) {
                                    paint(xGreen, yGreen);
                                    int x = greenLoc[57] / 1000;
                                    int y = greenLoc[57] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardG[57]++;
                                    boardG[i]--;
                                    clearPaint(x, y);
                                    if (winGame()) {
                                        qDebug() << "Win";
                                    }
                                    changeT = false;
                                    break;
                                }
                                else {
                                    int j = i + diceRes;
                                    int ret = j - 57;
                                    int fp = 57 - ret;
                                    paint(xGreen, yGreen);
                                    int x = greenLoc[fp] / 1000;
                                    int y = greenLoc[fp] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardG[fp]++;
                                    int stackN = boardG[fp];
                                    if (stackN > 1) {
                                        paint(ColorTurn, x, y, stackN);
                                    }
                                    boardG[i]--;
                                    int stackP = boardG[i];
                                    if (stackP == 1) {
                                        paint(ColorTurn, xGreen, yGreen);
                                    }
                                    else if (stackP > 1) {
                                        paint(ColorTurn, xGreen, yGreen, stackP);
                                    }
                                    changeT = false;
                                    break;
                                }
                            }
                        }
                    }
                    for (int i = 0; i < 12; i++) {
                        int j = 4 * i + 3;
                        if (jump == j) {
                            if (i == 4) {
                                j = 4 * 7 + 3;
                            } else {
                                j += 4;
                            }
                            collision('g', j);
                            int x = greenLoc[jump] / 1000;
                            int y = greenLoc[jump] % 1000;
                            paint(x, y);
                            boardG[jump]--;
                            int stackP = boardG[jump];
                            if (stackP == 1) {
                                paint(ColorTurn, x, y);
                            }
                            else if (stackP > 1) {
                                paint(ColorTurn, x, y, stackP);
                            }
                            int nx = greenLoc[j] / 1000;
                            int ny = greenLoc[j] % 1000;
                            paint(ColorTurn, nx, ny);
                            boardG[j]++;
                            int stackN = boardG[j];
                            if (stackN > 1) {
                                paint(ColorTurn, nx, ny, stackN);
                            }
                            changeT = false;
                            break;
                        }
                    }
                }
            }
        }
        else if (ColorTurn == 1) {
            //red
            if (boardR[0] != 0 && diceRes == 6) {
                if (changeT) {
                    if (xc > 720 && xc < 770 && yc > 730 && yc < 770) {
                        boardR[1]++;
                        int stackN = boardR[1];
                        paint(ColorTurn, 869, 666);
                        if (stackN > 1) {
                            paint(ColorTurn, 869, 666, stackN);
                        }
                        boardR[0]--;
                        paint(750, 750);
                        changeT = false;
                    }
                    else if (xc > 820 && xc < 870 && yc > 730 && yc < 770) {
                        boardR[1]++;
                        int stackN = boardR[1];
                        paint(ColorTurn, 869, 666);
                        if (stackN > 1) {
                            paint(ColorTurn, 869, 666, stackN);
                        }
                        boardR[0]--;
                        paint(850, 750);
                        changeT = false;
                    }
                    else if (xc > 720 && xc < 770 && yc > 830 && yc < 870) {
                        boardR[1]++;
                        int stackN = boardR[1];
                        paint(ColorTurn, 869, 666);
                        if (stackN > 1) {
                            paint(ColorTurn, 869, 666, stackN);
                        }
                        boardR[0]--;
                        paint(750, 850);
                        changeT = false;
                    }
                    else if (xc > 820 && xc < 870 && yc > 830 && yc < 870) {
                        boardR[1]++;
                        int stackN = boardR[1];
                        paint(ColorTurn, 869, 666);
                        if (stackN > 1) {
                            paint(ColorTurn, 869, 666, stackN);
                        }
                        boardR[0]--;
                        paint(850, 850);
                        changeT = false;
                    }
                }
            }
            else {
                if (changeT) {
                    int jump = 0;
                    for (int i = 1; i < 59; i++) {
                        if (boardR[i] != 0) {
                            xRed = redLoc[i] / 1000;
                            yRed = redLoc[i] % 1000;
                            if (xc > xRed - 40 && xc < xRed + 40 && yc > yRed - 40 && yc < yRed + 40) {
                                if (i + diceRes < 52) {
                                    jump = i + diceRes;
                                    collision('r', jump);
                                    paint(xRed, yRed);
                                    int x = redLoc[i + diceRes] / 1000;
                                    int y = redLoc[i + diceRes] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardR[i + diceRes]++;
                                    int stackN = boardR[i + diceRes];
                                    if (stackN > 1) {
                                        paint(ColorTurn, x, y, stackN);
                                    }
                                    boardR[i]--;
                                    int stackP = boardR[i];
                                    if (stackP == 1) {
                                        paint(ColorTurn, xRed, yRed);
                                    }
                                    else if (stackP > 1) {
                                        paint(ColorTurn, xRed, yRed, stackP);
                                    }
                                    changeT = false;
                                    break;
                                }
                                else if (i + diceRes >= 52 && i + diceRes < 57) {
                                    paint(xRed, yRed);
                                    int x = redLoc[i + diceRes] / 1000;
                                    int y = redLoc[i + diceRes] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardR[i + diceRes]++;
                                    int stackN = boardR[i + diceRes];
                                    if (stackN > 1) {
                                        paint(ColorTurn, x, y, stackN);
                                    }
                                    jump = i + diceRes;
                                    boardR[i]--;
                                    int stackP = boardR[i];
                                    if (stackP == 1) {
                                        paint(ColorTurn, xRed, yRed);
                                    }
                                    else if (stackP > 1) {
                                        paint(ColorTurn, xRed, yRed, stackP);
                                    }
                                    changeT = false;
                                    break;
                                }
                                else if (i + diceRes == 57) {
                                    paint(xRed, yRed);
                                    int x = redLoc[57] / 1000;
                                    int y = redLoc[57] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardR[57]++;
                                    boardR[i]--;
                                    clearPaint(x, y);
                                    if (winGame()) {
                                        qDebug() << "Win";
                                    }
                                    changeT = false;
                                    break;
                                }
                                else {
                                    int j = i + diceRes;
                                    int ret = j - 57;
                                    int fp = 57 - ret;
                                    paint(xRed, yRed);
                                    int x = redLoc[fp] / 1000;
                                    int y = redLoc[fp] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardR[fp]++;
                                    int stackN = boardR[fp];
                                    if (stackN > 1) {
                                        paint(ColorTurn, x, y, stackN);
                                    }
                                    boardR[i]--;
                                    int stackP = boardR[i];
                                    if (stackP == 1) {
                                        paint(ColorTurn, xRed, yRed);
                                    }
                                    else if (stackP > 1) {
                                        paint(ColorTurn, xRed, yRed, stackP);
                                    }
                                    changeT = false;
                                    break;
                                }
                            }
                        }
                    }
                    for (int i = 0; i < 12; i++) {
                        int j = 4 * i + 3;
                        if (jump == j) {
                            if (i == 4) {
                                j = 4 * 7 + 3;
                            } else {
                                j += 4;
                            }
                            collision('r', j);
                            int x = redLoc[jump] / 1000;
                            int y = redLoc[jump] % 1000;
                            paint(x, y);
                            boardR[jump]--;
                            int stackP = boardR[jump];
                            if (stackP == 1) {
                                paint(ColorTurn, x, y);
                            }
                            else if (stackP > 1) {
                                paint(ColorTurn, x, y, stackP);
                            }
                            int nx = redLoc[j] / 1000;
                            int ny = redLoc[j] % 1000;
                            paint(ColorTurn, nx, ny);
                            boardR[j]++;
                            int stackN = boardR[j];
                            if (stackN > 1) {
                                paint(ColorTurn, nx, ny, stackN);
                            }
                            break;
                        }
                    }
                }
            }
        }
        else {
            //yellow
            if (boardY[0] != 0 && diceRes == 6) {
                if (xc > 70 && xc < 120 && yc > 80 && yc < 120) {
                    boardY[1]++;
                    int stackN = boardY[1];
                    paint(ColorTurn, 79, 287);
                    if (stackN > 1) {
                        paint(ColorTurn, 79, 287, stackN);
                    }
                    boardY[0]--;
                    paint(100, 100);
                    changeT = false;
                }
                else if (xc > 170 && xc < 220 && yc > 80 && yc < 120) {
                    boardY[1]++;
                    int stackN = boardY[1];
                    paint(ColorTurn, 79, 287);
                    if (stackN > 1) {
                        paint(ColorTurn, 79, 287, stackN);
                    }
                    boardY[0]--;
                    paint(200, 100);
                    changeT = false;
                }
                else if (xc > 70 && xc < 120 && yc > 180 && yc < 220) {
                    boardY[1]++;
                    int stackN = boardY[1];
                    paint(ColorTurn, 79, 287);
                    if (stackN > 1) {
                        paint(ColorTurn, 79, 287, stackN);
                    }
                    boardY[0]--;
                    paint(100, 200);
                    changeT = false;
                }
                else if (xc > 170 && xc < 220 && yc > 180 && yc < 220) {
                    boardY[1]++;
                    int stackN = boardY[1];
                    paint(ColorTurn, 79, 287);
                    if (stackN > 1) {
                        paint(ColorTurn, 79, 287, stackN);
                    }
                    boardY[0]--;
                    paint(200, 200);
                    changeT = false;
                }
            }
            else {
                if (changeT) {
                    int jump = 0;
                    for (int i = 1; i < 58; i++) {
                        if (boardY[i] != 0) {
                            xYellow = yellowLoc[i] / 1000;
                            yYellow = yellowLoc[i] % 1000;

                            if (xc > xYellow - 40 && xc < xYellow + 40 && yc > yYellow - 40 && yc < yYellow + 40) {
                                if (i + diceRes < 52) {
                                    jump = i + diceRes;
                                    collision('y', jump);
                                    paint(xYellow, yYellow);
                                    int x = yellowLoc[i + diceRes] / 1000;
                                    int y = yellowLoc[i + diceRes] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardY[i + diceRes]++;
                                    int stackN = boardY[i + diceRes];
                                    if (stackN > 1) {
                                        paint(ColorTurn, x, y, stackN);
                                    }
                                    boardY[i]--;
                                    int stackP = boardY[i];
                                    if (stackP == 1) {
                                        paint(ColorTurn, xYellow, yYellow);
                                    }
                                    else if (stackP > 1) {
                                        paint(ColorTurn, xYellow, yYellow, stackP);
                                    }
                                    changeT = false;
                                    break;
                                }
                                else if (i + diceRes >= 52 && i + diceRes < 57) {
                                    paint(xYellow, yYellow);
                                    int x = yellowLoc[i + diceRes] / 1000;
                                    int y = yellowLoc[i + diceRes] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardY[i + diceRes]++;
                                    int stackN = boardY[i + diceRes];
                                    if (stackN > 1) {
                                        paint(ColorTurn, x, y, stackN);
                                    }
                                    jump = i + diceRes;
                                    boardY[i]--;
                                    int stackP = boardY[i];
                                    if (stackP == 1) {
                                        paint(ColorTurn, xYellow, yYellow);
                                    }
                                    else if (stackP > 1) {
                                        paint(ColorTurn, xYellow, yYellow, stackP);
                                    }
                                    changeT = false;
                                    break;
                                }
                                else if (i + diceRes == 57) {
                                    paint(xYellow, yYellow);
                                    int x = yellowLoc[57] / 1000;
                                    int y = yellowLoc[57] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardY[57]++;
                                    boardY[i]--;
                                    clearPaint(x, y);
                                    if (winGame()) {
                                        qDebug() << "Win";
                                    }
                                    changeT = false;
                                    break;
                                }
                                else {
                                    int j = i + diceRes;
                                    int ret = j - 57;
                                    int fp = 57 - ret;
                                    paint(xYellow, yYellow);
                                    int x = yellowLoc[fp] / 1000;
                                    int y = yellowLoc[fp] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardY[fp]++;
                                    int stackN = boardY[fp];
                                    if (stackN > 1) {
                                        paint(ColorTurn, x, y, stackN);
                                    }
                                    boardY[i]--;
                                    int stackP = boardY[i];
                                    if (stackP == 1) {
                                        paint(ColorTurn, xYellow, yYellow);
                                    }
                                    else if (stackP > 1) {
                                        paint(ColorTurn, xYellow, yYellow, stackP);
                                    }
                                    changeT = false;
                                    break;
                                }
                            }
                        }
                    }

                    for (int i = 0; i < 12; i++) {
                        int j = 4 * i + 3;
                        if (jump == j) {
                            if (i == 4) {
                                j = 4 * 7 + 3;
                            }
                            else {
                                j += 4;
                            }
                            collision('y', j);
                            int x = yellowLoc[jump] / 1000;
                            int y = yellowLoc[jump] % 1000;
                            paint(x, y);
                            boardY[jump]--;
                            int stackP = boardY[jump];
                            if (stackP == 1) {
                                paint(ColorTurn, x, y);
                            }
                            else if (stackP > 1) {
                                paint(ColorTurn, x, y, stackP);
                            }
                            int nx = yellowLoc[j] / 1000;
                            int ny = yellowLoc[j] % 1000;
                            paint(ColorTurn, nx, ny);
                            boardY[j]++;
                            int stackN = boardY[j];
                            if (stackN > 1) {
                                paint(ColorTurn, nx, ny, stackN);
                            }
                            changeT = false;
                            break;
                        }
                    }
                }
            }
        }
        break;

    case 4:
        if (ColorTurn == 0) {
            //green
            if (boardG[0] != 0 && diceRes == 6) {
                if (changeT) {
                    if (xc > 720 && xc < 770 && yc > 80 && yc < 120) {
                        boardG[1]++;
                        int stackN = boardG[1];
                        paint(ColorTurn, 663, 80);
                        if (stackN > 1) {
                            paint(ColorTurn, 663, 80, stackN);
                        }
                        boardG[0]--;
                        paint(750, 100);
                        changeT = false;
                    }
                    else if (xc > 820 && xc < 870 && yc > 80 && yc < 120) {
                        boardG[1]++;
                        int stackN = boardG[1];
                        paint(ColorTurn, 663, 80);
                        if (stackN > 1) {
                            paint(ColorTurn, 663, 80, stackN);
                        }
                        boardG[0]--;
                        paint(850, 100);
                        changeT = false;
                    }
                    else if (xc > 720 && xc < 770 && yc > 180 && yc < 220) {
                        boardG[1]++;
                        int stackN = boardG[1];
                        paint(ColorTurn, 663, 80);
                        if (stackN > 1) {
                            paint(ColorTurn, 663, 80, stackN);
                        }
                        boardG[0]--;
                        paint(750, 200);
                        changeT = false;
                    }
                    else if (xc > 820 && xc < 870 && yc > 180 && yc < 220) {
                        boardG[1]++;
                        int stackN = boardG[1];
                        paint(ColorTurn, 663, 80);
                        if (stackN > 1) {
                            paint(ColorTurn, 663, 80, stackN);
                        }
                        boardG[0]--;
                        paint(850, 200);
                        changeT = false;
                    }
                }
            }
            else {
                if (changeT) {
                    int jump = 0;
                    for (int i = 1; i < 58; i++) {
                        if (boardG[i] != 0) {
                            xGreen = greenLoc[i] / 1000;
                            yGreen = greenLoc[i] % 1000;

                            if (xc > xGreen - 40 && xc < xGreen + 40 && yc > yGreen - 40 && yc < yGreen + 40) {
                                if (i + diceRes < 52) {
                                    jump = i + diceRes;
                                    collision('g', jump);
                                    paint(xGreen, yGreen);
                                    int x = greenLoc[i + diceRes] / 1000;
                                    int y = greenLoc[i + diceRes] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardG[i + diceRes]++;
                                    int stackN = boardG[i + diceRes];
                                    if (stackN > 1) {
                                        paint(ColorTurn, x, y, stackN);
                                    }
                                    boardG[i]--;
                                    int stackP = boardG[i];
                                    if (stackP == 1) {
                                        paint(ColorTurn, xGreen, yGreen);
                                    }
                                    else if (stackP > 1) {
                                        paint(ColorTurn, xGreen, yGreen, stackP);
                                    }
                                    changeT = false;
                                    break;
                                }
                                else if (i + diceRes >= 52 && i + diceRes < 57) {
                                    paint(xGreen, yGreen);
                                    int x = greenLoc[i + diceRes] / 1000;
                                    int y = greenLoc[i + diceRes] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardG[i + diceRes]++;
                                    int stackN = boardG[i + diceRes];
                                    if (stackN > 1) {
                                        paint(ColorTurn, x, y, stackN);
                                    }
                                    jump = i + diceRes;
                                    boardG[i]--;
                                    int stackP = boardG[i];
                                    if (stackP == 1) {
                                        paint(ColorTurn, xGreen, yGreen);
                                    }
                                    else if (stackP > 1) {
                                        paint(ColorTurn, xGreen, yGreen, stackP);
                                    }
                                    changeT = false;
                                    break;
                                }
                                else if (i + diceRes == 57) {
                                    paint(xGreen, yGreen);
                                    int x = greenLoc[57] / 1000;
                                    int y = greenLoc[57] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardG[57]++;
                                    boardG[i]--;
                                    clearPaint(x, y);
                                    if (winGame()) {
                                        qDebug() << "Win";
                                    }
                                    changeT = false;
                                    break;
                                }
                                else {
                                    int j = i + diceRes;
                                    int ret = j - 57;
                                    int fp = 57 - ret;
                                    paint(xGreen, yGreen);
                                    int x = greenLoc[fp] / 1000;
                                    int y = greenLoc[fp] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardG[fp]++;
                                    int stackN = boardG[fp];
                                    if (stackN > 1) {
                                        paint(ColorTurn, x, y, stackN);
                                    }
                                    boardG[i]--;
                                    int stackP = boardG[i];
                                    if (stackP == 1) {
                                        paint(ColorTurn, xGreen, yGreen);
                                    }
                                    else if (stackP > 1) {
                                        paint(ColorTurn, xGreen, yGreen, stackP);
                                    }
                                    changeT = false;
                                    break;
                                }
                            }
                        }
                    }
                    for (int i = 0; i < 12; i++) {
                        int j = 4 * i + 3;
                        if (jump == j) {
                            if (i == 4) {
                                j = 4 * 7 + 3;
                            }
                            else {
                                j += 4;
                            }
                            collision('g', j);
                            int x = greenLoc[jump] / 1000;
                            int y = greenLoc[jump] % 1000;
                            paint(x, y);
                            boardG[jump]--;
                            int stackP = boardG[jump];
                            if (stackP == 1) {
                                paint(ColorTurn, x, y);
                            }
                            else if (stackP > 1) {
                                paint(ColorTurn, x, y, stackP);
                            }
                            int nx = greenLoc[j] / 1000;
                            int ny = greenLoc[j] % 1000;
                            paint(ColorTurn, nx, ny);
                            boardG[j]++;
                            int stackN = boardG[j];
                            if (stackN > 1) {
                                paint(ColorTurn, nx, ny, stackN);
                            }
                            changeT = false;
                            break;
                        }
                    }
                }
            }
        }
        else if (ColorTurn == 1) {
            //red
            if (boardR[0] != 0 && diceRes == 6) {
                if (changeT) {
                    if (xc > 720 && xc < 770 && yc > 730 && yc < 770) {
                        boardR[1]++;
                        int stackN = boardR[1];
                        paint(ColorTurn, 869, 666);
                        if (stackN > 1) {
                            paint(ColorTurn, 869, 666, stackN);
                        }
                        boardR[0]--;
                        paint(750, 750);
                        changeT = false;
                    }
                    else if (xc > 820 && xc < 870 && yc > 730 && yc < 770) {
                        boardR[1]++;
                        int stackN = boardR[1];
                        paint(ColorTurn, 869, 666);
                        if (stackN > 1) {
                            paint(ColorTurn, 869, 666, stackN);
                        }
                        boardR[0]--;
                        paint(850, 750);
                        changeT = false;
                    }
                    else if (xc > 720 && xc < 770 && yc > 830 && yc < 870) {
                        boardR[1]++;
                        int stackN = boardR[1];
                        paint(ColorTurn, 869, 666);
                        if (stackN > 1) {
                            paint(ColorTurn, 869, 666, stackN);
                        }
                        boardR[0]--;
                        paint(750, 850);
                        changeT = false;
                    }
                    else if (xc > 820 && xc < 870 && yc > 830 && yc < 870) {
                        boardR[1]++;
                        int stackN = boardR[1];
                        paint(ColorTurn, 869, 666);
                        if (stackN > 1) {
                            paint(ColorTurn, 869, 666, stackN);
                        }
                        boardR[0]--;
                        paint(850, 850);
                        changeT = false;
                    }
                }
            }
            else {
                if (changeT) {
                    int jump = 0;
                    for (int i = 1; i < 59; i++) {
                        if (boardR[i] != 0) {
                            xRed = redLoc[i] / 1000;
                            yRed = redLoc[i] % 1000;
                            if (xc > xRed - 40 && xc < xRed + 40 && yc > yRed - 40 && yc < yRed + 40) {
                                if (i + diceRes < 52) {
                                    jump = i + diceRes;
                                    collision('r', jump);
                                    paint(xRed, yRed);
                                    int x = redLoc[i + diceRes] / 1000;
                                    int y = redLoc[i + diceRes] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardR[i + diceRes]++;
                                    int stackN = boardR[i + diceRes];
                                    if (stackN > 1) {
                                        paint(ColorTurn, x, y, stackN);
                                    }
                                    boardR[i]--;
                                    int stackP = boardR[i];
                                    if (stackP == 1) {
                                        paint(ColorTurn, xRed, yRed);
                                    }
                                    else if (stackP > 1) {
                                        paint(ColorTurn, xRed, yRed, stackP);
                                    }
                                    changeT = false;
                                    break;
                                }
                                else if (i + diceRes >= 52 && i + diceRes < 57) {
                                    paint(xRed, yRed);
                                    int x = redLoc[i + diceRes] / 1000;
                                    int y = redLoc[i + diceRes] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardR[i + diceRes]++;
                                    int stackN = boardR[i + diceRes];
                                    if (stackN > 1) {
                                        paint(ColorTurn, x, y, stackN);
                                    }
                                    jump = i + diceRes;
                                    boardR[i]--;
                                    int stackP = boardR[i];
                                    if (stackP == 1) {
                                        paint(ColorTurn, xRed, yRed);
                                    }
                                    else if (stackP > 1) {
                                        paint(ColorTurn, xRed, yRed, stackP);
                                    }
                                    changeT = false;
                                    break;
                                }
                                else if (i + diceRes == 57) {
                                    paint(xRed, yRed);
                                    int x = redLoc[57] / 1000;
                                    int y = redLoc[57] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardR[57]++;
                                    boardR[i]--;
                                    clearPaint(x, y);
                                    if (winGame()) {
                                        qDebug() << "Win";
                                    }
                                    changeT = false;
                                    break;
                                }
                                else {
                                    int j = i + diceRes;
                                    int ret = j - 57;
                                    int fp = 57 - ret;
                                    paint(xRed, yRed);
                                    int x = redLoc[fp] / 1000;
                                    int y = redLoc[fp] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardR[fp]++;
                                    int stackN = boardR[fp];
                                    if (stackN > 1) {
                                        paint(ColorTurn, x, y, stackN);
                                    }
                                    boardR[i]--;
                                    int stackP = boardR[i];
                                    if (stackP == 1) {
                                        paint(ColorTurn, xRed, yRed);
                                    }
                                    else if (stackP > 1) {
                                        paint(ColorTurn, xRed, yRed, stackP);
                                    }
                                    changeT = false;
                                    break;
                                }
                            }
                        }
                    }
                    for (int i = 0; i < 12; i++) {
                        int j = 4 * i + 3;
                        if (jump == j) {
                            if (i == 4) {
                                j = 4 * 7 + 3;
                            }
                            else {
                                j += 4;
                            }
                            collision('r', j);
                            int x = redLoc[jump] / 1000;
                            int y = redLoc[jump] % 1000;
                            paint(x, y);
                            boardR[jump]--;
                            int stackP = boardR[jump];
                            if (stackP == 1) {
                                paint(ColorTurn, x, y);
                            }
                            else if (stackP > 1) {
                                paint(ColorTurn, x, y, stackP);
                            }
                            int nx = redLoc[j] / 1000;
                            int ny = redLoc[j] % 1000;
                            paint(ColorTurn, nx, ny);
                            boardR[j]++;
                            int stackN = boardR[j];
                            if (stackN > 1) {
                                paint(ColorTurn, nx, ny, stackN);
                            }
                            break;
                        }
                    }
                }
            }
        }
        else if (ColorTurn == 2) {
            if (boardB[0] != 0 && diceRes == 6) {
                if (changeT) {
                    if (xc > 70 && xc < 120 && yc > 730 && yc < 770) {
                        boardB[1]++;
                        int stackN = boardB[1];
                        paint(ColorTurn, 285, 868);
                        if (stackN > 1) {
                            paint(ColorTurn, 285, 868, stackN);
                        }
                        boardB[0]--;
                        paint(100, 750);
                        changeT = false;
                    }
                    else if (xc > 170 && xc < 220 && yc > 730 && yc < 770) {
                        boardB[1]++;
                        int stackN = boardB[1];
                        paint(ColorTurn, 285, 868);
                        if (stackN > 1) {
                            paint(ColorTurn, 285, 868, stackN);
                        }
                        boardB[0]--;
                        paint(200, 750);
                        changeT = false;
                    }
                    else if (xc > 70 && xc < 120 && yc > 830 && yc < 870) {
                        boardB[1]++;
                        int stackN = boardB[1];
                        paint(ColorTurn, 285, 868);
                        if (stackN > 1) {
                            paint(ColorTurn, 285, 868, stackN);
                        }
                        boardB[0]--;
                        paint(100, 850);
                        changeT = false;
                    }
                    else if (xc > 170 && xc < 220 && yc > 830 && yc < 870) {
                        boardB[1]++;
                        int stackN = boardB[1];
                        paint(ColorTurn, 285, 868);
                        if (stackN > 1) {
                            paint(ColorTurn, 285, 868, stackN);
                        }
                        boardB[0]--;
                        paint(200, 850);
                        changeT = false;
                    }
                }
            }
            else {
                if (changeT) {
                    int jump = 0;
                    for (int i = 1; i < 59; i++) {
                        if (boardB[i] != 0) {
                            xBlue = blueLoc[i] / 1000;
                            yBlue = blueLoc[i] % 1000;

                            if (xc > xBlue - 40 && xc < xBlue + 40 && yc > yBlue - 40 && yc < yBlue + 40) {
                                if (i + diceRes < 52) {
                                    jump = i + diceRes;
                                    collision('b', jump);
                                    paint(xBlue, yBlue);
                                    int x = blueLoc[i + diceRes] / 1000;
                                    int y = blueLoc[i + diceRes] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardB[i + diceRes]++;
                                    int stackN = boardB[i + diceRes];
                                    if (stackN > 1) {
                                        paint(ColorTurn, x, y, stackN);
                                    }
                                    boardB[i]--;
                                    int stackP = boardB[i];
                                    if (stackP == 1) {
                                        paint(ColorTurn, xBlue, yBlue);
                                    }
                                    else if (stackP > 1) {
                                        paint(ColorTurn, xBlue, yBlue, stackP);
                                    }
                                    changeT = false;
                                    break;
                                }
                                else if (i + diceRes >= 52 && i + diceRes < 57) {
                                    paint(xBlue, yBlue);
                                    int x = blueLoc[i + diceRes] / 1000;
                                    int y = blueLoc[i + diceRes] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardB[i + diceRes]++;
                                    int stackN = boardB[i + diceRes];
                                    if (stackN > 1) {
                                        paint(ColorTurn, x, y, stackN);
                                    }
                                    jump = i + diceRes;
                                    boardB[i]--;
                                    int stackP = boardB[i];
                                    if (stackP == 1) {
                                        paint(ColorTurn, xBlue, yBlue);
                                    }
                                    else if (stackP > 1) {
                                        paint(ColorTurn, xBlue, yBlue, stackP);
                                    }
                                    changeT = false;
                                    break;
                                }
                                else if (i + diceRes == 57) {
                                    paint(xBlue, yBlue);
                                    int x = blueLoc[57] / 1000;
                                    int y = blueLoc[57] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardB[57]++;
                                    boardB[i]--;
                                    clearPaint(x, y);
                                    if (winGame()) {
                                        qDebug() << "Win";
                                    }
                                    changeT = false;
                                    break;
                                }
                                else {
                                    int j = i + diceRes;
                                    int ret = j - 57;
                                    int fp = 57 - ret;
                                    paint(xBlue, yBlue);
                                    int x = blueLoc[fp] / 1000;
                                    int y = blueLoc[fp] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardB[fp]++;
                                    int stackN = boardB[fp];
                                    if (stackN > 1) {
                                        paint(ColorTurn, x, y, stackN);
                                    }
                                    boardB[i]--;
                                    int stackP = boardB[i];
                                    if (stackP == 1) {
                                        paint(ColorTurn, xBlue, yBlue);
                                    }
                                    else if (stackP > 1) {
                                        paint(ColorTurn, xBlue, yBlue, stackP);
                                    }
                                    changeT = false;
                                    break;
                                }
                            }
                        }
                    }
                    for (int i = 0; i < 12; i++) {
                        int j = 4 * i + 3;
                        if (jump == j) {
                            if (i == 4) {
                                j = 4 * 7 + 3;
                            }
                            else {
                                j += 4;
                            }
                            collision('b', j);
                            int x = blueLoc[jump] / 1000;
                            int y = blueLoc[jump] % 1000;
                            paint(x, y);
                            boardB[jump]--;
                            int stackP = boardB[jump];
                            if (stackP == 1) {
                                paint(ColorTurn, x, y);
                            }
                            else if (stackP > 1) {
                                paint(ColorTurn, x, y, stackP);
                            }
                            int nx = blueLoc[j] / 1000;
                            int ny = blueLoc[j] % 1000;
                            paint(ColorTurn, nx, ny);
                            boardB[j]++;
                            int stackN = boardB[j];
                            if (stackN > 1) {
                                paint(ColorTurn, nx, ny, stackN);
                            }
                            changeT = false;
                            break;
                        }
                    }
                }
            }
        }
        else {
            //yellow
            if (boardY[0] != 0 && diceRes == 6) {
                if (xc > 70 && xc < 120 && yc > 80 && yc < 120) {
                    boardY[1]++;
                    int stackN = boardY[1];
                    paint(ColorTurn, 79, 287);
                    if (stackN > 1) {
                        paint(ColorTurn, 79, 287, stackN);
                    }
                    boardY[0]--;
                    paint(100, 100);
                    changeT = false;
                }
                else if (xc > 170 && xc < 220 && yc > 80 && yc < 120) {
                    boardY[1]++;
                    int stackN = boardY[1];
                    paint(ColorTurn, 79, 287);
                    if (stackN > 1) {
                        paint(ColorTurn, 79, 287, stackN);
                    }
                    boardY[0]--;
                    paint(200, 100);
                    changeT = false;
                }
                else if (xc > 70 && xc < 120 && yc > 180 && yc < 220) {
                    boardY[1]++;
                    int stackN = boardY[1];
                    paint(ColorTurn, 79, 287);
                    if (stackN > 1) {
                        paint(ColorTurn, 79, 287, stackN);
                    }
                    boardY[0]--;
                    paint(100, 200);
                    changeT = false;
                }
                else if (xc > 170 && xc < 220 && yc > 180 && yc < 220) {
                    boardY[1]++;
                    int stackN = boardY[1];
                    paint(ColorTurn, 79, 287);
                    if (stackN > 1) {
                        paint(ColorTurn, 79, 287, stackN);
                    }
                    boardY[0]--;
                    paint(200, 200);
                    changeT = false;
                }
            }
            else {
                if (changeT) {
                    int jump = 0;
                    for (int i = 1; i < 58; i++) {
                        if (boardY[i] != 0) {
                            xYellow = yellowLoc[i] / 1000;
                            yYellow = yellowLoc[i] % 1000;

                            if (xc > xYellow - 40 && xc < xYellow + 40 && yc > yYellow - 40 && yc < yYellow + 40) {
                                if (i + diceRes < 52) {
                                    jump = i + diceRes;
                                    collision('y', jump);
                                    paint(xYellow, yYellow);
                                    int x = yellowLoc[i + diceRes] / 1000;
                                    int y = yellowLoc[i + diceRes] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardY[i + diceRes]++;
                                    int stackN = boardY[i + diceRes];
                                    if (stackN > 1) {
                                        paint(ColorTurn, x, y, stackN);
                                    }
                                    boardY[i]--;
                                    int stackP = boardY[i];
                                    if (stackP == 1) {
                                        paint(ColorTurn, xYellow, yYellow);
                                    } else if (stackP > 1) {
                                        paint(ColorTurn, xYellow, yYellow, stackP);
                                    }
                                    changeT = false;
                                    break;
                                }
                                else if (i + diceRes >= 52 && i + diceRes < 57) {
                                    paint(xYellow, yYellow);
                                    int x = yellowLoc[i + diceRes] / 1000;
                                    int y = yellowLoc[i + diceRes] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardY[i + diceRes]++;
                                    int stackN = boardY[i + diceRes];
                                    if (stackN > 1) {
                                        paint(ColorTurn, x, y, stackN);
                                    }
                                    jump = i + diceRes;
                                    boardY[i]--;
                                    int stackP = boardY[i];
                                    if (stackP == 1) {
                                        paint(ColorTurn, xYellow, yYellow);
                                    } else if (stackP > 1) {
                                        paint(ColorTurn, xYellow, yYellow, stackP);
                                    }
                                    changeT = false;
                                    break;
                                }
                                else if (i + diceRes == 57) {
                                    paint(xYellow, yYellow);
                                    int x = yellowLoc[57] / 1000;
                                    int y = yellowLoc[57] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardY[57]++;
                                    boardY[i]--;
                                    clearPaint(x, y);
                                    if (winGame()) {
                                        qDebug() << "Win";
                                    }
                                    changeT = false;
                                    break;
                                }
                                else {
                                    int j = i + diceRes;
                                    int ret = j - 57;
                                    int fp = 57 - ret;
                                    paint(xYellow, yYellow);
                                    int x = yellowLoc[fp] / 1000;
                                    int y = yellowLoc[fp] % 1000;
                                    paint(ColorTurn, x, y);
                                    boardY[fp]++;
                                    int stackN = boardY[fp];
                                    if (stackN > 1) {
                                        paint(ColorTurn, x, y, stackN);
                                    }
                                    boardY[i]--;
                                    int stackP = boardY[i];
                                    if (stackP == 1) {
                                        paint(ColorTurn, xYellow, yYellow);
                                    } else if (stackP > 1) {
                                        paint(ColorTurn, xYellow, yYellow, stackP);
                                    }
                                    changeT = false;
                                    break;
                                }
                            }
                        }
                    }

                    for (int i = 0; i < 12; i++) {
                        int j = 4 * i + 3;
                        if (jump == j) {
                            if (i == 4) {
                                j = 4 * 7 + 3;
                            } else {
                                j += 4;
                            }
                            collision('y', j);
                            int x = yellowLoc[jump] / 1000;
                            int y = yellowLoc[jump] % 1000;
                            paint(x, y);
                            boardY[jump]--;
                            int stackP = boardY[jump];
                            if (stackP == 1) {
                                paint(ColorTurn, x, y);
                            }
                            else if (stackP > 1) {
                                paint(ColorTurn, x, y, stackP);
                            }
                            int nx = yellowLoc[j] / 1000;
                            int ny = yellowLoc[j] % 1000;
                            paint(ColorTurn, nx, ny);
                            boardY[j]++;
                            int stackN = boardY[j];
                            if (stackN > 1) {
                                paint(ColorTurn, nx, ny, stackN);
                            }
                            changeT = false;
                            break;
                        }
                    }
                }
            }
        }
        break;
    }
    update();
}

void Game::greenPiece() {
    greenLoc[1] = 663080;
    greenLoc[2] = 629120;
    greenLoc[3] = 648175;
    greenLoc[4] = 648225;
    greenLoc[5] = 630280;
    greenLoc[6] = 670325;
    greenLoc[7] = 726303;
    greenLoc[8] = 776303;
    greenLoc[9] = 832322;
    greenLoc[10] = 850378;
    greenLoc[11] = 850426;
    greenLoc[12] = 850475;
    greenLoc[13] = 850523;
    greenLoc[14] = 850572;
    greenLoc[15] = 834628;
    greenLoc[16] = 776651;
    greenLoc[17] = 726651;
    greenLoc[18] = 670629;
    greenLoc[19] = 629672;
    greenLoc[20] = 648725;
    greenLoc[21] = 648775;
    greenLoc[22] = 629830;
    greenLoc[23] = 572850;
    greenLoc[24] = 523850;
    greenLoc[25] = 476850;
    greenLoc[26] = 426850;
    greenLoc[27] = 378850;
    greenLoc[28] = 325830;
    greenLoc[29] = 303775;
    greenLoc[30] = 303726;
    greenLoc[31] = 323673;
    greenLoc[32] = 280626;
    greenLoc[33] = 224651;
    greenLoc[34] = 174651;
    greenLoc[35] = 120629;
    greenLoc[36] = 100573;
    greenLoc[37] = 100525;
    greenLoc[38] = 100476;
    greenLoc[39] = 100428;
    greenLoc[40] = 100379;
    greenLoc[41] = 118323;
    greenLoc[42] = 177304;
    greenLoc[43] = 227304;
    greenLoc[44] = 280325;
    greenLoc[45] = 325280;
    greenLoc[46] = 302227;
    greenLoc[47] = 302175;
    greenLoc[48] = 325120;
    greenLoc[49] = 378100;
    greenLoc[50] = 428100;
    greenLoc[51] = 476100;
    greenLoc[52] = 476173;
    greenLoc[53] = 476218;
    greenLoc[54] = 476262;
    greenLoc[55] = 476305;
    greenLoc[56] = 476350;
    greenLoc[57] = 476394;
}

void Game::yellowPiece() {
    yellowLoc[1] = 79287;
    yellowLoc[2] = 118323;
    yellowLoc[3] = 177304;
    yellowLoc[4] = 227304;
    yellowLoc[5] = 280325;
    yellowLoc[6] = 325280;
    yellowLoc[7] = 302227;
    yellowLoc[8] = 302175;
    yellowLoc[9] = 325120;
    yellowLoc[10] = 378100;
    yellowLoc[11] = 428100;
    yellowLoc[12] = 476100;
    yellowLoc[13] = 524100;
    yellowLoc[14] = 574100;
    yellowLoc[15] = 629120;
    yellowLoc[16] = 648175;
    yellowLoc[17] = 648225;
    yellowLoc[18] = 630280;
    yellowLoc[19] = 670325;
    yellowLoc[20] = 726303;
    yellowLoc[21] = 776303;
    yellowLoc[22] = 832322;
    yellowLoc[23] = 850378;
    yellowLoc[24] = 850426;
    yellowLoc[25] = 850475;
    yellowLoc[26] = 850523;
    yellowLoc[27] = 850572;
    yellowLoc[28] = 834628;
    yellowLoc[29] = 776651;
    yellowLoc[30] = 726651;
    yellowLoc[31] = 670629;
    yellowLoc[32] = 629672;
    yellowLoc[33] = 648725;
    yellowLoc[34] = 648775;
    yellowLoc[35] = 629830;
    yellowLoc[36] = 572850;
    yellowLoc[37] = 523850;
    yellowLoc[38] = 476850;
    yellowLoc[39] = 426850;
    yellowLoc[40] = 378850;
    yellowLoc[41] = 325830;
    yellowLoc[42] = 303775;
    yellowLoc[43] = 303726;
    yellowLoc[44] = 323673;
    yellowLoc[45] = 280626;
    yellowLoc[46] = 224651;
    yellowLoc[47] = 174651;
    yellowLoc[48] = 120629;
    yellowLoc[49] = 100573;
    yellowLoc[50] = 100525;
    yellowLoc[51] = 100476;
    yellowLoc[52] = 172476;
    yellowLoc[53] = 218476;
    yellowLoc[54] = 262476;
    yellowLoc[55] = 307476;
    yellowLoc[56] = 353476;
    yellowLoc[57] = 398476;
}

void Game::redPiece() {
    redLoc[1] = 869666;
    redLoc[2] = 834628;
    redLoc[3] = 776651;
    redLoc[4] = 726651;
    redLoc[5] = 670629;
    redLoc[6] = 629672;
    redLoc[7] = 648725;
    redLoc[8] = 648775;
    redLoc[9] = 629830;
    redLoc[10] = 572850;
    redLoc[11] = 523850;
    redLoc[12] = 476850;
    redLoc[13] = 426850;
    redLoc[14] = 378850;
    redLoc[15] = 325830;
    redLoc[16] = 303775;
    redLoc[17] = 303726;
    redLoc[18] = 323673;
    redLoc[19] = 280626;
    redLoc[20] = 224651;
    redLoc[21] = 174651;
    redLoc[22] = 120629;
    redLoc[23] = 100573;
    redLoc[24] = 100525;
    redLoc[25] = 100476;
    redLoc[26] = 100428;
    redLoc[27] = 100379;
    redLoc[28] = 118323;
    redLoc[29] = 177304;
    redLoc[30] = 227304;
    redLoc[31] = 280325;
    redLoc[32] = 325280;
    redLoc[33] = 302227;
    redLoc[34] = 302175;
    redLoc[35] = 325120;
    redLoc[36] = 378100;
    redLoc[37] = 428100;
    redLoc[38] = 476100;
    redLoc[39] = 524100;
    redLoc[40] = 574100;
    redLoc[41] = 629120;
    redLoc[42] = 648175;
    redLoc[43] = 648225;
    redLoc[44] = 630280;
    redLoc[45] = 670325;
    redLoc[46] = 726303;
    redLoc[47] = 776303;
    redLoc[48] = 832322;
    redLoc[49] = 850378;
    redLoc[50] = 850426;
    redLoc[51] = 850475;
    redLoc[52] = 779475;
    redLoc[53] = 735475;
    redLoc[54] = 689475;
    redLoc[55] = 644475;
    redLoc[56] = 600475;
    redLoc[57] = 555475;
}

void Game::bluePiece() {
    blueLoc[1] = 285868;
    blueLoc[2] = 325830;
    blueLoc[3] = 303775;
    blueLoc[4] = 303726;
    blueLoc[5] = 323673;
    blueLoc[6] = 280626;
    blueLoc[7] = 224651;
    blueLoc[8] = 174651;
    blueLoc[9] = 120629;
    blueLoc[10] = 100573;
    blueLoc[11] = 100525;
    blueLoc[12] = 100476;
    blueLoc[13] = 100428;
    blueLoc[14] = 100379;
    blueLoc[15] = 118323;
    blueLoc[16] = 177304;
    blueLoc[17] = 227304;
    blueLoc[18] = 280325;
    blueLoc[19] = 325280;
    blueLoc[20] = 302227;
    blueLoc[21] = 302175;
    blueLoc[22] = 325120;
    blueLoc[23] = 378100;
    blueLoc[24] = 428100;
    blueLoc[25] = 476100;
    blueLoc[26] = 524100;
    blueLoc[27] = 574100;
    blueLoc[28] = 629120;
    blueLoc[29] = 648175;
    blueLoc[30] = 648225;
    blueLoc[31] = 630280;
    blueLoc[32] = 670325;
    blueLoc[33] = 726303;
    blueLoc[34] = 776303;
    blueLoc[35] = 832322;
    blueLoc[36] = 850378;
    blueLoc[37] = 850426;
    blueLoc[38] = 850475;
    blueLoc[39] = 850523;
    blueLoc[40] = 850572;
    blueLoc[41] = 834628;
    blueLoc[42] = 776651;
    blueLoc[43] = 726651;
    blueLoc[44] = 670629;
    blueLoc[45] = 629672;
    blueLoc[46] = 648725;
    blueLoc[47] = 648775;
    blueLoc[48] = 629830;
    blueLoc[49] = 572850;
    blueLoc[50] = 523850;
    blueLoc[51] = 476850;
    blueLoc[52] = 476779;
    blueLoc[53] = 476734;
    blueLoc[54] = 476690;
    blueLoc[55] = 476645;
    blueLoc[56] = 476600;
    blueLoc[57] = 476555;
}

void Game::loadBoard() {
    QImage tmp(m_BoardImg -> pixmap() -> toImage());

    QPainter m_Print( & tmp);

    switch (numPlayers) {
    case 2:
        m_Print.setBrush(Qt::green);
        m_Print.drawEllipse(750 - 20, 100 - 20, 40, 40);
        m_Print.drawEllipse(850 - 20, 100 - 20, 40, 40);
        m_Print.drawEllipse(750 - 20, 200 - 20, 40, 40);
        m_Print.drawEllipse(850 - 20, 200 - 20, 40, 40);
        boardG[0] = 4;
        greenPiece();

        m_Print.setBrush(Qt::yellow);
        m_Print.drawEllipse(100 - 20, 100 - 20, 40, 40);
        m_Print.drawEllipse(200 - 20, 100 - 20, 40, 40);
        m_Print.drawEllipse(100 - 20, 200 - 20, 40, 40);
        m_Print.drawEllipse(200 - 20, 200 - 20, 40, 40);
        boardY[0] = 4;
        yellowPiece();

        break;

    case 3:

        m_Print.setBrush(Qt::green);
        m_Print.drawEllipse(750 - 20, 100 - 20, 40, 40);
        m_Print.drawEllipse(850 - 20, 100 - 20, 40, 40);
        m_Print.drawEllipse(750 - 20, 200 - 20, 40, 40);
        m_Print.drawEllipse(850 - 20, 200 - 20, 40, 40);
        boardG[0] = 4;
        greenPiece();

        m_Print.setBrush(Qt::red);
        m_Print.drawEllipse(750 - 20, 750 - 20, 40, 40);
        m_Print.drawEllipse(850 - 20, 750 - 20, 40, 40);
        m_Print.drawEllipse(750 - 20, 850 - 20, 40, 40);
        m_Print.drawEllipse(850 - 20, 850 - 20, 40, 40);
        boardR[0] = 4;
        redPiece();

        m_Print.setBrush(Qt::yellow);
        m_Print.drawEllipse(100 - 20, 100 - 20, 40, 40);
        m_Print.drawEllipse(200 - 20, 100 - 20, 40, 40);
        m_Print.drawEllipse(100 - 20, 200 - 20, 40, 40);
        m_Print.drawEllipse(200 - 20, 200 - 20, 40, 40);
        boardY[0] = 4;
        yellowPiece();

        break;

    case 4:

        m_Print.setBrush(Qt::green);
        m_Print.drawEllipse(750 - 20, 100 - 20, 40, 40);
        m_Print.drawEllipse(850 - 20, 100 - 20, 40, 40);
        m_Print.drawEllipse(750 - 20, 200 - 20, 40, 40);
        m_Print.drawEllipse(850 - 20, 200 - 20, 40, 40);
        boardG[0] = 4;
        greenPiece();

        m_Print.setBrush(Qt::red);
        m_Print.drawEllipse(750 - 20, 750 - 20, 40, 40);
        m_Print.drawEllipse(850 - 20, 750 - 20, 40, 40);
        m_Print.drawEllipse(750 - 20, 850 - 20, 40, 40);
        m_Print.drawEllipse(850 - 20, 850 - 20, 40, 40);
        boardR[0] = 4;
        redPiece();

        m_Print.setBrush(Qt::blue);
        m_Print.drawEllipse(100 - 20, 750 - 20, 40, 40);
        m_Print.drawEllipse(200 - 20, 750 - 20, 40, 40);
        m_Print.drawEllipse(100 - 20, 850 - 20, 40, 40);
        m_Print.drawEllipse(200 - 20, 850 - 20, 40, 40);
        boardB[0] = 4;
        bluePiece();

        m_Print.setBrush(Qt::yellow);
        m_Print.drawEllipse(100 - 20, 100 - 20, 40, 40);
        m_Print.drawEllipse(200 - 20, 100 - 20, 40, 40);
        m_Print.drawEllipse(100 - 20, 200 - 20, 40, 40);
        m_Print.drawEllipse(200 - 20, 200 - 20, 40, 40);
        boardY[0] = 4;
        yellowPiece();

        break;
    }

    m_BoardImg -> setPixmap(QPixmap::fromImage(tmp));
}

void Game::mouseReleaseEvent(QMouseEvent * event) {
    if (changeT) {
        int tx = event -> x();
        tx -= 30;
        int ty = event -> y();
        ty -= 30;
        xc = tx;
        yc = ty;
        paintDis = true;
        update();
        movePiece();
    }
    else {
        event -> ignore();
    }
}

void Game::paint(int xLoc, int yLoc) {
    QImage tmp(m_BoardImg -> pixmap() -> toImage());

    QPainter m_Print( & tmp);

    m_Print.setBrush(Qt::color0);
    m_Print.drawEllipse(xLoc - 20, yLoc - 20, 40, 40);

    m_BoardImg -> setPixmap(QPixmap::fromImage(tmp));
    update();
}

void Game::paint(int playerC, int xLoc, int yLoc) {
    QImage tmp(m_BoardImg -> pixmap() -> toImage());

    QPainter m_Print( & tmp);

    switch (numPlayers) {
    case 2:
        if (playerC == 0) {
            m_Print.setBrush(Qt::green);
            m_Print.drawEllipse(xLoc - 20, yLoc - 20, 40, 40);
        }
        else {
            m_Print.setBrush(Qt::yellow);
            m_Print.drawEllipse(xLoc - 20, yLoc - 20, 40, 40);
        }
        break;

    case 3:

        if (playerC == 0) {
            m_Print.setBrush(Qt::green);
            m_Print.drawEllipse(xLoc - 20, yLoc - 20, 40, 40);
        }
        else if (playerC == 1) {
            m_Print.setBrush(Qt::red);
            m_Print.drawEllipse(xLoc - 20, yLoc - 20, 40, 40);
        }
        else {
            m_Print.setBrush(Qt::yellow);
            m_Print.drawEllipse(xLoc - 20, yLoc - 20, 40, 40);
        }
        break;

    case 4:
        if (playerC == 0) {
            m_Print.setBrush(Qt::green);
            m_Print.drawEllipse(xLoc - 20, yLoc - 20, 40, 40);
        }
        else if (playerC == 1) {
            m_Print.setBrush(Qt::red);
            m_Print.drawEllipse(xLoc - 20, yLoc - 20, 40, 40);
        }
        else if (playerC == 2) {
            m_Print.setBrush(Qt::blue);
            m_Print.drawEllipse(xLoc - 20, yLoc - 20, 40, 40);
        }
        else {
            m_Print.setBrush(Qt::yellow);
            m_Print.drawEllipse(xLoc - 20, yLoc - 20, 40, 40);
        }
        break;
    }

    m_BoardImg -> setPixmap(QPixmap::fromImage(tmp));
    update();

}

void Game::paint(int playerC, int xLoc, int yLoc, int pStack) {
    QImage tmp(m_BoardImg -> pixmap() -> toImage());

    QPainter m_Print( & tmp);

    std::string s;
    s = std::to_string(pStack);
    QString st = QString::fromUtf8(s.c_str());

    switch (numPlayers) {
    case 2:
        if (playerC == 0) {
            m_Print.setBrush(Qt::green);
            m_Print.drawEllipse(xLoc - 20, yLoc - 20, 40, 40);
            m_Print.drawText(xLoc, yLoc, st);
        }
        else {
            m_Print.setBrush(Qt::yellow);
            m_Print.drawEllipse(xLoc - 20, yLoc - 20, 40, 40);
            m_Print.drawText(xLoc, yLoc, st);
        }
        break;

    case 3:

        if (playerC == 0) {
            m_Print.setBrush(Qt::green);
            m_Print.drawEllipse(xLoc - 20, yLoc - 20, 40, 40);
            m_Print.drawText(xLoc, yLoc, st);
        }
        else if (playerC == 1) {
            m_Print.setBrush(Qt::red);
            m_Print.drawEllipse(xLoc - 20, yLoc - 20, 40, 40);
            m_Print.drawText(xLoc, yLoc, st);
        }
        else {
            m_Print.setBrush(Qt::yellow);
            m_Print.drawEllipse(xLoc - 20, yLoc - 20, 40, 40);
            m_Print.drawText(xLoc, yLoc, st);
        }
        break;

    case 4:
        if (playerC == 0) {
            m_Print.setBrush(Qt::green);
            m_Print.drawEllipse(xLoc - 20, yLoc - 20, 40, 40);
            m_Print.drawText(xLoc, yLoc, st);
        }
        else if (playerC == 1) {
            m_Print.setBrush(Qt::red);
            m_Print.drawEllipse(xLoc - 20, yLoc - 20, 40, 40);
            m_Print.drawText(xLoc, yLoc, st);
        }
        else if (playerC == 2) {
            m_Print.setBrush(Qt::blue);
            m_Print.drawEllipse(xLoc - 20, yLoc - 20, 40, 40);
            m_Print.drawText(xLoc, yLoc, st);
        }
        else {
            m_Print.setBrush(Qt::yellow);
            m_Print.drawEllipse(xLoc - 20, yLoc - 20, 40, 40);
            m_Print.drawText(xLoc, yLoc, st);
        }
        break;
    }

    m_BoardImg -> setPixmap(QPixmap::fromImage(tmp));
    update();
}

bool Game::winGame() {
    bool win = false;
    switch (numPlayers) {
    case 2:
        if (boardG[57] == 4) {
            win = true;
            slotWin();
            winner = 'g';
        }
        else if (boardY[57] == 4) {
            win = true;
            slotWin();
            winner = 'y';
        }
        break;

    case 3:
        if (boardG[57] == 4) {
            win = true;
            slotWin();
            winner = 'g';
        }
        else if (boardY[57] == 4) {
            win = true;
            slotWin();
            winner = 'y';
        }
        else if (boardR[57] == 4) {
            win = true;
            slotWin();
            winner = 'r';
        }
        break;

    case 4:
        if (boardG[57] == 4) {
            win = true;
            slotWin();
            winner = 'g';
        }
        else if (boardY[57] == 4) {
            win = true;
            slotWin();
            winner = 'y';
        }
        else if (boardR[57] == 4) {
            win = true;
            slotWin();
            winner = 'r';
        }
        else if (boardB[57] == 4) {
            win = true;
            slotWin();
            winner = 'b';
        }
        break;
    }
    return win;
}

void Game::clearPaint(int xLoc, int yLoc) {
    update();
    wait();
    paint(xLoc, yLoc);
}

void Game::collision(char col, int lastP) {
    switch (numPlayers) {
    case 2:
        //yellow
        if (col == 'g') {
            int searchP = greenLoc[lastP];
            for (int i = 2; i <= 51; i++) {
                if (searchP == yellowLoc[i] && boardY[i] != 0) {
                    int tmp = boardY[i];
                    boardY[i] = 0;
                    boardY[1] += tmp;
                    int overX = yellowLoc[i] / 1000;
                    int overY = yellowLoc[i] % 1000;
                    paint(overX, overY);
                    int nextX = yellowLoc[1] / 1000;
                    int nextY = yellowLoc[1] % 1000;
                    paint(1, nextX, nextY);
                    int stackN = boardY[1];
                    if (stackN > 1) {
                        paint(1, nextX, nextY, stackN);
                    }
                    break;
                }
            }
        }
        else if (col == 'y') {
            int searchP = yellowLoc[lastP];
            for (int i = 2; i <= 51; i++) {
                if (searchP == greenLoc[i] && boardG[i] != 0) {
                    int tmp = boardG[i];
                    boardG[i] = 0;
                    boardG[1] += tmp;
                    int overX = greenLoc[i] / 1000;
                    int overY = greenLoc[i] % 1000;
                    paint(overX, overY);
                    int nextX = greenLoc[1] / 1000;
                    int nextY = greenLoc[1] % 1000;
                    paint(0, nextX, nextY);
                    int stackN = boardG[1];
                    if (stackN > 1) {
                        paint(0, nextX, nextY, stackN);
                    }
                    break;
                }
            }
        }
        break;

    case 3:
        if (col == 'g') {
            int searchP = greenLoc[lastP];
            for (int i = 2; i <= 51; i++) {
                if (searchP == redLoc[i] && boardR[i] != 0) {
                    int tmp = boardR[i];
                    boardR[i] = 0;
                    boardR[1] += tmp;
                    int overX = redLoc[i] / 1000;
                    int overY = redLoc[i] % 1000;
                    paint(overX, overY);
                    int nextX = redLoc[1] / 1000;
                    int nextY = redLoc[1] % 1000;
                    paint(1, nextX, nextY);
                    int stackN = boardR[1];
                    if (stackN > 1) {
                        paint(1, nextX, nextY, stackN);
                    }
                    break;
                }
                else if (searchP == yellowLoc[i] && boardY[i] != 0) {
                    int tmp = boardY[i];
                    boardY[i] = 0;
                    boardY[1] += tmp;
                    int overX = yellowLoc[i] / 1000;
                    int overY = yellowLoc[i] % 1000;
                    paint(overX, overY);
                    int nextX = yellowLoc[1] / 1000;
                    int nextY = yellowLoc[1] % 1000;
                    paint(2, nextX, nextY);
                    int stackN = boardY[1];
                    if (stackN > 1) {
                        paint(2, nextX, nextY, stackN);
                    }
                    break;
                }
            }
        }
        else if (col == 'r') {
            int searchP = redLoc[lastP];
            for (int i = 2; i <= 51; i++) {
                if (searchP == greenLoc[i] && boardG[i] != 0) {
                    int tmp = boardG[i];
                    boardG[i] = 0;
                    boardG[1] += tmp;
                    int overX = greenLoc[i] / 1000;
                    int overY = greenLoc[i] % 1000;
                    paint(overX, overY);
                    int nextX = greenLoc[1] / 1000;
                    int nextY = greenLoc[1] % 1000;
                    paint(0, nextX, nextY);
                    int stackN = boardG[1];
                    if (stackN > 1) {
                        paint(0, nextX, nextY, stackN);
                    }
                    break;
                }
                else if (searchP == yellowLoc[i] && boardY[i] != 0) {
                    int tmp = boardY[i];
                    boardY[i] = 0;
                    boardY[1] += tmp;
                    int overX = yellowLoc[i] / 1000;
                    int overY = yellowLoc[i] % 1000;
                    paint(overX, overY);
                    int nextX = yellowLoc[1] / 1000;
                    int nextY = yellowLoc[1] % 1000;
                    paint(2, nextX, nextY);
                    int stackN = boardY[1];
                    if (stackN > 1) {
                        paint(2, nextX, nextY, stackN);
                    }
                    break;
                }
            }
        }
        else if (col == 'y') {
            int searchP = yellowLoc[lastP];
            for (int i = 2; i <= 51; i++) {
                if (searchP == greenLoc[i] && boardG[i] != 0) {
                    int tmp = boardG[i];
                    boardG[i] = 0;
                    boardG[1] += tmp;
                    int overX = greenLoc[i] / 1000;
                    int overY = greenLoc[i] % 1000;
                    paint(overX, overY);
                    int nextX = greenLoc[1] / 1000;
                    int nextY = greenLoc[1] % 1000;
                    paint(0, nextX, nextY);
                    int stackN = boardG[1];
                    if (stackN > 1) {
                        paint(0, nextX, nextY, stackN);
                    }
                    break;
                }
                else if (searchP == redLoc[i] && boardR[i] != 0) {
                    int tmp = boardR[i];
                    boardR[i] = 0;
                    boardR[1] += tmp;
                    int overX = redLoc[i] / 1000;
                    int overY = redLoc[i] % 1000;
                    paint(overX, overY);
                    int nextX = redLoc[1] / 1000;
                    int nextY = redLoc[1] % 1000;
                    paint(1, nextX, nextY);
                    int stackN = boardR[1];
                    if (stackN > 1) {
                        paint(1, nextX, nextY, stackN);
                    }
                    break;
                }
            }
        }
        break;

    case 4:
        if (col == 'g') {
            int searchP = greenLoc[lastP];
            for (int i = 2; i <= 51; i++) {
                if (searchP == redLoc[i] && boardR[i] != 0) {
                    int tmp = boardR[i];
                    boardR[i] = 0;
                    boardR[1] += tmp;
                    int overX = redLoc[i] / 1000;
                    int overY = redLoc[i] % 1000;
                    paint(overX, overY);
                    int nextX = redLoc[1] / 1000;
                    int nextY = redLoc[1] % 1000;
                    paint(1, nextX, nextY);
                    int stackN = boardR[1];
                    if (stackN > 1) {
                        paint(1, nextX, nextY, stackN);
                    }
                    break;
                }
                else if (searchP == blueLoc[i] && boardB[i] != 0) {
                    int tmp = boardB[i];
                    boardB[i] = 0;
                    boardB[1] += tmp;
                    int overX = blueLoc[i] / 1000;
                    int overY = blueLoc[i] % 1000;
                    paint(overX, overY);
                    int nextX = blueLoc[1] / 1000;
                    int nextY = blueLoc[1] % 1000;
                    paint(2, nextX, nextY);
                    int stackN = boardB[1];
                    if (stackN > 1) {
                        paint(2, nextX, nextY, stackN);
                    }
                    break;
                }
                else if (searchP == yellowLoc[i] && boardY[i] != 0) {
                    int tmp = boardY[i];
                    boardY[i] = 0;
                    boardY[1] += tmp;
                    int overX = yellowLoc[i] / 1000;
                    int overY = yellowLoc[i] % 1000;
                    paint(overX, overY);
                    int nextX = yellowLoc[1] / 1000;
                    int nextY = yellowLoc[1] % 1000;
                    paint(3, nextX, nextY);
                    int stackN = boardY[1];
                    if (stackN > 1) {
                        paint(3, nextX, nextY, stackN);
                    }
                    break;
                }
            }
        }
        else if (col == 'y') {
            int searchP = yellowLoc[lastP];
            for (int i = 2; i <= 51; i++) {
                if (searchP == greenLoc[i] && boardG[i] != 0) {
                    int tmp = boardG[i];
                    boardG[i] = 0;
                    boardG[1] += tmp;
                    int overX = greenLoc[i] / 1000;
                    int overY = greenLoc[i] % 1000;
                    paint(overX, overY);
                    int nextX = greenLoc[1] / 1000;
                    int nextY = greenLoc[1] % 1000;
                    paint(0, nextX, nextY);
                    int stackN = boardG[1];
                    if (stackN > 1) {
                        paint(0, nextX, nextY, stackN);
                    }
                    break;
                }
                else if (searchP == redLoc[i] && boardR[i] != 0) {
                    int tmp = boardR[i];
                    boardR[i] = 0;
                    boardR[1] += tmp;
                    int overX = redLoc[i] / 1000;
                    int overY = redLoc[i] % 1000;
                    paint(overX, overY);
                    int nextX = redLoc[1] / 1000;
                    int nextY = redLoc[1] % 1000;
                    paint(1, nextX, nextY);
                    int stackN = boardR[1];
                    if (stackN > 1) {
                        paint(1, nextX, nextY, stackN);
                    }
                    break;
                }
                else if (searchP == blueLoc[i] && boardB[i] != 0) {
                    int tmp = boardB[i];
                    boardB[i] = 0;
                    boardB[1] += tmp;
                    int overX = blueLoc[i] / 1000;
                    int overY = blueLoc[i] % 1000;
                    paint(overX, overY);
                    int nextX = blueLoc[1] / 1000;
                    int nextY = blueLoc[1] % 1000;
                    paint(2, nextX, nextY);
                    int stackN = boardB[1];
                    if (stackN > 1) {
                        paint(2, nextX, nextY, stackN);
                    }
                    break;
                }
            }
        }
        else if (col == 'r') {
            int searchP = redLoc[lastP];
            for (int i = 2; i <= 51; i++) {
                if (searchP == greenLoc[i] && boardG[i] != 0) {
                    int tmp = boardG[i];
                    boardG[i] = 0;
                    boardG[1] += tmp;
                    int overX = greenLoc[i] / 1000;
                    int overY = greenLoc[i] % 1000;
                    paint(overX, overY);
                    int nextX = greenLoc[1] / 1000;
                    int nextY = greenLoc[1] % 1000;
                    paint(0, nextX, nextY);
                    int stackN = boardG[1];
                    if (stackN > 1) {
                        paint(0, nextX, nextY, stackN);
                    }
                    break;
                }
                else if (searchP == blueLoc[i] && boardB[i] != 0) {
                    int tmp = boardB[i];
                    boardB[i] = 0;
                    boardB[1] += tmp;
                    int overX = blueLoc[i] / 1000;
                    int overY = blueLoc[i] % 1000;
                    paint(overX, overY);
                    int nextX = blueLoc[1] / 1000;
                    int nextY = blueLoc[1] % 1000;
                    paint(2, nextX, nextY);
                    int stackN = boardB[1];
                    if (stackN > 1) {
                        paint(2, nextX, nextY, stackN);
                    }
                    break;
                }
                else if (searchP == yellowLoc[i] && boardY[i] != 0) {
                    int tmp = boardY[i];
                    boardY[i] = 0;
                    boardY[1] += tmp;
                    int overX = yellowLoc[i] / 1000;
                    int overY = yellowLoc[i] % 1000;
                    paint(overX, overY);
                    int nextX = yellowLoc[1] / 1000;
                    int nextY = yellowLoc[1] % 1000;
                    paint(3, nextX, nextY);
                    int stackN = boardY[1];
                    if (stackN > 1) {
                        paint(3, nextX, nextY, stackN);
                    }
                    break;
                }
            }
        }
        else if (col == 'b') {
            int searchP = blueLoc[lastP];
            for (int i = 2; i <= 51; i++) {
                if (searchP == greenLoc[i] && boardG[i] != 0) {
                    int tmp = boardG[i];
                    boardG[i] = 0;
                    boardG[1] += tmp;
                    int overX = greenLoc[i] / 1000;
                    int overY = greenLoc[i] % 1000;
                    paint(overX, overY);
                    int nextX = greenLoc[1] / 1000;
                    int nextY = greenLoc[1] % 1000;
                    paint(0, nextX, nextY);
                    int stackN = boardG[1];
                    if (stackN > 1) {
                        paint(0, nextX, nextY, stackN);
                    }
                    break;
                }
                else if (searchP == redLoc[i] && boardR[i] != 0) {
                    int tmp = boardR[i];
                    boardR[i] = 0;
                    boardR[1] += tmp;
                    int overX = redLoc[i] / 1000;
                    int overY = redLoc[i] % 1000;
                    paint(overX, overY);
                    int nextX = redLoc[1] / 1000;
                    int nextY = redLoc[1] % 1000;
                    paint(1, nextX, nextY);
                    int stackN = boardR[1];
                    if (stackN > 1) {
                        paint(1, nextX, nextY, stackN);
                    }
                    break;
                }
                else if (searchP == yellowLoc[i] && boardY[i] != 0) {
                    int tmp = boardY[i];
                    boardY[i] = 0;
                    boardY[1] += tmp;
                    int overX = yellowLoc[i] / 1000;
                    int overY = yellowLoc[i] % 1000;
                    paint(overX, overY);
                    int nextX = yellowLoc[1] / 1000;
                    int nextY = yellowLoc[1] % 1000;
                    paint(3, nextX, nextY);
                    int stackN = boardY[1];
                    if (stackN > 1) {
                        paint(3, nextX, nextY, stackN);
                    }
                    break;
                }
            }
        }
        break;
    }
}

void Game::slotClose() {
    close();
}

void Game::slotDice() {
    Dice();
}

void Game::slotWin() {
    m_WinG = new WinGame(winner);
    m_WinG -> show();
}

QGroupBox * Game::m_BoardA() {
    QGroupBox * boardA = new QGroupBox("Board");

    m_BoardImg = new QLabel("Game Board");
    //m_BoardImg -> setPixmap(QPixmap(":src/img/board.png"));
    m_BoardImg -> setPixmap(QPixmap(":src/img/board2.png"));

    QVBoxLayout * vBox = new QVBoxLayout;
    vBox -> addWidget(m_BoardImg);
    loadBoard();

    boardA -> setLayout(vBox);

    return boardA;
}

QGroupBox * Game::m_DiceA() {
    QGroupBox * diceA = new QGroupBox("Dice");

    m_DiceChange = new QLabel();
    m_DiceChange -> setAlignment(Qt::AlignCenter);
    m_DiceChange -> setFont(QFont("Arial", 24));

    m_CurTurn = new QLabel();
    m_CurTurn -> setAlignment(Qt::AlignCenter);
    m_CurTurn -> setFont(QFont("Arial", 16));

    m_NextTurn = new QLabel();
    m_NextTurn -> setAlignment(Qt::AlignCenter);
    m_NextTurn -> setFont(QFont("Arial", 24));

    QLabel * diceI = new QLabel("Dice Image");
    diceI -> setPixmap(QPixmap(":src/img/dice.png"));

    QPushButton * roll = new QPushButton("Roll Dice");
    QObject::connect(roll, SIGNAL(clicked()), this, SLOT(slotDice()));

    QLabel * subT = new QLabel("Dice result:");
    subT -> setFont(QFont("Arial", 16));

    QLabel * playT = new QLabel("Next Player:");
    playT -> setFont(QFont("Arial", 16));

    m_NextTurn -> setText("Yellow");

    QVBoxLayout * vBox = new QVBoxLayout;
    vBox -> addWidget(diceI);
    vBox -> addWidget(roll);
    vBox -> addWidget(subT);
    vBox -> addWidget(m_CurTurn);
    vBox -> addWidget(m_DiceChange);
    vBox -> addWidget(playT);
    vBox -> addWidget(m_NextTurn);

    diceA -> setLayout(vBox);

    return diceA;
}
