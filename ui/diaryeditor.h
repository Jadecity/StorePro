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
//    ���յ�״̬��Ϣ������ʾ
    void rcvData(QByteArray data);
private:
    Ui::DiaryEditor *ui;

private slots:
    void on_handinBtn_clicked();
signals:
//    info������4��QString������Diary�ṹ���е�˳��
    void handinDiary(DiaryEditor *,QString *info);
};

#endif // DIARYEDITOR_H
