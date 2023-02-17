#include<TestData.h>
#include<Sort.h>

int main()
{
	std::vector<int> vec;
	TestRandomNumVec(vec);
	InsertionSort(vec);
	TestPrintVec(vec, 20, "InsertionSort:");
	system("pause");
	return 0;
}