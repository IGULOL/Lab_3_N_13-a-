/*Реализовать шаблон класса последовательность (Sequence<X>), хранящий элементы
произвольного типа. Класс должен в обязательном порядке содержать методы:
- Добавление элемента в конец; +
- Поиска элемента в последовательности; +
- Поиска подпоследовательности в последовательности; +
- Конкатенация последовательностей;
- Доступ к элементу последовательности по номеру; +
- Удаления элемента последовательности по номеру. +
a) Реализация последовательности с помощью массива.*/

#include "stdafx.h"
#include "Sequence.h"
#include "Money.h"
#include "Windows.h";

int Menu()
{
	cout << "------------------------------------------------------\n";
	cout << "                         МЕНЮ                         \n";
	cout << "------------------------------------------------------\n";
	cout << "1 - Добавление элемента в конец последовательности.\n";
	cout << "2 - Поиск элемента в последовательности.\n";
	cout << "3 - Поиск подпоследовательности в последовательности.\n";
	cout << "4 - Конкатенация последовательностей.\n";
	//Доступ к элементу последовательности по номеру
	cout << "5 - Печать элемента последовательности по номеру.\n";
	cout << "6 - Удаления элемента последовательности по номеру.\n";
	cout << "7 - Печать всех элементов последовательности.\n";
	cout << "0 - Выход.\n";
	cout << "------------------------------------------------------\n";
	int p;
	do {
		cout << ">> ";
		cin >> p;
		if ((p < 0) || (p > 7))
			cout << "Введеное значение неверно. Повторите ввод.\n";
	} while ((p < 0) || (p > 7));
	getchar();
	cout << "\n";
	return p;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Sequence<int> SeqInt;
	Sequence<string> SeqStr;
	Sequence<Money> SeqMn;

	int n;
	int search_ind;

	int a = 5;
	string str = "ежик";
	Money b(34.11);

	do
	{
		n = Menu();
		switch (n)
		{
		case 1: 
		{
			if (SeqInt.add(a))
				cout << "В SeqInt добавлено: " << a << endl;
			if (SeqStr.add(str))
				cout << "В SeqStr добавлено: " << str << endl;
			if (SeqMn.add(b))
				cout << "В SeqMn добавлено: " << b << endl;
		}
		break;
		case 2:
		{
			cout << "Результат -1, если не найдено: \n";
			search_ind = SeqInt.search(6);
				cout << "Поиск элемента 6 в SeqInt: " << search_ind << endl;
				search_ind = SeqStr.search(str);
			cout << "Поиск элемента " << str << " в SeqStr : " << search_ind << endl;
			search_ind = SeqMn.search(b);
				cout << "Поиск элемента " << b << " в SeqMn: " << search_ind << endl;
		}
		break;
		case 3:
		{
			cout << "Результат -1, если не найдено: \n";
			cout << "Пусть найдет саму себя: \n";
			search_ind = SeqInt.search(SeqInt);
				cout << search_ind << endl;
			search_ind = SeqStr.search(SeqStr);
				cout << search_ind << endl;
			search_ind = SeqMn.search(SeqMn);
				cout << search_ind << endl;
		}
		break;
		case 4:
		{
			cout << "Добавим к самой себе. \n";
			if (SeqInt.concat(SeqInt))
				cout << "Добавление в SeqInt удалось.\n";
			if (SeqStr.concat(SeqStr))
				cout << "Добавление в SeqStr удалось.\n";
			if (SeqMn.concat(SeqMn))
				cout << "Добавление в SeqMn удалось.\n";
		}
		break;
		case 5:
		{
			if ((SeqInt.size() > 0) && (SeqStr.size() > 0) && (SeqStr.size() > 0))
			{
				cout << "Печать первых элементов: \n";
				cout << "Элемент SeqInt: " << SeqInt.item(0) << endl;
				cout << "Элемент SeqStr: " << SeqStr.item(0) << endl;
				cout << "Элемент SeqMn: " << SeqMn.item(0) << endl;
			}
			else
				cout << "Элементов нет";
		}
		break;
		case 6:
		{
			if ((SeqInt.size() > 0) && (SeqStr.size() > 0) && (SeqStr.size() > 0))
			{
				cout << "Удаление первых элементов.\n";
				SeqInt.delete_ind(0);
				SeqStr.delete_ind(0);
				SeqMn.delete_ind(0);
			}
			else
				cout << "Элементов нет.";
		}
		break;
		case 7:
		{
			if ((SeqInt.size() > 0) && (SeqStr.size() > 0) && (SeqStr.size() > 0))
			{
				cout << "Печать всех элементов: \n";
				cout << "Элементы SeqInt: ";
				SeqInt.print();
				cout << "Элементы SeqStr: ";
				SeqStr.print();
				cout << "Элементы SeqMn: ";
				SeqMn.print();
			}
			else
				cout << "Элементов нет";
		}
		break;
		}
		cout << endl;
	} while (n != 0);

	system("Pause");
    return 0;
}
