#ifndef FIRST_VIEW_H
#define FIRST_VIEW_H

#include <QMainWindow>
#include<QApplication>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QScrollArea>
#include <QGraphicsPixmapItem>
#include"QMovie"
#include <QCoreApplication>
#include <chatwindow.h>
#include "gamewindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void paintEvent(QPaintEvent *event);//背景图片

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void onSendButtonClicked();//聊天按钮响应函数
    void onGameButtonClicked();//游戏按钮响应函数


private:
    Ui::MainWindow * firstview;

    QLabel* dictionaryImageLabel;//虚拟形象图片
    QLabel* exampleLabel;//上方各部分介绍标签题目
    QLabel* abilityLabel;
    QLabel* limitLabel;
    QPushButton* exampleButton1;//上方各部分介绍
    QPushButton* exampleButton2;
    QPushButton* exampleButton3;
    QPushButton* abilityButton1;
    QPushButton* abilityButton2;
    QPushButton* abilityButton3;
    QPushButton* limitButton1;
    QPushButton* limitButton2;
    QPushButton* limitButton3;
    QLabel* speakLable;
};

QT_BEGIN_NAMESPACE
namespace Ui { class first_view; }
QT_END_NAMESPACE


#endif // FIRST_VIEW_H
