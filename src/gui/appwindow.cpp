#include "appwindow.h"

#include "./ui_appwindow.h"

appWindow::appWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::appWindow) {
  ui->setupUi(this);
  ui->moveX->setValue(0);
  ui->moveX->setMinimum(-77);
  ui->moveX->setMaximum(77);

  ui->moveY->setValue(0);
  ui->moveY->setMinimum(-77);
  ui->moveY->setMaximum(77);

  ui->moveZ->setValue(0);
  ui->moveZ->setMinimum(-77);
  ui->moveZ->setMaximum(77);

  ui->rotateX->setValue(0);
  ui->rotateX->setMinimum(-360);
  ui->rotateX->setMaximum(360);

  ui->rotateY->setValue(0);
  ui->rotateY->setMinimum(-360);
  ui->rotateY->setMaximum(360);

  ui->rotateZ->setValue(0);
  ui->rotateZ->setMinimum(-360);
  ui->rotateZ->setMaximum(360);

  ui->scale->setValue(0);
  ui->scale->setMaximum(5);

  ui->background->setValue(0);
  ui->background->setMaximum(2);

  ui->edgesBg->setValue(0);
  ui->edgesBg->setMaximum(2);
  ui->edgesSize->setValue(0);
  ui->edgesSize->setMaximum(50);

  ui->verticesBg->setValue(0);
  ui->verticesBg->setMaximum(2);
  ui->verticesSize->setValue(0);
  ui->verticesSize->setMaximum(50);

  ui->field->perspective = true;
  ui->perspective->setChecked(true);

  ui->field->edgesType = 0;
  ui->solid->setChecked(true);
  ui->field->verticesType = 0;
  ui->def->setChecked(true);

  read_settings();
}

appWindow::~appWindow() { delete ui; }

void appWindow::on_choose_clicked() {
  QString fileName =
      QFileDialog::getOpenFileName(this, tr("Select a file to open"),
                                   QDir::homePath(), tr("Text Files (*.obj)"));
  if (fileName.isEmpty()) {
    QMessageBox::warning(this, "ERROR", "Try again");
    return;
  }
  int err = parserFile((char *)fileName.toStdString().c_str(), &data);
  if (err == OK) {
    ui->pathFile->setText(ui->pathFile->text() + ' ' + fileName);
    ui->vertexCount->setText(ui->vertexCount->text() + ' ' +
                             QString::number(data.idxVertex));
    ui->polygonCount->setText(ui->polygonCount->text() + ' ' +
                              QString::number(data.idxPolygon));

    resizeValue(&data, 0.9);

    ui->field->v_count = data.idxVertex;
    ui->field->f_count = data.idxPolygon;
    ui->field->v_array = data.vertexArray;
    ui->field->f_array = data.polygonArray;

  } else {
    QMessageBox::warning(this, "ERROR", "Wrong path!");
    return;
  }
}

void appWindow::on_reset_clicked() {
  ui->field->perspective = true;
  ui->field->orthographic = false;
  ui->perspective->setChecked(true);

  ui->field->edgesType = 0;
  ui->solid->setChecked(true);
  ui->field->edgesSize = 0;
  ui->input_edgesSize->setText("0");
  ui->edgesSize->setValue(0);

  ui->field->verticesType = 0;
  ui->def->setChecked(true);
  ui->field->verticesSize = 0;
  ui->input_vert_size->setText("0");
  ui->verticesSize->setValue(0);

  ui->field->bR = 0;
  ui->field->bG = 0;
  ui->field->bB = 0;
  ui->background->setValue(0);
  ui->field->eR = 255;
  ui->field->eR = 255;
  ui->field->eR = 255;
  ui->edgesBg->setValue(0);

  ui->field->vR = 255;
  ui->field->vR = 255;
  ui->field->vR = 255;
  ui->verticesBg->setValue(0);

  ui->input_moveX->setText("0");
  ui->input_moveY->setText("0");
  ui->input_moveZ->setText("0");
  ui->input_rotateX->setText("0");
  ui->input_rotateY->setText("0");
  ui->input_rotateZ->setText("0");
  ui->input_scale->setText("0");

  ui->moveX->setValue(0);
  ui->moveY->setValue(0);
  ui->moveZ->setValue(0);
  ui->rotateX->setValue(0);
  ui->rotateY->setValue(0);
  ui->rotateZ->setValue(0);
  ui->scale->setValue(0);

  ui->pathFile->setText("Path:");
  ui->vertexCount->setText("Vertex:");
  ui->polygonCount->setText("Polygon:");
  data.idxPolygon = 0;
  data.idxVertex = 0;
  //  free(data.polygonArray);
  //  free(data.vertexArray);
  delete data.polygonArray;
  delete data.vertexArray;

  ui->field->v_count = 0;
  ui->field->f_count = 0;
  ui->field->v_array = 0;
  ui->field->f_array = 0;

  moveX = 0;
  moveBufX = 0;
  moveY = 0;
  moveBufY = 0;
  moveZ = 0;
  moveBufZ = 0;
  rotateX = 0;
  rotateBufX = 0;
  rotateY = 0;
  rotateBufY = 0;
  rotateZ = 0;
  rotateBufZ = 0;

  ui->field->update();
}

