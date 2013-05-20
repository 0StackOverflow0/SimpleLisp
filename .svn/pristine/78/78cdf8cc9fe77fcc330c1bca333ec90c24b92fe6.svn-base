#include "stdafx.h"
#include "GetSymbols.h"
#include <sstream>

#ifndef _GetSymbols
#define _GetSymbols

namespace REPL {

	REPL::BaseUnit* GetSymbols(std::string input) {
		REPL::BaseUnit* Result = NULL;
		BaseUnit* TempUnit = NULL;
		BaseUnit* PrevUnit = NULL;


		// Remove Paranthesis from input
		size_t RemoveOpen = input.find('(', 0), RemoveClose = input.find(')', 0);

		while (RemoveOpen != std::string::npos) {
			input.erase(RemoveOpen, 1);
			RemoveOpen = input.find('(', 0); }
		while (RemoveClose != std::string::npos) {
			input.erase(RemoveClose, 1);
			RemoveClose = input.find(')', 0); }

		
		// Tokenize input, put tokens in vector
		std::stringstream tokenize(input);
		std::string StrtoSymbol;

		std::vector<std::string> names;

		while (!tokenize.eof()) {
			char nameBuffer[256];
			tokenize.getline(nameBuffer, 255, ' ');
			if (nameBuffer[0] != 0)
				names.push_back(std::string(nameBuffer));
		}

		// Resolve each token, build a result structure
		while (names.size() != 0) {

			StrtoSymbol = names.front();

			// Check if already in Hash Table
			TempUnit = FindUnit(StrtoSymbol);
			if (TempUnit != NULL) {
				if (Result == NULL) {
					Result = TempUnit;
				} else {
					PrevUnit->SetNextUnit(*TempUnit);
				}
				PrevUnit = TempUnit;
				names.erase(names.begin(), names.begin()+1);
				continue; }

			// Check if either an int or double
			std::stringstream toNumber(StrtoSymbol);

			double tryDouble = -1E-20, intToDub;
			int tryInt = INT_MAX;
			toNumber >> tryInt;
			toNumber.clear();
			toNumber.str(StrtoSymbol);
			toNumber >> tryDouble;

			intToDub = (double)tryInt;
			if (intToDub != tryDouble) {
				if (tryDouble != -1E-20) {
					TempUnit = new SymbolUnit();
					TempUnit->SetName(StrtoSymbol);
					((SymbolUnit*)TempUnit)->SetValue(retVal(tryDouble));
					RegisterUnit(TempUnit);

					if (Result == NULL) {
						Result = TempUnit;
					} else {
						PrevUnit->SetNextUnit(*TempUnit);
					}

					PrevUnit = TempUnit;
					names.erase(names.begin(), names.begin()+1);
					continue; }
			} else {
				if (tryInt != INT_MAX) {
					TempUnit = new SymbolUnit();
					TempUnit->SetName(StrtoSymbol);
					((SymbolUnit*)TempUnit)->SetValue(retVal(tryInt));
					RegisterUnit(TempUnit);

					if (Result == NULL) {
						Result = TempUnit;
					} else {
						PrevUnit->SetNextUnit(*TempUnit);
					}

					PrevUnit = TempUnit;
					
					names.erase(names.begin(), names.begin()+1);
					continue; }
			}

			// Check if token is a string
			size_t pos_first, pos_second;
			pos_first = StrtoSymbol.find('"', 0);
			pos_second = StrtoSymbol.find('"', pos_first+1);

			if ( pos_second != std::string::npos ) {
				TempUnit = new SymbolUnit();
				((SymbolUnit*)TempUnit)->SetValue(retVal(StrtoSymbol));
				RegisterUnit(TempUnit);
				if (Result == NULL) {
					Result = TempUnit;
				} else {
					PrevUnit->SetNextUnit(*TempUnit);
				}

				PrevUnit = TempUnit;
				
				names.erase(names.begin(), names.begin()+1);
				continue; }

			// If nothing is found, create a placeholder
			TempUnit = new SymbolUnit(StrtoSymbol, retVal());
			if (Result == NULL) {
				Result = TempUnit;
			} else {
				PrevUnit->SetNextUnit(*TempUnit);
			}

			PrevUnit = TempUnit;
			names.erase(names.begin(), names.begin()+1);
		}

		return Result;
	}
}

#endif //_GetSymbols