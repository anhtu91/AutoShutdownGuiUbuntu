#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateCurrentTimeLCD()));
    timer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateCurrentTimeLCD()
{
    QDateTime dateTime = QDateTime::currentDateTime();
    QString currentTimeText = dateTime.toString("hh:mm:ss");
    ui->lbCurrentTime->setText(currentTimeText);
    //qDebug()<<currentTimeText;

    QString currentDateText = dateTime.toString("dd-MM-yyyy");
    ui->lbCurrentDate->setText(currentDateText);
}


void MainWindow::on_btnSetTurnOffMinutes_clicked()
{
    QMessageBox msgBox;
    QProcess process;
    int setMinutes = ui->sbTurnOffMinutes->value();
    process.startDetached("shutdown -h "+QString::number(setMinutes));
    msgBox.setText("Turn off PC after "+QString::number(setMinutes)+" minutes!");
    msgBox.exec();
}

void MainWindow::on_btnUnsetTurnOffMinutes_clicked()
{
    QMessageBox msgBox;
    QProcess process;
    process.startDetached("shutdown -c");
    msgBox.setText("Cancel shutdown plan");
    msgBox.exec();
}

void MainWindow::on_btnSetTurnOffAt_clicked()
{
    QMessageBox msgBox;
    QProcess process;
    int setHours = ui->sbHour->value();
    int setMinutes = ui->sbMinute->value();
    process.startDetached("shutdown -h "+QString::number(setHours)+":"+QString::number(setMinutes));
    msgBox.setText("Turn off PC at "+QString::number(setHours)+":"+QString::number(setMinutes));
    msgBox.exec();
}

void MainWindow::on_btnUnsetTurnOffAt_clicked()
{
    QMessageBox msgBox;
    QProcess process;
    process.startDetached("shutdown -c");
    msgBox.setText("Cancel shutdown plan");
    msgBox.exec();
}
