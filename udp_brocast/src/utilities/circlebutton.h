/*
**************************************************************
 1. @ProjName:   graphics_test
 2. @Author:     impressionyang
 3. @Date:       2020-01-03
 4. @Brief:      File Description
**************************************************************
*/
#ifndef CIRCLEBUTTON_H
#define CIRCLEBUTTON_H

#include <QBrush>
#include <QColor>
#include <QPainter>
#include <QPen>
#include <QRectF>
#include <QWidget>

class CircleButton : public QWidget {
  Q_OBJECT
public:
  //按钮的私有方法
  explicit CircleButton(QWidget *parent = nullptr);
  explicit CircleButton(int radius, QString text, QWidget *parent = nullptr);

  //设置颜色
  void setColor(QColor front, QColor back, QColor hover, QColor press);
  //设置文字
  void setText(QString text);
  //设置半径
  void setRadius(int radius);

private:
  //按钮的属性
  //半径
  int radius;
  //前景色
  QColor front_color;
  //背景色
  QColor back_color;
  // hover color
  QColor hover_color;
  // click color
  QColor click_color;
  // right now color
  QColor color_now;
  // inner text
  QString text;
  // Pen
  QPen *pen;
  // Painter;
  QPainter *painter;
  // brush
  QBrush *brush;

signals:
  //按下的信号
  void clicked();

protected:
  //鼠标进入事件
  void enterEvent(QEvent *event) override;
  //鼠标离开事件
  void leaveEvent(QEvent *event) override;
  //鼠标按下事件
  void mousePressEvent(QMouseEvent *event) override;
  // release
  void mouseReleaseEvent(QMouseEvent *event) override;
  //绘制事件
  void paintEvent(QPaintEvent *event) override;
};

#endif // CIRCLEBUTTON_H
