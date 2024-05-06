// Hillel_HW_9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


class MyVector
{
private:
	int* data = nullptr;
	size_t length = 0;
	size_t capacity = 0;

public:

	MyVector() = default;
	MyVector(size_t newCapacity) : length(0), capacity(newCapacity)
	{
		data = new int[capacity];
	}
		MyVector(const MyVector& otherVector) : length(otherVector.length), capacity(otherVector.capacity)
	{
		data = new int[otherVector.capacity];
		for (size_t i = 0; i < length; ++i)
		{
			data[i] = otherVector.data[i];
		}
	}


	~MyVector()
	{
		delete[] data;
	}

	MyVector& operator= (const MyVector& otherVector)
	{
		if (this == &otherVector) return *this;

		if (data && otherVector.data)
		{
			delete[] data;
			data = new int[otherVector.capacity];
			length = otherVector.length;
			capacity = otherVector.capacity;
			for (size_t i = 0; i < length; i++)
			{
				data[i] = otherVector.data[i];
			}

		}
		return *this;
	}

	int operator[] (size_t index)
	{
		return data[index];
	}

	MyVector operator+(const MyVector& otherVector)
	{
		MyVector resultVector(length + otherVector.length);
		for (size_t i = 0; i < length; ++i)
		{
			resultVector.data[i] = data[i];
		}

		for (size_t i = 0; i < otherVector.length; i++)
		{
			resultVector.data[length + i] = otherVector.data[i];
		}
		resultVector.length = length + otherVector.length;
		return resultVector;
	}

	void push_back(const int item)
	{
		if (length == capacity)
		{
			std::cout << "Vector is full" << std::endl;
			return;
		}
		data[length++] = item;
	}

	size_t getLength() const
	{
		return length;
	}

	size_t getCapacity() const
	{
		return capacity;
	}

	void printData() const
	{
		for (size_t i = 0; i < length; ++i)
		{
			std::cout << data[i] << " ";
		}
		std::cout << "\n";
	}

};

int main()
{
	MyVector testVector1(40);
	for (int i = 1; i <= 20; ++i) {
		testVector1.push_back(i);
	}

	testVector1.printData();
	std::cout << "Lenght: " << testVector1.getLength() << "\n";
	std::cout << "Capacity: " << testVector1.getCapacity() << "\n";

	std::cout << "******************************\n";

	MyVector testVector2(10);
	for (int i = 21; i <= 30; ++i) {
		testVector2.push_back(i);
	}

	testVector2.printData();
	std::cout << "Lenght: " << testVector2.getLength() << "\n";
	std::cout << "Capacity: " << testVector2.getCapacity() << "\n";

	std::cout << "******************************\n";

	MyVector resultVector = testVector1 + testVector2;

	resultVector.printData();
	std::cout << "Lenght: " << resultVector.getLength() << "\n";
	std::cout << "Capacity: " << resultVector.getCapacity() << "\n";

	std::cout << "******************************\n";

	resultVector.push_back(99);	//should get here message that vector full

	return 0;
}


