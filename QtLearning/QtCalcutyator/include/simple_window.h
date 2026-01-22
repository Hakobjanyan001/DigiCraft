#ifndef SIMPLE_WINDOW_H
#define SIMPLE_WINDOW_H

#include <QWidget>

class QLineEdit;
class QGridLayout;

class SimpleWindow : public QWidget {
	Q_OBJECT

public:
	SimpleWindow(QWidget* parent = nullptr);

private slots:
	void digitClicked(const QString& digit);
	void clearDisplay();
	void changeSign();
	void operationClicked(const QString& op);
	void calculate();
	void equalClicked();

private:
	QLineEdit* display;
	QGridLayout* grid;
	QString currentInput = "0";
	double firstNumber = 0;
	QString possibleOperation = "";
	bool waitingForSecondNumber = false;
	QString text = "";

	void createDigitButton(const QString &text, 
							int row, 
							int column, 
							int row_number = 1, 
							int coulumn_number = 1);

	void createOperationButton(const QString &operation, int row, int column);
};


#endif //SIMPLE_WINDOW_H
