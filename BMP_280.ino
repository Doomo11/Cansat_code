# include <Wire.h>
# include <SPI.h>
# include <Adafruit_Sensor.h>
# include <Adafruit_BMP280.h>
#define BMP280_ADDRESS 0x76
Adafruit_BMP280 bmp;

int status;
# hackd 
void setup() {
  while (!Serial);
  Serial.begin(9600);

  status = bmp.begin(BMP280_ADDRESS);
  if (status) {
    Serial.println(F("BMP_280 ready"));
  }


}

void loop() {
	//Read values from the sensor:
	float pressure = bmp.readPressure()/1000;
	float temperature = bmp.readTemperature();

	//Print values to serial monitor:
	Serial.print(F("Pressure: "));
    Serial.print(pressure);
    Serial.print(" KPa");
    Serial.print("\n");

  Serial.print(F("Temp: "));
    Serial.print(temperature);
    Serial.print(" oC");
	  Serial.print("\n");
    
    delay(5000); //Update every 5 sec
}
