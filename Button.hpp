#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "IButtonListener.hpp"

template<int N> // N is the amount of listeners
class Button{
public:
	void SetListener(IButtonListener* Listener);
};

#endif
