#pragma once

#include "D.h"
#include "E.h"

class DD : public D, public E
{
public:
	DD() { std::cout << "DD()" << D::m_data << std::endl; };
	~DD() override { std::cout << "~DD()" << E::m_data << std::endl; };
};