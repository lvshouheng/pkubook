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

    void ai_ans(QString question) {
        QStringList monumentList;
        QStringList view_List;
        bool flag=1;
        view_List << "鸣鹤园" << "畅春园" << "慈济寺山门" << "鲁斯亭" << "紫琳浸月”石碑"
                   << "丹堰" << "六圣祠碑" << "“重修观音庵”碑" << "档案馆" << "海晏堂引水槽"
                   << "“云根”石" << "德才均备斋" << "承泽园" << "“柳浪闻莺”石牌坊构件"
                   << "第二体育馆" << "畅春园东北界碑" << "“断桥残雪”石牌坊构件" << "第一体育馆"
                   << "俄文楼" << "翻尾石鱼" << "方池" << "革命烈士纪念碑" << "葛利普墓"
                   << "国立西南联合大学纪念碑" << "杭爱碑" << "镜春园" << "花神庙碑" << "赖朴吾、夏仁德墓"
                   << "华表" << "朗润园" << "化学北楼" << "李大钊像" << "化学南楼" << "临湖轩"
                   << "静园" << "梅石碑" << "米玉墓志铭" << "一八遇难烈士纪念" << "民主楼"
                   << "生物东馆" << "南北阁" << "塞万提斯像" << "乾隆半月诗碑" << "石雕五供及石供桌"
                   << "乾隆御制诗碑" << "石舫" << "日" << "石屏风" << "碑" << "石麒麟" << "百族"
                   << "石狮" << "魏士毅墓" << "斯诺墓" << "体斋" << "健斋" << "全斋" << "外文楼"
                   << "校景亭" << "燕东园" << "振兴中华碑" << "钟亭" << "西校门" << "治贝子园"
                   << "守仁国际中心建筑群" << "校友桥" << "植树碑" << "石盆" << "博雅塔" << "鱼洗"
                   << "勺园太湖石" << "蔡元培铜像" << "燕南园" << "旗杆座(1952)" << "办公楼"
                   << "香炉" << "旗杆座(1934)" << "柱础" << "蔚秀园" << "旗杆座 (1924)";
        foreach (const QString& element, view_List) {//查找是否为北大校园内的风景名物

            if(question.contains(element)){
                flag=0;
                // 创建网络访问管理器
                QNetworkAccessManager* manager = new QNetworkAccessManager(this);

                // 创建网络请求
                QNetworkRequest request;
                request.setUrl(QUrl("https://www.pku.edu.cn/visit.html")); // 设置要访问的网址

                // 发送GET请求
                QNetworkReply* reply = manager->get(request);

                // 监听请求完成信号
                connect(reply, &QNetworkReply::finished, [=]() {
                    // 检查网络请求是否成功
                    if (reply->error() == QNetworkReply::NoError) {
                        // 读取响应数据
                        QByteArray data = reply->readAll();

                        // 处理网页内容
                        QString htmlContent = QString::fromUtf8(data);
                        QString nameToMatch = "博雅塔";

                        // 构建正则表达式模式
                        QString regexPattern = QString("<a\\b[^>]*href=\"([^\"]*)\"[^>]*>\\s*<span>%1</span>\\s*</a>").arg(element);
                        QRegularExpression regex(regexPattern);

                        // 在源代码中匹配元素
                        QRegularExpressionMatch match = regex.match(htmlContent);
                        QString url = "123";

                        if (match.hasMatch()) {
                            url = match.captured(1);     // 获取链接地址

                            // 创建新的网络访问管理器
                            QNetworkAccessManager* manager2 = new QNetworkAccessManager(this);

                            // 创建新的网络请求
                            QNetworkRequest request2;
                            request2.setUrl(QUrl(url)); // 设置要访问的网址

                            // 发送新的GET请求
                            QNetworkReply* reply2 = manager2->get(request2);

                            QObject::connect(reply2, &QNetworkReply::finished, [=]() {
                                QByteArray data2 = reply2->readAll();
                                QString htmlContent2 = QString::fromUtf8(data2);

                                // 正则表达式模式
                                QString pattern = "<strong[^>]*>([\\s\\S]*?)<\\/strong>";

                                // 创建正则表达式对象
                                QRegularExpression regex2(pattern);
                                QRegularExpressionMatch match2 = regex2.match(htmlContent2);
                                QString url2 = match2.captured(1);

                                qDebug() << "URL: " << htmlContent2;

                                // 发送信号将获取的数据传递出去
                                emit resultReady(url2);
                                reply2->deleteLater();
                            });
                        }
                    } else {
                        // 网络请求发生错误
                        QString error = "Network request error: " + reply->errorString();

                        // 发送信号将错误信息传递出去
                        emit resultReady(error);
                    }

                    // 释放网络响应对象
                    reply->deleteLater();
                });
                break;
            }
        }
        if(flag){
            emit resultReady("抱歉，我还不会这个，问点其他的试试吧");
        }
    }


signals:
    void resultReady(const QString& result);
};


#endif // GET_ANS_H
