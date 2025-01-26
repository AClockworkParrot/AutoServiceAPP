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

    // Подключение чекбокса заголовка
    connect(ui->headingCheckBox, &QCheckBox::checkStateChanged, this, &MainWindow::onHeadingStateChanged);

    // Подключение кнопок добавления строк и столбцов
    connect(ui->addRowButton, &QPushButton::clicked, this, &MainWindow::onAddRow);
    connect(ui->addColumnButton, &QPushButton::clicked, this, &MainWindow::onAddColumn);

    // Подключение кнопок удаления строк и столбцов
    connect(ui->delRowButton, &QPushButton::clicked, this, &MainWindow::onDelRow);
    connect(ui->delColumnButton, &QPushButton::clicked, this, &MainWindow::onDelColumn);

    // Устанавливаем пресет таблицы
    setTablePreset();
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
    int headerRow = ui->headingCheckBox->isChecked() ? 0 : 1; // Если включен заголовок, пропускаем первую строку
    ui->tableWidget->sortItems(column, Qt::AscendingOrder);
    if (headerRow == 1) {
        restoreHeaderRow(); // Восстанавливаем заголовок после сортировки
    }
}
// Сортировка по убыванию
void MainWindow::onSortDescending() {
    int column = ui->tableWidget->currentColumn(); // Получаем текущий выбранный столбец
    if (column == -1) {
        QMessageBox::warning(this, "Ошибка", "Выберите столбец для сортировки!");
        return;
    }
    int headerRow = ui->headingCheckBox->isChecked() ? 1 : 0; // Если включен заголовок, пропускаем первую строку
    ui->tableWidget->sortItems(column, Qt::DescendingOrder);
    if (headerRow == 1) {
        restoreHeaderRow(); // Восстанавливаем заголовок после сортировки
    }
}

void MainWindow::onSearch() {
    QString query = ui->lineSearch->text().trimmed(); // Получаем строку поиска

    if (query.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите текст для поиска!");
        return;
    }

    int rowCount = ui->tableWidget->rowCount();
    int colCount = ui->tableWidget->columnCount();
    bool found = false;

    // Начинаем поиск с позиции + 1
    int startRow = lastSearchRow;
    int startCol = lastSearchCol + 1;

    for (int row = startRow; row < rowCount; ++row) {
        for (int col = (row == startRow ? startCol : 0); col < colCount; ++col) {
            QTableWidgetItem *item = ui->tableWidget->item(row, col);
            if (item && item->text().contains(query, Qt::CaseInsensitive)) {
                // Устанавливаем найденную ячейку как текущую
                ui->tableWidget->setCurrentCell(row, col);
                lastSearchRow = row;
                lastSearchCol = col;
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (!found) {
        // Сбрасываем поиск, если ничего не найдено
        QMessageBox::information(this, "Результаты поиска", "Больше совпадений не найдено.");
        lastSearchRow = -1;
        lastSearchCol = -1;
    }
}


// Обработка изменения состояния чекбокса заголовка
void MainWindow::onHeadingStateChanged(int state) {
    if (state == Qt::Checked) {
        QStringList columnLabels;

        // Извлекаем значения из первой строки
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            QTableWidgetItem *item = ui->tableWidget->takeItem(0, col);
            columnLabels.append(item ? item->text() : QString(""));
        }

        ui->tableWidget->setHorizontalHeaderLabels(columnLabels);
        ui->tableWidget->removeRow(0); // Удаляем первую строку
    } else {
        QStringList columnLabels;
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            QTableWidgetItem *headerItem = ui->tableWidget->horizontalHeaderItem(col);
            columnLabels.append(headerItem ? headerItem->text() : QString(""));
        }

        // Добавляем значения заголовка в первую строку
        ui->tableWidget->insertRow(0);
        for (int col = 0; col < columnLabels.size(); ++col) {
            ui->tableWidget->setItem(0, col, new QTableWidgetItem(columnLabels[col]));
        }

        // Сбрасываем заголовки столбцов
        for (int col = 0; col < columnLabels.size(); ++col) {
            columnLabels[col] = "";
        }
        ui->tableWidget->setHorizontalHeaderLabels(columnLabels);
    }
}

// Восстановление заголовка после сортировки
void MainWindow::restoreHeaderRow() {
    QList<QTableWidgetItem *> headerItems;

    for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
        QTableWidgetItem *item = ui->tableWidget->takeItem(0, col);
        if (item) {
            headerItems.append(item);
        }
    }

    ui->tableWidget->removeRow(0);
    ui->tableWidget->insertRow(0);

    for (int col = 0; col < headerItems.size(); ++col) {
        ui->tableWidget->setItem(0, col, headerItems[col]);
    }
}


