#ifndef RULES_H
#define RULES_H

#include <QWidget>
#include <QObject>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QAction>

class Rules : public QWidget
{
    Q_OBJECT
public:
    Rules();
    ~Rules();

public slots:
    void slotClose();

protected:
    QVBoxLayout *m_LayoutR;
    QLabel *m_Title;
    QLabel *m_Rules;
    QPushButton *m_Close;

};

#endif // RULES_H
