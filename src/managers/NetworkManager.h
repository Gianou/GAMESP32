#ifndef NETWORK_MANAGER_H
#define NETWORK_MANAGER_H

#include <WiFi.h>
#include <Firebase_ESP_Client.h>

class NetworkManager
{
private:
    static NetworkManager *instance;
    NetworkManager();
    const char *ssid;
    const char *password;
    const char *_apiKey;
    const char *_databaseUrl;
    const char *_projectId;

    int getSignalStrength();

public:
    static NetworkManager *
    getInstance();
    void connectToWiFi();
    void connectToFirebase();
    void saveScoreFirestore(String username, int score);
    bool isConnected();
    void setCredentials(const char *wifi_ssid, const char *wifi_password);
    void setFirebaseCredentials(const char *apiKey, const char *databaseUrl, const char *projectId);
    String getConnectionQuality();
};

#endif
