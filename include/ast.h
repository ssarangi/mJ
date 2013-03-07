#ifndef __AST_H__
#define __AST_H__

#include "visitor.h"
#include "identifier.h"

#include <string>
#include <vector>
#include <memory>

namespace mJ
{

//List structures
struct ExpList;
struct ClassList;
struct VarList;
struct MethodList;
struct ArgumentList;
struct StmtList;

//Virtual structures
struct ClassDecl;
struct Stmt;
struct Exp;

//Non-virtual structures
struct Type;

struct Program;
struct MainClass;

struct NormalClassDecl;
struct ExtendsClassDecl;

struct VarDecl;

struct MethodDecl;

struct Argument;

struct NestedStmt;
struct IfStmt;
struct WhileStmt;
struct PrintlnStmt;
struct AssignmentStmt;
struct ArrayAssignmentStmt;
struct VarDeclStmt;

struct OrExp;
struct AndExp;
struct LessThanExp;
struct GreaterThanExp;
struct DifferentExp;
struct EqualExp;
struct PlusExp;
struct MinusExp;
struct TimesExp;

struct ArrayValueExp;
struct ArrayLengthExp;
struct MemberFunctionExp;
struct NewIntArrayExp;
struct NewIdExp;
struct NotExp;

struct NumberExp;
struct TrueExp;
struct FalseExp;
struct IdExp;
struct ThisExp;

enum ClassDeclType
{
    MainClassType,
    NormalClassType,
    ExtendsClassType
};

enum StmtType 
{
    NestedType,
    IfType,
    WhileType,
    PrintlnType,
    AssignmentType,
    ArrayAssignmentType,
    VarDeclType
};

enum ExpType 
{
    OrType,
    AndType,
    LessThanType,
    GreaterThanType,
    DifferentType,
    EqualType,
    PlusType,
    MinusType,
    TimesType,
    ArrayValueType,
    ArrayLengthType,
    MemberFunctionType,
    NewIntArrayType,
    NewIdType,
    NotType,
    NumberType,
    TrueType,
    FalseType,
    IdType,
    ThisType
};

struct ExpList 
{
    ExpList();
    void insert(Exp* exp);
    void insert(ExpList* expList);
    
    std::vector<std::shared_ptr<Exp> > exps;
};

struct ClassList 
{
    ClassList();
    void insert(ClassDecl* classDecl);
    void insert(ClassList* classList);

    std::vector<std::shared_ptr<ClassDecl> > classDecls;
};

struct VarList 
{
    VarList();
    void insert(VarDecl* varDecl);
    void insert(VarList* varList);

    std::vector<std::shared_ptr<VarDecl> > varDecls;
};

struct MethodList
{
    MethodList();
    void insert(MethodDecl* methodDecl);
    void insert(MethodList* methodList);

    std::vector<std::shared_ptr<MethodDecl> > methodDecls;
};

struct ArgumentList 
{
    ArgumentList();
    void insert(Argument* argument);
    void insert(ArgumentList* argumentList);

    std::vector<std::shared_ptr<Argument> > arguments;
};

struct StmtList 
{
    StmtList();
    void insert(Stmt* stmt);
    void insert(StmtList* stmtList);

    std::vector<std::shared_ptr<Stmt> > stmts;
};

struct ClassDecl 
{
    ClassDecl(Identifier* classId, VarList* varList, MethodList* methodList);
    virtual ClassDeclType getType() = 0;

    std::shared_ptr<Identifier> classId;
    std::shared_ptr<VarList>    varList;
    std::shared_ptr<MethodList> methodList;
};

struct Stmt 
{
    Stmt();
    virtual StmtType getType() = 0;
};

struct Exp 
{
    Exp();
    virtual ExpType getType() = 0;
};

struct Type 
{
    Type(std::string name);

    std::string name;
};

struct Program 
{
    Program(MainClass* mainClass, ClassList* classList);
    
