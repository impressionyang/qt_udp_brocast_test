#include "udpbrocastserver.h"

UdpBrocastServer::UdpBrocastServer(QString msg) {
  brocast_server = new QUdpSocket();
  if (!msg.isEmpty()) {
    brocast_server->writeDatagram(msg.toLocal8Bit(), QHostAddress::Broadcast,
                                  10086);
  } else {
    qDebug() << "brocast server: msg is empty!";
  }
}
