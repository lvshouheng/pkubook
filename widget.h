#ifndef WIDGET_H
#define WIDGET_H
#include "config.h"
#include "ui_widget.h"
#include <QIcon>
#include <QApplication>
#include <QtWidgets>
#include <QTimer>
#include "chatbutton.h"
#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    QLineEdit* inputLineEdit;

//    void initScene();

private:
    Ui::Widget *ui;
};



#endif // WIDGET_H