    std::shared_ptr<MainClass> mainClass;
    std::shared_ptr<ClassList> classList;
};

struct MainMethodDecl;

struct MainClass : public ClassDecl
{
    MainClass(MainMethodDecl* mainMethod);

    std::shared_ptr<Identifier> classId;
    std::shared_ptr<Identifier> stringArrayId;
    std::shared_ptr<StmtList>   stmtList;

    virtual ClassDeclType getType() { return NormalClassType; }
};

struct NormalClassDecl : public ClassDecl 
{
    NormalClassDecl(Identifier* classId, VarList* varList, MethodList* methodList);
    ClassDeclType getType() { return NormalClassType; }
};

struct ExtendsClassDecl : public ClassDecl 
{
    ExtendsClassDecl(Identifier* classId, Identifier* classExtendsId, VarList* varList, MethodList* methodList);
    ClassDeclType getType() { return ExtendsClassType; }

    std::shared_ptr<Identifier> classExtendsId;
};

struct VarDecl 
{
    VarDecl(Type* type, Identifier* id);

    std::shared_ptr<Type>       type;
    std::shared_ptr<Identifier> id;
};

struct MethodDecl 
{
    MethodDecl(Type* type, Identifier* id, ArgumentList* argumentList, StmtList* stmtList, Exp* exp);

    std::shared_ptr<Type>         type;
    std::shared_ptr<Identifier>   id;
    std::shared_ptr<ArgumentList> argumentList;
    std::shared_ptr<StmtList>     stmtList;
    std::shared_ptr<Exp>          exp;
};

struct MainMethodDecl : public MethodDecl
{
    MainMethodDecl(Identifier* argIdentifier, StmtList* stmtList);
};

struct Argument 
{
    Argument(Type* type, Identifier* id);

    std::shared_ptr<Type>        type;
    std::shared_ptr<Identifier> id;
};

struct NestedStmt : public Stmt 
{
    NestedStmt(StmtList* stmtList);
    StmtType getType() { return NestedType; }

    std::shared_ptr<StmtList> stmtList;
};

struct IfStmt : public Stmt 
{
    IfStmt(Exp* exp, Stmt* ifStmt, Stmt* elseStmt);
    StmtType getType() { return IfType; }

    std::shared_ptr<Exp>  exp;
    std::shared_ptr<Stmt> ifStmt;
    std::shared_ptr<Stmt> elseStmt;
};

struct WhileStmt : public Stmt 
{
    WhileStmt(Exp* exp, Stmt* stmt);	
    StmtType getType() { return WhileType; }

    std::shared_ptr<Exp>  exp;
    std::shared_ptr<Stmt> stmt;
};

struct PrintlnStmt : public Stmt 
{
    PrintlnStmt(Exp* exp);
    StmtType getType() { return PrintlnType; }

    std::shared_ptr<Exp> exp;
};

struct AssignmentStmt : public Stmt 
{
    AssignmentStmt(Identifier* id, Exp* exp);
    StmtType getType() { return AssignmentType; }

    std::shared_ptr<Identifier> id;
    std::shared_ptr<Exp>        exp;
};

struct ArrayAssignmentStmt : public Stmt 
{
    ArrayAssignmentStmt(Identifier* id, Exp* exp, Exp* assignmentExp);
    StmtType getType() { return ArrayAssignmentType; }

    std::shared_ptr<Identifier> id;
    std::shared_ptr<Exp>        exp;
    std::shared_ptr<Exp>        assignmentExp;
};

struct VarDeclStmt : public Stmt 
{
    VarDeclStmt(VarDecl* varDecl);
    StmtType getType() { return VarDeclType; }

    std::shared_ptr<VarDecl> varDecl;
};

struct OrExp : public Exp 
{
    OrExp(Exp* exp1, Exp* exp2);
    ExpType getType() { return OrType; }

    std::shared_ptr<Exp> exp1;
    std::shared_ptr<Exp> exp2;
};

struct AndExp : public Exp 
{
    AndExp(Exp* exp1, Exp* exp2);
    ExpType getType() { return AndType; }

