#ifndef Relay_h
#define Relay_h

class Relay
{
	public:
		Relay(int pin);
		Relay(int pin, int offPosition);
		void init();
		void on();
		void off();
		void test();
		bool isOn();
		bool isOff();
	private:
		bool _state = false;
		int _pin, _offPosition, _onPosition;
};
#endif
