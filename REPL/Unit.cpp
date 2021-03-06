#include "Unit.h"
#include "stdafx.h"

namespace REPL
{
	retVal::retVal(const retVal& copy) {
		iValue = copy.GetIntValue();
		dValue = copy.GetDubValue();
		sValue = copy.GetStrValue();
		bValue = copy.GetBulValue();
		thisType = copy.GetValType();
	}

	ValType retVal::GetValType() const {
		return thisType; }

	void retVal::SetValType(ValType vtype) {
		thisType = vtype; }



	int retVal::GetIntValue() const {
		return iValue; }

	double retVal::GetDubValue() const {
		return dValue; }

	std::string retVal::GetStrValue() const {
		return sValue; }

	bool retVal::GetBulValue() const {
		return bValue; }


	void retVal::SetValue(int val) {
		iValue = val;
		sValue = std::to_string((long long)val);
		SetValType(intType); }

	void retVal::SetValue(double val) {
		dValue = val;
		sValue = std::to_string((long double)val);
		SetValType(dubType); }

	void retVal::SetValue(std::string val) {
		sValue.assign(val.c_str());
		SetValType(strType); }

	void retVal::SetValue(bool val) {
		bValue = val;
		if (val)
			sValue = "true";
		else
			sValue = "false";
		SetValType(bulType); }


	bool retVal::AddValue(retVal val) {
		bool Result = false;

		switch (thisType) {
		case nonType:
			switch (val.GetValType()) {
			case intType:
				SetValue(val.GetIntValue());
				break;
			case dubType:
				SetValue(val.GetDubValue());
				break;
			case strType:
				SetValue(val.GetStrValue());
				break;
			case bulType:
				SetValue(val.GetBulValue());
				break;
			}
			break;

		case intType:
			switch (val.GetValType()) {
			case intType:
				SetValue(GetIntValue() + val.GetIntValue());
				break;
			case dubType:
				SetValue(GetIntValue() + (int)(val.GetDubValue()));
				break;
			case strType:
				return Result;
			case bulType:
				return Result;
			}
			break;

		case dubType:
			switch (val.GetValType()) {
			case intType:
				SetValue(GetDubValue() + (double)(val.GetIntValue()));
				break;
			case dubType:
				SetValue(GetDubValue() + val.GetDubValue());
				break;
			case strType:
				return Result;
			case bulType:
				return Result;
			}
			break;

		case strType:
			switch (val.GetValType()) {
			case intType:
				SetValue(GetStrValue() + std::to_string((long long)val.GetIntValue()));
				break;
			case dubType:
				SetValue(GetStrValue() + std::to_string((long double)val.GetDubValue()));
				break;
			case strType:
				SetValue(GetStrValue() + val.GetStrValue());
				break;
			case bulType:
				return Result;
			}
			break;

		case bulType:
			switch (val.GetValType()) {
			case intType:
				SetValue(true);
				break;
			case dubType:
				SetValue(true);
				break;
			case strType:
				SetValue(true);
				break;
			case bulType:
				SetValue(bValue + val.GetBulValue());
				break;
			}
			break;
		}

		return Result = true;
	}

	bool retVal::SubValue(retVal val) {
		bool Result = false;

		switch (thisType) {
		case nonType:
			{
				switch (val.GetValType()) {
				case intType:
					SetValue(val.GetIntValue());
					break;
				case dubType:
					SetValue(val.GetDubValue());
					break;
				case strType:
					return Result;
				case bulType:
					SetValue(false);
					break;
				}
			}
			break;

		case intType:
			{
				switch (val.GetValType()) {
				case intType:
					SetValue(GetIntValue() - val.GetIntValue());
					break;
				case dubType:
					SetValue(GetIntValue() - (int)(val.GetDubValue()));
					break;
				case strType:
					return Result;
				case bulType:
					return Result;
				}
			}
			break;

		case dubType:
			{
				switch (val.GetValType()) {
				case intType:
					SetValue(GetDubValue() - (double)(val.GetIntValue()));
					break;
				case dubType:
					SetValue(GetDubValue() - val.GetDubValue());
					break;
				case strType:
					return Result;
				case bulType:
					return Result;
				}
			}
			break;

		case strType:
			{
				std::string temp;
				switch (val.GetValType()) {
				case intType:
					temp = std::to_string((long long)val.GetIntValue());
					SetValue(GetStrValue().erase(GetStrValue().find( temp, 0), temp.length()));
					break;
				case dubType:
					temp = std::to_string((long double)val.GetDubValue());
					SetValue(GetStrValue().erase(GetStrValue().find( temp, 0), temp.length()));
					break;
				case strType:
					temp = val.GetStrValue();
					SetValue(GetStrValue().erase(GetStrValue().find( temp, 0), temp.length()));
					break;
				case bulType:
					return Result;
				}
			}
			break;

		case bulType:
			switch (val.GetValType()) {
			case intType:
				SetValue(false);
				break;
			case dubType:
				SetValue(false);
				break;
			case strType:
				SetValue(false);
				break;
			case bulType:
				SetValue(bValue - val.GetBulValue());
				break;
			}
			break;
		}

		return Result = true;
	}

