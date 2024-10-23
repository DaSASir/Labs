#include <iostream>
#include <string>
#include <vector>
#include "Boyer-Moore.h"

//#1
int BoyerMooreSearch(const string main_string, const string substring) {
	int* substring_cheese = CreateMassiveOfNumbersSubstring(substring);

	int i = 0;
	while (i <= main_string.length() - substring.length()) {
		int j = substring.length();
		while (j > 0 && main_string[i + j - 1] == substring[j - 1])
			j--;

		if (j == 0) break;
		else if (j == substring.length()) {
			int k = substring.length();
			while (k > 0 && main_string[i + j - 1] != substring[k - 1])
				k--;
			if (k == 0)
				i += substring_cheese[substring.length()];
			else if (k > 0 && main_string[i + j - 1] == substring[k - 1])
				i += substring_cheese[k - 1];
		}
		else if (j < substring.length())
			i += substring_cheese[j];

	}
	delete[] substring_cheese;
	return i;
}

int* CreateMassiveOfNumbersSubstring(const string substring) {
	int* massive_cheese = new int[substring.length() + 1];

	for (int i = 2; i <= substring.length(); i++)
		massive_cheese[substring.length() - i] = i - 1;

	massive_cheese[substring.length() - 1] = substring.length();
	massive_cheese[substring.length()] = substring.length();

	for (int i = 2; i <= substring.length(); i++) {
		for (int j = 3; j <= substring.length(); j++)
			if (substring[substring.length() - i] == substring[substring.length() - j])
				massive_cheese[substring.length() - j] = massive_cheese[substring.length() - i];

		if (substring[substring.length() - 1] == substring[substring.length() - i])
			massive_cheese[substring.length() - 1] = massive_cheese[substring.length() - i];
	}

	return massive_cheese;
	delete[] massive_cheese;
}

//#2
std::vector<int> SearchAllOccurrences(const string main_string, const string substring) {
	std::vector<int> cheese;

	int i = 0;
	while (i <= main_string.length() - substring.length()) {
		int entry_index = BoyerMooreSearch(main_string.substr(i), substring);

		cheese.push_back(entry_index + i);

		i += entry_index + 1;
	}

	return cheese;
}

//#3
std::vector<int> SearchAllOccurrencesInRange(const string main_string, const string substring, const int beginning, const int end) {
	std::vector<int> cheese;

	if (beginning < 0 || beginning > main_string.length() - substring.length())
		return cheese;

	int i = beginning;
	while (i <= end - substring.length()) {
		int entry_index = BoyerMooreSearch(main_string.substr(i), substring);

		if(entry_index + i < end)
			cheese.push_back(entry_index + i);

		i += entry_index + 1;
	}

	return cheese;
}