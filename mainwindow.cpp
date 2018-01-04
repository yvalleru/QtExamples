#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qstandarditemmodel.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initialisevalues();
    m_list.append(2);
    m_list.append(3);
    m_list.append(5);
    printValues();
}

void MainWindow::initialisevalues()
{
    m_list.reserve(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printValues()
{
    ui->log->append(tr("New list contents:"));
    QString line;
    for(int i=0; i<m_list.size(); ++i)
    {
        line.append(QString::number(m_list.at(i)));
        if (i < (m_list.size() - 1)) {
            line.append(", ");
        }
    }
    ui->log->append("[ " + line + " ]");
}

void MainWindow::on_add_clicked()
{
    m_list.push_back(m_list.size());
    printValues();
}

void MainWindow::on_remove_clicked()
{
   qDeleteAll(ui->listWidget->selectedItems());
   QString listl = ui->listWidget->selectedItems().front()->text();
    m_list.removeAt(m_list.contains(listl.toInt()));

}



void MainWindow::on_insert_clicked()
{
    if ( (0 < (ui->index->value()) && (ui->index->value()) < (m_list.size()+1) )){

        m_list.insert(ui->index->value(),ui->number->value());

        ui->log->append(tr("Adding number %1 to list at position %2")
                        .arg(ui->number->value()).arg(ui->index->value()));
        printValues();
    } else {
        ui->log->append(tr("out of order"));
    }
}
