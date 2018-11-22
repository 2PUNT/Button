#ifndef IBUTTONLISTENER_HPP
#define IBUTTONLISTENER_HPP

class IButtonListener{
public:
	///@fn virtual void IButtonListener::ButtonPressed(int ButtonID)=0
    ///@param ButtonID A Button ID.
	virtual void ButtonPressed(int ButtonID)=0;
	
	///@fn virtual void IButtonListener::ButtonReleased(int ButtonID)=0
    ///@param ButtonID A Button ID.
	virtual void ButtonReleased(int ButtonID)=0;
};

#endif
