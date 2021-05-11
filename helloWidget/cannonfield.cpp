
/****************************************************************
**
** Qt tutorial 8  cannonfield.cpp
**
****************************************************************/
 #include "cannonfield.h"

 CannonField::CannonField(QWidget *parent)
     : QWidget(parent)
 {
     currentAngle = 45;
     setPalette(QPalette(QColor(250, 250, 200)));
     setAutoFillBackground(true);
 }

 void CannonField::setAngle(int angle)
 {
     if (angle < 5)
         angle = 5;
     if (angle > 70)
         angle = 70;
     if (currentAngle == angle)
         return;
     currentAngle = angle;
     update();
     emit angleChanged(currentAngle);
 }

 void CannonField::paintEvent(QPaintEvent * /* event */)
 {
     QPainter painter(this);
     painter.drawText(200, 200,
                      tr("Angle = ") + QString::number(currentAngle));


     // tuto 9
     painter.setPen(Qt::NoPen);
     painter.setBrush(Qt::blue);

     painter.translate(0, rect().height());
     painter.drawPie(QRect(-35, -35, 70, 70), 0, 90 * 16);
     painter.rotate(-currentAngle);
     painter.drawRect(QRect(30, -5, 20, 10));
 }



