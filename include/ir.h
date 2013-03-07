#ifndef __IR_H__
#define __IR_H__

#include <memory>

#include <string>
#include <vector>

namespace Temp 
{
	struct Temp;
	struct Label;
	struct LabelList;
}

namespace Tree 
{

struct Exp;
struct Stm;

enum BinaryOperation 
{
	Plus = 0,
	Minus,
	Times,
	And,
	Or
};

enum CJumpOperation 
{
	Equal = 0,
	NotEqual,
	LessThan,
	GreaterThan
};

struct Exp 
{
	Exp();
};

struct ExpList
{
	ExpList(std::shared_ptr<Exp> head, std::shared_ptr<ExpList> tail);

	std::shared_ptr<Exp> head;
	std::shared_ptr<ExpList> tail;
};

struct Const : public Exp 
{
	Const(const int value);
	
	int value;
};

struct Name : public Exp 
{
	Name(std::shared_ptr<Temp::Label> label);

	std::shared_ptr<Temp::Label> label;
};

struct TempExp : public Exp 
{
	TempExp(std::shared_ptr<Temp::Temp> temp);

	std::shared_ptr<Temp::Temp> temp;
};

struct Binop : public Exp 
{
	Binop(BinaryOperation binop, std::shared_ptr<Exp> left, std::shared_ptr<Exp> right);

	BinaryOperation binop;
	std::shared_ptr<Exp> left;
	std::shared_ptr<Exp> right;
};

struct Mem : public Exp 
{
	Mem(std::shared_ptr<Exp> exp);

	std::shared_ptr<Exp> exp;
};

struct Call : public Exp 
{
	Call(std::shared_ptr<Exp> func, std::shared_ptr<ExpList> args);

	std::shared_ptr<Exp> func;
	std::shared_ptr<ExpList> args;
};

struct ESeq : public Exp 
{
	ESeq(std::shared_ptr<Stm> stm, std::shared_ptr<Exp> exp);

	std::shared_ptr<Stm> stm;
	std::shared_ptr<Exp> exp;
};

struct Stm 
{
	Stm();
};

struct StmList 
{
	StmList(std::shared_ptr<Stm> head, std::shared_ptr<StmList> tail);

	std::shared_ptr<Stm> head;
	std::shared_ptr<StmList> tail;
};

struct Move : public Stm 
{
	Move(std::shared_ptr<Exp> dst, std::shared_ptr<Exp> src);

	std::shared_ptr<Exp> dst;
	std::shared_ptr<Exp> src;
};

struct ExpStm : public Stm 
{
	ExpStm(std::shared_ptr<Exp> exp);

	std::shared_ptr<Exp> exp;
};

struct Jump : public Stm 
{
	Jump(std::shared_ptr<Exp> exp, std::shared_ptr<Temp::LabelList> targets);

	std::shared_ptr<Exp> exp;
	std::shared_ptr<Temp::LabelList> targets;
};

struct CJump : public Stm 
{
	CJump(CJumpOperation op, std::shared_ptr<Exp> left, std::shared_ptr<Exp> right, std::shared_ptr<Temp::Label> iftrue, std::shared_ptr<Temp::Label> iffalse);

	CJumpOperation op;
	std::shared_ptr<Exp> left;
	std::shared_ptr<Exp> right;
	std::shared_ptr<Temp::Label> iftrue;
	std::shared_ptr<Temp::Label> iffalse;
};

struct Seq : public Stm 
{
	Seq(std::shared_ptr<Stm> left, std::shared_ptr<Stm> right);

	std::shared_ptr<Stm> left;
	std::shared_ptr<Stm> right;
};

struct StmLabel : public Stm 
{
	StmLabel(std::shared_ptr<Temp::Label> label);

	std::shared_ptr<Temp::Label> label;
};

}

#endif

