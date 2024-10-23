#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include "Boyer-Moore.h"

using namespace std;

//#1
int BoyerMooreSearch(const string main_string, const string substring) {

	char* main_string_c = CharCreator(main_string);
	char* substring_c = CharCreator(substring);

	int* substring_cheese = CreateMassiveOfNumbersSubstring(substring, substring_c);

	int i = 0;
	while (i <= main_string.length() - substring.length()) {
		int j = substring.length();
		while (j > 0 && main_string_c[i + j - 1] == substring_c[j - 1])
			j--;

		if (j == 0) break;
		else if (j == substring.length()) {
			int k = substring.length();
			while (k > 0 && main_string_c[i + j - 1] != substring_c[k - 1])
				k--;
			if (k == 0)
				i += substring_cheese[substring.length()];
			else if (k > 0 && main_string_c[i + j - 1] == substring_c[k - 1])
				i += substring_cheese[k - 1];
		}
		else if (j < substring.length())
			i += substring_cheese[j];

	}
	delete[] main_string_c, substring_c;
	return i;
}

int* CreateMassiveOfNumbersSubstring(const string substring, char* substring_c) {
	int* massive_cheese = new int[substring.length() + 1];

	for (int i = 2; i <= substring.length(); i++)
		massive_cheese[substring.length() - i] = i - 1;

	massive_cheese[substring.length() - 1] = substring.length();
	massive_cheese[substring.length()] = substring.length();

	for (int i = 2; i <= substring.length(); i++) {
		for (int j = 3; j <= substring.length(); j++)
			if (substring_c[substring.length() - i] == substring_c[substring.length() - j])
				massive_cheese[substring.length() - j] = massive_cheese[substring.length() - i];

		if (substring_c[substring.length() - 1] == substring_c[substring.length() - i])
			massive_cheese[substring.length() - 1] = massive_cheese[substring.length() - i];
	}

	return massive_cheese;
	delete[] massive_cheese;
}

char* CharCreator(string str) {
	char* cheese = new char[str.length() + 1];
	for (int i = 0; i < str.length(); i++) cheese[i] = str[i];
	cheese[str.length()] = '\0';
	return cheese;
	delete[] cheese;
}

//#2