#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

#include "complexline.h"
#include "bezierline.h"
#include "view.h"

namespace Ui {
class Window;
}

class Window : public QWidget
{
    Q_OBJECT
    
    ComplexBezierPtr _bezierLine;

    View* view;

    void error(QString str)
    {}

public:
    explicit Window(QWidget *parent = 0);
    ~Window();
    
protected:

private slots:
    void readFile();

    void buttonClicked();

private:
    Ui::Window *ui;
};

#endif // WINDOW_H
