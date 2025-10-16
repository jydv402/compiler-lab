%{
	#include<stdio.h>
%}
%token DIGIT LETTER
%%
stmt:A
A:LETTER B;
B:LETTER B
|DIGIT B
|
;
%%
void main()
{
	printf("Enter string:");
	yyparse();
	printf("Valid");
	exit(0);
}
void yyerror()
{
	printf("Invalid");
	exit(0);
} 
