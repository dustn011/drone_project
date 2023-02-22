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

    // ui 사용자가 조종? 못하게함
    ui->verticalSlider_height->setDisabled(true);
    ui->dial_speed->setDisabled(true);

    connect(ui->progressBar_fuel, &QProgressBar::valueChanged, this, &Drone::check_position);

    ui->lineEdit_ranking->setMaxLength(5);      // lineedit 길이제한
    connect(ui->lineEdit_ranking, &QLineEdit::returnPressed, this, &Drone::update_rank);
    connect(ui->btn_ok, &QPushButton::clicked, this, &Drone::update_rank);

}

Drone::~Drone()
{
    delete ui;
}

// 전진 버튼 누르고 있을 때 드론 y축 증가(스레드 진행)
void Drone::on_btn_forward_pressed()
{
    // 연료가 없을 때
    if(drone_fuel == 0)
        QMessageBox::information(this, "NO!", "You are not have enough fuel! :(");
    // 드론이 떠있지 않을 때
    else if(drone_height == 0)
        QMessageBox::information(this, "NO!", "The drone have too low height! :(");
    else
    {
        thread->start();
        connect(thread, SIGNAL(Send(int)), this, SLOT(moving_forward(int)));
    }
}

// 전진 버튼 때면 드론 정지(스레드 멈춤)
void Drone::on_btn_forward_released()
{
    thread->th_end = true;      // 스레드 종료
    disconnect(thread, SIGNAL(Send(int)), this, SLOT(moving_forward(int)));     // 연결 함수 끊어버리기
    ui->dial_speed->setValue(0);        // 미터기? 초기화
}

//스레드 누르는 동안 y축 이동할 슬롯 함수
void Drone::moving_forward(int data)
{
    thread->th_end = false;
    QPoint labelPos = ui->lbl_drone->pos();
    if (labelPos.y() <= 20)
    {
        QMessageBox::information(this, "NO!", "You cannot go that direction! :(");
        thread->th_end = true;
    }
    else
    {
        ui->lbl_drone->move(labelPos.x(), labelPos.y()-5);  // 드론 위치 이동
        ui->dial_speed->setValue(data*5);   // 미터기 상승

        travel_distance += 5;   // 총 이동거리 계산하기
        ui->label_travelDistance->setText("("+QString::number(travel_distance)+"m)\n이동거리");     // 총 이동거리 출력

        drone_fuel -= 1;        // 연료 감소
        ui->progressBar_fuel->setValue(drone_fuel);
    }
    qDebug() << "Label position: (" << labelPos.x() << ", " << labelPos.y() << ")";
}

// 후진 버튼누르고 있을 때 드론 y축 감소(스레드 진행)
void Drone::on_btn_backward_pressed()
{
    if(drone_fuel == 0)
        QMessageBox::information(this, "NO!", "You are not have enough fuel! :(");
    else if(drone_height == 0)
        QMessageBox::information(this, "NO!", "The drone have too low height! :(");
    else
    {
        thread->start();
        connect(thread, SIGNAL(Send(int)), this, SLOT(moving_backward(int)));
    }
}

// 후진 버튼 때면 드론 정지(스레드 멈춤)
void Drone::on_btn_backward_released()
{
    thread->th_end = true;
    disconnect(thread, SIGNAL(Send(int)), this, SLOT(moving_backward(int)));
    ui->dial_speed->setValue(0);
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
        ui->lbl_drone->move(labelPos.x(), labelPos.y()+5);     // 5은 속력(1초에 5m를 이동합니다)
        ui->dial_speed->setValue(data*5);

        travel_distance += 5;
        ui->label_travelDistance->setText("("+QString::number(travel_distance)+"m)\n이동거리");

        drone_fuel -= 1;
        ui->progressBar_fuel->setValue(drone_fuel);
    }
    qDebug() << "Label position: (" << labelPos.x() << ", " << labelPos.y() << ")";
}


// 좌 버튼누르고 있으면 드론 x축 감소(스레드 진행)
void Drone::on_btn_left_pressed()
{
    if(drone_fuel == 0)
        QMessageBox::information(this, "NO!", "You are not have enough fuel! :(");
    else if(drone_height == 0)
        QMessageBox::information(this, "NO!", "The drone have too low height! :(");
    else
    {
        thread->start();
        connect(thread, SIGNAL(Send(int)), this, SLOT(moving_left(int)));
    }
}

