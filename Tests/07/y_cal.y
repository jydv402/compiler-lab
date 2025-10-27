%{
    #include <stdio.h>
    #include <stdlib.h>
    int yylex(void);
    void yyerror(const char *s);
    int flag = 0;
%}

%token DIGIT

%left'+''-'
%left'*''/''%'
%left'('')'
%%
AE:E {
    printf("\nResult : %d\n", $$ );
    return 0;
}
E:E'+'E { $$ = $1 + $3; }
| E'-'E { $$ = $1 - $3; }
| E'*'E { $$ = $1 * $3; }
| E'/'E {$$ = $1 / $3; }
| E'%'E {$$ = $1 % $3; }
| '('E')' { $$ = $2; }
| DIGIT { $$ = $1; }
;
%%

int main()
{
    printf("Enter the arithmetic expression : ");
    yyparse();
    flag = 0;
    if(flag == 0)
        printf("Valid arithmetic expression");
    return 0;
}

void yyerror(const char *s)
{
    flag = 1;
    printf("Invalid arithmetic expression");
    exit(0);
}