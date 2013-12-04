#include "bezierline.h"

#include <QPainter>

BezierLine::BezierLine() : SingleLine() {}
BezierLine::BezierLine(const SingleLine& tail, float x, float y) : SingleLine(tail, x, y)
{
    _points = tail._points;
    _points = std::make_shared<QPointFPtr>(x, y);
}

void BezierLine::paint(QPainter*)
{


}
