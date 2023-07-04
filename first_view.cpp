// first_view.cpp

#include "first_view.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QGridLayout* mainLayout = new QGridLayout(centralWidget);

    dictionaryImageLabel = new QLabel(this);
    dictionaryImageLabel->setScaledContents(true);
    QPixmap dictionaryImage("C:\\Users\\Lenovo\\Desktop\\tmp\\tmppic.png");
    //QPixmap scaledImage = dictionaryImage.scaled(dictionaryImageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    //dictionaryImageLabel->setPixmap(scaledImage);
    //dictionaryImageLabel->setAlignment(Qt::AlignCenter);
    dictionaryImageLabel->setPixmap(dictionaryImage);
    dictionaryImageLabel->setFixedSize(210, 280);
    speakimage=new QLabel(this);
    speakimage->setScaledContents(true);
    QPixmap speakimagetmp("C:\\Users\\Lenovo\\Desktop\\tmp\\R.png");
    speakimage->setPixmap(speakimagetmp);
    speakimage->setFixedSize(150,120);
    //虚拟形象图片显示初始化

    exampleLabel = new QLabel("EXAMPLE", this);
    exampleLabel->setStyleSheet("font-weight: bold; font-size: 20px;");
    exampleLabel->setAlignment(Qt::AlignCenter);

    abilityLabel = new QLabel("ABILITY", this);
    abilityLabel->setStyleSheet("font-weight: bold; font-size: 20px;");
    abilityLabel->setAlignment(Qt::AlignCenter);

    limitLabel = new QLabel("LIMITATION", this);
    limitLabel->setStyleSheet("font-weight: bold; font-size: 20px;");
    limitLabel->setAlignment(Qt::AlignCenter);

    exampleButton1 = new QPushButton("想了解学业方面？\n试试问问“转专业”", this);
    exampleButton2 = new QPushButton("想了解博雅塔？试试问问\n“博雅塔建立多少年了？”", this);
    exampleButton3 = new QPushButton("想了解假期去哪玩？试试问问\n“北大周边有哪些好玩的地方？”", this);

    abilityButton1 = new QPushButton("提供学业方面支持，如各种课程资料等", this);
    abilityButton2 = new QPushButton("包揽各方美食，让你享受舌尖上的愉悦", this);
    abilityButton3 = new QPushButton("搜寻附近名胜，假期不再无所适从！", this);

    limitButton1 = new QPushButton("数据库内容较局限", this);
    limitButton2 = new QPushButton("尚未能进行联网搜索分析", this);
    limitButton3 = new QPushButton("智能化程度较低", this);

    QVBoxLayout* exampleLayout = new QVBoxLayout();
    QVBoxLayout* abilityLayout = new QVBoxLayout();
    QVBoxLayout* limitLayout = new QVBoxLayout();

    exampleLayout->addWidget(exampleButton1);
    exampleLayout->addWidget(exampleButton2);
    exampleLayout->addWidget(exampleButton3);

    abilityLayout->addWidget(abilityButton1);
    abilityLayout->addWidget(abilityButton2);
    abilityLayout->addWidget(abilityButton3);

    limitLayout->addWidget(limitButton1);
    limitLayout->addWidget(limitButton2);
    limitLayout->addWidget(limitButton3);
    //初始功能选项

    QPushButton* sendButton = new QPushButton("Send", this);
    sendButton->setStyleSheet("background-color: #4CAF50; color: #FFFFFF; font-weight: bold; font-size: 14px; padding: 10px;");
    sendButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    sendButton->setFixedHeight(50);
    connect(sendButton, &QPushButton::clicked, this, &MainWindow::onSendButtonClicked);

    QPushButton* gameButton = new QPushButton("Game", this);
    gameButton->setStyleSheet("background-color: #008CBA; color: #FFFFFF; font-weight: bold; font-size: 14px; padding: 10px;");
    gameButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    gameButton->setFixedHeight(50);
    connect(gameButton, &QPushButton::clicked, this, &MainWindow::onGameButtonClicked);
    //send和game按钮

    QHBoxLayout* inputLayout = new QHBoxLayout();
    inputLayout->addWidget(sendButton);
    inputLayout->addWidget(gameButton);
    //下方操作区

    mainLayout->addWidget(exampleLabel,0,1,1,1);
    mainLayout->addLayout(exampleLayout,1,1);

    mainLayout->addWidget(abilityLabel,0,6,1,1);
    mainLayout->addLayout(abilityLayout,1,6);

    mainLayout->addWidget(limitLabel,0,11,1,1);
    mainLayout->addLayout(limitLayout,1,11);

    mainLayout->addWidget(dictionaryImageLabel,5,0,13,1);
    mainLayout->addWidget(speakimage,5,1,2,7);
    mainLayout->addLayout(inputLayout,17,4,1,13);
    mainLayout->setContentsMargins(10, 10, 10, 10);
    mainLayout->setSpacing(10);
    //进行布局
}

MainWindow::~MainWindow()
{
}

void MainWindow::onSendButtonClicked()
{
    ChatWindow *my_chat = new ChatWindow(this);
    my_chat->show();

//    // 隐藏各标签
//    speakimage->hide();
//    exampleLabel->hide();
//    abilityLabel->hide();
//    limitLabel->hide();
//    exampleButton1->hide();
//    exampleButton2->hide();
//    exampleButton3->hide();
//    abilityButton1->hide();
//    abilityButton2->hide();
//    abilityButton3->hide();
//    limitButton1->hide();
//    limitButton2->hide();
//    limitButton3->hide();
    // 隐藏字典图片标签
    //dictionaryImageLabel->setVisible(false);
}


void MainWindow::onGameButtonClicked()
{
    // 在这里处理点击游戏按钮的逻辑
}
