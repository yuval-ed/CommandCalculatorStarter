#pragma warning (disable : 4786)
#include <iostream>
using namespace std;

#include "Operations.h"

//************************************************************************************
// class Operations: The Model/Document class
//************************************************************************************
Operations::Operations(): m_total(0.0)
{
	m_op.clear();
}

Operator* Operations::Operate(char pi_Operator , float pi_Operand , bool pi_bUndoable)
{
	map<char,Operator*>::iterator it = m_op.find (pi_Operator);
	if (it!=m_op.end())
	{
		Operator* oper = it->second;
		oper->exec (m_total, pi_Operand);
		if (pi_bUndoable)
			return oper;
	}

	return 0;
}


// getters and setters for the total variable
float Operations::getTotal() {
	return m_total;
}
void Operations::setTotal(float total){
	m_total = total;
}

void Operations::Register (char pi_operator, Operator* operatorCmd)
{
	m_op.insert (make_pair (pi_operator, operatorCmd));
}
//************************************************************************************
// Class Operator: Base class to all Operator Commands.
//************************************************************************************


//************************************************************************************
// Class Plus: implementation of the Plus Operator.
//************************************************************************************


	/////////////////////////////////////////////
	//STUDENT - complete
	/////////////////////////////////////////////

//************************************************************************************
// Class Minus: implementation of the Minus Operator.
//************************************************************************************


	/////////////////////////////////////////////
	//STUDENT - complete
	/////////////////////////////////////////////

//************************************************************************************
// Class Multiply: implementation of the Multiply Operator.
//************************************************************************************
	
	/////////////////////////////////////////////
	//STUDENT - complete
	/////////////////////////////////////////////

//************************************************************************************
// Class Divide: implementation of the Divide Operator.
//************************************************************************************

	/////////////////////////////////////////////
	//STUDENT - complete
	/////////////////////////////////////////////
	float Minus::exec(float lOperand, float rOperand) {
		return lOperand - rOperand;
	}

Operator *Minus::Clone() {
	return nullptr;
}
