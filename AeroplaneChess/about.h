#ifndef ABOUT_H
#define ABOUT_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QAction>
#include <QLabel>

class About : public QWidget
{
    Q_OBJECT
public:
    About();
    ~About();

public slots:
    void slotClose();

protected:
    QVBoxLayout *m_LayoutA;
    QLabel *m_Logo;
    QLabel *m_Version;
    QLabel *m_Developer;
    QPushButton *m_Close;
};

#endif // ABOUT_H
