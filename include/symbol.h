#ifndef __SYMBOL_H__
#define __SYMBOL_H__

#include <string>
#include <vector>

namespace mJ
{

enum SymbolType 
{
	UndefinedSymbol,
	ClassSymbol,
	MethodSymbol,
	VariableSymbol,
};

class Symbol 
{
public:
	Symbol(std::string name = "", SymbolType type = UndefinedSymbol);
	std::string getName();
	SymbolType getType();
	void addArgument(std::string typeName);
	std::vector<std::string> getArguments();
	void setReturn(std::string typeName);
	std::string getReturn();

private:
	std::string name;
	std::string returnType;
	SymbolType type;
	std::vector<std::string> arguments;
};

} // End of namespace

#endif
