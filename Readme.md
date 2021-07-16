<p align="center">
  <img width="197" height="197" src="images/qt.png">
</p>

# Qt Tutorial
## 1: Hello, World!
  * With out pointer
```cpp
/****************************************************************
**
** Qt tutorial 1
**
****************************************************************/
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPushButton hello("Hello world!");
    hello.resize(100, 30);

    hello.show();
    return app.exec();
}
```
![alt text](images/1.PNG?raw=true "sortie de code")

 * With pointer
 ```cpp
 /****************************************************************
**
** Qt tutorial 1.b
**
****************************************************************/
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPushButton *hello (new QPushButton( "Hello world!"));
    hello->resize(100, 30);

    hello->show();
    return app.exec();
}
```
![alt text](images/1.PNG?raw=true "sortie de code")

## 2: Calling it Quits
```cpp
/****************************************************************
**
** Qt tutorial 2
**
****************************************************************/
#include <QApplication>
#include <QFont>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPushButton quit("Quit");
    quit.resize(75, 30);
    quit.setFont(QFont("Times", 18, QFont::Bold));

    QObject::connect(&quit, SIGNAL(clicked()), &app, SLOT(quit()));

    quit.show();
    return app.exec();
}
```
![alt text](images/2.PNG?raw=true "sortie de code")

## 3: Family Values
```cpp
/****************************************************************
**
** Qt tutorial 3
**
****************************************************************/
#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.resize(200, 120);

    QPushButton quit("Quit", &window);
    quit.setFont(QFont("Times", 18, QFont::Bold));
    quit.setGeometry(10, 40, 180, 40);
    QObject::connect(&quit, SIGNAL(clicked()), &app, SLOT(quit()));

    window.show();
    return app.exec();
}
```
![alt text](images/3.PNG?raw=true "sortie de code")


## 4: Let There Be Widgets
```cpp
/****************************************************************
**
** Qt tutorial 4
**
****************************************************************/

 #include <QApplication>
 #include <QFont>
 #include <QPushButton>
 #include <QWidget>

 class MyWidget : public QWidget
 {
 public:
     MyWidget(QWidget *parent = 0);
 };

 MyWidget::MyWidget(QWidget *parent)
     : QWidget(parent)
 {
     setFixedSize(200, 120);

     QPushButton *quit = new QPushButton(tr("Quit"), this);
     quit->setGeometry(62, 40, 75, 30);
     quit->setFont(QFont("Times", 18, QFont::Bold));

     connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
 }

 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     MyWidget widget;
     widget.show();
     return app.exec();
 }
```
![alt text](images/4.PNG?raw=true "sortie de code")


## 5: Building Blocks
```cpp
/****************************************************************
**
** Qt tutorial 5
**
****************************************************************/

#include <QApplication>
#include <QFont>
#include <QLCDNumber>
#include <QPushButton>
#include <QSlider>
#include <QVBoxLayout>
#include <QWidget>

// Prototype of class
class MyWidget : public QWidget
{
public:
    MyWidget(QWidget *parent = 0);
};

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *quit = new QPushButton(tr("Quit"));
    quit->setFont(QFont("Times", 18, QFont::Bold));

    QLCDNumber *lcd = new QLCDNumber(2);
    lcd->setSegmentStyle(QLCDNumber::Filled);

    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 99);
    slider->setValue(0);

    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(slider, SIGNAL(valueChanged(int)),
            lcd, SLOT(display(int)));

    QVBoxLayout *layout(new QVBoxLayout);
    layout->addWidget(quit);
    layout->addWidget(lcd);
    layout->addWidget(slider);
    setLayout(layout);
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MyWidget widget;
    widget.show();
    return app.exec();
}
```
![alt text](images/5.PNG?raw=true "sortie de code")


