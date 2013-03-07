
/*  A Bison parser, made from c:\dev\mj\grammar/grammar.yy with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	TIf	258
#define	TElse	259
#define	TWhile	260
#define	TClass	261
#define	TExtends	262
#define	TPublic	263
#define	TStatic	264
#define	TVoid	265
#define	TMain	266
#define	TMainClass	267
#define	TBoolean	268
#define	TInteger	269
#define	TString	270
#define	TTrue	271
#define	TFalse	272
#define	TThis	273
#define	TNew	274
#define	TPrintln	275
#define	TReturn	276
#define	TArrayLength	277
#define	TId	278
#define	TNumber	279
#define	TText	280
#define	TAssignment	281
#define	TNot	282
#define	TAnd	283
#define	TOr	284
#define	TLessThan	285
#define	TGreaterThan	286
#define	TDifferent	287
#define	TEqual	288
#define	TPlus	289
#define	TMinus	290
#define	TTimes	291
#define	TMember	292
#define	TLParen	293
#define	TRParen	294
#define	TLBracket	295
#define	TRBracket	296
#define	TLBraces	297
#define	TRBraces	298
#define	TComma	299
#define	TSemiColon	300


#include <cstdio>
#include <string>
#include "ast.h"

extern int yylex();
int yyerror(char * msg);
extern int yylinenumber;
Program* syntaxResult;

typedef union {
	int itype;
	char* stype;

	Type* type;
	
	ExpList* expList;
	ClassList* classList;
	VarList* varList;
	MethodList* methodList;
	ArgumentList* argumentList;
	StmtList* stmtList;

	Program* program;
	MainClass* mainClass;
	ClassDecl* classDecl;
	VarDecl* varDecl;
	MethodDecl* methodDecl;
	MainMethodDecl* mainMethodDecl;
	Stmt* stmt;
	Exp* exp;
	Argument* argument;

	Identifier* identifier;
} YYSTYPE;

#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#ifndef YYDEBUG
#define YYDEBUG 1
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		155
#define	YYFLAG		-32768
#define	YYNTBASE	46

#define YYTRANSLATE(x) ((unsigned)(x) <= 300 ? yytranslate[x] : 65)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     3,     9,    23,    26,    27,    28,    31,    32,    35,
    36,    43,    52,    56,    69,    72,    73,    77,    78,    81,
    85,    89,    91,    93,    95,    98,    99,   103,   111,   117,
   123,   128,   136,   138,   141,   142,   146,   147,   151,   155,
   159,   163,   167,   171,   175,   179,   183,   185,   190,   194,
   201,   203,   205,   207,   209,   211,   217,   222,   225
};

static const short yyrhs[] = {    47,
    51,     0,     6,    12,    42,    48,    43,     0,     8,     9,
    10,    11,    38,    15,    40,    41,    23,    39,    42,    59,
    43,     0,    54,    49,     0,     0,     0,    53,    50,     0,
     0,    52,    51,     0,     0,     6,    23,    42,    50,    49,
    43,     0,     6,    23,     7,    23,    42,    50,    49,    43,
     0,    58,    23,    45,     0,     8,    58,    23,    38,    55,
    39,    42,    59,    21,    64,    45,    43,     0,    57,    56,
     0,     0,    44,    57,    56,     0,     0,    58,    23,     0,
    14,    40,    41,     0,    15,    40,    41,     0,    13,     0,
    14,     0,    23,     0,    60,    59,     0,     0,    42,    59,
    43,     0,     3,    38,    64,    39,    60,     4,    60,     0,
     5,    38,    64,    39,    60,     0,    20,    38,    64,    39,
    45,     0,    23,    26,    64,    45,     0,    23,    40,    64,
    41,    26,    64,    45,     0,    53,     0,    64,    62,     0,
     0,    44,    64,    62,     0,     0,    64,    29,    64,     0,
    64,    28,    64,     0,    64,    30,    64,     0,    64,    31,
    64,     0,    64,    32,    64,     0,    64,    33,    64,     0,
    64,    34,    64,     0,    64,    35,    64,     0,    64,    36,
    64,     0,    63,     0,    64,    40,    64,    41,     0,    64,
    37,    22,     0,    64,    37,    23,    38,    61,    39,     0,
    24,     0,    16,     0,    17,     0,    23,     0,    18,     0,
    19,    14,    40,    64,    41,     0,    19,    23,    38,    39,
     0,    27,    64,     0,    38,    64,    39,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   116,   119,   122,   125,   126,   129,   130,   131,   134,   135,
   138,   139,   142,   145,   148,   149,   152,   153,   156,   159,
   160,   161,   162,   163,   166,   167,   170,   171,   172,   173,
   174,   175,   176,   179,   180,   183,   184,   187,   188,   189,
   190,   191,   192,   193,   194,   195,   198,   199,   200,   201,
   202,   203,   204,   205,   206,   207,   208,   209,   210
};

static const char * const yytname[] = {   "$","error","$undefined.","TIf","TElse",
"TWhile","TClass","TExtends","TPublic","TStatic","TVoid","TMain","TMainClass",
"TBoolean","TInteger","TString","TTrue","TFalse","TThis","TNew","TPrintln","TReturn",
"TArrayLength","TId","TNumber","TText","TAssignment","TNot","TAnd","TOr","TLessThan",
"TGreaterThan","TDifferent","TEqual","TPlus","TMinus","TTimes","TMember","TLParen",
"TRParen","TLBracket","TRBracket","TLBraces","TRBraces","TComma","TSemiColon",
"program","mainclass","mainmethoddecl","methoddecllist","vardecllist","classdecllist",
"classdecl","vardecl","methoddecl","formallist","formalrestlist","argument",
"type","stmtlist","stmt","explist","exprestlist","boolexp","exp",""
};
#endif

static const short yyr1[] = {     0,
    46,    47,    48,    49,    49,    50,    50,    50,    51,    51,
    52,    52,    53,    54,    55,    55,    56,    56,    57,    58,
    58,    58,    58,    58,    59,    59,    60,    60,    60,    60,
    60,    60,    60,    61,    61,    62,    62,    63,    63,    63,
    63,    63,    63,    63,    63,    63,    64,    64,    64,    64,
    64,    64,    64,    64,    64,    64,    64,    64,    64
};

static const short yyr2[] = {     0,
     2,     5,    13,     2,     0,     0,     2,     0,     2,     0,
     6,     8,     3,    12,     2,     0,     3,     0,     2,     3,
     3,     1,     1,     1,     2,     0,     3,     7,     5,     5,
     4,     7,     1,     2,     0,     3,     0,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     1,     4,     3,     6,
     1,     1,     1,     1,     1,     5,     4,     2,     3
};

static const short yydefact[] = {     0,
     0,    10,     0,     0,     1,    10,     0,     0,     9,     0,
     0,     0,     6,     0,     2,     0,    22,    23,     0,    24,
     5,     6,     0,     0,     6,     0,     0,     0,     0,     5,
     7,     0,     0,     5,    20,    21,     0,    11,     4,    13,
     0,     0,     0,     0,    12,    16,     0,     0,    18,     0,
     0,     0,     0,    15,    19,     0,    26,    18,     0,     0,
     0,     0,    24,    26,    33,     0,    26,    17,    26,     0,
     0,     0,     0,     0,     0,     0,    25,     0,    52,    53,
    55,     0,    54,    51,     0,     0,    47,     0,     0,     0,
     0,     0,    27,     0,     3,     0,     0,    58,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    31,     0,     0,     0,     0,    59,    39,
    38,    40,    41,    42,    43,    44,    45,    46,    49,     0,
     0,     0,    29,    30,     0,    14,     0,    57,    35,     0,
    48,     0,    56,     0,    37,    28,    32,    50,     0,    34,
    37,    36,     0,     0,     0
};

static const short yydefgoto[] = {   153,
     2,    11,    29,    21,     5,     6,    65,    30,    48,    54,
    49,    23,    66,    67,   144,   150,    87,    88
};

static const short yypact[] = {     4,
     8,    32,     6,    33,-32768,    32,    52,    -3,-32768,    58,
    28,    50,   255,    64,-32768,    35,-32768,    36,    49,-32768,
    67,   255,    70,    79,   255,    53,    54,   255,    65,    67,
-32768,    62,    72,    67,-32768,-32768,    88,-32768,-32768,-32768,
    77,    82,    74,    73,-32768,   255,    85,    89,    86,   106,
   108,   101,   255,-32768,-32768,   107,     3,    86,   102,   109,
   110,   123,   -19,     3,-32768,   139,     3,-32768,     3,    34,
    34,    34,    34,    34,   131,    34,-32768,   132,-32768,-32768,
-32768,     5,-32768,-32768,    34,    34,-32768,   164,   177,   190,
    51,   122,-32768,    69,-32768,   148,   151,   216,   203,    34,
    34,    34,    34,    34,    34,    34,    34,    34,    47,     3,
    34,     3,   157,-32768,   189,   185,    34,   202,-32768,   227,
   227,   239,   239,   246,   246,     7,     7,   -28,-32768,   217,
   250,   136,-32768,-32768,    34,-32768,   150,-32768,    34,     3,
-32768,    87,-32768,   226,   105,-32768,-32768,-32768,    34,-32768,
   105,-32768,   266,   277,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,    25,    40,   278,-32768,    41,-32768,-32768,   229,
   232,    -4,   -42,   -99,-32768,   137,-32768,   -71
};


#define	YYLAST		288


static const short yytable[] = {    89,
    90,    91,    92,    12,    94,    60,    73,    61,   109,     1,
   131,   111,   133,    98,    99,    17,    18,    19,    96,     3,
    74,    75,    62,    37,    77,    63,    78,    97,   120,   121,
   122,   123,   124,   125,   126,   127,   128,     4,    13,   132,
   146,    50,   108,   109,    64,   137,   111,     7,    50,    79,
    80,    81,    82,    22,    39,     8,    83,    84,    42,    10,
    85,    31,    22,   142,    34,    22,    14,   145,   129,   130,
    15,    86,    16,    24,    28,    26,    25,   151,   100,   101,
   102,   103,   104,   105,   106,   107,   108,   109,    27,    33,
   111,    44,    32,    35,    36,   114,   100,   101,   102,   103,
   104,   105,   106,   107,   108,   109,    40,    38,   111,    41,
    43,    46,    47,   116,   100,   101,   102,   103,   104,   105,
   106,   107,   108,   109,    45,    51,   111,    52,    55,    53,
    56,   147,   100,   101,   102,   103,   104,   105,   106,   107,
   108,   109,    57,    69,   111,    59,    70,    71,   149,   100,
   101,   102,   103,   104,   105,   106,   107,   108,   109,    76,
    72,   111,   115,   100,   101,   102,   103,   104,   105,   106,
   107,   108,   109,    93,    95,   111,   141,   100,   101,   102,
   103,   104,   105,   106,   107,   108,   109,   117,   118,   111,
   143,   100,   101,   102,   103,   104,   105,   106,   107,   108,
   109,   134,   110,   111,   100,   101,   102,   103,   104,   105,
   106,   107,   108,   109,   135,   112,   111,   100,   101,   102,
   103,   104,   105,   106,   107,   108,   109,   136,   113,   111,
   100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
   138,   119,   111,   100,   101,   102,   103,   104,   105,   106,
   107,   108,   109,   140,   139,   111,   102,   103,   104,   105,
   106,   107,   108,   109,   148,   154,   111,    17,    18,    19,
   104,   105,   106,   107,   108,   109,   155,    20,   111,   106,
   107,   108,   109,     9,    58,   111,    68,   152
};

static const short yycheck[] = {    71,
    72,    73,    74,     7,    76,     3,    26,     5,    37,     6,
   110,    40,   112,    85,    86,    13,    14,    15,    14,    12,
    40,    64,    20,    28,    67,    23,    69,    23,   100,   101,
   102,   103,   104,   105,   106,   107,   108,     6,    42,   111,
   140,    46,    36,    37,    42,   117,    40,    42,    53,    16,
    17,    18,    19,    13,    30,    23,    23,    24,    34,     8,
    27,    22,    22,   135,    25,    25,     9,   139,    22,    23,
    43,    38,    23,    10,     8,    40,    42,   149,    28,    29,
    30,    31,    32,    33,    34,    35,    36,    37,    40,    11,
    40,    15,    23,    41,    41,    45,    28,    29,    30,    31,
    32,    33,    34,    35,    36,    37,    45,    43,    40,    38,
    23,    38,    40,    45,    28,    29,    30,    31,    32,    33,
    34,    35,    36,    37,    43,    41,    40,    39,    23,    44,
    23,    45,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    42,    42,    40,    39,    38,    38,    44,    28,
    29,    30,    31,    32,    33,    34,    35,    36,    37,    21,
    38,    40,    41,    28,    29,    30,    31,    32,    33,    34,
    35,    36,    37,    43,    43,    40,    41,    28,    29,    30,
    31,    32,    33,    34,    35,    36,    37,    40,    38,    40,
    41,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    45,    39,    40,    28,    29,    30,    31,    32,    33,
    34,    35,    36,    37,    26,    39,    40,    28,    29,    30,
    31,    32,    33,    34,    35,    36,    37,    43,    39,    40,
    28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
    39,    39,    40,    28,    29,    30,    31,    32,    33,    34,
    35,    36,    37,     4,    38,    40,    30,    31,    32,    33,
    34,    35,    36,    37,    39,     0,    40,    13,    14,    15,
    32,    33,    34,    35,    36,    37,     0,    23,    40,    34,
    35,    36,    37,     6,    53,    40,    58,   151
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */


