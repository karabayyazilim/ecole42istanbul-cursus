#include <iostream>

using std::cout;
using std::endl;

struct Data
{
	int a;
	int b;
	char c;
};

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

int main()
{
	Data data;
	Data *dataPtr = &data;
	data.a = 100;
	data.b = 200;
	data.c = 'A';

	uintptr_t ptr = serialize(dataPtr);

	cout << "Serialized ptr: " << reinterpret_cast<uintptr_t *>(ptr) << " Data ptr: " << &data << endl;
	cout << "Data.a: " << *reinterpret_cast<int*>(ptr) << " Data.B: " << *(reinterpret_cast<int*>(ptr) + 1) << endl;

	dataPtr = deserialize(ptr);

	cout << "Data.a: " << dataPtr->a << " Data.b: " << dataPtr->b << endl;


}