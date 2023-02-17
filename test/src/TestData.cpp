#include<TestData.h>

void TestPrintVec(const std::vector<int>& vec, const int col, std::string info)
{
	if (vec.empty()) {
		std::cout << "empty." << std::endl;
		return;
	}

	if (!info.empty()) std::cout << info << std::endl;

	int iCnt = 0;
	for (auto& x : vec) {
		std::cout << std::setw(4) << x << ",";
		++iCnt;
		if (col == iCnt) {
			std::cout << std::endl;
			iCnt = 0;
		}
	}
}

void TestRandomNumVec(std::vector<int>& vec, const int vecSize, const int minNum, const int maxNum)
{
	if (vecSize < 0) return;
	time_t t;
	srand((unsigned)time(&t));
	vec.clear();
	vec.reserve(vecSize);
	for (int i = 0; i != vecSize; ++i) {
		vec.emplace_back(minNum + rand() % (maxNum - minNum));
	}
	TestPrintVec(vec, 20, "New Numbers:");
	return;
}
