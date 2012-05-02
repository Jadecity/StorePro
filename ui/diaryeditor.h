#ifndef DIARYEDITOR_H
#define DIARYEDITOR_H

#include <QWidget>

namespace Ui {
    class DiaryEditor;
}

class DiaryEditor : public QWidget
{
    Q_OBJECT

public:
    explicit DiaryEditor(QWidget *parent = 0);
    ~DiaryEditor();
public slots:
//    接收到状态信息，并显示
    void rcvData(QByteArray data);
private:
    Ui::DiaryEditor *ui;

private slots:
    void on_handinBtn_clicked();
signals:
//    info包括了4个QString，按照Diary结构体中的顺序
    void handinDiary(DiaryEditor *,QString *info);
};

#endif // DIARYEDITOR_H
