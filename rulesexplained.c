%{
#include <stdio.h>
int yywrap(void) { return 1; } 
//default function that flex expects , called at the end of the input. 
%}


//Rules Section 
%%


[ \t\n]   { /* Ignore spaces, tabs, and newlines */ }
int     { printf("Keyword: int\n"); }
[0-9]+  { printf("Number: %s\n", yytext); }
//yytext is matched text
[a-zA-Z_][a-zA-Z0-9_]* { printf("Identifier: %s\n", yytext); }
"="     { printf("Operator: =\n"); }
";"     { printf("Semicolon: ;\n"); }
.       { printf("Unknown character: %s\n", yytext); }
//Matches any character that doesn’t match any other rule (wildcard rule).

%%


/COde section
int main() {

/*This is the main function generated by Flex. It reads the input, applies the rules defined in the rules section, and calls the corresponding actions.*/
    yylex();
    return 0;
}