// 좌 버튼 때면 드론 정지(스레드 멈춤)
void Drone::on_btn_left_released()
{
    thread->th_end = true;
    disconnect(thread, SIGNAL(Send(int)), this, SLOT(moving_left(int)));
    ui->dial_speed->setValue(0);
}

// 스레드 실행될 동안 x축 이동할 슬롯 함수
void Drone::moving_left(int data)
{
    thread->th_end = false;
    QPoint labelPos = ui->lbl_drone->pos();
    if(labelPos.x() <= 90)
    {
        QMessageBox::information(this, "NO!", "You cannot go that direction! :(");
        thread->th_end = true;
    }
    else
    {
        ui->lbl_drone->move(labelPos.x()-5, labelPos.y());
        ui->dial_speed->setValue(data*5);

        travel_distance += 5;
        ui->label_travelDistance->setText("("+QString::number(travel_distance)+"m)\n이동거리");

        drone_fuel -= 1;
        ui->progressBar_fuel->setValue(drone_fuel);
    }
    qDebug() << "Label position: (" << labelPos.x() << ", " << labelPos.y() << ")";
}


// 우 버튼누르고 있으면 드론 x축 증가(스레드 진행)
void Drone::on_btn_right_pressed()
{
    if(drone_fuel == 0)
        QMessageBox::information(this, "NO!", "You are not have enough fuel! :(");
    else if(drone_height == 0)
        QMessageBox::information(this, "NO!", "The drone have too low height! :(");
    else
    {
        thread->start();
        connect(thread, SIGNAL(Send(int)), this, SLOT(moving_right(int)));
    }
}

// 우 버튼 때면 드론 정지(스레드 멈춤)
void Drone::on_btn_right_released()
{
    thread->th_end = true;
    disconnect(thread, SIGNAL(Send(int)), this, SLOT(moving_right(int)));
    ui->dial_speed->setValue(0);
}

// 스레드 실행될 동안 x축 이동할 슬롯 함수
void Drone::moving_right(int data)
{
    thread->th_end = false;
    QPoint labelPos = ui->lbl_drone->pos();
    if(labelPos.x() >= 620)
    {
        QMessageBox::information(this, "NO!", "You cannot go that direction! :(");
        thread->th_end = true;
    }
    else
    {
        ui->lbl_drone->move(labelPos.x()+5, labelPos.y());
        ui->dial_speed->setValue(data*5);

        travel_distance += 5;
        ui->label_travelDistance->setText("("+QString::number(travel_distance)+"m)\n이동거리");

        drone_fuel -= 1;
        ui->progressBar_fuel->setValue(drone_fuel);
    }
    qDebug() << "Label position: (" << labelPos.x() << ", " << labelPos.y() << ")";
}


// 상승 버튼, 드론 고도 증가(스레드 실행)
void Drone::on_btn_ascent_pressed()
{
    if(drone_fuel == 0)
        QMessageBox::information(this, "NO!", "You are not have enough fuel! :(");
    else
    {
        thread->start();
        connect(thread, SIGNAL(Send(int)), this, SLOT(moving_ascent(int)));
    }
}

// 드론 상승 멈춤(스레드 정지)
void Drone::on_btn_ascent_released()
{
    thread->th_end = true;
    disconnect(thread, SIGNAL(Send(int)), this, SLOT(moving_ascent(int)));
    ui->dial_speed->setValue(0);
}

// 상승 버튼 기능
void Drone::moving_ascent(int data)
{
    if (drone_height == 100)
    {
        QMessageBox::information(this, "NO!", "You are at too high position! :(");
        thread->th_end = true;
    }
    else
    {
        drone_height += 1;
        ui->verticalSlider_height->setValue(drone_height);
        ui->label_height->setText("고도("+QString::number(drone_height)+")m");
        ui->dial_speed->setValue(data*1);

        travel_distance += 1;
        ui->label_travelDistance->setText("("+QString::number(travel_distance)+"m)\n이동거리");

        drone_fuel -= 1;
        ui->progressBar_fuel->setValue(drone_fuel);
    }
}

// 하강 버튼, 드론 고도 감소(스레드 실행)
void Drone::on_btn_descent_pressed()
{
    if(drone_fuel == 0)
        QMessageBox::information(this, "NO!", "You are not have enough fuel! :(");
    else
    {
        thread->start();
        connect(thread, SIGNAL(Send(int)), this, SLOT(moving_descent(int)));
    }
}

// 드론 하강 멈춤(스레드 정지)
void Drone::on_btn_descent_released()
{
    thread->th_end = true;
    disconnect(thread, SIGNAL(Send(int)), this, SLOT(moving_descent(int)));
    ui->dial_speed->setValue(0);
}

