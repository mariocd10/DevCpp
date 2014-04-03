#include <iostream>
#include <stdlib.h>

#include "LongInt.h"
#include "List.h"

#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     // atol


//Initializes the Long Integer using a String S, which contains a number. S’scharacters are guaranteed to be digits, except the first character which may be a minus character.
void LongInt::Initialize(string S){
	List myList;
	//initialize our sign private var to the first element of the string

	LongInt::sign = S[0];
	S.erase(S.begin());
	//traverse through string without the sign char
	int i = S.length();
	while(i>0)
  	{
			//a check to make sure S.length()-i doesn't go out of bounds
			if(i>3){
				//grabbing the last 4 digits from the right
				string str = S.substr(i-4,4);
				//stripping the leading zero's
				for(int i=0; i<str.length(); ++i){
					if(str[i]!='0'){
						int index = str.length()-i;
						str.substr(i,index);
					}
				}
				//converting string to long value
				int value = atoi(str.c_str());
				//insert into list
				myList.insertLeft(value);

				i=i-4;
			}
			//when there are 4 digits from the right, grab those 4 digits
			else{
                string str = S.substr(0,i);
            	//stripping the leading zero's
				for(int i=0; i<str.length(); ++i){
					if(str[i]!='0'){
						string lennum = str.length()-i;
						str.substr(i,lennum);
						break;
					}
				}
            	int value = atoi(str.c_str());
            	myList.insertLeft(value);
            	break;
			}
  	}
  	//Assigning the newly created List to the private var list
  	LongInt::list = myList;
  	return;
}

//Get and set the sign of the Long Integer
return LongInt::getSign(){
	return this.sign;
}
void LongInt::setSign(char S){
	LongInt::sign = S;
}
/*
// Returns the total number of digits in the Long Integer
int LongInt::getDigitCount(){
	node *tmp;
	int digits=0;
	tmp = myList.getFirst();
	//count digits of each node
	while(tmp!=NULL){
		number = tmp->data;
		//TODO: handle the numbers with the leading zero's stripped. they must still be accounted for.
		long num = number;
		while(num>0){
			num /= 10;
			digits++;
		}
		tmp = myList.nextRight(tmp);
	}
	return digits;
}
// Prints the Long Integer to standard output. The output format is defined as a sequence of digit characters. The first character may be a minus.
void LongInt::Print(){
	List a = this.list;
	a.traverse();
}
//Determines if the Long Integer is greater than, less than, or equal to Q, respectively
bool LongInt::greaterThan(LongInt Q){
	List a = this.list;
	List b = Q.list;
	
	if(getSign() == 'p' && Q.getSign() == 'n'){
		return true;
	}
	if(getSign() == 'n' && Q.getSign() == 'p'){
		return false;
	}
	if(digits() > Q.digits()){
		return true;
	}
	if(Q.digits() > digits()){
		return false;
	}
	if(getSign() == 'p' && Q.getSign() == 'p'){
		node *tmpa = a.getFirst();
		node *tmpb = b.getFirst();
		//iterate through list a and b
		while(tmpa!=NULL && tmpb!=NULL){
			if(tmpa->data < tmpb->data){
				return true;
			}
			if(tmpa->data > tmpb->data){
				return false;
			}
			tmpa = tmpa->next;
			tmpb = tmpb->next;
		}
		return false;
	}
};
bool LongInt::lessThan(LongInt Q){
    List a = this.list;
	List b = q.list;

	if(getSign() == 'p' && Q.getSign() == 'n'){
		return false;
	}
	if(getSign() == 'n' && Q.getSign() == 'p'){
		return true;
	}
	if(digits() > Q.digits()){
		return false;
	}
	if(Q.digits() > digits()){
		return true;
	}
	if(getSign() == 'p' && Q.getSign() == 'p'){
		node *tmpa = a.getFirst();
		node *tmpb = b.getFirst();
		//iterate through list a and b
		while(tmpa!=NULL && tmpb!=NULL){
			if(tmpa->data < tmpb->data){
				return true;
			}
			if(tmpa->data > tmpb->data){
				return false;
			}
			tmpa = tmpa->next;
			tmpb = tmpb->next;
		}
		return false;

	}
};
bool LongInt::equalTo(LongInt Q){
    List a = this.list;
	List b = Q.list;

	if(getSign() != Q.getSign()){
		return false;
	}
	if(digits() != Q.digits()){
		return false;
	}
	if(getSign() == 'p' && Q.getSign() == 'p'){
		node *tmpa = a.getFirst();
		node *tmpb = b.getFirst();
		while(tmpa!=NULL && tmpb!=NULL){
			if(tmpa->data != tmpb->data){
				return false;
			}
			tmpa = tmpa->next;
			tmpb = tmpb->next;
		}
		return true;
	}
};
//Adds Q to the Long Integer and returns the result
LongInt LongInt::add(LongInt Q){
	 // TODO: Handle addition when signs are different
	/*
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
*/
/*
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
*/
