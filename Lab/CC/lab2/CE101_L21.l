%option noyywrap
%{
#include <stdio.h>
%}

%%
(00|11)[01]*(00|11)   { printf("Accepted: %s\n", yytext); }
.                      { printf("Rejected\n"); }
%%

int main() {
    yylex();
    return 0;
}
