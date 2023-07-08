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
#include <QCoreApplication>
#include <QtNetwork>
#include <QtNetwork/qnetworkaccessmanager.h>
#include <QtNetwork/qnetworkrequest.h>
#include <QtNetwork/qnetworkreply.h>
#include <QURL>
#include <QFile>
#include <QRegExp>
#include <QDebug>
#include "chatbutton.h"
#include "get_ans.h"

class ChatWindow : public QDialog {
public:
    ChatWindow(QWidget* parent = nullptr);//界面初始化

private slots:
    void addChatBubble();//向聊天区域加入气泡

private:
    QGridLayout* bubbleLayout_;//建立布局
};

#endif // CHATWINDOW_H
