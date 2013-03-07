#include "ir.h"

#include "temp.h"

namespace mJ
{

namespace Tree 
{

Exp::Exp() 
{
} 

ExpList::ExpList(std::shared_ptr<Exp> head, std::shared_ptr<ExpList> tail) 
    : head(head)
    , tail(tail) 
{
}

Const::Const(const int value) 
    : Exp()
    , value(value) 
{
}

Name::Name(std::shared_ptr<Temp::Label> label) 
    : Exp()
    , label(label) 
{
}

TempExp::TempExp(std::shared_ptr<Temp::Temp> temp) 
    : Exp()
    , temp(temp) 
{
}

Binop::Binop(BinaryOperation binop, std::shared_ptr<Exp> left, std::shared_ptr<Exp> right) 
    : Exp()
    , binop(binop)
    , left(left)
    , right(right) 
{
}

Mem::Mem(std::shared_ptr<Exp> exp) 
    : Exp()
    , exp(exp) 
{
}

Call::Call(std::shared_ptr<Exp> func, std::shared_ptr<ExpList> args) 
    : Exp()
    , func(func)
    , args(args) 
{
}

ESeq::ESeq(std::shared_ptr<Stm> stm, std::shared_ptr<Exp> exp) 
    : Exp()
    , stm(stm)
    , exp(exp) 
{
}

Stm::Stm() 
{
}

StmList::StmList(std::shared_ptr<Stm> head, std::shared_ptr<StmList> tail) 
    : head(head)
    , tail(tail) 
{
}

Move::Move(std::shared_ptr<Exp> dst, std::shared_ptr<Exp> src) 
    : Stm()
    , dst(dst)
    , src(src) 
{
}

ExpStm::ExpStm(std::shared_ptr<Exp> exp) 
    : Stm()
    , exp(exp) 
{
}

Jump::Jump(std::shared_ptr<Exp> exp, std::shared_ptr<Temp::LabelList> targets) 
    : Stm()
    , exp(exp)
    , targets(targets) 
{
}

CJump::CJump(CJumpOperation op, std::shared_ptr<Exp> left, std::shared_ptr<Exp> right, std::shared_ptr<Temp::Label> iftrue, std::shared_ptr<Temp::Label> iffalse) 
    : Stm()
    , op(op)
    , left(left)
    , right(right)
    , iftrue(iftrue)
    , iffalse(iffalse) 
{
}

Seq::Seq(std::shared_ptr<Stm> left, std::shared_ptr<Stm> right) 
    : Stm()
    , left(left)
    , right(right) 
{
}

StmLabel::StmLabel(std::shared_ptr<Temp::Label> label) 
    : Stm()
    , label(label) 
{
}

} // End of namespace Tree

} // End of namespace mJ