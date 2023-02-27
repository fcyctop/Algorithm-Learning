#pragma once
#include<iostream>

//native string match
int BruteForceMatcher(const std::string& text, const std::string& model);

//hash search match
int RobinKarpMatcher(const std::string& text, const std::string& model, const int prime = 13);

//Knuth-Morris-Pratt
int KMPMatcher(const std::string& text, const std::string& model);