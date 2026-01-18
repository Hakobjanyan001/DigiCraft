#include "simple_window.h"
#include <QApplication>

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	SimpleWindow w;
	w.show();
	return app.exec();
}
