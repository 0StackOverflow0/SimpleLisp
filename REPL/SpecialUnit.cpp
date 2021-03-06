#include "stdafx.h"
#include "SpecialUnit.h"
#include "Reduce.h"

namespace REPL
{
	AddUnit::AddUnit(const AddUnit&)
		: FunctionUnit() {
			SetName("+"); }

	SubUnit::SubUnit(const SubUnit&)
		: FunctionUnit() {
			SetName("-"); }

	MulUnit::MulUnit(const MulUnit&)
		: FunctionUnit() {
			SetName("*"); }

	DivUnit::DivUnit(const DivUnit&)
		: FunctionUnit() {
			SetName("/"); }

	EqlUnit::EqlUnit(const EqlUnit&)
		: FunctionUnit() {
			SetName("="); }

	LesUnit::LesUnit(const LesUnit&)
		: FunctionUnit() {
			SetName("<"); }

	GtrUnit::GtrUnit(const GtrUnit&)
		: FunctionUnit() {
			SetName(">"); }

	LetUnit::LetUnit(const LetUnit&)
		: FunctionUnit() {
			SetName("let"); }

	LambdaUnit::LambdaUnit(const LambdaUnit&)
		: FunctionUnit() {
			SetName("lambda"); }

	DefunUnit::DefunUnit(const DefunUnit&)
		: FunctionUnit() {
			SetName("defun"); }

	IfThenUnit::IfThenUnit(const IfThenUnit&)
		: FunctionUnit() {
			SetName("if"); }

	CondUnit::CondUnit(const CondUnit&)
		: FunctionUnit() {
			SetName("cond"); }


	BaseUnit* AddUnit::Perform() {
		BaseUnit* CurUnit = this;
		SymbolUnit* Result = new SymbolUnit();

		while( CurUnit->GetNextUnit() != NULL) {
			SymbolUnit* ReducedUnit;
			ReducedUnit = (SymbolUnit*)Reduce(*CurUnit->GetNextUnit());

			switch ( ReducedUnit->GetUnitType() ) {
			case SymUnit:
				if (ReducedUnit->GetRetVal()->GetValType() == nonType) {
					std::cout << "Adding nonType Symbol Error" << std::endl;
					CurUnit = ReducedUnit;
					continue; }
				if (!Result->GetRetVal()->AddValue(*ReducedUnit->GetRetVal()))
					std::cout << "Error Adding Value" << std::endl;
				break;
			case FunUnit:
				std::cout << "Adding Function Unit Error" << std::endl;
				return Result;
			case BasUnit:
				std::cout << "Adding Basic Unit Error" << std::endl;
				return Result;
			}

			CurUnit = ReducedUnit;
		}
		
		Result->SetNameToValue();
		return Result;
	}

	BaseUnit* SubUnit::Perform() {
		BaseUnit* CurUnit = this;
		SymbolUnit* Result = new SymbolUnit();

		while( CurUnit->GetNextUnit() != NULL) {
			SymbolUnit* ReducedUnit;
			ReducedUnit = (SymbolUnit*)Reduce(*CurUnit->GetNextUnit());

			switch ( ReducedUnit->GetUnitType() ) {
			case SymUnit:
				if (ReducedUnit->GetRetVal()->GetValType() == nonType) {
					std::cout << "Subtracting nonType Symbol Error" << std::endl;
					CurUnit = ReducedUnit;
					continue; }
				if (!Result->GetRetVal()->SubValue(*ReducedUnit->GetRetVal()))
					std::cout << "Error Subtracting Value" << std::endl;
				break;
			case FunUnit:
				std::cout << "Subtracting Function Unit Error" << std::endl;
				return Result;
			case BasUnit:
				std::cout << "Subtracting Basic Unit Error" << std::endl;
				return Result;
			}

			CurUnit = ReducedUnit;
		}
		
		Result->SetNameToValue();
		return Result;
	}

	BaseUnit* MulUnit::Perform() {
		BaseUnit* CurUnit = this;
		SymbolUnit* Result = new SymbolUnit();

		while( CurUnit->GetNextUnit() != NULL) {
			SymbolUnit* ReducedUnit;
			ReducedUnit = (SymbolUnit*)Reduce(*CurUnit->GetNextUnit());

			switch ( ReducedUnit->GetUnitType() ) {
			case SymUnit:
				if (ReducedUnit->GetRetVal()->GetValType() == nonType) {
					std::cout << "Multiplying nonType Symbol Error" << std::endl;
					CurUnit = ReducedUnit;
					continue; }
				if (!Result->GetRetVal()->MulValue(*ReducedUnit->GetRetVal()))
					std::cout << "Error Multiplying Value" << std::endl;
				break;
			case FunUnit:
				std::cout << "Multiplying Function Unit Error" << std::endl;
				return Result;
			case BasUnit:
				std::cout << "Multiplying Basic Unit Error" << std::endl;
				return Result;
			}

			CurUnit = ReducedUnit;
		}
		Result->SetNameToValue();
		return Result;
	}

