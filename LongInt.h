#ifndef LONGINT_H
#define LONGINT_H

#include <sstream>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>      /* printf, fgets */


#include "List.h"

using namespace std;

class LongInt{
	private:
		bool sign;
		void stripz(string s);
		int digits(int t);
		List list;
	public:
		
		LongInt(){}
		int overFlow(int &T);
		void Initialize(string S); //Initializes the Long Integer using a String S, which contains a number. Sï¿½scharacters are guaranteed to be digits, except the first character which may be a minus character.
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

void LongInt::stripz(string s){
    for(int i=0; i<s.length(); ++i){
		if(s[i]!='0'){
			int index = s.length()-i;
			s.substr(i,index);
		}
	}
}

//Initializes the Long Integer using a String S, which contains a number. S’scharacters are guaranteed to be digits, except the first character which may be a minus character.
void LongInt::Initialize(string S){
	int f = 1;
 	List tmp;
	//if first element is - then remove and assign it to sign
	if(S[0]=='-'){
        LongInt::sign = false;
		S.erase(S.begin());
	}
	LongInt::sign = true;
	//traverse through string without the sign char
	int i = S.length();
	while(i>0){
			//a check to make sure S.length()-i doesn't go out of bounds
			if(i>3){
				//grabbing the last 4 digits from the right
				string str = S.substr(i-4,4);
				//stripping the leading zero's
				stripz(str);
				//converting string to long value
				int value = atoi(str.c_str());
				//insert into list if first node
				if(f==1){
					tmp.createNode(value);
					f+=1;
				}
				//if not the first node
				else{
					tmp.insertLeft(value);
					f+=1;
				}
				i-=4;
			}
			//when there are less than 4 digits left
			else{
                string str = S.substr(0,i);
            	//stripping the leading zero's
				stripz(str);
				//convert to int
            	int value = atoi(str.c_str());
            	if(f==1){
            		tmp.createNode(value);
            		f+=1;
            	}
            	f+=1;
            	tmp.insertLeft(value);
            	break;
			}
  	}
  	//Assigning the newly created List to the private var list
  	LongInt::list = tmp;
	return;
}

//Get and set the sign of the Long Integer
bool LongInt::getSign(){
	return LongInt::sign;
}
void LongInt::setSign(bool S){
	LongInt::sign = S;
}

// Returns the total number of digits in the Long Integer
int LongInt::getDigitCount(){
	int first=1;
	int digits=0;
	List a = LongInt::list;
	node *tmp = a.Head;
	while(tmp!=NULL){
		if(first==1){
            int number = tmp->data;
   			int num = LongInt::digits(number);
			digits+=num;
			first+=1;
			tmp = a.nextRight(tmp);
		}
		else{
			digits +=4;
			tmp = a.nextRight(tmp);
		}
	}
	return digits;
}

// Prints the Long Integer to standard output. The output format is defined as a sequence of digit characters. The first character may be a minus.
string LongInt::Print(){
	string total = "";
	bool first = true;
	//get List and first node
	List a = LongInt::list;
	node *tmp = a.getFirst();
	//loop through list
	while(tmp!=NULL){
		//convert int to char array
		int x = tmp->data;
	    char buffer[4];
		sprintf(buffer,"%d",x);//param 1: the int, param2: the destination, param3: format of conversion
		//convert char array to string
		string s = buffer;
		/*stringstream ss;
		ss<<buffer;
		ss>>s;*/
		//don't add zero's to first node
		if(first){
			total+=s;
		}
		//check if less than 4 to add zero's
		if(s.length()==3 && first!=true){
			s.insert(0,"0");
		    total +=s;
		}
		else if(s.length()==2 && first!=true){
			s.insert(0,"00");
			total+=s;
		}
		else if(s.length()==1 && first!=true){
			s.insert(0,"000");
			total+=s;
		}
		else if(s.length()==4 && first!=true){
			total+=s;
		}
		//iterate
		first=false;
		tmp = a.nextRight(tmp);

	}
	if(LongInt::sign==false){
		total.insert(0,"-");
	}
	return total;
}

//Determines if the Long Integer is greater than, less than, or equal to Q, respectively
bool LongInt::greaterThan(LongInt Q){
	bool curr = getSign();
	bool other = Q.getSign();
	int currDigits = getDigitCount();
	int otherDigits = Q.getDigitCount();
	if(curr && !other){
		return true;
	}
	if(!curr && other){
		return false;
	}
	if(currDigits > otherDigits){
		return true;
	}
	if(otherDigits > currDigits){
		return false;
	}
	if(curr && other){
		List currList = LongInt::list;
		List otherList = Q.list;
		node *tmpc = currList.getFirst();
		node *tmpo = otherList.getFirst();
		//iterate through list a and b
		while(tmpc!=NULL && tmpo!=NULL){
			if(tmpc->data < tmpo->data){
				return false;
			}
			if(tmpc->data > tmpo->data){
				return true;
			}
			tmpc = tmpc->next;
			tmpo = tmpo->next;
		}
		return false;
	}
};

bool LongInt::lessThan(LongInt Q){
    bool curr = getSign();
	bool other = Q.getSign();
	int currDigits = getDigitCount();
	int otherDigits = Q.getDigitCount();
	if(curr && !other){
		return false;
	}
	if(!curr && other){
		return true;
	}
	if(currDigits > otherDigits){
		return false;
	}
	if(otherDigits > currDigits){
		return true;
	}
	if(curr && other){
		List currList = LongInt::list;
		List otherList = Q.list;
		node *tmpc = currList.getFirst();
		node *tmpo = otherList.getFirst();
		//iterate through list a and b
		while(tmpc!=NULL && tmpo!=NULL){
			if(tmpc->data < tmpo->data){
				return true;
			}
			if(tmpc->data > tmpo->data){
				return false;
			}
			tmpc = tmpc->next;
			tmpo = tmpo->next;
		}
		return false;
	}
};

bool LongInt::equalTo(LongInt Q){
    bool curr = getSign();
	bool other = Q.getSign();
	int currDigits = getDigitCount();
	int otherDigits = Q.getDigitCount();
	if(curr && !other){
		return false;
	}
	if(!curr && other){
		return true;
	}
	if(currDigits == otherDigits && curr && other){
		List currList = LongInt::list;
		List otherList = Q.list;
		node *tmpc = currList.getFirst();
		node *tmpo = otherList.getFirst();
		//iterate through list a and b
		while(tmpc!=NULL && tmpo!=NULL){
			if(tmpc->data < tmpo->data){
				return false;
			}
			if(tmpc->data > tmpo->data){
				return false;
			}
			tmpc = tmpc->next;
			tmpo = tmpo->next;
		}
		return true;
	}
};

int LongInt::overFlow(int &T){
	int digits =0;
	int left, right;
    int x = LongInt::digits(T);
	if(x>4){
		left = T/10000;
		T = T%10000;
		return left;
	}
	else{
		return T;
	}
}

int LongInt::digits(int t){
	int tmp = t;
	int digits=0;
    while(tmp>0){
		tmp/=10;
		digits+=1;
	}
	return digits;
}

/*
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
	 int carry = overflow(addValue); // Enforce 4 digit rule
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

