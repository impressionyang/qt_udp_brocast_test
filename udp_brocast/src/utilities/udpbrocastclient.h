#ifndef UDPBROCASTCLIENT_H
#define UDPBROCASTCLIENT_H

#include <QDebug>
#include <QObject>
#include <QString>
#include <QtNetwork>

class UdpBrocastClient : public QObject {
  Q_OBJECT
public:
  UdpBrocastClient();

signals:
  void getBrocastMsg(QString msg);

private:
  QUdpSocket *brocast_client;
};

#endif // UDPBROCASTCLIENT_H
