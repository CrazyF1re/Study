#include <iostream>
#pragma once

class Node 
{
	char* str;
	int freq;
	Node* next, * left, * right;
public:
	Node() // Deafult
	{
		str = new char[1];
		str[0] = '\0';
		freq = 0;
		next = left = right = 0;
	}
	Node(char s[], int fr = 0, Node* nxt = 0, Node* l = 0, Node* r = 0) 
	{
		str = new char[strlen(s) + 1];
		strcpy_s(str,strlen(s)+1, s);
		freq = fr;
		next = nxt;
		left = l;
		right = r;
	}
	Node(const Node& T) 
	{
		str = new char[strlen(T.str) + 1];
		strcpy_s(str, strlen(T.str) + 1, T.str);
		freq = T.freq;
		next = T.next;
		left = T.left;
		right = T.right;
	}
	~Node(){ delete str; }
	friend class Code;

};
 

class Code
{


	Node* head;
	bool type;//1- односвязный список, 1 - дерево



	bool Find(char ch, char s[]);

	void PrintTree(Node* p, int k);

	void Copy(Node* q, Node* p, int k);


public:
	Code() { head = 0; type = 0; }

	Code(char s[]);

	~Code();




	void AddToHead(char s[], int f);

	void AddToTail(char s[], int f);

	void AddAfter(Node* pr, char s[], int k);
	


	void AddToHead(Node* T);

	void AddToTail(Node* T);

	void AddAfter(Node* q, Node* pr);
	

	void DelHead();
	
	void Clear();

	//void Clear(Node* pr, Node* t);

	void PrintList();

	void PrintTree();

	Node* GetHead() { return head; }

	void FormTree();//преобразование списка в дерево

	void CodeText(char s[], char code[], int n);

	void DecodeText(char code[], char s[], int n);

};