## 6 - Building Blocks Galore!
```cpp
/****************************************************************
**
** Qt tutorial 6
**
****************************************************************/

#include <QApplication>
 #include <QFont>
 #include <QGridLayout>
 #include <QLCDNumber>
 #include <QPushButton>
 #include <QSlider>
 #include <QVBoxLayout>
 #include <QWidget>

 class LCDRange : public QWidget
 {
 public:
     LCDRange(QWidget *parent = 0);
 };

 LCDRange::LCDRange(QWidget *parent)
     : QWidget(parent)
 {
     QLCDNumber *lcd = new QLCDNumber(2);
     lcd->setSegmentStyle(QLCDNumber::Filled);

     QSlider *slider = new QSlider(Qt::Horizontal);
     slider->setRange(0, 99);
     slider->setValue(0);
     connect(slider, SIGNAL(valueChanged(int)),
             lcd, SLOT(display(int)));

     QVBoxLayout *layout = new QVBoxLayout;
     layout->addWidget(lcd);
     layout->addWidget(slider);
     setLayout(layout);
 }

 class MyWidget : public QWidget
 {
 public:
     MyWidget(QWidget *parent = 0);
 };

 MyWidget::MyWidget(QWidget *parent)
     : QWidget(parent)
 {
     QPushButton *quit = new QPushButton(tr("Quit"));
     quit->setFont(QFont("Times", 18, QFont::Bold));
     connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

     QGridLayout *grid = new QGridLayout;
     for (int row = 0; row < 3; ++row) {
         for (int column = 0; column < 3; ++column) {
             LCDRange *lcdRange = new LCDRange;
             grid->addWidget(lcdRange, row, column);
         }
     }

     QVBoxLayout *layout = new QVBoxLayout;
     layout->addWidget(quit);
     layout->addLayout(grid);
     setLayout(layout);
 }

 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     MyWidget widget;
     widget.show();
     return app.exec();
 }

 ```
![alt text](images/6.PNG?raw=true "sortie de code")



## 7 - One Thing Leads to Another
  * lcdrange.h
```cpp
/****************************************************************
**
** Qt tutorial 7  lcdrange.h
**
****************************************************************/
#ifndef LCDRANGE_H
#define LCDRANGE_H

#include <QWidget>
#include <QLCDNumber>
#include <QSlider>
#include <QVBoxLayout>


class LCDRange : public QWidget
{
    Q_OBJECT

public:
    LCDRange(QWidget *parent = 0);

    int value() const;

public slots:
    void setValue(int value);
    void setRange(int minValue, int maxValue);

signals:
    void valueChanged(int newValue);

private:
    QSlider *slider;
};

#endif
```

* lcdrange.cpp
```cpp
/****************************************************************
**
** Qt tutorial 7  lcdrange.cpp
**
****************************************************************/
#include "lcdrange.h"

 LCDRange::LCDRange(QWidget *parent)
     : QWidget(parent)
 {
     QLCDNumber *lcd = new QLCDNumber(2);
     lcd->setSegmentStyle(QLCDNumber::Filled);

     slider = new QSlider(Qt::Horizontal);
     slider->setRange(0, 99);
     slider->setValue(0);

     connect(slider, SIGNAL(valueChanged(int)),
             lcd, SLOT(display(int)));
     connect(slider, SIGNAL(valueChanged(int)),
             this, SIGNAL(valueChanged(int)));

     QVBoxLayout *layout = new QVBoxLayout;
     layout->addWidget(lcd);
     layout->addWidget(slider);
     setLayout(layout);

     setFocusProxy(slider);
 }

 int LCDRange::value() const
 {
     return slider->value();
 }

 void LCDRange::setValue(int value)
 {
     slider->setValue(value);
 }

 void LCDRange::setRange(int minValue, int maxValue)
 {
     if (minValue < 0 || maxValue > 99 || minValue > maxValue) {
         qWarning("LCDRange::setRange(%d, %d)\n"
                  "\tRange must be 0..99\n"
                  "\tand minValue must not be greater than maxValue",
                  minValue, maxValue);
         return;
     }
     slider->setRange(minValue, maxValue);
 }


```
* main.cpp
```cpp
/****************************************************************
**
** Qt tutorial 7  lcdrange.h  lcdrange.cpp main.cpp
**
****************************************************************/
#include <QApplication>
#include <QFont>
#include <QGridLayout>
#include <QPushButton>
#include <QWidget>

#include "lcdrange.h"

class MyWidget : public QWidget
{
public:
    MyWidget(QWidget *parent = 0);
};

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *quit = new QPushButton(tr("Quit"));
    quit->setFont(QFont("Times", 18, QFont::Bold));

    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    QGridLayout *grid = new QGridLayout;
    LCDRange *previousRange = 0;

    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            LCDRange *lcdRange = new LCDRange;
            grid->addWidget(lcdRange, row, column);
            if (previousRange)
                connect(lcdRange, SIGNAL(valueChanged(int)),
                        previousRange, SLOT(setValue(int)));
            previousRange = lcdRange;
        }
    }
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(quit);
    layout->addLayout(grid);
    setLayout(layout);
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MyWidget widget;
    widget.show();
    return app.exec();
}
```
![alt text](images/6.PNG?raw=true "sortie de code")


