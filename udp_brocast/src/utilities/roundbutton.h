#ifndef ROUNDBUTTON_H
#define ROUNDBUTTON_H

#include <QColor>
#include <QPainter>
#include <QPen>
#include <QWidget>

class RoundButton : public QWidget {
  Q_OBJECT
public:
  explicit RoundButton(int width, int height, QString text,
                       QWidget *parent = nullptr);

  void setText(QString text);

private:
  //圆角按钮属性
  //高度
  int height;
  //宽度
  int width;
  //前景色
  QColor front_color;
  //背景色
  QColor back_color;
  //按下色
  QColor press_color;
  //浮动色
  QColor hover_color;
  //当前色
  QColor now_color;
  //文字
  QString text;

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

#endif // ROUNDBUTTON_H
