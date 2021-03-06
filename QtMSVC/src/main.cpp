/****************************************************************
**
** Qt tutorial 1.a
**
****************************************************************/
/*
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QPushButton Button_hello("Hello world!");

    Button_hello.resize(100, 30);
    Button_hello.show();

    return app.exec();
}
//*/

/****************************************************************
**
** Qt tutorial 1.b
**
****************************************************************/
/*
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QPushButton * Button_hello(new QPushButton( "Hello world!"));
    
    Button_hello->resize(100, 30);
    Button_hello->show();
    
    return app.exec();
}
//*/


/****************************************************************
**
** Qt tutorial 2
**
****************************************************************/
/*
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

    //QPushButton* quit = new QPushButton("Quit");QObject::connect(quit, SIGNAL(clicked()), &app, SLOT(quit()));quit->show();

    return app.exec();
}
//*/

/****************************************************************
**
** Qt tutorial 3
**
****************************************************************/
/*
#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QWidget>
int main(int argc, char *argv[])
{
    int largeur(200), heuteur(120);
    QApplication app(argc, argv);
    QWidget window;
    window.resize(largeur, heuteur);

    QPushButton quit("Quit", &window);
    //quit.resize(75, 30);
    quit.setFont(QFont("Times", 18, QFont::Bold));
    quit.setGeometry(largeur-70, heuteur-40, 70, 40);
    QObject::connect(&quit, SIGNAL(clicked()), &app, SLOT(quit()));

    window.show();
    return app.exec();
}
//*/
/****************************************************************
**
** Qt tutorial 4
**
****************************************************************/
/*
#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QWidget>

class MyWidget : public QWidget
{
public:
    MyWidget( const int& _largeur = 200, const int& _heuteur = 120, QWidget* window_parent = 0);
private:
    int largeur, heuteur;
};

MyWidget::MyWidget( const int& _largeur , const int& _heuteur, QWidget* window_parent)
    : largeur(_largeur), heuteur(_heuteur), QWidget(window_parent)
{
    setFixedSize(largeur, heuteur);

    QPushButton *quit = new QPushButton(tr("Quit"), this);
    quit->setGeometry(largeur -75, heuteur -30, 75, 30);
    quit->setFont(QFont("Times", 18, QFont::Bold));

    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MyWidget widget(200,100);
    widget.show();
    return app.exec();
}//*/



/****************************************************************
**
** Qt tutorial 5
**
****************************************************************/
/*
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

MyWidget::MyWidget(QWidget *parent): QWidget(parent)
{
    QPushButton *quit = new QPushButton(tr("Quit"),this);
    quit->setFont(QFont("Times", 18, QFont::Bold));

    QLCDNumber *lcd = new QLCDNumber(2,this);
    lcd->setSegmentStyle(QLCDNumber::Filled);

    QSlider *slider = new QSlider(Qt::Horizontal,this);
    slider->setRange(0, 99);
    slider->setValue(0);

    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(slider, SIGNAL(valueChanged(int)),lcd, SLOT(display(int)));

    QVBoxLayout* layout(new QVBoxLayout);
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
//*/


/****************************************************************
**
** Qt tutorial 6
**
****************************************************************/
/*
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
 //*/

/****************************************************************
**
** Qt tutorial 7  lcdrange.h  lcdrange.cpp main.cpp
**
****************************************************************/
/*
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

//*/

/****************************************************************
**
** Qt tutorial 8  lcdrange8.h  lcdrange8.cpp cannonfield.h cannonfield.cpp main.cpp
**
****************************************************************/
/*
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
//*/



/****************************************************************
**
** Qt tutorial 10
**
****************************************************************/

/*
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
 //*/


/****************************************************************
**
** Qt tutorial 11
**
****************************************************************/
/*
#include <QApplication>
 #include <QFont>
 #include <QGridLayout>
 #include <QHBoxLayout>
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

     QPushButton *shoot = new QPushButton(tr("&Shoot"));
     shoot->setFont(QFont("Times", 18, QFont::Bold));

     connect(shoot, SIGNAL(clicked()), cannonField, SLOT(shoot()));

     QHBoxLayout *topLayout = new QHBoxLayout;
     topLayout->addWidget(shoot);
     topLayout->addStretch(1);

     QVBoxLayout *leftLayout = new QVBoxLayout;
     leftLayout->addWidget(angle);
     leftLayout->addWidget(force);

     QGridLayout *gridLayout = new QGridLayout;
     gridLayout->addWidget(quit, 0, 0);
     gridLayout->addLayout(topLayout, 0, 1);
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


 //*/

/****************************************************************
**
** Qt tutorial 12
**
****************************************************************/

#include <QApplication>

 #include "gameboard.h"

 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     GameBoard board;
     board.setGeometry(100, 100, 500, 355);
     board.show();
     return app.exec();
 } //*/


