#ifndef SINGLELINE_H
#define SINGLELINE_H

#include <QPointF>
#include <QList>

#include <memory>

class QPainter;
typedef std::shared_ptr<QPointF> QPointFPtr;

class SingleLine
{
    QList<QPointFPtr> _points;
public:
    SingleLine() { }
    SingleLine(const SingleLine& tail, float x, float y) { }

    int size() const { return _points.size(); }
    QPointF& operator[](int i) { return *_points[i]; }

    virtual bool add(float x, float y);

    virtual void paint(QPainter*) = 0;
};

#endif // SINGLELINE_H
