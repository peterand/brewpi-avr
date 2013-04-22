/*
 * OneWireTempSensor.h
 *
 * Created: 15/03/2013 09:53:09
 *  Author: mat
 */ 


#ifndef ONEWIRETEMPSENSOR_H_
#define ONEWIRETEMPSENSOR_H_

#include "TempSensor.h"
#include "FastDigitalPin.h"

class DallasTemperature;
class OneWire;


class OneWireTempSensor : public BasicTempSensor {
public:	
	OneWireTempSensor(uint8_t pinNumber, DeviceAddress address=NULL) : pinNr(pinNumber), oneWire(NULL), sensor(NULL) {		
		lastRequestTime = 0;
		connected = 0;	
		autoAddress = address==NULL;
		if (address)
			memcpy(sensorAddress, address, sizeof(*address));
	};
	
	~OneWireTempSensor(){
		delete oneWire;
		delete sensor;
	};
	
	bool isConnected(void){
		return connected;
	}
	
	fixed7_9 init();
	fixed7_9 read();
	
	private:
	bool connected;
	bool autoAddress;
	const uint8_t pinNr;
	unsigned long lastRequestTime; // in milliseconds
	
	OneWire * oneWire;
	DallasTemperature * sensor;
	DeviceAddress sensorAddress;	
};



#endif /* ONEWIRETEMPSENSOR_H_ */