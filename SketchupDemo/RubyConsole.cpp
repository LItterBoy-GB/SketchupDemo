#include "RubyConsole.h"

RubyConsole::RubyConsole(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	// 将 textEdit 添加到布局中
	//this->layout()->replaceWidget(ui.inputText, textEdit);
	//ui.inputText->layout()->addWidget(textEdit);
	connect(ui.inputText, &EnterCallQTextEdit::returnEnterPressed, this, &RubyConsole::ExecuteRubyStr);
}

RubyConsole::~RubyConsole()
{}

void RubyConsole::ExecuteRubyStr()
{
	QString str = ui.inputText->toPlainText();
	//RubyResult ruby_res = ruby_interperter.EvalString(str.toStdString());
	QString res(str);
	/*res.append("\n");
	if (ruby_res.m_state)
		res.append("=>");
	res.append(QString(ruby_res.ToString().c_str()));*/
	ui.resultText->setPlainText(res);
}
