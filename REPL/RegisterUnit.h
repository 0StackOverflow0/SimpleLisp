#include "stdafx.h"

#ifndef _RegisterUnit
#define _RegisterUnit

namespace REPL {
	
	static std::unordered_multimap<std::string, BaseUnit*> REPLWorld;

	void RegisterSpecialUnits();

	void RegisterUnit(BaseUnit*);

	void RemoveUnit(const std::string);

	REPL::BaseUnit* FindUnit(const std::string);
}

#endif //_RegisterUnit