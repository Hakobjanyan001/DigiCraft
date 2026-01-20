#include "simple_window.h"
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QFont>

SimpleWindow::SimpleWindow(QWidget* parent) : QWidget(parent) {
	setWindowTitle("Calculator");
	setFixedSize(350, 450);

	display = new QLineEdit("0");
	display->setReadOnly(true);
	display->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
	display->setFont(QFont("Segoe UI", 32, QFont::Bold));
	display->setStyleSheet("background: #1a1a2e; color: white; padding: 12px; border: none;");

	grid = new QGridLayout(this);
	grid->setSpacing(8);
	grid->setContentsMargins(12, 12, 12, 12);
	grid->addWidget(display, 0, 0, 1, 4);

	// tver
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
	
	// C ev +/-
	createDigitButton("C", 1, 3);
	createDigitButton("+/-", 2, 3);

	// gorcoxutyun
	createDigitButton("+", 1,3 );
	createDigitButton("-", 2,3 );
	createDigitButton("*", 3,3 );
	createDigitButton("/", 4,3 );
	setLayout(grid);

	QPushButton* equalBtn = new QPushButton("=", this);
	equalBtn->setFont(QFont("Arial", 20));
	equalBtn->setFixedSize(70, 70);
	equalBtn->setStyleSheet("background: #28a745; color: white; border-radius: 8px;");
	grid-> addWidget(equalBtn, 4, 3);
	connect(equalBtn, &QPushButton::clicked, this, &SimpleWindow::equalClicked);

	setLayout(grid);
}

void SimpleWindow::createDigitButton(const QString& text, int row, int column, int row_number, int coulumn_number){
	QPushButton* btn = new QPushButton(text, this);
	btn->setFont(QFont("Segoe UI", 20));
	btn->setFixedSize(70,70);
	btn->setStyleSheet("background: #2a2a4a; color: white; border-radius: 8px;");

	grid->addWidget(btn, row, column, row_number, coulumn_number);

	if(text == "C") {
		connect(btn, &QPushButton::clicked, this, &SimpleWindow::clearDisplay);
	} else if(text == "+/-") {
		connect(btn, &QPushButton::clicked, this, &SimpleWindow::changeSign);
	} else {
		connect(btn, &QPushButton::clicked, this, [this, text](){
			digitClicked(text);		
		});
	}
}

void SimpleWindow::digitClicked(const QString& digit) {
	if(waitingForSecondNumber) {
		currentInput = "0";
		waitingForSecondNumber = false;
	}

	if(digit == ".") {
		if(currentInput.contains('.')) return;
		if(currentInput.isEmpty() || currentInput == "0") {
			currentInput = "0";
		}else {
			currentInput += ".";
		}
	}else {
		if(currentInput == "0" && digit != "0") {
			currentInput = digit;
		}else {
			currentInput += digit;
		}
	}
	display->setText(currentInput);
}

void SimpleWindow::clearDisplay() {
	currentInput = "0";
	display->setText("0");
	possibleOperation = "";
	waitingForSecondNumber = false;
	display->setText("0");
}

void SimpleWindow::changeSign() {
	if(currentInput == "0") return;
	
	double num = currentInput.toDouble();
	num = -num;
	currentInput = QString::number(num);
	display->setText(currentInput);
}

void SimpleWindow::createOperationButton(const QString &operation, int row, int column){
	QPushButton* btn = new QPushButton(operation, this);
	btn->setFont(QFont("Arial", 20));
	btn->setFixedSize(70, 70);
	btn->setStyleSheet("background: #ff9500; color: white; border-radius: 8px;");
	grid->addWidget(btn, row, column);

	connect(btn, &QPushButton::clicked, this, [this, operation]() {
		operationClicked(operation);
	});
}

void SimpleWindow::operationClicked(const QString& operation){
	if(waitingForSecondNumber) { 
		calculate();
	}

	firstNumber = currentInput.toDouble();
	possibleOperation = operation;
	waitingForSecondNumber = true;
	currentInput = "0";
	display->setText("0");
}

void SimpleWindow::calculate() {
	double secondNumber = currentInput.toDouble();
	double result = 0;
	
	if(possibleOperation == "+") result = firstNumber + secondNumber;
	if(possibleOperation == "-") result = firstNumber - secondNumber;
	if(possibleOperation == "*") result = firstNumber * secondNumber;
	if(possibleOperation == "/") {
		if(secondNumber == 0) {
			display->setText("Error");
			currentInput = "0";
			waitingForSecondNumber = false;
			possibleOperation = "";
			return;
		}
		result = firstNumber / secondNumber;
	}

	currentInput = QString::number(result);
	display->setText(currentInput);
	waitingForSecondNumber = false;
	possibleOperation = "";
}

void SimpleWindow::equalClicked() {
	if(waitingForSecondNumber && !possibleOperation.isEmpty()){
		calculate();
	}
}
