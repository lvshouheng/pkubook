// GameDialog.h

#ifndef GAMEDIALOG_H
#define GAMEDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QFont>

class GameDialog : public QDialog {
    Q_OBJECT

public:
    GameDialog(QWidget* parent = nullptr);
    QStringList pku_views;//各题目信息
    QStringList option_string;//选项内容
    QFont ques_font;//字体设置
    QFont ans_font;
    QStringList pic_name;//各题目背景
    QPalette pal;
    QLabel* questionLabel;//问题及选项
    QPushButton* optionButton1;
    QPushButton* optionButton2;
    QPushButton* optionButton3;
    QPushButton* optionButton4;
private slots:
    void optionButtonClicked1();//各选项反馈
    void optionButtonClicked2();
    void optionButtonClicked3();
    void optionButtonClicked4();
};
static int col_num = 0;//记录题目序号
#endif // GAMEDIALOG_H
