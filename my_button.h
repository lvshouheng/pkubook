#ifndef MY_BUTTON_H
#define MY_BUTTON_H

#include <QAbstractButton>
#include <QPalette>
#include <QPainter>
#include <QFont>

class MyButton : public QAbstractButton {
    Q_OBJECT

public:
    MyButton(const QString& text, QWidget* parent = nullptr) : QAbstractButton(parent) {
        setText(text);
        setButtonStyle();
    }

protected:
    void paintEvent(QPaintEvent* event) override {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        // 绘制按钮背景
        painter.setBrush(palette().button());
        painter.setPen(Qt::NoPen);
        painter.drawRoundedRect(rect(), 5, 5);

        // 绘制按钮文本
        painter.setPen(palette().buttonText().color());  // 使用文本颜色
        painter.setFont(font());
        painter.drawText(rect(), Qt::AlignCenter, text());
    }

private:
    void setButtonStyle() {
        // 设置按钮背景色和文本颜色
        QPalette palette;
        palette.setColor(QPalette::Button, QColor("#4CAF50"));  // 设置背景色
        palette.setColor(QPalette::ButtonText, Qt::white);  // 设置文本颜色
        setPalette(palette);

        // 设置按钮文本字体样式
        QFont font;
        font.setBold(true);
        setFont(font);
    }
};

#endif // MY_BUTTON_H
