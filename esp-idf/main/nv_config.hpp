#include <nvs.h>
#include "esp32-hal-log.h"
#include <WiFi.h>

class NonVolatileConfig {
    public:
        NonVolatileConfig() {};
        esp_err_t loadNonvolatileConfiguration();

        String getWifiSSID() {
            return wifiSSID;
        };

        String getWifiPassword() {
            return wifiPassword;
        };

        bool isWifiConfigured() {
            return wifiConfigured;
        }

    private:
        esp_err_t __espret__;

        bool wifiConfigured;
        String wifiSSID;
        String wifiPassword;
};
