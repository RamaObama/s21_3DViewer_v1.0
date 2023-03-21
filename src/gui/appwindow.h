#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QDir>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QSettings>
#include <QString>

#include "../core/main.h"
#include "openglwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class appWindow;
}
QT_END_NAMESPACE

class appWindow : public QMainWindow {
  Q_OBJECT

 public:
  appWindow(QWidget *parent = nullptr);
  ~appWindow();

  //  QString fileName;
  dataStruct data;

  double moveX = 0;
  double moveBufX = 0;

  double moveY = 0;
  double moveBufY = 0;

  double moveZ = 0;
  double moveBufZ = 0;

  double rotateX = 0;
  double rotateBufX = 0;

  double rotateY = 0;
  double rotateBufY = 0;

  double rotateZ = 0;
  double rotateBufZ = 0;

 private slots:
  void on_choose_clicked();

  void on_moveX_valueChanged(int value);

  void on_moveY_valueChanged(int value);

  void on_moveZ_valueChanged(int value);

  void on_rotateX_valueChanged(int value);

  void on_rotateY_valueChanged(int value);

  void on_rotateZ_valueChanged(int value);

  void on_scale_valueChanged(int value);

  void on_background_valueChanged(int value);

  void on_edgesBg_valueChanged(int value);

  void on_edgesSize_valueChanged(int value);

  void on_verticesBg_valueChanged(int value);

  void on_verticesSize_valueChanged(int value);

  void on_reset_clicked();

  void on_solid_clicked(bool checked);

  void on_dashed_clicked(bool checked);

  void on_cirlce_clicked(bool checked);

  void on_square_clicked(bool checked);

  void on_def_clicked(bool checked);

  void on_perspective_clicked(bool checked);

  void on_orthographic_clicked(bool checked);

  void on_screenBtn_clicked();

  void on_gifBtn_clicked(bool checked);

  void on_settings_clicked();

 private:
  QString last_dirpath_record = NULL;
  QString get_filedir(QString fullpath);
  QString get_filename(QString fullpath);
  QString get_fileext(QString fullpath);
  void write_settings();
  void read_settings();
  Ui::appWindow *ui;
};
#endif  // APPWINDOW_H
