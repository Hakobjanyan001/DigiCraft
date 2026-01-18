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
	void digitClicked(const QString &digit);

private:
	QLineEdit* display;
	QGridLayout* grid;

	void createDigitButton(const QString &text, 
							int row, 
							int column, 
							int row_number = 1, 
							int coulumn_number = 1);
};

#endif //SIMPLE_WINDOW_H
