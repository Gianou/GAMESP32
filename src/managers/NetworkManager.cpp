#include "NetworkManager.h"

NetworkManager::NetworkManager()
{
}

// Initialize the static instance pointer to nullptr
NetworkManager *NetworkManager::instance = nullptr;

NetworkManager *NetworkManager::getInstance()
{
    if (instance == nullptr)
    {
        instance = new NetworkManager();
    }
    return instance;
}

void NetworkManager::setCredentials(const char *wifi_ssid, const char *wifi_password)
{
    ssid = wifi_ssid;
    password = wifi_password;
}

void NetworkManager::connectToWiFi()
{
    delay(1000);
    Serial.print("SSID: ");
    Serial.println(ssid); // Should print the correct SSID
    Serial.print("Password: ");
    Serial.println(password);
    // Check if SSID and password are valid
    if (ssid == nullptr || password == nullptr || strlen(ssid) == 0 || strlen(password) == 0)
    {
        Serial.println("Invalid SSID or password. Cannot connect to WiFi.");
        return;
    }

    if (WiFi.status() != WL_CONNECTED)
    {
        Serial.println("Connecting to WiFi...");
        WiFi.begin(ssid, password);

        // Wait for the connection to be established
        while (WiFi.status() != WL_CONNECTED)
        {
            delay(500);
            Serial.print(".");
        }

        Serial.println("\nConnected to WiFi!");
        Serial.print("IP Address: ");
        Serial.println(WiFi.localIP());
    }
    else
    {
        Serial.println("Already connected to WiFi");
    }
}

// Check WiFi connection status
bool NetworkManager::isConnected()
{
    return (WiFi.status() == WL_CONNECTED);
}

// Get the quality of the WiFi connection based on RSSI
int NetworkManager::getSignalStrength()
{
    if (WiFi.status() == WL_CONNECTED)
    {
        return WiFi.RSSI();
    }
    else
    {
        Serial.println("Not connected to WiFi.");
        return 0; // Return 0 if not connected
    }
}

// Get connection quality in human-readable form
String NetworkManager::getConnectionQuality()
{
    int rssi = getSignalStrength();

    if (rssi == 0)
    {
        return "No signal";
    }
    else if (rssi >= -50)
    {
        return "Excellent";
    }
    else if (rssi >= -60)
    {
        return "Good";
    }
    else if (rssi >= -70)
    {
        return "Fair";
    }
    else if (rssi >= -80)
    {
        return "Weak";
    }
    else
    {
        return "Very weak";
    }
}
