#include <stdio.h>
#include <string.h>
#include <ctype.h>

char input[200];
int i = 0, error = 0;

void E();
void T();
void Eprime();
void Tprime();
void F();

void main()
{
	printf("Enter the arithmetic expression : ");
	scanf("%s", input);

	E();

	if (strlen(input) == i && error == 0)
	{
		printf("\nInput is accepted\n");
	}
	else
	{
		printf("\nInput is rejected\n");
	}
}

void E()
{
	T();
	Eprime();
}

void T()
{
	F();
	Tprime();
}

void Eprime()
{
	if (input[i] == '+')
	{
		i++;
		T();
		Eprime();
	}
}

void Tprime()
{
	if (input[i] == '*')
	{
		i++;
		F();
		Tprime();
	}
}

void F()
{
	if (isalnum(input[i]))
	{
		while (isalnum(input[i]))
			i++;
	}
	else if (input[i] == '(')
	{
		i++;
		E();
		if (input[i] == ')')
			i++;
		else
			error = 1;
	}
	else
	{
		error = 1;
	}
}
