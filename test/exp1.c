#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKey(char buffer[])
{
    char keywords[][10] = {"int", "char", "void", "main", "printf", "include", "stdio"};

    for (int i = 0; i < 7; i++)
    {
        if (strcmp(keywords[i], buffer) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    char ch;
    char buffer[50];
    int i = 0;

    FILE *fp = fopen("one.c", "r");

    if (fp == NULL)
    {
        printf("No File");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        if (isalnum(ch) || ch == '_')
        {
            buffer[i++] = ch;
        }
        else
        {
            if (i > 0)
            {
                buffer[i] = '\0';
                i = 0;

                if (iskeyword(buffer))
                    printf("%s is keyword\n", buffer);
                else if (isalpha(buffer[0]) || buffer[0] == '_')
                    printf("%s is identifier\n", buffer);
                else if (isdigit(buffer[0]))
                    printf("%s is constant\n", buffer);
            }

            if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
                printf("%c is operator\n", ch);
            else if (strchr(";(){}[]=,#", ch))
                printf("%c is special character\n", ch);
        }
    }

    if (i > 0)
    {
        buffer[i] = '\0';
        if (iskeyword(buffer))
            printf("%s is keyword\n", buffer);
        else if (isalpha(buffer[0]) || buffer[0] == '_')
            printf("%s is identifier\n", buffer);
        else if (isdigit(buffer[0]))
            printf("%s is constant\n", buffer);
    }

    fclose(fp);
    return 0;
}