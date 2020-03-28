#include "udpbrocastserverwidget.h"
#include "ui_udpbrocastserverwidget.h"

UdpBrocastServerWidget::UdpBrocastServerWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::UdpBrocastServerWidget) {
  ui->setupUi(this);
  lock = 1;
}

UdpBrocastServerWidget::~UdpBrocastServerWidget() { delete ui; }

void UdpBrocastServerWidget::on_pushButton_clicked() {

  if (!ui->plainTextEdit->toPlainText().isEmpty() && lock) {
    server = new UdpBrocastServer(ui->plainTextEdit->toPlainText());
  }
}
