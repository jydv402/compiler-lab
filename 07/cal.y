%{
	#include <stdio.h>
	#include <stdlib.h>
	int yylex(void);
	void yyerror(const char *s);
	int flag = 0;
%}

%token NUMBER
%left'+''-'
%left'*''/''%'
%left'('')'

%%
AE:E {
		printf("\nResult is %d: \n",$$);
		return 0;
	}
E:E'+'E	{$$=$1+$3;}
| E'-'E	{$$=$1-$3;}
| E'*'E	{$$=$1*$3;}
| E'/'E	{$$=$1/$3;}
| E'%'E	{$$=$1%$3;}
| '('E')'	{$$=$2;}
| NUMBER	{$$=$1;}
%%

void main()
{
	printf("Enter the Arithmetic expression : ");
	yyparse();
	flag=0;
	if(flag==0)
	{
		printf("\nValid\n");
	}
	
	exit(0);
}

void yyerror(const char *s)
{
	flag = 1;
	printf("\nInvalid\n");
	exit(0);
}
