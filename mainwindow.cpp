#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addnewstudent.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    listWidget = ui->listWidget;
    schoolLogoLabel = ui->schoolLogoLabel;
    calculateButton = ui->calculateButton;
    addStudentButton = ui->addStudentButton;

    connect(calculateButton, &QPushButton::clicked, this, &MainWindow::calculateAverages);
    connect(addStudentButton, &QPushButton::clicked, this, &MainWindow::addStudentButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculateAverages() {

}

void MainWindow::addStudentButton_clicked() {
    AddNewStudent addNewStudent;

    if (addNewStudent.exec() == QDialog::Accepted) {
        QString studentInfo = QString("%1 %2 - Oceny: %3, %4")
                                  .arg(addNewStudent.getStudentName())
                                  .arg(addNewStudent.getStudentSurname())
                                  .arg(addNewStudent.getGrade1())
                                  .arg(addNewStudent.getGrade2());
        listWidget->addItem(studentInfo);
    }
}