/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif



/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
{ syntaxResult = new Program(yyvsp[-1].mainClass, yyvsp[0].classList); yyval.program = syntaxResult; ;
    break;}
case 2:
{ yyval.mainClass = new MainClass(yyvsp[-1].mainMethodDecl); ;
    break;}
case 3:
{ yyval.mainMethodDecl = new MainMethodDecl(yyvsp[-4].identifier, yyvsp[-1].stmtList); ;
    break;}
case 4:
{ MethodList* list = new MethodList(); list->insert(yyvsp[-1].methodDecl); list->insert(yyvsp[0].methodList); yyval.methodList = list; delete yyvsp[0].methodList; ;
    break;}
case 5:
{ yyval.methodList = new MethodList(); ;
    break;}
case 7:
{ VarList* list = new VarList(); list->insert(yyvsp[-1].varDecl); list->insert(yyvsp[0].varList); yyval.varList = list; delete yyvsp[0].varList; ;
    break;}
case 8:
{ yyval.varList = new VarList(); ;
    break;}
case 9:
{ ClassList* list = new ClassList(); list->insert(yyvsp[-1].classDecl); list->insert(yyvsp[0].classList); yyval.classList = list; delete yyvsp[0].classList; ;
    break;}
case 10:
{ yyval.classList = new ClassList(); ;
    break;}