	bool retVal::MulValue(retVal val) {
		bool Result = false;

		switch (thisType) {
		case nonType:
			{
				switch (val.GetValType()) {
				case intType:
					SetValue(val.GetIntValue());
					break;
				case dubType:
					SetValue(val.GetDubValue());
					break;
				case strType:
					return Result;
				case bulType:
					return Result;
				}
			}
			break;

		case intType:
			{
				switch (val.GetValType()) {
				case intType:
					SetValue(GetIntValue() * val.GetIntValue());
					break;
				case dubType:
					SetValue(GetIntValue() * (int)(val.GetDubValue()));
					break;
				case strType:
					return Result;
				case bulType:
					return Result;
				}
			}
			break;

		case dubType:
			{
				switch (val.GetValType()) {
				case intType:
					SetValue(GetDubValue() * (double)(val.GetIntValue()));
					break;
				case dubType:
					SetValue(GetDubValue() * val.GetDubValue());
					break;
				case strType:
					return Result;
				case bulType:
					return Result;
				}
			}
			break;

		case strType:
			{
				return Result;
			}
			break;

		case bulType:
			switch (val.GetValType()) {
			case bulType:
				SetValue(bValue * val.GetBulValue());
				break;
			default:
				return Result;
			}
			break;
		}

		return Result = true;
	}

	bool retVal::DivValue(retVal val) {
		bool Result = false;

		switch (thisType) {
		case nonType:
			{
				switch (val.GetValType()) {
				case intType:
					SetValue(val.GetIntValue());
					break;
				case dubType:
					SetValue(val.GetDubValue());
					break;
				case strType:
					return Result;
				case bulType:
					return Result;
				}
			}
			break;

		case intType:
			{
				switch (val.GetValType()) {
				case intType:
					SetValue(GetIntValue() / val.GetIntValue());
					break;
				case dubType:
					SetValue(GetIntValue() / (int)(val.GetDubValue()));
					break;
				case strType:
					return Result;
				case bulType:
					return Result;
				}
			}
			break;

		case dubType:
			{
				switch (val.GetValType()) {
				case intType:
					SetValue(GetDubValue() / (double)(val.GetIntValue()));
					break;
				case dubType:
					SetValue(GetDubValue() / val.GetDubValue());
					break;
				case strType:
					return Result;
				case bulType:
					return Result;
				}
			}
			break;

		case strType:
			{
				return Result;
			}
			break;

		case bulType:
			switch (val.GetValType()) {
			case bulType:
				SetValue(false);
				break;
			default:
				return Result;
			}
			break;
		}

		return Result = true;
	}


	bool retVal::EqlValue(retVal val) {
		bool Result = false;

		switch (thisType) {
		case nonType:
			{
				switch (val.GetValType()) {
				case intType:
					SetValue(true);
					SetValue(val.GetIntValue());
					break;
				case dubType:
					SetValue(true);
					SetValue(val.GetDubValue());
					break;
				case strType:
					SetValue(true);
					SetValue(val.GetStrValue());
					break;
				case bulType:
					SetValue((int)(val.GetBulValue()));
					SetValue(true);
					break;
				}
			}
			break;

		case intType:
			{
				switch (val.GetValType()) {
				case intType:
					if (GetBulValue()) {
						SetValue(GetIntValue() == val.GetIntValue());
						SetValue(val.GetIntValue()); }
					break;
				case dubType:
					if (GetBulValue()) {
						SetValue(GetIntValue() == (int)(val.GetDubValue()));
						SetValue(val.GetIntValue()); }
					break;
				case strType:
					SetValue(false);
					return Result;
				case bulType:
					SetValue(false);
					return Result;
				}
			}
			break;

		case dubType:
			{
				switch (val.GetValType()) {
				case intType:
					if (GetBulValue()) {
						SetValue(GetDubValue() == (double)(val.GetIntValue()));
						SetValue(val.GetIntValue()); }
					break;
				case dubType:
					if (GetBulValue()) {
						SetValue(GetDubValue() == val.GetIntValue());
						SetValue(val.GetIntValue()); }
					break;
				case strType:
					SetValue(false);
					return Result;
				case bulType:
					SetValue(false);
					return Result;
				}
			}
			break;

		case strType:
			{
				switch (val.GetValType()) {
				case intType:
					if (GetBulValue()) {
						SetValue(GetStrValue() == std::to_string((long long)val.GetIntValue()));
						SetValue(GetStrValue()); }
					break;
				case dubType:
					if (GetBulValue()) {
						SetValue(GetStrValue() == std::to_string((long double)val.GetDubValue()));
						SetValue(GetStrValue()); }
					break;
				case strType:
					if (GetBulValue()) {
						SetValue(GetStrValue() == val.GetStrValue());
						SetValue(val.GetStrValue()); }
					break;
				case bulType:
					SetValue(false);
					break;
				}
			}
			break;

		case bulType:
			switch (val.GetValType()) {
			case intType:
				if (GetBulValue()) {
					int match = GetIntValue();
					SetValue(val.GetIntValue());
					SetValue(match == GetIntValue()); }
				break;
			case bulType:
				if (GetBulValue()) {
					int match = GetIntValue();
					SetValue((int)(val.GetBulValue()));
					SetValue(match == GetIntValue()); }
				break;
			default:
				SetValue(false);
				return Result;
			}
			break;
		}

		return Result = true;
	}

