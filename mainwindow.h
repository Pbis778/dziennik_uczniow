#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QLabel>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QListWidget *listWidget;
    QLabel *schoolLogoLabel;
    QPushButton *calculateButton;
    QPushButton *addStudentButton;

private slots:
    void calculateAverages();
    void addStudentButton_clicked();
};
#endif // MAINWINDOW_H
