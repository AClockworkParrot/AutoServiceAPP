#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QStringList>

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

private slots:
    void onLoadCSV(); // Слот для загрузки CSV файла
    void onSaveCSV();
    void on_centralwidget_customContextMenuRequested(const QPoint &pos);
    void onSortAscending();
    void onSortDescending();
    void onSearch();
    void onHeadingStateChanged(int state);
    void restoreHeaderRow();
    void onAddRow();
    void onAddColumn();

private:
    Ui::MainWindow *ui;
    QTableWidget *tableWidget;
    QPushButton *loadButton;

    void loadCSV(const QString &filePath);
};
#endif // MAINWINDOW_H
