%option noyywrap

%{
int prev_char = 0;
%}

%%
[a-zA-Z]+ {
    if (strcmp(yytext, yytext + 1) >= 0) {
        printf("Invalid: %s\n", yytext);
        return 0;
    }
}

\n {
    if (prev_char != 0 && prev_char != '\n') {
        printf("Invalid: %s\n", yytext);
        return 0;
    }
    prev_char = '\n';
}

. { prev_char = yytext[0]; }
%%

int main() {
    yylex();
    printf("Valid: All strings are in lexicographical order.\n");
    return 0;
}
