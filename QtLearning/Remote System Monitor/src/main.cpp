// project library
#include "SystemAgent.h"

// third party
#include <QApplication>

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);

	SystemAgent agent;
	agent.start();

	return app.exec();
}
