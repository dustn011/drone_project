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

// 전진 버튼, 드론 y축 증가
void Drone::on_btn_forward_clicked()
{
    QPoint labelPos = ui->lbl_drone->pos();
    if (labelPos.y() < 30)
        QMessageBox::information(this, "NO!", "You cannot go that direction! :(");
    else
    {
        qDebug() << "Label position: (" << labelPos.x() << ", " << labelPos.y() << ")";
        ui->lbl_drone->move(labelPos.x(), labelPos.y()-10);     // 10은 속력(1초에 10m를 이동합니다)
    }

}


// 전진 버튼 누르고 있을 때 드론 y축 증가(스레드 진행)
void Drone::on_btn_forward_pressed()
{
//    thread = new ForwardThread(this);
//    connect(thread, SIGNAL(forward_thread_end()), this, SLOT(forward_thread_run()));
//    thread->start();
}

// 전진 버튼 때면 드론 정지(스레드 멈춤)
void Drone::on_btn_forward_released()
{
//    thread->quit();
}

// 후진 버튼, 드론 y축 감소
void Drone::on_btn_backward_clicked()
{
    QPoint labelPos = ui->lbl_drone->pos();
    if (labelPos.y()+10 > 230)
        QMessageBox::information(this, "NO!", "You cannot go that direction! :(");
    else
    {
        ui->lbl_drone->move(labelPos.x(), labelPos.y()+10);
        qDebug() << "Label position: (" << labelPos.x() << ", " << labelPos.y() << ")";
    }
}

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
