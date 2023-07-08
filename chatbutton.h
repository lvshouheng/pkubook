//名字起错了，应该是bubble（气泡）

#ifndef CHATBUTTON_H
#define CHATBUTTON_H
#include <QApplication>
#include <QtWidgets>
#include <QTimer>

class ChatBubble : public QWidget {
public:
    ChatBubble(const QString& text, bool isSender, const QString& avatarPath, QWidget* parent = nullptr);
    void setText(const QString& text);//设置气泡文本

protected:
    void updateSize();
    void paintEvent(QPaintEvent* event) override {
        QPainter painter(this);
        QPen pen;
        pen.setWidth(2);
        painter.setPen(pen);

        if (isSender_) {
            painter.setBrush(QColor("#DCF8C6")); // 发送者气泡颜色
            painter.drawRoundedRect(rect().adjusted(0, 0, -10, 0), 10, 10); // 向左气泡
        } else {
            painter.setBrush(QColor("#E5E5EA")); // 接收者气泡颜色
            painter.drawRoundedRect(rect().adjusted(0, 0, -10, 0), 10, 10); // 向右气泡
        }
    }//绘画气泡

private:
    QLabel* textLabel_;
    QLabel* avatarLabel_;//头像路径
    bool isSender_;//判断是否是发送者
};
#endif // CHATBUTTON_H
