#include "stdafx.h"
#include <string>

#ifndef _Unit
#define _Unit

namespace REPL
{
	enum ValType {
		nonType,
		intType,
		dubType,
		strType,
		bulType
	};

	enum UnitType {
		BasUnit,
		SymUnit,
		FunUnit,
		AddUnit_,
		SubUnit_,
		MulUnit_,
		DivUnit_,
		EqlUnit_,
		GtrUnit_,
		LesUnit_,
		LetUnit_,
		LamUnit_,
		DfnUnit_,
		IfUnit_,
		CondUnit_
	};

	class BaseUnit
	{
	protected:
		std::string name;
		UnitType tpUnit;
		BaseUnit* DownUnit;
		BaseUnit* NextUnit;

	public:
		std::string GetName() const;
		BaseUnit* GetNextUnit() const;
		BaseUnit* GetDownUnit() const;
		UnitType GetUnitType();
		void SetName(std::string);
		void SetNextUnit(BaseUnit&);
		void SetDownUnit(BaseUnit&);

		std::string GetStructString();

		BaseUnit ();
		BaseUnit (std::string name_param): name(name_param) { BaseUnit(); }
		BaseUnit (const BaseUnit&);
	};

	struct retVal {
		int iValue;
		double dValue;
		std::string sValue;
		bool bValue;
		ValType thisType;

		ValType GetValType() const;
		int GetIntValue() const;
		double GetDubValue() const;
		std::string GetStrValue() const;
		bool GetBulValue() const;
		
		void SetValType(ValType);
		void SetValue(int);
		void SetValue(double);
		void SetValue(std::string);
		void SetValue(bool);

		retVal (): thisType(nonType) { }
		retVal (const retVal&);

		retVal (int val)		{ SetValue(val); }
		retVal (double val)		{ SetValue(val); }
		retVal (std::string val){ SetValue(val); }
		retVal (bool val)		{ SetValue(val); }

		bool AddValue(retVal);
		bool SubValue(retVal);
		bool MulValue(retVal);
		bool DivValue(retVal);

		bool EqlValue(retVal);
		bool GtrValue(retVal);
		bool LesValue(retVal);
	};

	class SymbolUnit: public BaseUnit
	{
	private:
		retVal value;

	public:
		retVal* GetRetVal();
		retVal GetRetValConst() const;
		void SetValue(retVal);
		void SetNameToValue();

		SymbolUnit () { tpUnit = SymUnit; };
		SymbolUnit (const std::string, const retVal);
		SymbolUnit (const SymbolUnit&);
	};

	class FunctionUnit: public SymbolUnit
	{
	private:
	public:
		virtual BaseUnit* Perform();

		FunctionUnit () { tpUnit = FunUnit; }
		FunctionUnit (const FunctionUnit&);
	};
}

#endif //_Unit