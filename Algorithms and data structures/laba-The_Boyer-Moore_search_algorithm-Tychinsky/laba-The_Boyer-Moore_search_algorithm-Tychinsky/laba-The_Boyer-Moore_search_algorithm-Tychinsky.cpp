#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include "Boyer-Moore.h"

int main() {
    setlocale(LC_ALL, "ru");
    //1. [10 баллов] Реализовать функцию получения индекса первого вхождения подстроки в тексте. Эта функция не должна использовать консольный ввод-вывод.
    string main_string = "std::move_iterator is an iterator adaptor which behaves exactly like the underlying iterator";
    string substring = "tor";

    int first_enter = BoyerMooreSearch(main_string, substring);

    if (first_enter <= main_string.length() - substring.length())
        std::cout << "Вывод первого вхождения: " << first_enter << std::endl;
    else std::cout << "ERROR";

    //2. [5 баллов] Реализовать функцию получения индексов всех вхождений подстроки в тексте. Эта функция не должна использовать консольный ввод-вывод, для упрощения работы с памятью используйте класс std::vector<int>.





}