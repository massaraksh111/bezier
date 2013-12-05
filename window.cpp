#include "window.h"
#include "ui_window.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>

Window::Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);

    view = new View(this);

    ui->gridLayout->addWidget(view, 1, 0, 1, 2);
    connect(ui->openButton, SIGNAL(clicked()), SLOT(buttonClicked()));
}

Window::~Window()
{
    delete ui;
}

void Window::readFile()
{
    QString name = ui->fileName->text();
    if(name.isEmpty())
    {
        error("имя файла не может быть пустой строкой");
        return;
    }

    QFile file(name);

    if(file.open(QFile::ReadOnly))
    {
        QTextStream stream(&file);

        BezierLine line;

        float x, y;
        while(!line.full() && !stream.atEnd())
        {
            stream >> x >> y;
            line.add(x, y);
        }

        if(!line.full())
        {
            error("мало точек");
            return;
        }

        _bezierLine = std::make_shared< ComplexLine<BezierLine> >(line);

        while(!stream.atEnd())
        {
            stream >> x >> y;
            _bezierLine->add(x, y);
        }

        view->setData(_bezierLine);
    }
}

void Window::buttonClicked()
{
    QString name = "D:\\Projects\\cg\\lines\\test1.txt";
    //QString name = QFileDialog::getOpenFileName(this);
    if(!name.isEmpty())
        ui->fileName->setText(name);

    readFile();
}
