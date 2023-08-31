#include "Code.h"

bool Code::Find(char ch, char s[])
{
	for (int i = 0; i < (int)std::strlen(s); i++) 
	{
		if (s[i] == ch)	return true;
	}
	return false;
}

void Code::PrintTree(Node* p, int k)
{
	if (p == NULL) return;
	PrintTree(p->right, k + 5);
	for (int i = 0; i < k; i++) std::cout << ' ';
	std::cout << p->str << std::endl;
	PrintTree(p->left, k + 5);
	
}

void Code::Copy(Node* q,  Node* p, int f )
{
	if (q == NULL) return;
	Node* t = new Node(q->str, q->freq);
	if (f == 0) p->left = t;
	else p->right = t;
	Copy(q->left, t, 0);
	Copy(q->right, t, 1);
}

Code::Code(char p[])
{
	type = 0;
	//создание массива букв и их частот
	int i, TAB[256] = { 0 };
	for (i = 0; p[i]; i++)
	{
		TAB[(256+p[i])%256]++;
	}


	//поиск 1-го (по ASCII) символа из p и создание головы списка
	char s[2]; s[1] = '\0';
	for (i = 0; i < 256 && TAB[i] == 0; i++);

	if (i == 256) { puts("string is empty"); head = NULL; return; }
	s[0] = i;
	head = new Node(s, TAB[i]);
	i++;

	//формирование упорядоченного по частоте линейного 
	//списка символов строки p
	for (; i < 256; i++)
	{
		if (TAB[i] != 0)
		{
			s[0] = i;
			if (TAB[i] < head->freq) AddToHead(s, TAB[i]);
			else {
				Node* t = head;
				while (t->next && t->next->freq < TAB[i])
					t = t->next;
				if (t->next == NULL) AddToTail(s, TAB[i]);
				else AddAfter(t, s, TAB[i]);
			}
		}
	}

}

Code::~Code()
{
}

void Code::AddToHead(char s[], int f)
{
	Node* temp = new Node(s, f);
	temp->next = head;
	head = temp;
}

void Code::AddToTail(char s[], int f)
{
	Node* temp = new Node(s, f);
	Node* p = head;
	while (p->next != 0)p = p->next;
	p->next = temp;
}

void Code::AddAfter(Node* pr, char s[], int f)
{
	Node* temp = new Node(s, f);
	temp->next = pr->next;
	pr->next = temp;
}

void Code::AddToHead(Node* T)
{
	T->next = head;
	head = T;
}

void Code::AddToTail(Node* T)
{
	Node* temp = head;
	while (temp->next != 0)temp = temp->next;
	temp->next = T;
}

void Code::AddAfter(Node* q, Node* pr)
{
	pr->next = q->next;
	q->next = pr;
}

void Code::DelHead()
{
	Node* del = head;
	if(head->next!=0)head = head->next;
	delete del;
}

void Code::Clear()
{
	
}

void Code::PrintList()
{
	Node* temp = head;
	while(temp!=0)
	{
		std::cout<<temp->str<<"   ";
		temp = temp->next;
	}
}

void Code::PrintTree()
{
	
	PrintTree(head, 5);

	
}

void Code::FormTree()
{
	if (head == NULL)
	{
		 return;
	}

	type = 1;
	Node* q, * p1, * p2, * t;
	int n1, n2, fr;
	char* s;

	while (head->next != 0) 
	{
		p1 = head;  p2 = head->next;
		n1 = strlen(p1->str); n2 = strlen(p2->str);
		s = new char[n1 + n2 + 1];
		strcpy_s(s, n1 + n2 + 1, p1->str);
		strcat_s(s, n1 + n2 + 1, p2->str);
		fr = p1->freq + p2->freq;
		q = new Node(s, fr, NULL, p1, p2);
		head = p2->next;
		delete[]s;

		t = head;
		if (t == NULL) head = q;
		else {
			while (t->next && t->next->freq < fr)
				t = t->next;
			if (t->next == NULL) AddToTail(q);
			else AddAfter(t, q);
		}
	}

}


void Code::CodeText( char s[], char code[], int n)//кодирование строки s, n -- размер строки code
{
	if (type == 0) return; // если тип не дерево - выход
	
	
	int i, TAB[256] = { 0 };//счетчик и таблица букв и частот
	for (i = 0; s[i]; i++)
	{
		//TAB[(256 + s[i]) % 256]++;
		TAB[(unsigned char)s[i]]++;
	}
	
	//создание кодовой таблицы
	char CodeTAB[256][10];
	Node* t;
	for (i = 0; i < 256; i++)
		CodeTAB[i][0] = '\0';

	for (i = 0; i < 256; i++)
	{
		if (TAB[i] != 0)
		{
			t = head;
			while (t->left || t->right)
			{
				if (t->left && Find(i, t->left->str))
				{
					strcat_s(CodeTAB[i], 10, "0"); t = t->left;
				}
				else { strcat_s(CodeTAB[i], 10, "1"); t = t->right; }
			}
		}
	}

	code[0] = '\0';

	for (i = 0; s[i]; i++) {
		strcat_s(code, n, CodeTAB[(unsigned char)s[i]]);
		/*for (int j = 0; j < 10; j++) {
			std::cout << CodeTAB[s[i]][j];
		}*/
		}
	 


}

void Code::DecodeText(char code[], char s[], int n)
{
	int i = 0;
	Node* temp = head;
	if (temp == NULL)return;
	while (code[i]) 
	{
		while (temp->left || temp->right) 
		{
			if (code[i]=='1')temp = temp->right;
			else
			{
				temp = temp->left;
			} 
			i++;
		}
		strcat_s(s, n, temp->str);
		temp = head;
	}
}
