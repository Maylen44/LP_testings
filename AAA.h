#pragma once

#include "AA.h"

class AAA : public AA
{
public:
	AAA() 
		: AA(Type_AAA)
	{ std::cout << "AAA()" << m_data << std::endl; };
	~AAA() override { std::cout << "~AAA()" << m_data << std::endl; };
};