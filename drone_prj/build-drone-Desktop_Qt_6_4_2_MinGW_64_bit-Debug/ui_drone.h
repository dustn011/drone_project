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
#include <QtWidgets/QProgressBar>
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
    QPushButton *btn_ascent;
    QLabel *lbl_DroneBase;
    QLabel *lbl_drone;
    QLabel *label_3;
    QLabel *label_4;
    QProgressBar *progressBar_fuel;
    QPushButton *btn_refuel;
    QLabel *label;
    QListWidget *listWidget;
    QLabel *label_height;
    QSlider *verticalSlider_height;
    QPushButton *btn_left;
    QPushButton *btn_forward;
    QPushButton *btn_right;
    QPushButton *btn_backward;
    QLabel *label_travelDistance;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Drone)
    {
        if (Drone->objectName().isEmpty())
            Drone->setObjectName("Drone");
        Drone->resize(799, 493);
        centralwidget = new QWidget(Drone);
        centralwidget->setObjectName("centralwidget");
        dial_speed = new QDial(centralwidget);
        dial_speed->setObjectName("dial_speed");
        dial_speed->setGeometry(QRect(350, 300, 181, 131));
        dial_speed->setMaximum(200);
        dial_speed->setSingleStep(1);
        dial_speed->setNotchesVisible(true);
        btn_descent = new QPushButton(centralwidget);
        btn_descent->setObjectName("btn_descent");
        btn_descent->setGeometry(QRect(280, 370, 51, 41));
        btn_ascent = new QPushButton(centralwidget);
        btn_ascent->setObjectName("btn_ascent");
        btn_ascent->setGeometry(QRect(280, 310, 51, 41));
        lbl_DroneBase = new QLabel(centralwidget);
        lbl_DroneBase->setObjectName("lbl_DroneBase");
        lbl_DroneBase->setGeometry(QRect(90, 20, 571, 251));
        lbl_DroneBase->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lbl_drone = new QLabel(centralwidget);
        lbl_drone->setObjectName("lbl_drone");
        lbl_drone->setGeometry(QRect(90, 230, 41, 41));
        lbl_drone->setStyleSheet(QString::fromUtf8("background-color: rgb(175, 161, 255);"));
        lbl_drone->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(400, 430, 81, 16));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(540, 430, 41, 20));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);
        progressBar_fuel = new QProgressBar(centralwidget);
        progressBar_fuel->setObjectName("progressBar_fuel");
        progressBar_fuel->setGeometry(QRect(540, 300, 41, 121));
        progressBar_fuel->setValue(0);
        progressBar_fuel->setTextVisible(false);
        progressBar_fuel->setOrientation(Qt::Vertical);
        progressBar_fuel->setInvertedAppearance(false);
        btn_refuel = new QPushButton(centralwidget);
        btn_refuel->setObjectName("btn_refuel");
        btn_refuel->setGeometry(QRect(600, 340, 61, 81));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(690, 20, 81, 21));
        label->setAlignment(Qt::AlignCenter);
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(680, 40, 101, 221));
        label_height = new QLabel(centralwidget);
        label_height->setObjectName("label_height");
        label_height->setGeometry(QRect(17, 261, 71, 20));
        label_height->setAlignment(Qt::AlignCenter);
        verticalSlider_height = new QSlider(centralwidget);
        verticalSlider_height->setObjectName("verticalSlider_height");
        verticalSlider_height->setGeometry(QRect(40, 30, 22, 231));
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
        verticalSlider_height->setTickInterval(10);
        btn_left = new QPushButton(centralwidget);
        btn_left->setObjectName("btn_left");
        btn_left->setGeometry(QRect(90, 360, 51, 41));
        btn_forward = new QPushButton(centralwidget);
        btn_forward->setObjectName("btn_forward");
        btn_forward->setGeometry(QRect(140, 320, 51, 41));
        btn_right = new QPushButton(centralwidget);
        btn_right->setObjectName("btn_right");
        btn_right->setGeometry(QRect(190, 360, 51, 41));
        btn_backward = new QPushButton(centralwidget);
        btn_backward->setObjectName("btn_backward");
        btn_backward->setGeometry(QRect(140, 360, 51, 41));
        label_travelDistance = new QLabel(centralwidget);
        label_travelDistance->setObjectName("label_travelDistance");
        label_travelDistance->setGeometry(QRect(680, 350, 101, 51));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        label_travelDistance->setFont(font1);
        label_travelDistance->setAlignment(Qt::AlignCenter);
        Drone->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Drone);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 799, 22));
        Drone->setMenuBar(menubar);
        statusbar = new QStatusBar(Drone);
        statusbar->setObjectName("statusbar");
        Drone->setStatusBar(statusbar);
        QWidget::setTabOrder(btn_ascent, btn_descent);
        QWidget::setTabOrder(btn_descent, dial_speed);

        retranslateUi(Drone);

        QMetaObject::connectSlotsByName(Drone);
    } // setupUi

    void retranslateUi(QMainWindow *Drone)
    {
        Drone->setWindowTitle(QCoreApplication::translate("Drone", "Drone", nullptr));
        btn_descent->setText(QCoreApplication::translate("Drone", "\355\225\230\352\260\225", nullptr));
        btn_ascent->setText(QCoreApplication::translate("Drone", "\354\203\201\354\212\271", nullptr));
        lbl_DroneBase->setText(QString());
        lbl_drone->setText(QCoreApplication::translate("Drone", "drone", nullptr));
        label_3->setText(QCoreApplication::translate("Drone", "m/s", nullptr));
        label_4->setText(QCoreApplication::translate("Drone", "Fuel", nullptr));
        btn_refuel->setText(QCoreApplication::translate("Drone", "\354\227\260\353\243\214", nullptr));
        label->setText(QCoreApplication::translate("Drone", "\353\236\255\355\202\271", nullptr));
        label_height->setText(QCoreApplication::translate("Drone", "\352\263\240\353\217\204(0m)", nullptr));
        btn_left->setText(QCoreApplication::translate("Drone", "\354\242\214", nullptr));
        btn_forward->setText(QCoreApplication::translate("Drone", "\354\240\204\354\247\204", nullptr));
        btn_right->setText(QCoreApplication::translate("Drone", "\354\232\260", nullptr));
        btn_backward->setText(QCoreApplication::translate("Drone", "\355\233\204\354\247\204", nullptr));
        label_travelDistance->setText(QCoreApplication::translate("Drone", "(0m)\n"
"\354\235\264\353\217\231\352\261\260\353\246\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Drone: public Ui_Drone {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRONE_H
