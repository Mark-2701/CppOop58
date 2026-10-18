#pragma once
#include "Product.h"

class Electrical : public Product {
private:
	double power;
public:
	double getPower() const;
	void setPower(double);
};