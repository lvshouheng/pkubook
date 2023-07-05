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
#include<ui_first_view.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void paintEvent(QPaintEvent *event);

public:
    MainWindow(QWidget *parent = nullptr);;
    ~MainWindow();


private slots:
    void onSendButtonClicked();
    void onGameButtonClicked();


private:
    Ui::MainWindow * firstview;

    QLabel* dictionaryImageLabel;//虚拟形象图片
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
    QLabel* speakLable;
};

QT_BEGIN_NAMESPACE
namespace Ui { class first_view; }
QT_END_NAMESPACE


#endif // FIRST_VIEW_H
