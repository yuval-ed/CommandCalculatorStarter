#ifndef _CALCULATOR_H
#define _CALCULATOR_H

#include <vector>

using namespace std;

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

class Calculator
{
	vector<Operator*> m_undoList;			// undo/redo list
	Operations m_oper;						// the model object
	int m_currentLevel;						// undo/redo stack pointer.

public:

	// Ctor
	Calculator();

	// Compute forward the request to the m_oper "model" member. Gets a copy of the
	// executed command (Operator *) and saves it in the appropriate place in the
	// undo list.
	void Compute(char pi_Operator , float pi_Operand);

	// Undo the last level steps (one after the other)
	void Undo(int levels);
	
	// Redo the last level steps (one after the other)
	void Redo(int levels);

	void registerOperator (char pi_Operator , Operator* pOperator);
};

#endif