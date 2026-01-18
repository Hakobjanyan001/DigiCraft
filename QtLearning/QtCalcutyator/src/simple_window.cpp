#include "simple_window.h"
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QFont>

SimpleWindow::SimpleWindow(QWidget* parent) : QWidget(parent) {
	setWindowTitle("Calculator");
	setFixedSize(300, 400);

	display = new QLineEdit("0");
	display->setReadOnly(true);
	display->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
	display->setFont(QFont("Segoe UI", 32, QFont::Bold));
	display->setStyleSheet("background: #1a1a2e; color: white; padding: 12px; border: none;");

	grid = new QGridLayout(this);
	grid->setSpacing(8);
	grid->setContentsMargins(12, 12, 12, 12);
	grid->addWidget(display, 0, 0, 1, 4);

	createDigitButton("7", 1, 0);
	createDigitButton("8", 1, 1);
	createDigitButton("9", 1, 2);
	createDigitButton("4", 2, 0);
	createDigitButton("5", 2, 1);
	createDigitButton("6", 2, 2);
	createDigitButton("1", 3, 0);
	createDigitButton("2", 3, 1);
	createDigitButton("3", 3, 2);
	createDigitButton("0", 4, 0, 1, 2);
	createDigitButton(".", 4, 2);

	setLayout(grid);
}

void SimpleWindow::createDigitButton(const QString& text, int row, int column, int row_number, int coulumn_number){
	QPushButton* btn = new QPushButton(text, this);
	btn->setFont(QFont("Segoe UI", 20));
	btn->setFixedSize(70,70);
	btn->setStyleSheet("background: #2a2a4a; color: white; border-radius: 8px;");

	grid->addWidget(btn, row, column, row_number, coulumn_number);

	connect(btn, &QPushButton::clicked, this, [this, text](){
		digitClicked(text);		
	});
}

void SimpleWindow::digitClicked(const QString& digit) {
	QString current = display->text();

	if(digit == ".") {
		if(current.contains('.')) {
			return;
		}

		if(current.isEmpty() || current == "0") {
			display->setText("0.");
			return;
		}
		display->setText(current + ".");
		return;
	}

	if(current == "0" && digit != "0") {
		display->setText(digit);
	} else {
		display->setText(current + digit);
	}
}
