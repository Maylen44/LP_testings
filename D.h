#pragma once

#include <iostream>

class D
{
public:
	D() :m_data(4) 
	{
		std::cout << "D()" << m_data << std::endl;
	};
	virtual ~D() { std::cout << "~D()" << m_data << std::endl; };

	int m_data;
};