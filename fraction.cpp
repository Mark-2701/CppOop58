#define _CRT_SECURE_NO_WARNINGS
#include "fraction.h"
#include <format>
#include <iostream>

fraction_t::fraction_t() {
	numerator = 0;
	denominator = 1;
	name = NULL;
}

fraction_t::fraction_t(int n) {
	numerator = n;
	denominator = 1;
	name = NULL;
}

fraction_t::fraction_t(int numerator, int denominator) :
	numerator{ numerator }, denominator{ denominator }
{
	name = NULL;
}

fraction_t::fraction_t(int numerator, int denominator, char* name) :
	numerator{ numerator }, denominator{ denominator }, name{ name } {
}

fraction_t::fraction_t(fraction_t& other) {
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	if (other.name != NULL) {
		size_t len = strlen(other.name) + 1;
		this->name = new char[len];
		strcpy(this->name, other.name);
		std::cout << "Copy constructor: copy from " << (void*)other.name << " to "
			<< (void*)(this->name) << std::endl;
	}
	else {
		this->name = NULL;
	}
}

fraction_t::fraction_t(fraction_t&& other) noexcept {
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	this->name = other.name;
	other.name = NULL;
	std::cout << "Move constructor: take from " << (void*)this->name << std::endl;
}

char* fraction_t::get_name() const {
	return name;
}

void fraction_t::set_name(char* name) {
	this->name = name;
}

int fraction_t::get_numerator() const {
	return numerator;
}

int fraction_t::get_denominator() const {
	return denominator;
}

void fraction_t::set_numerator(int numerator) {
	this->numerator = numerator;
}

void fraction_t::set_denominator(int denominator) {
	this->denominator = denominator;
}

std::string fraction_t::to_string() const {
	return std::format("({0}/{1}{2})", numerator, denominator, (name == NULL ? "" : name));
}

fraction_t::~fraction_t() {
	if (name != NULL) {
		delete[] name;
	}
}

fraction_t fraction_t::operator +(const fraction_t& other) {
	char* new_name = NULL;
	if (this->name != NULL && other.name != NULL) {
		size_t len1 = strlen(this->name);
		size_t len = len1 + strlen(other.name) + 2;
		new_name = new char[len];
		strcpy(new_name, this->name);
		strcpy(new_name + len1, "+");
		strcpy(new_name + len1 + 1, other.name);
	}
	return fraction_t(
		this->numerator * other.denominator + this->denominator * other.numerator,
		this->denominator * other.denominator,
		new_name);
}

fraction_t& fraction_t::operator =(const fraction_t& other) {
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	if (other.name != NULL) {
		size_t len = strlen(other.name) + 1;
		this->name = new char[len];
		strcpy(this->name, other.name);
	}
	else {
		this->name = NULL;
	}
	return *this;
}

fraction_t& fraction_t::operator =(fraction_t&& other) noexcept {
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	this->name = other.name;
	other.name = NULL;
	return *this;
}

fraction_t operator *(const fraction_t& f1, const fraction_t& f2) {
	return fraction_t(
		f1.numerator * f2.numerator,
		f1.denominator * f2.denominator
	);
}

fraction_t operator /(const fraction_t& f1, const fraction_t& f2) {
	return fraction_t(
		f1.get_numerator() * f2.get_denominator(),
		f1.get_denominator() * f2.get_numerator()
	);
}

std::ostream& operator <<(std::ostream& out, const fraction_t& f) {
	out << f.to_string();
	return out;
}

fraction_t operator -(const fraction_t& f) {
	return fraction_t(
		-f.get_numerator(),
		f.get_denominator()
	);
}

void fraction_t::operator += (const fraction_t& other) {
	this->numerator = this->numerator * other.denominator + this->denominator * other.numerator;
	this->denominator = this->denominator * other.denominator;
	reduce();
}

void fraction_t::operator += (int n) {
	this->numerator += n * this->denominator;
	reduce();
}

int fraction_t::gcd(int a, int b) {
	if (a < 0) a = -a;
	if (b < 0) b = -b;
	if (b > a) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a % b);
}

void fraction_t::reduce() {
	int g = gcd(numerator, denominator);
	if (g != 1) {
		numerator /= g;
		denominator /= g;
	}
}

// === РЕАЛІЗАЦІЯ МЕТОДІВ КЛАСУ vector2_t ===
vector2_t::vector2_t() : x(0.0), y(0.0) {}

vector2_t::vector2_t(double x, double y) : x(x), y(y) {}

double vector2_t::get_x() const {
	return x;
}

double vector2_t::get_y() const {
	return y;
}

void vector2_t::set_x(double x) {
	this->x = x;
}

void vector2_t::set_y(double y) {
	this->y = y;
}

std::string vector2_t::to_string() const {
	return std::format("({0}, {1})", x, y);
}
/*
Правило опису класів (The Rule Of Six):
При описі класів необхідно обов'язково включити до опису
- конструктор за замовчанням
- конструктор копіювання
- конструктор перенесення
- оператор = копіювання
- оператор = перенесення
- деструктор
~ інколи додають параметризований конструктор
*/

/*
Д.З. Описати клас, що задає вектор на площині (vector_2 / vector2_t)
склад: 2 поля-координати х та у (дробові)
+ аксессори для них
Розділити оголошення типу та реалізацію його методів на різні файли.

Д.З. Реалізувати для класу, що задає вектор на площині (попереднє ДЗ)
додати поле для імені вектора (char*), аксесори для нього
конструктори (без параметрів, з різними параметрами, конструктор копіювання)
метод рядкового представлення (to_string), що включає ім'я (якщо воно є)
деструктор
Створити декілька об'єктів - векторів, у т.ч. за допомогою копіювання,
вивести дані на екран. Додати скріншот і посилання  на репозиторій.
*/