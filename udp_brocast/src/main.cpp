#include "udpchooser.h"
#include <QApplication>

int main(int argc, char *argv[]) {

  QApplication a(argc, argv);

  //  IpTest m;

  //  TcpTesst m;
  //  m.show();
  UdpChooser u;
  u.show();

  return a.exec();
}
