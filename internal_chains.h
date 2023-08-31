#pragma once
class Usel
{
	int key, next;
public:
	Usel(int k = -1, int N = -1)
	{
		key = k; next = N;
	}
	void PrintUsel();
	friend class Hash;
};

class Hash
{
	int dim;  		//������ ���-�������
	int p;			//���-�������: h=x%p
	Usel* TAB;

public:
	Hash();
	Hash(int a[], int n, int P); 	//n--������ ������� a
								   //p=P
	~Hash();
	Hash(const Hash&);
	Hash& operator= (const Hash&);
	void Add(int k);	//���������� ��-�� � ���-�������
	Usel* Find(int k);
	void Del(int k);	//k -- ����
	void Print();
};
