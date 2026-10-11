#include "intro.h"
#include <iostream>
#include "fraction.h"

void intro() {
	std::cout << "Intro to OOP" << std::endl;

	fraction_t frac1;
	fraction_t* frac2 = new fraction_t;
	std::cout
		<< frac1.to_string() << std::endl
		<< frac2->to_string() << std::endl;

	fraction_t frac3(10);
	fraction_t* frac4 = new fraction_t(1, 10);
	std::cout
		<< frac3.to_string() << std::endl
		<< frac4->to_string() << std::endl;

	fraction_t frac5(1, 2, new char[] {"Half"});
	fraction_t* frac6 = new fraction_t(frac5);
	std::cout
		<< frac5.to_string() << std::endl
		<< frac6->to_string() << std::endl;

	fraction_t d = std::move(fraction_t::decil());
	std::cout << d.to_string() << std::endl;

	std::cout
		<< frac5.to_string() << " + " << d.to_string()
		<< " = " << (frac5 + d).to_string() << std::endl;

	std::cout << "-------------------------" << std::endl;
	fraction_t f;
	std::cout << f.to_string() << std::endl;
	f = d;
	std::cout << f.to_string() << std::endl;

	std::cout << "-------------------------" << std::endl;
	f = f + frac5;
	std::cout << f << std::endl;

	f = f * frac5;
	std::cout << f << std::endl;

	f = f / frac5;
	std::cout << f << std::endl;

	std::cout << -f << std::endl;

	f += 1;
	std::cout << "f += 1: " << f << std::endl;
	f += frac5;
	std::cout << f << std::endl;

	// === ДЕМОНСТРАЦІЯ РОБОТИ З КЛАСОМ ВЕКТОРА (vector2_t) ===
	std::cout << "\n--- Vector2_t Demonstration ---" << std::endl;
	vector2_t v1;
	vector2_t v2(3.5, -2.1);

	std::cout << "v1 (default): " << v1.to_string() << std::endl;
	std::cout << "v2 (params): " << v2.to_string() << std::endl;

	v1.set_x(5.2);
	v1.set_y(8.9);
	std::cout << "v1 after setters: " << v1.to_string() << std::endl;
	std::cout << "v2 coordinates -> x: " << v2.get_x() << ", y: " << v2.get_y() << std::endl;
	// ========================================================

	delete frac2;
	delete frac4;
	delete frac6;
}

/*
ООП. Вступ.
Парадигма - термін, що поєднує традиції, підходи, прийоми, методики тощо.
У програмуванні існують декілька парадигм:
- Імперативна парадигма (в яку входить процедурний підхід)
   програма вважається послідовністю інструкцій, серед яких лише одна
   виконується у даний момент часу. Окремі інструкції програми дозволяють
   змінювати порядок виконання (умови, цикли)
   Процедурний підхід - організація коду у вигяді набору процедур, тіла
   яких є послідовностями інструкцій
- Функціональна парадигма - базується на математично-функціональних засадах
   програма вважається "конвертом" у якому лежить інструкція, що слід
   зробити, та новий "конверт" над яким слід виконати цю дію.
   Представники: LISP, Python, J, TCL, Haskel
- Декларативна парадигма (в яку входить логічна) - базується на теорії знань
   програма складається за набору правил (аксіом) та твердження, яке
   слід перевірити (теореми)
   Представник: Prolog (5 покоління)
- Об'єктно-орієнтована парадигма (ООП) - базується на принципах взаємодії
   Розроблялась як засіб описання еволюційних систем, у яких задаються
   об'єкти та правила їх взаємодії. Суть програми - еволюція системи об'єктів.
   З точки зору практичного програмування вносить ідею колекцій - як
   розвиток поняття масиву, але з можливістю змін розміру (через еволюцію -
   роботу програми)
   Представники ООП: C#, Java, прототипної підпарадигми: JavaScript, Python, PHP
*/
/*
Центральними поняттями ООП є "клас" та "об'єкт"
Клас - тип даних (аналогічний структурі), що дозволяє поєднувати інші типи
 даних, а також методи. Клас можна порівняти з "кресленням" за яким створюються
 об'єкти.
Об'єкт - це елемент (instance) класу.

*/