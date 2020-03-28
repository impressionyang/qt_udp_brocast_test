#ifndef UDPCHOOSER_H
#define UDPCHOOSER_H

#include <QWidget>
#include <udpbrocastclientwidget.h>
#include <udpbrocastserverwidget.h>

namespace Ui {
class UdpChooser;
}

class UdpChooser : public QWidget {
  Q_OBJECT

public:
  explicit UdpChooser(QWidget *parent = nullptr);
  ~UdpChooser();

private slots:
  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

private:
  Ui::UdpChooser *ui;
};

#endif // UDPCHOOSER_H
