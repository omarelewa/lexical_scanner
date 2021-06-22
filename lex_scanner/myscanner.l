%{
	#include "myscanner.h"
%}

%%

[a-zA-z][a-zA-z0-9]*([\.|@|_][a-zA-z0-9]*)			return ID;
[0-9]												return DIGIT;
[0-9]+([0-9]\.[0-9][[E|e][\+|\-]?[0-9]]*)*			return NUM;

[a-zA-z]											return LETTER;


\/\*				    							return COMMENT_OPEN;
\*\/												return COMMENT_CLOSE;

\+													return PLUS;
\-													return MINUS;
\*													return MULTIPLY;
\/													return FORWARD_SLASH;

"<"													return G_THAN;
"<="												return G_THAN_EQUAL;
>													return L_THAN;
>=													return L_THAN_EQUAL;
==													return EQUAL_EQUAL;
!=													return NOT_EQUAL;
=													return EQUAL;

;													return SEMICOLON;
,													return COMMA;

\(													return OPEN_PAR;
\)													return CLOSE_PAR;
\[.													return OPEN_BRACKET;
\].													return CLOSE_BRACKET;
\{													return OPEN_CURLY;
\}													return CLOSE_CURLY;

[e|E][l|L][s|S][e|E]								return ELSE;
[i|I][f|F]											return IF;
[i|I][n|N][t|T]										return INT;
[r|R][e|E][t|T][u|U][r|R][n|N]						return RETURN;
[v|V][o|O][i|I][d|D]								return VOID;
[w|W][h|H][i|I][l|L][e|E]							return WHILE;

<<EOF>>												return EOF;					

[ \t\n]												;
 						


.													printf("Syntax Error: unexpected character.\n");

%%

int yywrap(void)
{
	return 1;
}