
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
#define	TBoolean	267
#define	TInteger	268
#define	TString	269
#define	TTrue	270
#define	TFalse	271
#define	TThis	272
#define	TNew	273
#define	TPrintln	274
#define	TReturn	275
#define	TArrayLength	276
#define	TId	277
#define	TNumber	278
#define	TText	279
#define	TAssignment	280
#define	TNot	281
#define	TAnd	282
#define	TOr	283
#define	TLessThan	284
#define	TGreaterThan	285
#define	TDifferent	286
#define	TEqual	287
#define	TPlus	288
#define	TMinus	289
#define	TTimes	290
#define	TMember	291
#define	TLParen	292
#define	TRParen	293
#define	TLBracket	294
#define	TRBracket	295
#define	TLBraces	296
#define	TRBraces	297
#define	TComma	298
#define	TSemiColon	299


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



#define	YYFINAL		151
#define	YYFLAG		-32768
#define	YYNTBASE	45

#define YYTRANSLATE(x) ((unsigned)(x) <= 299 ? yytranslate[x] : 63)

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
    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     3,    21,    24,    25,    32,    41,    44,    45,    49,
    52,    53,    66,    69,    70,    74,    75,    78,    82,    84,
    86,    88,    91,    92,    96,   104,   110,   116,   121,   129,
   131,   134,   135,   139,   140,   144,   148,   152,   156,   160,
   164,   168,   172,   176,   178,   183,   187,   194,   196,   198,
   200,   202,   204,   210,   215,   218
};

static const short yyrhs[] = {    46,
    47,     0,     6,    22,    41,     8,     9,    10,    11,    37,
    14,    39,    40,    22,    38,    41,    57,    42,    42,     0,
    48,    47,     0,     0,     6,    22,    41,    49,    51,    42,
     0,     6,    22,     7,    22,    41,    49,    51,    42,     0,
    50,    49,     0,     0,    56,    22,    44,     0,    52,    51,
     0,     0,     8,    56,    22,    37,    53,    38,    41,    57,
    20,    62,    44,    42,     0,    55,    54,     0,     0,    43,
    55,    54,     0,     0,    56,    22,     0,    13,    39,    40,
     0,    12,     0,    13,     0,    22,     0,    58,    57,     0,
     0,    41,    57,    42,     0,     3,    37,    62,    38,    58,
     4,    58,     0,     5,    37,    62,    38,    58,     0,    19,
    37,    62,    38,    44,     0,    22,    25,    62,    44,     0,
    22,    39,    62,    40,    25,    62,    44,     0,    50,     0,
    62,    60,     0,     0,    43,    62,    60,     0,     0,    62,
    28,    62,     0,    62,    27,    62,     0,    62,    29,    62,
     0,    62,    30,    62,     0,    62,    31,    62,     0,    62,
    32,    62,     0,    62,    33,    62,     0,    62,    34,    62,
     0,    62,    35,    62,     0,    61,     0,    62,    39,    62,
    40,     0,    62,    36,    21,     0,    62,    36,    22,    37,
    59,    38,     0,    23,     0,    15,     0,    16,     0,    22,
     0,    17,     0,    18,    13,    39,    62,    40,     0,    18,
    22,    37,    38,     0,    26,    62,     0,    37,    62,    38,
     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   113,   116,   119,   120,   123,   124,   127,   128,   131,   134,
   135,   138,   141,   142,   145,   146,   149,   152,   153,   154,
   155,   158,   159,   162,   163,   164,   165,   166,   167,   168,
   171,   172,   175,   176,   179,   180,   181,   182,   183,   184,
   185,   186,   187,   190,   191,   192,   193,   194,   195,   196,
   197,   198,   199,   200,   201,   202
};

