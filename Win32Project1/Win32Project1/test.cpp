#include"myvector.h"
#include"iostream"
using namespace std;
void printfVector(myVector<int>& vector1)
{
	for (unsigned int i = 0; i < vector1.size(); ++i)
	{
		cout << vector1[i] << ",";
	}
	cout << "alloc size = " << vector1.allocSize() << ",size = " << vector1.size() << endl;
}

void main()
{
	myVector<int> myVector1;
	myVector<int> myVector2(0, 10);
	myVector2.push_front(1);
	myVector2.erase(11);
	printfVector(myVector2);
	myVector1.push_back(2);
	myVector1.push_front(1);
	printfVector(myVector1);
	myVector1.insert_after(1, 3);
	printfVector(myVector1);

	myVector2 = myVector1;
	myVector2.insert_before(0, 0);
	myVector2.insert_before(1, -1);
	printfVector(myVector2);
}