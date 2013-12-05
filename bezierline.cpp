#include "bezierline.h"

#include <QPainter>

BezierLine::BezierLine() : SingleLine() {}
BezierLine::BezierLine(const SingleLine& tail, float x, float y) : SingleLine(tail)
{
    for(int i = 1; i < _points.size(); i++)
        _points[i-1] = _points[i];

    _points[_points.size()-1] = std::make_shared<QPointF>(x, y);
}

bool BezierLine::full() const
{
    return _points.size() == 4;
}

void BezierLine::paint(QPainter* canvas)
{
    canvas->setPen(linePen());
    canvas->drawLine(*_points[0], *_points[1]);
    canvas->drawLine(*_points[1], *_points[2]);
    canvas->drawLine(*_points[2], *_points[3]);
}


QPen BezierLine::linePen()
{
    static QPen pen(QBrush(Qt::blue), 5.0);

    return pen;
}

QPen BezierLine::framePen()
{
    static QPen pen(QColor(Qt::red), 5);

    return pen;
}
