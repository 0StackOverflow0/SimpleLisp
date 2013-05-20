#include "stdafx.h"
#include "RegisterUnit.h"

namespace REPL {

	// Replace symbols in a structure with current world values
	BaseUnit* ReplaceSymbols(BaseUnit& unit_param) {
		BaseUnit* pSymbols = &unit_param;
		BaseUnit* TempUnit = NULL;
		BaseUnit* rSymbols = NULL;
		BaseUnit* Result   = NULL;
		while (pSymbols != NULL) {
			TempUnit = FindUnit(pSymbols->GetName());

			if (TempUnit == NULL)
				TempUnit = pSymbols;

			if (TempUnit->GetUnitType() == BasUnit)
				TempUnit->SetDownUnit(*ReplaceSymbols(*TempUnit->GetDownUnit()));
			
			if (rSymbols == NULL) {
				rSymbols = TempUnit;
				Result = TempUnit;
			} else {
				rSymbols->SetNextUnit(*TempUnit);
				rSymbols = rSymbols->GetNextUnit();
			}

			pSymbols = pSymbols->GetNextUnit();
		}
		return Result;
	}
}