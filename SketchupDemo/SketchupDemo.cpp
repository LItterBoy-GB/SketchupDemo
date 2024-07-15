#include "SketchupDemo.h"

SketchupDemo::SketchupDemo(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    connect(ui.actionRuby, &QAction::triggered, this, &SketchupDemo::onShowConsole);
}

SketchupDemo::~SketchupDemo()
{
}

void SketchupDemo::onShowConsole()
{
    ruby_console.show();
}
