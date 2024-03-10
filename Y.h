#pragma once

#include "Z.h"
#include "X.h"

class Y : public Z, public X
{
public:
	Y() { std::cout << "Y()" << X::m_data << std::endl; };
	~Y() override { std::cout << "~Y()" << Z::m_data << std::endl; };
};