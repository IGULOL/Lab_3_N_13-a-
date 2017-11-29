/*Реализовать шаблон класса последовательность (Sequence<X>), хранящий элементы
произвольного типа. Класс должен в обязательном порядке содержать методы:
- Добавление элемента в конец; +
- Поиска элемента в последовательности; +
- Поиска подпоследовательности в последовательности; +
- Конкатенация последовательностей;
- Доступ к элементу последовательности по номеру; +
- Удаления элемента последовательности по номеру. +
a) Реализация последовательности с помощью массива.*/

#pragma once
#include < iostream >
#include < string >
#include < cassert >
#include  < cstdlib >
using namespace std;


template <class Type>
class Sequence
{
public:

	typedef std::size_t size_type;
	//максимальная вместимость
	static const size_type MaxN = 30;

	//конструктор
	Sequence();

	//возвращает количество элементов в последовательности
	size_type size() const;
	//проверяет пуста ли последовательность
	bool is_empty() const;
	//возвращает элемент по индексу
	Type item(int n) const;

	//вставка элемента в конец последовательности
	bool add(Type entry);
	//удалить элемент по его номеру
	bool delete_ind(int n);
	//поиск элем ента (на выходе индекс найденного элемента) 
	int search(Type value);
	//поиск подпоследовательности (на выходе индекс начала найденной подпоследовательности) 
	int search(Sequence seq);
	//конкатенация последовательностей
	bool concat(Sequence seq);

	//печать элементов последовательности
	void print();

private:
	//массив
	Type data[MaxN];
	//количество элементов в последовательности
	size_type count;
};

//конструктор
template <class Type>
Sequence<Type>::Sequence()
{
	count = 0;
}

//возвращает количество элементов в последовательности
template <class Type>
size_t Sequence<Type>::size() const
{
	return count;
}

//проверяет пуста ли последовательность
template <class Type>
bool Sequence<Type>::is_empty() const
{
	return (count == 0);
}

//возвращает элемент по индексу
template <class Type>
Type Sequence<Type>::item(int n) const
{
	if (!is_empty())
		return data[n];
	else
		return 0;
}



template <class Type>
bool Sequence<Type>::add(Type entry)
{
	if (count == MaxN)
		return false;
	else
	{
		data[count] = entry;
		count++;
		return true;
	}
}

//удалить элемент по его номеру
template <class Type>
bool Sequence<Type>::delete_ind(int n)
{
	if (!is_empty())
	{
		for (size_type i = n; i < count; i++)
			data[i] = data[i + 1];
		count--;
		return true;
	}
	else
		return false;
}

//поиск элемента (на выходе индекс найденного элемента) 
//если такого элемента нет, то на выходе -1
template <class Type>
int Sequence<Type>::search(Type value)
{
	int index = -1;
	if (!is_empty())
	{
		bool ok = false;
		for (size_type i = 0; (i < count) && !ok; i++)
		{
			if (data[i] == value)
			{
				ok = true;
				index = i;
			}
		}
	}
	return index;
}

//поиск подпоследовательности (на выходе индекс начала найденной подпоследовательности)
//если такого элемента нет, то на выходе -1
template <class Type>
int Sequence<Type>::search(Sequence seq)
{
	int index = -1;
	if (!is_empty() && !seq.is_empty())
	{
		bool ok = false;
		for (size_type i = 0; (i < count) && !ok; i++)
		{
			int j = 0;
			if (data[i] == seq.data[j])
			{
				index = i;
				ok = true;
				for (j = 0; (i < count) && (j < seq.count) && ok; j++)
				{
					i++;
					ok = (data[i] == seq.data[j]);
				}
				if (ok && j == seq.count)
					return index;
			}
		}
	}
	return index;
}

//конкатенация последовательностей
template <class Type>
bool Sequence<Type>::concat(Sequence seq)
{
	if (seq.count <= MaxN - count)
	{
		int i = 0;
		while ((i < seq.count) && (add(seq.item(i))))
			i++;
		return true;
	}
	else
		return false;
}

template <class Type>
void Sequence<Type>::print()
{
	cout << "{";
	for (size_type i = 0; i < count; i++)
	{
		cout << data[i];
		if (i != count - 1)
			cout << "; ";
	}
	cout << "}\n";
}
