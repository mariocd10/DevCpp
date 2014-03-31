#include <iostream>
#include "LongInt.h"
#include "List.h"

using namespace std;

int main(){
	long num = 123;
	List myList;
	myList.createNode(num);
	myList.traverse();
	return 0;
}

//Initializes the Long Integer using a String S, which contains a number. S’scharacters are guaranteed to be digits, except the first character which may be a minus character.
void LongInt::Initialize(string S){
	long num = 123;
	cout<<"This works so far";
	return;
}
//Get and set the sign of the Long Integer
void LongInt::getSign(){
}
void LongInt::setSign(char S){
}
// Returns the total number of digits in the Long Integer
int LongInt::getDigitCount(){
}
// Prints the Long Integer to standard output. The output format is defined as a sequence of digit characters. The first character may be a minus.
void LongInt::Print(){
}
//Determines if the Long Integer is greater than, less than, or equal to Q, respectively
bool LongInt::greaterThan(LongInt Q){
};
bool LongInt::lessThan(LongInt Q){
};
bool LongInt::equalTo(LongInt Q){
};
//Adds Q to the Long Integer and returns the result
LongInt LongInt::add(LongInt Q){
	 // TODO: Handle addition when signs are different

	 node* r1, *r2;

	 List a = this.list;
	 List b = q.list;

	 r1 = a.getLast();
	 r2 = b.getLast();

	 LongInt result; // Create an empty LongInt to store result in
	 List c = result.list;

	 int addValue = r1.value + r2.value;
	 int carry = overflow(addValue); // Enforce 4 digit rule

	 c.insertLeft(addValue);

	 while(!a.isFirst(r1) && !b.isFirst(r2)) {
	 r1 = a.nextLeft(r1);
	 r2 = b.nextLeft(r2);

	 addValue = r1.value + r2.value + carry;
	carry = overflow(addValue); // Enforce 4 digit rule
	 c.insertLeft(addValue);
	 }

	 // TODO: finish adding the remaining digits from either this LongInt or Q, plus any overflow

	 return result;
};
 //Subtracts Q from the Long Integer and returns the result
LongInt LongInt::subtract(LongInt Q){
};
// Multiplies the Long Integer by Q and returns the result
LongInt LongInt::multiply(LongInt Q){
};
//Raises the Long Integer to the power p and returns the result. NOTE: p is a normal integer.
LongInt LongInt::power(int p){
};
 //Divides the Long Integer by Q and returns the quotient portion of the result
LongInt LongInt::divide(LongInt Q){
};
