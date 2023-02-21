#ifndef DRONE_H
#define DRONE_H

#include <QMainWindow>
#include <QWidget>
#include <QDebug>
#include <QMessageBox>
#include <QLabel>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QApplication>

#include <iostream>
#include <thread>
#include "thread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Drone; }
QT_END_NAMESPACE

class Drone : public QMainWindow
{
    Q_OBJECT

public:
    Drone(QWidget *parent = nullptr);
    ~Drone();

private slots:
    // 상하좌우 이동 기능
    void moving_forward(int data);
//    void moving_backward(int data);
//    void moving_left(int data);
//    void moving_right(int data);

    // 스레드로 작용할 함수들(상하좌우 버튼)
    void on_btn_forward_pressed();
    void on_btn_forward_released();

//    void on_btn_backward_pressed();
//    void on_btn_backward_released();

//    void on_btn_left_pressed();
//    void on_btn_left_released();

//    void on_btn_right_pressed();
//    void on_btn_right_released();

    // 상승, 하강 버튼
    void on_btn_ascent_clicked();
    void on_btn_descent_clicked();

    // 버튼
    void on_btn_left_clicked();
    void on_btn_right_clicked();



private:
    Ui::Drone *ui;
    Thread * forward_thread;
    Thread * backward_thread;
    Thread * left_thread;
    Thread * right_thread;
};


#endif // DRONE_H
