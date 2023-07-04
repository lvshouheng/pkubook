#include "widget.h"
#include "config.h"
#include "ui_widget.h"
#include <QIcon>
#include <QApplication>
#include <QtWidgets>
#include <QTimer>
#include "chatbutton.h"

static int col_num=1;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 创建主窗口
    QWidget *mainWindow=new QWidget(this);
    QVBoxLayout* mainLayout = new QVBoxLayout(mainWindow);
    mainWindow->resize(600, 900);


    // 设置窗口背景图片
    QPalette pal = mainWindow->palette();
    QPixmap background(":/my_pic/OIP2.jpg"); // 自定义的背景图片文件路径
    pal.setBrush(QPalette::Background, background);
    mainWindow->setPalette(pal);

    // 创建滚动区域
    QScrollArea* scrollArea = new QScrollArea();
    QWidget* scrollContent = new QWidget();
    QVBoxLayout* scrollLayout = new QVBoxLayout(scrollContent);
    scrollLayout->setAlignment(Qt::AlignTop);
    scrollArea->setWidget(scrollContent);
    scrollArea->setWidgetResizable(true);

//    // 设置滚动区域的背景颜色
//    scrollContent->setStyleSheet("background-color: #FFFFFF;"); // 替换为需要的颜色

    // 将滚动区域添加到主窗口中
    mainLayout->addWidget(scrollArea);

    // 创建聊天气泡
    QWidget* chatContainer = new QWidget();
    QGridLayout* chatLayout = new QGridLayout(chatContainer);
    chatLayout->setAlignment(Qt::AlignTop);
    chatLayout->setHorizontalSpacing(20); // 设置气泡之间的水平间距为20像素
    chatLayout->setVerticalSpacing(10); // 设置气泡之间的垂直间距为10像素
    chatLayout->setColumnStretch(0, 1);
    chatLayout->setColumnStretch(1, 1);
    scrollLayout->addWidget(chatContainer);

    // 添加聊天气泡
    ChatBubble* bubble1 = new ChatBubble("你好，这是发送者的消息", true,":/my_pic/tmppic2.jpg");
    ChatBubble* bubble2 = new ChatBubble("Hi，这是接收者的消息", false,":/my_pic/tmppic.png");
    ChatBubble* bubble3 = new ChatBubble("很高兴见到你", true,":/my_pic/tmppic2.jpg");
    chatLayout->addWidget(bubble1,0,0);
    chatLayout->addWidget(bubble2,1,1);
    chatLayout->addWidget(bubble3,2,0);

    // 创建文本输入框
    QLineEdit* inputLineEdit = new QLineEdit();
    mainLayout->addWidget(inputLineEdit);


    // 监听文本输入框的文本变化，创建并添加新的聊天气泡
    QObject::connect(inputLineEdit, &QLineEdit::returnPressed, [&chatLayout,&inputLineEdit]() {
        col_num+=2;
        QString text = inputLineEdit->text();
        if (!text.isEmpty()) {
            ChatBubble* newBubble = new ChatBubble(text, true,":/my_pic/tmppic2.jpg");
            chatLayout->addWidget(newBubble,col_num,0);
            inputLineEdit->clear();
            inputLineEdit->setFocus();
//            ChatBubble* newBubble1 = new ChatBubble("Hi，这是接收者的消息", false,":/my_pic/tmppic.png");
//            chatLayout->addWidget(newBubble1,col_num+1,1);
            QTimer* timer=new QTimer();
            timer->setInterval(500); // 设置延时时间
            timer->setSingleShot(true); // 设置为单次触发，即只触发一次


            QObject::connect(timer, &QTimer::timeout, [&chatLayout]() {
                // 这里是后续操作的代码，会在延时结束后执行
                // 可以在这里添加你想要的操作
                 ChatBubble* newBubble1 = new ChatBubble("Hi，这是接收者的消息", false,":/my_pic/tmppic.png");
                 chatLayout->addWidget(newBubble1,col_num+1,1);

            });
            timer->start();
        }
    });
}

Widget::~Widget()
{
    delete ui;
}

//void Widget::initScene()
//{
//    setFixedSize(GAME_WIDTH,GAME_HIGH);
//    setWindowTitle(GAME_TITLE);
//    setWindowIcon(QIcon(":/my_pic/tmppic.png"));
//}