// ===================== STYLE =====================
void appWindow::on_perspective_clicked(bool checked) {
  if (checked) {
    ui->field->orthographic = false;
    ui->field->perspective = true;
    ui->perspective->setChecked(true);
    //      ui->field->update();
  }
}

void appWindow::on_orthographic_clicked(bool checked) {
  if (checked) {
    ui->field->perspective = false;
    ui->field->orthographic = true;
    ui->orthographic->setChecked(true);
    //    ui->field->update();
  }
}

// ================================================

// ===================== MOVE =====================
void appWindow::on_moveX_valueChanged(int value) {
  ui->input_moveX->setText(QString::number(value));
  QString tmp = ui->input_moveX->text();
  double step = tmp.toDouble();
  moveX = step - moveBufX;
  moveX /= 100;
  move_x(&data, moveX);
  moveBufX = step;
  ui->field->update();
}

void appWindow::on_moveY_valueChanged(int value) {
  ui->input_moveY->setText(QString::number(value));
  QString tmp = ui->input_moveY->text();
  double step = tmp.toDouble();
  moveY = step - moveBufY;
  moveY /= 100;
  move_y(&data, moveY);
  moveBufY = step;
  ui->field->update();
}

void appWindow::on_moveZ_valueChanged(int value) {
  ui->input_moveZ->setText(QString::number(value));
  QString tmp = ui->input_moveZ->text();
  double step = tmp.toDouble();
  moveZ = step - moveBufZ;
  moveZ /= 100;
  move_z(&data, moveZ);
  moveBufZ = step;
  ui->field->update();
}
// ===============================================

// ===================== ROTATE ==================
void appWindow::on_rotateX_valueChanged(int value) {
  ui->input_rotateX->setText(QString::number(value));

  QString tmp = ui->input_rotateX->text();
  double step = tmp.toDouble();
  rotateX = step - rotateBufX;
  rotate_x(&data, rotateX);
  rotateBufX = step;
  ui->field->update();
}

void appWindow::on_rotateY_valueChanged(int value) {
  ui->input_rotateY->setText(QString::number(value));

  QString tmp = ui->input_rotateY->text();
  double step = tmp.toDouble();
  rotateY = step - rotateBufY;
  rotate_y(&data, rotateY);
  rotateBufY = step;
  ui->field->update();
}

void appWindow::on_rotateZ_valueChanged(int value) {
  ui->input_rotateZ->setText(QString::number(value));
  QString tmp = ui->input_rotateZ->text();
  double step = tmp.toDouble();
  rotateZ = step - rotateBufZ;
  rotate_z(&data, rotateZ);
  rotateBufZ = step;
  ui->field->update();
}
// ===============================================

// ===================== SCALE ==================
void appWindow::on_scale_valueChanged(int value) {
  ui->input_scale->setText(QString::number(value));
  if (value > 1) {
    resizeValue(&data, 1.0);
    scale(&data, value);
    //    ui->field->update();
  } else {
    resizeValue(&data, 1.0);
  }
  ui->field->update();
}
// ===============================================

// ===================== BG_VALUE ================
void appWindow::on_background_valueChanged(int value) {
  ui->input_bgField->setText(QString::number(value));

  if (value == 0) {
    ui->field->bR = 0;
    ui->field->bG = 0;
    ui->field->bB = 0;
    //    ui->field->update();
  } else if (value == 1) {
    ui->field->bR = 0;
    ui->field->bG = 255;
    ui->field->bB = 255;
    //    ui->field->update();
  } else if (value == 2) {
    ui->field->bR = 202;
    ui->field->bG = 0;
    ui->field->bB = 3;
    //    ui->field->update();
  }
  ui->field->update();
}
// ===============================================

// ===================== EDGES ==================
void appWindow::on_solid_clicked(bool checked) {
  if (checked) {
    ui->field->edgesType = 0;
    ui->solid->setChecked(true);
  }
}

