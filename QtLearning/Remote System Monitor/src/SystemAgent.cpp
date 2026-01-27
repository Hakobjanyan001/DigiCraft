// project library
#include "SystemAgent.h"

// system library
#include <sys/sysinfo.h> // Linux-i gradaran RAM-i hamr

// third-party library
#include <QDebug>

SystemAgent::SystemAgent(QObject* parent) : QObject(parent) {
	networkSocket = new QTcpSocket(this); // stexcum enq obyektner hishoxutyan mej
	updateTimer = new QTimer(this);

	connect(networkSocket, &QTcpSocket::connected, this, &SystemAgent::onServerConnected); // erb sokety asume vor miacel e (conected) kanchi onServerConnected-y

	connect(updateTimer, &QTimer::timeout, this, &SystemAgent::sendDataToServer); // erb taymery lranuma (timeout) kanchi sendDataToServer
	
	networkSocket->connectToHost("187.0.0.1", 8080); // mianal serverin 8080 portov

}

void SystemAgent::onServerConnected() {
	qDebug() << "Successfully connected to the server ";
		updateTimer->start(2000); // taymery 2 varkyan intervalov
}

QJsonObject SystemAgent::collectDataRAM() {
	struct sysinfo memInfo; // erku hat struct-ner 
						   // sysinfo-n naxapes sahmanvac struct-a sys/sysinfo.h gradaranic nmana datark axyusaki uni hatuk dashter nkaragrelu yndhanur RAM-y, kam RAM-i procesneri   							qanaky
						   // meminfo-n mer komic stexcvac popoxakanna,skzbum uxxaki texa zbaxecnum hishoxutyan mej vor heto lcvi tvyalnerov, sysinfo(&meminfo) Operacion Hamakargi 							 (Kernel) funkcia,OH-in talisenq datark dzevatuxt u asumenq du inqt lracra
	sysinfo(&memInfo); // karduma OH-i tvyalnery
	
	// hashvumenq RAM-i chapy bayterov
	long long totalRam = memInfo.totalram* memInfo.mem_unit;
	long long freeRam = memInfo.freeram* memInfo.mem_unit;
	long long usedRam = totalRam - freeRam;

	// tvyalnery lcnumenq JSON karucvacki mej
	QJsonObject data;
	data["total_ram"] = QString::number(totalRam / (1024 * 1024)) + "MB";
	data["used_ram"] = QString::number(usedRam / (1024 * 1024)) + "MB";
	data["time"] = QDateTime::currentDateTime().toString("hh:mm:ss");

	return data;
}

void SystemAgent::sendDataToServer() {
	if(networkSocket->state() == QAbstractSocket::ConnectedState) { // stugenq kapy der ka
		QJsonObject currentData = collectDataRAM(); // vercnumenq tvyalnery
		QJsonDocument doc(currentData); // darcnum pastatuxt

		networkSocket->write(doc.toJson(QJsonDocument::Compact)); // uxxarkumenq vorpes JSon text
		networkSocket->flush(); // stugumenq vor tvyalnery miangamic  gnacin

		qDebug() << "Data sent to server...";
	}
}

void SystemAgent::start() {
	sendDataToServer();
}
