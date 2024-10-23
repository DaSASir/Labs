#pragma once

using namespace std;

//#1
int BoyerMooreSearch(const string main_string, const string substring);
int* CreateMassiveOfNumbersSubstring(const string substring);

//#2
std::vector<int> SearchAllOccurrences(const string main_string, const string substring);

//#3
std::vector<int> SearchAllOccurrencesInRange(const string main_string, const string substring, const int beginning, const int end);