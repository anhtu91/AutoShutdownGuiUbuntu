#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include <QTimer>
#include <QDebug>
#include <QMessageBox>
#include <QProcess>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateCurrentTimeLCD();

    void on_btnSetTurnOffMinutes_clicked();

    void on_btnUnsetTurnOffMinutes_clicked();

    void on_btnSetTurnOffAt_clicked();

    void on_btnUnsetTurnOffAt_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
