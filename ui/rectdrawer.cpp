#include "rectdrawer.h"
#include <QPainter>

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

RectDrawer::RectDrawer(QWidget *parent) :
    QWidget(parent),m_iPosX(0),m_iPosY(0),m_iWidth(0),m_iHeight(0),
    m_iDistence(0)
{
    m_lstPercent.clear();
}

RectDrawer::~RectDrawer()
{
    m_lstPercent.clear();
}

void RectDrawer::setPos(int iPosX, int iPosY)
{
    m_iPosX = iPosX;
    m_iPosY = iPosY;
}
void RectDrawer::setSize(int iWidth, int iHeight)
{
    m_iWidth = iWidth;
    m_iHeight = iHeight;
}

void RectDrawer::setRectPercent(QList<float> lstPercent)
{
    m_lstPercent = lstPercent;
}

void RectDrawer::setDistance(int margin)
{
    m_iDistence = margin;
}

void RectDrawer::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter;
    painter.begin(this);

    int count = m_lstPercent.size();
    if (count <= 0)
    {
      return;
    }

    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::black,12,Qt::DashLine,Qt::RoundCap));
    for(int i=0;i<count;i++)
    {
        painter.setBrush(cstDownPieColor[i]);
        painter.drawRect(m_iPosX,m_iPosY - i*(m_iWidth + m_iDistence),m_iWidth*m_lstPercent[i],m_iHeight/m_lstPercent.size()-m_iDistence);
    }
    painter.end();
 }
