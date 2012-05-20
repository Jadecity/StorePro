#ifndef RECTDRAWER_H
#define RECTDRAWER_H

#include <QWidget>

class RectDrawer : public QWidget
{
    Q_OBJECT
public:
    explicit RectDrawer(QWidget *parent = 0);
    ~RectDrawer();
public:
    void   setPos(int iPosX, int iPosY);
    void   setSize(int iWidth, int iHeight);
    void   setRectPercent(QList<float> lstPercent);
    void   setDistance(int margin);
    void   paintEvent(QPaintEvent *event); // override
signals:
    
public slots:
private:
    int    m_iPosX;
    int    m_iPosY;
    int    m_iWidth;
    int    m_iHeight;
    int    m_iDistence;
    QList<float> m_lstPercent;
};

#endif // RECTDRAWER_H
