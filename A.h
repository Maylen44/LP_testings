#pragma once

#include <iostream>
#include <vector>

#include "X.h"

enum Type
{
	Type_A,
	Type_AA,
	Type_AAA
};


class A
{
public:
	A(Type type) :m_data(3) 
	{
		m_vector.push_back(std::make_pair(type, this));
		std::cout << "A()" << m_data << std::endl;
		std::cout << "vector size in A()" << m_vector.size() << std::endl;
	};
	virtual ~A()
	{
		std::cout << "~A()" << m_data << std::endl;
	};

	int m_data;
	static std::vector<std::pair<Type, A*>> m_vector;
};