case 11:
{ yyval.classDecl = new NormalClassDecl(yyvsp[-4].identifier, yyvsp[-2].varList, yyvsp[-1].methodList); ;
    break;}
case 12:
{ yyval.classDecl = new ExtendsClassDecl(yyvsp[-6].identifier, yyvsp[-4].identifier, yyvsp[-2].varList, yyvsp[-1].methodList); ;
    break;}
case 13:
{ yyval.varDecl = new VarDecl(yyvsp[-2].type, yyvsp[-1].identifier); ;
    break;}
case 14:
{ yyval.methodDecl = new MethodDecl(yyvsp[-10].type, yyvsp[-9].identifier, yyvsp[-7].argumentList, yyvsp[-4].stmtList, yyvsp[-2].exp); ;
    break;}
case 15:
{ ArgumentList* list = new ArgumentList(); list->insert(yyvsp[-1].argument); list->insert(yyvsp[0].argumentList); yyval.argumentList = list; delete yyvsp[0].argumentList; ;
    break;}
case 16:
{ yyval.argumentList = new ArgumentList(); ;
    break;}
case 17:
{ ArgumentList* list = new ArgumentList(); list->insert(yyvsp[-1].argument); list->insert(yyvsp[0].argumentList); yyval.argumentList = list; delete yyvsp[0].argumentList; ;
    break;}
