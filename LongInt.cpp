#include <sstream>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "LongInt.h"

using namespace std;

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
	if(S[0]== '-'){
        LongInt::sign = false;
		S.erase(S.begin());
	}
	else{
		LongInt::sign=true;
	}
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
	int len = getDigitCount();
	
	//loop through list
	while(tmp!=NULL){
		//convert int to char array
		int x = tmp->data;
	    char buffer[4];
		sprintf(buffer,"%d",x);//param 1: the int, param2: the destination, param3: format of conversion
		//convert char array to string
		string s = buffer;
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
	if(sign==false){
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
	if(curr && other && currDigits == otherDigits){
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
	if(!curr && !other && currDigits == otherDigits){
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
	if(!curr && !other){
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

bool LongInt::greater(LongInt Q){
	int currDigits = getDigitCount();
	int otherDigits = Q.getDigitCount();
	if(currDigits > otherDigits){
		return true;
	}
	if(otherDigits > currDigits){
		return false;
	}
	if(currDigits == otherDigits){
		List currList = list;
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
	if(currDigits == otherDigits){
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
}

bool LongInt::equalTo(LongInt Q){
    bool curr = getSign();
	bool other = Q.getSign();
	int currDigits = getDigitCount();
	int otherDigits = Q.getDigitCount();
	if(curr && !other){
		return false;
	}
	if(!curr && other){
		return false;
	}
	if(currDigits > otherDigits){
		return false;
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
				return false;
			}
			tmpc = tmpc->next;
			tmpo = tmpo->next;
		}
		return true;
	}
	if(!curr && !other){
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
		return 0;
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

//Adds Q to the Long Integer and returns the result

LongInt LongInt::add(LongInt Q){
	 int addValue, borrow;
	 node* a1, *b2;
	 List a = list;
	 List b = Q.list;
	 //check if a > q
	 int aCount = getDigitCount();
	 int bCount = Q.getDigitCount();
	 //get sign
	 bool s1 = getSign();
	 bool s2 = Q.getSign();
	 //get last nodes
	 a1 = a.getLast();
	 b2 = b.getLast();
	 // Create an empty LongInt to store result in
	 LongInt result;
	 List c;
	
	//check if different signs
	if(s1!=s2){
		if(equalTo(Q)){
			c.createNode(0);
			result.list = c;
			result.sign = true;
			return result;
		}
		//check if lena>lenb or if equal then check first node a > first node b
		if(greater(Q)){//if so then a-b
		    //check if we need to borrow first node
			if(a1->data < b2->data && !a.isFirst(a1) && !b.isFirst(b2)){
				addValue = (a1->data + 10000) - b2->data;
				borrow = 1;
				c.createNode(addValue);
			}
			else{
				addValue = a1->data - b2->data;
				borrow=0;
				c.createNode(addValue);
			}
			//since a>b b will finish first so use b as limit to loop
			while(!b.isFirst(b2)) {
				a1 = a.nextLeft(a1);
				b2 = b.nextLeft(b2);
				//check if we need to borrow
				if(a1->data < b2->data){
					addValue = ((a1->data-borrow)+10000) - b2->data;
					borrow = 1;
					c.insertLeft(addValue);
				}
				else{
					addValue = a1->data - b2->data;
					borrow=0;
					c.insertLeft(addValue);
				}
			}
			//list b is done so now add the rest of a into result
			while(!a.isFirst(a1)){
				a1 = a.nextLeft(a1);
				addValue = a1->data - borrow;
				borrow=0;
				c.insertLeft(addValue);
			}
			//check the sign
			if(!s1){
				result.sign = false;
			}
			else{
				result.sign = true;
			}
			result.list = c;
			return result;
		}
		//check if lena<lenb or if equal then check first node a < first node b
		else if(!greater(Q)){//if so then b
		    if(b2->data < a1->data && !a.isFirst(a1) && !b.isFirst(b2)){
				addValue = (b2->data + 10000) - a1->data;
				borrow = 1;
				c.createNode(addValue);
			}
			else{
				addValue = b2->data - a1->data;
				borrow=0;
				c.createNode(addValue);
			}
			//list a will finish first so we traverse through that
			while(!a.isFirst(a1)) {
				a1 = a.nextLeft(a1);
				b2 = b.nextLeft(b2);
				if(b2->data < a1->data){
					addValue = ((b2->data-borrow)+10000) - a1->data;
					borrow = 1;
					c.insertLeft(addValue);
				}
				else{
					addValue = b2->data - a1->data;
					borrow=0;
					c.insertLeft(addValue);
				}
			}
			//list a is done now we add the rest of b into c
			while(!b.isFirst(b2)){
				b2 = b.nextLeft(b2);
				addValue = b2->data - borrow;
				borrow=0;
				c.insertLeft(addValue);
			}
			//both lists done and c is populate
			//now check for the sign
			if(s1){
				result.sign = false;
			}
			else{
				result.sign=true;
			}
			
			result.list = c;
			return result;
		}
	}
	//both are same sign +a +b or -a -b
	else{
		addValue = a1->data + b2->data;
		int carry = overFlow(addValue);
		c.createNode(addValue);
		//perform regular addition
		while(!a.isFirst(a1) && !b.isFirst(b2)) {
			 a1 = a.nextLeft(a1);
			 b2 = b.nextLeft(b2);
			 
			 addValue = b2->data + a1->data + carry;
			 carry = overFlow(addValue); // Enforce 4 digit rule
			 c.insertLeft(addValue);
		 }

		//if list A is done then add values of B into C
		if(a.isFirst(a1) && !b.isFirst(b2)){
			while(!b.isFirst(b2)){
				b2 = b.nextLeft(b2);
				addValue = b2->data + carry;
				carry = overFlow(addValue);
				c.insertLeft(addValue);
				
			}
			//list B is done, insert the carry if any into C as the first node
			if(carry!=0){
				c.insertLeft(carry);
				if(s1){
					result.sign = true;
				}
				else{
					result.sign = false;
    			}
				//c.traverse();
				result.list = c;
				return result;
			}
			
			if(s1){
					result.sign = true;
				}
				else{
					result.sign = false;
				}
			//c.traverse();
			result.list = c;
			return result;
  		}
		//if list B is done, add values of A into C
		if(b.isFirst(b2) && !a.isFirst(a1)){
			while(!a.isFirst(a1)){
				a1 = a.nextLeft(a1);
				addValue = a1->data + carry;
				carry = overFlow(addValue);
				c.insertLeft(addValue);
			}
			//list A is done, insert the carry if any as the first node
			if(carry!=0){
				c.insertLeft(carry);
				result.list = c;
				if(s1){
					result.sign = true;
				}
				else{
					result.sign = false;
				}
				return result;
			}
			
			if(s1){
					result.sign = true;
				}
				else{
					result.sign = false;
				}
			return result;
		}
		//if Both lists are done at the same time of traversal
		else{
			//check if there's a carry, if so add it to the front of the list C
			if(carry!=0){
				c.insertLeft(carry);
				result.list = c;
				if(s1){
					result.sign = true;
				}
				else{
					result.sign;
				}
				return result;
				
			}
			else{
				result.list = c;
				if(s1){
					result.sign = true;
				}
				else{
					result.sign = false;
				}
				return result;
			}
		}
	}
}

 //Subtracts Q from the Long Integer and returns the result
LongInt LongInt::subtract(LongInt Q){
     int subValue, borrow;
	 node* a1, *b2, *f1, *f2;
	 List a = list;
	 List b = Q.list;
	 //check if a > q
	 int aCount = getDigitCount();
	 int bCount = Q.getDigitCount();
	 //get sign
	 bool s1 = LongInt::getSign();
	 bool s2 = Q.getSign();
	 //get last nodes
	 a1 = a.getLast();
	 b2 = b.getLast();
	 // Create an empty LongInt to store result in
	 LongInt result;
	 List c;
	 //if signs are different
	 if(s1 != s2){
			subValue = a1->data + b2->data;
			int carry = overFlow(subValue);
			c.createNode(subValue);
			
			while(!a.isFirst(a1) && !b.isFirst(b2)) {
				a1 = a.nextLeft(a1);
			 	b2 = b.nextLeft(b2);

				subValue = b2->data + a1->data + carry;
				carry = overFlow(subValue); // Enforce 4 digit rule
				c.insertLeft(subValue);
			}
			
			//if list A is done then add values of B into C
			if(a.isFirst(a1) && !b.isFirst(b2)){
				while(!b.isFirst(b2)){
					b2 = b.nextLeft(b2);
					subValue = b2->data + carry;
					carry = overFlow(subValue);
					c.insertLeft(subValue);
				}
				//list B is done, insert the carry if any into C as the first node
				if(carry!=0){
					c.insertLeft(carry);
					result.list = c;
					if(!s1){
						result.sign = false;
					}
					else{
						result.sign = true;
					}
					return result;
				}
				result.list = c;
				if(!s1){
						result.sign = false;
					}
					else{
						result.sign = true;
					}
				return result;
	  		}
			//if list B is done, add values of A into C
			if(b.isFirst(b2) && !a.isFirst(a1)){
				while(!a.isFirst(a1)){
					a1 = a.nextLeft(a1);
					subValue = a1->data + carry;
					carry = overFlow(subValue);
					c.insertLeft(subValue);
				}
				//list A is done, insert the carry if any as the first node
				if(carry!=0){
					c.insertLeft(carry);
					result.list = c;
					//if -a then -()a+b)
					if(!s1){
						result.sign = false;
					}
					else{
						result.sign = true;
					}
					return result;
				}
				if(!s1){
						result.sign = false;
					}
					else{
						result.sign = true;
					}
				return result;
			}
			//if Both lists are done at the same time of traversal
			else{
				//check if there's a carry, if so add it to the front of the list C
				if(carry!=0){
					c.insertLeft(carry);
					result.list = c;
					if(!s1){
						result.sign = false;
					}
					else{
						result.sign = true;
					}
					return result;
				}
			}
		 }
	else{
		//same sign
		int borrow;
		if(equalTo(Q)){
			c.createNode(0);
			result.list = c;
			result.sign = true;
			return result;
		}
		//if a<b then b-a
		if(!greater(Q)){
			if(b2->data < a1->data && !a.isFirst(a1) && !b.isFirst(b2)){
				subValue = (b2->data+10000) - a1->data;
				borrow=1;
				c.createNode(subValue);
			}
			else{
				subValue = b2->data - a1->data;
				borrow=0;
				c.createNode(subValue);
			}
			
			while(!a.isFirst(a1) && !b.isFirst(b2)){
				a1 = a.nextLeft(a1);
				b2 = b.nextLeft(b2);
				if(b2->data < a1->data){
					subValue = ((b2->data - borrow) + 10000) - a1->data;
					borrow = 1;
					c.insertLeft(subValue);
				}
				else{
					subValue = (b2->data-borrow) - a1->data;
					c.insertLeft(subValue);
					borrow=0;
				}
			}
			
			while(!b.isFirst(b2)){
				b2= b.nextLeft(b2);
				subValue = b2->data - borrow;
				borrow=0;
				c.insertLeft(subValue);
			}
			//remove any leading nodes that are zero's
			node *tmpc, *tmpd;
			tmpc = c.getFirst();
			while(tmpc->data==0){
				tmpd = c.nextRight(tmpc);
				c.remove(tmpc);
				tmpc = tmpd;
			}
			result.list = c;
			
			if(s1){
				result.sign = false;
			}
			else{
				result.sign = true;
			}
			
			return result;
		}
		//a>b then a-b
		else{
			if(a1->data < b2->data && !a.isFirst(a1) && !b.isFirst(b2)){
				subValue = (a1->data+10000) - b2->data;
				borrow=1;
				c.createNode(subValue);
			}
			else{
				subValue = a1->data - b2->data;
				borrow=0;
				c.createNode(subValue);
			}
			
			while(!a.isFirst(a1) && !b.isFirst(b2)){
				a1 = a.nextLeft(a1);
				b2 = b.nextLeft(b2);
				if(a1->data < b2->data){
					subValue = ((a1->data - borrow) + 10000) - b2->data;
					borrow = 1;
					c.insertLeft(subValue);
				}
				else{
					subValue = (a1->data-borrow) - b2->data;
					c.insertLeft(subValue);
					borrow=0;
				}
			}
			
			while(!a.isFirst(a1)){
				a1= a.nextLeft(a1);
				subValue = a1->data - borrow;
				borrow=0;
				c.insertLeft(subValue);
			}
			
			node *tmpc, *tmpd;
			tmpc = c.getFirst();
			while(tmpc->data==0){
				tmpd = c.nextRight(tmpc);
				c.remove(tmpc);
				tmpc = tmpd;
			}
			
			result.list = c;
			
			if(s1){
				result.sign = true;
			}
			else{
				result.sign = false;
			}
			
			return result;
		}
	}
};

// Multiplies the Long Integer by Q and returns the result
LongInt LongInt::multiply(LongInt Q){
	List b = Q.list;
	List a = list;
	
	node *b2,*a1;
	
	LongInt sumTotal;
	sumTotal.sign=true;
	List total;
	total.createNode(0);
	if(a.getFirst()->data == 0 || b.getFirst()->data == 0){
		sumTotal.list = total;
	}
	else if((a.getFirst() == a.getLast() && a.getFirst()->data == 1) || (b.getFirst() == b.getLast() && b.getFirst()->data == 1)){
		if(a.getFirst()->data == 1){
			sumTotal.list = b;
		}
		else{
			sumTotal.list = a;
		}
	}
	if(greater(Q)){
		b2 = b.getLast();
		sumTotal.list=total;
		while(b2!=NULL){
			a1 = a.getLast();
			bool first = true;
			int zeroC =0;
			int carry=0;
			int multValue;
			LongInt Sum;
			List sumL;
			while(a1!=NULL){
				multValue = (b2->data * a1->data)+carry;
				carry = overFlow(multValue);
				if(first){
					sumL.createNode(multValue);
					first=false;
				}
				else{
					sumL.insertLeft(multValue);
				}
				
				a1 = b.nextLeft(a1);
			}
			if(carry!=0){
				sumL.insertLeft(carry);
				carry=0;
			}
			for(int i; i<zeroC; i++){
				sumL.insertRight(0);
			}
			Sum.setSign(true);
			Sum.list = sumL;
			zeroC++;
			sumTotal = sumTotal.add(Sum);
			b2 = a.nextLeft(b2);
			
		}
	}
	//a<b
	else{
		a1 = a.getLast();
		
		sumTotal.list=total;
		int zeroC =0;
		while(a1!=NULL){
			b2 = b.getLast();
			bool first = true;
			int carry=0;
			int multValue;
			LongInt Sum;
			List sumL;
			while(b2!=NULL){
				multValue = (a1->data * b2->data)+carry;
				carry = overFlow(multValue);
				if(first){
					sumL.createNode(multValue);
					first=false;
				}
				else{
					sumL.insertLeft(multValue);
				}
				
				b2 = b.nextLeft(b2);
			}
			if(carry!=0){
				sumL.insertLeft(carry);
				carry=0;
			}
			for(int i=0;i<zeroC;i++){
				sumL.insertRight(0);
			}
			Sum.setSign(true);
			Sum.list = sumL;
			sumTotal = sumTotal.add(Sum);
			a1 = a.nextLeft(a1);
			zeroC++;
		}
	}
	if(getSign() == Q.getSign()){
		if(getSign()){
			sumTotal.setSign(true);
		}
		else{
			sumTotal.setSign(false);
		}
	}
	else{
		sumTotal.setSign(false);
	}
	
	return sumTotal;
};
/*
//Raises the Long Integer to the power p and returns the result. NOTE: p is a normal integer.
LongInt LongInt::power(int p){
};
 //Divides the Long Integer by Q and returns the quotient portion of the result
LongInt LongInt::divide(LongInt Q){
};
*/
