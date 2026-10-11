#pragma once
#include <string>
#include <iostream>

// Оголошення класу вектора на площині
class vector2_t {
private:
	double x; // координата x (дробова)
	double y; // координата y (дробова)

public:
	vector2_t();                    // конструктор за замовчуванням
	vector2_t(double x, double y);  // конструктор з параметрами

	// Аксесори (гетери та сетери)
	double get_x() const;
	double get_y() const;
	void set_x(double x);
	void set_y(double y);

	std::string to_string() const;
};

class fraction_t {
private:
	int numerator;
	int denominator;
	char* name;
	int gcd(int a, int b);
	void reduce();
public:
	int get_numerator() const;
	int get_denominator() const;
	void set_numerator(int);
	void set_denominator(int);
	char* get_name() const;
	void set_name(char*);
	std::string to_string() const;

	fraction_t();
	fraction_t(int);
	fraction_t(int, int);
	fraction_t(int, int, char*);
	fraction_t(fraction_t&);
	fraction_t(fraction_t&&) noexcept;

	~fraction_t();

	static fraction_t decil() {
		fraction_t d(1, 10, new char[] {"Decil"});
		return d;
	}

	fraction_t operator +(const fraction_t& other);
	fraction_t& operator =(const fraction_t& other);
	fraction_t& operator =(fraction_t&& other) noexcept;

	void operator += (const fraction_t& other);
	void operator += (int n);

	friend fraction_t operator *(const fraction_t& f1, const fraction_t& f2);
};

fraction_t operator *(const fraction_t& f1, const fraction_t& f2);
fraction_t operator /(const fraction_t& f1, const fraction_t& f2);
fraction_t operator -(const fraction_t& f);

std::ostream& operator <<(std::ostream& out, const fraction_t& f);