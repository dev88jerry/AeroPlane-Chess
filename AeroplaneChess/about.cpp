#include "about.h"

About::About()
{
    m_LayoutA = new QVBoxLayout;
    m_Close = new QPushButton("Close");

    m_Logo = new QLabel("Logo");
    m_Logo->setPixmap(QPixmap(":src/img/TestBoard.png"));

    m_Version = new QLabel("Version: 0.1");
    m_Version->setAlignment(Qt::AlignCenter);

    m_Developer = new QLabel("Developer: Jerry Lau");
    m_Developer->setAlignment(Qt::AlignCenter);

    m_LayoutA->addWidget(m_Logo);
    m_LayoutA->addWidget(m_Version);
    m_LayoutA->addWidget(m_Developer);
    m_LayoutA->addWidget(m_Close);

    QObject::connect(m_Close, SIGNAL(clicked()),this, SLOT(slotClose()));

    setLayout(m_LayoutA);
}

About::~About()
{

}

void About::slotClose()
{
    close();
}
