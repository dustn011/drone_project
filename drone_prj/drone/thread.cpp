#include "thread.h"

Thread::Thread(QObject *parent):
    QThread(parent)
{

}

void Thread::run()
{
    int i = 0;
    th_end = false;
    while(true)
    {
        if(th_end)
        {
            qDebug() << "thread off!";
            break;
        }
        emit Send(i);   // Send 시그널 함수로 i를 송신
        i++;
        Sleep(70);
    }
    return;
}
