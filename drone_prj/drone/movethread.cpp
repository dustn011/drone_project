#include "movethread.h"

// 전진 스레드(헤더파일에 선언해놓은 함수?들 다 정의안하면 build할 때 오류남 ㄱ-)
ForwardThread::ForwardThread(QObject *parent):QThread(parent)
{

}

void ForwardThread::forward_thread_run()
{
    while(true)
    {
        qDebug() << "전진";
        sleep(1);
    }
}

// 후진 스레드
BackwardThread::BackwardThread(QObject *parent):QThread(parent)
{

}

void BackwardThread::backward_thread_run()
{
    while(true)
    {
        qDebug() << "후진";
        sleep(1);
    }
}

// 좌 스레드
LeftThread::LeftThread(QObject *parent):QThread(parent)
{

}

void LeftThread::left_thread_run()
{
    while(true)
    {
        qDebug() << "좌";
        sleep(1);
    }
}

// 우 스레드
RightThread::RightThread(QObject *parent):QThread(parent)
{

}

void RightThread::right_thread_run()
{
    while(true)
    {
        qDebug() << "우";
        sleep(1);
    }
}
