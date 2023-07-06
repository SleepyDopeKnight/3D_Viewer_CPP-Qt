#include "object_observer.h"

#include "ui_object_observer.h"

ObjectObserver::ObjectObserver(s21::ObjectHandlerController *object_controller,
                               s21::StyleHandlerController *style_controller,
                               QWidget *parent)
    : QOpenGLWidget(parent),
      object_controller_(object_controller),
      style_controller_(style_controller) {
  setGeometry(0, 0, 1100, 700);
}

void ObjectObserver::initializeGL() { glEnable(GL_DEPTH_TEST); }

void ObjectObserver::resizeGL(int w, int h) {}

void ObjectObserver::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  // ortho begin
  float min_x = 0;
  float max_x = 0;
  float min_y = 0;
  float max_y = 0;
  float min_z = 0;
  float max_z = 0;

  if (!model_.vertices.empty()) {
    min_x = model_.vertices[0].x;
    max_x = model_.vertices[0].x;
    min_y = model_.vertices[0].y;
    max_y = model_.vertices[0].y;
    min_z = model_.vertices[0].z;
    max_z = model_.vertices[0].z;
  }

for (const auto& vertex : model_.vertices) {
    min_x = std::min(min_x, vertex.x);
    max_x = std::max(max_x, vertex.x);
    min_y = std::min(min_y, vertex.y);
    max_y = std::max(max_y, vertex.y);
    min_z = std::min(min_z, vertex.z);
    max_z = std::max(max_z, vertex.z);
}

  float scene_size = std::max({max_x - min_x, max_y - min_y, max_z - min_z});
  float center_x = (min_x + max_x) / 2;
  float center_y = (min_y + max_y) / 2;
  float center_z = (min_z + max_z) / 2;

//   float left = center_x - scene_size;
//   float right = center_x + scene_size;
//   float bottom = center_y - scene_size;
//   float top = center_y + scene_size;
//   float near = center_z - scene_size;
  float far = center_z + scene_size;

  // glOrtho(left, right, bottom, top, near, far);
  // ortho end



float top =tan(60.0 * M_PI / 180 / 2); // Верхняя граница проекции
float bottom = -top; // Нижняя граница проекции
float right = top; // Правая граница проекции
float left = -right; // Левая граница проекции

glFrustum(left, right, bottom, top, 1, 100000000000);
glTranslatef(-center_x, -center_y, -scene_size + (-1));




  // glFrustum(-1, 1, -1, 1, 1, 99999);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glRotatef(xRot_m, 1, 0, 0);
  glRotatef(yRot_m, 0, 1, 0);

  draw_model();
  // draw_points();
}

void ObjectObserver::draw_model() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST | GL_LINE_STIPPLE);
  // glEnable(GL_LINE_STIPPLE);
  // glLineStipple(1, 0x1010);
  glLineWidth(1);
  glColor3d((double)255 / 255, (double)255 / 255, (double)255 / 255);
  glVertexPointer(3, GL_FLOAT, 0, model_.vertices.data());
  glEnableClientState(GL_VERTEX_ARRAY);
  glDrawElements(GL_LINES, model_.facets.size(), GL_UNSIGNED_INT,
                 model_.facets.data());
  glDisable(GL_DEPTH_BUFFER_BIT | GL_LINE_STIPPLE);
  ;
}

void ObjectObserver::draw_points() {
  glPointSize(10);
  // glEnable(GL_POINT_SMOOTH);
  glEnable(GL_QUADS);
  glColor3f((double)255 / 255, (double)255 / 255, (double)255 / 255);
  for (const auto &vertex : model_.vertices) {
    glBegin(GL_POINTS);
    glVertex3f(vertex.x, vertex.y, vertex.z);
  }
  glDisable(GL_QUADS);
  // glDisable(GL_POINT_SMOOTH);

  glEnd();
}
