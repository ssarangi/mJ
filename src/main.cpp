#include <string>
#include <iostream>
#include <vector>
#include "ast.h"
#include "semantic.h"

#include <memory>

extern int yyparse();
extern FILE* yyin;

extern mJ::Program* syntaxResult;

std::shared_ptr<mJ::Program> program;

int main(int ac, char** av)
{
    bool only_parse = false;
    bool file = false;
    try 
    {
        std::string filename = "";
        if (ac > 1)
            filename = std::string(av[1]);

        yyin = fopen( filename.c_str(), "r");
        
        if(yyin) 
            file = true;
        
        if(file) 
        {
            std::cout << "Parsing phase" << std::endl;
            if(yyparse())
                return 1;
            
            if(!only_parse) 
            {
                std::cout << "Semantic analysis" << std::endl;
                program = std::shared_ptr<mJ::Program>(syntaxResult);
                mJ::SemanticAnalyser analyser(program);
                analyser.checkProgram();
            }
            return 0;
        }
        else 
        {
                std::cout << "Error in arguments" << std::endl;
                return 0;
        }
    }
    catch(std::exception& e) 
    {
         std::cerr << "error: " << e.what() << std::endl;
         return 2;
    }
    catch(...) 
    {
        std::cerr << "Unexpected error!" << std::endl;
        return 3;
    }

    return 0;
}