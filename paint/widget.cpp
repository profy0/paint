#include "widget.h"



widget::widget(QWidget *parent) : QWidget(parent)
{

    ok = 0;
    brush = Qt::white;
    tp = 1;

}

void widget::paintEvent(QPaintEvent *)
{
    img.load(str);
    QPainter painter;
    painter.begin(this);
    img = img.scaled(width(),height());
    painter.drawImage(0, 0, img);

    for(auto now : vec) {
        painter.setBrush(now.brush);
        painter.setPen(now.p);
        if(now.type==1) {
            painter.drawLine(now.posx*width(),now.posy*height(),now.scalex*width(),now.scaley*height());
        }
        if(now.type==2) {
            painter.drawEllipse(now.posx*width(),now.posy*height(),now.scalex*width(),now.scaley*height());
        }
        if(now.type==3) {
            painter.drawRect(now.posx*width(),now.posy*height(),now.scalex*width(),now.scaley*height());
        }
    }

    if(!ok) {
        painter.setBrush(brush);
        painter.setPen(pen);
        if(tp==1) {
            painter.drawLine(t.posx*width(), t.posy*height(), t.scalex*width(), t.scaley*height());
        }
        if(tp==2) {
            painter.drawEllipse(t.posx*width(), t.posy*height(), t.scalex*width(), t.scaley*height());
        }
        if(tp==3) {
            painter.drawRect(t.posx*width(), t.posy*height(), t.scalex*width(), t.scaley*height());
        }
    }



    painter.end();

}

void widget::mousePressEvent(QMouseEvent *eventPress)
{
    QPoint pp = eventPress->pos();
    x = pp.rx();
    y = pp.ry();
    ok = 0;

}

void widget::mouseMoveEvent(QMouseEvent *eventMove)
{
    QPoint pp = eventMove->pos();
    xx = pp.rx();
    yy = pp.ry();
    t.posx = (double)x/width();
    t.posy = (double)y/height();
    if(tp==1) {
        t.scalex = (double)(xx)/width();
        t.scaley = (double)(yy)/height();
    } else {
        t.scalex = (double)(xx-x)/width();
        t.scaley = (double)(yy-y)/height();
    }


    update();


}

void widget::mouseReleaseEvent(QMouseEvent *eventRelease)
{
    t.brush = brush;
    t.p = pen;
    t.type = tp;
    vec.push_back(t);
    ok = 1;
}


