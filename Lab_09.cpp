﻿// Лаборатораня работа №9, вариант 3.
// 	Скопировать в файл F2 только те строки из F1,  кото-рые начинаются и заканчиваются на одну и ту же букву.
// 	Подсчитать количество символов в  F2.

//https://www.cyberforum.ru/c-beginners/thread1608778.html

#include <iostream>
#include <fstream>
#include <cstdlib>      // Для функции srand
#include <string>       // Строковый тип данных
#include <windows.h>    // Библиотека для русской локализации

using namespace std;   // Для сокращения cout cin, ofstream

int main()
{
	SetConsoleCP(1251);         // Ввод с консоли в кодировке 1251 для русской локализации.
	SetConsoleOutputCP(1251);   // Вывод на консоль в кодировке 1251 для русской локализации.

	string text[10], k;
	/* заполняем массив случайными строками */
	for (int i = 0; i < 10; i++) {
		cout << "Введите текст " << i + 1 << "-ой строки: ";
		cin >> k;
		text[i] = k;
	}
	/*создаем объект F1, который создаст файл F1.txt
	циклом for заполнеяем файл из массива text[10] */
	ofstream F1("F1.txt", ios_base::trunc);
	for (int i = 0; i < 10; i++)
	{
		F1 << text[i] << endl;
	}

	/* создаем объект,чтобы считать из файла F1.txt данные*/
	ifstream F1_1("F1.txt");
	string second_text[10];
	for (int i = 0; !F1_1.eof(); i++)
	{
		F1_1 >> second_text[i];
	}
	/* создаем объект F2 ,в который записываем одинаковые слова которые начинаются и заканчиваются на одну и ту же букву */
	ofstream F2("F2.txt", ios_base::trunc);
	for (int i = 0; i < 10; i++)
	{
		if (second_text[i] == second_text[second_text[i].size() - 1])
		{
			F2 << second_text[i] << endl;
		}
	
	}
	cout << "Готово, файлы хранятся в корневой папке проекта!";
	return 0;
}
