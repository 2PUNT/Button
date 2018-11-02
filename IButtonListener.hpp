#ifndef IBUTTONLISTENER_HPP
#define IBUTTONLISTENER_HPP

class IButtonListener{
public:
	virtual void ButtonPressed(int ButtonID)=0;
	virtual void ButtonReleased(int ButtonID)=0;
};

#endif
