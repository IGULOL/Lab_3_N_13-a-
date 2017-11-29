/*����������� ������ ������ ������������������ (Sequence<X>), �������� ��������
������������� ����. ����� ������ � ������������ ������� ��������� ������:
- ���������� �������� � �����; +
- ������ �������� � ������������������; +
- ������ ��������������������� � ������������������; +
- ������������ �������������������;
- ������ � �������� ������������������ �� ������; +
- �������� �������� ������������������ �� ������. +
a) ���������� ������������������ � ������� �������.*/

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
	//������������ �����������
	static const size_type MaxN = 30;

	//�����������
	Sequence();

	//���������� ���������� ��������� � ������������������
	size_type size() const;
	//��������� ����� �� ������������������
	bool is_empty() const;
	//���������� ������� �� �������
	Type item(int n) const;

	//������� �������� � ����� ������������������
	bool add(Type entry);
	//������� ������� �� ��� ������
	bool delete_ind(int n);
	//����� ���� ���� (�� ������ ������ ���������� ��������) 
	int search(Type value);
	//����� ��������������������� (�� ������ ������ ������ ��������� ���������������������) 
	int search(Sequence seq);
	//������������ �������������������
	bool concat(Sequence seq);

	//������ ��������� ������������������
	void print();

private:
	//������
	Type data[MaxN];
	//���������� ��������� � ������������������
	size_type count;
};

//�����������
template <class Type>
Sequence<Type>::Sequence()
{
	count = 0;
}

//���������� ���������� ��������� � ������������������
template <class Type>
size_t Sequence<Type>::size() const
{
	return count;
}

//��������� ����� �� ������������������
template <class Type>
bool Sequence<Type>::is_empty() const
{
	return (count == 0);
}

//���������� ������� �� �������
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

//������� ������� �� ��� ������
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

//����� �������� (�� ������ ������ ���������� ��������) 
//���� ������ �������� ���, �� �� ������ -1
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

//����� ��������������������� (�� ������ ������ ������ ��������� ���������������������)
//���� ������ �������� ���, �� �� ������ -1
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

//������������ �������������������
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
