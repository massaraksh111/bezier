#ifndef COMPLEXLINE_H
#define COMPLEXLINE_H

#include <QPainter>
#include <QList>

#include "singleline.h"
#include "bezierline.h"

template<class Line>
class ComplexLine
{
    QList<Line> _line;
public:
    ComplexLine(const Line& line)
    {
        _line.push_back(line);
    }

    void add(float x, float y)
    {
        _line.push_back(Line(_line.back(), x, y));
    }

    void paint(QPainter* canvas)
    {
        for(Line& l :_line)
        {
            l.paint(canvas);
        }
    }
};

typedef std::shared_ptr<ComplexLine<BezierLine>> ComplexBezierPtr;

#endif // COMPLEXLINE_H
