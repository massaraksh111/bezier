#include "singleline.h"

bool SingleLine::add(float x, float y)
{
    _points.push_back(std::make_shared<QPointF>(x, y));
    return true;
}
