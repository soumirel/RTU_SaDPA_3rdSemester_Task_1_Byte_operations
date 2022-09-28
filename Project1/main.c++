#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

int operation_1(size_t number);
int operation_2(size_t number);
int operation_3(size_t number);
int operation_4(size_t number);
int operation_5(size_t number, size_t position);
void printBinaryNumberOnBorders(size_t number, size_t width);


int main()
{
	setlocale(LC_ALL, "ru");

	//Переменные для пользовательского выбора.
	int userMenuChoice = -1;

	//Переменные для работы программы
	size_t number = 0;
	bool isNumberInit = false;

	// Главный меню-цикл.
	while (userMenuChoice != 6)
	{
		system("cls");
		cout << "Практическая работа #1 ИКБО-03-21 Мазанов А.Е. Вариант 16\n\n"
			"Задание - Битовые операции.\n"
			"~~~~~~~~~~~~~~~~~Меню~~~~~~~~~~~~~~~\n"
			"Число в hex формате: ";
		if (isNumberInit)
		{
			cout << hex << uppercase << number << '\n';
		}
		else
		{
			cout << "Не введено\n";
		}

		cout << "\nВведите [0], чтобы задать число в hex формате."
			<< "\nВведите [1], чтобы установить 1, 2 и 7 позиции в 1."
			<< "\nВведите [2], чтобы обнулить 7-9 позиции."
			<< "\nВведите [3], чтобы умножить число на 8 (в 10сс)."
			<< "\nВведите [4], чтобы разделить число на 8 (в 10сс)."
			<< "\nВведите [5], чтобы обнулить n-ый бит, используя маску (иннициализирована единицей в мл.разряде)."
			<< "\nВведите [6], чтобы закончить работу программы."
			<< "\nВаш выбор: ";

		cin >> userMenuChoice;
		cin.ignore();
		if (userMenuChoice > 0 && userMenuChoice < 6)
		{
			if (isNumberInit)
			{
				size_t position = 0;
				if (userMenuChoice == 5)
				{
					cout << "Введите номер позиции, которую хотите обнулить: ";
					cin >> position;
				}
				size_t result = 0;
				switch (userMenuChoice)
				{
				case 1:
					result = operation_1(number);
					break;
				case 2:
					result = operation_2(number);
					break;
				case 3:
					result = operation_3(number);
					break;
				case 4:
					result = operation_4(number);					
					break;
				case 5:
					result = operation_5(number, position);					
					break;
				}
				size_t numberWidth;
				if (number == 0 && result == 0)
				{
					numberWidth = 1;
				}
				else
				{
					numberWidth = max(log2(number) + 1, log2(result) + 1);
				}
				
				cout << setw(25) << "Исходное число в 2сс: ";
				printBinaryNumberOnBorders(number, numberWidth);
				cout << setw(25) << "Результат операции: ";
				printBinaryNumberOnBorders(result, numberWidth);
				system("pause");
			}
			else
			{
				cout << "Действие невозможно. Введите число.\n";
				system("pause");
			}
		}
		else
		{
			switch (userMenuChoice)
			{
			case 0:
				cout << "Введите число в hex формате: ";
				cin.unsetf(ios::dec);
				cin.setf(ios::hex);
				cin >> number;
				isNumberInit = true;
				system("pause");
				break;
			case 6:
				cout << "\nДо свидания!\n";

				cout << '\n';
				system("pause");
				break;

			default:
				cout << "\nЯ не понимаю вас.\n";
				cin.clear();

				cout << '\n';
				system("pause");
				break;
			}
		}
	}

	return 0;
}



int operation_1(size_t number)
{
	size_t mask = 0b10000110;
	return number | mask;
}


int operation_2(size_t number)
{
	size_t mask = 0b1110000000;
	return number & ~mask;
}


int operation_3(size_t number)
{
	return number << 3;
}


int operation_4(size_t number)
{
	return number >> 3;
}


int operation_5(size_t number, size_t position)
{
	size_t mask = 0b1;
	return number & ~(mask << position);
}


void printBinaryNumberOnBorders(size_t number, size_t width)
{
	string result = "";
	int zeros;
	if (number != 0)
	{
		int ownWidth = (log2(number) + 1);
		zeros = width - ownWidth;
	}
	else
	{
		zeros = width;
	}
	
	while (number > 0)
	{
		result = to_string(number % 2) + result;
		number /= 2;
	}
	for (int i = 0; i < zeros; i++)
	{
		cout << '0';
	}
	cout << result << '\n';
}