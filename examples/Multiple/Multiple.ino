#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 3 on the Arduino
#define ONE_WIRE_BUS 3
#define TEMP_RESOLUTION 9

#define MAX_NUM_OF_DEVICE  10

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

// arrays to hold device addresses
DeviceAddress Device_add[MAX_NUM_OF_DEVICE];
DeviceAddress insideThermometer, outsideThermometer;

void setup(void) {
    // start serial port
    Serial.begin(115200);
    Serial.println("Dallas Temperature IC Control Library Demo");

    // Start up the library
    sensors.begin();

    // locate devices on the bus
    Serial.print("Locating devices...");
    Serial.print("Found ");
    Serial.print(sensors.getDeviceCount(), DEC);
    Serial.println(" devices.");

    Serial.print("Parasite power is: ");
    if (sensors.isParasitePowerMode()) {
        Serial.println("ON");
    } else {
        Serial.println("OFF");
    }

    for (int i = 0; i < sensors.getDeviceCount(); i++) {
        if (!sensors.getAddress(Device_add[i], i)) {
            Serial.println("Find device error!!");
        } else {
            Serial.print("Device [");
            Serial.print(i);
            Serial.print("] addr =");
            printAddress(Device_add[i]);
        }
        Serial.println(" ");
    }

}

// function to print a device address
void printAddress(DeviceAddress deviceAddress) {
    for (uint8_t i = 0; i < 8; i++) {
        // zero pad the address if necessary
        if (deviceAddress[i] < 16) {
            Serial.print("0");
        }
        Serial.print(deviceAddress[i], HEX);
    }
}

// function to print the temperature for a device
void printTemperature(DeviceAddress deviceAddress) {
    float tempC = sensors.getTempC(deviceAddress);
    Serial.print("Temp C: ");
    Serial.print(tempC);
    Serial.print(" Temp F: ");
    Serial.print(DallasTemperature::toFahrenheit(tempC));
}

// function to print a device's resolution
void printResolution(DeviceAddress deviceAddress) {
    Serial.print("Resolution: ");
    Serial.print(sensors.getResolution(deviceAddress));
    Serial.println();
}

// main function to print information about a device
void printData(DeviceAddress deviceAddress) {
    Serial.print("Device Address: ");
    printAddress(deviceAddress);
    Serial.print(" ");
    printTemperature(deviceAddress);
    Serial.println();
}

void loop(void) {
    // call sensors.requestTemperatures() to issue a global temperature
    // request to all devices on the bus
    Serial.print("Requesting temperatures...");
    sensors.requestTemperatures();
    Serial.println("DONE");

    for (int i = 0; i < sensors.getDeviceCount(); i++) {
        printData(Device_add[i]);
    }

}

