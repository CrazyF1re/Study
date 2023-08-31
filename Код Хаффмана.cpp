
#include <iostream>
#include "Code.h"

int main()
{
    setlocale(LC_ALL, "RU");
    char str[] = "на дворе трава, на траве дрова";
    Code example(str);
    example.FormTree();
    example.PrintTree();
    char code[1000];
    code[0] = '\0';

    example.CodeText(str, code, 1000);

    for (int i = 0; code[i]; i++) std::cout << code[i];

    char s[1000];
    s[0] = '\0';
    example.DecodeText(code, s, 1000);

    std::cout << std::endl;

    for (int i = 0; s[i]; i++)
    {
        std::cout << s[i];
    }
}