#include "openglwidget.h"

OpenGLWidget::OpenGLWidget(QWidget *parent) : QOpenGLWidget(parent) {
  bR = 0;
  bG = 0;
  bB = 0;

  eR = 255;
  eG = 255;
  eB = 255;

  vR = 255;
  vG = 255;
  vB = 255;

  v_array = 0;
  f_array = 0;
}

void OpenGLWidget::initializeGL() { glEnable(GL_DEPTH_TEST); }

void OpenGLWidget::resizeGL(int w, int h) { glViewport(0, 0, w, h); }

void OpenGLWidget::paintGL() {
  glLoadIdentity();
  glClearColor(bR, bG, bB, 0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnableClientState(GL_VERTEX_ARRAY);

  glMatrixMode(GL_PROJECTION);
  glOrtho(-1, 1, -1, 1, -1, 1);

  if (orthographic == true) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
  }

  if (perspective == true) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1, 1, -1, 1, 2, 6);
    glTranslatef(0, 0, -3);
  }
  update();

  if (edgesType == 1) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00F0);
    glColor3d(eR, eG, eB);
  } else if (edgesType == 0) {
    glDisable(GL_LINE_STIPPLE);
    glColor3d(eR, eG, eB);
  }
  update();

  glLineWidth(edgesSize);

  glVertexPointer(3, GL_DOUBLE, 0, v_array);
  glDrawElements(GL_LINES, f_count, GL_UNSIGNED_INT, f_array);

  if (verticesType == 0) {
    glPointSize(0);
  } else if (verticesType == 1) {
    glEnable(GL_POINT_SMOOTH);
    glPointSize(verticesSize);

    glColor3d(vR, vG, vB);

    glEnableClientState(GL_VERTEX_ARRAY);
    glDrawArrays(GL_POINTS, 0, v_count);

    glDisableClientState(GL_VERTEX_ARRAY);
  } else if (verticesType == 2) {
    glDisable(GL_POINT_SMOOTH);
    glPointSize(verticesSize);

    glColor3d(vR, vG, vB);

    glEnableClientState(GL_VERTEX_ARRAY);
    glDrawArrays(GL_POINTS, 0, v_count);
    glDisableClientState(GL_VERTEX_ARRAY);
  }
  update();

  glDisable(GL_POINT_SMOOTH);
  glDisable(GL_LINE_STIPPLE);
  glDisableClientState(GL_VERTEX_ARRAY);
}

void OpenGLWidget::screen(QString filename, QString fileext) {
  this->grabFramebuffer().save(filename, fileext.toStdString().c_str());
}

void OpenGLWidget::recordStart() {
  gif = new QGifImage();
  gif_timer = new QTimer(this);

  gif->setDefaultDelay(gif_interval);

  connect(gif_timer, SIGNAL(timeout()), this, SLOT(record()));
  gif_timer->start(gif_interval);
}

void OpenGLWidget::recordFinish(QString filename, QString fileext) {
  gif_timer->stop();
  disconnect(gif_timer, SIGNAL(timeout()), this, SLOT(record()));

  if (!filename.isNull()) {
    gif->save(filename + fileext);
  }

  delete gif;
  delete gif_timer;
}

void OpenGLWidget::record() {
  QPixmap frame(this->size());
  this->render(&frame);

  QImage img = frame.toImage();
  gif->addFrame(img, gif_interval);
}
