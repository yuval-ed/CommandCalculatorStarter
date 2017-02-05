#ifndef _OPER_H
#define _OPER_H

#pragma warning (disable : 4786)
#include <map>
using namespace std;

class Operator;

//************************************************************************************
// class Operations: The Model/Document class
// Keeps the needed data (such as the current total, m_total) for the model
// Keeps a prototype/map of available Operators in the system.
// Main method: Operate.
//************************************************************************************

class Operations {
private:

	map<char,Operator*> m_op;			// a pool of all possible Operators, registered
									    // by their sign ('+','-','%' etc)
	float m_total;						// the current total in the calculator
	
public:
	Operations();

	
	// getters and setters for the total variable
	float getTotal();
	void setTotal(float total);
	

	// Operate: recieves the sign of the operator (+,- etc), the operand, and a boolean
	// indicating if the operator is Undoable or not.
	// Should find and execute the appropriate Operator, and return its (the operator
	// command object) copy as a result.
	Operator* Operate(char pi_Operator , float pi_Operand , bool pi_bUndoable);
	void Register (char pi_Operator, Operator* operatorCmd);
};

//************************************************************************************
// Class Operator: Base class to all Operator Commands.
// Supports Execute  and UnExecute virtual methods.
// Supports a Clone method so that an operator can be copied in a polymorphic  way.
//************************************************************************************


class Operator
{
	/////////////////////////////////////////////
	//STUDENT - add methods and members as needed
	/////////////////////////////////////////////

public:

	// Clone returns a copy of the Operator object.
	virtual Operator* Clone() = 0;
	virtual float exec(float lOperand, float rOperand) = 0;


};
//************************************************************************************
// Class Plus: implementation of the Plus Operator.
//************************************************************************************
class Plus : public Operator
{
	/////////////////////////////////////////////
	//STUDENT - add methods and members as needed
	/////////////////////////////////////////////

public:

	virtual float exec(float lOperand, float rOperand);

	virtual Operator* Clone();
};

//************************************************************************************
// Class Minus: implementation of the Minus Operator.
//************************************************************************************
class Minus : public Operator
{
	/////////////////////////////////////////////
	//STUDENT - add methods and members as needed
	/////////////////////////////////////////////

public:


	virtual float exec(float lOperand, float rOperand);
	virtual Operator* Clone();
};

//************************************************************************************
// Class Multiply: implementation of the Multiply Operator.
//************************************************************************************
class Multiply : public Operator
{
	/////////////////////////////////////////////
	//STUDENT - add methods and members as needed
	/////////////////////////////////////////////

public:

	virtual float exec(float lOperand, float rOperand);

	virtual Operator* Clone();
};
//************************************************************************************
// Class Divide: implementation of the Divide Operator.
//************************************************************************************
class Divide : public Operator
{
	/////////////////////////////////////////////
	//STUDENT - add methods and members as needed
	/////////////////////////////////////////////

public:

	virtual float exec(float lOperand, float rOperand);
	virtual Operator* Clone();
};



#endif