## 8 - Preparing for Battle
 * cannonfield.h
 ```cpp
 /****************************************************************
**
** Qt tutorial 8  cannonfield.h
**
****************************************************************/
#ifndef CANNONFIELD_H
 #define CANNONFIELD_H

 #include <QWidget>
 #include <QPainter>
 class CannonField : public QWidget
 {
     Q_OBJECT

 public:
     CannonField(QWidget *parent = 0);

     int angle() const { return currentAngle; }

 public slots:
     void setAngle(int angle);

 signals:
     void angleChanged(int newAngle);

 protected:
     void paintEvent(QPaintEvent *event);

 private:
     int currentAngle;
 };

 #endif
```
 * cannonfield.cpp
```cpp

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
 }

```
 
 * Main.cpp
```cpp

/****************************************************************
**
** Qt tutorial 8  main.cpp 
**
****************************************************************/
#include <QApplication>
#include <QFont>
#include <QGridLayout>
#include <QPushButton>

#include "cannonfield.h"
#include "lcdrange.h"

class MyWidget : public QWidget
{
public:
    MyWidget(QWidget *parent = 0);
};

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *quit = new QPushButton(tr("Quit"));
    quit->setFont(QFont("Times", 18, QFont::Bold));

    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    LCDRange *angle = new LCDRange;
    angle->setRange(5, 70);

    CannonField *cannonField = new CannonField;

    connect(angle, SIGNAL(valueChanged(int)),
            cannonField, SLOT(setAngle(int)));
    connect(cannonField, SIGNAL(angleChanged(int)),
            angle, SLOT(setValue(int)));

    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(quit, 0, 0);
    gridLayout->addWidget(angle, 1, 0);
    gridLayout->addWidget(cannonField, 1, 1, 2, 1);
    gridLayout->setColumnStretch(1, 10);
    setLayout(gridLayout);

    angle->setValue(60);
    angle->setFocus();
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MyWidget widget;
    widget.setGeometry(100, 100, 500, 355);
    widget.show();
    return app.exec();
}
```
![alt text](images/8.PNG?raw=true "sortie de code")
![alt text](images/tutorial8-layout.png?raw=true "sortie de code")



## 9 - With Cannon You Can
modified function paintEvent in cannonfield.cpp
``` cpp
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
```
![alt text](images/9.PNG?raw=true "sortie de code")




