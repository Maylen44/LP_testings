#pragma once

#include "A.h"

class AA : public A
{
public:
	AA(Type type) 
		: A(type)
	{ std::cout << "AA()" << m_data << std::endl; };
	~AA() override { std::cout << "~AA()" << m_data << std::endl; };
};