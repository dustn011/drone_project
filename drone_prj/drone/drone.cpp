#include "drone.h"
#include "ui_drone.h"

Drone::Drone(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Drone)
{
    ui->setupUi(this);
    this->setWindowTitle("Drone");
}

Drone::~Drone()
{
    delete ui;
}



// 전진 버튼 누르고 있을 때 드론 y축 증가(스레드 진행)
void Drone::on_btn_forward_pressed()
{
    forward_thread = new Thread(this);      // Thread 클래스의 객체 만들기
    forward_thread->start();
    connect(forward_thread, SIGNAL(Send(int)), this, SLOT(moving_forward(int)));
}

// 전진 버튼 때면 드론 정지(스레드 멈춤)
void Drone::on_btn_forward_released()
{
    forward_thread->th_end = true;
}

//스레드 누르는 동안 y축 이동할 슬롯 함수
void Drone::moving_forward(int data)
{
    QPoint labelPos = ui->lbl_drone->pos();
    if (labelPos.y() < 30)
    {
        QMessageBox::information(this, "NO!", "You cannot go that direction! :(");
        forward_thread->th_end = true;
    }
    else
    {
        ui->lbl_drone->move(labelPos.x(), labelPos.y()-10);     // 10은 속력(1초에 10m를 이동합니다)
    }

}


//// 후진 버튼누르고 있을 때 드론 y축 감소(스레드 진행)
//void Drone::on_btn_backward_pressed()
//{
//    backward_thread = new Thread(this);      // Thread 클래스의 객체 만들기
//    backward_thread->start();
//    connect(backward_thread, SIGNAL(Send(int)), this, SLOT(moving_backward(int)));
//}


//void Drone::on_btn_backward_released()
//{
//    backward_thread->th_end = true;
//}

//void Drone::moving_backward(int data)
//{
//    QPoint labelPos = ui->lbl_drone->pos();
//    if (labelPos.y()+10 > 230)
//        QMessageBox::information(this, "NO!", "You cannot go that direction! :(");
//        backward_thread->th_end = true;
//    else
//    {
//        ui->lbl_drone->move(labelPos.x(), labelPos.y()+10);
//    }
//}


//void Drone::on_btn_left_pressed()
//{

//}


//void Drone::on_btn_left_released()
//{

//}


//void Drone::on_btn_right_pressed()
//{

//}


//void Drone::on_btn_right_released()
//{

//}


// 좌 버튼, 드론 x축 감소
void Drone::on_btn_left_clicked()
{
    QPoint labelPos = ui->lbl_drone->pos();
    if(labelPos.x()-10 < 140)
        QMessageBox::information(this, "NO!", "You cannot go that direction! :(");
    else
    {
        ui->lbl_drone->move(labelPos.x()-10, labelPos.y());
        qDebug() << "Label position: (" << labelPos.x() << ", " << labelPos.y() << ")";
    }
}


// 우 버튼, 드론 x축 증가
void Drone::on_btn_right_clicked()
{
    QPoint labelPos = ui->lbl_drone->pos();
    if (labelPos.x()+10 > 670)
        QMessageBox::information(this, "NO!", "You cannot go that direction! :(");
    else
    {
        ui->lbl_drone->move(labelPos.x()+10, labelPos.y());
        qDebug() << "Label position: (" << labelPos.x() << ", " << labelPos.y() << ")";
    }
}


// 상승 버튼, 드론 고도 증가
void Drone::on_btn_ascent_clicked()
{
    // empty
}

// 하강 버튼, 드론 고도 감소
void Drone::on_btn_descent_clicked()
{
    // empty
}
