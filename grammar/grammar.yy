%{
#include <cstdio>
#include <string>
#include "ast.h"

extern int yylex();
int yyerror(char * msg);
extern int yylinenumber;
Program* syntaxResult;
%}

%union {
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
}

%token TIf
%token TElse
%token TWhile
%token TClass
%token TExtends
%token TPublic
%token TStatic
%token TVoid
%token TMain
%token TMainClass
%token TBoolean
%token TInteger
%token TString
%token TTrue
%token TFalse
%token TThis
%token TNew
%token TPrintln
%token TReturn
%token TArrayLength

%token <identifier> TId
%token <itype> TNumber
%token <stype> TText

%token TAssignment
%token TNot
%token TAnd
%token TOr
%token TLessThan
%token TGreaterThan
%token TDifferent
%token TEqual
%token TPlus
%token TMinus
%token TTimes
%token TMember

%token TLParen
%token TRParen
%token TLBracket
%token TRBracket
%token TLBraces
%token TRBraces
%token TComma
%token TSemiColon

%left TOr TAnd
%left TLessThan TGreaterThan
%left TDifferent TEqual
%left TPlus TMinus
%left TTimes

%start program

%type <expList>	explist
%type <expList>	exprestlist
%type <classList> classdecllist
%type <varList> vardecllist
%type <methodList> methoddecllist
%type <argumentList> formallist
%type <argumentList> formalrestlist
%type <stmtList> stmtlist

%type <program> program
%type <mainClass> mainclass
%type <classDecl> classdecl
%type <varDecl> vardecl
%type <methodDecl> methoddecl
%type <mainMethodDecl> mainmethoddecl
%type <stmt>	stmt
%type <exp> boolexp
%type <exp>	exp
%type <argument>	argument
%type <type> type

%%

program	: mainclass classdecllist { syntaxResult = new Program($1, $2); $$ = syntaxResult; }
		;

mainclass	: TClass TMainClass TLBraces mainmethoddecl TRBraces { $$ = new MainClass($4); }
			;

mainmethoddecl  : TPublic TStatic TVoid TMain TLParen TString TLBracket TRBracket TId TRParen TLBraces stmtlist TRBraces { $$ = new MainMethodDecl($9, $12); }


methoddecllist	: methoddecl methoddecllist { MethodList* list = new MethodList(); list->insert($1); list->insert($2); $$ = list; delete $2; }
				| { $$ = new MethodList(); }
				;

vardecllist	: /* Blank */
			| vardecl vardecllist { VarList* list = new VarList(); list->insert($1); list->insert($2); $$ = list; delete $2; }
			| { $$ = new VarList(); }
			;

classdecllist	: classdecl classdecllist { ClassList* list = new ClassList(); list->insert($1); list->insert($2); $$ = list; delete $2; }
							| { $$ = new ClassList(); }
							;

classdecl	: TClass TId TLBraces vardecllist methoddecllist TRBraces { $$ = new NormalClassDecl($2, $4, $5); }
			| TClass TId TExtends TId TLBraces vardecllist methoddecllist TRBraces { $$ = new ExtendsClassDecl($2, $4, $6, $7); }
			;

vardecl	: type TId TSemiColon { $$ = new VarDecl($1, $2); }
		;

methoddecl	: TPublic type TId TLParen formallist TRParen TLBraces stmtlist TReturn exp TSemiColon TRBraces { $$ = new MethodDecl($2, $3, $5, $8, $10); }
			;

formallist	: argument formalrestlist { ArgumentList* list = new ArgumentList(); list->insert($1); list->insert($2); $$ = list; delete $2; }
			| { $$ = new ArgumentList(); }
			;

formalrestlist	: TComma argument formalrestlist { ArgumentList* list = new ArgumentList(); list->insert($2); list->insert($3); $$ = list; delete $3; }
				|	{ $$ = new ArgumentList(); }
				;

argument	: type TId { $$ = new Argument($1, $2); }
			;

type	: TInteger TLBracket TRBracket { $$ = new Type("int[]"); }
		| TString  TLBracket TRBracket { $$ = new Type("String[]"); }
		| TBoolean { $$ = new Type("bool"); }
		| TInteger { $$ = new Type("int"); }
		| TId { $$ = new Type($1->name); delete $1; }
		;

stmtlist	: stmt stmtlist { StmtList* list = new StmtList(); list->insert($1); list->insert($2); $$ = list; delete $2; }
			| { $$ = new StmtList(); }
			;

stmt	: TLBraces stmtlist TRBraces { $$ = new NestedStmt($2); }
		| TIf TLParen exp TRParen stmt TElse stmt { $$ = new IfStmt($3, $5, $7); }
		| TWhile TLParen exp TRParen stmt { $$ = new WhileStmt($3, $5); }
		| TPrintln TLParen exp TRParen TSemiColon { $$ = new PrintlnStmt($3); }
		| TId TAssignment exp TSemiColon { $$ = new AssignmentStmt($1, $3); }
		| TId TLBracket exp TRBracket TAssignment exp TSemiColon { $$ = new ArrayAssignmentStmt($1, $3, $6); }
		| vardecl { $$ = new VarDeclStmt($1); }
		;

explist	: exp exprestlist { ExpList* list = new ExpList(); list->insert($1); list->insert($2); $$ = list; delete $2; }
		| { $$ = new ExpList(); }
		;

exprestlist	: TComma exp exprestlist { ExpList* list = new ExpList(); list->insert($2); list->insert($3); $$ = list; }
			| { $$ = new ExpList(); }
			;

boolexp	: exp TOr exp { $$ = new OrExp($1, $3); }
		| exp TAnd exp { $$ = new AndExp($1, $3); }
		| exp TLessThan exp { $$ = new LessThanExp($1, $3); }
		| exp TGreaterThan exp { $$ = new GreaterThanExp($1, $3); }
		| exp TDifferent exp { $$ = new DifferentExp($1, $3); }
		| exp TEqual exp { $$ = new EqualExp($1, $3); }
		| exp TPlus exp { $$ = new PlusExp($1, $3); }
		| exp TMinus exp { $$ = new MinusExp($1, $3); }
		| exp TTimes exp { $$ = new TimesExp($1, $3); }
		;

exp	:	boolexp { $$ = $1; }
	| exp TLBracket exp TRBracket { $$ = new ArrayValueExp($1, $3); }
	| exp TMember TArrayLength { $$ = new ArrayLengthExp($1); }
	| exp TMember TId TLParen explist TRParen { $$ = new MemberFunctionExp($1, $3, $5); }
	| TNumber { $$ = new NumberExp($1); }
	| TTrue { $$ = new TrueExp(); }
	| TFalse { $$ = new FalseExp(); }
	| TId { $$ = new IdExp($1); }
	| TThis { $$ = new ThisExp(); }
	| TNew TInteger TLBracket exp TRBracket { $$ = new NewIntArrayExp($4); }
	| TNew TId TLParen TRParen { $$ = new NewIdExp($2); }
	| TNot exp { $$ = new NotExp($2); }
	| TLParen exp TRParen { $$ = $2; }
	;
%%

int yyerror(char * msg)
{
	printf("Syntax Error: %s at %d\n", msg, yylinenumber);
	return 0;
}
