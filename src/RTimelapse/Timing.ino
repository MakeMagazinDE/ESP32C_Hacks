bool initWiFi(){
   uint16_t c = 0; // Timeout-Zähler für WLAN-Verbindung
   WiFi.begin(SSID, PASSWORD);
   while (WiFi.status() != WL_CONNECTED && c++ < 50) { 
     Serial.print(".");
     delay(500);
   } // Maximal 50×500ms auf WLAN warten
    if (WiFi.status() != WL_CONNECTED) {
     return false;
   } else {
     return true;
  }
}

void initTime(){
  configTime(3600 * TIMEZONE, DAY_SAVE_TIME * 3600, "time.nist.gov", "0.pool.ntp.org", "1.pool.ntp.org");
}