	BaseUnit* DivUnit::Perform() {
		BaseUnit* CurUnit = this;
		SymbolUnit* Result = new SymbolUnit();

		while( CurUnit->GetNextUnit() != NULL) {
			SymbolUnit* ReducedUnit;
			ReducedUnit = (SymbolUnit*)Reduce(*CurUnit->GetNextUnit());

			switch ( ReducedUnit->GetUnitType() ) {
			case SymUnit:
				if (ReducedUnit->GetRetVal()->GetValType() == nonType) {
					std::cout << "Dividing nonType Symbol Error" << std::endl;
				CurUnit = ReducedUnit;
					continue; }
				if (!Result->GetRetVal()->DivValue(*ReducedUnit->GetRetVal()))
					std::cout << "Error Dividing Value" << std::endl;
				break;
			case FunUnit:
				std::cout << "Dividing Function Unit Error" << std::endl;
				return Result;
			case BasUnit:
				std::cout << "Dividing Basic Unit Error" << std::endl;
				return Result;
			}
			
			CurUnit = ReducedUnit;
		}
		
		Result->SetNameToValue();
		return Result;
	}

	BaseUnit* EqlUnit::Perform() {
		BaseUnit* CurUnit = this;
		SymbolUnit* Result = new SymbolUnit();

		while( CurUnit->GetNextUnit() != NULL) {
			SymbolUnit* ReducedUnit;
			ReducedUnit = (SymbolUnit*)Reduce(*CurUnit->GetNextUnit());

			switch ( ReducedUnit->GetUnitType() ) {
			case SymUnit:
				if (ReducedUnit->GetRetVal()->GetValType() == nonType) {
					std::cout << "Matching nonType Symbol Error" << std::endl;
				CurUnit = ReducedUnit;
					continue; }
				if (!Result->GetRetVal()->EqlValue(*ReducedUnit->GetRetVal()))
					std::cout << "Error Matching Value" << std::endl;
				break;
			case FunUnit:
				std::cout << "Matching Function Unit Error" << std::endl;
				return Result;
			case BasUnit:
				std::cout << "Matching Basic Unit Error" << std::endl;
				return Result;
			}
			
			CurUnit = ReducedUnit;
		}
		Result->GetRetVal()->SetValue(Result->GetRetVal()->GetBulValue());
		Result->SetNameToValue();
		return Result;
	}

	BaseUnit* GtrUnit::Perform() {
		BaseUnit* CurUnit = this;
		SymbolUnit* Result = new SymbolUnit();

		while( CurUnit->GetNextUnit() != NULL) {
			SymbolUnit* ReducedUnit;
			ReducedUnit = (SymbolUnit*)Reduce(*CurUnit->GetNextUnit());

			switch ( ReducedUnit->GetUnitType() ) {
			case SymUnit:
				if (ReducedUnit->GetRetVal()->GetValType() == nonType) {
					std::cout << "Comparing > nonType Symbol Error" << std::endl;
				CurUnit = ReducedUnit;
					continue; }
				if (!Result->GetRetVal()->GtrValue(*ReducedUnit->GetRetVal()))
					std::cout << "Error Comparing > Value" << std::endl;
				break;
			case FunUnit:
				std::cout << "Comparing > Function Unit Error" << std::endl;
				return Result;
			case BasUnit:
				std::cout << "Comparing > Basic Unit Error" << std::endl;
				return Result;
			}
			
			CurUnit = ReducedUnit;
		}
		Result->GetRetVal()->SetValType(bulType);
		Result->GetRetVal()->SetValue(Result->GetRetVal()->GetBulValue());
		Result->SetNameToValue();
		return Result;
	}

	BaseUnit* LesUnit::Perform() {
		BaseUnit* CurUnit = this;
		SymbolUnit* Result = new SymbolUnit();

		while( CurUnit->GetNextUnit() != NULL) {
			SymbolUnit* ReducedUnit;
			ReducedUnit = (SymbolUnit*)Reduce(*CurUnit->GetNextUnit());

			switch ( ReducedUnit->GetUnitType() ) {
			case SymUnit:
				if (ReducedUnit->GetRetVal()->GetValType() == nonType) {
					std::cout << "Comparing < nonType Symbol Error" << std::endl;
				CurUnit = ReducedUnit;
					continue; }
				if (!Result->GetRetVal()->LesValue(*ReducedUnit->GetRetVal()))
					std::cout << "Error Comparing < Value" << std::endl;
				break;
			case FunUnit:
				std::cout << "Comparing < Function Unit Error" << std::endl;
				return Result;
			case BasUnit:
				std::cout << "Comparing < Basic Unit Error" << std::endl;
				return Result;
			}
			
			CurUnit = ReducedUnit;
		}
		Result->GetRetVal()->SetValue(Result->GetRetVal()->GetBulValue());
		Result->SetNameToValue();
		return Result;
	}