case 18:
{ yyval.argumentList = new ArgumentList(); ;
    break;}
case 19:
{ yyval.argument = new Argument(yyvsp[-1].type, yyvsp[0].identifier); ;
    break;}
case 20:
{ yyval.type = new Type("int[]"); ;
    break;}
case 21:
{ yyval.type = new Type("String[]"); ;
    break;}
case 22:
{ yyval.type = new Type("bool"); ;
    break;}
case 23:
{ yyval.type = new Type("int"); ;
    break;}
case 24:
{ yyval.type = new Type(yyvsp[0].identifier->name); delete yyvsp[0].identifier; ;
    break;}
case 25:
{ StmtList* list = new StmtList(); list->insert(yyvsp[-1].stmt); list->insert(yyvsp[0].stmtList); yyval.stmtList = list; delete yyvsp[0].stmtList; ;
    break;}
case 26:
{ yyval.stmtList = new StmtList(); ;
    break;}
case 27:
{ yyval.stmt = new NestedStmt(yyvsp[-1].stmtList); ;
    break;}
case 28:
{ yyval.stmt = new IfStmt(yyvsp[-4].exp, yyvsp[-2].stmt, yyvsp[0].stmt); ;
    break;}
case 29:
{ yyval.stmt = new WhileStmt(yyvsp[-2].exp, yyvsp[0].stmt); ;
    break;}
