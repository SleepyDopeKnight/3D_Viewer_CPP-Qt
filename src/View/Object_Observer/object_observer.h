#ifndef OBJECT_OBSERVER_H
#define OBJECT_OBSERVER_H

#include <QtOpenGLWidgets/qopenglwidget.h>

#include <QMouseEvent>
#include <QWidget>
#include <QtOpenGLWidgets/QOpenGLWidget>

#include "../../Controller/Object_Controller/object_controller.h"
#include "../../Controller/Style_Controller/style_controlloer.h"

namespace Ui {
class ObjectObserver;
}

class ObjectObserver : public QOpenGLWidget {
  Q_OBJECT

 public:
  explicit ObjectObserver(s21::ObjectHandlerController *object_controller,
                          s21::StyleHandlerController *style_controller,
                          QWidget *parent = nullptr);

  ~ObjectObserver() {}

  void SetObjectController(s21::ObjectHandlerController *object_controller) {
    object_controller_ = object_controller;
  };

  void SetStyleController(s21::StyleHandlerController *style_controller) {
    style_controller_ = style_controller;
  };

  void GetData() { model_ = object_controller_->GetData(); };

  void mousePressEvent(QMouseEvent *mo) { mPos = mo->pos(); }

  void mouseMoveEvent(QMouseEvent *mo) {
    xRot_m = 1 / M_PI * (mo->pos().y() - mPos.y());
    yRot_m = 1 / M_PI * (mo->pos().x() - mPos.x());
    update();
  }

 private:
  s21::ObjectHandlerController *object_controller_;
  s21::StyleHandlerController *style_controller_;

  Ui::ObjectObserver *ui;
  s21::ObjectData model_;
  float xRot_m, yRot_m;
  QPoint mPos;

  void initializeGL();
  void resizeGL(int w, int h);
  void paintGL();
  void draw_model();
  void draw_points();

};

#endif  // OBJECT_OBSERVER_H
