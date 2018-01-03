#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initialisevalues();
}

void MainWindow::initialisevalues()
{
    for(int i=0;i<10; ++i)
        m_list.push_back(i);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printValues()
{
    ui->textedit->clear();
    for(int i=0; i<m_list.size(); ++i) {
        ui->textedit->append(QString::number(i));
    }
}

void MainWindow::on_add_clicked()
{

    m_list.push_back(m_list.size());
    printValues();

}

void MainWindow::on_remove_clicked()
{
    if(!m_list.empty())
    {
        m_list.pop_back();
        printValues();
    }
}
