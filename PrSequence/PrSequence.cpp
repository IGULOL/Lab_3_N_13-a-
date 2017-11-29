/*����������� ������ ������ ������������������ (Sequence<X>), �������� ��������
������������� ����. ����� ������ � ������������ ������� ��������� ������:
- ���������� �������� � �����; +
- ������ �������� � ������������������; +
- ������ ��������������������� � ������������������; +
- ������������ �������������������;
- ������ � �������� ������������������ �� ������; +
- �������� �������� ������������������ �� ������. +
a) ���������� ������������������ � ������� �������.*/

#include "stdafx.h"
#include "Sequence.h"
#include "Money.h"
#include "Windows.h";

int Menu()
{
	cout << "------------------------------------------------------\n";
	cout << "                         ����                         \n";
	cout << "------------------------------------------------------\n";
	cout << "1 - ���������� �������� � ����� ������������������.\n";
	cout << "2 - ����� �������� � ������������������.\n";
	cout << "3 - ����� ��������������������� � ������������������.\n";
	cout << "4 - ������������ �������������������.\n";
	//������ � �������� ������������������ �� ������
	cout << "5 - ������ �������� ������������������ �� ������.\n";
	cout << "6 - �������� �������� ������������������ �� ������.\n";
	cout << "7 - ������ ���� ��������� ������������������.\n";
	cout << "0 - �����.\n";
	cout << "------------------------------------------------------\n";
	int p;
	do {
		cout << ">> ";
		cin >> p;
		if ((p < 0) || (p > 7))
			cout << "�������� �������� �������. ��������� ����.\n";
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
	string str = "����";
	Money b(34.11);

	do
	{
		n = Menu();
		switch (n)
		{
		case 1: 
		{
			if (SeqInt.add(a))
				cout << "� SeqInt ���������: " << a << endl;
			if (SeqStr.add(str))
				cout << "� SeqStr ���������: " << str << endl;
			if (SeqMn.add(b))
				cout << "� SeqMn ���������: " << b << endl;
		}
		break;
		case 2:
		{
			cout << "��������� -1, ���� �� �������: \n";
			search_ind = SeqInt.search(6);
				cout << "����� �������� 6 � SeqInt: " << search_ind << endl;
				search_ind = SeqStr.search(str);
			cout << "����� �������� " << str << " � SeqStr : " << search_ind << endl;
			search_ind = SeqMn.search(b);
				cout << "����� �������� " << b << " � SeqMn: " << search_ind << endl;
		}
		break;
		case 3:
		{
			cout << "��������� -1, ���� �� �������: \n";
			cout << "����� ������ ���� ����: \n";
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
			cout << "������� � ����� ����. \n";
			if (SeqInt.concat(SeqInt))
				cout << "���������� � SeqInt �������.\n";
			if (SeqStr.concat(SeqStr))
				cout << "���������� � SeqStr �������.\n";
			if (SeqMn.concat(SeqMn))
				cout << "���������� � SeqMn �������.\n";
		}
		break;
		case 5:
		{
			if ((SeqInt.size() > 0) && (SeqStr.size() > 0) && (SeqStr.size() > 0))
			{
				cout << "������ ������ ���������: \n";
				cout << "������� SeqInt: " << SeqInt.item(0) << endl;
				cout << "������� SeqStr: " << SeqStr.item(0) << endl;
				cout << "������� SeqMn: " << SeqMn.item(0) << endl;
			}
			else
				cout << "��������� ���";
		}
		break;
		case 6:
		{
			if ((SeqInt.size() > 0) && (SeqStr.size() > 0) && (SeqStr.size() > 0))
			{
				cout << "�������� ������ ���������.\n";
				SeqInt.delete_ind(0);
				SeqStr.delete_ind(0);
				SeqMn.delete_ind(0);
			}
			else
				cout << "��������� ���.";
		}
		break;
		case 7:
		{
			if ((SeqInt.size() > 0) && (SeqStr.size() > 0) && (SeqStr.size() > 0))
			{
				cout << "������ ���� ���������: \n";
				cout << "�������� SeqInt: ";
				SeqInt.print();
				cout << "�������� SeqStr: ";
				SeqStr.print();
				cout << "�������� SeqMn: ";
				SeqMn.print();
			}
			else
				cout << "��������� ���";
		}
		break;
		}
		cout << endl;
	} while (n != 0);

	system("Pause");
    return 0;
}
