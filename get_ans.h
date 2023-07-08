#ifndef GET_ANS_H
#define GET_ANS_H


#include <QObject>
#include <QtNetwork/qnetworkaccessmanager.h>
#include <QtNetwork/qnetworkrequest.h>
#include <QtNetwork/qnetworkreply.h>
#include <QRegularExpression>

class MyClass : public QObject {
    Q_OBJECT
public:
    explicit MyClass(QObject *parent = nullptr) : QObject(parent) {}

    void ai_ans(QString question);//爬取网站


signals:
    void resultReady(const QString& result);//接收信号
};


#endif // GET_ANS_H
