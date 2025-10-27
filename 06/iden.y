%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
void yyerror(const char *s);
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

int main()
{
	printf("Enter the identifier : ");
	yyparse();
	printf("VALID IDENTIFIER");
	return 0;
}

void yyerror(const char *s)
{
	printf("INVALID IDENTIFIER");
	exit(0);
}
