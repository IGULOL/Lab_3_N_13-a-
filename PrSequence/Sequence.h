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

/*�������� �  MONEY ���������� COUT <<*/



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
	void add(Type entry);
	//������� ������� �� ��� ������
	void delete_ind(int n);
	//����� �������� (�� ������ ������ ���������� ��������) 
	int search(Type value);
	//����� ��������������������� (�� ������ ������ ������ ��������� ���������������������) 
	int search(Sequence seq);
	//������������ �������������������
	void concat(Sequence seq);

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
	if (count > 0)
		return false;
	return true;
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
void Sequence<Type>::add(Type entry)
{
	//�������� ����������� ������������������
	assert(count < MaxN);

	data[count] = entry;
	count++;
}

//������� ������� �� ��� ������
template <class Type>
void Sequence<Type>::delete_ind(int n)
{
	if (!is_empty())
	{
		for (size_type i = n; i < count; i++)
			data[i] = data[i + 1];
		count--;
	}
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
void Sequence<Type>::concat(Sequence seq)
{
	for (size_t i = 0; i < seq.count; i++)
	{
		add(seq.item(i));
	}
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
