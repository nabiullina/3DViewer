#ifndef CPP4_3DVIEWER_V2_0_1_SRC_VIEW_MAINWINDOW_H
#define CPP4_3DVIEWER_V2_0_1_SRC_VIEW_MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>

#include "../controller/view_controller/view_controller.h"
#include "3rdParty/giflib/gif_lib.h"
#include "gifimage/qgifimage.h"
#include "glwidget.h"
#include "ui_mainwindow.h"

namespace s21 {

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(s21::ViewController *view_controller,
             s21::ObjectController *object_ontroller,
             QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_open_obj_clicked();

  void on_projectionType_currentIndexChanged(int value);

  void on_backgroundColor_clicked();
  void on_vertexColor_clicked();
  void on_lineColor_clicked();

  void on_scale_obj_Box_valueChanged(int value);

  void on_lineType_currentIndexChanged(int value);
  void on_lineSizeSpin_valueChanged(int value);

  void on_vertexSizeSpin_valueChanged(int value);
  void on_vertexType_currentIndexChanged(int value);

  void on_plus_x_clicked();

  void on_minus_x_clicked();

  void on_plus_y_clicked();

  void on_minus_y_clicked();

  void on_plus_z_clicked();

  void on_minus_z_clicked();

  void on_plus_x_rotate_clicked();

  void on_minus_x_rotate_clicked();

  void on_plus_y_rotate_clicked();

  void on_minus_y_rotate_clicked();

  void on_plus_z_rotate_clicked();

  void on_minus_z_rotate_clicked();

  void wheelEvent(QWheelEvent *event);

 private:
  s21::ViewController *view_controller_;
  s21::ObjectController *object_controller_;

  QString filepath_ = nullptr;
  QGifImage *gif_ = nullptr;
  QTimer *timer_ = nullptr;
  int number_fps_ = 0;

  Ui::MainWindow *ui;
};

}  // namespace s21
#endif  // CPP4_3DVIEWER_V2_0_1_SRC_VIEW_MAINWINDOW_H
