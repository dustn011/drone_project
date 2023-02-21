#ifndef DRONE_H
#define DRONE_H
#include "movethread.h"

#include <iostream>
#include <QMainWindow>
#include <QWidget>
#include <QDebug>
#include <QMessageBox>
#include <QLabel>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QThread>
#include <QApplication>

#include <QString>
#include <QTimer>
#include <QVector>
#include <QCheckBox>
#include <QComboBox>
#include <QList>



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
    // 상승, 하강 버튼
    void on_btn_ascent_clicked();
    void on_btn_descent_clicked();

    // 상하좌우 이동 버튼
    void on_btn_forward_clicked();
    void on_btn_backward_clicked();
    void on_btn_left_clicked();
    void on_btn_right_clicked();

    // 상하좌우 이동 (스레드로)
    void on_btn_forward_pressed();
    void on_btn_forward_released();

private:
    Ui::Drone *ui;
    ForwardThread * movethread;
};


#endif // DRONE_H
