#include "drone.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Drone w;
    w.show();
    return a.exec();
}























//#include <QApplication>
//#include <QPushButton>
//#include <QPropertyAnimation>

//int main(int argc, char *argv[])
//{
//    QApplication app(argc, argv);

//    QPushButton button("Move me!");
//    button.show();

//    // 애니메이션을 적용할 위젯과 속성을 선택합니다.
//    QPropertyAnimation *animation = new QPropertyAnimation(&button, "pos");

//    // 시작 위치, 끝 위치, 애니메이션의 지속 시간(ms)을 설정합니다.
//    animation->setStartValue(QPoint(140, 320));
//    animation->setEndValue(QPoint(140, 100));
//    animation->setDuration(1000);

//    // 애니메이션을 실행합니다.
//    animation->start();

//    return app.exec();
//}
