#pragma once

class Array {
public:
	//конструкторы
	Array();
	Array(int a[]);
	Array(Array b);

	//деструктор
	~Array();

	int AmountOfArray();//получение размера
	void SwapArrays();//обмен содержимого с другим массивом 
	int FindIndex();//поиск элемента

	void Print();//ввод/вывод
	void Scan();

	void Sorting();//сортировка элементов

	//вставка элемента по индексу
	//удаление элемента по индексу
	//удаление элемента по значению (первое вхождение)
private:
	std::vector<int> array;
};