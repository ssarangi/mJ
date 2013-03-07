#include "symbol.h"

namespace mJ
{

Symbol::Symbol(std::string name, SymbolType type) : name(name), type(type) 
{
	returnType = "_undeclared_type";
}

std::string Symbol::getName() 
{
	return name;
}

SymbolType Symbol::getType() 
{
	return type;
}

void Symbol::addArgument(std::string typeName) 
{
	if(type == MethodSymbol) arguments.push_back(typeName);
}

std::vector<std::string> Symbol::getArguments() 
{
	return arguments;
}

void Symbol::setReturn(std::string typeName) 
{
	returnType = typeName;
}

std::string Symbol::getReturn() 
{
	return returnType;
}

} // End of namespace mJ