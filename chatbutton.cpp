//chatbutton.cpp

#include "chatbutton.h"

ChatBubble::ChatBubble(const QString& text, bool isSender, const QString& avatarPath, QWidget* parent) : QWidget(parent), isSender_(isSender) {
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

void ChatBubble::setText(const QString& text) {
    textLabel_->setText(text);
    updateSize();
}

void ChatBubble::updateSize() {
    int width = qMax(textLabel_->sizeHint().width()+60,150);
    int height = textLabel_->sizeHint().height()+50;
    setFixedSize(width, height);
}

