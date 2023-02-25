#pragma once
#include<vector>
#include<iostream>

using martix = std::vector<std::vector<int>>;

class MyMartix
{
public:
	MyMartix(const size_t& row, const size_t& col);
	MyMartix(const size_t& row, const size_t& col, const martix& mar);
	MyMartix(size_t&& row, size_t&& col, martix&& mar);
	MyMartix(const MyMartix& right);

	MyMartix& operator=(const MyMartix& right);
	MyMartix& operator*(const MyMartix& right);
	
	friend std::ostream& operator<<(std::ostream& os, const MyMartix& right);
public:
	auto Row()const { return m_row; }
	auto Col()const { return m_col; }
	auto Success()const { return m_success; }

private:
	bool m_success;
	size_t m_row;
	size_t m_col;
	martix m_martix;
};