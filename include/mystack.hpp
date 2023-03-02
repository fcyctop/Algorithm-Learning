#pragma once
#include<iostream>
#include<vector>

template<typename T>
class mystack 
{
public:
	mystack() { Init(); }
	
public:
	void push(T&& val) { m_vecData.emplace_back(val); }
	void pop();
	bool empty() { return m_vecData.empty(); }
	auto size() { return m_vecData.size(); }
	void Output();

	
	friend std::ostream& operator<<(std::ostream& os, mystack<T>& obj) {
		os << "stack Size: " << obj.size() << std::endl;
		os << "elements from the buttom to the top: ";
		obj.Output();
		os << std::endl;
		return os;
	}

private:
	void Init() { m_vecData.clear(); }

protected:
	std::vector<T> m_vecData;
};

template<typename T>
inline void mystack<T>::pop()
{
	if (!m_vecData.empty()) {
		m_vecData.pop_back();
	}
}

template<typename T>
inline void mystack<T>::Output()
{
	for (auto& x : m_vecData) {
		std::cout << x << ',';
	}
}
