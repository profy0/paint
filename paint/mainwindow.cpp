#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ww = new widget(this);
    ui->verticalLayout->addWidget(ww);

    lb = new QLabel(this);
    lb->setText("Прямая линия");
    statusBar()->addWidget(lb);

}

void MainWindow::chechit()
{
    QMessageBox::warning(this, "Ошибка", "Вы не нарисовали ни одной фигуры!");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{

}

void MainWindow::closeEvent(QCloseEvent *)
{
    on_actionClose_triggered();
}


void MainWindow::on_actionOpen_triggered()
{

    ww->str = QFileDialog::getOpenFileName(0, tr("Open"), "","*.jpg ;; *.png ;; *.bmp");

}

void MainWindow::on_actionSave_triggered()
{
    QPixmap pix(ww->size());
    ww->render(&pix);
    QString strFilter;
    QString str = QFileDialog::getSaveFileName(0, tr("Save"), "Pixmap", "*.jpg ;; *.png ;; *.bmp", &strFilter);
    if (!str.isEmpty()) {
        if (strFilter.contains("jpg")) {
            pix.save(str, "JPG");
        } else
            if (strFilter.contains("bmp")) {
                pix.save(str, "BMP");
            } else {
                pix.save(str, "PNG");
            }
    }
}
void MainWindow::on_actionClose_triggered()
{
    if (QMessageBox::question(this, "Выход", "Сохранить файл перед выходом?",
                              QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes) == QMessageBox::Yes) {
        on_actionSave_triggered();
    }
    QApplication::quit();
}

void MainWindow::on_actionLine_triggered()
{
    ww->tp = 1;
    lb->setText("Прямая линия");
}

void MainWindow::on_actionCircle_triggered()
{
    ww->tp = 2;
    lb->setText("Круг");
}

void MainWindow::on_actionRectangle_triggered()
{
    ww->tp = 3;
    lb->setText("Прямоугольник");
}

void MainWindow::on_action_triggered()
{
    ww->brush = QColorDialog::getColor();
}

void MainWindow::on_actionPero_triggered()
{
    int x = QInputDialog::getInt(0, "Input" ,"Толщина пера:",0,0);
    ww->pen.setWidth(x);
}

void MainWindow::on_actionEditX_triggered()
{
    if(ww->vec.size()==0) {
        chechit();
        return;
    }
    int x = QInputDialog::getInt(0, "Input" ,"Координата x:",0,0);
    ww->vec.back().posx = (double)x/width();
    update();
}

void MainWindow::on_actionEditY_triggered()
{
    if(ww->vec.size()==0) {
        chechit();
        return;
    }
    int y = QInputDialog::getInt(0, "Input" ,"Координата y:",0,0);
    ww->vec.back().posy = (double)y/height();
    update();
}

void MainWindow::on_actionScaleX_triggered()
{
    if(ww->vec.size()==0) {
        chechit();
        return;
    }
    int x = QInputDialog::getInt(0, "Input" ,"Размер по x:",0,0);
    ww->vec.back().scalex = (double)x/width();
    update();
}

void MainWindow::on_actionScaleY_triggered()
{
    if(ww->vec.size()==0) {
        chechit();
        return;
    }
    int y = QInputDialog::getInt(0, "Input" ,"Размер по y:",0,0);
    ww->vec.back().scaley = (double)y/height();
    update();
}

void MainWindow::on_actionColor_triggered()
{
    if(ww->vec.size()==0) {
        chechit();
        return;
    }
    ww->vec.back().brush = QColorDialog::getColor();
    update();
}

void MainWindow::on_actionNPero_triggered()
{
    if(ww->vec.size()==0) {
        chechit();
        return;
    }
    int x = QInputDialog::getInt(0, "Input" ,"Толщина пера:",0,0);
    ww->vec.back().p.setWidth(x);
    update();
}
