#include<string-match.h>
#include<vector>
#include<assert.h>

int BruteForceMatcher(const std::string& text, const std::string& match)
{
	auto srcSize = text.size();
	auto subSize = match.size();
	auto&& end = srcSize - subSize;
	bool bSuccess = true;
	for (int i = 0; i <= end; ++i) {
		bSuccess = true;
		for (int j = 0; j < subSize; ++j) {
			if (text[i + j] != match[j]) {
				bSuccess = false;
				break;
			}
		}
		if (bSuccess) return i;
	}
	return -1;
}

int RobinKarpMatcher(const std::string& text, const std::string& match, const int prime)
{
	assert(0 != prime);
	auto nText = text.size();
	auto nMatch = match.size();
	assert(nText >= nMatch);
	int sumMatch = 0, sumText = 0;

	for (int i = 0; i < nMatch; ++i) {
		sumMatch = (sumMatch + (match[i] - '0')) % prime;
		sumText = (sumText + (text[i] - '0')) % prime;
	}

	auto&& end = nText - nMatch;
	for (auto i = 0; i <= end; ++i) {
		if (sumMatch == sumText) {
			bool flag = true;
			for (int j = i; j < nMatch; ++j) {
				if (text[j] != match[j - i]) {
					flag = false;
					break;
				}
			}
			if (flag) return i;
		}
		if (i != end) {
			sumText = (sumText - (text[i] - '0') + (text[i + nMatch] - '0')) % prime;
		}
	}

	return -1;
}
//===========================================================
std::vector<int> ComputePrefixFunction(const std::string model)
{
	auto size = model.size();
	std::vector<int> vec(size, -1);
	int k = -1;
	for (int i = 1; i < size; ++i) {
		while (k > -1 && model[k + 1] != model[i]) {
			k = vec[k];
		}
		if (model[k + 1] == model[i]) {
			k += 1;
		}
		vec[i] = k;
	}
	return vec;
}

int KMPMatcher(const std::string& text, const std::string& model)
{
	auto tsize = text.size();
	auto msize = model.size();
	std::vector<int> vec = ComputePrefixFunction(model);
	int k = -1;
	for (int i = 0; i < tsize; ++i) {
		while (k > -1 && model[k + 1] != text[i])
			k = vec[k];
		if (model[k + 1] == text[i])
			k = k + 1;
		if (k == msize - 1)
			return static_cast<int>(i - msize + 1);
	}
	return -1;
}
