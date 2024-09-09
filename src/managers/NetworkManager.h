#ifndef NETWORK_MANAGER_H
#define NETWORK_MANAGER_H

#include <WiFi.h>

class NetworkManager
{
private:
    static NetworkManager *instance;
    NetworkManager();
    const char *ssid;
    const char *password;

    int getSignalStrength();

public:
    static NetworkManager *
    getInstance();
    void connectToWiFi();
    bool isConnected();
    void setCredentials(const char *wifi_ssid, const char *wifi_password);
    String getConnectionQuality();
};

#endif
