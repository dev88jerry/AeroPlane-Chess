#include "rules.h"

Rules::Rules()
{
    m_LayoutR = new QVBoxLayout;
    m_Close = new QPushButton("Close");


    m_Title = new QLabel("Games rules:");
    m_Title->setAlignment(Qt::AlignCenter);

    m_Rules = new QLabel("-Roll a 6 to move from the hanger to the launch area\n-On the same color, your piece will move to the next tile\n-Capture other pieces by stacking on top of them\n-First player to have their 4 pieces at the end arrow wins the game");
    m_Rules->setWordWrap(true);
    m_Rules->setAlignment(Qt::AlignLeft);

    m_LayoutR->addWidget(m_Title);
    m_LayoutR->addWidget(m_Rules);
    m_LayoutR->addWidget(m_Close);

    QObject::connect(m_Close, SIGNAL(clicked()), this, SLOT(slotClose()));

    setLayout(m_LayoutR);
}

Rules::~Rules()
{

}

void Rules::slotClose()
{
    close();
}