	bool retVal::GtrValue(retVal val) {
		bool Result = false;

		switch (thisType) {
		case nonType:
			{
				switch (val.GetValType()) {
				case intType:
					SetValue(true);
					SetValue(val.GetIntValue());
					break;
				case dubType:
					SetValue(true);
					SetValue(val.GetDubValue());
					break;
				case strType:
					SetValue(true);
					SetValue(val.GetStrValue());
					break;
				case bulType:
					SetValue(false);
					break;
				}
			}
			break;

		case intType:
			{
				switch (val.GetValType()) {
				case intType:
					if (GetBulValue()) {
						SetValue(GetIntValue() > val.GetIntValue());
						SetValue(GetIntValue()); }
					break;
				case dubType:
					if (GetBulValue()) {
						SetValue(GetIntValue() > (int)(val.GetDubValue()));
						SetValue(GetIntValue()); }
					break;
				case strType:
					SetValue(false);
					return Result;
				case bulType:
					SetValue(false);
					return Result;
				}
			}
			break;

		case dubType:
			{
				switch (val.GetValType()) {
				case intType:
					if (GetBulValue()) {
						SetValue(GetDubValue() > (double)(val.GetIntValue()));
						SetValue(GetIntValue()); }
					break;
				case dubType:
					if (GetBulValue()) {
						SetValue(GetDubValue() > val.GetIntValue());
						SetValue(GetIntValue()); }
					break;
				case strType:
					SetValue(false);
					return Result;
				case bulType:
					SetValue(false);
					return Result;
				}
			}
			break;

		case strType:
			{
				switch (val.GetValType()) {
				case intType:
					if (GetBulValue()) {
						SetValue(GetStrValue() > std::to_string((long long)val.GetIntValue()));
						SetValue(GetStrValue()); }
					break;
				case dubType:
					if (GetBulValue()) {
						SetValue(GetStrValue() > std::to_string((long double)val.GetDubValue()));
						SetValue(GetStrValue()); }
					break;
				case strType:
					if (GetBulValue()) {
						SetValue(GetStrValue() > val.GetStrValue());
						SetValue(GetStrValue()); }
					break;
				case bulType:
					SetValue(false);
					break;
				}
			}
			break;

		case bulType:
			SetValue(false);
			return Result;
			break;
		}

		return Result = true;
	}


bool retVal::LesValue(retVal val) {
		bool Result = false;

		switch (thisType) {
		case nonType:
			{
				switch (val.GetValType()) {
				case intType:
					SetValue(true);
					SetValue(val.GetIntValue());
					break;
				case dubType:
					SetValue(true);
					SetValue(val.GetDubValue());
					break;
				case strType:
					SetValue(true);
					SetValue(val.GetStrValue());
					break;
				case bulType:
					SetValue(false);
					break;
				}
			}
			break;

		case intType:
			{
				switch (val.GetValType()) {
				case intType:
					if (GetBulValue()) {
						SetValue(GetIntValue() < val.GetIntValue());
						SetValue(GetIntValue()); }
					break;
				case dubType:
					if (GetBulValue()) {
						SetValue(GetIntValue() < (int)(val.GetDubValue()));
						SetValue(GetIntValue()); }
					break;
				case strType:
					SetValue(false);
					return Result;
				case bulType:
					SetValue(false);
					return Result;
				}
			}
			break;

		case dubType:
			{
				switch (val.GetValType()) {
				case intType:
					if (GetBulValue()) {
						SetValue(GetDubValue() < (double)(val.GetIntValue()));
						SetValue(GetIntValue()); }
					break;
				case dubType:
					if (GetBulValue()) {
						SetValue(GetDubValue() < val.GetIntValue());
						SetValue(GetIntValue()); }
					break;
				case strType:
					SetValue(false);
					return Result;
				case bulType:
					SetValue(false);
					return Result;
				}
			}
			break;

		case strType:
			{
				switch (val.GetValType()) {
				case intType:
					if (GetBulValue()) {
						SetValue(GetStrValue() < std::to_string((long long)val.GetIntValue()));
						SetValue(GetStrValue()); }
					break;
				case dubType:
					if (GetBulValue()) {
						SetValue(GetStrValue() < std::to_string((long double)val.GetDubValue()));
						SetValue(GetStrValue()); }
					break;
				case strType:
					if (GetBulValue()) {
						SetValue(GetStrValue() < val.GetStrValue());
						SetValue(GetStrValue()); }
					break;
				case bulType:
					SetValue(false);
					break;
				}
			}
			break;

		case bulType:
				SetValue(false);
				return Result;
			break;
		}

		return Result = true;
	}


