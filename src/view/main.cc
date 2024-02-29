#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::ObjectFacade model;
  s21::ObjectController *object_controller =
      s21::ObjectController::GetInstance(&model);

  s21::StyleView style_view;
  s21::ViewController view_controller(&style_view);
  s21::MainWindow w(&view_controller, object_controller);
  w.setWindowTitle("3dViewer");
  w.show();
  return a.exec();
}
