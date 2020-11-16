#include <QDebug>
#include "testgamedraw.h"

TestGameDraw::TestGameDraw()
{
    myTestBox = new QVBoxLayout;

    quitTest = new QPushButton("Quit");
    QObject::connect(quitTest, SIGNAL(clicked(bool)), this, SLOT(slotClose()));

    myTestLabel = new QLabel("test");
    myTestLabel->setPixmap(QPixmap(":src/img/board.png"));

    QImage tmp(myTestLabel->pixmap()->toImage());

    QPainter paint(&tmp);

    paint.setBrush(Qt::yellow);

    //path top left clockwise
    paint.drawEllipse(168-20,373-20,40,40);
    paint.drawEllipse(227-20,354-20,40,40);
    paint.drawEllipse(277-20,354-20,40,40);
    paint.drawEllipse(330-20,375-20,40,40);
    paint.drawEllipse(375-20,330-20,40,40);
    paint.drawEllipse(352-20,277-20,40,40);
    paint.drawEllipse(352-20,225-20,40,40);
    paint.drawEllipse(375-20,170-20,40,40);
    paint.drawEllipse(428-20,150-20,40,40);
    paint.drawEllipse(478-20,150-20,40,40);
    paint.drawEllipse(526-20,150-20,40,40);
    paint.drawEllipse(574-20,150-20,40,40);
    paint.drawEllipse(624-20,150-20,40,40);
    paint.drawEllipse(679-20,170-20,40,40);
    paint.drawEllipse(698-20,225-20,40,40);
    paint.drawEllipse(698-20,275-20,40,40);
    paint.drawEllipse(680-20,330-20,40,40);
    paint.drawEllipse(720-20,375-20,40,40);
    paint.drawEllipse(776-20,353-20,40,40);
    paint.drawEllipse(826-20,353-20,40,40);
    paint.drawEllipse(882-20,372-20,40,40);
    paint.drawEllipse(900-20,428-20,40,40);
    paint.drawEllipse(900-20,476-20,40,40);
    paint.drawEllipse(900-20,525-20,40,40);
    paint.drawEllipse(900-20,573-20,40,40);
    paint.drawEllipse(900-20,622-20,40,40);
    paint.drawEllipse(884-20,678-20,40,40);
    paint.drawEllipse(826-20,701-20,40,40);
    paint.drawEllipse(776-20,701-20,40,40);
    paint.drawEllipse(720-20,679-20,40,40);
    paint.drawEllipse(679-20,722-20,40,40);
    paint.drawEllipse(698-20,775-20,40,40);
    paint.drawEllipse(698-20,825-20,40,40);
    paint.drawEllipse(679-20,880-20,40,40);
    paint.drawEllipse(622-20,900-20,40,40);
    paint.drawEllipse(573-20,900-20,40,40);
    paint.drawEllipse(526-20,900-20,40,40);
    paint.drawEllipse(476-20,900-20,40,40);
    paint.drawEllipse(428-20,900-20,40,40);
    paint.drawEllipse(375-20,880-20,40,40);
    paint.drawEllipse(353-20,825-20,40,40);
    paint.drawEllipse(353-20,776-20,40,40);
    paint.drawEllipse(373-20,723-20,40,40);
    paint.drawEllipse(330-20,676-20,40,40);
    paint.drawEllipse(274-20,701-20,40,40);
    paint.drawEllipse(224-20,701-20,40,40);
    paint.drawEllipse(170-20,679-20,40,40);
    paint.drawEllipse(150-20,623-20,40,40);
    paint.drawEllipse(150-20,575-20,40,40);
    paint.drawEllipse(150-20,526-20,40,40);
    paint.drawEllipse(150-20,478-20,40,40);
    paint.drawEllipse(150-20,429-20,40,40);

    //launch yellow
    paint.drawEllipse(129-20,337-20,40,40);
    //final yellow
    paint.drawEllipse(222-20,526-20,40,40);
    paint.drawEllipse(268-20,526-20,40,40);
    paint.drawEllipse(312-20,526-20,40,40);
    paint.drawEllipse(357-20,526-20,40,40);
    paint.drawEllipse(403-20,526-20,40,40);
    paint.drawEllipse(448-20,526-20,40,40);

    paint.setBrush(Qt::green);
    //launch green
    paint.drawEllipse(713-20,130-20,40,40);
    //final green
    paint.drawEllipse(526-20,223-20,40,40);
    paint.drawEllipse(526-20,268-20,40,40);
    paint.drawEllipse(526-20,312-20,40,40);
    paint.drawEllipse(526-20,355-20,40,40);
    paint.drawEllipse(526-20,400-20,40,40);
    paint.drawEllipse(526-20,444-20,40,40);

    paint.setBrush(Qt::red);
    //launch red
    paint.drawEllipse(919-20,716-20,40,40);
    //final red
    paint.drawEllipse(829-20,525-20,40,40);
    paint.drawEllipse(785-20,525-20,40,40);
    paint.drawEllipse(739-20,525-20,40,40);
    paint.drawEllipse(694-20,525-20,40,40);
    paint.drawEllipse(650-20,525-20,40,40);
    paint.drawEllipse(605-20,525-20,40,40);

    paint.setBrush(Qt::blue);
    //launch blue
    paint.drawEllipse(335-20,918-20,40,40);
    //final blue
    paint.drawEllipse(526-20,829-20,40,40);
    paint.drawEllipse(526-20,784-20,40,40);
    paint.drawEllipse(526-20,740-20,40,40);
    paint.drawEllipse(526-20,695-20,40,40);
    paint.drawEllipse(526-20,650-20,40,40);
    paint.drawEllipse(526-20,605-20,40,40);

    myTestLabel->setPixmap(QPixmap::fromImage(tmp));

    myTestBox->addWidget(myTestLabel);
    myTestBox->addWidget(quitTest);

    setLayout(myTestBox);
}

void TestGameDraw::mouseReleaseEvent(QMouseEvent *event)
{
        int tx = event->x();
        tx -=20;
        int ty = event->y();
        ty -=20;

        qDebug()<<tx<<","<<ty;
}

void TestGameDraw::slotClose()
{
    close();
}
