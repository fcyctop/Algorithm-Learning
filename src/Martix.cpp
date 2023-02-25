#include<Martix.h>
#include<TestData.h>
#include<iomanip>
#include<Windows.h>
#include<assert.h>

MyMartix::MyMartix(const size_t& row, const size_t& col)
{
	m_row = row;
	m_col = col;
	m_success = true;
	m_martix.reserve(row);
	for (int i = 0; i < row; ++i) {
		std::vector<int> vec;
		TestRandomNumVec2(vec, static_cast<int>(col), 0, 10);
		m_martix.emplace_back(std::move(vec));
	}
}

MyMartix::MyMartix(const size_t& row, const size_t& col, const martix& mar)
{
	m_success = false;
	m_row = 0;
	m_col = 0;
	if (mar.size() != row) {
		return;
	}
	for (const auto& x : mar) {
		if (x.size() != col) return;
	}

	m_row = row;
	m_col = col;

	m_martix.reserve(row);
	for (const auto& x : mar) {
		std::vector<int> vec(x);
		m_martix.emplace_back(std::move(vec));
	}
	m_success = true;
}

MyMartix::MyMartix(size_t&& row, size_t&& col, martix&& mar)
{
	m_success = false;
	m_row = 0;
	m_col = 0;
	if (mar.size() != row) {
		return;
	}
	for (const auto& x : mar) {
		if (x.size() != col) return;
	}

	m_row = row;
	m_col = col;

	m_martix.reserve(row);
	for (const auto& x : mar) {
		std::vector<int> vec(x);
		m_martix.emplace_back(std::move(vec));
	}
	m_success = true;
}

MyMartix& MyMartix::operator=(const MyMartix& right)
{
	m_row = right.m_row;
	m_col = right.m_col;
	m_success = right.m_success;
	m_martix.reserve(m_row);
	for (auto& x : right.m_martix) {
		std::vector<int> vec(x);
		m_martix.emplace_back(vec);
	}
	return *this;
}

MyMartix& MyMartix::operator*(const MyMartix& right)
{
	assert(m_col == right.m_row);
	MyMartix left(*this);
	m_col = right.m_col;
	m_martix.clear();
	m_martix.reserve(m_row);
	for (int i = 0; i < m_row; ++i) {
		m_martix.emplace_back(std::vector<int>());
		m_martix[i].reserve(m_col);
		for (int j = 0; j < m_col; ++j) {
			int ret = 0;
			for (int k = 0; k < left.m_col; ++k) {
				ret += left.m_martix[i][k] * right.m_martix[k][j];
			}
			m_martix[i].emplace_back(std::move(ret));
		}
	}
	return *this;
}

MyMartix::MyMartix(const MyMartix& right)
{
	m_row = right.m_row;
	m_col = right.m_col;
	m_success = right.m_success;
	m_martix.reserve(m_row);
	for (auto& x : right.m_martix) {
		std::vector<int> vec(x);
		m_martix.emplace_back(vec);
	}
}

std::ostream& operator<<(std::ostream& os, const MyMartix& right)
{
	os << "{" << std::endl;
	for (const auto& x : right.m_martix) {
		for (const auto& y : x) {
			os << std::setw(3) << y << ',';
		}
		os << std::endl;
	}
	os << "}" << std::endl;
	return os;
}
