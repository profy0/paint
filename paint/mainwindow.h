#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "widget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void chechit();
    ~MainWindow();
protected:
    void paintEvent(QPaintEvent*) override;
    void closeEvent(QCloseEvent*) override;

private slots:
    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionClose_triggered();

    void on_actionLine_triggered();

    void on_actionCircle_triggered();

    void on_actionRectangle_triggered();

    void on_action_triggered();

    void on_actionPero_triggered();

    void on_actionEditX_triggered();

    void on_actionEditY_triggered();

    void on_actionScaleX_triggered();

    void on_actionScaleY_triggered();

    void on_actionColor_triggered();

    void on_actionNPero_triggered();

private:
    Ui::MainWindow *ui;
    widget *ww;
    QLabel *lb;
};
#endif // MAINWINDOW_H
