#ifndef __TEMP_H__
#define __TEMP_H__

#include <memory>
#include <string>

namespace mJ
{

class Symbol;

namespace Temp 
{

struct Temp 
{
	Temp();

	std::string toString();
};

struct Label 
{
	Label();
	Label(std::string s);
	Label(std::shared_ptr<Symbol> symbol);
	
	std::string toString();

	std::string s;
	std::shared_ptr<Symbol> symbol;
};

struct TempList 
{
	TempList();
};

struct LabelList 
{
	LabelList();
};

} // End of namespace Temp

} // End of namespace mJ

#endif

