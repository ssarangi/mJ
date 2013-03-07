typedef union {
	int itype;
	char* stype;

	mJ::Type* type;
	
	mJ::ExpList* expList;
	mJ::ClassList* classList;
	mJ::VarList* varList;
	mJ::MethodList* methodList;
	mJ::ArgumentList* argumentList;
	mJ::StmtList* stmtList;

	mJ::Program* program;
	mJ::MainClass* mainClass;
	mJ::ClassDecl* classDecl;
	mJ::VarDecl* varDecl;
	mJ::MethodDecl* methodDecl;
	mJ::MainMethodDecl* mainMethodDecl;
	mJ::Stmt* stmt;
	mJ::Exp* exp;
	mJ::Argument* argument;

	mJ::Identifier* identifier;
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


extern YYSTYPE yylval;
