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


extern YYSTYPE yylval;
