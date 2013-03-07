#ifndef __SEMANTIC_H__
#define __SEMANTIC_H__

#include "ast.h"
#include <string>
#include <vector>

#include <memory>

class SemanticAnalyser 
{
public:
	SemanticAnalyser(std::shared_ptr<Program> program);
	~SemanticAnalyser();
	
	void checkProgram();
	bool hasErrors();
	void printErrors();

private:
	std::shared_ptr<Program> program;
	std::vector<std::string> errors;
};

#endif
