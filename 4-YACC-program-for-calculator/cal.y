%{
  #include <stdio.h>
  int flag=0;
%}
%token NUMBER;
%left'+''-'
%left'*''/''%'
%left'('')'
%%
 AE: E{
  printf("\nResult = %d\n",$$);
  return 0;
  }; 
E:E'+'E{$$=$1+$3;}
 |E'-'E {$$=$1-$3;}
 |E'*'E {$$=$1*$3;}
 |E'/'E {$$=$1/$3;}
 |E'%'E {$$=$1%$3;}
 |'('E')' {$$=$2;}
 |NUMBER {$$=$1;}
 ;
%%

void main()
 {
   printf("\nEnter the arithmetic expression:");
   yyparse();
   if(flag==0)
   printf("\nThe arithmetic expression is VALID\n");
 }

void yyerror()
 {
   printf("\nThe entered arithmetic expression is INVALID.\n");
   flag=1;
 }

