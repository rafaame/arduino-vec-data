#include "common/common.h"
#include "common/controller/I2cController.h"
#include "common/controller/StateController.h"
#include "controller/ELM327Controller.h"
#include "controller/SignalController.h"
#include "handler/DataHandler.h"
#include "vec-common/Packet.h"

I2cController i2cController;
StateController stateController;
ELM327Controller elm327Controller;
SignalController signalController;
DataHandler dataHandler(&stateController, &elm327Controller, &signalController);
void setup() {
	Serial.begin(115200);
	Serial.println("Starting arduino-vec-data...");

	pinMode(10, OUTPUT);
	digitalWrite(10, HIGH);

	signalController.init();
	i2cController.init(0x0A);
	i2cController.setOnRequestCallback([]() -> void {
		i2cController.write(dataHandler.getPacketBuffer(), DataPacket::getByteArraySize());
	});
}

void loop() {	
	dataHandler.loop();
}