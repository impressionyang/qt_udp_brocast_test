#include "udpbrocastclient.h"

UdpBrocastClient::UdpBrocastClient() {
  brocast_client = new QUdpSocket();
  brocast_client->bind(10086, QUdpSocket::ShareAddress);

  QObject::connect(brocast_client, &QUdpSocket::readyRead, this, [=]() {
    //
    QByteArray datagram;
    datagram.resize(brocast_client->pendingDatagramSize());
    brocast_client->readDatagram(datagram.data(), datagram.size());
    emit getBrocastMsg(QString(datagram));
  });
}
