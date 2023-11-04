// homework_3.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Эта задача номер 2 урока 3, модуль "Продвинутое программирование"

#include <iostream>

class Smart_array
{
public:
	int count = 0;
	int* data;

	Smart_array(int size)
	{
		std::cout << "Constructor called\n";
		this->Size = size;
		this->data = new int[size];

		for (int i = 0; i < size; i++)
		{
			data[i] = 0;
		}
	}

	Smart_array(const Smart_array& other)
	{
		std::cout << "Copies constructor called\n"; this->Size = other.Size;
		this->data = new int[other.Size];
		for (int i = 0; i < other.Size; i++)
		{
			this->data[i] = other.data[i];
		}
	}

	~Smart_array()
	{
		std::cout << "Destructor called\n";
		delete[] data;
	}

	void add_element(int x)
	{
		x = x;

		if ((count + 1) <= Size) // это случай, когда нам не нужно увеличивать массив, просто пишем значения в элементы массива
		{
			// если вызываем функцию добавления в массив элемента в первый раз, то кладём 
			// значение элемента в самый первый элемент массива, то есть с индексом 0
			// если вызываем функцию добавления в массив второй раз, то кладём в ячейку с индексом 1 и т.д
			data[count] = x;

			// Распечатем тот массив, который получился в результате вызова метода add_element
			std::cout << "Массив значений" << std::endl;
			for (int i = 0; i < Size; i++)
			{
				std::cout << data[i] << std::endl;
			}

		}
		else // здесь у нас количество элементов уже больше, чем изначально заданный массив,
			// поэтому нужно увеличить массив, чтобы положить туда новый элемент
		{
			std::cout << "Количество элементов, которое Вы ходите ввести, больше, чем количество мест в массиве.Массив увеличен." << std::endl;

			// создаём временный массив arr_temp
			int* data_temp = new int[Size + 1];
			// передаём туда все значения из первичного массива
			for (int i = 0; i < Size; i++)
			{
				data_temp[i] = data[i];
			}
			// добавляем в последний элемент новое значение 
			data_temp[Size] = x;

			std::cout << "Временный массив значений" << std::endl;
			for (int i = 0; i < (Size + 1); i++)
			{
				std::cout << data_temp[i] << std::endl;
			}
			Size++;
			delete[] data;

			data = data_temp;
			std::cout << "Массив значений" << std::endl;
			for (int i = 0; i < (Size); i++)
			{
				std::cout << data_temp[i] << std::endl;
			}
		}
		count = count + 1;
	
	}

	int get_element_from_index(int y)
	{
		if (y >= 0 && y < Size)
		{
			std::cout << "Вот значение элемента массива соответствующим индексом" << std::endl;
			return data[y];
		}
		else
		{
			throw std::runtime_error("Вы ввели значение ошибочное значение индекса, набирайте значение индекса правильно");
		}
	}
	
	Smart_array & operator = (const Smart_array & other) 
	{
		std::cout << "Вызвался оператор присваивания" << std::endl;
		// случай, если массив, в который нужно копировать, меньше, чем изначальный массив.
		// То есть new_array (это массив, из которого мы копируем, больше, чем arr.
		// Например, массив new_array состоит из трёх элементов, а массив arr из двух элементов.
		
		// сначала освобождаем память в массиве данных объекта arr, потом меняем значения полей объекта
		// потом заполняем объект arr данными из объекта new_array
		
		if (this != &other)
		{
			if (this->data != nullptr)
			{
				delete[] this->data;
			}
			this->Size = other.Size;
			this->count = other.count;
			this->data = new int[other.Size];

			for (int i = 0; i < other.Size; i++)
			{
				this->data[i] = other.data[i];
			}

			// случай, если массив, в который нужно копировать, больше, чем изначальный массив.
			// в этом случае последние значения в большом массиве будут потеряны. 
			// это не важно, поскольку задача - сделать объект arr таким же, как и new_array. 
			// Поэтом мы просто делаем его точно таким же, со всеми данными и размерами.
		}

		return *this;
	}

	void print_arr()
	{
		std::cout << "Печатаем массив" << std::endl;
		for (int i = 0; i < Size; i++)
		{
			std::cout << data[i] << std::endl;
		}
	}

private:
	int Size;
};

int main()
{
	setlocale(LC_ALL, "ru");
	std::cout << "Hello World!\n";
	try {
		Smart_array arr(2);

		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(40);
		arr.add_element(48);
		arr.add_element(21);

		Smart_array new_array(3);
		new_array.add_element(44);
		new_array.add_element(34);
		new_array.add_element(48);

		std::cout << "Smart_array printed\n";
		
		arr = arr;
		std::cout << "Массив значений" << std::endl;
		arr.print_arr();

		Smart_array arr1(3);
		Smart_array arr2(arr);
		
	}
	catch (const std::runtime_error& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}