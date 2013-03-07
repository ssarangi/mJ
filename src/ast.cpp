#include "ast.h"

namespace mJ
{

ExpList::ExpList() 
{
}

void ExpList::insert(Exp* exp) 
{
    exps.push_back(std::shared_ptr<Exp>(exp));
}

void ExpList::insert(ExpList* expList) 
{
    exps.insert(exps.end(), expList->exps.begin(), expList->exps.end());
}

ClassList::ClassList() 
{
}

void ClassList::insert(ClassDecl* classDecl) 
{
    classDecls.push_back(std::shared_ptr<ClassDecl>(classDecl));	
}

void ClassList::insert(ClassList* classList) 
{
    classDecls.insert(classDecls.end(), classList->classDecls.begin(), classList->classDecls.end());
}

VarList::VarList() 
{
}

void VarList::insert(VarDecl* varDecl) 
{
    varDecls.push_back(std::shared_ptr<VarDecl>(varDecl));
}

void VarList::insert(VarList* varList) 
{
    varDecls.insert(varDecls.end(), varList->varDecls.begin(), varList->varDecls.end());
}

MethodList::MethodList() 
{
}

void MethodList::insert(MethodDecl* methodDecl) 
{
    methodDecls.push_back(std::shared_ptr<MethodDecl>(methodDecl));
}

void MethodList::insert(MethodList* methodList) 
{
    methodDecls.insert(methodDecls.end(), methodList->methodDecls.begin(), methodList->methodDecls.end());
}

ArgumentList::ArgumentList() 
{
}

void ArgumentList::insert(Argument* argument) 
{
    arguments.push_back(std::shared_ptr<Argument>(argument));
}

void ArgumentList::insert(ArgumentList* argumentList) 
{
    arguments.insert(arguments.end(), argumentList->arguments.begin(), argumentList->arguments.end());
}

StmtList::StmtList() 
{
}

void StmtList::insert(Stmt* stmt) 
{
    stmts.push_back(std::shared_ptr<Stmt>(stmt));
}

void StmtList::insert(StmtList* stmtList) 
{
    stmts.insert(stmts.end(), stmtList->stmts.begin(), stmtList->stmts.end());
}

ClassDecl::ClassDecl(Identifier* classId, VarList* varList, MethodList* methodList)
    : classId(classId)
    , varList(varList)
    , methodList(methodList) 
{
}

Stmt::Stmt() 
{
}

Exp::Exp() 
{
}

Type::Type(std::string name) : name(name) 
{
}

Program::Program(MainClass* mainClass, ClassList* classList) 
    : mainClass(mainClass)
    , classList(classList)
{
}

MainClass::MainClass(MainMethodDecl* mainMethod)
    : ClassDecl(new Identifier("Main"), nullptr, new MethodList())
{
    methodList->insert(static_cast<MethodDecl*>(mainMethod));
}

MainMethodDecl::MainMethodDecl(Identifier* argIdentifier, StmtList* stmtList)
    : MethodDecl(new Type("void"), new Identifier("main"), new ArgumentList(), new StmtList(), nullptr)
{
}

NormalClassDecl::NormalClassDecl(Identifier* classId, VarList* varList, MethodList* methodList) 
    : ClassDecl(classId, varList, methodList) 
{
}

ExtendsClassDecl::ExtendsClassDecl(Identifier* classId, Identifier* classExtendsId, VarList* varList, MethodList* methodList) 
    : ClassDecl(classId, varList, methodList)
    , classExtendsId(classExtendsId) 
{
}

VarDecl::VarDecl(Type* type, Identifier* id) 
    : type(type) 
    , id(id) 
{
}

MethodDecl::MethodDecl(Type* type, Identifier* id, ArgumentList* argumentList, StmtList* stmtList, Exp* exp) 
    : type(type)
    , id(id)
    , argumentList(argumentList)
    , stmtList(stmtList)
    , exp(exp) 
{
}

Argument::Argument(Type* type, Identifier* id) 
    : type(type)
    , id(id) 
{
}

NestedStmt::NestedStmt(StmtList* stmtList) 
    : stmtList(stmtList) 
{
}

IfStmt::IfStmt(Exp* exp,Stmt* ifStmt, Stmt* elseStmt) 
    : Stmt()
    , exp(exp)
    , ifStmt(ifStmt)
    , elseStmt(elseStmt) 
{
}

WhileStmt::WhileStmt(Exp* exp, Stmt* stmt) 
    : Stmt()
    , exp(exp)
    , stmt(stmt) 
{
} 

PrintlnStmt::PrintlnStmt(Exp* exp) 
    : Stmt()
    , exp(exp) 
{
}

AssignmentStmt::AssignmentStmt(Identifier* id, Exp* exp) 
    : Stmt()
    , id(id)
    , exp(exp) 
{
}

ArrayAssignmentStmt::ArrayAssignmentStmt(Identifier* id, Exp* exp, Exp* assignmentExp) 
    : Stmt()
    , id(id)
    , exp(exp)
    , assignmentExp(assignmentExp) 
{
}

VarDeclStmt::VarDeclStmt(VarDecl* varDecl) 
    : Stmt()
    , varDecl(varDecl) 
{
}

OrExp::OrExp(Exp* exp1, Exp* exp2) 
    : Exp()
    , exp1(exp1)
    , exp2(exp2) 
{
}

AndExp::AndExp(Exp* exp1, Exp* exp2) 
    : Exp()
    , exp1(exp1)
    , exp2(exp2) 
{
}

LessThanExp::LessThanExp(Exp* exp1, Exp* exp2) 
    : Exp()
    , exp1(exp1)
    , exp2(exp2) 
{
}

GreaterThanExp::GreaterThanExp(Exp* exp1, Exp* exp2) 
    : Exp()
    , exp1(exp1)
    , exp2(exp2) 
{
}

DifferentExp::DifferentExp(Exp* exp1, Exp* exp2) 
    : Exp()
    , exp1(exp1)
    , exp2(exp2) 
{
}

EqualExp::EqualExp(Exp* exp1, Exp* exp2) 
    : Exp()
    , exp1(exp1)
    , exp2(exp2) 
{
}

PlusExp::PlusExp(Exp* exp1, Exp* exp2) 
    : Exp()
    , exp1(exp1)
    , exp2(exp2) 
{
}

MinusExp::MinusExp(Exp* exp1, Exp* exp2) 
    : Exp()
    , exp1(exp1)
    , exp2(exp2) 
{
}

TimesExp::TimesExp(Exp* exp1, Exp* exp2) 
    : Exp()
    , exp1(exp1)
    , exp2(exp2) 
{
}

ArrayValueExp::ArrayValueExp(Exp* exp1, Exp* exp2) 
    : Exp()
    , exp1(exp1)
    , exp2(exp2) 
{
}

ArrayLengthExp::ArrayLengthExp(Exp* exp) 
    : Exp()
    , exp(exp) 
{
}

MemberFunctionExp::MemberFunctionExp(Exp* exp, Identifier* id, ExpList* list) 
    : Exp()
    , exp(exp)
    , id(id)
    , list(list) 
{
}

NewIntArrayExp::NewIntArrayExp(Exp* exp) 
    : Exp()
    , exp(exp) 
{
}

NewIdExp::NewIdExp(Identifier* id) 
    : Exp()
    , id(id) 
{
}

NotExp::NotExp(Exp* exp) 
    : Exp()
    , exp(exp) 
{
}

NumberExp::NumberExp(int value) 
    : Exp()
    , value(value) 
{
}

TrueExp::TrueExp() 
    : Exp() 
{
}

FalseExp::FalseExp() 
    : Exp() 
{
}

IdExp::IdExp(Identifier* id) 
    : Exp()
    , id(id) 
{
}

ThisExp::ThisExp() 
    : Exp() 
{
}

} // End of namespace mJ