static const char * const yytname[] = {   "$","error","$undefined.","TIf","TElse",
"TWhile","TClass","TExtends","TPublic","TStatic","TVoid","TMain","TBoolean",
"TInteger","TString","TTrue","TFalse","TThis","TNew","TPrintln","TReturn","TArrayLength",
"TId","TNumber","TText","TAssignment","TNot","TAnd","TOr","TLessThan","TGreaterThan",
"TDifferent","TEqual","TPlus","TMinus","TTimes","TMember","TLParen","TRParen",
"TLBracket","TRBracket","TLBraces","TRBraces","TComma","TSemiColon","program",
"mainclass","classdecllist","classdecl","vardecllist","vardecl","methoddecllist",
"methoddecl","formallist","formalrestlist","argument","type","stmtlist","stmt",
"explist","exprestlist","boolexp","exp",""
};
#endif

static const short yyr1[] = {     0,
    45,    46,    47,    47,    48,    48,    49,    49,    50,    51,
    51,    52,    53,    53,    54,    54,    55,    56,    56,    56,
    56,    57,    57,    58,    58,    58,    58,    58,    58,    58,
    59,    59,    60,    60,    61,    61,    61,    61,    61,    61,
    61,    61,    61,    62,    62,    62,    62,    62,    62,    62,
    62,    62,    62,    62,    62,    62
};

static const short yyr2[] = {     0,
     2,    17,     2,     0,     6,     8,     2,     0,     3,     2,
     0,    12,     2,     0,     3,     0,     2,     3,     1,     1,
     1,     2,     0,     3,     7,     5,     5,     4,     7,     1,
     2,     0,     3,     0,     3,     3,     3,     3,     3,     3,
     3,     3,     3,     1,     4,     3,     6,     1,     1,     1,
     1,     1,     5,     4,     2,     3
};

static const short yydefact[] = {     0,
     0,     4,     0,     0,     1,     4,     0,     0,     3,     0,
     0,     8,     0,     0,    19,    20,    21,    11,     8,     0,
     0,     8,     0,     0,     0,    11,     7,     0,     0,    11,
    18,     0,     5,    10,     9,     0,     0,     0,     0,     6,
    14,     0,     0,    16,     0,     0,     0,     0,    13,    17,
     0,    23,    16,     0,     0,     0,     0,    21,    23,    30,
     0,    23,    15,    23,     0,     0,     0,     0,     0,     0,
     0,    22,     0,    49,    50,    52,     0,    51,    48,     0,
     0,    44,     0,     0,     0,     0,     0,    24,     0,     0,
     0,     0,    55,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    28,     0,
     0,     2,     0,     0,    56,    36,    35,    37,    38,    39,
    40,    41,    42,    43,    46,     0,     0,     0,    26,    27,
     0,    12,     0,    54,    32,     0,    45,     0,    53,     0,
    34,    25,    29,    47,     0,    31,    34,    33,     0,     0,
     0
};

static const short yydefgoto[] = {   149,
     2,     5,     6,    18,    60,    25,    26,    43,    49,    44,
    20,    61,    62,   140,   146,    82,    83
};

static const short yypact[] = {    21,
    -9,    48,    17,    44,-32768,    48,    60,    -3,-32768,    63,
    54,    -1,    68,    52,-32768,    56,-32768,    86,    -1,    74,
    97,    -1,    72,    -1,    67,    86,-32768,    70,    76,    86,
-32768,   104,-32768,-32768,-32768,   113,    87,    93,    92,-32768,
    -1,   105,    73,   101,   110,   125,   108,    -1,-32768,-32768,
   123,     4,   101,   121,   111,   139,   153,   -19,     4,-32768,
   155,     4,-32768,     4,    34,    34,    34,    34,    34,   147,
    34,-32768,   161,-32768,-32768,-32768,    31,-32768,-32768,    34,
    34,-32768,   166,   179,   192,    53,   124,-32768,    71,   174,
   190,   219,   218,   205,    34,    34,    34,    34,    34,    34,
    34,    34,    34,    69,     4,    34,     4,   198,-32768,   230,
   224,-32768,    34,   237,-32768,   229,   229,   238,   238,    28,
    28,     7,     7,   -17,-32768,   239,   263,   138,-32768,-32768,
    34,-32768,   152,-32768,    34,     4,-32768,    89,-32768,   240,
   107,-32768,-32768,-32768,    34,-32768,   107,-32768,   279,   280,
-32768
};

