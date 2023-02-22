#ifndef THREAD_H
#define THREAD_H
#include <QThread>
#include <QtDebug>
#include <windows.h>

class Thread:public QThread
{
    Q_OBJECT

public:
    bool th_end = false;
    explicit Thread(QObject*parent = 0);
private:
    void run();     // <- 스레드로 동작할 함수
signals:
    void Send(int data);
};

#endif // THREAD_H
