#include "EnterCallQTextEdit.h"
#include<QKeyEvent>

EnterCallQTextEdit::EnterCallQTextEdit(QWidget *parent)
	: QTextEdit(parent)
{
    //setPlaceholderText("SHIFT+ENTER ·¢ËÍÊý¾Ý");
}

EnterCallQTextEdit::~EnterCallQTextEdit()
{}

void EnterCallQTextEdit::keyPressEvent(QKeyEvent * event)
{
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
        if (event->modifiers() & Qt::ShiftModifier) {
            // Enter: Clear the text
            emit returnEnterPressed();
            this->clear();
        }
        else {
            // Shift+Enter: Insert a newline
            QTextEdit::keyPressEvent(event);
        }
    }
    else {
        // Handle other key events
        QTextEdit::keyPressEvent(event);
    }
}