    std::shared_ptr<Exp> exp1;
    std::shared_ptr<Exp> exp2;
};

struct LessThanExp : public Exp 
{
    LessThanExp(Exp* exp1, Exp* exp2);
    ExpType getType() { return LessThanType; }

    std::shared_ptr<Exp> exp1;
    std::shared_ptr<Exp> exp2;
};

struct GreaterThanExp : public Exp 
{
    GreaterThanExp(Exp* exp1, Exp* exp2);
    ExpType getType() { return GreaterThanType; }

    std::shared_ptr<Exp> exp1;
    std::shared_ptr<Exp> exp2;
};

struct DifferentExp : public Exp 
{
    DifferentExp(Exp* exp1, Exp* exp2);
    ExpType getType() { return DifferentType; }

    std::shared_ptr<Exp> exp1;
    std::shared_ptr<Exp> exp2;
};

struct EqualExp : public Exp 
{
    EqualExp(Exp* exp1, Exp* exp2);
    ExpType getType() { return EqualType; }

    std::shared_ptr<Exp> exp1;
    std::shared_ptr<Exp> exp2;
};

struct PlusExp : public Exp 
{
    PlusExp(Exp* exp1, Exp* exp2);
    ExpType getType() { return PlusType; }

    std::shared_ptr<Exp> exp1;
    std::shared_ptr<Exp> exp2;
};

struct MinusExp : public Exp 
{
    MinusExp(Exp* exp1, Exp* exp2);
    ExpType getType() { return MinusType; }

    std::shared_ptr<Exp> exp1;
    std::shared_ptr<Exp> exp2;
};

struct TimesExp : public Exp 
{
    TimesExp(Exp* exp1, Exp* exp2);
    ExpType getType() { return TimesType; }

    std::shared_ptr<Exp> exp1;
    std::shared_ptr<Exp> exp2;
};

struct ArrayValueExp : public Exp 
{
    ArrayValueExp(Exp* exp1, Exp* exp2);
    ExpType getType() { return ArrayValueType; }
    
    std::shared_ptr<Exp> exp1;
    std::shared_ptr<Exp> exp2;
};

struct ArrayLengthExp : public Exp 
{
    ArrayLengthExp(Exp* exp);
    ExpType getType() { return ArrayLengthType; }

    std::shared_ptr<Exp> exp;
};

struct MemberFunctionExp : public Exp 
{
    MemberFunctionExp(Exp* exp, Identifier* id, ExpList* list);
    ExpType getType() { return MemberFunctionType; }

    std::shared_ptr<Exp>        exp;
    std::shared_ptr<Identifier> id;
    std::shared_ptr<ExpList>    list;
};

struct NewIntArrayExp : public Exp 
{
    NewIntArrayExp(Exp* exp);
    ExpType getType() { return NewIntArrayType; }

    std::shared_ptr<Exp> exp;
};

struct NewIdExp : public Exp 
{
    NewIdExp(Identifier* id);
    ExpType getType() { return NewIdType; }

    std::shared_ptr<Identifier> id;
};

struct NotExp : public Exp 
{
    NotExp(Exp* exp);
    ExpType getType() { return NotType; }

    std::shared_ptr<Exp> exp;
};

struct NumberExp : public Exp 
{
    NumberExp(int value);
    ExpType getType() { return NumberType; }

    int value;
};

struct TrueExp : public Exp 
{
    TrueExp();
    ExpType getType() { return TrueType; }
};

struct FalseExp : public Exp 
{
    FalseExp();
    ExpType getType() { return FalseType; }
};

struct IdExp : public Exp 
{
    IdExp(Identifier* id);
    ExpType getType() { return IdType; }

    std::shared_ptr<Identifier> id;
};

struct ThisExp : public Exp 
{
    ThisExp();
    ExpType getType() { return ThisType; }
};

} // End of namespace mJ

#endif // __AST_H__