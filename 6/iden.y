%{
#include <stdio.h>
%}

%token LETTER DIGIT
%%
stmt:A;
A:LETTER B;
B:LETTER B;
| DIGIT B;
|
;
%%

void main()
{
	printf("Enter input string : ");
	yyparse();
	printf("VALID");
	exit(0);
}

void yyerror()
{
	printf("Not valid identifier");
	exit(0);
}
