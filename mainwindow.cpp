#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Настройка таблицы из интерфейса
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);

    // Подключение кнопки загрузки
    connect(ui->loadButton, &QPushButton::clicked, this, &MainWindow::onLoadCSV);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onLoadCSV() {
    // Укажите путь к файлу CSV здесь
    QString filePath = "C:/Qt projects/AutoService/AutoParts.csv"; // Замените на ваш путь

    // Проверяем, существует ли файл
    if (!QFile::exists(filePath)) {
        QMessageBox::warning(this, "Ошибка", "Файл не найден!");
        return;
    }

    loadCSV(filePath);
}

void MainWindow::loadCSV(const QString &filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл!");
        return;
    }

    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(0);

    QTextStream stream(&file);
    int row = 0;

    while (!stream.atEnd()) {
        QString line = stream.readLine();
        QStringList values = line.split(","); // Разделитель запятая

        if (ui->tableWidget->columnCount() < values.size()) {
            ui->tableWidget->setColumnCount(values.size());
        }

        ui->tableWidget->insertRow(row);
        for (int col = 0; col < values.size(); ++col) {
            ui->tableWidget->setItem(row, col, new QTableWidgetItem(values[col].trimmed()));
        }
        ++row;
    }

    file.close();
}

void MainWindow::on_centralwidget_customContextMenuRequested(const QPoint &pos)
{

}

