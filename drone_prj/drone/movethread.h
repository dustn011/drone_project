#ifndef MOVETHREAD_H
#define MOVETHREAD_H
#include <QThread>
#include <windows.h>
#include <qdebug.h>

/* 이동 스레드들을 모아놓은 헤더 파일 */

class ForwardThread: public QThread
{
    Q_OBJECT
public:
    // explict은 자동 형변환을 하지 않게 해준다(성일님 이거 왜 썼어요?)
    explicit ForwardThread(QObject * parent = 0);
private:
    // 스레드 실행 함수
    void forward_thread_run();
signals:
    void forward_thread_end();
};

class BackwardThread: public QThread
{
    Q_OBJECT
public:
    explicit BackwardThread(QObject * parent = 0);
private:
    // 스레드 실행 함수
    void backward_thread_run();
};

class LeftThread: public QThread
{
    Q_OBJECT
public:
    explicit LeftThread(QObject * parent = 0);
private:
    // 스레드 실행 함수
    void left_thread_run();
};


class RightThread: public QThread
{
    Q_OBJECT
public:
    explicit RightThread(QObject * parent = 0);
private:
    // 스레드 실행 함수
    void right_thread_run();
};


#endif // MOVETHREAD_H
