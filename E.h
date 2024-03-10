#pragma once

#include <iostream>

#include "D.h"

class E : public D
{
public:
	E() :m_data(5)
	{
		std::cout << "E()" << m_data << std::endl;
	};
	virtual ~E() { std::cout << "~E()" << m_data << std::endl; };

	int m_data;
};