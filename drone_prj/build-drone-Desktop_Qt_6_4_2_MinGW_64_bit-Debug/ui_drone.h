/********************************************************************************
** Form generated from reading UI file 'drone.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRONE_H
#define UI_DRONE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Drone
{
public:
    QWidget *centralwidget;
    QDial *dial_speed;
    QPushButton *btn_descent;
    QPushButton *btn_forward;
    QLabel *label;
    QPushButton *btn_backward;
    QListWidget *listWidget;
    QDial *dial_fuel;
    QPushButton *btn_ascent;
    QLabel *lbl_DroneBase;
    QLabel *lbl_drone;
    QLabel *label_2;
    QSlider *verticalSlider_height;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *btn_left;
    QPushButton *btn_right;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Drone)
    {
        if (Drone->objectName().isEmpty())
            Drone->setObjectName("Drone");
        Drone->resize(799, 500);
        centralwidget = new QWidget(Drone);
        centralwidget->setObjectName("centralwidget");
        dial_speed = new QDial(centralwidget);
        dial_speed->setObjectName("dial_speed");
        dial_speed->setGeometry(QRect(190, 290, 181, 131));
        dial_speed->setMaximum(200);
        dial_speed->setSingleStep(1);
        dial_speed->setNotchesVisible(true);
        btn_descent = new QPushButton(centralwidget);
        btn_descent->setObjectName("btn_descent");
        btn_descent->setGeometry(QRect(90, 380, 51, 41));
        btn_forward = new QPushButton(centralwidget);
        btn_forward->setObjectName("btn_forward");
        btn_forward->setGeometry(QRect(650, 330, 51, 41));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 30, 81, 21));
        label->setAlignment(Qt::AlignCenter);
        btn_backward = new QPushButton(centralwidget);
        btn_backward->setObjectName("btn_backward");
        btn_backward->setGeometry(QRect(650, 370, 51, 41));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(20, 50, 101, 221));
        dial_fuel = new QDial(centralwidget);
        dial_fuel->setObjectName("dial_fuel");
        dial_fuel->setGeometry(QRect(400, 290, 181, 131));
        dial_fuel->setMaximum(200);
        dial_fuel->setSingleStep(1);
        dial_fuel->setNotchesVisible(true);
        btn_ascent = new QPushButton(centralwidget);
        btn_ascent->setObjectName("btn_ascent");
        btn_ascent->setGeometry(QRect(90, 320, 51, 41));
        lbl_DroneBase = new QLabel(centralwidget);
        lbl_DroneBase->setObjectName("lbl_DroneBase");
        lbl_DroneBase->setGeometry(QRect(140, 20, 571, 251));
        lbl_DroneBase->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lbl_drone = new QLabel(centralwidget);
        lbl_drone->setObjectName("lbl_drone");
        lbl_drone->setGeometry(QRect(140, 230, 41, 41));
        lbl_drone->setStyleSheet(QString::fromUtf8("background-color: rgb(175, 161, 255);"));
        lbl_drone->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(727, 260, 51, 20));
        label_2->setAlignment(Qt::AlignCenter);
        verticalSlider_height = new QSlider(centralwidget);
        verticalSlider_height->setObjectName("verticalSlider_height");
        verticalSlider_height->setGeometry(QRect(740, 29, 22, 231));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(verticalSlider_height->sizePolicy().hasHeightForWidth());
        verticalSlider_height->setSizePolicy(sizePolicy);
        verticalSlider_height->setMouseTracking(false);
        verticalSlider_height->setFocusPolicy(Qt::StrongFocus);
        verticalSlider_height->setMinimum(0);
        verticalSlider_height->setMaximum(99);
        verticalSlider_height->setSingleStep(10);
        verticalSlider_height->setValue(0);
        verticalSlider_height->setOrientation(Qt::Vertical);
        verticalSlider_height->setTickPosition(QSlider::TicksAbove);
        verticalSlider_height->setTickInterval(11);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(240, 430, 81, 16));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(460, 430, 61, 16));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);
        btn_left = new QPushButton(centralwidget);
        btn_left->setObjectName("btn_left");
        btn_left->setGeometry(QRect(600, 370, 51, 41));
        btn_right = new QPushButton(centralwidget);
        btn_right->setObjectName("btn_right");
        btn_right->setGeometry(QRect(700, 370, 51, 41));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(720, 246, 21, 16));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(720, 222, 21, 16));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(720, 197, 21, 16));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(720, 172, 21, 16));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(720, 149, 21, 16));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(720, 125, 21, 16));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(720, 100, 21, 16));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(720, 75, 21, 16));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(720, 51, 21, 16));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(710, 27, 31, 16));
        label_14->setAlignment(Qt::AlignCenter);
        Drone->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Drone);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 799, 22));
        Drone->setMenuBar(menubar);
        statusbar = new QStatusBar(Drone);
        statusbar->setObjectName("statusbar");
        Drone->setStatusBar(statusbar);
        QWidget::setTabOrder(listWidget, verticalSlider_height);
        QWidget::setTabOrder(verticalSlider_height, btn_ascent);
        QWidget::setTabOrder(btn_ascent, btn_descent);
        QWidget::setTabOrder(btn_descent, dial_speed);
        QWidget::setTabOrder(dial_speed, dial_fuel);
        QWidget::setTabOrder(dial_fuel, btn_forward);
        QWidget::setTabOrder(btn_forward, btn_left);
        QWidget::setTabOrder(btn_left, btn_right);
        QWidget::setTabOrder(btn_right, btn_backward);

        retranslateUi(Drone);

        QMetaObject::connectSlotsByName(Drone);
    } // setupUi

    void retranslateUi(QMainWindow *Drone)
    {
        Drone->setWindowTitle(QCoreApplication::translate("Drone", "Drone", nullptr));
        btn_descent->setText(QCoreApplication::translate("Drone", "\355\225\230\352\260\225", nullptr));
        btn_forward->setText(QCoreApplication::translate("Drone", "\354\240\204\354\247\204", nullptr));
        label->setText(QCoreApplication::translate("Drone", "\353\236\255\355\202\271", nullptr));
        btn_backward->setText(QCoreApplication::translate("Drone", "\355\233\204\354\247\204", nullptr));
        btn_ascent->setText(QCoreApplication::translate("Drone", "\354\203\201\354\212\271", nullptr));
        lbl_DroneBase->setText(QString());
        lbl_drone->setText(QCoreApplication::translate("Drone", "drone", nullptr));
        label_2->setText(QCoreApplication::translate("Drone", "\352\263\240\353\217\204(0m)", nullptr));
        label_3->setText(QCoreApplication::translate("Drone", "m/s", nullptr));
        label_4->setText(QCoreApplication::translate("Drone", "Fuel", nullptr));
        btn_left->setText(QCoreApplication::translate("Drone", "\354\242\214", nullptr));
        btn_right->setText(QCoreApplication::translate("Drone", "\354\232\260", nullptr));
        label_5->setText(QCoreApplication::translate("Drone", "10", nullptr));
        label_6->setText(QCoreApplication::translate("Drone", "20", nullptr));
        label_7->setText(QCoreApplication::translate("Drone", "30", nullptr));
        label_8->setText(QCoreApplication::translate("Drone", "40", nullptr));
        label_9->setText(QCoreApplication::translate("Drone", "50", nullptr));
        label_10->setText(QCoreApplication::translate("Drone", "60", nullptr));
        label_11->setText(QCoreApplication::translate("Drone", "70", nullptr));
        label_12->setText(QCoreApplication::translate("Drone", "80", nullptr));
        label_13->setText(QCoreApplication::translate("Drone", "90", nullptr));
        label_14->setText(QCoreApplication::translate("Drone", "100", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Drone: public Ui_Drone {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRONE_H
