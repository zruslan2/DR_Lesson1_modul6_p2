#include <locale.h>
#include <math.h>
#include <vector>
#include <time.h>
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

void head(char mas[]);
void yellow();
void white();
void red();
bool IsLeapYear(int Y);
int MonthDays(int M, int Y);
void NextDate(int *D, int *M, int *Y);
double f(double x, double y);
double f1(double x1, double y1, double x2, double y2);
int f2(int m2, int m1, int m0);

using namespace std;
unsigned short int nz;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(0));

	int i, j;
	while (true)
	{
		cout << "Введите номер задания, 0 - для выхода "; cin >> nz;

		if (nz == 0)
		{
			break;
			system("exit");
		}
		else if (nz == 1)
		{
			/*6.	Используя функцию MonthDays из задания 4, описать процедуру NextDate(D, M, Y), 
				которая по информации о правильной дате, включаю - щей день D, номер месяца M и 
				год Y, определяет следующую дату(пара - метры целого типа D, M, Y являются 
				одновременно входными и выходными).Применить процедуру NextDate к трем исходным 
				датам и вывести полученные значения следующих дат.*/
			head("5. Используя функцию MonthDays из задания 4, описать процедуру NextDate(D, M, Y), которая по информации о дате (день D, месяц M и год Y), определяет следующую дату (параметры D, M, Y являются одновременно входными и выходными). Применить процедуру NextDate к трем датам и вывести полученные значения предыдущих дат");
			int Y = 2008, M = 2, D = 29;
			yellow();
			cout << " Дата: " << D << "." << M << "." << Y << endl << endl;
			NextDate(&D, &M, &Y);
			white();
			cout << " Следующая дата: " << D << "." << M << "." << Y << endl << endl;

			Y = 2017; M = 12; D = 31;
			yellow();
			cout << " Дата: " << D << "." << M << "." << Y << endl << endl;
			NextDate(&D, &M, &Y);
			white();
			cout << " Следующая дата: " << D << "." << M << "." << Y << endl << endl;

			time_t t;
			tm *tk;
			time(&t);
			tk = localtime(&t);
			Y = 1900 + tk->tm_year;
			M = 1 + tk->tm_mon;
			D = tk->tm_mday;

			yellow();
			cout << " Дата: " << D << "." << M << "." << Y << endl << endl;
			NextDate(&D, &M, &Y);
			white();
			cout << " Следующая дата: " << D << "." << M << "." << Y << endl << endl;
		}
		else if (nz == 2)
		{
			/*7.	Используя функцию Dist из задания Proc59, описать процедуру 
				Altitudes(xA, yA, xB, yB, xC, yC, hA, hB, hC), находящую высоты hA, hB, hC 
				треугольника ABC(выходные параметры), проведенные соответственно из вершин 
				A, B, C(их координаты являются входными параметрами).С помощью этой процедуры 
				найти высоты треугольников ABC, ABD, ACD, если даны координаты точек A, B, C, D.*/

			// У нас нет функции Dist и задания Proc59
		}
		else if (nz == 3)
		{
			/*8.	Определите функцию double f(double x, double y), которая вычисляет и возвращает 
				длину гипотенузы прямоугольного треугольника, две другие стороны x и y которого 
				известны.*/
			head("8. Определите функцию double f(double x, double y), которая вычисляет и возвращает длину гипотенузы прямоугольного треугольника, две другие стороны x и y которого известны.");
			double x, y;
			x = (1.2 + rand() % 20) / (1.2 + rand() % 20);
			y = (1.2 + rand() % 20) / (1.2 + rand() % 20);
			yellow();
			cout << " Первый катет = "<<x<<endl;
			cout << " Второй катет = " << y << endl;
			cout << " Гипотенуза = " << f(x, y) << endl<<endl;
			white();
		}
		else if (nz == 4)
		{
			/*9.	Напишите функцию double f(double x1, double y1, double x2, double y2), которая 
				вычисляет расстояние между двумя точками(xl, yl) и(x2, y2).*/
			head("9. Напишите функцию double f(double x1, double y1, double x2, double y2), которая вычисляет расстояние между двумя точками (xl, yl) и (x2, y2).");
			double x1, x2, y1, y2;
			x1 = (1.2 + rand() % 20) / (1.2 + rand() % 20);
			y1 = (1.2 + rand() % 20) / (1.2 + rand() % 20);
			x2 = (1.2 + rand() % 20) / (1.2 + rand() % 20);
			y2 = (1.2 + rand() % 20) / (1.2 + rand() % 20);
			yellow();
			cout << " Координаты первой точки = " << x1<<","<<y1 << endl;
			cout << " Координаты второй точки = " << x2 << "," << y2 << endl;
			cout << " Расстояние между точками = " << f1(x1, y1, x2, y2) << endl << endl;
			white();
		}
		else if (nz == 5)
		{
			/*10.	Напишите функцию int f(int m2, int m1, int m0), которая вычисляет и возвращает 
				натуральное число, первая(сотни), вторая(десятки) и третья(единицы) цифры 
				которого равны соответственно m2, m1, m0.*/
			head("10. Напишите функцию int f(int m2, int m1, int m0), которая вычисляет и возвращает натуральное число, первая (сотни), вторая (десятки) и третья (единицы) цифры которого равны соответственно m2, m1, m0.");
			int ch1, ch2, ch3;
			ch1 = 1 + rand() % 9;
			ch2 = 1 + rand() % 9;
			ch3 = 1 + rand() % 9;
			yellow();
			cout << " Числа " << endl;
			white();
			cout << ch1 << endl;
			cout << ch2 << endl;
			cout << ch3 << endl;
			yellow();
			cout << " Функция возвращает число " << f2(ch1, ch2, ch3) << endl << endl;
			white();
		}
	}
}


