#ifndef WORKFLOW_H
#define WORKFLOW_H

#include "upcntrbase.h"
#include "logic/cmddef.h"

namespace WorkFlow
{
    class WorkFlowMgr:public UpCntrBase
    {
        Q_OBJECT
        public:
            explicit WorkFlowMgr(QObject *parent=0);
            ~WorkFlowMgr();
            void setDatacntr (DataTrans *dc);
        private:
            DataTrans *datacntr;
        public slots:
            void  recv (QByteArray data);
            /*
                �������UI�л�����ÿ����������ȫ������
                �����еĲ��ݶ����ʱ�������ָ�봫�ݸ�
                sendTables����
            */
            //sendTables��������UI��������ݷ��͵�������
            void sendTables(QByteArray,int);
        signals:
            //�����������ص�״̬��ʾ��UI��
            void post2ui(int flag,QByteArray data);
    };
}
#endif // WORKFLOW_H
