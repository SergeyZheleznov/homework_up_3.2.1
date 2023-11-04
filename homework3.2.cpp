// homework_3.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// ��� ������ ����� 2 ����� 3, ������ "����������� ����������������"

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

		if ((count + 1) <= Size) // ��� ������, ����� ��� �� ����� ����������� ������, ������ ����� �������� � �������� �������
		{
			// ���� �������� ������� ���������� � ������ �������� � ������ ���, �� ����� 
			// �������� �������� � ����� ������ ������� �������, �� ���� � �������� 0
			// ���� �������� ������� ���������� � ������ ������ ���, �� ����� � ������ � �������� 1 � �.�
			data[count] = x;

			// ���������� ��� ������, ������� ��������� � ���������� ������ ������ add_element
			std::cout << "������ ��������" << std::endl;
			for (int i = 0; i < Size; i++)
			{
				std::cout << data[i] << std::endl;
			}

		}
		else // ����� � ��� ���������� ��������� ��� ������, ��� ���������� �������� ������,
			// ������� ����� ��������� ������, ����� �������� ���� ����� �������
		{
			std::cout << "���������� ���������, ������� �� ������ ������, ������, ��� ���������� ���� � �������.������ ��������." << std::endl;

			// ������ ��������� ������ arr_temp
			int* data_temp = new int[Size + 1];
			// ������� ���� ��� �������� �� ���������� �������
			for (int i = 0; i < Size; i++)
			{
				data_temp[i] = data[i];
			}
			// ��������� � ��������� ������� ����� �������� 
			data_temp[Size] = x;

			std::cout << "��������� ������ ��������" << std::endl;
			for (int i = 0; i < (Size + 1); i++)
			{
				std::cout << data_temp[i] << std::endl;
			}
			Size++;
			delete[] data;

			data = data_temp;
			std::cout << "������ ��������" << std::endl;
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
			std::cout << "��� �������� �������� ������� ��������������� ��������" << std::endl;
			return data[y];
		}
		else
		{
			throw std::runtime_error("�� ����� �������� ��������� �������� �������, ��������� �������� ������� ���������");
		}
	}
	
	Smart_array & operator = (const Smart_array & other) 
	{
		std::cout << "�������� �������� ������������" << std::endl;
		// ������, ���� ������, � ������� ����� ����������, ������, ��� ����������� ������.
		// �� ���� new_array (��� ������, �� �������� �� ��������, ������, ��� arr.
		// ��������, ������ new_array ������� �� ��� ���������, � ������ arr �� ���� ���������.
		
		// ������� ����������� ������ � ������� ������ ������� arr, ����� ������ �������� ����� �������
		// ����� ��������� ������ arr ������� �� ������� new_array
		
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

			// ������, ���� ������, � ������� ����� ����������, ������, ��� ����������� ������.
			// � ���� ������ ��������� �������� � ������� ������� ����� ��������. 
			// ��� �� �����, ��������� ������ - ������� ������ arr ����� ��, ��� � new_array. 
			// ������ �� ������ ������ ��� ����� ����� ��, �� ����� ������� � ���������.
		}

		return *this;
	}

	void print_arr()
	{
		std::cout << "�������� ������" << std::endl;
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
		std::cout << "������ ��������" << std::endl;
		arr.print_arr();

		Smart_array arr1(3);
		Smart_array arr2(arr);
		
	}
	catch (const std::runtime_error& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}