	std::string BaseUnit::GetName() const {
		return name; }

	void BaseUnit::SetName(std::string name_param) {
		name.assign(name_param.c_str()); }





	BaseUnit* BaseUnit::GetNextUnit() const {
		return NextUnit; }

	BaseUnit* BaseUnit::GetDownUnit() const {
		return DownUnit; }
	
	void BaseUnit::SetNextUnit(BaseUnit& Unit_param) {
		NextUnit = &Unit_param; }

	void BaseUnit::SetDownUnit(BaseUnit& Unit_param) {
		DownUnit = &Unit_param; }

	UnitType BaseUnit::GetUnitType() {
		return tpUnit; }


	std::string BaseUnit::GetStructString() {
		std::string Result;

		//Build text from data structure

		return Result;
	}

	BaseUnit::BaseUnit()
		:DownUnit(NULL), NextUnit(NULL), tpUnit(BasUnit) {
	}

	BaseUnit::BaseUnit(const BaseUnit& copy) {
		SetName(copy.GetName());

		SetDownUnit(*copy.GetDownUnit());
		tpUnit = BasUnit;
	}


	retVal* SymbolUnit::GetRetVal() {
		return &value; }

	retVal SymbolUnit::GetRetValConst() const {
		return value; }

	void SymbolUnit::SetValue(retVal value_param) {
		value = value_param;
		}

	void SymbolUnit::SetNameToValue() {
		if ( value.GetValType() == intType) {
			SetName(std::to_string((long long)value.GetIntValue()));
		} else { if ( value.GetValType() == dubType) {
			SetName(std::to_string((long long)value.GetDubValue()));
		} else { if ( value.GetValType() == strType) {
			SetName(value.GetStrValue());
		} else { if ( value.GetValType() == bulType) {
			if (value.GetBulValue())
				SetName("true");
			else
				SetName("false"); }
		} } }
	}
	
	SymbolUnit::SymbolUnit(std::string name_val, retVal val) {
		SetName(name_val);
		SetValue(val);
		tpUnit = SymUnit; }

	SymbolUnit::SymbolUnit(const SymbolUnit& copy) {
		SetName(copy.GetName());
		SetValue(copy.GetRetValConst());
		tpUnit = SymUnit; }


	BaseUnit* FunctionUnit::Perform() {
		BaseUnit* Result = NULL;
		BaseUnit* Param = this->GetNextUnit();
		BaseUnit* Args  = this->GetDownUnit()->GetNextUnit();
		BaseUnit* func  = this->GetDownUnit();
		
		std::vector<std::string> list;

		// Review Arguments, pair with defined argument names
		while (Args != NULL && Param != NULL) {
			SymbolUnit* RegUnit = (SymbolUnit*)Args;
			SymbolUnit* ValUnit = (SymbolUnit*)Reduce(*Param);

			RegUnit->SetValue(*ValUnit->GetRetVal());

			RegisterUnit(RegUnit);
			list.push_back(RegUnit->GetName());

			Args = Args->GetNextUnit();
			Param = Param->GetNextUnit();
		}

		if (Args != NULL)
			std::cout << "Not Enough provided Parameters" << std::endl;

		if (Param != NULL)
			std::cout << "Too many provided Parameters" << std::endl;

		// Replace function definition units of arguments with paired values
		func = ReplaceSymbols(*func);

		// Reduce
		Result = Reduce(*func);
		
		while (list.size() > 0) {
			RemoveUnit(list.front());
			list.erase(list.begin(), list.begin()+1);
		}

		return Result;
	}

	FunctionUnit::FunctionUnit(const FunctionUnit& copy)
	{
		SetName(copy.GetName());
		SetDownUnit(*copy.GetDownUnit());
		SetNextUnit(*copy.GetNextUnit());
		tpUnit = FunUnit;
	}
}