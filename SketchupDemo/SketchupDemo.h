#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SketchupDemo.h"

class SketchupDemo : public QMainWindow
{
    Q_OBJECT

public:
    SketchupDemo(QWidget *parent = nullptr);
    ~SketchupDemo();

private:
    Ui::SketchupDemoClass ui;
};
