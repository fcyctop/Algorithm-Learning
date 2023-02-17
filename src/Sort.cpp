#include<Sort.h>

void InsertionSort(std::vector<int>& vec)
{
	if (!TestCheckVecForSort(vec)) return;
	auto vecSize = vec.size();
	for (size_t i = 1; i < vecSize; ++i) {
		auto curNum = vec[i];
		int j = i - 1;
		while (j >= 0 && curNum < vec[j]) {
			vec[j + 1] = vec[j];
			--j;
		}
		vec[j + 1] = curNum;
	}
}
