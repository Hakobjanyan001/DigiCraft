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
	display->setStyleSheet("background: black; color: white; padding: 12px; border: none;");

	grid = new QGridLayout(this);
	grid->setSpacing(8);
	grid->setContentsMargins(12, 12, 12, 12);
	grid->addWidget(display, 0, 0, 1, 4);

	// tver
	createDigitButton("7", 2, 0);
	createDigitButton("8", 2, 1);
	createDigitButton("9", 2, 2);
	createDigitButton("4", 3, 0);
	createDigitButton("5", 3, 1);
	createDigitButton("6", 3, 2);
	createDigitButton("1", 4, 0);
	createDigitButton("2", 4, 1);
	createDigitButton("3", 4, 2);
	createDigitButton("0", 5, 1);
	createDigitButton(".", 1, 0);
	
	// C ev +/-
	createDigitButton("+/-", 1, 1);

	// gorcoxutyun
	createOperationButton("+", 1,3 );
	createOperationButton("-", 2,3 );
	createOperationButton("*", 3,3 );
	createOperationButton("/", 4,3 );
	setLayout(grid);
	
	QPushButton* clearBtn = new QPushButton("C", this);
	clearBtn->setFont(QFont("Arial",20));
	clearBtn->setFixedSize(70,70);
	clearBtn->setStyleSheet("background: green; color: white; border-radius: 8px;");
	grid->addWidget(clearBtn, 5, 2);
	connect(clearBtn, &QPushButton::clicked, this, &SimpleWindow::clearDisplay);
	
	QPushButton* equalBtn = new QPushButton("=", this);
	equalBtn->setFont(QFont("Arial", 20));
	equalBtn->setFixedSize(70, 70);
	equalBtn->setStyleSheet("background: green; color: white; border-radius: 8px;");
	grid->addWidget(equalBtn, 1, 2);
	connect(equalBtn, &QPushButton::clicked, this, &SimpleWindow::equalClicked);

	setLayout(grid);
}

void SimpleWindow::createDigitButton(const QString& text, int row, int column, int row_number, int coulumn_number){
	QPushButton* btn = new QPushButton(text, this);
	btn->setFont(QFont("Segoe UI", 20));
	btn->setFixedSize(70,70);
	btn->setStyleSheet("background: black; color: white; border-radius: 8px;");

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
		currentInput.clear();
		waitingForSecondNumber = false;
	}
	if(digit == ".") {
		if(currentInput.contains('.')) return;
		if(currentInput.isEmpty() || currentInput == "0") {
			currentInput = "0.";
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
	display->setText(text + " " + currentInput);
}

void SimpleWindow::clearDisplay() {
	currentInput = "0";
	display->setText("0");
	text = "0";
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
	btn->setStyleSheet("background: black; color: white; border-radius: 8px;");
	grid->addWidget(btn, row, column);

	connect(btn, &QPushButton::clicked, this, [this, operation]() {
		operationClicked(operation);
	});
}

void SimpleWindow::operationClicked(const QString& op){
	if(waitingForSecondNumber) { 
		calculate();
	}

	firstNumber = currentInput.toDouble();
	possibleOperation = op;
	waitingForSecondNumber = true;
	text = currentInput + " " + op;
	display->setText(text);
	currentInput = "0";
}

void SimpleWindow::calculate() {
	if(possibleOperation.isEmpty()) return;

	double secondNumber = currentInput.toDouble();
	double result = 0;
	
	if(possibleOperation == "+") {
		result = firstNumber + secondNumber;
	}else if(possibleOperation == "-") {
		result = firstNumber - secondNumber;
	}else if(possibleOperation == "*") {
		result = firstNumber * secondNumber;
	}else if(possibleOperation == "/") {
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
	
	firstNumber = result;
	text = currentInput;
	waitingForSecondNumber = false;
	possibleOperation = "";
}

void SimpleWindow::equalClicked() {
	if(!possibleOperation.isEmpty()){
		calculate();
	}
		text = currentInput;
		display->setText(text);
}
