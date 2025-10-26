%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int word=0, lines=0, ch=0;    
%}
%%
[a-z|A-Z|0-9] {ch++;}
" " {word++;}
"\n" {lines++;word++;}
. {}
%%

void main(int argc, char *argv[])
{
	yyin=fopen(argv[1],"r");
	yylex();
	printf("No of Words: %d\n",word);
	printf("No of Lines: %d\n",lines);
	printf("No of Characters: %d\n",ch);
}

int yywrap()
{
	return 1;
}
