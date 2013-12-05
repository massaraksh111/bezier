#ifndef SINGLELINE_H
#define SINGLELINE_H

#include <QPointF>
#include <QList>
#include <QPen>

#include <memory>

class QPainter;
typedef std::shared_ptr<QPointF> QPointFPtr;

class SingleLine
{
protected:
    QList<QPointFPtr> _points;

    virtual QPen linePen() = 0;
    virtual QPen framePen() = 0;

public:
    SingleLine() { }
    SingleLine(const SingleLine& tail) { _points = tail._points; }
    virtual ~SingleLine() { }

    int size() const { return _points.size(); }
    QPointF& operator[](int i) { return *_points[i]; }

    virtual bool add(float x, float y);
    virtual bool full() const = 0;

    virtual void paint(QPainter*) = 0;
};

#endif // SINGLELINE_H
