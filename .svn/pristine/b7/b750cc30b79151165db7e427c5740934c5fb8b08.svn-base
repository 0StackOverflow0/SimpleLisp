#include "stdafx.h"

#define SetRetVal(unit, value) ((SymbolUnit*)unit)->GetRetVal()->SetValue(value);

namespace REPL {
	REPL::BaseUnit* deduce(const std::string& prog)
	{
		std::vector<size_t> OpenParam;
		std::vector<size_t> CloseParam;
		std::string result = "";

		BaseUnit* Result = new REPL::SymbolUnit();

	
		if (( *(prog.begin()) != '(') && ( *(prog.end()-1) != ')')) {
			SetRetVal(Result, "Statement MUST begin with '(' and end with ')'");
			return Result;
		}

		for( size_t idx = 0; idx < prog.length(); ++idx) {
			switch( prog[idx] ) {
			case '(':
				OpenParam.push_back(idx);
				break;
			case ')':
				CloseParam.push_back(idx);
				break;
			}
		}

		if (OpenParam.size() > CloseParam.size()) {
			SetRetVal(Result, "')' Expected");
			return Result; }
		if (OpenParam.size() < CloseParam.size()) {
			SetRetVal(Result, "Too many ')'");
			return Result; }

		std::vector<std::vector<size_t>> FirstOrderParam;

		for (size_t idx = 1, low_pair = 0; idx < OpenParam.size(); ++idx) {
			std::vector<size_t> pair;
			pair.push_back(OpenParam[idx]);
			for(size_t idx_c = 0; idx_c + low_pair < CloseParam.size() - 1; ++idx_c) {
				if ( (idx + idx_c + 1) < OpenParam.size()) {
					if ( CloseParam[idx_c + low_pair] < OpenParam[idx + idx_c + 1]) {
						pair.push_back(CloseParam[idx_c + low_pair]);
						FirstOrderParam.push_back(pair);
						low_pair += idx_c + 1;
						idx += idx_c;
						break;
					}
				} else {
					pair.push_back(CloseParam[idx_c + low_pair]);
					FirstOrderParam.push_back(pair);
					low_pair += idx_c + 1;
					idx += idx_c;
					break;
				}
			}
		}
	
		REPL::BaseUnit* symbols = new REPL::BaseUnit();

		//Get Symbols before each first order param + Reduce First order param
		size_t last_pos = 1;
		for (size_t idx = 0; idx < FirstOrderParam.size(); ++idx) {
			size_t length = FirstOrderParam[idx].front() - last_pos;
			REPL::BaseUnit* fetch_symbol = REPL::GetSymbols(prog.substr( last_pos, length));
			last_pos = FirstOrderParam[idx].back();
			if (fetch_symbol != NULL) {
				if (idx == 0)
					symbols->SetDownUnit(*fetch_symbol);
				else {
					REPL::BaseUnit* Temp = symbols->GetDownUnit();
					while( Temp->GetNextUnit() != NULL)
						Temp = Temp->GetNextUnit();
					Temp->SetNextUnit(*fetch_symbol);
				}
			}

			size_t start = FirstOrderParam[idx].front();
			length = FirstOrderParam[idx].back() - FirstOrderParam[idx].front() + 1;
			fetch_symbol = deduce(prog.substr(start, length));
			if (fetch_symbol != NULL) {
				if (symbols->GetDownUnit() == NULL)
					symbols->SetDownUnit(*fetch_symbol);
				else {
					REPL::BaseUnit* Temp = symbols->GetDownUnit();
					while( Temp->GetNextUnit() != NULL)
						Temp = Temp->GetNextUnit();
					Temp->SetNextUnit(*fetch_symbol);
				}
			}
		} 
		//Also check after the last First Order Param
		{
			size_t length = prog.length() - last_pos - 1;
			REPL::BaseUnit* fetch_symbol = REPL::GetSymbols(prog.substr(last_pos, length));
			if (fetch_symbol != NULL) {
				if (symbols->GetDownUnit() == NULL)
					symbols->SetDownUnit(*fetch_symbol);
				else {
					REPL::BaseUnit* Temp = symbols->GetDownUnit();
					while( Temp->GetNextUnit() != NULL)
						Temp = Temp->GetNextUnit();
					Temp->SetNextUnit(*fetch_symbol); } }
		} 

		delete Result;
		Result = NULL;

//		Result = REPL::Reduce(*symbols);

//		delete symbols;

		return symbols;
	}
}