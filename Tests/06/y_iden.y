%{
    #include <stdio.h>
    #include <stdlib.h>
    int yylex(void);
    void yyerror(const char *s);
%}

%token DIGIT
%token LETTER

%%
stmt:A;
A:LETTER B;
B:LETTER B
| DIGIT B
|
;
%%

int main()
{
    printf("Enter the identifier name : ");
    yyparse();
    printf("\nVALID\n");
    return 0;
}

void yyerror(const char *s)
{
    printf("\nINVALID\n");
    exit(0);
}