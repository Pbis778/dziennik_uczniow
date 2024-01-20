#include "addnewstudent.h"
#include "ui_addnewstudent.h"

AddNewStudent::AddNewStudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewStudent)
{
    ui->setupUi(this);

    connect(ui->okButton, &QPushButton::clicked, this, &AddNewStudent::accept);
    connect(ui->cancelButton, &QPushButton::clicked, this, &AddNewStudent::reject);
}

AddNewStudent::~AddNewStudent() {
    delete ui;
}

QString AddNewStudent::getStudentName() const {
    return ui->nameLineEdit->text();
}

QString AddNewStudent::getStudentSurname() const {
    return ui->surnameLineEdit->text();
}

int AddNewStudent::getGrade1() const {
    int grade = ui->grade1SpinBox->value();
    return (grade >= 1 && grade <= 6) ? grade : 1;
}

int AddNewStudent::getGrade2() const {
    int grade = ui->grade2SpinBox->value();
    return (grade >= 1 && grade <= 6) ? grade : 1;
}
