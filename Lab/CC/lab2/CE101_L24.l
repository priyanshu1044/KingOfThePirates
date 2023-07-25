%option noyywrap
%{
int line_count = 0;
int word_count = 0;
int in_word = 0;
%}

%%
\n { line_count++; }
[a-zA-Z]+ { if (!in_word) { word_count++; in_word = 1; } }
[^a-zA-Z]+ { in_word = 0; }
%%

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }
    
    yyin = file;
    yylex();
    
    printf("Number of lines: %d\n", line_count);
    printf("Number of words: %d\n", word_count);
    
    fclose(file);
    return 0;
}
