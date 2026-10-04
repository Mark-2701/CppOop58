#include "fraction.h"
#include <format>

int fraction_t::get_numerator() {
	return numerator;
}

int fraction_t::get_denominator() {
	return denominator;
}

void fraction_t::set_numerator(int numerator) {
	this->numerator = numerator;
	/* this - покажчик на об'єкт, неявний параметр, що передається у
	   нестатичні методи класу. */
}

void fraction_t::set_denominator(int denominator) {
	this->denominator = denominator;
}

std::string fraction_t::to_string() {
	return std::format("({}/{})", numerator, denominator);
}

/*
Д.З. Описати клас, що задає вектор на площині (vector_2 / vector2_t)
склад: 2 поля-координати х та у (дробові)
+ аксессори для них
Розділити оголошення типу та реалізацію його методів на різні файли.
*/