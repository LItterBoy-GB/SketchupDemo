#pragma once

#include <QDialog>
#include <Qlayout>
#include "ui_RubyConsole.h"
#include "EnterCallQTextEdit.h"
#include "RubyInterpreter.h"

class RubyConsole : public QDialog
{
	Q_OBJECT

public:
	RubyConsole(QWidget *parent = nullptr);
	~RubyConsole();

private:
	Ui::RubyConsoleClass ui;
	RubyInterpreter ruby_interperter;

private slots:  // 对应方法需要声明  slots
	void ExecuteRubyStr();
};
