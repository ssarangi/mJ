#include "translate.h"
#include "ir.h"

#include <memory>
#include <assert.h>

namespace mJ
{

std::shared_ptr<Tree::Exp> Translate::translate(std::shared_ptr<Exp> exp) 
{
    switch(exp->getType()) 
    {
        case OrType:
            return translate(std::static_pointer_cast<OrExp>(exp));
        case AndType:
            return translate(std::static_pointer_cast<AndExp>(exp));
        case LessThanType:
            return translate(std::static_pointer_cast<LessThanExp>(exp));
        case GreaterThanType:
            // return translate(boost::static_pointer_cast<GreaterThanExp>(exp));
            break;
        case DifferentType:
            // return translate(boost::static_pointer_cast<DifferentExp>(exp));
            break;
        case EqualType:
            // return translate(boost::static_pointer_cast<EqualExp>(exp));
            break;
        case PlusType:
            return translate(std::static_pointer_cast<PlusExp>(exp));
        case MinusType:
            return translate(std::static_pointer_cast<MinusExp>(exp));
        case TimesType:
            return translate(std::static_pointer_cast<TimesExp>(exp));
/*		case ArrayValueType:
            return translate(boost::static_pointer_cast<ArrayValueExp>(exp));
        case ArrayLengthType:
            return translate(boost::static_pointer_cast<ArrayLengthExp>(exp));
        case MemberFunctionType:
            return translate(boost::static_pointer_cast<MemberFunctionExp>(exp));
        case NewIntArrayType:
            return translate(boost::static_pointer_cast<NewIntArrayExp>(exp));
        case NewIdType:
            return translate(boost::static_pointer_cast<NewIdExp>(exp));
*/
        case NotType:
            return translate(std::static_pointer_cast<NotExp>(exp));
        case NumberType:
            return translate(std::static_pointer_cast<NumberExp>(exp));
        case TrueType:
            return translate(std::static_pointer_cast<TrueExp>(exp));
        case FalseType:
            return translate(std::static_pointer_cast<FalseExp>(exp));
/*		case IdType:
            return translate(boost::static_pointer_cast<IdExp>(exp));
        case ThisType:
            return translate(boost::static_pointer_cast<ThisExp>(exp));
*/
        default:
            assert(0);
            break;
    }
}

std::shared_ptr<Tree::Exp> Translate::translate(std::shared_ptr<OrExp> orExp) 
{
    return std::shared_ptr<Tree::Binop>(new Tree::Binop(Tree::Or, translate(orExp->exp1), translate(orExp->exp2)));
}

std::shared_ptr<Tree::Exp> Translate::translate(std::shared_ptr<AndExp> andExp) 
{
    return std::shared_ptr<Tree::Binop>(new Tree::Binop(Tree::And, translate(andExp->exp1), translate(andExp->exp2)));
}

std::shared_ptr<Tree::Exp> Translate::translate(std::shared_ptr<PlusExp> plusExp) 
{
    return std::shared_ptr<Tree::Binop>(new Tree::Binop(Tree::Plus, translate(plusExp->exp1), translate(plusExp->exp2)));
}

std::shared_ptr<Tree::Exp> Translate::translate(std::shared_ptr<MinusExp> minusExp) 
{
    return std::shared_ptr<Tree::Binop>(new Tree::Binop(Tree::Minus, translate(minusExp->exp1), translate(minusExp->exp2)));
}

std::shared_ptr<Tree::Exp> Translate::translate(std::shared_ptr<TimesExp> timesExp) 
{
    return std::shared_ptr<Tree::Binop>(new Tree::Binop(Tree::Times, translate(timesExp->exp1), translate(timesExp->exp2)));
}

std::shared_ptr<Tree::Exp> Translate::translate(std::shared_ptr<NumberExp> numberExp) 
{
    return std::shared_ptr<Tree::Const>(new Tree::Const(numberExp->value));
}

std::shared_ptr<Tree::Exp> Translate::translate(std::shared_ptr<TrueExp> trueExp) 
{
    return std::shared_ptr<Tree::Const>(new Tree::Const(1));
}

std::shared_ptr<Tree::Exp> Translate::translate(std::shared_ptr<FalseExp> falseExp) 
{
    return std::shared_ptr<Tree::Const>(new Tree::Const(0));
}

} // End of namespace mJ

