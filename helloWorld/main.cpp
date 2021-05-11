#include <QCoreApplication>
#include <iostream>
#include "QDebug"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "Hello World!!!" << endl;
    qDebug() << "Hello World!!!"; // Qt way
    return 0;
}
