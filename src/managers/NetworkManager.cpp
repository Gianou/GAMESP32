#include "NetworkManager.h"

#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

FirebaseConfig config;
FirebaseAuth auth;

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
void NetworkManager::setFirebaseCredentials(const char *apiKey, const char *databaseUrl, const char *projectId)
{
    _apiKey = apiKey;
    _databaseUrl = databaseUrl;
    _projectId = projectId;
}

void NetworkManager::connectToWiFi()
{
    delay(1000);
    Serial.print("SSID: ");
    Serial.println(ssid);
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

void NetworkManager::connectToFirebase()
{
    config.api_key = _apiKey;
    config.database_url = _databaseUrl;

    config.token_status_callback = tokenStatusCallback;

    if (Firebase.signUp(&config, &auth, "", ""))
    {
        Serial.println("Anonymous sign-in successful");
    }
    else
    {
        Serial.printf("Sign-in error: %s\n", config.signer.signupError.message.c_str());
    }

    Firebase.begin(&config, &auth);
    Firebase.reconnectWiFi(true);
}

void NetworkManager::saveScoreFirestore(String username, int score)
{
    FirebaseData fbdo;
    FirebaseJson content;

    content.set("fields/player/stringValue", username);
    content.set("fields/score/integerValue", score);

    Serial.print("Saving score... ");

    if (Firebase.Firestore.createDocument(&fbdo, _projectId, "", "scoreboard", content.raw()))
        Serial.printf("ok\n%s\n\n", fbdo.payload().c_str());
    else
        Serial.println(fbdo.errorReason());
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

// Get connection quality as an integer (0-3)
int NetworkManager::getConnectionQuality()
{
    int rssi = getSignalStrength();

    if (rssi == 0)
    {
        return 0; // No signal
    }
    else if (rssi >= -50)
    {
        return 3; // Excellent
    }
    else if (rssi >= -60)
    {
        return 2; // Good
    }
    else if (rssi >= -80)
    {
        return 1; // Fair/Weak
    }
    else
    {
        return 0; // Very weak
    }
}
