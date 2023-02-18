#include<Sort.h>

/*******************************************************/
void InsertionSort(std::vector<int>& vec)
{
	auto vecSize = vec.size();
	for (size_t i = 1; i < vecSize; ++i) {
		auto curNum = vec[i];
		size_t j = i - 1;
		while (j >= 0 && curNum < vec[j]) {
			vec[j + 1] = vec[j];
			--j;
		}
		vec[j + 1] = curNum;
	}
}

/*******************************************************/
void BubbleSort(std::vector<int>& vec)
{
	auto vecSize = vec.size();
	for (size_t i = vecSize - 1; i > 0; --i) {
		for (size_t j = 0; j < i; ++j) {
			if (vec[j] > vec[j + 1]) TestSwap(vec[j], vec[j + 1]);
		}
	}
}

/*******************************************************/
void SelectionSort(std::vector<int>& vec)
{
	auto vecSize = vec.size();
	for (size_t i = 0; i < vecSize - 1; ++i) {
		auto minIndex = i;
		for (size_t j = i + 1; j < vecSize; ++j) {
			if (vec[minIndex] > vec[j]) minIndex = j;
		}
		if (minIndex != i) TestSwap(vec[minIndex], vec[i]);
	}
}

/*******************************************************/
void Merge(std::vector<int>& vec, size_t low, size_t mid, size_t high)
{
	std::vector<int> vecTmp;
	auto&& numSize = high - low + 1;
	vecTmp.reserve(numSize);

	size_t i = low, j = mid + 1;
	while (i <= mid && j <= high) {
		if (vec[i] <= vec[j]) {
			vecTmp.emplace_back(vec[i++]);
			continue;
		}
		vecTmp.emplace_back(vec[j++]);
	}
	
	while (i <= mid) {
		vecTmp.emplace_back(vec[i++]);
	}

	while (j <= high) {
		vecTmp.emplace_back(vec[j++]);
	}
	
	for (size_t k = 0; k < numSize; ++k) {
		vec[k + low] = vecTmp[k];
	}
}

void MergeSort(std::vector<int>& vec, size_t low, size_t high)
{
	if (low < high) {
		auto mid = low + ((high - low) >> 1);
		MergeSort(vec, low, mid);
		MergeSort(vec, mid + 1, high);
		Merge(vec, low, mid, high);
	}
}

void MergeSort(std::vector<int>& vec)
{
	MergeSort(vec, 0, vec.size() - 1);
}
