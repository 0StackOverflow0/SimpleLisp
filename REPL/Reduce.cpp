#include "Reduce.h"
#include "stdafx.h"

namespace REPL
{
	BaseUnit* Reduce(BaseUnit& Unit_Param) {
		BaseUnit* Next = Unit_Param.GetNextUnit();
		BaseUnit* Result = &Unit_Param;

		switch ( Unit_Param.GetUnitType() ) {
			case SymUnit:
				// Keep Unit_Param as Result
				break;
			case FunUnit:
				Result = ((FunctionUnit*)Result)->Perform();
				break;
			case AddUnit_:
				Result = ((AddUnit*)Result)->Perform();
				break;
			case SubUnit_:
				Result = ((SubUnit*)Result)->Perform();
				break;
			case MulUnit_:
				Result = ((MulUnit*)Result)->Perform();
				break;
			case DivUnit_:
				Result = ((DivUnit*)Result)->Perform();
				break;
			case EqlUnit_:
				Result = ((EqlUnit*)Result)->Perform();
				break;
			case GtrUnit_:
				Result = ((GtrUnit*)Result)->Perform();
				break;
			case LesUnit_:
				Result = ((LesUnit*)Result)->Perform();
				break;
			case LetUnit_:
				Result = ((LetUnit*)Result)->Perform();
				break;
			case DfnUnit_:
				Result = ((DefunUnit*)Result)->Perform();
				break;
			case BasUnit:
				if (Unit_Param.GetDownUnit() == NULL)
					return &Unit_Param;

				Result = Reduce(*(Unit_Param.GetDownUnit()));

				if (Result == NULL)
					return &Unit_Param;

				if (Result->GetUnitType() == FunUnit) {
					Result->SetNextUnit(*Unit_Param.GetNextUnit());
					Result = Reduce(*Result);
				}
				break;
		}
		
		Result->SetNextUnit(*Next);
		return Result;
	}
}