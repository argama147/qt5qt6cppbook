#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Widget w;
  w.show();

  Widget w2;
  w2.move(w.x(), w.y() + 200);
  w2.show();

  return a.exec();
}
