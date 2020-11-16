#ifndef WINGAME_H
#define WINGAME_H
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QAction>

class WinGame : public QWidget
{
    Q_OBJECT
public:
    WinGame();
    WinGame(char colorPlayer);
    ~WinGame();

public slots:
    void slotClose();

protected:
    QVBoxLayout *mLayout;
    QLabel *mText;
    QLabel *mButton;
    QPushButton *mClose;

};

#endif // WINGAME_H
