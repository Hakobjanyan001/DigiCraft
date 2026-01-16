#ifndef SIMPLEWINDOW_H
#define SIMPLEWINDOW_H

#include <QWidget>

class QLabel;
class QPushButton;
class QVBoxLayout;

class Simplewindow : public QWidget {
Q_OBJECT
public:
	Simplewindow(QWidget* parent = nullptr);
	~Simplewindow();

private:
	QLabel* label;
	QPushButton* button;
	QVBoxLayout* mainLayout;
};

#endif //SIMPLEWINDOW_H
