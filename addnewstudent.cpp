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

AddNewStudent::~AddNewStudent()
{
    delete ui;
}

QString AddNewStudent::getStudentName() const
{
    return ui->nameLineEdit->text();
}

QString AddNewStudent::getStudentSurname() const
{
    return ui->surnameLineEdit->text();
}

double AddNewStudent::getGrade1() const
{
    return ui->grade1SpinBox->value();
}

double AddNewStudent::getGrade2() const
{
    return ui->grade2SpinBox->value();
}