static const short yypgoto[] = {-32768,
-32768,   275,-32768,    55,     6,    29,-32768,-32768,   231,   234,
     0,    11,   -97,-32768,   136,-32768,   -66
};


#define	YYLAST		284


static const short yytable[] = {    84,
    85,    86,    87,    11,    89,    68,    55,   127,    56,   129,
    15,    16,     3,    93,    94,    15,    16,    19,   104,    69,
    17,   106,    57,    32,    19,    58,     1,    19,   116,   117,
   118,   119,   120,   121,   122,   123,   124,    12,   142,   128,
    45,   103,   104,    91,    59,   106,   133,    45,    74,    75,
    76,    77,    92,     4,    34,    78,    79,     7,    37,    80,
   101,   102,   103,   104,   138,     8,   106,    10,   141,    70,
    81,    13,    72,    27,    73,    14,    30,    21,   147,    95,
    96,    97,    98,    99,   100,   101,   102,   103,   104,   125,
   126,   106,    22,    24,    23,    28,   109,    95,    96,    97,
    98,    99,   100,   101,   102,   103,   104,    29,    33,   106,
    47,    31,    36,    35,   111,    95,    96,    97,    98,    99,
   100,   101,   102,   103,   104,    38,    39,   106,    40,    41,
    42,    50,   143,    95,    96,    97,    98,    99,   100,   101,
   102,   103,   104,    48,    46,   106,    51,    65,    52,   145,
    95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
    54,    64,   106,   110,    95,    96,    97,    98,    99,   100,
   101,   102,   103,   104,    71,    66,   106,   137,    95,    96,
    97,    98,    99,   100,   101,   102,   103,   104,    88,    67,
   106,   139,    95,    96,    97,    98,    99,   100,   101,   102,
   103,   104,    90,   105,   106,    95,    96,    97,    98,    99,
   100,   101,   102,   103,   104,   112,   107,   106,    95,    96,
    97,    98,    99,   100,   101,   102,   103,   104,   113,   108,
   106,    95,    96,    97,    98,    99,   100,   101,   102,   103,
   104,   130,   115,   106,    95,    96,    97,    98,    99,   100,
   101,   102,   103,   104,   131,   114,   106,    97,    98,    99,
   100,   101,   102,   103,   104,   132,   136,   106,    99,   100,
   101,   102,   103,   104,   134,   135,   106,   144,   150,   151,
     9,    53,   148,    63
};

