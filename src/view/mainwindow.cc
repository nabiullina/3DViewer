#include "mainwindow.h"

namespace s21 {

MainWindow::MainWindow(s21::ViewController *view_controller,
                       s21::ObjectController *object_controller,
                       QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      view_controller_(view_controller),
      object_controller_(object_controller) {
  ui->setupUi(this);
  ui->GLwidget->object_controller = object_controller;
  timer_ = new QTimer(0);
}

MainWindow::~MainWindow() {
  view_controller_->SaveSettings();
  delete timer_;
  delete ui;
}

void MainWindow::on_open_obj_clicked() {
  ui->GLwidget->object_controller->ClearData();
  QString path = QFileDialog::getOpenFileName(0, "Open file", QDir::homePath(),
                                              "Файлы формата .obj (*.obj)");

  this->ui->GLwidget->obj_path = path;
  this->ui->GLwidget->object_controller->ParseDataFromFile(
      this->ui->GLwidget->obj_path.toUtf8().data());
  int lastIndex = path.lastIndexOf('/');
  ui->file_name->setText("Название: " + path.mid(lastIndex + 1));
  ui->count_vertex->setText(
      "Кол-во вершин: " +
      QString::number(this->ui->GLwidget->object_controller->GetCountV()));
  ui->count_facets->setText(
      "Кол-во полигонов: " +
      QString::number(this->ui->GLwidget->object_controller->GetCountP()));

  this->ui->GLwidget->SetStyleSettings(view_controller_->GetColors(),
                                       view_controller_->GetSize(),
                                       view_controller_->GetType());
  ui->lineSizeSpin->setValue(ui->GLwidget->size["line_size"]);
  ui->vertexSizeSpin->setValue(ui->GLwidget->size["vertex_size"]);
  ui->projectionType->setCurrentIndex(ui->GLwidget->type["projection_type"]);
  ui->lineType->setCurrentIndex(ui->GLwidget->type["line_type"]);
  ui->vertexType->setCurrentIndex(ui->GLwidget->type["vertex_type"]);
}

void MainWindow::on_scale_obj_Box_valueChanged(int value) {
  if (this->ui->GLwidget->scale_obj == 0) {
    this->ui->GLwidget->scale_obj = 1;
  }
  double prev = this->ui->GLwidget->scale_obj;
  double now = value / 100.0f;
  this->ui->GLwidget->scale_obj = now / prev;
  this->ui->GLwidget->ScaleObj();
  this->ui->GLwidget->scale_obj = now;
}

void MainWindow::on_lineColor_clicked() {
  ui->GLwidget->line_color = QColorDialog::getColor(QColor(255, 255, 255, 255));
  ui->GLwidget->colors["line_color_r"] = ui->GLwidget->line_color.redF();
  ui->GLwidget->colors["line_color_g"] = ui->GLwidget->line_color.greenF();
  ui->GLwidget->colors["line_color_b"] = ui->GLwidget->line_color.blueF();
  view_controller_->SetColors(ui->GLwidget->colors);
}

void MainWindow::on_vertexColor_clicked() {
  ui->GLwidget->vertex_color =
      QColorDialog::getColor(QColor(255, 255, 255, 255));
  ui->GLwidget->colors["vertex_color_r"] = ui->GLwidget->vertex_color.redF();
  ui->GLwidget->colors["vertex_color_g"] = ui->GLwidget->vertex_color.greenF();
  ui->GLwidget->colors["vertex_color_b"] = ui->GLwidget->vertex_color.blueF();

  view_controller_->SetColors(ui->GLwidget->colors);
}

void MainWindow::on_backgroundColor_clicked() {
  ui->GLwidget->background_color =
      QColorDialog::getColor(QColor(255, 255, 255, 255));
  ui->GLwidget->colors["background_color_r"] =
      ui->GLwidget->background_color.redF();
  ui->GLwidget->colors["background_color_g"] =
      ui->GLwidget->background_color.greenF();
  ui->GLwidget->colors["background_color_b"] =
      ui->GLwidget->background_color.blueF();
  view_controller_->SetColors(ui->GLwidget->colors);
}

void MainWindow::on_lineSizeSpin_valueChanged(int value) {
  this->ui->GLwidget->size["line_size"] = value;
  view_controller_->SetSize(ui->GLwidget->size);
}

void MainWindow::on_lineType_currentIndexChanged(int value) {
  switch (value) {
    case 0:
      ui->GLwidget->type["line_type"] = 0;
      break;
    case 1:
      ui->GLwidget->type["line_type"] = 1;
      break;
  }
  view_controller_->SetType(ui->GLwidget->type);
}

void MainWindow::on_vertexType_currentIndexChanged(int value) {
  switch (value) {
    case 0:
      ui->GLwidget->type["vertex_type"] = 0;
      break;
    case 1:
      ui->GLwidget->type["vertex_type"] = 1;
      break;
    case 2:
      ui->GLwidget->type["vertex_type"] = 2;
      break;
  }
  view_controller_->SetType(ui->GLwidget->type);
}

void MainWindow::on_vertexSizeSpin_valueChanged(int value) {
  ui->GLwidget->size["vertex_size"] = value;
  view_controller_->SetSize(ui->GLwidget->size);
}

void MainWindow::on_projectionType_currentIndexChanged(int value) {
  switch (value) {
    case 0:
      ui->GLwidget->type["projection_type"] = 0;
      break;
    case 1:
      ui->GLwidget->type["projection_type"] = 1;
      break;
  }
  view_controller_->SetType(ui->GLwidget->type);
}

void MainWindow::on_plus_x_clicked() {
  this->ui->GLwidget->object_controller->Move(
      this->ui->doubleMoveSpinBox->value(), 0);
}

void MainWindow::on_minus_x_clicked() {
  this->ui->GLwidget->object_controller->Move(
      -this->ui->doubleMoveSpinBox->value(), 0);
}

void MainWindow::on_plus_y_clicked() {
  this->ui->GLwidget->object_controller->Move(
      this->ui->doubleMoveSpinBox->value(), 1);
}

void MainWindow::on_minus_y_clicked() {
  this->ui->GLwidget->object_controller->Move(
      -this->ui->doubleMoveSpinBox->value(), 1);
}

void MainWindow::on_plus_z_clicked() {
  this->ui->GLwidget->object_controller->Move(
      this->ui->doubleMoveSpinBox->value(), 2);
}

void MainWindow::on_minus_z_clicked() {
  this->ui->GLwidget->object_controller->Move(
      -this->ui->doubleMoveSpinBox->value(), 2);
}

void MainWindow::on_plus_x_rotate_clicked() {
  this->ui->GLwidget->object_controller->Rotate(
      this->ui->doubleRotateSpinBox->value(), 0);
}

void MainWindow::on_minus_x_rotate_clicked() {
  this->ui->GLwidget->object_controller->Rotate(
      -this->ui->doubleRotateSpinBox->value(), 0);
}

void MainWindow::on_plus_y_rotate_clicked() {
  this->ui->GLwidget->object_controller->Rotate(
      this->ui->doubleRotateSpinBox->value(), 1);
}

void MainWindow::on_minus_y_rotate_clicked() {
  this->ui->GLwidget->object_controller->Rotate(
      -this->ui->doubleRotateSpinBox->value(), 1);
}

void MainWindow::on_plus_z_rotate_clicked() {
  this->ui->GLwidget->object_controller->Rotate(
      this->ui->doubleRotateSpinBox->value(), 2);
}

void MainWindow::on_minus_z_rotate_clicked() {
  this->ui->GLwidget->object_controller->Rotate(
      -this->ui->doubleRotateSpinBox->value(), 2);
}

void MainWindow::wheelEvent(QWheelEvent *event) {
  double value = 1 + event->angleDelta().y() / 940.0;
  this->ui->GLwidget->object_controller->Scale(value);
  update();
}

}  // namespace s21
