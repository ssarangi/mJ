#ifndef __TABLEGENERATOR_H__
#define __TABLEGENERATOR_H__

#include "ast.h"
#include "symboltable.h"
#include "visitor.h"
#include <string>
#include <map>

typedef std::map<std::string, std::shared_ptr<SymbolTable> > MethodMap;

class TableGenerator: public Visitor 
{
public:
	TableGenerator(std::shared_ptr<Program> program);
	~TableGenerator();

	void generate();
	std::shared_ptr<SymbolTable> getClassTable();
	MethodMap getMethodsMap();

	void visit(std::shared_ptr<Program> program);
	void visit(std::shared_ptr<MainClass> mainClass);
	void visit(std::shared_ptr<NormalClassDecl> normalClassDecl);
	void visit(std::shared_ptr<ExtendsClassDecl> extendsClassDecl);
	void visit(std::shared_ptr<VarDecl> varDecl);
	void visit(std::shared_ptr<MethodDecl> methodDecl);
	void visit(std::shared_ptr<Argument> argument);
	void visit(std::shared_ptr<NestedStmt> nestedStmt);
	void visit(std::shared_ptr<IfStmt> ifStmt);
	void visit(std::shared_ptr<WhileStmt> whileStmt);
	void visit(std::shared_ptr<PrintlnStmt> printlnStmt);
	void visit(std::shared_ptr<AssignmentStmt> assignmentStmt);
	void visit(std::shared_ptr<ArrayAssignmentStmt> arrayAssignmentStmt);
	void visit(std::shared_ptr<VarDeclStmt> varDeclStmt);
	void visit(std::shared_ptr<OrExp> exp);
	void visit(std::shared_ptr<AndExp> exp);
	void visit(std::shared_ptr<LessThanExp> exp);
	void visit(std::shared_ptr<GreaterThanExp> exp);
	void visit(std::shared_ptr<DifferentExp> exp);
	void visit(std::shared_ptr<EqualExp> exp);
	void visit(std::shared_ptr<PlusExp> exp);
	void visit(std::shared_ptr<MinusExp> exp);
	void visit(std::shared_ptr<TimesExp> exp);
	void visit(std::shared_ptr<ArrayValueExp> exp);
	void visit(std::shared_ptr<ArrayLengthExp> exp);
	void visit(std::shared_ptr<MemberFunctionExp> exp);
	void visit(std::shared_ptr<NewIntArrayExp> exp);
	void visit(std::shared_ptr<NewIdExp> exp);
	void visit(std::shared_ptr<NotExp> exp);
	void visit(std::shared_ptr<NumberExp> exp);
	void visit(std::shared_ptr<TrueExp> exp);
	void visit(std::shared_ptr<FalseExp> exp);
	void visit(std::shared_ptr<IdExp> exp);
	void visit(std::shared_ptr<ThisExp> exp);

private:
	std::shared_ptr<Program> program;
	std::shared_ptr<SymbolTable> classTable;
	MethodMap methods;
	std::string classScope;
	std::string methodScope;
};

#endif
