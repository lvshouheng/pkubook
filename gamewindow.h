// GameDialog.h

#ifndef GAMEDIALOG_H
#define GAMEDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QFont>
#include "my_button.h"

class GameDialog : public QDialog {
    Q_OBJECT

public:
    GameDialog(QWidget* parent = nullptr);
    QStringList pku_views;
    QStringList option_string;
    QFont ques_font;
    QFont ans_font;
    QStringList pic_name;
    QPalette pal;
    QLabel* questionLabel;
    QPushButton* optionButton1;
    QPushButton* optionButton2;
    QPushButton* optionButton3;
    QPushButton* optionButton4;
private slots:
    void optionButtonClicked1();
    void optionButtonClicked2();
    void optionButtonClicked3();
    void optionButtonClicked4();
};
static int col_num = 0;
#endif // GAMEDIALOG_H