// Добавление новой строки
void MainWindow::onAddRow() {
    int currentRowCount = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(currentRowCount);
}

// Добавление нового столбца
void MainWindow::onAddColumn() {
    int currentColumnCount = ui->tableWidget->columnCount();
    ui->tableWidget->insertColumn(currentColumnCount);
}

void MainWindow::onDelRow() {
    int currentRow = ui->tableWidget->currentRow(); // Получить индекс выбранной строки
    if (currentRow >= 0) { // Проверка, что строка выбрана
        ui->tableWidget->removeRow(currentRow);
    }
}

void MainWindow::onDelColumn() {
    int currentColumn = ui->tableWidget->currentColumn(); // Получить индекс выбранного столбца
    if (currentColumn >= 0) { // Проверка, что столбец выбран
        ui->tableWidget->removeColumn(currentColumn);
    }
}

// Функция пресета таблицы для примера
void MainWindow::setTablePreset() {
    QString data =
        "Запчасть,Остаток на складе,PN,SN,Стоимость\n"
        "Глушитель,15,12A3456BCE,123-675,150\n"
        "Дрыгатель,8,45B7890DEF,987-345,3500\n"
        "Фильтр воздушный,20,78C2345GHI,567-123,500\n"
        "Масляный насос,12,67D8901JKL,321-765,4500\n"
        "Тормозной диск,25,56E1234MNO,765-432,1200\n"
        "Ремень ГРМ,10,23F4567PQR,234-678,750\n"
        "Карбулятор,5,90G6789STU,876-543,3200\n"
        "Шаровая опора,18,89H0123VWX,456-987,900\n"
        "Генератор,7,34I5678YZA,654-321,5000\n"
        "Свеча зажигания,40,12J8901BCD,789-012,300\n"
        "Радиатор,9,78K2345EFG,321-876,4000\n"
        "Топливный насос,6,67L3456HIJ,654-789,2500\n"
        "Ступица колеса,15,23M5678KLM,567-234,1800\n"
        "Амортизатор,20,45N7890NOP,987-456,2200\n"
        "Подшипник,30,90O1234QRS,876-654,1200\n"
        "Пыльник ШРУС,50,12P3456TUV,234-123,400";

    // Разбиваем данные на строки
    QStringList rows = data.split("\n");

    // Устанавливаем количество строк и столбцов
    ui->tableWidget->setRowCount(rows.size());
    ui->tableWidget->setColumnCount(rows.first().split(",").size());

    // Устанавливаем заголовки для столбцов (первая строка данных)
    QStringList headers = rows.first().split(",");
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    // Заполняем таблицу данными
    for (int row = 1; row < rows.size(); ++row) { // Начинаем с 1, так как 0 — это заголовки
        QStringList cells = rows[row].split(",");
        for (int col = 0; col < cells.size(); ++col) {
            ui->tableWidget->setItem(row - 1, col, new QTableWidgetItem(cells[col].trimmed()));
        }
    }
}



void MainWindow::on_centralwidget_customContextMenuRequested(const QPoint &pos)
{

}

