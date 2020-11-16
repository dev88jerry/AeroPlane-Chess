#ifndef TESTGAMEDRAW_H
#define TESTGAMEDRAW_H

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

class TestGameDraw : public QWidget
{
    Q_OBJECT
public:
    TestGameDraw();
    void mouseReleaseEvent(QMouseEvent *event);

public slots:
    void slotClose();

protected:
    QLabel *myTestLabel;
    QLabel *myDrawLabel;
    QVBoxLayout *myTestBox;
    QPushButton *quitTest;

};

#endif // TESTGAMEDRAW_H
