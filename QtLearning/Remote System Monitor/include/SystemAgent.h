#ifndef SYSTEMAGENT_H
#define SYSTEMAGENT_H

// third-party library
#include <QObject>
#include <QTcpSocket>
#include <QTimer>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDateTime>

class SystemAgent : public QObject {
	Q_OBJECT
public:
	SystemAgent(QObject* parent = nullptr);

private slots:
	void onServerConnected(); // kkanchvi erb serveri het kap hastatvi
	void sendDataToServer(); // kkanchvi varkyany mek angam ktarmacni tvyalnery serveri

private:
	QTcpSocket* networkSocket; // cancayin kapi objekt
	QTimer* updateTimer; // jamanakachap, parberakan ashxatanqi hamar
	QJsonObject collectDataRAM(); // havaquma Rami tvyalnery ev sarqum JSON

public:
	void start();
};

#endif //SYSTEMAGENT_H
