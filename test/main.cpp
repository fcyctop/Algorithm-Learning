#include<TestData.h>
#include<Sort.h>
#include<Divide-and-conquer.h>
#include<string-match.h>
#include<Martix.h>

int main()
{
	//std::vector<int> vec;
	//TestRandomNumVec(vec, 20, -10, 10);
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
	//HeapSort(vec);
	//TestPrintVec(vec, 20, "HeapSort:");
	//CountingSort(vec);
	//TestPrintVec(vec, 20, "CountingSort:");
	//auto x = FindMaximumSubarray(vec, 0, static_cast<int>(vec.size()));
	//std::cout << "start:" << std::get<0>(x) << ", end:" << std::get<1>(x) << ", sum:" << std::get<2>(x) << std::endl;
	/*MyMartix m(2, 2);
	MyMartix n(2, 3);
	
	std::cout << m << std::endl;
	std::cout << "==============" << std::endl;
	std::cout << n << std::endl;
	std::cout << "==============" << std::endl;
	std::cout << m * n << std::endl;*/
	std::string src = "abcabababcdcbd";
	std::string sub = "ababc";
	auto n = KMPMatcher(src, sub);
	std::cout << n << std::endl;
	system("pause");
	return 0;
}