#include "stdafx.h"
#include "RegisterUnit.h"

namespace REPL {

	void RegisterUnit(BaseUnit* unit_param) {
		BaseUnit* UnitToAdd = NULL;
		SymbolUnit* test = NULL;

		switch (unit_param->GetUnitType()) {
		case BasUnit:
			UnitToAdd = new BaseUnit(*unit_param);
			break;
		case SymUnit:
			UnitToAdd = new SymbolUnit(*(SymbolUnit*)unit_param);
			break;
		case FunUnit:
			UnitToAdd = new FunctionUnit(*(FunctionUnit*)unit_param);
			break;
		default:
			UnitToAdd = unit_param;
		}

		std::pair<std::string, BaseUnit*> regUnit(UnitToAdd->GetName(), UnitToAdd);
		REPLWorld.insert(regUnit);
	}

	void RegisterSpecialUnits() {
		//Create Units to Register
		AddUnit* add = new AddUnit();
		SubUnit* sub = new SubUnit();
		MulUnit* mul = new MulUnit();
		DivUnit* div = new DivUnit();
		EqlUnit* eql = new EqlUnit();
		GtrUnit* gtr = new GtrUnit();
		LesUnit* les = new LesUnit();
		LetUnit* let = new LetUnit();
		LambdaUnit* lam = new LambdaUnit();
		DefunUnit* def = new DefunUnit();
		IfThenUnit* ifthen = new IfThenUnit();
		CondUnit* cond = new CondUnit();

		SymbolUnit* pi = new SymbolUnit("pi",retVal(3.1415926535897932384626433832795));
		
		SymbolUnit* true_unit = new SymbolUnit("true", retVal(true));
		SymbolUnit* false_unit = new SymbolUnit("false", retVal(false));

		//Register Units
		RegisterUnit(add);
		RegisterUnit(sub);
		RegisterUnit(mul);
		RegisterUnit(div);
		RegisterUnit(eql);
		RegisterUnit(gtr);
		RegisterUnit(les);
		RegisterUnit(let);
		RegisterUnit(lam);
		RegisterUnit(def);
		RegisterUnit(ifthen);
		RegisterUnit(cond);

		RegisterUnit(pi);

		RegisterUnit(true_unit);
		RegisterUnit(false_unit);
	}

	BaseUnit* FindUnit(const std::string name) {
		auto list = REPLWorld.equal_range(name);
		auto size = REPLWorld.count(name);

		if (size == 0 || name == "")
			return NULL;

		// Use last entered Unit
		auto last = list.first;
		for (auto inc = 0; inc < (size - 1); ++inc)
			++last;

		BaseUnit* UnitToReturn = last->second;

		switch (UnitToReturn->GetUnitType()) {
		case BasUnit:
			UnitToReturn = new BaseUnit(*UnitToReturn);
			break;
		case SymUnit:
			UnitToReturn = new SymbolUnit(*(SymbolUnit*)UnitToReturn);
			break;
		case FunUnit:
			UnitToReturn = new FunctionUnit(*(FunctionUnit*)UnitToReturn);
			break;
		case AddUnit_:
			UnitToReturn = new AddUnit(*(AddUnit*)UnitToReturn);
			break;
		case SubUnit_:
			UnitToReturn = new SubUnit(*(SubUnit*)UnitToReturn);
			break;
		case MulUnit_:
			UnitToReturn = new MulUnit(*(MulUnit*)UnitToReturn);
			break;
		case DivUnit_:
			UnitToReturn = new DivUnit(*(DivUnit*)UnitToReturn);
			break;
		case EqlUnit_:
			UnitToReturn = new EqlUnit(*(EqlUnit*)UnitToReturn);
			break;
		case LesUnit_:
			UnitToReturn = new LesUnit(*(LesUnit*)UnitToReturn);
			break;
		case GtrUnit_:
			UnitToReturn = new GtrUnit(*(GtrUnit*)UnitToReturn);
			break;
		case LetUnit_:
			UnitToReturn = new LetUnit(*(LetUnit*)UnitToReturn);
			break;
		case LamUnit_:
			UnitToReturn = new LambdaUnit(*(LambdaUnit*)UnitToReturn);
			break;
		case DfnUnit_:
			UnitToReturn = new DefunUnit(*(DefunUnit*)UnitToReturn);
			break;
		case IfUnit_:
			UnitToReturn = new IfThenUnit(*(IfThenUnit*)UnitToReturn);
			break;
		case CondUnit_:
			UnitToReturn = new CondUnit(*(CondUnit*)UnitToReturn);
			break;
		} 
		return UnitToReturn;
	}

	void RemoveUnit(const std::string name) {
		auto list = REPLWorld.equal_range(name);
		auto size = REPLWorld.count(name);

		if (size == 0)
			return;

		// Use last entered Unit
		auto last = list.first;
		for (auto inc = 0; inc < (size - 1); ++inc)
			++last;

		REPLWorld.erase(last);
	}
}