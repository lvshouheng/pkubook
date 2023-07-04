#include "widget.h"
#include <QApplication>
#include <QtWidgets>
#include <QTimer>
#include "config.h"
#include "chatbutton.h"
#include "chatwindow.h"
#include <first_view.h>


int main(int argc, char** argv) {
    QApplication app(argc, argv);
    MainWindow first_v;
    first_v.show();

    return app.exec();
}
