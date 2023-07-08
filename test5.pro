#-------------------------------------------------
#
# Project created by QtCreator 2023-06-28T13:34:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test5
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
    first_view.cpp \
    gamewindow.cpp \
    chatwindow.cpp \
    get_ans.cpp \
    chatbutton.cpp

HEADERS += \
    chatbutton.h \
    chatwindow.h \
    first_view.h \
    get_ans.h \
    gamewindow.h

FORMS += \
        widget.ui

QT += \
    network

QT += core widgets


#LIBS += -lssl -lcrypto

#QT += \
#    ssl

#LIBS += -L"C:/Program Files (x86)/OpenSSL-Win32/lib" -llibeay32
#LIBS += -L"C:/Program Files (x86)/OpenSSL-Win32/lib" -lssleay32

#INCLUDEPATH += $$quote(C:/Program Files (x86)/OpenSSL-Win32/include)

#win32 {
#INCLUDEPATH += $$quote(C:/Program Files (x86)/OpenSSL-Win32/include)
#LIBS += -L$$quote(C:/Program Files (x86)/OpenSSL-Win32/lib) -llibcrypto
#}


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    my_pic.qrc

