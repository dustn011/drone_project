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
#include <QTimer>
#include <QSqlDatabase>

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
    void moving_backward(int data);
    void moving_left(int data);
    void moving_right(int data);

    // 상승, 하강 기능
    void moving_ascent(int data);
    void moving_descent(int data);

    // 스레드로 작용할 함수들(상하좌우 버튼)
    void on_btn_forward_pressed();
    void on_btn_forward_released();

    void on_btn_backward_pressed();
    void on_btn_backward_released();

    void on_btn_left_pressed();
    void on_btn_left_released();

    void on_btn_right_pressed();
    void on_btn_right_released();

    // 상승, 하강 버튼
    void on_btn_ascent_pressed();
    void on_btn_ascent_released();

    void on_btn_descent_pressed();
    void on_btn_descent_released();

    // 연료 채우는 버튼
    void on_btn_refuel_clicked();

    // 연료 채우는 기능
    void refuel(int data);

    // 모든 버튼 비활성화 기능
    void enable_button_false();
    // 모든 버튼 활성화 기능
    void enable_button_true();

    // 연료가 0이 됐을 때 드론의 위치 어쩌고
    void check_position();

    // 랭킹 등록 이벤트
    void update_rank();

    void on_btn_cancel_clicked();

private:
    Ui::Drone *ui;
    Thread * thread;
    int drone_height = 0;
    int drone_fuel = 0;
    int travel_distance = 0;
};


#endif // DRONE_H
