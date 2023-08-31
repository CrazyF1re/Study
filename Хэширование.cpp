#include <iostream>
#include <time.h>
#include "external_chains.h"// внешние цепочки
#include "internal_chains.h"// внутренние цепочки

//метод внутренних цепочек
//int main() 
//{
//	srand(time(0));
//	int n = 15;
//	int *a = new int[n],  h;
//	int p=0;
//	//хеш-функция: h=x%p
//	//создаем массив случайных чисел
//	for (int i = 0; i < n; i++) {
//		a[i] = rand() % 100;
//		std::cout << a[i] << " ";
//	}
//
//	for (int i = 0; i < 4; i++)std::cout << std::endl;
//
//	std::cout << "Enter p for hash-function: ";
//	std::cin >> p;
//
//	Hash table(a, n, p);
//
//	table.Print();
//
//	for (int i = 0; i < 4; i++)std::cout << std::endl;
//
//	int x, y;
//	std::cout << "Enter x and y: ";
//	std::cin >> x >> y;
//	if (table.Find(x) != 0)table.Del(x);
//	std::cout << "Delete element" << x<<" : "<<std::endl;
//	table.Print();
//
//	//std::cout << std::endl;
//	//std::cout << std::endl;
//	//std::cout << std::endl;
//	//for (int i = 0; i < 4; i++)std::cout << std::endl;
//
//	if (table.Find(y) == 0)table.Add(y);
//	std::cout << "Adding element" << y << " : "<<std::endl;
//
//		table.Print();
//	
//
//}






int main()
	{
		srand(time(0));
		int n = 25;
		int *a = new int[n],  h;
		int p=0;
		//хеш-функция: h=x%p
		//создаем массив случайных чисел
		for (int i = 0; i < n; i++) {
			a[i] = rand() % 100;
			std::cout << a[i] << " ";
		}

		for (int i = 0; i < 4; i++)std::cout << std::endl;

		std::cout << "Enter p for hash-function: ";
		std::cin >> p;
		//создаете хеш-таблицу
		List* H = new List[p];
		for (int i = 0; i < n; i++) 
		{
			h = a[i] % p;
			H[h].AddToTail(a[i]);
		}
		
		//вывести хеш-таблицу
		for (int j = 0; j < p; j++) 
		{
			H[j].PrintList();
		}

		for (int i = 0; i < 4; i++)std::cout << std::endl;

		int x, y;
		std::cout << "Enter x and y: ";
		std::cin >> x >> y;
		if (H[x % p].FindKey(x) != 0)H[x % p].Del(H[x%p].FindKey(x));
		for (int j = 0; j < p; j++)
		{
			H[j].PrintList();
		}

		for(int i=0;i<4;i++)std::cout << std::endl;

		if (H[y % p].FindKey(y)==0)H[y % p].AddToTail(y);
		for (int j = 0; j < p; j++)
		{
			H[j].PrintList();
		}
			
}
