#include <iostream>
#include <string>
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
    std::vector<int> all_occurrences = SearchAllOccurrences(main_string, substring);

    std::cout << "Вывод всех вхождений: " << std::endl;
    std::copy(all_occurrences.begin(), all_occurrences.end(), std::ostream_iterator<int>(std::cout, " "));

    //3. [10 баллов] Реализовать функцию получения индексов вхождений подстроки в тексте в заданном диапазоне (индексы начала и конца поиска в тексте). Эта функция не должна использовать консольный ввод-вывод, для упрощения работы с памятью используйте класс std::vector<int>.
    std::vector<int> findAll_0_91 = SearchAllOccurrencesInRange(main_string, substring, 0, 91);
    std::vector<int> findAll_17_91 = SearchAllOccurrencesInRange(main_string, substring, 17, 91);
    std::vector<int> findAll_28_36 = SearchAllOccurrencesInRange(main_string, substring, 28, 36);

    std::cout << std::endl << "findAll(0, 91), ответ: ";
    std::copy(findAll_0_91.begin(), findAll_0_91.end(), std::ostream_iterator<int>(std::cout, " "));

    std::cout << std::endl << "findAll(17, 91), ответ: ";
    std::copy(findAll_17_91.begin(), findAll_17_91.end(), std::ostream_iterator<int>(std::cout, " "));

    std::cout << std::endl << "findAll(28, 36), ответ: ";
    std::copy(findAll_28_36.begin(), findAll_28_36.end(), std::ostream_iterator<int>(std::cout, " "));

}