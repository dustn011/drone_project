#include "drone.h"
#include "ui_drone.h"

Drone::Drone(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Drone)
{
    ui->setupUi(this);
    this->setWindowTitle("Drone");
    thread = new Thread(this);      // Thread 클래스의 객체 만들기

    ui->verticalSlider_height->setValue(drone_height);
}

Drone::~Drone()
{
    delete ui;
}

// 전진 버튼 누르고 있을 때 드론 y축 증가(스레드 진행)
void Drone::on_btn_forward_pressed()
{
    thread->start();
    connect(thread, SIGNAL(Send(int)), this, SLOT(moving_forward(int)));
}

// 전진 버튼 때면 드론 정지(스레드 멈춤)
void Drone::on_btn_forward_released()
{
    thread->th_end = true;
    disconnect(thread, SIGNAL(Send(int)), this, SLOT(moving_forward(int)));
}

//스레드 누르는 동안 y축 이동할 슬롯 함수
void Drone::moving_forward(int data)
{
    thread->th_end = false;
    QPoint labelPos = ui->lbl_drone->pos();
    if (labelPos.y() < 30)
    {
        QMessageBox::information(this, "NO!", "You cannot go that direction! :(");
        thread->th_end = true;
    }
    else
    {
        ui->lbl_drone->move(labelPos.x(), labelPos.y()-10);     // 10은 속력(1초에 10m를 이동합니다)
        qDebug() << "Label position: (" << labelPos.x() << ", " << labelPos.y() << ")";
    }
    qDebug() << "전진 " << data;
}


// 후진 버튼누르고 있을 때 드론 y축 감소(스레드 진행)
void Drone::on_btn_backward_pressed()
{
    thread->start();
    connect(thread, SIGNAL(Send(int)), this, SLOT(moving_backward(int)));
}

// 후진 버튼 때면 드론 정지(스레드 멈춤)
void Drone::on_btn_backward_released()
{
    thread->th_end = true;
    disconnect(thread, SIGNAL(Send(int)), this, SLOT(moving_backward(int)));
}

// 스레드 실행될 동안 y축 이동할 슬롯 함수
void Drone::moving_backward(int data)
{
    thread->th_end = false;
    QPoint labelPos = ui->lbl_drone->pos();
    if (labelPos.y() >= 230)
    {
        QMessageBox::information(this, "NO!", "You cannot go that direction! :(");
        thread->th_end = true;
    }
    else
    {
        ui->lbl_drone->move(labelPos.x(), labelPos.y()+10);     // 10은 속력(1초에 10m를 이동합니다)
        qDebug() << "Label position: (" << labelPos.x() << ", " << labelPos.y() << ")";
    }
    qDebug() << "후진 " << data;
}


// 좌 버튼누르고 있으면 드론 x축 감소(스레드 진행)
void Drone::on_btn_left_pressed()
{
    thread->start();
    connect(thread, SIGNAL(Send(int)), this, SLOT(moving_left(int)));
}

// 좌 버튼 때면 드론 정지(스레드 멈춤)
void Drone::on_btn_left_released()
{
    thread->th_end = true;
    disconnect(thread, SIGNAL(Send(int)), this, SLOT(moving_left(int)));
}

// 스레드 실행될 동안 x축 이동할 슬롯 함수
void Drone::moving_left(int data)
{
    thread->th_end = false;
    QPoint labelPos = ui->lbl_drone->pos();
    if(labelPos.x()-10 < 140)
    {
        QMessageBox::information(this, "NO!", "You cannot go that direction! :(");
        thread->th_end = true;
    }
    else
    {
        ui->lbl_drone->move(labelPos.x()-10, labelPos.y());
        qDebug() << "Label position: (" << labelPos.x() << ", " << labelPos.y() << ")";
    }
    qDebug() << "좌로 이동 " << data;
}


// 우 버튼누르고 있으면 드론 x축 증가(스레드 진행)
void Drone::on_btn_right_pressed()
{
    thread->start();
    connect(thread, SIGNAL(Send(int)), this, SLOT(moving_right(int)));
}

// 우 버튼 때면 드론 정지(스레드 멈춤)
void Drone::on_btn_right_released()
{
    thread->th_end = true;
    disconnect(thread, SIGNAL(Send(int)), this, SLOT(moving_right(int)));
}

// 스레드 실행될 동안 x축 이동할 슬롯 함수
void Drone::moving_right(int data)
{
    thread->th_end = false;
    QPoint labelPos = ui->lbl_drone->pos();
    if(labelPos.x()-10 > 650)
    {
        QMessageBox::information(this, "NO!", "You cannot go that direction! :(");
        thread->th_end = true;
    }
    else
    {
        ui->lbl_drone->move(labelPos.x()+10, labelPos.y());
        qDebug() << "Label position: (" << labelPos.x() << ", " << labelPos.y() << ")";
    }
    qDebug() << "우로 이동 " << data;
}


// 상승 버튼, 드론 고도 증가
void Drone::on_btn_ascent_pressed()
{
    thread->start();
    connect(thread, SIGNAL(Send(int)), this, SLOT(moving_ascent(int)));
}

// 드론 상승 멈춤
void Drone::on_btn_ascent_released()
{
    thread->th_end = true;
    disconnect(thread, SIGNAL(Send(int)), this, SLOT(moving_ascent(int)));
}

void Drone::moving_ascent(int data)
{
    if (drone_height == 100)
    {
        QMessageBox::information(this, "NO!", "You are at too high position! :(");
        thread->th_end = true;
    }
    else
    {
        drone_height += 10;
        ui->verticalSlider_height->setValue(drone_height);
        qDebug() << (ui->verticalSlider_height->value());
    }
}

// 하강 버튼, 드론 고도 감소
void Drone::on_btn_descent_pressed()
{
    thread->start();
    connect(thread, SIGNAL(Send(int)), this, SLOT(moving_descent(int)));
}

// 드론 하강 멈춤
void Drone::on_btn_descent_released()
{
    thread->th_end = true;
    disconnect(thread, SIGNAL(Send(int)), this, SLOT(moving_descent(int)));
}

void Drone::moving_descent(int data)
{
    if (drone_height == 0)
    {
        QMessageBox::information(this, "NO!", "You are on the ground! :(");
        thread->th_end = true;
    }
    else
    {
        drone_height -= 10;
        ui->verticalSlider_height->setValue(drone_height);
        qDebug() << (ui->verticalSlider_height->value());
    }
}
