#ifndef WORKFLOW_H
#define WORKFLOW_H

#include "upcntrbase.h"
namespace WorkFlow
{
    class WorkFlowMgr:public UpCntrBase
    {
        Q_OBJECT
        public:
            explicit WorkFlowMgr(QObject *parent=0);
            ~WorkFlowMgr();
        private:
            DataTrans *datacntr;
        public slots:
            void  recv (QByteArray data);
            /*
                这里假设UI中缓冲了每个工作流的全部数据
                当所有的操纵都完成时将缓冲的指针传递给
                sendTables函数
            */
            //sendTables函数负责将UI缓冲的数据发送到服务器
            void sendTables();
        signals:
    };
}
#endif // WORKFLOW_H
