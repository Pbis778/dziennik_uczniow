#ifndef ADDNEWSTUDENT_H
#define ADDNEWSTUDENT_H

#include <QDialog>

namespace Ui {
class AddNewStudent;
}

class AddNewStudent : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewStudent(QWidget *parent = nullptr);
    ~AddNewStudent();

    QString getStudentName() const;
    QString getStudentSurname() const;
    double getGrade1() const;
    double getGrade2() const;

private:
    Ui::AddNewStudent *ui;
};
#endif
