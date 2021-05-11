<p align="center">
  <img width="197" height="197" src="images/qt.png">
</p>

# Qt Tutorial
## 1: Hello, World!
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