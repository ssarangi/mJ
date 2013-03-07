#include "typechecker.h"
#include <memory>

namespace mJ
{

TypeChecker::TypeChecker(std::shared_ptr<Program> program) 
    : program(program) 
{
}

TypeChecker::~TypeChecker() 
{
}

void TypeChecker::check() 
{
    TableGenerator generator(program);
    generator.generate();
    classTable = generator.getClassTable();
    methods = generator.getMethodsMap();
    
    if(classTable->hasErrors()) 
    {
        for (auto I = classTable->getErrors().begin(), E = classTable->getErrors().end(); I != E; ++I)
        {
            errors.push_back(*I);
        }
    }

    std::pair<std::string, std::shared_ptr<SymbolTable> > methodPair;
    for (auto I = methods.begin(), E = methods.end(); I != E; ++I)
    {
        auto methodPair = *I;
        std::shared_ptr<SymbolTable> methodTable = methodPair.second;
        if(methodTable->hasErrors()) 
        {
            for (auto eb = methodTable->getErrors().begin(), ee = methodTable->getErrors().end(); eb != ee; ++eb)
                errors.push_back(*eb);
        }
    }

    visit(program);
    
    if(variables.hasErrors()) 
    {
        for (auto error = variables.getErrors().begin(), E = variables.getErrors().end(); error != E; ++error)
            errors.push_back(*error);
    }
}

void TypeChecker::visit(std::shared_ptr<Program> program) 
{
    visit(program->mainClass);

    for (auto I = program->classList->classDecls.begin(), E = program->classList->classDecls.end();
         I != E;
         ++I)
         visit(*I);
}

void TypeChecker::visit(std::shared_ptr<MainClass> mainClass) 
{
    variables.beginScope();
    classScope = mainClass->classId->name;

    for (auto stmt = mainClass->stmtList->stmts.begin(), stmtend = mainClass->stmtList->stmts.end();
         stmt != stmtend;
         ++stmt)
         visit(*stmt);

    classScope = "";
    variables.endScope();
}

void TypeChecker::visit(std::shared_ptr<ClassDecl> classDecl) 
{
    switch(classDecl->getType()) 
    {
        case NormalClassType:
            visit(std::static_pointer_cast<NormalClassDecl>(classDecl));
        case ExtendsClassType:
            visit(std::static_pointer_cast<ExtendsClassDecl>(classDecl));
    }
}

void TypeChecker::visit(std::shared_ptr<NormalClassDecl> normalClassDecl) 
{
    variables.beginScope();
    classScope = normalClassDecl->classId->name;

    for (auto decl = normalClassDecl->varList->varDecls.begin(), declEnd = normalClassDecl->varList->varDecls.end();
         decl != declEnd;
         ++decl)
         visit(*decl);

    for (auto decl = normalClassDecl->methodList->methodDecls.begin(), declEnd = normalClassDecl->methodList->methodDecls.end();
         decl != declEnd;
         ++decl)
         visit(*decl);

    classScope = "";
    variables.endScope();
}

void TypeChecker::visit(std::shared_ptr<ExtendsClassDecl> extendsClassDecl) 
{
    variables.beginScope();
    classScope = extendsClassDecl->classId->name;

    for (auto decl = extendsClassDecl->varList->varDecls.begin(), declEnd = extendsClassDecl->varList->varDecls.end();
         decl != declEnd;
         ++decl)
         visit(*decl);

    for (auto decl = extendsClassDecl->methodList->methodDecls.begin(), declEnd = extendsClassDecl->methodList->methodDecls.end();
        decl != declEnd;
        ++decl)
        visit(*decl);
    
    classScope = "";
    variables.endScope();
}

void TypeChecker::visit(std::shared_ptr<VarDecl> varDecl) 
{
    std::string name = varDecl->id->name;
    std::string type = varDecl->type->name;
    std::shared_ptr<Symbol> newSymbol(new Symbol(name, VariableSymbol));
    newSymbol->setReturn(type);

    variables.addSymbol(newSymbol);
}

void TypeChecker::visit(std::shared_ptr<MethodDecl> methodDecl) 
{
    std::string name = methodDecl->id->name;
    std::string type = methodDecl->type->name;

    variables.beginScope();

    for (auto argument = methodDecl->argumentList->arguments.begin(), argumentEnd = methodDecl->argumentList->arguments.end();
         argument != argumentEnd;
         ++argument)
         visit(*argument);

    for (auto stmt = methodDecl->stmtList->stmts.begin(), stmtEnd = methodDecl->stmtList->stmts.end();
        stmt != stmtEnd;
        ++stmt)
        visit(*stmt);
    
    if(visit(methodDecl->exp).name != type) 
        errors.push_back("Return type expected was " + type);

    variables.endScope();
}

void TypeChecker::visit(std::shared_ptr<Argument> argument) 
{
    std::string name = argument->id->name;
    std::string type = argument->type->name;
    std::shared_ptr<Symbol> newSymbol(new Symbol(name, VariableSymbol));
    newSymbol->setReturn(type);

    variables.addSymbol(newSymbol);
}

void TypeChecker::visit(std::shared_ptr<Stmt> stmt) 
{
    switch(stmt->getType()) 
    {
        case NestedType:
            return visit(std::static_pointer_cast<NestedStmt>(stmt));
        case IfType:
            return visit(std::static_pointer_cast<IfStmt>(stmt));
        case WhileType:
            return visit(std::static_pointer_cast<WhileStmt>(stmt));
        case PrintlnType:
            return visit(std::static_pointer_cast<PrintlnStmt>(stmt));
        case AssignmentType:
            return visit(std::static_pointer_cast<AssignmentStmt>(stmt));
        case ArrayAssignmentType:
            return visit(std::static_pointer_cast<ArrayAssignmentStmt>(stmt));
        case VarDeclType:
            return visit(std::static_pointer_cast<VarDeclStmt>(stmt));
    }
}

void TypeChecker::visit(std::shared_ptr<NestedStmt> nestedStmt) 
{
    variables.beginScope();

    for (auto stmt = nestedStmt->stmtList->stmts.begin(), stmtEnd = nestedStmt->stmtList->stmts.end();
         stmt != stmtEnd;
         ++stmt)
         visit(*stmt);

    variables.endScope();
}

void TypeChecker::visit(std::shared_ptr<IfStmt> ifStmt) 
{
    if(visit(ifStmt->exp).name != "bool") 
        errors.push_back("Expected boolean expression");
    visit(ifStmt->ifStmt);
    visit(ifStmt->elseStmt);
}

void TypeChecker::visit(std::shared_ptr<WhileStmt> whileStmt) 
{
    if(visit(whileStmt->exp).name != "bool") 
        errors.push_back("Expected boolean expression");
    visit(whileStmt->stmt);
}

void TypeChecker::visit(std::shared_ptr<PrintlnStmt> printlnStmt) 
{
    if(visit(printlnStmt->exp).name != "int") 
        errors.push_back("Expected integer expression in System.out.println.");
}

void TypeChecker::visit(std::shared_ptr<AssignmentStmt> assignmentStmt) 
{
    std::shared_ptr<Symbol> symbol = variables.getSymbol(assignmentStmt->id->name);
    
    if(symbol->getType() == UndefinedSymbol) 
    {
        errors.push_back("Undefined symbol " + symbol->getName());
        return;
    }

    if(symbol->getReturn() != visit(assignmentStmt->exp).name)
        errors.push_back("Type in assignment wrong.");
}

void TypeChecker::visit(std::shared_ptr<ArrayAssignmentStmt> arrayAssignmentStmt) 
{
    std::shared_ptr<Symbol> symbol = variables.getSymbol(arrayAssignmentStmt->id->name);
    
    if(symbol->getType() == UndefinedSymbol) 
    {
        errors.push_back("Undefined symbol " + symbol->getName());
        return;
    }

    if(symbol->getReturn() != "int[]") 
        errors.push_back("Variable " + arrayAssignmentStmt->id->name + " not an array");

    if(visit(arrayAssignmentStmt->exp).name != "int") 
        errors.push_back("Expected integer expression.");

    if(visit(arrayAssignmentStmt->assignmentExp).name == symbol->getReturn()) 
        errors.push_back("Expected integer expression.");
}

void TypeChecker::visit(std::shared_ptr<VarDeclStmt> varDeclStmt) 
{
    visit(varDeclStmt->varDecl);
}

Type TypeChecker::visit(std::shared_ptr<Exp> exp) 
{
    switch(exp->getType()) {
        case OrType:
            return visit(std::static_pointer_cast<OrExp>(exp));
        case AndType:
            return visit(std::static_pointer_cast<AndExp>(exp));
        case LessThanType:
            return visit(std::static_pointer_cast<LessThanExp>(exp));
        case GreaterThanType:
            return visit(std::static_pointer_cast<GreaterThanExp>(exp));
        case DifferentType:
            return visit(std::static_pointer_cast<DifferentExp>(exp));
        case EqualType:
            return visit(std::static_pointer_cast<EqualExp>(exp));
        case PlusType:
            return visit(std::static_pointer_cast<PlusExp>(exp));
        case MinusType:
            return visit(std::static_pointer_cast<MinusExp>(exp));
        case TimesType:
            return visit(std::static_pointer_cast<TimesExp>(exp));
        case ArrayValueType:
            return visit(std::static_pointer_cast<ArrayValueExp>(exp));
        case ArrayLengthType:
            return visit(std::static_pointer_cast<ArrayLengthExp>(exp));
        case MemberFunctionType:
            return visit(std::static_pointer_cast<MemberFunctionExp>(exp));
        case NewIntArrayType:
            return visit(std::static_pointer_cast<NewIntArrayExp>(exp));
        case NewIdType:
            return visit(std::static_pointer_cast<NewIdExp>(exp));
        case NotType:
            return visit(std::static_pointer_cast<NotExp>(exp));
        case NumberType:
            return visit(std::static_pointer_cast<NumberExp>(exp));
        case TrueType:
            return visit(std::static_pointer_cast<TrueExp>(exp));
        case FalseType:
            return visit(std::static_pointer_cast<FalseExp>(exp));
        case IdType:
            return visit(std::static_pointer_cast<IdExp>(exp));
        case ThisType:
            return visit(std::static_pointer_cast<ThisExp>(exp));
    }
    return Type("_internal_error1");
}

Type TypeChecker::visit(std::shared_ptr<OrExp> exp) 
{
    if(!(visit(exp->exp1).name == visit(exp->exp2).name && visit(exp->exp1).name == "bool")) 
        errors.push_back("Expected boolean expressions.");

    return Type("bool");
}

Type TypeChecker::visit(std::shared_ptr<AndExp> exp) 
{
    if(!(visit(exp->exp1).name == visit(exp->exp2).name && visit(exp->exp1).name == "bool")) 
        errors.push_back("Expected boolean expressions.");

    return Type("bool");
}

Type TypeChecker::visit(std::shared_ptr<LessThanExp> exp) 
{
    if(!(visit(exp->exp1).name == visit(exp->exp2).name && visit(exp->exp1).name == "bool")) 
        errors.push_back("Expected boolean expressions.");

    return Type("bool");
}

Type TypeChecker::visit(std::shared_ptr<GreaterThanExp> exp) 
{
    if(!(visit(exp->exp1).name == visit(exp->exp2).name && visit(exp->exp1).name == "bool")) 
        errors.push_back("Expected boolean expressions.");

    return Type("bool");
}

Type TypeChecker::visit(std::shared_ptr<DifferentExp> exp) 
{
    if(!(visit(exp->exp1).name == visit(exp->exp2).name && (visit(exp->exp1).name == "bool" || visit(exp->exp1).name == "int"))) 
        errors.push_back("Expected expressions with same type.");

    return Type("bool");
}

Type TypeChecker::visit(std::shared_ptr<EqualExp> exp) 
{
    if(!(visit(exp->exp1).name == visit(exp->exp2).name && (visit(exp->exp1).name == "bool" || visit(exp->exp1).name == "int"))) 
        errors.push_back("Expected expressions with same type.");

    return Type("bool");
}

Type TypeChecker::visit(std::shared_ptr<PlusExp> exp) 
{
    if(!(visit(exp->exp1).name == visit(exp->exp2).name && visit(exp->exp1).name == "int")) 
        errors.push_back("Expected integer expressions.");

    return Type("int");
}

Type TypeChecker::visit(std::shared_ptr<MinusExp> exp) 
{
    if(!(visit(exp->exp1).name == visit(exp->exp2).name && visit(exp->exp1).name == "int")) 
        errors.push_back("Expected integer expressions.");

    return Type("int");
}

Type TypeChecker::visit(std::shared_ptr<TimesExp> exp) 
{
    if(!(visit(exp->exp1).name == visit(exp->exp2).name && visit(exp->exp1).name == "int")) errors.push_back("Expected integer expressions.");

    return Type("int");
}

Type TypeChecker::visit(std::shared_ptr<ArrayValueExp> exp) 
{
    return Type("int");
}

Type TypeChecker::visit(std::shared_ptr<ArrayLengthExp> exp) 
{
    return Type("int");
}

Type TypeChecker::visit(std::shared_ptr<MemberFunctionExp> exp) 
{
    Type classType = visit(exp->exp);
    std::shared_ptr<Symbol> classSymbol = classTable->getSymbol(classType.name);
    
    if(classSymbol->getType() == UndefinedSymbol) 
    {
        errors.push_back("Class " + classType.name + " undeclared");
        return Type(classType.name);
    }

    std::shared_ptr<SymbolTable> classMethods = methods[classType.name];
    std::shared_ptr<Symbol> methodSymbol = classMethods->getSymbol(exp->id->name);
    
    if(methodSymbol->getType() == UndefinedSymbol) 
    {
        errors.push_back("Method " + exp->id->name + " doesn't exist in class " + classType.name);
        return Type("_internal_error2");
    }

    std::vector<std::string> arguments = methodSymbol->getArguments();
    std::vector<std::shared_ptr<Exp> > list = exp->list->exps;

    if(list.size() != arguments.size()) 
    {
        errors.push_back("Argument number wrong in method " + methodSymbol->getName() + " in class " + classType.name);
        return Type(methodSymbol->getReturn());
    }

    for(unsigned int i = 0; i < list.size(); i++) 
    {
        if(visit(list[i]).name != arguments[i]) 
        {
            errors.push_back("Expected argument with type " + arguments[i] + " in method " + methodSymbol->getName() + " in class " + classType.name);
        }
    }

    return Type(methodSymbol->getReturn());
}

Type TypeChecker::visit(std::shared_ptr<NewIntArrayExp> exp) 
{
    return Type("int[]");
}

Type TypeChecker::visit(std::shared_ptr<NewIdExp> exp) 
{
    return Type(exp->id->name);
}

Type TypeChecker::visit(std::shared_ptr<NotExp> exp) 
{
    std::shared_ptr<Exp> expression = exp->exp;	
    if(visit(expression).name != "bool") errors.push_back("Expected expression to be boolean.");

    return Type("bool");
}

Type TypeChecker::visit(std::shared_ptr<NumberExp> exp) 
{
    return Type("int");
}

Type TypeChecker::visit(std::shared_ptr<TrueExp> exp) 
{
    return Type("bool");
}

Type TypeChecker::visit(std::shared_ptr<FalseExp> exp) 
{
    return Type("bool");
}

Type TypeChecker::visit(std::shared_ptr<IdExp> exp) 
{
    std::shared_ptr<Symbol> symbol = variables.getSymbol(exp->id->name);
    
    if(symbol->getType() == UndefinedSymbol) 
    {
        errors.push_back("Undeclared variable with name " + exp->id->name);
    }

    return Type(symbol->getReturn());
}

Type TypeChecker::visit(std::shared_ptr<ThisExp> exp) 
{
    return Type(classScope);
}

bool TypeChecker::hasErrors() 
{
    return (!errors.empty());
}

std::vector<std::string> TypeChecker::getErrors() 
{
    return errors;
}

} // End of namespace mJ