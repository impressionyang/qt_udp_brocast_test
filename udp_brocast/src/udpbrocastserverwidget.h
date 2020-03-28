#ifndef UDPBROCASTSERVERWIDGET_H
#define UDPBROCASTSERVERWIDGET_H

#include "utilities/udpbrocastserver.h"
#include <QWidget>

namespace Ui {
class UdpBrocastServerWidget;
}

class UdpBrocastServerWidget : public QWidget {
  Q_OBJECT

public:
  explicit UdpBrocastServerWidget(QWidget *parent = nullptr);
  ~UdpBrocastServerWidget();

private slots:
  void on_pushButton_clicked();

private:
  Ui::UdpBrocastServerWidget *ui;
  UdpBrocastServer *server;
  int lock;
};

#endif // UDPBROCASTSERVERWIDGET_H
