#ifndef BEZIERLINE_H
#define BEZIERLINE_H

#include "singleline.h"

class BezierLine : public SingleLine
{
protected:
    QPen linePen();
    QPen framePen();

public:
    BezierLine();
    BezierLine(const SingleLine& tail, float x, float y);

    bool full() const;

    void paint(QPainter*);
};

#endif // BEZIERLINE_H
