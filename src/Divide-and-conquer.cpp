#include<Divide-and-conquer.h>
#include<TestData.h>

auto FindMaxCrossingSubarray(std::vector<int>& vec, int low, int mid, int high)
{
	auto leftSum = INT32_MIN;
	auto sum = 0;
	auto leftIndex = mid;
	for (int i = mid; i >= low; --i) {
		sum += vec[i];
		if (sum > leftSum) {
			leftSum = sum;
			leftIndex = i;
		}
	}

	auto rightSum = INT32_MIN;
	sum = 0;
	auto rightIndex = mid + 1;
	for (int i = mid + 1; i <= high; ++i) {
		sum += vec[i];
		if (sum > rightSum) {
			rightSum = sum;
			rightIndex = i;
		}
	}

	return std::tuple<int, int, int>(leftIndex, rightIndex, leftSum + rightSum);
}

std::tuple<int, int, int> FindMaximumSubarray(std::vector<int>& vec, int low, int high)
{
	if (high == low)
		return std::tuple<int, int, int>(low, high, vec[low]);

	int mid = low + ((high - low) >> 1);
	auto left = FindMaximumSubarray(vec, low, mid);
	auto right = FindMaximumSubarray(vec, mid + 1, high);
	auto cross = FindMaxCrossingSubarray(vec, low, mid, high);

	if (std::get<2>(left) >= std::get<2>(right) && std::get<2>(left) >= std::get<2>(cross))
		return left;
	else if (std::get<2>(right) >= std::get<2>(left) && std::get<2>(right) >= std::get<2>(cross))
		return right;
	else
		return cross;
}
