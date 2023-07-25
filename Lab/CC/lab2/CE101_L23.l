%option noyywrap

%{
#include <stdio.h>
int a_count = 0;
int an_count = 0;
int the_count = 0;
%}

%%
[aA][ ]      { a_count++; }
[aA][nN][ ]  { an_count++; }
[tT][hH][eE][ ] { the_count++; }
.    ;
%%

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: ./article_counter <input_file>\n");
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    yyin = file;
    yylex();

    printf("Occurrences:\n");
    printf("'a': %d\n", a_count);
    printf("'an': %d\n", an_count);
    printf("'the': %d\n", the_count);

    fclose(file);
    return 0;
}
