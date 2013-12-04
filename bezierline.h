#ifndef BEZIERLINE_H
#define BEZIERLINE_H

#include "singleline.h"

class BezierLine : public SingleLine
{
public:
    BezierLine();
    BezierLine(const SingleLine& tail, float x, float y);

    void paint(QPainter*);
};

#endif // BEZIERLINE_H
