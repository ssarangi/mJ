#include "semantic.h"
#include "symboltable.h"
#include "typechecker.h"
#include <iostream>

SemanticAnalyser::SemanticAnalyser(std::shared_ptr<Program> program) 
    : program(program) 
{
}

SemanticAnalyser::~SemanticAnalyser() 
{
}

void SemanticAnalyser::checkProgram() 
{
    TypeChecker checker(program);
    checker.check();

    if(checker.hasErrors()) 
    {
        for (auto error = checker.getErrors().begin(), errorEnd = checker.getErrors().end();
             error != errorEnd;
             ++error)
             std::cout << *error << std::endl;
    }
}

bool SemanticAnalyser::hasErrors() 
{
    return !(errors.empty());
}

void SemanticAnalyser::printErrors() 
{
    if(hasErrors()) 
    {
        for(unsigned int i = 0; i < errors.size(); i++) 
        {
            std::cout << errors[i] << std::endl;
        }
    }
}
