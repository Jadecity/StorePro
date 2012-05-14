#ifndef DRAW3DPIECHART_H
#define DRAW3DPIECHART_H

#include <QWidget>

class CDraw3dPieChart : public QWidget
{
Q_OBJECT
public:
CDraw3dPieChart(QWidget *parent = 0);
public:
~CDraw3dPieChart(void);
public:
void   setPiePos(int iPosX, int iPosY);
void   setPieSize(int iWidth, int iHeight);
void   setPiePerCent(QList<double> lstPercent);
void   setChartDepth(int iDepth);
void   setChartDistance(int iDistence);// the distance of left and right???? 实现小部分扇形插入效果
void   paintEvent(QPaintEvent *event); // override
private:
int    m_iPosX;
int    m_iPosY;
int    m_iWidth;
int    m_iHeight;
int    m_iDepth;
int    m_iDistence;
QList<double> m_lstPercent;
QList<int>  m_lstSpanAgl;
QList<int>  m_lstStartAgl;
};

#endif // DRAW3DPIECHART_H
