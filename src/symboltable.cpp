#include "symboltable.h"
#include <iostream>
#include <memory>

namespace mJ
{

SymbolTable::SymbolTable() 
{
    currentMap = std::shared_ptr<SymbolMap>(new SymbolMap());
}

void SymbolTable::addSymbol(std::shared_ptr<Symbol> symbol) 
{
    if(currentMap->count(symbol->getName()) != 0) 
    {
        errors.push_back("Redeclaration of symbol: " + symbol->getName());
    }

    currentMap->insert(make_pair(symbol->getName(), symbol));
}

std::shared_ptr<Symbol> SymbolTable::getSymbol(std::string name) 
{
    if(currentMap->count(name) != 0) return (*currentMap)[name];

    std::list<std::shared_ptr<SymbolMap> >::iterator it;

    for(it = symbols.begin(); it != symbols.end(); it++) 
    {
        std::shared_ptr<SymbolMap> map = /*(SymbolMap*)*/ (*it);
        if(map->count(name) != 0) return (*map)[name];
    }

    errors.push_back("Undeclared symbol: " + name);
    return std::shared_ptr<Symbol>(new Symbol(name));
}

void SymbolTable::beginScope() 
{
    symbols.push_front(currentMap);
    currentMap = std::shared_ptr<SymbolMap>(new SymbolMap());
}

void SymbolTable::endScope() 
{
    currentMap = symbols.front();
    symbols.pop_front();
}

bool SymbolTable::hasErrors() 
{
    return (!errors.empty());
}

void SymbolTable::print() 
{
    SymbolMap::iterator mapIt = currentMap->begin();
    while(mapIt != currentMap->end()) 
    {
        std::cout << mapIt->second->getName() << std::endl;
        mapIt++;
    }

    std::list<std::shared_ptr<SymbolMap> >::iterator it;
    
    for(it = symbols.begin(); it != symbols.end(); it++) 
    {
        std::cout << "Scope" << std::endl;
        mapIt = (*it)->begin();
        while(mapIt != (*it)->end()) 
        {
            std::cout << mapIt->second->getName() << std::endl;
            mapIt++;
        }
    }
}

std::vector<std::string> SymbolTable::getErrors() 
{
    return errors;
}

} // End of namespace mJ