%{
#include <stdio.h>
int v=0,c=0;    
%}

%%
[\n\t ]+	;
[aeiouAEIOU]	{v++;}
[^aeiouAEIOU]	{c++;}
%%

int main()
{
	printf("Enter the input string : ");
	yylex();
	printf("No of vowels %d\n",v);
	printf("No of consonents %d\n",c);
	return 0;
}

int yywrap()
{
	return 1;
}
