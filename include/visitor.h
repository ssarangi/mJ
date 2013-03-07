#ifndef __VISITOR_H__
#define __VISITOR_H__

#include "ast.h"

#include <memory>

class Visitor 
{
public:
	virtual ~Visitor() { }

	virtual void visit(std::shared_ptr<Program> program) = 0;
	virtual void visit(std::shared_ptr<MainClass> mainClass) = 0;
	virtual void visit(std::shared_ptr<NormalClassDecl> normalClassDecl) = 0;
	virtual void visit(std::shared_ptr<ExtendsClassDecl> extendsClassDecl) = 0;
	virtual void visit(std::shared_ptr<VarDecl> varDecl) = 0;
	virtual void visit(std::shared_ptr<MethodDecl> methodDecl) = 0;
	virtual void visit(std::shared_ptr<Argument> argument) = 0;
	virtual void visit(std::shared_ptr<NestedStmt> nestedStmt) = 0;
	virtual void visit(std::shared_ptr<IfStmt> ifStmt) = 0;
	virtual void visit(std::shared_ptr<WhileStmt> whileStmt) = 0;
	virtual void visit(std::shared_ptr<PrintlnStmt> printlnStmt) = 0;
	virtual void visit(std::shared_ptr<AssignmentStmt> assignmentStmt) = 0;
	virtual void visit(std::shared_ptr<ArrayAssignmentStmt> arrayAssignmentStmt) = 0;
	virtual void visit(std::shared_ptr<VarDeclStmt> varDeclStmt) = 0;
	virtual void visit(std::shared_ptr<OrExp> exp) = 0;
	virtual void visit(std::shared_ptr<AndExp> exp) = 0;
	virtual void visit(std::shared_ptr<LessThanExp> exp) = 0;
	virtual void visit(std::shared_ptr<GreaterThanExp> exp) = 0;
	virtual void visit(std::shared_ptr<DifferentExp> exp) = 0;
	virtual void visit(std::shared_ptr<EqualExp> exp) = 0;
	virtual void visit(std::shared_ptr<PlusExp> exp) = 0;
	virtual void visit(std::shared_ptr<MinusExp> exp) = 0;
	virtual void visit(std::shared_ptr<TimesExp> exp) = 0;
	virtual void visit(std::shared_ptr<ArrayValueExp> exp) = 0;
	virtual void visit(std::shared_ptr<ArrayLengthExp> exp) = 0;
	virtual void visit(std::shared_ptr<MemberFunctionExp> exp) = 0;
	virtual void visit(std::shared_ptr<NewIntArrayExp> exp) = 0;
	virtual void visit(std::shared_ptr<NewIdExp> exp) = 0;
	virtual void visit(std::shared_ptr<NotExp> exp) = 0;
	virtual void visit(std::shared_ptr<NumberExp> exp) = 0;
	virtual void visit(std::shared_ptr<TrueExp> exp) = 0;
	virtual void visit(std::shared_ptr<FalseExp> exp) = 0;
	virtual void visit(std::shared_ptr<IdExp> exp) = 0;
	virtual void visit(std::shared_ptr<ThisExp> exp) = 0;
};

#endif
