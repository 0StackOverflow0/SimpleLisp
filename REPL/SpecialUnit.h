#include "stdafx.h"
#include "Unit.h"

#ifndef _SpecialUnit
#define _SpecialUnit

namespace REPL
{
	class AddUnit: public FunctionUnit
	{
	private:
	public:
		BaseUnit* Perform();

		AddUnit (): FunctionUnit() { tpUnit = AddUnit_; SetName("+"); }
		AddUnit (const AddUnit&);
	};

	class SubUnit: public FunctionUnit
	{
	private:
	public:
		BaseUnit* Perform();

		SubUnit (): FunctionUnit() { tpUnit = SubUnit_; SetName("-"); }
		SubUnit (const SubUnit&);
	};

	class MulUnit: public FunctionUnit
	{
	private:
	public:
		BaseUnit* Perform();

		MulUnit (): FunctionUnit() { tpUnit = MulUnit_; SetName("*"); }
		MulUnit (const MulUnit&);
	};

	class DivUnit: public FunctionUnit
	{
	private:
	public:
		BaseUnit* Perform();

		DivUnit (): FunctionUnit() { tpUnit = DivUnit_; SetName("/"); }
		DivUnit (const DivUnit&);
	};

	class EqlUnit: public FunctionUnit
	{
	private:
	public:
		BaseUnit* Perform();

		EqlUnit (): FunctionUnit() { tpUnit = EqlUnit_; SetName("="); }
		EqlUnit (const EqlUnit&);
	};

	class GtrUnit: public FunctionUnit
	{
	private:
	public:
		BaseUnit* Perform();

		GtrUnit (): FunctionUnit() { tpUnit = GtrUnit_; SetName(">"); }
		GtrUnit (const GtrUnit&);
	};

	class LesUnit: public FunctionUnit
	{
	private:
	public:
		BaseUnit* Perform();

		LesUnit (): FunctionUnit() { tpUnit = LesUnit_; SetName("<"); }
		LesUnit (const LesUnit&);
	};

	class LetUnit: public FunctionUnit
	{
	private:
	public:
		BaseUnit* Perform();

		LetUnit (): FunctionUnit() { tpUnit = LetUnit_; SetName("let"); }
		LetUnit (const LetUnit&);
	};

	class LambdaUnit: public FunctionUnit
	{
	private:
	public:
		BaseUnit* Perform();

		LambdaUnit (): FunctionUnit() { tpUnit = LamUnit_; SetName("lambda"); }
		LambdaUnit (const LambdaUnit&);
	};

	class DefunUnit: public FunctionUnit
	{
	private:
	public:
		BaseUnit* Perform();

		DefunUnit (): FunctionUnit() { tpUnit = DfnUnit_; SetName("defun"); }
		DefunUnit (const DefunUnit&);
	};

	class IfThenUnit: public FunctionUnit
	{
	private:
	public:
		BaseUnit* Perform();

		IfThenUnit (): FunctionUnit() { tpUnit = IfUnit_; SetName("if"); }
		IfThenUnit (const IfThenUnit&);
	};

	class CondUnit: public FunctionUnit
	{
	private:
	public:
		BaseUnit* Perform();

		CondUnit (): FunctionUnit() { tpUnit = CondUnit_; SetName("cond"); }
		CondUnit (const CondUnit&);
	};
}

#endif