#include <stdio.h>
#include "myscanner.h"

extern int yylex();

extern int yylineno;

extern char* yytext;

char * names[] = { 			NULL				,
					"ID"				,
					"NUM"				,
					"LETTER"			,
					"DIGIT"				,
					"COMMENT_OPEN"			,
					"PLUS"				,
					"MINUS"				,
					"MULTIPLY"			,
					"FORWARD_SLASH"			,
					"G_THAN"			,
					"G_THAN_EQUAL"			,
					"L_THAN"			,
					"L_THAN_EQUAL"			,
					"EQUAL_EQUAL"			,
					"NOT_EQUAL"			,
					"EQUAL"				,
					"SEMICOLON"			,
					"COMMA"				,
					"OPEN_PAR"			,
					"CLOSE_PAR"			,
					"OPEN_BRACKET"			,
					"CLOSE_BRACKET"			,
					"OPEN_CURLY"			,
					"CLOSE_CURLY"			,
					"ELSE"				,
					"IF"				,
					"INT"				,
					"RETURN"			,
					"VOID"				,
					"WHILE"				,
					"COMMENT_CLOSE"			,
					"EOF"
				};

int main (void)
{
	int ntoken, vtoken;

	int comment_flag = 0;

	ntoken = yylex();

	while (ntoken)
	{
		if (!comment_flag)
		{
			switch (ntoken)
			{
				case COMMENT_OPEN:
					comment_flag = 1;
					break;
				case PLUS:
				case MINUS:
				case MULTIPLY:
				case FORWARD_SLASH:
				case G_THAN:
				case G_THAN_EQUAL:
				case L_THAN:
				case L_THAN_EQUAL:
				case EQUAL_EQUAL:
				case NOT_EQUAL:
				case EQUAL:
					printf("operator (%s) \n", names[ntoken]);
					break;
				case ID:
				case NUM:
				case LETTER:
				case DIGIT:
				case SEMICOLON:
				case COMMA:
				case OPEN_PAR:
				case CLOSE_PAR:
				case OPEN_BRACKET:
				case CLOSE_BRACKET:
				case OPEN_CURLY:
				case CLOSE_CURLY:
				case ELSE:
				case IF:
				case INT:
				case RETURN:
				case VOID:
				case WHILE:
					printf("%s\n", names[ntoken]);
					break;
				case EOF:
					printf("End of file\n");
					break;
				
				default:
					printf("Syntax Error at line %d\n", yylineno);
					break;
			}
		}
		else
		{
			if (ntoken == COMMENT_CLOSE)
			{
				printf("[comment]\n");
				comment_flag = 0;	
			}
		}
		
		ntoken = yylex();
	}

	if (comment_flag == 1)
	{
		printf("File ended inside a comment block.\n");
	}

	return 0;
} 