static const short yycheck[] = {    66,
    67,    68,    69,     7,    71,    25,     3,   105,     5,   107,
    12,    13,    22,    80,    81,    12,    13,    12,    36,    39,
    22,    39,    19,    24,    19,    22,     6,    22,    95,    96,
    97,    98,    99,   100,   101,   102,   103,    41,   136,   106,
    41,    35,    36,    13,    41,    39,   113,    48,    15,    16,
    17,    18,    22,     6,    26,    22,    23,    41,    30,    26,
    33,    34,    35,    36,   131,    22,    39,     8,   135,    59,
    37,     9,    62,    19,    64,    22,    22,    10,   145,    27,
    28,    29,    30,    31,    32,    33,    34,    35,    36,    21,
    22,    39,    41,     8,    39,    22,    44,    27,    28,    29,
    30,    31,    32,    33,    34,    35,    36,    11,    42,    39,
    38,    40,    37,    44,    44,    27,    28,    29,    30,    31,
    32,    33,    34,    35,    36,    22,    14,    39,    42,    37,
    39,    22,    44,    27,    28,    29,    30,    31,    32,    33,
    34,    35,    36,    43,    40,    39,    22,    37,    41,    43,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    38,    41,    39,    40,    27,    28,    29,    30,    31,    32,
    33,    34,    35,    36,    20,    37,    39,    40,    27,    28,
    29,    30,    31,    32,    33,    34,    35,    36,    42,    37,
    39,    40,    27,    28,    29,    30,    31,    32,    33,    34,
    35,    36,    42,    38,    39,    27,    28,    29,    30,    31,
    32,    33,    34,    35,    36,    42,    38,    39,    27,    28,
    29,    30,    31,    32,    33,    34,    35,    36,    39,    38,
    39,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    44,    38,    39,    27,    28,    29,    30,    31,    32,
    33,    34,    35,    36,    25,    37,    39,    29,    30,    31,
    32,    33,    34,    35,    36,    42,     4,    39,    31,    32,
    33,    34,    35,    36,    38,    37,    39,    38,     0,     0,
     6,    48,   147,    53
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
{ yyval.mainClass = new MainClass(yyvsp[-15].identifier, yyvsp[-5].identifier, yyvsp[-2].stmtList); ;
    break;}
case 3:
{ ClassList* list = new ClassList(); list->insert(yyvsp[-1].classDecl); list->insert(yyvsp[0].classList); yyval.classList = list; delete yyvsp[0].classList; ;
    break;}
case 4:
{ yyval.classList = new ClassList(); ;
    break;}
case 5:
{ yyval.classDecl = new NormalClassDecl(yyvsp[-4].identifier, yyvsp[-2].varList, yyvsp[-1].methodList); ;
    break;}
case 6:
{ yyval.classDecl = new ExtendsClassDecl(yyvsp[-6].identifier, yyvsp[-4].identifier, yyvsp[-2].varList, yyvsp[-1].methodList); ;
    break;}
case 7:
{ VarList* list = new VarList(); list->insert(yyvsp[-1].varDecl); list->insert(yyvsp[0].varList); yyval.varList = list; delete yyvsp[0].varList; ;
    break;}
case 8:
{ yyval.varList = new VarList(); ;
    break;}
case 9:
{ yyval.varDecl = new VarDecl(yyvsp[-2].type, yyvsp[-1].identifier); ;
    break;}
case 10:
{ MethodList* list = new MethodList(); list->insert(yyvsp[-1].methodDecl); list->insert(yyvsp[0].methodList); yyval.methodList = list; delete yyvsp[0].methodList; ;
    break;}
case 11:
{ yyval.methodList = new MethodList(); ;
    break;}
case 12:
{ yyval.methodDecl = new MethodDecl(yyvsp[-10].type, yyvsp[-9].identifier, yyvsp[-7].argumentList, yyvsp[-4].stmtList, yyvsp[-2].exp); ;
    break;}
case 13:
{ ArgumentList* list = new ArgumentList(); list->insert(yyvsp[-1].argument); list->insert(yyvsp[0].argumentList); yyval.argumentList = list; delete yyvsp[0].argumentList; ;
    break;}
case 14:
{ yyval.argumentList = new ArgumentList(); ;
    break;}
case 15:
{ ArgumentList* list = new ArgumentList(); list->insert(yyvsp[-1].argument); list->insert(yyvsp[0].argumentList); yyval.argumentList = list; delete yyvsp[0].argumentList; ;
    break;}
case 16:
{ yyval.argumentList = new ArgumentList(); ;
    break;}
case 17:
{ yyval.argument = new Argument(yyvsp[-1].type, yyvsp[0].identifier); ;
    break;}
case 18:
{ yyval.type = new Type("int[]"); ;
    break;}
case 19:
{ yyval.type = new Type("bool"); ;
    break;}
case 20:
{ yyval.type = new Type("int"); ;
    break;}
case 21:
{ yyval.type = new Type(yyvsp[0].identifier->name); delete yyvsp[0].identifier; ;
    break;}
case 22:
{ StmtList* list = new StmtList(); list->insert(yyvsp[-1].stmt); list->insert(yyvsp[0].stmtList); yyval.stmtList = list; delete yyvsp[0].stmtList; ;
    break;}
case 23:
{ yyval.stmtList = new StmtList(); ;
    break;}
case 24:
{ yyval.stmt = new NestedStmt(yyvsp[-1].stmtList); ;
    break;}
case 25:
{ yyval.stmt = new IfStmt(yyvsp[-4].exp, yyvsp[-2].stmt, yyvsp[0].stmt); ;
    break;}
case 26:
{ yyval.stmt = new WhileStmt(yyvsp[-2].exp, yyvsp[0].stmt); ;
    break;}
case 27:
{ yyval.stmt = new PrintlnStmt(yyvsp[-2].exp); ;
    break;}
case 28:
{ yyval.stmt = new AssignmentStmt(yyvsp[-3].identifier, yyvsp[-1].exp); ;
    break;}
case 29:
{ yyval.stmt = new ArrayAssignmentStmt(yyvsp[-6].identifier, yyvsp[-4].exp, yyvsp[-1].exp); ;
    break;}
case 30:
{ yyval.stmt = new VarDeclStmt(yyvsp[0].varDecl); ;
    break;}
case 31:
{ ExpList* list = new ExpList(); list->insert(yyvsp[-1].exp); list->insert(yyvsp[0].expList); yyval.expList = list; delete yyvsp[0].expList; ;
    break;}
case 32:
{ yyval.expList = new ExpList(); ;
    break;}
case 33:
{ ExpList* list = new ExpList(); list->insert(yyvsp[-1].exp); list->insert(yyvsp[0].expList); yyval.expList = list; ;
    break;}
case 34:
{ yyval.expList = new ExpList(); ;
    break;}
case 35:
{ yyval.exp = new OrExp(yyvsp[-2].exp, yyvsp[0].exp); ;
    break;}
case 36:
{ yyval.exp = new AndExp(yyvsp[-2].exp, yyvsp[0].exp); ;
    break;}
case 37:
{ yyval.exp = new LessThanExp(yyvsp[-2].exp, yyvsp[0].exp); ;
    break;}
case 38:
{ yyval.exp = new GreaterThanExp(yyvsp[-2].exp, yyvsp[0].exp); ;
    break;}
case 39:
{ yyval.exp = new DifferentExp(yyvsp[-2].exp, yyvsp[0].exp); ;
    break;}
case 40:
{ yyval.exp = new EqualExp(yyvsp[-2].exp, yyvsp[0].exp); ;
    break;}
case 41:
{ yyval.exp = new PlusExp(yyvsp[-2].exp, yyvsp[0].exp); ;
    break;}
case 42:
{ yyval.exp = new MinusExp(yyvsp[-2].exp, yyvsp[0].exp); ;
    break;}
case 43:
{ yyval.exp = new TimesExp(yyvsp[-2].exp, yyvsp[0].exp); ;
    break;}
case 44:
{ yyval.exp = yyvsp[0].exp; ;
    break;}
case 45:
{ yyval.exp = new ArrayValueExp(yyvsp[-3].exp, yyvsp[-1].exp); ;
    break;}
case 46:
{ yyval.exp = new ArrayLengthExp(yyvsp[-2].exp); ;
    break;}
case 47:
{ yyval.exp = new MemberFunctionExp(yyvsp[-5].exp, yyvsp[-3].identifier, yyvsp[-1].expList); ;
    break;}
case 48:
{ yyval.exp = new NumberExp(yyvsp[0].itype); ;
    break;}
case 49:
{ yyval.exp = new TrueExp(); ;
    break;}
case 50:
{ yyval.exp = new FalseExp(); ;
    break;}
case 51:
{ yyval.exp = new IdExp(yyvsp[0].identifier); ;
    break;}
case 52:
{ yyval.exp = new ThisExp(); ;
    break;}
case 53:
{ yyval.exp = new NewIntArrayExp(yyvsp[-1].exp); ;
    break;}
case 54:
{ yyval.exp = new NewIdExp(yyvsp[-2].identifier); ;
    break;}
case 55:
{ yyval.exp = new NotExp(yyvsp[0].exp); ;
    break;}
case 56:
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
