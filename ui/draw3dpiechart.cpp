#include "draw3dpiechart.h"
#include <math.h>
#include <QPainter>
/*--------------------------------------------------------------------------*/
/*-------------------------- Constant Definition ---------------------------*/
/*--------------------------------------------------------------------------*/
const QColor cstDownPieColor[7] = {
          QColor(Qt::darkYellow),
          QColor(Qt::darkBlue),
          QColor(Qt::darkRed),
          QColor(Qt::darkGreen),
          QColor(Qt::darkCyan),
          QColor(Qt::darkGray),
          QColor(Qt::darkMagenta)
         };
const QColor cstUpPieColor[7] = {
          QColor(Qt::yellow),
          QColor(Qt::blue),
          QColor(Qt::red),
          QColor(Qt::green),
          QColor(Qt::cyan),
          QColor(Qt::gray),
          QColor(Qt::magenta)
         }; //这里我定义了七种颜色，最大设为七块-
CDraw3dPieChart::CDraw3dPieChart(QWidget *parent)
   :QWidget(parent)
{
m_iPosX = 0;
m_iPosY = 0;
m_iWidth = 0;
m_iHeight = 0;
m_iDepth = 0;
m_iDistence = 0;
m_lstPercent.clear();
m_lstSpanAgl.clear();
m_lstStartAgl.clear();
setFixedSize(929, 530);
}
CDraw3dPieChart::~CDraw3dPieChart(void)
{
m_lstPercent.clear();
m_lstSpanAgl.clear();
m_lstStartAgl.clear();
}
void CDraw3dPieChart::setPiePos(int iPosX, int iPosY)
{
m_iPosX = iPosX;
m_iPosY = iPosY;
}
void CDraw3dPieChart::setPieSize(int iWidth, int iHeight)
{
m_iWidth = iWidth;
m_iHeight = iHeight;
}
void CDraw3dPieChart::setChartDepth(int iDepth)
{
m_iDepth = iDepth;
}
void CDraw3dPieChart::setChartDistance(int iDistence)
{
m_iDistence = iDistence;
}
void CDraw3dPieChart::setPiePerCent(QList<double> lstPercent)
{
m_lstPercent = lstPercent;
}
void CDraw3dPieChart::paintEvent(QPaintEvent *event)
{
Q_UNUSED(event);
QPainter painter;
painter.begin(this);
m_lstSpanAgl.clear();
m_lstStartAgl.clear();
m_lstStartAgl.append(60);
if (m_lstPercent.size() <= 0)
{
  return;
}
for (int i = 0; i < m_lstPercent.size(); i++)
{
  m_lstSpanAgl.append(ceil(360*m_lstPercent.at(i)));
  if (i == 0)
  {
   continue;
  }
  m_lstStartAgl.append(m_lstSpanAgl.at(i-1) + m_lstStartAgl.at(i-1));
}
painter.setRenderHint(QPainter::Antialiasing, true); //设置平滑
painter.setPen(Qt::NoPen);
//下部分循环m_iDepth次
for (int i = 0; i < m_iDepth; i++)
{
  QRect rectDown(m_iPosX, m_iPosY-i, m_iWidth, m_iHeight);
  for (int j = 0; j < m_lstSpanAgl.size(); j++)
  {
   painter.setBrush(cstDownPieColor[j]);
   painter.drawPie(rectDown, m_lstStartAgl.at(j)*16, m_lstSpanAgl.at(j)*16);
  }
}
//最上部分画一次（不同颜色）
QRect rectUp(m_iPosX, m_iPosY-m_iDepth, m_iWidth, m_iHeight);
for (int i = 0; i < m_lstPercent.size(); i++)
{
  painter.setBrush(cstUpPieColor[i]);
  painter.drawPie(rectUp, m_lstStartAgl.at(i)*16, m_lstSpanAgl.at(i)*16);
  painter.drawText(30,30,QString("here"));
}
painter.end();
}
