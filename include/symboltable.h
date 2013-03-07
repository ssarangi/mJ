#ifndef __SYMBOLTABLE_H__
#define __SYMBOLTABLE_H__

#include "symbol.h"

#include <memory>

#include <string>
#include <map>
#include <vector>
#include <list>

typedef std::map<std::string, std::shared_ptr<Symbol> > SymbolMap;

class SymbolTable 
{
public:
	SymbolTable();

	void addSymbol(std::shared_ptr<Symbol> symbol);
	std::shared_ptr<Symbol> getSymbol(std::string name);
	void beginScope();
	void endScope();
	bool hasErrors();
	void print();
	std::vector<std::string> getErrors();

private:
	std::vector<std::string> errors;
	std::list<std::shared_ptr<SymbolMap> > symbols;
	std::shared_ptr<SymbolMap> currentMap;
};

#endif
