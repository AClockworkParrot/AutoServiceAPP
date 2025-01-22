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
    // Подключение кнопок сортировки
    connect(ui->sortAscButton, &QPushButton::clicked, this, &MainWindow::onSortAscending);
    connect(ui->sortDescButton, &QPushButton::clicked, this, &MainWindow::onSortDescending);

    // Подключение кнопки поиска
    connect(ui->searchButton, &QPushButton::clicked, this, &MainWindow::onSearch);
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

// Сортировка по возрастанию
void MainWindow::onSortAscending() {
    int column = ui->tableWidget->currentColumn(); // Получаем текущий выбранный столбец
    if (column == -1) {
        QMessageBox::warning(this, "Ошибка", "Выберите столбец для сортировки!");
        return;
    }
    ui->tableWidget->sortItems(column, Qt::AscendingOrder);
}

// Сортировка по убыванию
void MainWindow::onSortDescending() {
    int column = ui->tableWidget->currentColumn(); // Получаем текущий выбранный столбец
    if (column == -1) {
        QMessageBox::warning(this, "Ошибка", "Выберите столбец для сортировки!");
        return;
    }
    ui->tableWidget->sortItems(column, Qt::DescendingOrder);
}

// Поиск строки в таблице
void MainWindow::onSearch() {
    QString query = ui->lineSearch->text().trimmed(); // Получаем строку поиска

    if (query.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите текст для поиска!");
        return;
    }

    bool found = false;

    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            QTableWidgetItem *item = ui->tableWidget->item(row, col);
            if (item && item->text().contains(query, Qt::CaseInsensitive)) {
                ui->tableWidget->setCurrentCell(row, col);
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (!found) {
        QMessageBox::information(this, "Результаты поиска", "Строка не найдена.");
    }
}


void MainWindow::on_centralwidget_customContextMenuRequested(const QPoint &pos)
{

}

