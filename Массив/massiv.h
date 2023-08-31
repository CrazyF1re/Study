#pragma once
#include <iostream>
class Array
{
private:
	int n;//���������� ���������
	int* a;//��������� �� ������
public:
	Array();//����������� �� ���������
	Array(int N);//����������� � ����������, N - ���������� ���������
	Array(int* b, int m);//����������� � ���������� ��� N - ���������� ��������� � ������� b
	Array(const Array& X);//����������� �����������
	~Array();//����������
	Array& operator= (const Array& X);//���������� ��������� ������������
	void Scan(int m);//���������� m ���������
	void Print();//����� �������
	int FindKey(int key);// ����� �������� � �������
	int & operator[] (int i);//���������� ��� ���������� �������� �� �������
	Array& operator+= (int key);//���������� ��� ���������� key � ����� �������
	Array operator+(int key);//���������� ��� ������������ ������ ������� b = a+ key
	Array& operator+=(const Array &�);// ���������� ���������� ������� � � ����� ������� �
	Array operator+(const Array& C);//���������� ������������ ������� y = a + C
	Array& operator-=(int key);//���������� �������� ��������	key
	Array operator-(int key);// ������������ ������ ������� b = a - key
	Array& DelPosEq(int pos);// �������� �������� � ������� pos
	Array DelPosNew(int pos);// ������������ ������ ������� b, � ������� ������ ������� �� ������� pos
	bool operator==(Array C);// �������� ��������� ��������
	bool operator!=(Array C);// �������� ����������� ��������
	int Max();//������ ������������� �������� ������� 
	int Min();//������ ������������ �������� �������
	void Sorting();// ���������� ������� 
	void ShiftLeft(int pos);//����� ����� ������� � ������� pos+1
	friend std::ostream & operator << (std::ostream &r,Array &x);
	friend std::istream & operator >> (std::istream &r,Array &x);
	int len();
	int Get_one(int i);
	void random_generate();
};