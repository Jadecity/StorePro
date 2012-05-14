#ifndef OVERTIMETAB_H
#define OVERTIMETAB_H

#include <QWidget>
#include <QTableWidget>
namespace Ui {
class OverTimeTab;
}

class OverTimeTab : public QWidget
{
    Q_OBJECT
    
public:
    explicit OverTimeTab(QWidget *parent = 0);
    ~OverTimeTab();
   void	setItem ( int row, int column, QTableWidgetItem * item );
private:
    Ui::OverTimeTab *ui;
};

#endif // OVERTIMETAB_H
