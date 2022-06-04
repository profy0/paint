#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtWidgets>

struct node {
    double posx, posy, scalex, scaley;
    int type;
    QColor brush;
    QPen p;
   // node(int posx, int posy, int scalex, int scaley) : posx(posx), posy(posy),scalex(scalex),scaley(scaley) {}
   // node(){}
};

class widget : public QWidget
{
    Q_OBJECT
public:

    explicit widget (QWidget *parent = 0);
    QImage img;
    int x,y,xx,yy,tp;
    QString str;
   // std::set <std::pair<std::pair<int,int>,std::pair<int,int> > > st;
  //  std::set <node> st;
    QVector <node> vec;
    bool ok, add;
    node t;
    QColor brush;
    QPen pen;

protected:
    void paintEvent(QPaintEvent *) override;
    void mousePressEvent(QMouseEvent *eventPress) override;
    void mouseMoveEvent(QMouseEvent *eventMove) override;
    void mouseReleaseEvent(QMouseEvent *eventRelease) override;


};

#endif // WIDGET_H
