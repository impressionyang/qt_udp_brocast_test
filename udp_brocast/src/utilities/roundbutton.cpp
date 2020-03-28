#include "roundbutton.h"

RoundButton::RoundButton(int width, int height, QString text, QWidget *parent)
    : QWidget(parent) {

  this->width = width;
  this->height = height;
  this->text = text;
  this->front_color = QColor(70, 184, 255);
  this->back_color = QColor(255, 255, 255);
  this->hover_color = QColor(71, 95, 255);
  this->press_color = QColor(2, 2, 171);
  now_color = front_color;
  setFixedSize(width, height);
}

void RoundButton::setText(QString text) {
  this->text = text;
  update();
}

void RoundButton::mousePressEvent(QMouseEvent *event) {
  emit clicked();
  this->now_color = press_color;
  update();
}

void RoundButton::mouseReleaseEvent(QMouseEvent *event) {
  this->now_color = hover_color;
  update();
}

void RoundButton::enterEvent(QEvent *event) {
  this->now_color = hover_color;
  update();
}

void RoundButton::leaveEvent(QEvent *event) {
  this->now_color = front_color;
  update();
}
void RoundButton::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  QPen pen(now_color);
  painter.setRenderHint(QPainter::Antialiasing, true);

  // draw button body
  pen.setColor(now_color);
  pen.setCapStyle(Qt::RoundCap);
  pen.setWidth(this->height - 2);
  painter.setPen(pen);
  painter.drawLine(height / 2 + 1, height / 2, this->width - (height / 2) - 1,
                   height / 2);

  // draw text
  //  float progress = abs((value * 100) / (360 * 16));
  //  QString pre_num = QString::number(progress);
  QFont f = QFont("Noto", height / 4, QFont::Bold);
  pen.setColor(back_color);
  painter.setPen(pen);
  painter.setFont(f);
  painter.setFont(f);
  painter.drawText(height / 4, 2, width - height / 2, height - 4,
                   Qt::AlignCenter, text);
}
