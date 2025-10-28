#include <stdio.h>
#include <string.h>
#include <ctype.h>

int z = 0, i = 0, j = 0, c = 0;
char a[10], stk[20], ac[20];

void reduce();

int main()
{
  printf("Grammer is:\nE->E+E\nE->E*E\nE->(E)\nE->id\n");

  printf("Enter the input string:");
  scanf("%s", a);

  c = strlen(a);

  printf("\nStack\tInput String\tAction");
  printf("\n$\t%s\t", a);

  for (i = 0, j = 0; j < c; i++, j++)
  {
    strcpy(ac, "SHIFT->");
    if (a[j] == 'i' && a[j + 1] == 'd')
    {
      stk[i] = a[j];
      stk[i + 1] = a[j + 1];
      stk[i + 2] = '\0';

      a[j] = ' ';
      a[j + 1] = ' ';

      printf("\n$%s\t%s$\t%sid", stk, a, ac);
      reduce();
    }
    else
    {
      stk[i] = a[j];
      stk[i + 1] = '\0';

      a[j] = ' ';

      printf("\n$%s\t%s$\t%ssymbol", stk, a, ac);
      reduce();
    }
  }
}

void reduce()
{
  strcpy(ac, "Reduce to E");

  for (z = 0; z < c; z++)
    if (stk[z] == 'i' && stk[z + 1] == 'd')
    {
      stk[z] = 'E';
      stk[z + 1] = '\0';
      printf("\n$%s\t%s$\t%s", stk, a, ac);
      j++;
    }

  for (z = 0; z < c; z++)
    if (stk[z] == 'E' && stk[z + 1] == '+' && stk[z + 2] == 'E')
    {
      stk[z] = 'E';
      stk[z + 1] = '\0';
      stk[z + 2] = '\0';
      printf("\n$%s\t%s$\t%s", stk, a, ac);
      i = i - 2;
    }

  for (z = 0; z < c; z++)
    if (stk[z] == 'E' && stk[z + 1] == '*' && stk[z + 2] == 'E')
    {
      stk[z] = 'E';
      stk[z + 1] = '\0';
      stk[z + 2] = '\0';
      printf("\n$%s\t%s$\t%s", stk, a, ac);
      i = i - 2;
    }

  for (z = 0; z < c; z++)
    if (stk[z] == '(' && stk[z + 1] == 'E' && stk[z + 2] == ')')
    {
      stk[z] = 'E';
      stk[z + 1] = '\0';
      stk[z + 2] = '\0';
      printf("\n$%s\t%s$\t%s", stk, a, ac);
      i = i - 2;
    }
}