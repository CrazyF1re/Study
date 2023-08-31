#pragma once
#include "bool_vector.h"

class Set : public BoolVector 
{
	int M; // ���������� ���������

public:
	Set();
	Set(char* );
	Set(const Set& );
	~Set() override;
	Set& operator = (const Set& );
	Set operator +(char);// ���������� �������� � ��������� ��������� ����� ���������
	Set& operator+=(char);//���������� �������� � ���������, ���������� *this
	Set operator -(char);// �������� �������� �� ��������� ��������� ����� ���������
	Set& operator-=(char);//�������� �������� �� ���������,���������� *this
	Set operator +(Set );// ����������� ��������,��������� ����� ���������
	Set& operator+=(Set );//����������� ��������, ���������� *this
	Set operator *(Set );// ����������� ��������,��������� ����� ���������
	Set& operator*=(Set );//����������� ��������, ���������� *this
	Set operator -(Set );// �������� �������� *this/X ��������� ����� ���������
	Set& operator-=(Set );//�������� �������� *this/X,���������� *this
	Set operator~();//���������� �� �������������� ��������� (��.��������� - ��������� �� 256 �������� ��������)
	bool operator ==(Set );//�������� ��������� ���� ��������
	bool operator !=(Set );
	int GetNumber();//���������� �����  ��������� ���������
	bool FindKey(char);//�������� �������������� ��������
	bool Is_Empty();
	bool Is_not_Empty();
	virtual void Print()override;
	virtual void Scan(int n)override;

	friend std::ostream& operator <<(std::ostream& r, Set& X);
	friend std::istream& operator >>(std::istream& r, Set& X);
	operator int() 
	{
		return M;
	}
};