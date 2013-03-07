%{
#include <cstdio>
#include <string>
#include "ast.h"

extern int yylex();
int yyerror(char * msg);
extern int yylinenumber;
mJ::Program* syntaxResult;
%}

%union {
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

program	: mainclass classdecllist { syntaxResult = new mJ::Program($1, $2); $$ = syntaxResult; }
		;

mainclass	: TClass TMainClass TLBraces mainmethoddecl TRBraces { $$ = new mJ::MainClass($4); }
			;

mainmethoddecl  : TPublic TStatic TVoid TMain TLParen TString TLBracket TRBracket TId TRParen TLBraces stmtlist TRBraces { $$ = new mJ::MainMethodDecl($9, $12); }


methoddecllist	: methoddecl methoddecllist { mJ::MethodList* list = new mJ::MethodList(); list->insert($1); list->insert($2); $$ = list; delete $2; }
				| { $$ = new mJ::MethodList(); }
				;

vardecllist	: /* Blank */
			| vardecl vardecllist { mJ::VarList* list = new mJ::VarList(); list->insert($1); list->insert($2); $$ = list; delete $2; }
			| { $$ = new mJ::VarList(); }
			;

classdecllist	: classdecl classdecllist { mJ::ClassList* list = new mJ::ClassList(); list->insert($1); list->insert($2); $$ = list; delete $2; }
							| { $$ = new mJ::ClassList(); }
							;

classdecl	: TClass TId TLBraces vardecllist methoddecllist TRBraces { $$ = new mJ::NormalClassDecl($2, $4, $5); }
			| TClass TId TExtends TId TLBraces vardecllist methoddecllist TRBraces { $$ = new mJ::ExtendsClassDecl($2, $4, $6, $7); }
			;

vardecl	: type TId TSemiColon { $$ = new mJ::VarDecl($1, $2); }
		;

methoddecl	: TPublic type TId TLParen formallist TRParen TLBraces stmtlist TReturn exp TSemiColon TRBraces { $$ = new mJ::MethodDecl($2, $3, $5, $8, $10); }
			;

formallist	: argument formalrestlist { mJ::ArgumentList* list = new mJ::ArgumentList(); list->insert($1); list->insert($2); $$ = list; delete $2; }
			| { $$ = new mJ::ArgumentList(); }
			;

formalrestlist	: TComma argument formalrestlist { mJ::ArgumentList* list = new mJ::ArgumentList(); list->insert($2); list->insert($3); $$ = list; delete $3; }
				|	{ $$ = new mJ::ArgumentList(); }
				;

argument	: type TId { $$ = new mJ::Argument($1, $2); }
			;

type	: TInteger TLBracket TRBracket { $$ = new mJ::Type("int[]"); }
		| TString  TLBracket TRBracket { $$ = new mJ::Type("String[]"); }
		| TBoolean { $$ = new mJ::Type("bool"); }
		| TInteger { $$ = new mJ::Type("int"); }
		| TId { $$ = new mJ::Type($1->name); delete $1; }
		;

stmtlist	: stmt stmtlist { mJ::StmtList* list = new mJ::StmtList(); list->insert($1); list->insert($2); $$ = list; delete $2; }
			| { $$ = new mJ::StmtList(); }
			;

stmt	: TLBraces stmtlist TRBraces { $$ = new mJ::NestedStmt($2); }
		| TIf TLParen exp TRParen stmt TElse stmt { $$ = new mJ::IfStmt($3, $5, $7); }
		| TWhile TLParen exp TRParen stmt { $$ = new mJ::WhileStmt($3, $5); }
		| TPrintln TLParen exp TRParen TSemiColon { $$ = new mJ::PrintlnStmt($3); }
		| TId TAssignment exp TSemiColon { $$ = new mJ::AssignmentStmt($1, $3); }
		| TId TLBracket exp TRBracket TAssignment exp TSemiColon { $$ = new mJ::ArrayAssignmentStmt($1, $3, $6); }
		| vardecl { $$ = new mJ::VarDeclStmt($1); }
		;

explist	: exp exprestlist { mJ::ExpList* list = new mJ::ExpList(); list->insert($1); list->insert($2); $$ = list; delete $2; }
		| { $$ = new mJ::ExpList(); }
		;

exprestlist	: TComma exp exprestlist { mJ::ExpList* list = new mJ::ExpList(); list->insert($2); list->insert($3); $$ = list; }
			| { $$ = new mJ::ExpList(); }
			;

boolexp	: exp TOr exp { $$ = new mJ::OrExp($1, $3); }
		| exp TAnd exp { $$ = new mJ::AndExp($1, $3); }
		| exp TLessThan exp { $$ = new mJ::LessThanExp($1, $3); }
		| exp TGreaterThan exp { $$ = new mJ::GreaterThanExp($1, $3); }
		| exp TDifferent exp { $$ = new mJ::DifferentExp($1, $3); }
		| exp TEqual exp { $$ = new mJ::EqualExp($1, $3); }
		| exp TPlus exp { $$ = new mJ::PlusExp($1, $3); }
		| exp TMinus exp { $$ = new mJ::MinusExp($1, $3); }
		| exp TTimes exp { $$ = new mJ::TimesExp($1, $3); }
		;

exp	:	boolexp { $$ = $1; }
	| exp TLBracket exp TRBracket { $$ = new mJ::ArrayValueExp($1, $3); }
	| exp TMember TArrayLength { $$ = new mJ::ArrayLengthExp($1); }
	| exp TMember TId TLParen explist TRParen { $$ = new mJ::MemberFunctionExp($1, $3, $5); }
	| TNumber { $$ = new mJ::NumberExp($1); }
	| TTrue { $$ = new mJ::TrueExp(); }
	| TFalse { $$ = new mJ::FalseExp(); }
	| TId { $$ = new mJ::IdExp($1); }
	| TThis { $$ = new mJ::ThisExp(); }
	| TNew TInteger TLBracket exp TRBracket { $$ = new mJ::NewIntArrayExp($4); }
	| TNew TId TLParen TRParen { $$ = new mJ::NewIdExp($2); }
	| TNot exp { $$ = new mJ::NotExp($2); }
	| TLParen exp TRParen { $$ = $2; }
	;
%%

int yyerror(char * msg)
{
	printf("Syntax Error: %s at %d\n", msg, yylinenumber);
	return 0;
}