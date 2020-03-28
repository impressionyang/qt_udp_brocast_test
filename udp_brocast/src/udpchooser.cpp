#include "udpchooser.h"
#include "ui_udpchooser.h"

UdpChooser::UdpChooser(QWidget *parent)
    : QWidget(parent), ui(new Ui::UdpChooser) {
  ui->setupUi(this);
}

UdpChooser::~UdpChooser() { delete ui; }

void UdpChooser::on_pushButton_clicked() {
  UdpBrocastServerWidget *server = new UdpBrocastServerWidget();
  server->show();
  this->setVisible(false);
}

void UdpChooser::on_pushButton_2_clicked() {
  UdpBrocastClientWidget *client = new UdpBrocastClientWidget();
  client->show();
  this->setVisible(false);
}
