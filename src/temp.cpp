#include "temp.h"
#include "symbol.h"

namespace Temp 
{

Temp::Temp() 
{
}

Label::Label() 
{
}

Label::Label(std::shared_ptr<Symbol> symbol) 
    : symbol(symbol) 
{
}

Label::Label(std::string s) 
    : s(s) 
{
} 

TempList::TempList() 
{
}

LabelList::LabelList() 
{
}

}

