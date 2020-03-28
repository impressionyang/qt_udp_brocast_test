#include "udpbrocastclientwidget.h"
#include "ui_udpbrocastclientwidget.h"

UdpBrocastClientWidget::UdpBrocastClientWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::UdpBrocastClientWidget) {
  ui->setupUi(this);
  lock = 1;
}

UdpBrocastClientWidget::~UdpBrocastClientWidget() { delete ui; }

void UdpBrocastClientWidget::on_pushButton_clicked() {
  if (lock) {
    client = new UdpBrocastClient();
    connect(client, &UdpBrocastClient::getBrocastMsg, this, [=](QString msg) {
      //        this->ui->text.g
      ui->plantext->setPlainText(msg);
    });
  }
}
