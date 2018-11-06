#include "hwlib.hpp"
#include "IButtonListener.hpp"
#include "Button.hpp"

class ButtonListener_CoutDummy: public IButtonListener{
public:
	ButtonListener_CoutDummy(){};
	void ButtonPressed(int ButtonID) override{
		hwlib::cout << ButtonID << '\n';
	}
	
	void ButtonReleased(int ButtonID) override{
		hwlib::cout << ButtonID << '\n';
	}
};

int main(void){
	
	// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;
	hwlib::wait_ms(500);
	
	namespace target = hwlib::target;
	auto Buttonpin = target::pins::d8;
	
	auto button = Button<1>(Buttonpin,1, 0, "TheButton");
	
	auto ButtonDummy = ButtonListener_CoutDummy();
	IButtonListener* ButtonDummyBase = &ButtonDummy;
	button.SetButtonListener(ButtonDummyBase);
	
	rtos::run();
	
	return 0;
}