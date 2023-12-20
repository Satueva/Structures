﻿#include <iostream>
#include <string>

struct Date {
	int day = 1;
	int month = 1;
	int year = 1970;
	std::string note = "empty"; // или {empty};
};

void print_date(const Date& D) {
	std::cout << D.day << '.' << D.month << '.' << D.year << " - " << D.note << std::endl;
}

Date enter_date() {
	Date result;

	std::cout << "Введите день  -> ";
	std::cin >> result.day;
	std::cout << "Введите месяц -> ";
	std::cin >> result.month;
	std::cout << "Введите год - > ";
	std::cin >> result.year;

	std::cin.ignore();
	std::cout << "Введите запись -> ";
	std::getline(std::cin, result.note);

	return result;
};

void fill_date(Date& D) {
	std::cout << "Введите день  -> ";
	std::cin >> D.day;
	std::cout << "Введите месяц -> ";
	std::cin >> D.month;
	std::cout << "Введите год - > ";
	std::cin >> D.year;

	std::cin.ignore();
	std::cout << "Введите запись -> ";
	std::getline(std::cin, D.note);
};

struct Date2 {
	int day = 1;
	int month = 1;
	int year = 1970;
};

struct CoinsKeeper {
	std::string name;
	Date2 birthday;
	int coins_number = 0;
	int* coins = nullptr;
};

void print_keeper(const CoinsKeeper &CK) {
	std::cout << "Имя: " << CK.name << std::endl;
	std::cout << "Дата рождения: " << CK.birthday.day << '.' << CK.birthday.month << '.' << CK.birthday.year << std::endl;
	std::cout << "Монеты: ";
	for (int i = 0; i < CK.coins_number; i++)
		std::cout << CK.coins[i] << ", ";
	std::cout << "\b\b \n";
	
}

inline int age(const CoinsKeeper& CK, int year) {
	return (year - CK.birthday.year);
}


int cash(const CoinsKeeper& CK) {
	int sum = 0;
	for (int i = 0; i < CK.coins_number; i++)
		sum += CK.coins[i];
	return sum;
}


int main() {
	setlocale(LC_ALL, "Russian");

	// Структура - описание множества, состоящая из одной или более переменных,
	// возможно




	// Создание структур.
	int n;
	struct Person {
		std::string name;
		int age;
		std::string job;
		int	salary;
	} p4, p5, p6{  };

	Person p1; // создание объекта структуры
	p1.name = "Thomas";
	p1.age = 18;
	p1.job = "programmer";
	p1.salary = 60000;

	std::cout << "Имя: " << p1.name << std::endl;
	std::cout << "Возраст: " << p1.age << std::endl;
	std::cout << "Должность: " << p1.job << std::endl;
	std::cout << "Зарплата: " << p1.salary << std::endl;

	std::cout << "-----------------------------\n";

	Person p2{
		"Rodion",
		30,
		"director",
		120000
	};

	std::cout << "Имя: " << p2.name << std::endl;
	std::cout << "Возраст: " << p2.age << std::endl;
	std::cout << "Должность: " << p2.job << std::endl;
	std::cout << "Зарплата: " << p2.salary << std::endl;


	Person p3 = p1; // копирование значений полей объекта
	// p1 в поля объекта p3.


	//int arr[3];
	//arr[0];
	//arr[1];
	//arr[2];
	//arr[3];
	//int arr[5] { 1, 10, 100 };





	// Указатель на объекты
	Date d1{20, 12, 2023};

	print_date(d1);

	Date* pd1 = &d1;
	std::cout << pd1->day << std::endl; // обращение к полю объекта через указатель на сам объект.



	// Структуры и функциию
	Date d2 = enter_date();
	print_date(d2);



	Date d3;
	fill_date(d3);
	print_date(d3);



	// Задача 1. Хранитель монет.
	std::cout << "\n";
	CoinsKeeper ck{
		"Margot",
		{29, 7, 2013},
		6,
		new int[6]{ 5, 1, 2, 5, 2, 1 }
	};

	print_keeper(ck);
	std::cout << "Возраст: " << age(ck, 2023) << std::endl;
	std::cout << "Общие сбеpежения: " << cash(ck) << std::endl;


	return 0;
}