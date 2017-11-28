#pragma once

#include "stdafx.h"
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class Money
{

public:

	//конструктор (Init)
	Money()
	{
		rubles = 0;
		kopecks = 0;
		sumM = 0;
	}

	Money(double sum)
	{
		rubles = (int)sum;
		//точность 3 символа после запятой
		kopecks = (sum - (int)sum) * 1000;
		if (kopecks % 10 == 9)
			kopecks += 1;
		//сокращаем до двух символов
		kopecks = kopecks / 10;

		//сохраняем сумму со знаком
		if (sum < 0)
			sumM = (-1)*(rubles + ((int)kopecks)*0.01);
		else
			sumM = rubles + ((int)kopecks)*0.01;
	};

	//ввод с клавиатуры
	void Read()
	{
		cin >> sumM;
		rubles = (int)sumM;
		//точность 3 символа после запятой
		kopecks = (sumM - (int)sumM) * 1000;
		if (kopecks % 10 == 9)
			kopecks += 1;
		//сокращаем до двух символов
		kopecks = kopecks / 10;
	}

	//вывод на экран
	void Display()
	{
		if (sumM < 0)
			cout << "-";
		cout << rubles << ",";
		if ((int)kopecks < 10)
			cout << "0";
		cout << (int)kopecks << endl;
	}

	//преобразование в строку
	string toString()
	{
		string strMoney = "";
		if (sumM < 0)
			strMoney = strMoney + "-";
		strMoney = strMoney + to_string(rubles) + ",";
		if ((int)kopecks < 10)
			strMoney += "0";
		strMoney += to_string(kopecks);
		return strMoney;
	}

	//ПЕРЕГРУЗКА ОСНОВНЫХ ОПЕРАЦИЙ
	friend ostream& operator<<(ostream& os, const Money& m1)
	{
		if (m1.sumM < 0)
			os << "-";
		os << m1.rubles << ",";
		if ((int)(m1.kopecks) < 10)
			os << "0";
		os << (int)(m1.kopecks);
		return os;
	}

	Money operator+ (Money m2)
	{
		double sumRes = sumM + m2.sumM;
		return Money(sumRes);
	}

	Money operator- (Money m2)
	{
		double sumRes = sumM - m2.sumM;
		return Money(sumRes);
	}

	Money operator/ (Money m2)
	{
		double sumRes = sumM / m2.sumM;
		return Money(sumRes);
	}

	Money operator/ (double sumM2)
	{
		double sumRes = sumM / sumM2;
		return Money(sumRes);
	}

	Money operator* (Money m2)
	{
		double sumRes = sumM * m2.sumM;
		return Money(sumRes);
	}

	Money operator* (double sumM2)
	{
		double sumRes = sumM * sumM2;
		return Money(sumRes);
	}

	bool operator== (Money m2) const
	{
		return ((rubles == m2.rubles) && (kopecks == m2.kopecks)) ? true : false;
	}

	bool operator> (Money m2) const
	{
		bool res1 = (rubles > m2.rubles) || ((rubles == m2.rubles) && (kopecks > m2.kopecks));
		//false включает m1<=m2
		return res1 ? true : false;
	}

	bool operator< (Money m2) const
	{
		bool res1 = (m2.rubles > rubles) || ((rubles == m2.rubles) && (m2.kopecks > kopecks));
		//false включает m1>=m2
		return res1 ? true : false;
	}

	bool operator>= (Money m2) const
	{
		bool res1 = (m2.rubles > rubles) || ((rubles == m2.rubles) && (m2.kopecks > kopecks));
		//true включает m1>=m2
		return res1 ? false : true;
	}

	bool operator<= (Money m2) const
	{
		bool res1 = (rubles > m2.rubles) || ((rubles == m2.rubles) && (kopecks > m2.kopecks));
		//false включает m1<=m2
		return res1 ? false : true;
	}

private:

	long rubles;
	unsigned char kopecks;
	double sumM;

};

