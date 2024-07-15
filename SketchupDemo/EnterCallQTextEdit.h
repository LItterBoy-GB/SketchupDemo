#pragma once

#include <QTextEdit>

class EnterCallQTextEdit  : public QTextEdit
{
	Q_OBJECT

public:
	EnterCallQTextEdit(QWidget *parent);
	~EnterCallQTextEdit();

signals:
	void returnEnterPressed();  // 利用信号槽 机制 灵活的让控件与其它控件进行交互

protected:
	void keyPressEvent(QKeyEvent* event) override;
};
