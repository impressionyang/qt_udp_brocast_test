#ifndef UDPBROCASTCLIENTWIDGET_H
#define UDPBROCASTCLIENTWIDGET_H

#include "utilities/udpbrocastclient.h"
#include <QString>
#include <QWidget>

namespace Ui {
class UdpBrocastClientWidget;
}

class UdpBrocastClientWidget : public QWidget {
  Q_OBJECT

public:
  explicit UdpBrocastClientWidget(QWidget *parent = nullptr);
  ~UdpBrocastClientWidget();

private slots:
  void on_pushButton_clicked();

private:
  Ui::UdpBrocastClientWidget *ui;
  UdpBrocastClient *client;
  int lock;
};

#endif // UDPBROCASTCLIENTWIDGET_H
