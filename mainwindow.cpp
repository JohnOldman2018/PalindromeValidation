#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <iostream>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    readFromFile("input.txt");
}

void MainWindow::writeToFile(QString writeLine, QString fileName)
{
    QFile outFile(fileName);
    if (!outFile.open(QIODevice::Append | QIODevice::Text)){
        qDebug() << "Cannot write to file.";
    }
    outFile.write(qPrintable(writeLine + "\n"));
    outFile.close();
}

void MainWindow::readFromFile(QString fileName) {
    char buf[1024];
    QString qsTemp;
    QFile inputFile(fileName);
    ui->label_5->setText("Palindromes from file " + fileName + " have been written to file output.txt");
    if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Can't open file" ;
    }
    while (!inputFile.atEnd()) {
        inputFile.readLine(buf, 1024);
        qsTemp = buf;
        qsTemp = qsTemp.trimmed();
        if (isPalindrome(qsTemp))  qsTemp =  "yes, it is a palindrome: " + qsTemp;
        else  qsTemp = "this is not a palindrome: " + qsTemp;
        ui->plainTextEdit->appendPlainText(qsTemp);
        writeToFile(qsTemp, "output.txt");
    }
}

bool MainWindow::isPalindrome(QString line)
{
       int j = line.size() - 1;
       for (int i = 0; i < line.size(); i++){
           if (line[i] == line[j]){
               j--;
               return true;
           } else return false;
       }
}