void appWindow::on_dashed_clicked(bool checked) {
  if (checked) {
    ui->field->edgesType = 1;
    ui->dashed->setChecked(true);
  }
}
void appWindow::on_edgesBg_valueChanged(int value) {
  ui->input_edgesBg->setText(QString::number(value));
  if (value == 0) {
    ui->field->eR = 255;
    ui->field->eG = 255;
    ui->field->eB = 255;
    //      ui->field->update();
  } else if (value == 1) {
    ui->field->eR = 0;
    ui->field->eG = 255;
    ui->field->eB = 255;
    //      ui->field->update();
  } else if (value == 2) {
    ui->field->eR = 202;
    ui->field->eG = 0;
    ui->field->eB = 3;
    //      ui->field->update();
  }
  ui->field->update();
}

void appWindow::on_edgesSize_valueChanged(int value) {
  ui->input_edgesSize->setText(QString::number(value));

  ui->field->edgesSize = value;
  ui->field->update();
}
// ===============================================

// ===================== VERTICES ================
void appWindow::on_def_clicked(bool checked) {
  if (checked) {
    ui->field->verticesType = 0;
    ui->def->setChecked(true);
    // ui->field->update();
  }
  ui->field->update();
}

void appWindow::on_cirlce_clicked(bool checked) {
  if (checked) {
    ui->field->verticesType = 1;
    ui->cirlce->setChecked(true);
    // ui->field->update();
  }
  ui->field->update();
}

void appWindow::on_square_clicked(bool checked) {
  if (checked) {
    ui->field->verticesType = 2;
    ui->square->setChecked(true);
    // ui->field->update();
  }
  ui->field->update();
}
void appWindow::on_verticesBg_valueChanged(int value) {
  ui->input_vert_bg->setText(QString::number(value));
  if (value == 0) {
    ui->field->vR = 255;
    ui->field->vG = 255;
    ui->field->vB = 255;
    //    ui->field->update();
  } else if (value == 1) {
    ui->field->vR = 0;
    ui->field->vG = 255;
    ui->field->vB = 255;
    //    ui->field->update();
  } else if (value == 2) {
    ui->field->vR = 202;
    ui->field->vG = 0;
    ui->field->vB = 3;
    //    ui->field->update();
  }
  ui->field->update();
}

void appWindow::on_verticesSize_valueChanged(int value) {
  ui->input_vert_size->setText(QString::number(value));

  ui->field->verticesSize = value;
  ui->field->update();
}
// ===============================================

// ===================== SCREEN ================
void appWindow::on_screenBtn_clicked() {
  QString filter = "jpg;; bmp";
  QString fileName = QFileDialog::getSaveFileName(
      NULL, "save screenshot:", last_dirpath_record, filter, &filter);

  if (!fileName.isNull()) {
    last_dirpath_record = get_filedir(fileName);
    ui->field->screen(fileName + "." + filter, filter);
  }
}

QString appWindow::get_filedir(QString fullpath) {
  QFileInfo fileInfo;
  fileInfo.setFile(fullpath);
  return fileInfo.absolutePath();
}

QString appWindow::get_filename(QString fullpath) {
  QString fileName;
  QFileInfo fileInfo;

  fileInfo.setFile(fullpath);

  if (fileInfo.completeSuffix().isEmpty()) {
    fileName = fileInfo.completeBaseName();
  } else {
    fileName = fileInfo.completeBaseName() + "." + fileInfo.completeSuffix();
  }
  return fileName;
}

QString appWindow::get_fileext(QString fullpath) {
  QFileInfo fileInfo;
  fileInfo.setFile(fullpath);
  return fileInfo.completeSuffix();
}
// ===============================================

// ===================== GIF ================
void appWindow::on_gifBtn_clicked(bool checked) {
  ui->gifBtn->setChecked(checked);

  if (checked) {
    ui->gifBtn->setText("stop recording");
    ui->recordl->setText("● recording in progress");
    ui->field->recordStart();
  } else {
    ui->gifBtn->setText("● record");
    ui->recordl->setText("");

    QString filter = ".gif";
    QString fileName = QFileDialog::getSaveFileName(
        NULL, "save screenshot:", last_dirpath_record, filter, &filter);
    ui->field->recordFinish(fileName, filter);

    if (!fileName.isNull()) {
      last_dirpath_record = get_filedir(fileName);
    }
  }
}
// ===============================================