void head(char mas[])
{
	int len, third, s1_len, s2_len, s3_len, maks;
	len = strlen(mas);
	third = len / 3;
	s1_len = third;
	for (int i = s1_len; i < len; i++)
	{
		if (mas[s1_len] != ' ') s1_len++;
		else break;
	}
	s2_len = third;
	for (int i = s1_len + s2_len; i < len; i++)
	{
		if (mas[s1_len + s2_len] != ' ') s2_len++;
		else break;
	}
	s3_len = len - (s1_len + s2_len);
	vector<char>str1(s1_len);
	vector<char>str2(s2_len);
	vector<char>str3(s3_len);
	for (int i = 0; i < s1_len; i++)
	{
		str1[i] = mas[i];
	}
	for (int i = s1_len + 1; i < s1_len + s2_len; i++)
	{
		str2[i - (s1_len + 1)] = mas[i];
	}
	for (int i = s1_len + s2_len + 1; i < len; i++)
	{
		str3[i - (s1_len + s2_len + 1)] = mas[i];
	}
	maks = s1_len;
	if (s2_len > maks)maks = s2_len;
	if (s3_len > maks)maks = s3_len;
	system("cls");
	SetConsoleTextAttribute(hConsole, 11);
	setlocale(LC_ALL, ".866");
	cout << " Ъ";
	for (int i = 0; i <= maks + 1; i++)cout << "Д";
	cout << "ї\n";
	cout << " і "; setlocale(LC_ALL, ".1251");
	for (int i = 0; i<s1_len; i++) cout << str1[i];
	if (s1_len < maks)
	{
		for (int i = 0; i < maks - s1_len; i++)cout << " ";
	}
	setlocale(LC_ALL, ".866"); cout << " і\n";
	cout << " і "; setlocale(LC_ALL, ".1251");
	for (int i = 0; i<s2_len; i++) cout << str2[i];
	if (s2_len < maks)
	{
		for (int i = 0; i < maks - s2_len; i++)cout << " ";
	}
	setlocale(LC_ALL, ".866"); cout << " і\n";
	cout << " і "; setlocale(LC_ALL, ".1251");
	for (int i = 0; i<s3_len; i++) cout << str3[i];
	if (s3_len < maks)
	{
		for (int i = 0; i < maks - s3_len; i++)cout << " ";
	}
	setlocale(LC_ALL, ".866"); cout << " і\n";
	cout << " А";
	for (int i = 0; i <= maks + 1; i++)cout << "Д";
	cout << "Щ\n";
	SetConsoleTextAttribute(hConsole, 15);
	setlocale(LC_ALL, ".1251");
}

void yellow()
{
	SetConsoleTextAttribute(hConsole, 14);
}

void white()
{
	SetConsoleTextAttribute(hConsole, 15);
}

void red()
{
	SetConsoleTextAttribute(hConsole, 12);
}

bool IsLeapYear(int Y)
{
	if (Y % 4 != 0)
	{
		return false;
	}
	else if (Y % 4 == 0 && Y % 100 == 0 && Y % 400 != 0)
	{
		return false;
	}
	else return true;
}

int MonthDays(int M, int Y)
{
	if (M >= 1 && M <= 12)
	{
		if (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12)
			return 31;
		else if (M == 4 || M == 6 || M == 9 || M == 11)
			return 30;
		else if (M == 2)
		{
			if (IsLeapYear(Y))
				return 29;
			else
				return 28;
		}
	}
	else cout << " Вы не правильно ввели номер месяца" << endl;
}

void NextDate(int *D, int *M, int *Y)
{
	if (!((*M == 1&&*D==31)||(*M==3&&*D==31)|| (*M == 5 && *D == 31) || (*M == 7 && *D == 31) || (*M == 8 && *D == 31) || (*M == 10 && *D == 31) || (*M == 12 && *D == 31) || (*M == 4 && *D == 30) || (*M == 6 && *D == 30) || (*M == 9 && *D == 30) || (*M == 11 && *D == 30) || (IsLeapYear(*Y)&&*M == 2 && *D == 29) || (!IsLeapYear(*Y) && *M == 2 && *D == 28)))
	{
		*D = *D + 1;
	}
	else
	{
		if (*M == 12 && *D == 31)
		{
			*D = 1;
			*M = 1;
			*Y = *Y + 1;
		}
		else 
		{
			*D = 1;
			*M = *M + 1;
		}		
	}
}

double f(double x, double y)
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

double f1(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int f2(int m2, int m1, int m0)
{
	return m2 * 100 + m1 * 10 + m0;
}