// 하강 버튼 기능
void Drone::moving_descent(int data)
{
    QPoint labelPos = ui->lbl_drone->pos();

    if(drone_height==0 && labelPos.x()==90 && labelPos.y()==230)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Drone is back!", "Do you want to continue?", QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes);     // 예 버튼 눌렀을 때 계속 진행
        else
        {
            // 아니오 버튼을 눌렀을 때 랭킹등록 페이지로 이동
            ui->stackedWidget->setCurrentIndex(1);
        }
    }
    else if (drone_height == 0)
    {
        QMessageBox::information(this, "NO!", "You are on the ground! :(");
        thread->th_end = true;
    }
    else
    {
        drone_height -= 1;
        ui->verticalSlider_height->setValue(drone_height);
        ui->label_height->setText("고도("+QString::number(drone_height)+")m");
        ui->dial_speed->setValue(data*1);

        travel_distance += 1;
        ui->label_travelDistance->setText("("+QString::number(travel_distance)+"m)\n이동거리");

        drone_fuel -= 1;
        ui->progressBar_fuel->setValue(drone_fuel);
    }
}

// 연료 채우기 버튼
void Drone::on_btn_refuel_clicked()
{
    QPoint labelPos = ui->lbl_drone->pos();
    if((drone_height==0) && (labelPos.x()==90) && (labelPos.y()==230))
    {
        qDebug() << "refuel now...";

        enable_button_false();      // 버튼 기능 모두 비활성화 시키기 (연료 채울 때 다른 행동 불가)
        thread->start();            // 스레드 실행
        connect(thread, SIGNAL(Send(int)), this, SLOT(refuel(int)));
    }
    else
        QMessageBox::information(this, "NO!", "your drone is not on your hand! :(");

}

// 연료 채우는 기능
void Drone::refuel(int data)
{
    drone_fuel += 2;
    ui->progressBar_fuel->setValue(drone_fuel);
    if (drone_fuel >= 100)
    {
        thread->th_end = true;
        disconnect(thread, SIGNAL(Send(int)), this, SLOT(refuel(int)));
        enable_button_true();       // 버튼 기능 모두 활성화 시키기 (연료 모두 채우고 나서 행동 가능)
    }
}

// 버튼들 비활성화 시키기
void Drone::enable_button_false()
{
    ui->btn_ascent->setEnabled(false);
    ui->btn_descent->setEnabled(false);
    ui->btn_forward->setEnabled(false);
    ui->btn_backward->setEnabled(false);
    ui->btn_left->setEnabled(false);
    ui->btn_right->setEnabled(false);
    ui->btn_refuel->setEnabled(false);
}

// 버튼들 활성화 시키기
void Drone::enable_button_true()
{
    ui->btn_ascent->setEnabled(true);
    ui->btn_descent->setEnabled(true);
    ui->btn_forward->setEnabled(true);
    ui->btn_backward->setEnabled(true);
    ui->btn_left->setEnabled(true);
    ui->btn_right->setEnabled(true);
    ui->btn_refuel->setEnabled(true);
}

void Drone::check_position()
{
    QPoint labelPos = ui->lbl_drone->pos();
    if((drone_height==0) && (labelPos.x()==90) && (labelPos.y()==230))
        return;
    // 연료가 다 떨어졌을 때 드론 추락
    else if(ui->progressBar_fuel->value() == 0)
    {
        QMessageBox::information(this, "NOOOOOOO", "The drone was fallen! :(\nWe're taking back the drones");
        ui->lbl_drone->move(90, 230);
        drone_height = 0;
        ui->verticalSlider_height->setValue(drone_height);
        ui->label_height->setText("고도("+QString::number(drone_height)+")m");

        travel_distance = 0;
        ui->label_travelDistance->setText("("+QString::number(travel_distance)+"m)\n이동거리");
    }
}

// 랭킹 등록 이벤트
void Drone::update_rank()
{
    qDebug() << ui->lineEdit_ranking->text();
    // 랭킹 등록
    // 드론 조종 페이지로 이동
    QMessageBox::information(this, "Register Success", "your rank is registerd!");
    ui->lineEdit_ranking->clear();
    travel_distance = 0;
    drone_fuel = 0;

    ui->label_travelDistance->setText("("+QString::number(travel_distance)+"m)\n이동거리");
    ui->progressBar_fuel->setValue(drone_fuel);

    ui->stackedWidget->setCurrentIndex(0);
}


// 랭킹 등록 취소
void Drone::on_btn_cancel_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

