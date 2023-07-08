// GameDialog.cpp

#include "gamewindow.h"

GameDialog::GameDialog(QWidget* parent) : QDialog(parent) {
    QVBoxLayout* layout = new QVBoxLayout(this);
    setFixedSize(1070 , 700);

    pic_name<<":/my_pic/ximen.jpg"<<":/my_pic/huabiao1.jpg"<<":/my_pic/weiming.jpg"<<":/my_pic/tushu.jpg"<<":/my_pic/tushu.jpg";

    ques_font.setFamily("Arial"); // 设置字体家族
    ques_font.setPointSize(16);  // 设置字体大小
    ques_font.setBold(true);     // 设置字体为粗体

    ans_font.setFamily("Arial"); // 设置字体家族
    ans_font.setPointSize(16);  // 设置字体大小
    ans_font.setBold(true);     // 设置字体为粗体

    pal = palette();
    QPixmap background(pic_name[col_num]);
    pal.setBrush(QPalette::Background, background);//设置背景

    setPalette(pal);
    pku_views << "你是李华，通过自己的努力考上了白鲸大学。今天是你\n报道的第一天，你很喜欢看书，想去号称亚洲藏书最多的北\n大图书馆去借阅几本书看看，但是你在去往图书馆的路上遇\n到了猫猫拦路，只有正确回答猫猫的问题才能前往下一个地点。\n第一个问题：西门别称？"
            << "你成功进入了学校，看到面前有两座高大的华表。请问，\n华表的位置在哪？"
            << "你路过了美丽的未名湖畔，看到前方一座古朴的石塔。\n“哦，这就是博雅塔”。请问博雅塔曾是一座什么塔？"
            << "恭喜你来到了图书馆。\n这时，猫猫又拦住了你：图书馆成立于哪一年？"
            << "成功进入图书馆！你接下来准备干什么呢？";
    option_string<< "A 校友门"
                 << "B 玄武门"
                 << "C 西大门"
                 << "D 燕园门"
                 << "A 办公楼后"
                 << "B 办公楼前"
                 << "C 办公楼侧面"
                 << "D 办公楼内的院子里"
                 << "A 镇妖塔"
                 << "B 修炼塔"
                 << "C 水塔"
                 << "D 佛塔"
                 << "A 1919"
                 << "B 1974"
                 << "C 1985"
                 << "D 1898"
                 << "A 进入图书馆开始学习"
                 << "B 走出图书馆"
                 << "C 进入图书馆摸鱼"
                 << "D 钝角";

    // 创建问题标签
    questionLabel = new QLabel(pku_views[col_num], this);
    questionLabel->setFont(ques_font);
    questionLabel->setFixedHeight(250); // 设置高度为 250 像素
    questionLabel->setStyleSheet("QLabel {"
                            "   border: 1px solid black;" // 设置边框样式
                            "   background-color: white;" // 设置背景色
                            "}");
    layout->addWidget(questionLabel);

    // 创建选项按钮
    optionButton1 = new QPushButton(option_string[col_num*4], this);
    optionButton1->setStyleSheet("QPushButton {"
                             "background-color: #4CAF50;"
                             "border: none;"
                             "color: white;"
                             "padding: 10px 20px;"
                             "text-align: center;"
                             "text-decoration: none;"
                             "display: inline-block;"
                             "font-size: 16px;"
                             "border-radius: 8px;"
                         "}"
                         "QPushButton:hover {"
                             "background-color: #45a049;"
                         "}"
                         "QPushButton:pressed {"
                             "background-color: #367533;"
                         "}");
    optionButton2 = new QPushButton(option_string[col_num*4+1], this);
    optionButton2->setStyleSheet("QPushButton {"
                             "background-color: #4CAF50;"
                             "border: none;"
                             "color: white;"
                             "padding: 10px 20px;"
                             "text-align: center;"
                             "text-decoration: none;"
                             "display: inline-block;"
                             "font-size: 16px;"
                             "border-radius: 8px;"
                         "}"
                         "QPushButton:hover {"
                             "background-color: #45a049;"
                         "}"
                         "QPushButton:pressed {"
                             "background-color: #367533;"
                         "}");
    optionButton3 = new QPushButton(option_string[col_num*4+2], this);
    optionButton3->setStyleSheet("QPushButton {"
                             "background-color: #4CAF50;"
                             "border: none;"
                             "color: white;"
                             "padding: 10px 20px;"
                             "text-align: center;"
                             "text-decoration: none;"
                             "display: inline-block;"
                             "font-size: 16px;"
                             "border-radius: 8px;"
                         "}"
                         "QPushButton:hover {"
                             "background-color: #45a049;"
                         "}"
                         "QPushButton:pressed {"
                             "background-color: #367533;"
                         "}");
    optionButton4 = new QPushButton(option_string[col_num*4+3], this);
    optionButton4->setStyleSheet("QPushButton {"
                             "background-color: #4CAF50;"
                             "border: none;"
                             "color: white;"
                             "padding: 10px 20px;"
                             "text-align: center;"
                             "text-decoration: none;"
                             "display: inline-block;"
                             "font-size: 16px;"
                             "border-radius: 8px;"
                         "}"
                         "QPushButton:hover {"
                             "background-color: #45a049;"
                         "}"
                         "QPushButton:pressed {"
                             "background-color: #367533;"
                         "}");

    layout->addWidget(optionButton1);
    layout->addWidget(optionButton2);
    layout->addWidget(optionButton3);
    layout->addWidget(optionButton4);

    // 连接按钮点击信号到槽函数
    connect(optionButton1, &QPushButton::clicked, this, &GameDialog::optionButtonClicked1);
    connect(optionButton2, &QPushButton::clicked, this, &GameDialog::optionButtonClicked2);
    connect(optionButton3, &QPushButton::clicked, this, &GameDialog::optionButtonClicked3);
    connect(optionButton4, &QPushButton::clicked, this, &GameDialog::optionButtonClicked4);
}

