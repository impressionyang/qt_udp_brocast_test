
#include "circlebutton.h"

/*
**************************************************************
 1. @ProjName:   graphics_test
 2. @Author:     impressionyang
 3. @Date:       2020-01-03
 4. @Brief:      File Description
**************************************************************
*/

CircleButton::CircleButton(QWidget *parent) : QWidget(parent) {

  setFixedSize(2 * radius + 4, 2 * radius + 4);
  //
  this->radius = 100;
  this->front_color = QColor(70, 184, 255);
  this->back_color = QColor(255, 255, 255);
  this->hover_color = QColor(71, 95, 255);
  this->click_color = QColor(2, 2, 171);
  this->text = QString("BUTTON");
  color_now = front_color;
  this->pen = new QPen();
  this->painter = new QPainter();
  update();
}

CircleButton::CircleButton(int radius, QString text, QWidget *parent)
    : QWidget((parent)) {

  setFixedSize(2 * radius + 4, 2 * radius + 4);

  this->radius = radius;
  this->front_color = QColor(70, 184, 255);
  this->back_color = QColor(255, 255, 255);
  this->hover_color = QColor(71, 95, 255);
  this->click_color = QColor(2, 2, 171);
  this->text = text;
  color_now = front_color;
  this->pen = new QPen();
  this->painter = new QPainter();
  update();
}

void CircleButton::setColor(QColor front, QColor back, QColor hover,
                            QColor press) {
  this->front_color = front;
  this->back_color = back;
  this->hover_color = hover;
  color_now = front;
  click_color = press;

  update();
}

void CircleButton::setText(QString text) {
  this->text = text;
  update();
}

void CircleButton::setRadius(int radius) {
  this->radius = radius;
  update();
}

void CircleButton::mousePressEvent(QMouseEvent *event) {
  emit clicked();
  this->color_now = click_color;
  update();
}

void CircleButton::mouseReleaseEvent(QMouseEvent *event) {
  this->color_now = hover_color;
  update();
}

void CircleButton::enterEvent(QEvent *event) {
  this->color_now = hover_color;
  update();
}

void CircleButton::leaveEvent(QEvent *event) {
  this->color_now = front_color;
  update();
}

void CircleButton::paintEvent(QPaintEvent *event) {
  //开始绘制
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing, true);
  QPen pen(color_now);
  painter.setPen(pen);
  QBrush brush(color_now, Qt::SolidPattern);
  painter.setBrush(brush);
  // drwaw ract
  QRect rectf(1, 1, 2 * radius + 1, 2 * radius + 1);
  int startangle = 0 * 16;
  int endangle = 120 * 16;
  //  painter.drawPie(rectf, startangle, endangle);
  painter.drawEllipse(rectf);

  // text

  QFont f = QFont("Noto", (2 * radius) / 7, QFont::Bold);
  painter.setFont(f);
  painter.setFont(f);
  pen.setColor(back_color);
  painter.setPen(pen);
  painter.drawText(0, (2 * radius) / 2 - (2 * radius) / 12, (2 * radius),
                   (2 * radius) / 6, Qt::AlignCenter, text);
}

//
