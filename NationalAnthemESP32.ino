#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16x2 display
LiquidCrystal_I2C lcd(0x27, 16, 2);

// National anthem text (in Hindi)
String anthem = "Jana Gana Mana Adhinayaka Jaya He Bharata Bhagya Vidhata Punjab Sindh Gujarat Maratha Dravida Utkala Banga Vindhya Himachala Yamuna Ganga Uchchala Jaladhi Taranga Tava Shubha Name Jage Tava Shubha Ashish Mage Gahe Tava Jaya Gatha Jana Gana Mangala Dayaka Jaya He Bharata Bhagya Vidhata Jaya He Jaya He Jaya He Jaya Jaya Jaya Jaya He";

// Time delay for scrolling (adjust for speed)
int scrollDelay = 250;

void setup() {
  // Initialize the LCD
  lcd.init();
  lcd.backlight();  // Turn on the backlight
  lcd.clear();

  // Display a greeting message before starting the scroll
  lcd.setCursor(0, 0);
  lcd.print("National Anthem");
  lcd.setCursor(0, 1);
  lcd.print("of India");
  delay(3000);  // Display the greeting for 3 seconds
  lcd.clear();
}

void loop() {
  for (int i = 0; i < anthem.length(); i++) {
    lcd.clear();  // Clear the display

    // Display 16 characters at a time
    lcd.setCursor(0, 0);
    lcd.print(anthem.substring(i, i + 16));

    delay(scrollDelay);  // Control the scroll speed
  }
}
