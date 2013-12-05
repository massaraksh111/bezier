#ifndef VIEW_H
#define VIEW_H

#include <QWidget>

#include <memory>

#include "complexline.h"

class View : public QWidget
{
    Q_OBJECT

    std::weak_ptr<ComplexLine<BezierLine>> _bezierLine;

public:
    explicit View(QWidget *parent = 0);
    
    void setData(ComplexBezierPtr ptr) { _bezierLine = ptr; update(); }

protected:
    void paintEvent(QPaintEvent * event);

};

#endif // VIEW_H
