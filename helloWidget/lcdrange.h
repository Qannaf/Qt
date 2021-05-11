
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
