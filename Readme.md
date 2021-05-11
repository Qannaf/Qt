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
#include <qapplication.h>
#include <qpushbutton.h>


int main( int argc, char **argv )
{
    QApplication a( argc, argv );
    QPushButton hello( "Hello world!", 0 );
    hello.resize( 100, 30 );
    a.setActiveWindow(&hello);
    hello.show();
    return a.exec();
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
#include <qapplication.h>
#include <qpushbutton.h>
#

int main( int argc, char **argv )
{
    QApplication a( argc, argv );
    QPushButton *hello (new QPushButton( "Hello world!"));
    hello->resize( 100, 30 );
    a.setActiveWindow(hello);
    hello->show();
    return a.exec();
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
#include <qapplication.h>
#include <qpushbutton.h>
#include <qfont.h>


int main( int argc, char **argv )
{
    QApplication a( argc, argv );
    QPushButton quit( "Quit", 0 );
    quit.resize( 75, 30 );
    quit.setFont( QFont( "Times", 18, QFont::Bold ) );
    QObject::connect( &quit, SIGNAL(clicked()), &a, SLOT(quit()) );
    a.setActiveWindow( &quit );
    quit.show();
    return a.exec();
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

#include <qapplication.h>
#include <qpushbutton.h>
#include <qfont.h>
#include <QVBoxLayout>

int main( int argc, char **argv )
{
    QApplication a( argc, argv );
    QWidget box;
    box.resize( 200, 120 );
    QPushButton quit( "Quit", &box );
    quit.setFont( QFont( "Times", 18, QFont::Bold ) );
    QObject::connect( &quit, SIGNAL(clicked()), &a, SLOT(quit()) );
    a.setActiveWindow( &box );
    box.show();
    return a.exec();
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
#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QWidget>

// Prototype of class
class MyWidget : public QWidget
{
public:
    MyWidget(QWidget *parent = 0);
};


MyWidget::MyWidget(QWidget *parent )
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
    QApplication a(argc, argv);
    MyWidget widget;
    widget.setGeometry( 100, 100, 200, 120 );
    a.setActiveWindow( &widget );
    widget.show();
    return a.exec();
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