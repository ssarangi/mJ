#ifndef __TYPECHECKER_H__
#define __TYPECHECKER_H__

#include "ast.h"
#include "symboltable.h"
#include "visitor.h"
#include "tablegenerator.h"
#include <string>
#include <map>

class TypeChecker 
{
public:
	TypeChecker(std::shared_ptr<Program> program);
	~TypeChecker();

	void check();

	void visit(std::shared_ptr<Program> program);
	void visit(std::shared_ptr<MainClass> mainClass);
	void visit(std::shared_ptr<ClassDecl> classDecl);
	void visit(std::shared_ptr<NormalClassDecl> normalClassDecl);
	void visit(std::shared_ptr<ExtendsClassDecl> extendsClassDecl);
	void visit(std::shared_ptr<VarDecl> varDecl);
	void visit(std::shared_ptr<MethodDecl> methodDecl);
	void visit(std::shared_ptr<Argument> argument);
	void visit(std::shared_ptr<Stmt> stmt);
	void visit(std::shared_ptr<NestedStmt> nestedStmt);
	void visit(std::shared_ptr<IfStmt> ifStmt);
	void visit(std::shared_ptr<WhileStmt> whileStmt);
	void visit(std::shared_ptr<PrintlnStmt> printlnStmt);
	void visit(std::shared_ptr<AssignmentStmt> assignmentStmt);
	void visit(std::shared_ptr<ArrayAssignmentStmt> arrayAssignmentStmt);
	void visit(std::shared_ptr<VarDeclStmt> varDeclStmt);
	Type visit(std::shared_ptr<Exp> exp);
	Type visit(std::shared_ptr<OrExp> exp);
	Type visit(std::shared_ptr<AndExp> exp);
	Type visit(std::shared_ptr<LessThanExp> exp);
	Type visit(std::shared_ptr<GreaterThanExp> exp);
	Type visit(std::shared_ptr<DifferentExp> exp);
	Type visit(std::shared_ptr<EqualExp> exp);
	Type visit(std::shared_ptr<PlusExp> exp);
	Type visit(std::shared_ptr<MinusExp> exp);
	Type visit(std::shared_ptr<TimesExp> exp);
	Type visit(std::shared_ptr<ArrayValueExp> exp);
	Type visit(std::shared_ptr<ArrayLengthExp> exp);
	Type visit(std::shared_ptr<MemberFunctionExp> exp);
	Type visit(std::shared_ptr<NewIntArrayExp> exp);
	Type visit(std::shared_ptr<NewIdExp> exp);
	Type visit(std::shared_ptr<NotExp> exp);
	Type visit(std::shared_ptr<NumberExp> exp);
	Type visit(std::shared_ptr<TrueExp> exp);
	Type visit(std::shared_ptr<FalseExp> exp);
	Type visit(std::shared_ptr<IdExp> exp);
	Type visit(std::shared_ptr<ThisExp> exp);
	
	bool hasErrors();
	std::vector<std::string> getErrors();

private:
	std::shared_ptr<Program> program;
	std::shared_ptr<SymbolTable> classTable;
	MethodMap methods;
	SymbolTable variables;
	std::vector<std::string> errors;
	std::string classScope;
};

#endif
