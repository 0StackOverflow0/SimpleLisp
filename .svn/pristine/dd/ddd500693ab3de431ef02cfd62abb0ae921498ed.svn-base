// REPL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GetSymbols.h"
#include <memory>

#define GetSymString(unit) ((REPL::SymbolUnit*)unit)->GetRetVal()->GetStrValue()

int _tmain(int argc, _TCHAR* argv[])
{
	std::string initial;
	REPL::BaseUnit* result;

	REPL::RegisterSpecialUnits();

	while(1)
	{
		getline(std::cin, initial);

		if (initial == "quit")
			return 1;

		if (initial == "")
			continue;

		// Parse input into symbol structure
		result = REPL::deduce(initial);
		// Reduce symbol structure
		result = REPL::Reduce(*result);

		//Find Suitable Output
		if ((result)->GetUnitType() == REPL::SymUnit)
			std::cout << GetSymString(result) << std::endl;
		else if (result->GetUnitType() == REPL::FunUnit)
			std::cout << result->GetName() << std::endl;
		else
			std::cout << result->GetStructString() << std::endl;
	}

	return 0;
}