## 10
 * cannonfield.h
 ``` cpp
/****************************************************************
**
** Qt tutorial 10  cannonfield.h
**
****************************************************************/
 #ifndef CANNONFIELD_H
 #define CANNONFIELD_H

 #include <QWidget>
 #include <QPaintEvent>
 #include <QPainter>

 class CannonField : public QWidget
 {
     Q_OBJECT

 public:
     CannonField(QWidget *parent = 0);

     int angle() const { return currentAngle; }
     int force() const { return currentForce; }

 public slots:
     void setAngle(int angle);
     void setForce(int force);

 signals:
     void angleChanged(int newAngle);
     void forceChanged(int newForce);

 protected:
     void paintEvent(QPaintEvent *event);

 private:
     QRect cannonRect() const;

     int currentAngle;
     int currentForce;
 };

 #endif
 ```
 * cannonfield.cpp
 ``` cpp
/****************************************************************
**
** Qt tutorial 10  cannonfield.cpp
**
****************************************************************/


 #include "cannonfield.h"

 CannonField::CannonField(QWidget *parent)
     : QWidget(parent)
 {
     currentAngle = 45;
     currentForce = 0;
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
     update(cannonRect());
     emit angleChanged(currentAngle);
 }

 void CannonField::setForce(int force)
 {
     if (force < 0)
         force = 0;
     if (currentForce == force)
         return;
     currentForce = force;
     emit forceChanged(currentForce);
 }

 void CannonField::paintEvent(QPaintEvent * /* event */)
 {
     QPainter painter(this);

     painter.setPen(Qt::NoPen);
     painter.setBrush(Qt::blue);

     painter.translate(0, height());
     painter.drawPie(QRect(-35, -35, 70, 70), 0, 90 * 16);
     painter.rotate(-currentAngle);
     painter.drawRect(QRect(30, -5, 20, 10));
 }

 QRect CannonField::cannonRect() const
 {
     QRect result(0, 0, 50, 50);
     result.moveBottomLeft(rect().bottomLeft());
     return result;
 }
 ```
 * Main.cpp
 ```cpp
 /****************************************************************
**
** Qt tutorial 10
**
****************************************************************/
#include <QApplication>
 #include <QFont>
 #include <QGridLayout>
 #include <QPushButton>
 #include <QVBoxLayout>

 #include "cannonfield.h"
 #include "lcdrange.h"

 class MyWidget : public QWidget
 {
 public:
     MyWidget(QWidget *parent = 0);
 };

 MyWidget::MyWidget(QWidget *parent)
     : QWidget(parent)
 {
     QPushButton *quit = new QPushButton(tr("&Quit"));
     quit->setFont(QFont("Times", 18, QFont::Bold));

     connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

     LCDRange *angle = new LCDRange;
     angle->setRange(5, 70);

     LCDRange *force = new LCDRange;
     force->setRange(10, 50);

     CannonField *cannonField = new CannonField;

     connect(angle, SIGNAL(valueChanged(int)),
             cannonField, SLOT(setAngle(int)));
     connect(cannonField, SIGNAL(angleChanged(int)),
             angle, SLOT(setValue(int)));

     connect(force, SIGNAL(valueChanged(int)),
             cannonField, SLOT(setForce(int)));
     connect(cannonField, SIGNAL(forceChanged(int)),
             force, SLOT(setValue(int)));

     QVBoxLayout *leftLayout = new QVBoxLayout;
     leftLayout->addWidget(angle);
     leftLayout->addWidget(force);

     QGridLayout *gridLayout = new QGridLayout;
     gridLayout->addWidget(quit, 0, 0);
     gridLayout->addLayout(leftLayout, 1, 0);
     gridLayout->addWidget(cannonField, 1, 1, 2, 1);
     gridLayout->setColumnStretch(1, 10);
     setLayout(gridLayout);

     angle->setValue(60);
     force->setValue(25);
     angle->setFocus();
 }

 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     MyWidget widget;
     widget.setGeometry(100, 100, 500, 355);
     widget.show();
     return app.exec();
 }

 ```
![alt text](images/10.PNG?raw=true "sortie de code")

## 11 - Giving It a Shot
![alt text](images/11.PNG?raw=true "sortie de code")

##12 - Facing the Wall
Look helloWidget folder

![alt text](images/f.PNG?raw=true "sortie de code")



For more of Qt5 tutorial visit this website
 http://zetcode.com/gui/qt5/




