#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QGridLayout>
#include <QLineEdit>
#include <QTimer>
#include <QDialog>
#include "chatbutton.h"

class ChatWindow : public QDialog {
public:
    ChatWindow(QWidget* parent = nullptr) : QDialog(parent) {
        QVBoxLayout* mainLayout = new QVBoxLayout(this);
        setFixedSize(600, 900);

        QPalette pal = palette();
        QPixmap background(":/my_pic/OIP2.jpg"); // Custom background image file path
        pal.setBrush(QPalette::Background, background);
        setPalette(pal);

        QScrollArea* scrollArea = new QScrollArea();
        QWidget* scrollContent = new QWidget();
        QVBoxLayout* scrollLayout = new QVBoxLayout(scrollContent);
        scrollLayout->setAlignment(Qt::AlignTop);
        scrollArea->setWidget(scrollContent);
        scrollArea->setWidgetResizable(true);
        mainLayout->addWidget(scrollArea);

        QWidget* chatContainer = new QWidget();
        QGridLayout* chatLayout = new QGridLayout(chatContainer);
        chatLayout->setAlignment(Qt::AlignTop);
        chatLayout->setHorizontalSpacing(20);
        chatLayout->setVerticalSpacing(10);
        chatLayout->setColumnStretch(0, 1);
        chatLayout->setColumnStretch(1, 1);
        scrollLayout->addWidget(chatContainer);

        bubbleLayout_ = chatLayout; // Save the layout for adding chat bubbles later

        QLineEdit* inputLineEdit = new QLineEdit();
        mainLayout->addWidget(inputLineEdit);

        connect(inputLineEdit, &QLineEdit::returnPressed, this, &ChatWindow::addChatBubble);
    }

private slots:
    void addChatBubble() {
        static int col_num = 1;


        QLineEdit* inputLineEdit = qobject_cast<QLineEdit*>(sender());
        if (inputLineEdit) {
            col_num += 2;
            QString text = inputLineEdit->text();
            if (!text.isEmpty()) {
                ChatBubble* newBubble = new ChatBubble(text, true, ":/my_pic/tmppic2.jpg");
                bubbleLayout_->addWidget(newBubble, col_num, 0);
                inputLineEdit->clear();
                inputLineEdit->setFocus();

                QTimer::singleShot(500, this, [this]() {
                    ChatBubble* newBubble1 = new ChatBubble("Hi，这是接收者的消息", false, ":/my_pic/tmppic.png");
                    bubbleLayout_->addWidget(newBubble1, col_num + 1, 1);
                });


            }
        }
    }

private:
    QGridLayout* bubbleLayout_;
};

#endif // CHATWINDOW_H
