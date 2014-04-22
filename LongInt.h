#ifndef LONGINT_H
#define LONGINT_H

#include "List.h"

using namespace std;

class LongInt{
	private:
		bool sign;
		void stripz(string s);
		int digits(int t);
		bool greater(LongInt Q);
		List list;
	public:
		
		LongInt(){};
		~LongInt(){};
		int overFlow(int &T);
		void Initialize(string S); //Initializes the Long Integer using a String S, which contains a number. S�scharacters are guaranteed to be digits, except the first character which may be a minus character.
		//Get and set the sign of the Long Integer
		bool getSign();
		void setSign(bool S);
		int getDigitCount();// Returns the total number of digits in the Long Integer
		string Print();// Prints the Long Integer to standard output. The output format is defined as a sequence of digit characters. The first character may be a minus.
		//Determines if the Long Integer is greater than, less than, or equal to Q, respectively
		bool greaterThan(LongInt Q);
		bool lessThan(LongInt Q);
		bool equalTo(LongInt Q);
		LongInt add(LongInt Q);//Adds Q to the Long Integer and returns the result
		LongInt subtract(LongInt Q); //Subtracts Q from the Long Integer and returns the result
		LongInt multiply(LongInt Q);// Multiplies the Long Integer by Q and returns the result
		LongInt power(int p); //Raises the Long Integer to the power p and returns the result. NOTE: p is a normal integer.
		LongInt divide(LongInt Q); //Divides the Long Integer by Q and returns the quotient portion of the result
};

#endif



