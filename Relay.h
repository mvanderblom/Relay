#ifndef Relay_h
#define Relay_h

#include "Arduino.h"

class Relay
{
	public:
		Relay(int pin);
		Relay(int pin, int offPosition);
		void init();
		void debug();
		void on();
		void off();
		void test();
		boolean isOn();
		boolean isOff();
	private:
		boolean _debug = false;
		boolean _state = false;
		int _pin, _offPosition, _onPosition;
};
#endif
