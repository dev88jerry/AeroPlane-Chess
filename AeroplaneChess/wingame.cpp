#include "wingame.h"

WinGame::WinGame()
{
    mLayout = new QVBoxLayout;
    mClose = new QPushButton("Close");
    QObject::connect(mClose,SIGNAL(clicked()), this, SLOT(slotClose()));

    mText = new QLabel("You win");
    mText->setFont(QFont("Arial", 16));

    mLayout->addWidget(mText);
    mLayout->addWidget(mClose);

    setLayout(mLayout);
}

WinGame::WinGame(char colorPlayer)
{
    mLayout = new QVBoxLayout;
    mClose = new QPushButton("Close");
    QObject::connect(mClose,SIGNAL(clicked()), this, SLOT(slotClose()));

    if(colorPlayer == 'g'){
        mText = new QLabel("Green player wins!!!");
    }
    else if (colorPlayer == 'r') {
        mText = new QLabel("Red player wins!!!");
    }
    else if (colorPlayer == 'b') {
        mText = new QLabel("Blue player wins!!!");
    }
    else if (colorPlayer == 'y') {
        mText = new QLabel("Yellow player wins!!!");
    }
    mText->setFont(QFont("Arial", 16));

    mLayout->addWidget(mText);
    mLayout->addWidget(mClose);

    setLayout(mLayout);
}

WinGame::~WinGame()
{

}

void WinGame::slotClose()
{
    close();
}
