//ui_first_view.cpp

#include "ui_first_view.h"

void Ui_MainWindow::setupUi(QMainWindow *MainWindow)
{
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QStringLiteral("MainWindow"));
    MainWindow->resize(628, 390);
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QStringLiteral("centralwidget"));
    pushButton = new QPushButton(centralwidget);
    pushButton->setObjectName(QStringLiteral("pushButton"));
    pushButton->setGeometry(QRect(130, 130, 131, 71));
    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QStringLiteral("menubar"));
    menubar->setGeometry(QRect(0, 0, 628, 19));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QStringLiteral("statusbar"));
    MainWindow->setStatusBar(statusbar);

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
} // setupUi

void Ui_MainWindow::retranslateUi(QMainWindow *MainWindow)
{
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
    pushButton->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
} // retranslateUi
