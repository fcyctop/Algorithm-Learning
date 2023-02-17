#pragma once
#include<vector>
#include<iostream>
#include<iomanip>
#include<random>
#include<time.h>

//Print numbers in vector.
void TestPrintVec(const std::vector<int>& vec, const int col = 20, std::string info = "");

//Generating random numbers and store them in the vector.
void TestRandomNumVec(std::vector<int>& vec, const int vecSize = 20, const int minNum = 0, const int maxNum = 100);

bool TestCheckVecForSort(const std::vector<int>& vec);