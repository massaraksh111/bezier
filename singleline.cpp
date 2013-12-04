#include "singleline.h"

bool SingleLine::add(float x, float y)
{
    if(_points.size() == 3)
        return false;

    _points.push_back(std::make_shared<QPointFPtr>(x, y));
    return true;
}
