#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "hwlib.hpp"
#include "rtos.hpp"
#include "IButtonListener.hpp"

template<int N> // N is the max amount of listeners
class Button: public rtos::task<>{
	int ButtonID;
	rtos::clock ButtonClock;
	hwlib::target::pin_in ButtonPin;
	IButtonListener* Listeners[N];
	int listenersSize;

public:
	///@fn Button::Button(hwlib::target::pin_in ButtonPin, int ButtonID, const unsigned int priority, const char* name)
    ///@brief The constructor for the Button class.
    ///@details This constructor creates a Button object.
    ///@param ButtonPin The input pin to the button.
    ///@param ButtonID The ID of the button.
	///@param priority The priority of the listener.
	///@param name The name of the listener.
	Button(hwlib::target::pin_in ButtonPin, int ButtonID, const unsigned int priority, const char* name):
	task(priority, name), ButtonID(ButtonID), ButtonClock(this, 50'000, "ButtonClock"),
	ButtonPin(ButtonPin), listenersSize(0){};

	///@fn void Button::SetButtonListener(IButtonListener *Listener)
    ///@brief Set ButtonListener.
    ///@details This method sets the listeners.
    ///@param Listener A listener.
	void SetButtonListener(IButtonListener* Listener){
		if(listenersSize == N){ hwlib::cout << "Maximum listeners reached!\n"; return;}
		Listeners[listenersSize] = Listener;
		listenersSize++;
	}

	///@fn void Button::main()
    ///@brief The main of the Button task.
	void main(){
		while(true){
			wait(ButtonClock);
			if(!ButtonPin.get()){ //Button Pressed
				for(int i = 0; i < listenersSize; i++){
					Listeners[i] -> ButtonPressed(ButtonID);
				}
				for(;;){
					wait(ButtonClock);
					if(ButtonPin.get()){
						for(int i = 0; i < listenersSize; i++){
							Listeners[i] -> ButtonReleased(ButtonID);
						}
						break;
					}
				}
			}
		}
	}
};

#endif
