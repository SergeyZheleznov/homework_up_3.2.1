// homework_3.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Эта задача номер 2 урока 3, модуль "Продвинутое программирование"

#include <iostream>

class Smart_array
{
public:
	int size;
	int count = 0;
	int* arr;
	int* arr_temp;

public:
	Smart_array()
	{

		size = 5;
		arr = new int[size];

		// заполняем созданный массив нулями
		for (int i = 0; i < size; i++)
		{
			arr[i] = 0;
		}

		std::cout << "Constructor called\n";

	}

	Smart_array(int size)
	{
		std::cout << "Constructor called\n";
		this->size = size;
		arr = new int[size];

		for (int i = 0; i < size; i++)
		{
			arr[i] = 0;
		}
	}

	~Smart_array()
	{
		delete[] arr;
		std::cout << "Destructor called\n";
	}

	int add_element(int x)
	{

		x = x;

		if ((count + 1) <= size)
		{
			// создаём временный массив arr_temp и передаём туда все значения из первичного массива
			arr_temp = new int[size];

			for (int i = 0; i < size; i++)
			{
				arr_temp[i] = arr[i];
			}

			// если вызываем функцию добавления в массив элемента в первый раз, то кладём
			// значение элемента в самый первый элемент массива, то есть с индексом 0
			arr_temp[count] = x;

			delete[] arr;
			arr = new int[size];

			for (int i = 0; i < size; i++)
			{
				arr[i] = arr_temp[i];
			}

			delete[] arr_temp;

			std::cout << "Массив значений" << std::endl;
			for (int i = 0; i < size; i++)
			{
				std::cout << arr[i] << std::endl;
			}

			count = count + 1;
		}
		else
		{
			throw std::exception("Количество элементов, которое Вы ходите ввести, больше, чем количество мест в массиве. Вы не можете больше вводить элементы массива");
		}
	}

	int get_element_from_index(int y)
	{
		if (y > 0 && y < size)
		{
			std::cout << "Вот значение элемента массива соответствующим индексом" << std::endl;
			return arr[y];
		}
		else
		{
			throw std::exception("Вы ввели значение ошибочное значение индекса, набирайте значение индекса правильно");
		}
	}

	Smart_array& operator=(const Smart_array& counter)
	{
		size = counter.size;
		for (int i = 0; i < size; i++)
		{
			arr[i] = counter.arr[i];
		}
		return *this;
	}

	void print_arr()
	{

		std::cout << "Печатаем массив" << std::endl;
		for (int i = 0; i < size; i++)
		{
			std::cout << arr[i] << std::endl;
		}
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	std::cout << "Hello World!\n";
	try {
		Smart_array arr_one(5);

		arr_one.add_element(1);
		arr_one.add_element(4);
		arr_one.add_element(155);

		Smart_array new_array(2);

		new_array.add_element(44);
		new_array.add_element(34);

		std::cout << "Smart_array printed\n";

		arr_one = new_array;
		std::cout << "Массив значений" << std::endl;
		arr_one.print_arr();

	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}