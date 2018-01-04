#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_add_clicked();

    void on_remove_clicked();

    void on_insert_clicked();

private:
    Ui::MainWindow *ui;
    QList<int> m_list;
    QList<QString> m_str ;
    void initialisevalues();
    void printValues();
};

#endif // MAINWINDOW_H
