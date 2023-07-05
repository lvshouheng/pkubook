//名字起错了，应该是bubble（气泡）

#ifndef CHATBUTTON_H
#define CHATBUTTON_H
#include <QApplication>
#include <QtWidgets>
#include <QTimer>

class ChatBubble : public QWidget {
public:
    ChatBubble(const QString& text, bool isSender, const QString& avatarPath, QWidget* parent = nullptr) : QWidget(parent), isSender_(isSender) {
        textLabel_ = new QLabel(text);
        textLabel_->setWordWrap(true);

        avatarLabel_ = new QLabel();
        QPixmap avatarPixmap(avatarPath); // 头像图片路径
        avatarLabel_->setPixmap(avatarPixmap.scaledToWidth(50)); // 设置头像宽度为50像素

        QHBoxLayout* layout = new QHBoxLayout(this);
        if(isSender){
            layout->addWidget(avatarLabel_);
            layout->addWidget(textLabel_);
        }
        else{
            layout->addWidget(textLabel_);
            layout->addWidget(avatarLabel_);
        }
        layout->setContentsMargins(10, 10, 10, 10);

        setSizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        updateSize();
    }

    void setText(const QString& text) {
        textLabel_->setText(text);
        updateSize();
    }

protected:
    void updateSize() {
        int width = qMax(textLabel_->sizeHint().width()+60,150);
        int height = textLabel_->sizeHint().height()+50;
        setFixedSize(width, height);
    }

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
    }

private:
    QLabel* textLabel_;
    QLabel* avatarLabel_;
    bool isSender_;
};
#endif // CHATBUTTON_H
