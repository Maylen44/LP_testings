#pragma once

#include "X.h"

class Z : public X
{
public:
	Z() { std::cout << "Z()" << m_data << std::endl; };
	~Z() override { std::cout << "~Z()" << m_data << std::endl; };
};