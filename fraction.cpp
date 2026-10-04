#include "fraction.h"
#include <format>
#include <iostream>

fraction_t::fraction_t() {  // конструктор без параметрів - констуктор за замовчанням
	numerator = 0;          // f = new fraction_t  або  f = new fraction_t()
	denominator = 1;
	name = NULL;
}

fraction_t::fraction_t(int n) {  // конструктор з параметрами, його слід зазначати
	numerator = n;               // прямо (не за замовчанням) f = new fraction_t(10)
	denominator = 1;             // Присвоювання значень
	name = NULL;
}

fraction_t::fraction_t(int numerator, int denominator) : // ініціалізація полів
	numerator{ numerator }, denominator{ denominator }   // на відміну від присвоювання
{                                                        // дозволяє задавати значення
	name = NULL;                                         // незмінним полям (константам)
}                                                        // і комбінується з присвоєнням

fraction_t::fraction_t(int numerator, int denominator, char* name) :
	numerator{ numerator }, denominator{ denominator }, name{ name } {
}

fraction_t::fraction_t(fraction_t& other) {
	// конструктор копіювання (copy constructor), який будує новий об'єкт
	// за зразком іншого об'єкту.
	// Проблема: просте присвоєння полів об'єкта-зразка правильно працює для
	// полів зі значеннями, але неправильно - для покажчиків. Присвоювання 
	// this->name = other.name - створить другий покажчик на одне і те саме ім'я
	// деструктор одного об'єкта видаляє ресурс, а деструктор другого об'єкту 
	// призведе до помилки. Також другий об'єкт продовжить працювати з видаленною
	// памяттю. Копіювання - це утворення копій усіх ресурсів-покажчиків.
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	// для референсного ресурсу створюємо копію
	if (other.name != NULL) {
		this->name = new char[strnlen_s(other.name, 100) + 1];
		strcpy_s(this->name, 100, other.name);
		std::cout << "Copy constructor: copy from " << (void*)other.name << " to "
			<< (void*)this->name << std::endl;
	}
	else {
		this->name = NULL;
	}

	//   0x123("Half\0")               0x567("Half\0")
	// A[1/2"Half"] - A[1,2,0x123]     |
	// B = copy A   - B[1,2,0x123] - strcpy - B[1,2,0x567]
	// delete A - звільнення 0x123 --> В посилається на видалений ресурс
}

char* fraction_t::get_name() {
	return name;
}

void fraction_t::set_name(char* name) {
	this->name = name;
}

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
	// форматування рядків - заповнення "формату" - рядка з плейсхолдерами
	//                    v   v - placeholders
	return std::format("({0}/{1})", numerator, denominator);
	//                                  ^           ^
	//               дані, які будуть підставлені на міце плейсхолдерів
}

/*
Д.З. Описати клас, що задає вектор на площині (vector_2 / vector2_t)
склад: 2 поля-координати х та у (дробові)
+ аксессори для них
Розділити оголошення типу та реалізацію його методів на різні файли.
*/