	BaseUnit* LetUnit::Perform() {
		BaseUnit* CurUnit = this;
		BaseUnit* ArgList = CurUnit->GetNextUnit();
		BaseUnit* FuncList = ArgList->GetNextUnit();
		BaseUnit* Result = NULL;

		std::vector<std::string> list;

		//Gather Variable Arguments and Register
		if (ArgList != NULL) {
			ArgList = ArgList->GetDownUnit();
			while (ArgList != NULL) {
				SymbolUnit* RegUnit = (SymbolUnit*)ArgList->GetDownUnit();
				SymbolUnit* ValUnit = (SymbolUnit*)Reduce(*RegUnit->GetNextUnit());

				RegUnit->SetValue(*ValUnit->GetRetVal());

				RegisterUnit(RegUnit);
				list.push_back(RegUnit->GetName());

				ArgList = ArgList->GetNextUnit();
			}

			while (FuncList != NULL) {
				FuncList->SetDownUnit(*ReplaceSymbols(*FuncList->GetDownUnit()));

				BaseUnit* ReducedUnit = Reduce(*FuncList->GetDownUnit());
				
				Result = ReducedUnit;

				FuncList = FuncList->GetNextUnit();
			}
		}

		while (list.size() > 0) {
			RemoveUnit(list.front());
			list.erase(list.begin(), list.begin()+1);
		}

		return Result;
	}

	BaseUnit* LambdaUnit::Perform() {
		BaseUnit* CurUnit = this;
		BaseUnit* ArgList = CurUnit->GetNextUnit();
		BaseUnit* FuncList = ArgList->GetNextUnit();
		BaseUnit* Result = new FunctionUnit();

		Result->SetDownUnit(*FuncList);
		Result->GetDownUnit()->SetNextUnit(*ArgList->GetDownUnit());

		return Result;
	}

	BaseUnit* DefunUnit::Perform() {
		std::string FunName = this->GetNextUnit()->GetName();
		BaseUnit* RegUnit = NULL;
		LambdaUnit* LamUnit = new LambdaUnit();

		LamUnit->SetNextUnit(*this->GetNextUnit()->GetNextUnit());

		RegUnit = LamUnit->Perform();

		RegUnit->SetName(FunName);

		RegisterUnit(RegUnit);

		return RegUnit;
	}

	BaseUnit* IfThenUnit::Perform() {
		BaseUnit* Check = this->GetNextUnit();
		BaseUnit* IfTrue = Check->GetNextUnit();
		BaseUnit* IfFalse = NULL;
		BaseUnit* Result = NULL;

		if (IfTrue->GetNextUnit() != NULL)
			IfFalse = IfTrue->GetNextUnit();
		else
			IfFalse = new SymbolUnit("nil", retVal(false));

		// Reduce Check
		Check = Reduce(*Check);
		// If true, reduce IfTrue to Result
		// else false, reduce IfFalse to Result
		if (Check->GetUnitType() == SymUnit) {
			if ( ((SymbolUnit*)Check)->GetRetVal()->GetValType() == bulType) {
				if (((SymbolUnit*)Check)->GetRetVal()->GetBulValue() )
					Result = Reduce(*IfTrue);
				else
					Result = Reduce(*IfFalse);
			} else {
				Result = new SymbolUnit("nil", retVal(false));
			}
		}
		return Result;
	}

	BaseUnit* CondUnit::Perform() {
		BaseUnit* NextCheck = this;
		BaseUnit* Result = FindUnit("false");

		while (NextCheck->GetNextUnit() != NULL) {
			NextCheck = NextCheck->GetNextUnit();

			BaseUnit* eval = NextCheck->GetDownUnit();

			if (eval != NULL) {
				eval = Reduce(*eval);

				if (eval->GetUnitType() == SymUnit)
					if ( ((SymbolUnit*)eval)->GetRetVal()->GetValType() == bulType)
						if ( ((SymbolUnit*)eval)->GetRetVal()->GetBulValue() ) {
							Result = Reduce(*eval->GetNextUnit());
							break; } }
		}
		return Result;
	}

}