//进行选择及题目跳转
void GameDialog::optionButtonClicked1() {
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    if (clickedButton) {
        QString optionText = clickedButton->text();
        if(col_num==0){
            col_num++;
            // 创建一个消息对话框
            QMessageBox msgBox;
            msgBox.setWindowTitle("提示");
            msgBox.setText("回答正确，即将前往下一地点");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.setDefaultButton(QMessageBox::Ok);

            // 弹出对话框并等待用户确认
            int result = msgBox.exec();
            if (result == QMessageBox::Ok) {
                questionLabel->setText(pku_views[col_num]);
                optionButton1->setText(option_string[col_num*4]);
                optionButton2->setText(option_string[col_num*4+1]);
                optionButton3->setText(option_string[col_num*4+2]);
                optionButton4->setText(option_string[col_num*4+3]);
                QPixmap background(pic_name[col_num]);
                pal.setBrush(QPalette::Background, background);
                setPalette(pal);//设置背景
                    // 用户点击了确认按钮
                    // 执行相应的操作
            }

        }
        else{
            QMessageBox msgBox;
            msgBox.setWindowTitle("提示");
            msgBox.setText("回答错误啦，再好好想想，或者去问问小北");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.setDefaultButton(QMessageBox::Ok);
            // 弹出对话框并等待用户确认
            int result = msgBox.exec();
        }
        // 在这里处理选项按钮的点击事件
        // 根据选项的文本执行相应的逻辑
    }
}
void GameDialog::optionButtonClicked2() {
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    if (clickedButton) {
        QString optionText = clickedButton->text();

        if(col_num==1){
            col_num++;
            // 创建一个消息对话框
            QMessageBox msgBox;
            msgBox.setWindowTitle("提示");
            msgBox.setText("回答正确，即将前往下一地点");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.setDefaultButton(QMessageBox::Ok);

            // 弹出对话框并等待用户确认
            int result = msgBox.exec();
            if (result == QMessageBox::Ok) {
                questionLabel->setText(pku_views[col_num]);
                optionButton1->setText(option_string[col_num*4]);
                optionButton2->setText(option_string[col_num*4+1]);
                optionButton3->setText(option_string[col_num*4+2]);
                optionButton4->setText(option_string[col_num*4+3]);
                QPixmap background(pic_name[col_num]);
                pal.setBrush(QPalette::Background, background);
                setPalette(pal);//设置背景
                    // 用户点击了确认按钮
                    // 执行相应的操作
            }

        }
        else{
            QMessageBox msgBox;
            msgBox.setWindowTitle("提示");
            msgBox.setText("回答错误啦，再好好想想，或者去问问小北");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.setDefaultButton(QMessageBox::Ok);
            // 弹出对话框并等待用户确认
            int result = msgBox.exec();
        }
        // 在这里处理选项按钮的点击事件
        // 根据选项的文本执行相应的逻辑
    }
}
void GameDialog::optionButtonClicked3() {
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    if (clickedButton) {
        QString optionText = clickedButton->text();
        if(col_num==2){
            col_num++;
            // 创建一个消息对话框
            QMessageBox msgBox;
            msgBox.setWindowTitle("提示");
            msgBox.setText("回答正确，即将前往下一地点");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.setDefaultButton(QMessageBox::Ok);

            // 弹出对话框并等待用户确认
            int result = msgBox.exec();
            if (result == QMessageBox::Ok) {
                questionLabel->setText(pku_views[col_num]);
                optionButton1->setText(option_string[col_num*4]);
                optionButton2->setText(option_string[col_num*4+1]);
                optionButton3->setText(option_string[col_num*4+2]);
                optionButton4->setText(option_string[col_num*4+3]);
                QPixmap background(pic_name[col_num]);
                pal.setBrush(QPalette::Background, background);
                setPalette(pal);//设置背景
                    // 用户点击了确认按钮
                    // 执行相应的操作
            }

        }
        else{
            QMessageBox msgBox;
            msgBox.setWindowTitle("提示");
            msgBox.setText("回答错误啦，再好好想想，或者去问问小北");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.setDefaultButton(QMessageBox::Ok);
            // 弹出对话框并等待用户确认
            int result = msgBox.exec();
        }
        // 在这里处理选项按钮的点击事件
        // 根据选项的文本执行相应的逻辑
    }
}
void GameDialog::optionButtonClicked4() {
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    if (clickedButton) {
        QString optionText = clickedButton->text();
        if(col_num>=4){
            QMessageBox msgBox;
            msgBox.setWindowTitle("提示");
            msgBox.setText("恭喜你完成了所有问题！");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.setDefaultButton(QMessageBox::Ok);
            int result = msgBox.exec();
            if (result == QMessageBox::Ok) {
                this->close();
            }
            return;
        }
        if(col_num==3){
            col_num++;
            // 创建一个消息对话框
            QMessageBox msgBox;
            msgBox.setWindowTitle("提示");
            msgBox.setText("回答正确，即将前往下一地点");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.setDefaultButton(QMessageBox::Ok);

            // 弹出对话框并等待用户确认
            int result = msgBox.exec();
            if (result == QMessageBox::Ok) {
                questionLabel->setText(pku_views[col_num]);
                optionButton1->setText(option_string[col_num*4]);
                optionButton2->setText(option_string[col_num*4+1]);
                optionButton3->setText(option_string[col_num*4+2]);
                optionButton4->setText(option_string[col_num*4+3]);
                QPixmap background(pic_name[col_num]);
                pal.setBrush(QPalette::Background, background);
                setPalette(pal);//设置背景
                    // 用户点击了确认按钮
                    // 执行相应的操作
            }

        }
        else{
            QMessageBox msgBox;
            msgBox.setWindowTitle("提示");
            msgBox.setText("回答错误啦，再好好想想，或者去问问小北");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.setDefaultButton(QMessageBox::Ok);
            // 弹出对话框并等待用户确认
            int result = msgBox.exec();
        }
        // 在这里处理选项按钮的点击事件
        // 根据选项的文本执行相应的逻辑
    }
}
