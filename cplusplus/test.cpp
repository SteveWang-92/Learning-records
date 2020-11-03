#include <initializer_list>
#include <iostream>
using namespace std;

int makeSum(initializer_list<int> lst)
{
	int total = 0;
	for (int value : lst){
		total += value;
	}
	return total;
}

int main()
{
	int a = makeSum({1,2,3});
	cout << a <<endl;
	return 0;
}