#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Устанавливаем название окна программы
    this->setWindowTitle("AutoServiceAPP");

    // Настройка таблицы из интерфейса
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);

    // Подключение кнопки загрузки
    connect(ui->loadButton, &QPushButton::clicked, this, &MainWindow::onLoadCSV);
    connect(ui->saveButton, &QPushButton::clicked, this, &MainWindow::onSaveCSV);
}

MainWindow::~MainWindow() {
    delete ui;
}

// Слот onLoadCSV
void MainWindow::onLoadCSV() {
    // Укажите путь к файлу CSV здесь
    QString openFilePath = this->ui->lineFilePath->text();

    // Проверяем, существует ли файл
    if (!QFile::exists(openFilePath)) {
        QMessageBox::warning(this, "Ошибка", "Файл не найден!");
        return;
    }

    loadCSV(openFilePath);
}

void MainWindow::onSaveCSV() {
    // Получаем путь для сохранения файла из виджета
    QString saveFilePath = this->ui->lineSaveFilePath->text();

    // Проверяем, указан ли путь к файлу
    if (saveFilePath.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, укажите путь для сохранения файла!");
        return;
    }

    QFile file(saveFilePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл для записи!");
        return;
    }

    QTextStream stream(&file);
    stream.setEncoding(QStringConverter::Utf8);

    // Сохранение данных из QTableWidget в файл
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        QStringList rowValues;
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            QTableWidgetItem *item = ui->tableWidget->item(row, col);
            rowValues.append(item ? item->text() : ""); // Если ячейка пустая, добавляем пустую строку
        }
        stream << rowValues.join(",") << "\n"; // Разделитель - запятая
    }

    file.close();
    QMessageBox::information(this, "Успех", "Файл успешно сохранён по указанному пути!");
}

void MainWindow::loadCSV(const QString &openFilePath) {
    QFile file(openFilePath);
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

