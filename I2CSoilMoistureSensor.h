/*----------------------------------------------------------------------*
 * I2CSoilMoistureSensor.h - Arduino library for the Sensor version of  *
 * I2C Soil Moisture Sensor version from Chrirp                         *
 * (https://github.com/Miceuz/i2c-moisture-sensor).                     *
 *                                                                      *
 * Ingo Fischer 11Nov2015                                               *
 * https://github.com/Apollon77/I2CSoilMoistureSensor                   *
 *                                                                      *
 * MIT license                                                          *
 *----------------------------------------------------------------------*/ 

#ifndef I2CSOILMOISTURESENSOR_H
#define I2CSOILMOISTURESENSOR_H

#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h> 
#else
#include <WProgram.h> 
#endif

//Default I2C Address of the sensor
#define SOILMOISTURESENSOR_DEFAULT_ADDR 0x20

//Soil Moisture Sensor Register Addresses
#define SOILMOISTURESENSOR_GET_CAPACITANCE 	0x00 // (r) 	2 bytes
#define SOILMOISTURESENSOR_SET_ADDRESS 		0x01 //	(w) 	1 byte
#define SOILMOISTURESENSOR_GET_ADDRESS 		0x02 // (r) 	1 byte
#define SOILMOISTURESENSOR_MEASURE_LIGHT 	0x03 //	(w) 	n/a
#define SOILMOISTURESENSOR_GET_LIGHT 		0x04 //	(r) 	2 bytes
#define SOILMOISTURESENSOR_GET_TEMPERATURE	0x05 //	(r) 	2 bytes
#define SOILMOISTURESENSOR_RESET 			0x06 //	(w) 	n/a
#define SOILMOISTURESENSOR_GET_VERSION 		0x07 //	(r) 	1 bytes


class I2CSoilMoistureSensor {
    public:
        I2CSoilMoistureSensor(uint8_t addr = SOILMOISTURESENSOR_DEFAULT_ADDR);

		void begin();
        unsigned int getCapacitance();
        bool setAddress(int addr, bool reset);
        uint8_t getAddress();
        void startMeasureLight();
        unsigned int getLight(bool wait = false);
        int getTemperature();
        void resetSensor();
        uint8_t getVersion();

    private:
		int sensorAddress;

        void writeI2CRegister8bit(int addr, int value);
        void writeI2CRegister8bit(int addr, int reg, int value);
        unsigned int readI2CRegister16bitUnsigned(int addr, int reg);
        int readI2CRegister16bitSigned(int addr, int reg);
        uint8_t readI2CRegister8bit(int addr, int reg);
};

#endif
