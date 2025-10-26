#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>

char post[30];
char s[30];
int count = 0;
int top = -1;

int priority(char ch)
{
	switch (ch)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^':
		return 3;
	case '(':
		return 4;
	default:
		return -1;
	}
}

void infixtopos(char exp[])
{
	int pos = 0, top = -1;

	char stack[30];
	for (int i = 0; i < strlen(exp); i++)
	{
		if (isalpha(exp[i]))
		{
			post[pos++] = exp[i];
		}
		else
		{
			if (exp[i] == ')')
			{
				while (stack[top] != '(')
				{
					post[pos++] = stack[top--];
				}
			}
			else if (top != -1 && priority(exp[i]) > priority(stack[top]))
			{
				stack[++top] = exp[i];
			}
			else
			{
				while (top != -1 && priority(exp[i]) <= priority(stack[top]))
				{
					post[pos++] = stack[top--];
				}
				stack[++top] = exp[i];
			}
		}
	}
	while (top != -1)
		post[pos++] = stack[top--];
	post[pos] = '\0';
	printf("Postfix Expression:%s", post);
}

void pattern(char ch)
{
	if (isdigit(s[top]) && isdigit(s[top - 1]))
		printf("T%d = T%c %c T%c\n", count, s[top - 1], ch, s[top]);
	else if (isdigit(s[top]))
		printf("T%d = %c %c T%c\n", count, s[top - 1], ch, s[top]);
	else if (isdigit(s[top - 1]))
		printf("T%d = T%c %c %c\n", count, s[top - 1], ch, s[top]);
	else
		printf("T%d = %c %c %c\n", count, s[top - 1], ch, s[top]);
}

void evaluate()
{

	for (int i = 0; i < strlen(post); i++)
	{
		if (isalpha(post[i]))
		{
			s[++top] = post[i];
		}
		else
		{
			switch (post[i])
			{
			case '+':
				pattern('+');
				break;
			case '-':
				pattern('-');
				break;
			case '*':
				pattern('*');
				break;
			case '/':
				pattern('/');
				break;
			case '^':
				pattern('^');
				break;
			default:
				break;
			}
			s[--top] = count + '0';
			count++;
		}
	}
}
void main()
{
	char e[] = "a+b*c-d^e/f";
	infixtopos(e);
	printf("\n");
	evaluate();
}
