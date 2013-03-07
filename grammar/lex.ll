%option noyywrap
%option stack
%option outfile="lexer.cpp"

%{
#include "ast.h"
#include "identifier.h"
#include "parser.h"
#include <cstring>
#include <string>

int yylinenumber = 1;
extern YYSTYPE yylval;
#define YY_NEVER_INTERACTIVE 1 
#define isatty _isatty
%}

	/* Basics */
alpha [A-Za-z]
digit [0-9]
alphanum ({alpha}|{digit})

%%

	/* Reserved words */
"if"												return TIf;
"else"											return TElse;
"while"											return TWhile;
"class"											return TClass;
"extends"										return TExtends;
"public"										return TPublic;
"static"										return TStatic;
"void"											return TVoid;
"main"											return TMain;
"boolean"										return TBoolean;
"int"												return TInteger;
"String"										return TString;
"true"											return TTrue;
"false"											return TFalse;
"this"											return TThis;
"new"					    					return TNew;
"System.out.println"				return TPrintln;
"return"										return TReturn;
"length"										return TArrayLength;

	/* Constants */
{alpha}({alphanum}|"_")*		{ yylval.identifier = new Identifier(std::string(yytext)); return TId; }
{digit}+										{ yylval.itype = atoi(yytext); return TNumber; }
\"(.|"\n")*\"								{ yylval.stype = strdup(yytext); return TText; }

	/* Operators */
"="													return TAssignment;
"!"													return TNot;
"&&"												return TAnd;
"||"												return TOr;
"<"													return TLessThan;
">"													return TGreaterThan;
"!="												return TDifferent;
"=="												return TEqual;
"+"													return TPlus;
"-"													return TMinus;
"*"													return TTimes;
"."													return TMember;

	/* { ( [ , ; */
"("													return TLParen;
")"													return TRParen;
"["													return TLBracket;
"]"													return TRBracket;
"{"													return TLBraces;
"}"													return TRBraces;
","													return TComma;
";"													return TSemiColon;

	/* Ignored */
"//".*"\n"									/* Comment */
"/*"(.|"\n")*"*\\"					/* Comment */
[ \t\r]											/* Whitespace */
"\n"												{yylinenumber++;}

%%