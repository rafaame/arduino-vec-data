#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include "common/common.h"

#define DATA_DEBUG false

#define FUEL_LEVEL_UPDATE_PERIOD 60000
#define COOLANT_TEMP_UPDATE_PERIOD 5000
#define ENGINE_LOAD_UPDATE_PERIOD 60000
#define TIMING_ADVANCE_UPDATE_PERIOD 60000
#define THROTTLE_UPDATE_PERIOD 60000

class StateController;
class ELM327Controller;
class SignalController;
class DataPacket;

class DataHandler {
private:
	StateController *stateController;
	const ELM327Controller *elm327Controller;
	const SignalController *signalController;

	uint8_t *packetBuffer;

public:
	DataHandler(StateController *stateController, const ELM327Controller *elm327Controller, const SignalController *signalController);
	~DataHandler();

	void loop();

	uint8_t *getPacketBuffer();
	const DataPacket *readPacket();
	
	const DataPacket *generateTestPacket();
	void printDataPacket(DataPacket *packet);
	void printCalibrationConstants();
};

#endif