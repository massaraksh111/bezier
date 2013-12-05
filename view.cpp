#include "view.h"

View::View(QWidget *parent) :
    QWidget(parent)
{
    repaint();
}

void View::paintEvent(QPaintEvent *event)
{
    QPainter canvas(this);
    canvas.setBrush(QBrush(Qt::white));

    canvas.drawRect(0, 0, width(), height());

    canvas.setBrush(QBrush(Qt::red));
    if(auto ptr = _bezierLine.lock())
    {
        ptr->paint(&canvas);
    }
}
