#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QToolButton>
#include <QGridLayout>
#include <QPushButton>
#include <QString>

class CButton : public QWidget
{
    Q_OBJECT
public:
    CButton(QWidget *parent = 0);
    ~CButton();

private:
    QPushButton *m_pBtn;
    QPixmap *m_pIcon;

public:
    void setIcon(const QString &filename);
    void setButtonSize(const QSize &size);
};


class CButton;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    CButton *m_pCbtnXdirPositive;
    CButton *m_pCbtnXdirNagtive;
    CButton *m_pCbtnYdirPositive;
    CButton *m_pCbtnYdirNagtive;
    QToolButton *m_pLinearXPositiveBtn;
    QToolButton *m_pLinearXNagtiveBtn;
    QToolButton *m_pLinearYPositiveBtn;
    QToolButton *m_pLinearYNagtiveBtn;
};

#endif // WIDGET_H
