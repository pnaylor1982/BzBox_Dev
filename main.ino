#include "SparkFunBME280.h"
#include "SparkFunBQ27441.h"

bool once = true;
int count = 0;
BME280 mySensor;

const unsigned int BATTERY_CAPACITY = 2000; // e.g. 850mAh battery

void setup() {

  //***Driver settings********************************//
mySensor.settings.commInterface = I2C_MODE;
mySensor.settings.I2CAddress = 0x77;


//***Operation settings*****************************//

//runMode can be:
//  0, Sleep mode
//  1 or 2, Forced mode
//  3, Normal mode
mySensor.settings.runMode = 3; //Forced mode

//tStandby can be:
//  0, 0.5ms
//  1, 62.5ms
//  2, 125ms
//  3, 250ms
//  4, 500ms
//  5, 1000ms
//  6, 10ms
//  7, 20ms
mySensor.settings.tStandby = 0;

//filter can be off or number of FIR coefficients to use:
//  0, filter off
//  1, coefficients = 2
//  2, coefficients = 4
//  3, coefficients = 8
//  4, coefficients = 16
mySensor.settings.filter = 0;

//tempOverSample can be:
//  0, skipped
//  1 through 5, oversampling *1, *2, *4, *8, *16 respectively
mySensor.settings.tempOverSample = 1;

//pressOverSample can be:
//  0, skipped
//  1 through 5, oversampling *1, *2, *4, *8, *16 respectively
mySensor.settings.pressOverSample = 1;

//humidOverSample can be:
//  0, skipped
//  1 through 5, oversampling *1, *2, *4, *8, *16 respectively
mySensor.settings.humidOverSample = 1;
delay(10);  //Make sure sensor had enough time to turn on. BME280 requires 2ms to start up.         Serial.begin(57600);

Serial.begin(9600);
Serial.println("Setup");

Serial.print("Starting BME280... result of .begin(): 0x");
//Calling .begin() causes the settings to be loaded
Serial.println(mySensor.begin(), HEX);

if (!lipo.begin())
{
    Serial.println("Error: Unable to communicate with BQ27441.");
    Serial.println("  Check wiring and try again.");
    Serial.println("  (Battery must be plugged into Battery Babysitter!)");
    while (1) ;
}
Serial.println("Connected to BQ27441!");


lipo.setCapacity(BATTERY_CAPACITY); // Configure BQ27441 to assume a 1000 mAh battery

}



void loop() {

// BME280 reads
  Serial.println("_________");

  Serial.print("temp (C): ");
  float tempC = mySensor.readTempC();
  Serial.println(tempC);

  Serial.print("Pressure (kPa): ");
  float pressure = mySensor.readFloatPressure();
  Serial.println(pressure);

  Serial.print("Altitude (m): ");
  float altitude = mySensor.readFloatAltitudeMeters();
  Serial.println(altitude);

  Serial.print("RH (%): ");
  float RH = mySensor.readFloatHumidity();
  Serial.println(RH);
//----------//

// BQ27441 Battery Manager calls
unsigned int soc = lipo.soc(); // Read state-of-charge (in %)
unsigned int volts = lipo.voltage(); // Read voltage (in mV)
int current = lipo.current(AVG); // Read average current (in mA)
int power = lipo.power(); // Read power consumption (in mW)
int health = lipo.soh(); // Read state-of-health (in %)

Serial.print("State of Charge/Health: ");
Serial.println(soc);

Serial.print("mV, mA, mAH, mW: ");
Serial.println(volts);


  delay(1000);

}
