#ifndef CPP4_3DVIEWER_V2_0_1_SRC_VIEW_GLWIDGET_H
#define CPP4_3DVIEWER_V2_0_1_SRC_VIEW_GLWIDGET_H

#include <QColor>
#include <QColorDialog>
#include <QFileDialog>
#include <QMouseEvent>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QSettings>
#include <cstring>
#include <iostream>

#include "../controller/model_controller/object_controller.h"

namespace s21 {

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions {
 public:
  s21::ObjectController *object_controller;

  QSettings settings;
  GLWidget(QWidget *parent = 0);
  ~GLWidget();

  void initializeGL();
  void paintGL();
  void PaintModel(s21::ModelData model);
  void resizeGL(int w, int h);
  void ScaleObj();
  void CustomizeLineDisplay();
  void CustomizeVertexDisplay();
  void SetupPerspective(s21::ModelData model);
  void DrawObj();
  void SetStyleSettings(std::map<std::string, float> colors,
                        std::map<std::string, int> size,
                        std::map<std::string, int> type);

  QColor vertex_color = nullptr;
  QColor line_color = nullptr;
  QColor background_color = nullptr;

  QString obj_path;

  double scale_obj = 0.0;

  std::map<std::string, float> colors;
  std::map<std::string, int> size;
  std::map<std::string, int> type;

 private:
  void mousePressEvent(QMouseEvent *mouse);
  void mouseMoveEvent(QMouseEvent *mouse);
  float rotate_mouse_x, rotate_mouse_y;
  QPoint mouse_pos;
};

}  // namespace s21
#endif  // CPP4_3DVIEWER_V2_0_1_SRC_VIEW_GLWIDGET_H
