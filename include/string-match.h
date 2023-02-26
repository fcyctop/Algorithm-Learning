#pragma once
#include<iostream>

//native string match
int BruteForceMatcher(const std::string& src, const std::string& sub);

//hash search match
int RobinKarpMatcher(const std::string& src, const std::string& sub, const int prime = 13);