void appWindow::write_settings() {
  QSettings settings("C_3DEngine");
  settings.setValue("saved_state", true);

  settings.setValue("value_b", ui->input_bgField->text());
  settings.setValue("value_e", ui->input_edgesBg->text());
  settings.setValue("value_v", ui->input_vert_bg->text());

  settings.setValue("edgesType", ui->field->edgesType);
  settings.setValue("edgesSize", ui->input_edgesSize->text());

  settings.setValue("verticesType", ui->field->verticesType);
  settings.setValue("verticesSize", ui->input_vert_size->text());

  settings.setValue("perspective", ui->field->perspective);
  settings.setValue("orthographic", ui->field->orthographic);

  qDebug() << "123";
}

void appWindow::read_settings() {
  QSettings settings("C_3DEngine");
  qDebug() << "321";
  const auto saved_state =
      settings.value("saved_state", QByteArray()).toByteArray();
  if (!saved_state.isEmpty()) {
    this->setGeometry(settings.value("windowsize").toRect());
    if ((ui->field->value_b = settings.value("value_b").toUInt()) == 0) {
      ui->field->bR = 0;
      ui->field->bG = 0;
      ui->field->bB = 0;
      ui->background->setValue(0);
    } else if ((ui->field->value_b = settings.value("value_b").toUInt()) == 1) {
      ui->field->bR = 0;
      ui->field->bG = 255;
      ui->field->bB = 255;
      ui->background->setValue(1);
    } else if ((ui->field->value_b = settings.value("value_b").toUInt()) == 2) {
      ui->field->bR = 202;
      ui->field->bG = 0;
      ui->field->bB = 3;
      ui->background->setValue(2);
    }

    if ((ui->field->value_e = settings.value("value_e").toUInt()) == 0) {
      ui->field->eR = 255;
      ui->field->eG = 255;
      ui->field->eB = 255;
      ui->edgesBg->setValue(0);
    } else if ((ui->field->value_e = settings.value("value_e").toUInt()) == 1) {
      ui->field->eR = 0;
      ui->field->eG = 255;
      ui->field->eB = 255;
      ui->edgesBg->setValue(1);
    } else if ((ui->field->value_e = settings.value("value_e").toUInt()) == 2) {
      ui->field->eR = 202;
      ui->field->eG = 0;
      ui->field->eB = 3;
      ui->edgesBg->setValue(2);
    }

    if ((ui->field->value_v = settings.value("value_v").toUInt()) == 0) {
      ui->field->vR = 255;
      ui->field->vG = 255;
      ui->field->vB = 255;
      ui->verticesBg->setValue(0);
    } else if ((ui->field->value_v = settings.value("value_v").toUInt()) == 1) {
      ui->field->vR = 0;
      ui->field->vG = 255;
      ui->field->vB = 255;
      ui->verticesBg->setValue(1);
    } else if ((ui->field->value_v = settings.value("value_v").toUInt()) == 2) {
      ui->field->vR = 202;
      ui->field->vG = 0;
      ui->field->vB = 3;
      ui->verticesBg->setValue(2);
    }

    if ((ui->field->edgesType = settings.value("edgesType").toInt()) == 1) {
      ui->field->edgesType = 1;
      ui->dashed->setChecked(true);
    } else {
      ui->field->edgesType = 0;
      ui->solid->setChecked(true);
    }
    ui->field->edgesSize = settings.value("edgesSize").toDouble();
    ui->input_edgesSize->setText(QString::number(ui->field->edgesSize));
    ui->edgesSize->setValue(settings.value("edgesSize").toInt());

    if ((ui->field->verticesType = settings.value("verticesType").toInt()) ==
        0) {
      ui->field->verticesType = 0;
      ui->def->setChecked(true);
    } else if ((ui->field->verticesType =
                    settings.value("verticesType").toInt()) == 1) {
      ui->field->verticesType = 1;
      ui->cirlce->setChecked(true);
    } else if ((ui->field->verticesType =
                    settings.value("verticesType").toInt()) == 2) {
      ui->field->verticesType = 2;
      ui->square->setChecked(true);
    }

    ui->field->verticesSize = settings.value("verticesSize").toDouble();
    ui->input_vert_size->setText(QString::number(ui->field->verticesSize));
    ui->verticesSize->setValue(settings.value("verticesSize").toInt());

    if ((ui->field->perspective = settings.value("perspective").toBool()) ==
        true) {
      ui->field->perspective = true;
      ui->perspective->setChecked(true);
    } else if ((ui->field->orthographic =
                    settings.value("orthographic").toBool()) == true) {
      ui->field->orthographic = true;
      ui->orthographic->setChecked(true);
    }

  } else {
    qDebug() << "first start of the application, no settings to load";
  }
}

void appWindow::on_settings_clicked() { write_settings(); }
