#include <SimpleDHT.h> 
#include <U8x8lib.h>

int DHTPIN = 21;                //GPIO15 (ADC2_CH3)    //DHT11 sensor

SimpleDHT11 dht11;              //defind model of sensor : DHT11
byte temperature = 0;         
byte humidity = 0;         

// the OLED used
U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(15,4,16);

void setup() {
  
    Serial.begin(115200);   
    u8x8.begin();
    u8x8.setFont(u8x8_font_amstrad_cpc_extended_r);
    //u8x8.setFont(u8x8_font_chroma48medium8_r);  // แบบตัวเล็กลงมาหน่อยนะ

}

void loop() {

  readTemp();

  char buffer_temp[30];
  char buffer_humi[30];
  String str_temp;
  String str_humi;
  
  
  str_temp = "Temp : " + String(temperature) + " C'";
  str_humi = "Humi : " + String(humidity) + " %";
  str_temp.toCharArray(buffer_temp, 30);
  str_humi.toCharArray(buffer_humi, 30);
    
  u8x8.drawString(0, 1, " Digital branch"); // show string first line x,y
  u8x8.drawString(0, 3, buffer_temp); // show temp value
  u8x8.drawString(0, 5, buffer_humi); // show humi value
}



    
void readTemp(){
  
    dht11.read(DHTPIN, &temperature, &humidity, NULL);  // Read value from sensor
    delay(2000);                                    //wait 2 seconds
    Serial.print("DHT11 read: ");
    Serial.print((int)temperature); Serial.print(" *C, "); 
    Serial.print((int)humidity); Serial.println(" %H");
  }

//====================================================================
