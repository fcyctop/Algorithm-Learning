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

/*******************************************************/
int Partition(std::vector<int>& vec, int low, int high)
{
	auto randIndex = low + rand() % (high - low + 1);
	TestSwap(vec[randIndex], vec[low]);
	auto slow = low;
	auto fast = slow + 1;
	while (fast <= high) {
		if (vec[fast] < vec[low]) {
			if (++slow != fast) {
				TestSwap(vec[fast], vec[slow]);
			}
		}
		++fast;
	}
	TestSwap(vec[low], vec[slow]);
	return slow;
}

void QuickSort(std::vector<int>& vec, int low, int high)
{
	if (low < high) {
		auto pos = Partition(vec, low, high);
		QuickSort(vec, low, pos - 1);
		QuickSort(vec, pos + 1, high);
	}
}

void QuickSort(std::vector<int>& vec)
{
	QuickSort(vec, 0, static_cast<int>(vec.size() - 1));
}

/*******************************************************/
void MaxHeapify(std::vector<int>& vec, int index, int high)
{
	auto left = 2 * index + 1;
	if (left > high) return;
	auto right = 2 * index + 2;

	auto maxNumIndex = index;
	if (right <= high && vec[right] > vec[maxNumIndex]) maxNumIndex = right;
	if (left <= high && vec[left] > vec[maxNumIndex]) maxNumIndex = left;

	if (maxNumIndex != index) {
		TestSwap(vec[maxNumIndex], vec[index]);
		MaxHeapify(vec, maxNumIndex, high);
	}
}

void BuildMaxHeap(std::vector<int>& vec)
{
	int&& high = static_cast<int>(vec.size() - 1);
	for (int i = (high - 1) / 2; i >= 0; --i) {
		MaxHeapify(vec, i, high);
	}
}

void HeapSort(std::vector<int>& vec)
{
	BuildMaxHeap(vec);
	for (int i = static_cast<int>(vec.size() - 1); i > 0; --i) {
		TestSwap(vec[0], vec[i]);
		MaxHeapify(vec, 0, i - 1);
	}
}

/*******************************************************/
//Suppose the data range to be sorted is between 0 and 100
void CountingSort(std::vector<int>& vec)
{
	constexpr int MAXVALUE = 101;
	int cnt[MAXVALUE] = { 0 };
	for (auto& x : vec) ++cnt[x];
	vec.clear();
	for (int i = 0; i < MAXVALUE; ++i) {
		while (0 < cnt[i]--) {
			vec.emplace_back(i);
		}
	}
}

/*******************************************************/
