#include <QApplication>

#include "appwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  appWindow w;
  w.show();

  return a.exec();
  ;
}
