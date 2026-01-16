#include "simple_window.h"
#include <QApplication>

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	Simplewindow window;
	window.show();
	return app.exec();
}
