#ifndef __TRANSLATE_H__
#define __TRANSLATE_H__

#include "ast.h"

struct Program;

namespace Tree 
{
	struct Exp;
}

class Translate 
{
	static std::shared_ptr<Tree::Exp> translate(std::shared_ptr<Exp> exp);
	static std::shared_ptr<Tree::Exp> translate(std::shared_ptr<OrExp> OrExp);
	static std::shared_ptr<Tree::Exp> translate(std::shared_ptr<AndExp> andExp);
	static std::shared_ptr<Tree::Exp> translate(std::shared_ptr<GreaterThanExp> greaterThanExp);
	static std::shared_ptr<Tree::Exp> translate(std::shared_ptr<DifferentExp> differentExp);
	static std::shared_ptr<Tree::Exp> translate(std::shared_ptr<EqualExp> equalExp);
	static std::shared_ptr<Tree::Exp> translate(std::shared_ptr<PlusExp> plusExp);
	static std::shared_ptr<Tree::Exp> translate(std::shared_ptr<MinusExp> minusExp);
	static std::shared_ptr<Tree::Exp> translate(std::shared_ptr<TimesExp> timesExp);
	static std::shared_ptr<Tree::Exp> translate(std::shared_ptr<NumberExp> numberExp);
	static std::shared_ptr<Tree::Exp> translate(std::shared_ptr<TrueExp> trueExp);
	static std::shared_ptr<Tree::Exp> translate(std::shared_ptr<FalseExp> falseExp);
};

#endif

