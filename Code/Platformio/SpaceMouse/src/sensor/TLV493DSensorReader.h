/* 
* TimedPulseGenerator.h
*
* Created: 2/7/2024 12:39:13 PM
* Author: Alex
*/


#ifndef __TLV_493D_SENSOR_READER_H__
#define __TLV_493D_SENSOR_READER_H__
#include <Tlv493d.h>
#include "SensorReadings.h"
#include "MagneticSensorReader.h"

extern "C" {
};

namespace MagneticSensor {

class TLV493DSensorReader: public MagneticSensorReader {

private: 	
public:
	
	// TODO: implementations will use default I2C bus address for now
	virtual bool initSensor(int sensorId, TwoWire* wire = 0);
	virtual void shutdownSensor();
	virtual long getMeasurementDurationMillis();

	/**
	 * Perform sensor calibration (TODO)
	*/
	virtual void calibrateSensor();
	

	virtual void getSensorReading(SensorReading* readingReceiver);
	virtual SensorReading* getSensorReading();
	
	TLV493DSensorReader();
	// free some resources
	virtual ~TLV493DSensorReader();

protected:
private:
	Tlv493d driver;
	SensorReading currentReading;
};

}
#endif //__TLV_493D_SENSOR_READER_H__
