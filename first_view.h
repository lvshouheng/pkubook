#ifndef FIRST_VIEW_H
#define FIRST_VIEW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QScrollArea>
#include <QGraphicsPixmapItem>
#include <chatwindow.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onSendButtonClicked();
    void onGameButtonClicked();

private:
    QLabel* dictionaryImageLabel;//虚拟形象图片
    QLabel* speakimage;
    QLabel* exampleLabel;
    QLabel* abilityLabel;
    QLabel* limitLabel;
    QPushButton* exampleButton1;
    QPushButton* exampleButton2;
    QPushButton* exampleButton3;
    QPushButton* abilityButton1;
    QPushButton* abilityButton2;
    QPushButton* abilityButton3;
    QPushButton* limitButton1;
    QPushButton* limitButton2;
    QPushButton* limitButton3;
};

#endif // FIRST_VIEW_H