case 30:
{ yyval.stmt = new PrintlnStmt(yyvsp[-2].exp); ;
    break;}
case 31:
{ yyval.stmt = new AssignmentStmt(yyvsp[-3].identifier, yyvsp[-1].exp); ;
    break;}
case 32:
{ yyval.stmt = new ArrayAssignmentStmt(yyvsp[-6].identifier, yyvsp[-4].exp, yyvsp[-1].exp); ;
    break;}
case 33:
{ yyval.stmt = new VarDeclStmt(yyvsp[0].varDecl); ;
    break;}
case 34:
{ ExpList* list = new ExpList(); list->insert(yyvsp[-1].exp); list->insert(yyvsp[0].expList); yyval.expList = list; delete yyvsp[0].expList; ;
    break;}
case 35:
{ yyval.expList = new ExpList(); ;
    break;}
case 36:
{ ExpList* list = new ExpList(); list->insert(yyvsp[-1].exp); list->insert(yyvsp[0].expList); yyval.expList = list; ;
    break;}
case 37:
{ yyval.expList = new ExpList(); ;
    break;}
case 38:
{ yyval.exp = new OrExp(yyvsp[-2].exp, yyvsp[0].exp); ;
    break;}
case 39:
{ yyval.exp = new AndExp(yyvsp[-2].exp, yyvsp[0].exp); ;
    break;}
case 40:
{ yyval.exp = new LessThanExp(yyvsp[-2].exp, yyvsp[0].exp); ;
    break;}
case 41:
{ yyval.exp = new GreaterThanExp(yyvsp[-2].exp, yyvsp[0].exp); ;
    break;}
case 42:
{ yyval.exp = new DifferentExp(yyvsp[-2].exp, yyvsp[0].exp); ;
    break;}
case 43:
{ yyval.exp = new EqualExp(yyvsp[-2].exp, yyvsp[0].exp); ;
    break;}
case 44:
{ yyval.exp = new PlusExp(yyvsp[-2].exp, yyvsp[0].exp); ;
    break;}
case 45:
{ yyval.exp = new MinusExp(yyvsp[-2].exp, yyvsp[0].exp); ;
    break;}
case 46:
{ yyval.exp = new TimesExp(yyvsp[-2].exp, yyvsp[0].exp); ;
    break;}
case 47:
{ yyval.exp = yyvsp[0].exp; ;
    break;}
case 48:
{ yyval.exp = new ArrayValueExp(yyvsp[-3].exp, yyvsp[-1].exp); ;
    break;}
case 49:
{ yyval.exp = new ArrayLengthExp(yyvsp[-2].exp); ;
    break;}
case 50:
{ yyval.exp = new MemberFunctionExp(yyvsp[-5].exp, yyvsp[-3].identifier, yyvsp[-1].expList); ;
    break;}
case 51:
{ yyval.exp = new NumberExp(yyvsp[0].itype); ;
    break;}
case 52:
{ yyval.exp = new TrueExp(); ;
    break;}
case 53:
{ yyval.exp = new FalseExp(); ;
    break;}
case 54:
{ yyval.exp = new IdExp(yyvsp[0].identifier); ;
    break;}
case 55:
{ yyval.exp = new ThisExp(); ;
    break;}
case 56:
{ yyval.exp = new NewIntArrayExp(yyvsp[-1].exp); ;
    break;}
case 57:
{ yyval.exp = new NewIdExp(yyvsp[-2].identifier); ;
    break;}
case 58:
{ yyval.exp = new NotExp(yyvsp[0].exp); ;
    break;}
case 59:
{ yyval.exp = yyvsp[-1].exp; ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */


  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}


int yyerror(char * msg)
{
	printf("Syntax Error: %s at %d\n", msg, yylinenumber);
	return 0;
}
