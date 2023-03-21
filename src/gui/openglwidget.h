#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H
#define GL_SILENCE_DEPRECATION

// #include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QTimer>
// #include <QtEvents>
#include <QOpenGLWidget>
#include <QWidget>

#include "../core/main.h"
#include "./QtGifImage-master/src/gifimage/qgifimage.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class OpenGLWidget;
}
QT_END_NAMESPACE

class OpenGLWidget : public QOpenGLWidget {
  Q_OBJECT

 public:
  OpenGLWidget(QWidget *parent = nullptr);
  //  void initializeGL() override;
  //  void resizeGL(int w, int h) override;
  //  void paintGL() override;
  void screen(QString filename, QString fileext);
  void recordStart();
  void recordFinish(QString filename, QString fileext);

  unsigned int v_count;
  unsigned int f_count;

  double *v_array;
  unsigned int *f_array;

  int edgesType = 0;
  double edgesSize;

  int verticesType = 0;
  double verticesSize;

  bool perspective = true;
  bool orthographic = false;

  unsigned int bR = 0;
  unsigned int bG = 0;
  unsigned int bB = 0;
  unsigned int value_b;

  unsigned int eR = 255;
  unsigned int eG = 255;
  unsigned int eB = 255;
  unsigned int value_e;

  unsigned int vR = 255;
  unsigned int vG = 255;
  unsigned int vB = 255;
  unsigned int value_v;

 private slots:
  void record();

 protected:
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;

 private:
  QGifImage *gif = NULL;
  QTimer *gif_timer = NULL;
  const int gif_interval = 1000 / 10;
};

#endif  // OPENGLWIDGET_H
