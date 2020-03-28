#ifndef UDPBROCASTSERVER_H
#define UDPBROCASTSERVER_H

#include <QDebug>
#include <QObject>
#include <QString>
#include <QtNetwork>

class UdpBrocastServer : public QObject {
  Q_OBJECT
public:
  UdpBrocastServer(QString msg);

private:
  QUdpSocket *brocast_server;
};

#endif // UDPBROCASTSERVER_H
