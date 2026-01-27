#ifndef SYSTEMAGENT_H
#define SYSTEMAGENT_H

// third-party library
#include <Qobject>
#include <QTcpSocket>
#include <QTimer>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDateTimne>

class SystemAgent : public Qobject {
	Q_OBJECT
public:
	SystemAgent(Qobject* parent = nullptr);

private slots:
	void onServerConnected(); // kkanchvi erb serveri het kap hastatvi
	void sendDataToServer(); // kkanchvi varkyany mek angam ktarmacni tvyalnery serveri

private:
	QTcpSocket* networkSocket; // cancayin kapi objekt
	QTimer* updateTimer; // jamanakachap, parberakan ashxatanqi hamar
	QJsonObject collectDataRAM(); // havaquma Rami tvyalnery ev sarqum JSON
};

#endif //SYSTEMAGENT_H
