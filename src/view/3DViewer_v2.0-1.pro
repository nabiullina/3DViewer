QT += core gui
QT += opengl
QT += openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
include(gifimage/qtgifimage.pri)

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../model/model_view/model_view.cc \
    ../controller/model_controller/object_controller.cc \
    ../model/parser/simple_parser.cc \
    ../model/transformer/transformer.cc \
    ../controller/view_controller/view_controller.cc \
    glwidget.cc \
    main.cc \
    mainwindow.cc \

HEADERS += \
    glwidget.h \
    ../model/model_data.h \
    ../model/model_view/model_view.h \
    ../controller/model_controller/object_controller.h \
    ../model/object_facade/object_facade.h \
    ../model/parser/parser.h \
    ../model/parser/parser_strategy.h \
    ../model/parser/simple_parser.h \
    ../model/transformer/transformer.h \
    ../controller/view_controller/view_controller.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Makefile.file

 RESOURCES += \
    resource.qrc
