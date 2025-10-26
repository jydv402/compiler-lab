%{
    #include <stdio.h>
    int c = 0, v = 0;
%}

%%
[\n\t ]+ ;
[aeiouAEIOU] {v++;}
[^aeiouAEIOU] {c++;}
%%

int main()
{
    printf("Enter the string : ");
    yylex();
    printf("\nCounts\n\tVowels = %d\n\tConsonents = %d\n\t",v,c);
    return 0;
}

int yywrap()
{
    return 1;
}