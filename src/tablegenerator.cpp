#include "tablegenerator.h"

namespace mJ
{

TableGenerator::TableGenerator(std::shared_ptr<Program> program) 
    : program(program) 
{
}

TableGenerator::~TableGenerator()
{
}

void TableGenerator::generate()
{
    classTable = std::shared_ptr<SymbolTable>(new SymbolTable());
    visit(program);
}

std::shared_ptr<SymbolTable> TableGenerator::getClassTable() 
{
    return classTable;
}

MethodMap TableGenerator::getMethodsMap() 
{
    return methods;
}

void TableGenerator::visit(std::shared_ptr<Program> program) 
{
    visit(program->mainClass);
    std::vector<std::shared_ptr<ClassDecl> > decls = program->classList->classDecls;

    for(unsigned int i = 0; i < decls.size(); i++)
        switch(decls[i]->getType()) 
    {
        case NormalClassType:
            visit(std::static_pointer_cast<NormalClassDecl>(decls[i]));
            break;
        case ExtendsClassType:
            visit(std::static_pointer_cast<ExtendsClassDecl>(decls[i]));
            break;
    }
}

void TableGenerator::visit(std::shared_ptr<MainClass> mainClass)
{
    classTable->addSymbol(std::shared_ptr<Symbol>(new Symbol(mainClass->classId->name, ClassSymbol)));
}

void TableGenerator::visit(std::shared_ptr<NormalClassDecl> normalClassDecl) 
{
    classScope = normalClassDecl->classId->name;

    classTable->addSymbol(std::shared_ptr<Symbol>(new Symbol(normalClassDecl->classId->name, ClassSymbol)));
    std::shared_ptr<SymbolTable> table = std::shared_ptr<SymbolTable>(new SymbolTable());
    methods.insert( make_pair(classScope, table) );
    std::vector< std::shared_ptr<MethodDecl> > decls = normalClassDecl->methodList->methodDecls;

    for(unsigned int i = 0; i < decls.size(); i++)
        visit(decls[i]);

    classScope = "";
}

void TableGenerator::visit(std::shared_ptr<ExtendsClassDecl> extendsClassDecl)
{
    classScope = extendsClassDecl->classId->name;

    classTable->addSymbol(std::shared_ptr<Symbol>(new Symbol(extendsClassDecl->classId->name, ClassSymbol)));
    std::shared_ptr<SymbolTable> table(new SymbolTable(*(methods[extendsClassDecl->classExtendsId->name])));
    methods.insert( make_pair(classScope, table) );

    std::vector<std::shared_ptr<MethodDecl> > decls = extendsClassDecl->methodList->methodDecls;
    for(unsigned int i = 0; i < decls.size(); i++)
        visit(decls[i]);

    classScope = "";
}

void TableGenerator::visit(std::shared_ptr<VarDecl> varDecl)
{

}

void TableGenerator::visit(std::shared_ptr<MethodDecl> methodDecl) 
{
    methodScope = methodDecl->id->name;

    std::shared_ptr<Symbol> newSymbol(new Symbol(methodDecl->id->name, MethodSymbol));
    newSymbol->setReturn(methodDecl->type->name);
    std::shared_ptr<SymbolTable> table = methods[classScope];
    table->addSymbol(newSymbol);

    std::vector<std::shared_ptr<Argument> > arguments = methodDecl->argumentList->arguments;
    for(unsigned int i = 0; i < arguments.size(); i++)
        visit(arguments[i]);

    methodScope = "";
}

void TableGenerator::visit(std::shared_ptr<Argument> argument) 
{
    std::shared_ptr<SymbolTable> table = methods[classScope];
    std::shared_ptr<Symbol> methodSymbol = table->getSymbol(methodScope);
    methodSymbol->addArgument(argument->type->name);
}

void TableGenerator::visit(std::shared_ptr<NestedStmt> nestedStmt) 
{
}

void TableGenerator::visit(std::shared_ptr<IfStmt> ifStmt) 
{
}

void TableGenerator::visit(std::shared_ptr<WhileStmt> whileStmt) 
{
}

void TableGenerator::visit(std::shared_ptr<PrintlnStmt> printlnStmt) 
{
}

void TableGenerator::visit(std::shared_ptr<AssignmentStmt> assignmentStmt) 
{
}

void TableGenerator::visit(std::shared_ptr<ArrayAssignmentStmt> arrayAssignmentStmt) 
{
}

void TableGenerator::visit(std::shared_ptr<VarDeclStmt> varDeclStmt) 
{
}

void TableGenerator::visit(std::shared_ptr<OrExp> exp) 
{
}

void TableGenerator::visit(std::shared_ptr<AndExp> exp) 
{
}

void TableGenerator::visit(std::shared_ptr<LessThanExp> exp) 
{
}

void TableGenerator::visit(std::shared_ptr<GreaterThanExp> exp) 
{
}

void TableGenerator::visit(std::shared_ptr<DifferentExp> exp) 
{
}

void TableGenerator::visit(std::shared_ptr<EqualExp> exp) 
{
}

void TableGenerator::visit(std::shared_ptr<PlusExp> exp) 
{
}

void TableGenerator::visit(std::shared_ptr<MinusExp> exp) 
{
}

void TableGenerator::visit(std::shared_ptr<TimesExp> exp) 
{
}

void TableGenerator::visit(std::shared_ptr<ArrayValueExp> exp) 
{
}

void TableGenerator::visit(std::shared_ptr<ArrayLengthExp> exp) 
{
}

void TableGenerator::visit(std::shared_ptr<MemberFunctionExp> exp) 
{
}

void TableGenerator::visit(std::shared_ptr<NewIntArrayExp> exp) 
{
}

void TableGenerator::visit(std::shared_ptr<NewIdExp> exp) 
{
}

void TableGenerator::visit(std::shared_ptr<NotExp> exp) 
{
}

void TableGenerator::visit(std::shared_ptr<NumberExp> exp) 
{
}

void TableGenerator::visit(std::shared_ptr<TrueExp> exp) 
{
}

void TableGenerator::visit(std::shared_ptr<FalseExp> exp) 
{
}

void TableGenerator::visit(std::shared_ptr<IdExp> exp) 
{
}

void TableGenerator::visit(std::shared_ptr<ThisExp> exp) 
{
}

} // End of namespace mJ