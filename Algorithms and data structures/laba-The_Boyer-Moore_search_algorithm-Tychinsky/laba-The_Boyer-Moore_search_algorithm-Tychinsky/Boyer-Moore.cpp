#include <iostream>
#include <string>
#include <vector>
#include "Boyer-Moore.h"

//#1
std::vector<int> GetTableOfChar(const string substring) {
    std::vector<int> table(256, -1);

    for (int i = 0; i < substring.size(); i++)
        table[substring[i]] = i;

    return table;
}

int BoyerMooreSearch(const string main_string, const string substring) {
    if (substring.size() > main_string.size())
        return -1;

    std::vector<int> table_shift = GetTableOfChar(substring);
    int shift = 0;

    while (shift <= (main_string.size() - substring.size())) {
        int index = substring.size() - 1;

        while (index >= 0 && substring[index] == main_string[shift + index]) index--;

        if (index < 0)
			return shift;

		int shift_by_el;
		if (main_string[shift + index] >= 0 && main_string[shift + index] < 256)
			shift_by_el = index - table_shift[main_string[shift + index]];
		else shift_by_el = index + 1;

        (shift_by_el > 0) ? shift += shift_by_el : shift += 1;
    }

    return -1;
}

//#2
std::vector<int> SearchAllOccurrences(const string main_string, const string substring) {
	std::vector<int> occurrences;

	int i = 0;
	while (i <= main_string.length() - substring.length()) {
		int entry_index = BoyerMooreSearch(main_string.substr(i), substring);

		occurrences.push_back(entry_index + i);

		i += entry_index + 1;
	}

	return occurrences;
}

//#3
std::vector<int> SearchAllOccurrencesInRange(const string main_string, const string substring, const int beginning, const int end) {
	std::vector<int> occurrences;

	if (beginning < 0 || beginning > main_string.length() - substring.length())
		return occurrences;

	int i = beginning;
	while (i <= end - substring.length()) {
		int entry_index = BoyerMooreSearch(main_string.substr(i), substring);

		if(entry_index + i < end)
			occurrences.push_back(entry_index + i);

		i += entry_index + 1;
	}

	return occurrences;
}