#include "glwidget.h"

namespace s21 {

GLWidget::~GLWidget() {}

void GLWidget::initializeGL() {
  QOpenGLWidget::initializeGL();
  initializeOpenGLFunctions();
}

void GLWidget::SetStyleSettings(std::map<std::string, float> colors_const,
                                std::map<std::string, int> size_const,
                                std::map<std::string, int> type_const) {
  this->colors = colors_const;
  this->size = size_const;
  this->type = type_const;
}

GLWidget::GLWidget(QWidget *parent) : QOpenGLWidget(parent) {}

void GLWidget::paintGL() {
  s21::ModelData model = object_controller->GetModelData();
  makeCurrent();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
  initializeOpenGLFunctions();
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  SetupPerspective(model);
  CustomizeLineDisplay();
  CustomizeVertexDisplay();
  glRotatef(rotate_mouse_x, 1, 0, 0);
  glRotatef(rotate_mouse_y, 0, 1, 0);
  glEnableVertexAttribArray(0);
  PaintModel(model);
  update();
}

void GLWidget::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
}

void GLWidget::PaintModel(s21::ModelData model) {
  glClearColor(this->colors["background_color_r"],
               this->colors["background_color_g"],
               this->colors["background_color_b"], 1.0);
  glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, 0, model.vertexes.data());

  glColor3d(this->colors["vertex_color_r"], this->colors["vertex_color_g"],
            this->colors["vertex_color_b"]);
  if (type["vertex_type"] != 0) glDrawArrays(GL_POINTS, 0, model.count_v);

  glColor3d(this->colors["line_color_r"], this->colors["line_color_g"],
            this->colors["line_color_b"]);
  glDrawElements(GL_LINES, model.facets.size(), GL_UNSIGNED_INT,
                 model.facets.data());
  glDisable(GL_BLEND);
}

void GLWidget::ScaleObj() {
  object_controller->Scale(scale_obj);
  update();
}

void GLWidget::CustomizeLineDisplay() {
  glLineWidth(size["line_size"]);
  if (type["line_type"] == 0) {
    glDisable(GL_LINE_STIPPLE);
  } else if (type["line_type"] == 1) {
    glLineStipple(5, 0x00FF);
    glEnable(GL_LINE_STIPPLE);
  }
}

void GLWidget::CustomizeVertexDisplay() {
  glPointSize(size["vertex_size"]);
  if (type["vertex_type"] == 1) {
    glEnable(GL_POINT_SMOOTH);
  } else if (type["vertex_type"] == 2) {
    glDisable(GL_POINT_SMOOTH);
  }
}

void GLWidget::SetupPerspective(s21::ModelData model) {
  if (type["projection_type"] == 1) {
    glOrtho(model.min_x * 1.5, model.min_x * 1.5, model.max_x * 1.5,
            model.max_y * 1.5, model.min_z * 100, model.max_z * 100);

  } else if (type["projection_type"] == 0) {
    GLdouble zNear = model.max_coord * 0.001;
    GLdouble zFar = model.max_coord * 2;
    GLdouble angle = 90;
    GLdouble fH = tan(angle / 360 * M_PI) * zNear;
    GLdouble fW = fH;
    glFrustum(-fW, fW, -fH, fH, zNear, zFar);
    glTranslatef(0, 0, -1);
  }
}

void GLWidget::mousePressEvent(QMouseEvent *mouse) { mouse_pos = mouse->pos(); }

void GLWidget::mouseMoveEvent(QMouseEvent *mouse) {
  rotate_mouse_x = 1 / M_PI * (mouse->pos().y() - mouse_pos.y());
  rotate_mouse_y = 1 / M_PI * (mouse->pos().x() - mouse_pos.x());
}

}  // namespace s21
