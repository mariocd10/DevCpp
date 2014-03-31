#ifndef LONGINT_H
#define LONGINT_H

using namespace std;

class LongInt{
	private:
		char sign;
	public:
		List list;
		void Initialize(string S); //Initializes the Long Integer using a String S, which contains a number. S�scharacters are guaranteed to be digits, except the first character which may be a minus character.
		//Get and set the sign of the Long Integer
		void getSign();
		void setSign(char S);
		int getDigitCount();// Returns the total number of digits in the Long Integer
		void Print();// Prints the Long Integer to standard output. The output format is defined as a sequence of digit characters. The first character may be a minus.
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
