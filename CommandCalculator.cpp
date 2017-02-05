
#pragma warning (disable : 4786)
#include <iostream>
#include <map>
#include <vector>
using namespace std;
#include "Operations.h"
#include "CommandCalculator.h"


//************************************************************************************
// Calculator class is the class the user interacts with.
// Calculator supports operations such as Compute, Undo, Redo
// The "model" itself (what operations are available, information like current total etc)
//   is not implemented in this class, but rather in a helper, "docuement" like class, operations.
//   Class calculator only "manages" requests by forwarding them to its member, m_oper (the model
//	 above), and keeps track of executed commands (Operator *) in an Undo/Redo vector (m_undoList).
//   The separation to two management classes, Operations and Calculator, allows the Calculator
//   class to be a "thin client", that only manages Undo/Redo.
//************************************************************************************

	// Ctor
	Calculator::Calculator()
	{
			// STUDENT
	}
	// Compute forward the request to the m_oper "model" member. Gets a copy of the
	// executed command (Operator *) and saves it in the appropriate place in the
	// undo list.
	void Calculator::Compute(char pi_Operator , float pi_Operand)
	{
		Operator* oper = m_oper.Operate(pi_Operator, pi_Operand, true);
		m_undoList.push_back(oper);
	}

	// Undo the last level steps (one after the other)
	void Calculator::Undo(int levels)
	{
		cout << "****** Undo (" << levels << ") ******" << endl;

			// STUDENT
	}

	// Redo the last level steps (one after the other)
	void Calculator::Redo(int levels)
	{		
		cout << "****** Redo (" << levels << ") ******" << endl;

			// STUDENT
	}

void Calculator::registerOperator(char pi_Operator, Operator *OperatorCmd) {
	m_oper.Register (pi_Operator, OperatorCmd);
}


int main()
{

	Calculator calc;

	// Registration

	calc.registerOperator('+', new Plus());
	calc.registerOperator('-', new Minus());
	calc.registerOperator('*', new Multiply());
	calc.registerOperator('/', new Divide());
	


	calc.Compute('+' , 10);	
	calc.Compute('*' , 5);
	calc.Compute('-' , 19.5);
	calc.Compute('/' , 2);

	calc.Undo(2);
	calc.Undo(1);
	calc.Redo(3);
	calc.Redo(1);

	char c;
	cin >> c;

	return 0;
}