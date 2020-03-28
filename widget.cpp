#include "widget.h"
#include <QBitmap>
#include <QCoreApplication>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QString appdir = QCoreApplication::applicationDirPath();
    qDebug() << appdir;
    m_pCbtnXdirPositive = new CButton;
    m_pCbtnXdirPositive->setIcon(appdir+tr("/images/linear2.jpg"));
    m_pCbtnXdirNagtive = new CButton;
    m_pCbtnXdirNagtive->setIcon(appdir+tr("/images/linear1.jpg"));
    m_pCbtnYdirPositive = new CButton;
    m_pCbtnYdirPositive->setIcon(appdir+tr("/images/linear4.jpg"));
    m_pCbtnYdirNagtive = new CButton;
    m_pCbtnYdirNagtive->setIcon(appdir+tr("/images/linear3.jpg"));

    QGridLayout *gridlayout = new QGridLayout(this);
    gridlayout->addWidget(m_pCbtnXdirPositive, 0,1);
    gridlayout->addWidget(m_pCbtnXdirNagtive, 2,1);
    gridlayout->addWidget(m_pCbtnYdirPositive, 1,0);
    gridlayout->addWidget(m_pCbtnYdirNagtive, 1,2);
    setLayout(gridlayout);
}

Widget::~Widget()
{

}

CButton::CButton(QWidget *parent)
    : QWidget(parent)
{
    m_pBtn = new QPushButton;
    QGridLayout *gridlayout = new QGridLayout(this);
    gridlayout->addWidget(m_pBtn, 0,0);
    setLayout(gridlayout);
}

CButton::~CButton()
{

}

void CButton::setIcon(const QString &filename)
{
//    QPixmap icon(tr("../CustomSteerBtn/images/linear2.jpg"));
    QPixmap icon(filename);
    QBitmap mask = icon.createMaskFromColor(QColor(255,255,255),Qt::MaskInColor);
    icon.setMask(mask);
    icon = icon.scaled(100,100);
    m_pBtn->setFixedSize(icon.size());
    m_pBtn->setIconSize(icon.size()*0.8);
    m_pBtn->setIcon(icon);
    m_pBtn->setStyleSheet("border::none;");
}
