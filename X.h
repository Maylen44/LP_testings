#pragma once

#include <iostream>

#include "D.h"

class X : public D
{
public:
	X() :m_data(6) 
	{
		std::cout << "X()" << m_data << std::endl;
	};
	virtual ~X() { std::cout << "~X()" << m_data << std::endl; };

	int m_data;
};