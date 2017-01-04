#include "Relay.h"
#include "Arduino.h"

Relay::Relay(int pin) {
	this->_pin = pin;
	this->_offPosition = HIGH;
	this->_onPosition = LOW;
}

Relay::Relay(int pin, int offPosition) {
	this->_pin = pin;
	this->_offPosition = offPosition;
	this->_onPosition = (offPosition == HIGH) ? LOW : HIGH;
}

void Relay::debug() {
	this->_debug = true;
}

void Relay::init() {
	pinMode(_pin, OUTPUT);
	if(_debug){
		Serial.print("Initialized Relay on pin: ");
		Serial.print(_pin);
		Serial.print(", offPosition: ");
		Serial.print(_offPosition);
		Serial.print(", onPosition: ");
		Serial.println(_onPosition);
	}
	off();
}

void Relay::on() {
	if (isOff()) {
		if (_debug) {
			Serial.print("Turning on relay at pin ");
			Serial.print(_pin);
			Serial.print(" with value: ");
			Serial.println(_onPosition);
		}
		digitalWrite(_pin, _onPosition);
		_state = true;
	}
}

void Relay::off() {
	if (isOn()) {
		if (_debug) {
			Serial.print("Turning off relay at pin ");
			Serial.print(_pin);
			Serial.print(" with value: ");
			Serial.println(_offPosition);
		}
		digitalWrite(_pin, _offPosition);
		_state = false;
	}
}

void Relay::test() {
	Serial.println("Testing relay");
	on();
	delay(500);
	off();
}

boolean Relay::isOn() {
	return _state;
}

boolean Relay::isOff() {
	return !isOn();
}
