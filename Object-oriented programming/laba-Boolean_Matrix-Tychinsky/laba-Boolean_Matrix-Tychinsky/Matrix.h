#pragma once
#include "C:\GitHub_Repositories\Labs\Object-oriented programming\laba-Boolean_vector-Tychinsky\laba-Boolean_vector-Tychinsky\Vector.h"

class BoolMatrix {
	typedef unsigned int UI;

public:
	// ������������ (�� ���������, � ����������� (���������� �����/�������� � �������� ��������), ����������� �� ������� char, ����������� �����������);
	BoolMatrix();
	BoolMatrix(const UI col_count, const UI row_count, const bool value);
	BoolMatrix(const char** matrix, const UI col_count, const UI row_count);
	BoolMatrix(const BoolMatrix& other);
	// ����������;
	~BoolMatrix();
	//��������� ����� ����� � �������� �������;
	int GetAmountOfRows();
	int GetAmountOfCols();
	//����� ����������� � ������ �������� (swap);
	void Swap(BoolMatrix& other);
	//����/����� � ������� (���������);
	void Print();
	//��� ������� (���������� ��������� ���������);
	int Weight();
	//���������� ���� ����� (���������� ����� ������);
	
	//���������� ���� ����� (���������� ����� ������);
	
	//��� j-�� ������;
	int Weight(const UI index_row);
	//�������� � i-�� ���������� j-�� ������;
	void Inversion(const int index_i, const int index_j);
	//�������� k ��������� j-�� ������, ������� � i-�� ����������;
	void Inversion(const int index_i, const int index_j, const int k);
	//��������� � 0/1 i-�� ���������� j-�� ������;
	void Set(const bool value, const int index_i, const int index_j);
	//��������� � 0/1 k ��������� j-�� ������, ������� � i-�� ����������;
	void Set(const bool value, const int index_i, const int index_j, const int k);

	//������������ (=);
	
	//��������� ������([]);
	
	//���������� ��������� ���������(&, &=);
	
	//���������� ��������� ��������(| , |=);
	
	//���������� ��������� ����������� ���(^, ^=);
	
	//���������� ��������� ��������(~).






private:
	BoolVector* m_count_vectors = nullptr;
	UI m_amount_row, m_amount_col;
};
