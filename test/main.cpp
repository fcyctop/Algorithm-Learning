#include<TestData.h>
#include<Sort.h>

int main()
{
	std::vector<int> vec;
	TestRandomNumVec(vec);
	//InsertionSort(vec);
	//TestPrintVec(vec, 20, "InsertionSort:");
	//BubbleSort(vec);
	//TestPrintVec(vec, 20, "BubbleSort:");
	//SelectionSort(vec);
	//TestPrintVec(vec, 20, "SelectionSort:");
	//MergeSort(vec);
	//TestPrintVec(vec, 20, "MergeSort:");
	//QuickSort(vec);
	//TestPrintVec(vec, 20, "QuickSort");
	HeapSort(vec);
	TestPrintVec(vec, 20, "HeapSort:");
	system("pause");
	return 0;
}