#include "simple_window.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

Simplewindow::Simplewindow(QWidget* parent) : QWidget(parent) {
	setWindowTitle("My first Qt");
	setFixedSize(400, 300);

	mainLayout = new QVBoxLayout(this);

	
	label = new QLabel("Enter key", this);
	label->setAlignment(Qt::AlignCenter);
	label->setStyleSheet("font-size: 18px; padding: 10px;");

	button = new QPushButton("Click me", this);
	button->setStyleSheet("font-size: 16px; padding: 8px;");

	connect(button, &QPushButton::clicked, this, [this] () {
		label->setText("Yes it's to run");
		label->setStyleSheet("font-size: 28px; color: #006400; font-weight; bold;");
	});

	mainLayout->addWidget(label);
	mainLayout->addWidget(button);

	setLayout(mainLayout);
}

Simplewindow::~Simplewindow() {}
