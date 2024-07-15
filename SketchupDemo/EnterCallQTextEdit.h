#pragma once

#include <QTextEdit>

class EnterCallQTextEdit  : public QTextEdit
{
	Q_OBJECT

public:
	EnterCallQTextEdit(QWidget *parent);
	~EnterCallQTextEdit();

signals:
	void returnEnterPressed();  // �����źŲ� ���� �����ÿؼ��������ؼ����н���

protected:
	void keyPressEvent(QKeyEvent* event) override;
};
