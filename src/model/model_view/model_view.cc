#include "model_view.h"

s21::StyleView::StyleView() {
  colors_.emplace(std::pair<std::string, float>("line_color_r", 0.0));
  colors_.emplace(std::pair<std::string, float>("line_color_g", 0.0));
  colors_.emplace(std::pair<std::string, float>("line_color_b", 0.0));
  colors_.emplace(std::pair<std::string, float>("background_color_r", 0.0));
  colors_.emplace(std::pair<std::string, float>("background_color_g", 0.0));
  colors_.emplace(std::pair<std::string, float>("background_color_b", 0.0));
  colors_.emplace(std::pair<std::string, float>("vertex_color_r", 0.0));
  colors_.emplace(std::pair<std::string, float>("vertex_color_g", 0.0));
  colors_.emplace(std::pair<std::string, float>("vertex_color_b", 0.0));
  size_.emplace(std::pair<std::string, int>("line_size", 1));
  size_.emplace(std::pair<std::string, int>("vertex_size", 1));
  type_.emplace(std::pair<std::string, int>("projection_type", 0));
  type_.emplace(std::pair<std::string, int>("vertex_type", 0));
  type_.emplace(std::pair<std::string, int>("line_type", 0));
  InitSettings();
}

void s21::StyleView::SaveSettings() {
  QString path =
      QStandardPaths::writableLocation(QStandardPaths::HomeLocation) +
      "/.Viewer";
  QDir().mkpath(path);
  QSettings settings(path + "/settings.ini", QSettings::IniFormat);
  for (const auto &s : size_) {
    settings.setValue(QString::fromStdString(s.first), QVariant(s.second));
  }

  for (const auto &c : colors_) {
    settings.setValue(QString::fromStdString(c.first), QVariant(c.second));
  }

  for (const auto &t : type_) {
    settings.setValue(QString::fromStdString(t.first), QVariant(t.second));
  }
}

void s21::StyleView::InitSettings() {
  QString path =
      QStandardPaths::writableLocation(QStandardPaths::HomeLocation) +
      "/.Viewer";
  QSettings settings(path + "/settings.ini", QSettings::IniFormat);
  for (const auto &s : size_) {
    size_[s.first] = settings.value(QString::fromStdString(s.first), 0).toInt();
  }
  for (const auto &c : colors_) {
    colors_[c.first] =
        settings.value(QString::fromStdString(c.first), 0).toFloat();
  }
  for (const auto &t : type_) {
    type_[t.first] = settings.value(QString::fromStdString(t.first), 0).toInt();
  }
}

std::map<std::string, float> s21::StyleView::GetColors() { return colors_; }

std::map<std::string, int> s21::StyleView::GetSize() { return size_; }

std::map<std::string, int> s21::StyleView::GetType() { return type_; }

void s21::StyleView::SetColors(std::map<std::string, float> colors) {
  this->colors_ = colors;
}

void s21::StyleView::SetType(std::map<std::string, int> type) {
  this->type_ = type;
}

void s21::StyleView::SetSize(std::map<std::string, int> size) {
  this->size_ = size;
}
