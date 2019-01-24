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
    void on_pushButton_clicked();

private:
    void writeToFile(QString writeLine, QString fileName);
    void readFromFile(QString fileName);
    bool isPalindrome (QString line);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
