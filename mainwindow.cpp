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

    QPixmap schoolLogo("C:/Users/pbist/OneDrive/Pulpit/przyk_kolT0B/dziennik_uczniow/logo.png");
    if (schoolLogo.isNull()) {
        qDebug() << "Błąd ładowania pliku zasobu logo.png";
    } else {
        schoolLogoLabel->setPixmap(schoolLogo);
    }

    connect(calculateButton, &QPushButton::clicked, this, &MainWindow::calculateAverages);
    connect(addStudentButton, &QPushButton::clicked, this, &MainWindow::addStudentButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculateAverages() {
    if (listWidget->count() == 0) {
        QMessageBox::information(this, "Informacja", "Lista studentów jest pusta");
        return;
    }

    double sumGrade1 = 0.0;
    double sumGrade2 = 0.0;
    int numberOfStudents = listWidget->count();

    for (int i=0; i< numberOfStudents; i++) {
        QString studentInfo = listWidget->item(i)->text();
        QStringList parts = studentInfo.split(" - Oceny: ");
        QStringList grades = parts[1].split(", ");

        sumGrade1 += grades[0].toDouble();
        sumGrade2 += grades[1].toDouble();
    }

    double averageGrade1 = sumGrade1 / numberOfStudents;
    double averageGrade2 = sumGrade2 / numberOfStudents;

    QString resultMessage = QString("Średnia z oceny 1: %1\nŚrednia z oceny 2: %2")
                                .arg(averageGrade1, 0, 'f', 2)
                                .arg(averageGrade2, 0, 'f', 2);
    QMessageBox::information(this, "Wyniki obliczeń: ", resultMessage);

    listWidget->sortItems(Qt::AscendingOrder);
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
        listWidget->sortItems(Qt::AscendingOrder);
    }
}
