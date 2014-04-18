#include "LongInt.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
	string a = "2222";
	string b = "99999999";
	string c = "246813575732";
	string d = "180270361023456789";
	string ax = "29302390234702973402973420937420973420937420937234872349872934872893472893749287423847";
	string az = "-98534342983742987342987339234098230498203894209928374662342342342356723423423";

	//create LongInt Objs
	LongInt A;
	LongInt B;
	LongInt C;
	LongInt D;
	LongInt AX;
	LongInt AZ;
	//Create with Initialize
    A.Initialize(a);
    B.Initialize(b);
    C.Initialize(c);
    D.Initialize(d);
    AX.Initialize(ax);
    AZ.Initialize(az);
    //Print out test cases
    cout<<"Number A is: "<<A.Print()<<endl;
	cout<<"Number B is: "<<B.Print()<<endl;
	cout<<"Number C is: "<<C.Print()<<endl;
	cout<<"Number D is: "<<D.Print()<<endl;
	cout<<"Number AX is: "<<AX.Print()<<endl;
	cout<<"Number AZ is: "<<AZ.Print()<<endl;
	//Print Digits
	/*
	int digita = A.getDigitCount();
    int digitb = B.getDigitCount();
    int digitc = C.getDigitCount();
    int digitd = D.getDigitCount();
    int digitax = AX.getDigitCount();
    int digitaz = AZ.getDigitCount();
	cout<<"Digits A is: "<<digita<<endl;
	cout<<"Digits B is: "<<digitb<<endl;
	cout<<"Digits C is: "<<digitc<<endl;
	cout<<"Digits D is: "<<digitd<<endl;
	cout<<"Digits AX is: "<<digitax<<endl;
	cout<<"Digits AZ is: "<<digitaz<<endl;

	cout<<"----------------------------------------------------"<<endl;
	//Comparing A with the other nums
	cout<<"A greatThan B: "<<A.greaterThan(B)<<endl;
    cout<<"A greatThan C: "<<A.greaterThan(C)<<endl;
    cout<<"A greatThan D: "<<A.greaterThan(D)<<endl;
    cout<<"A greatThan AX: "<<A.greaterThan(AX)<<endl;
    cout<<"A greatThan AZ: "<<A.greaterThan(AZ)<<endl;
    cout<<"----------------------------------------------------"<<endl;
    //Comparing Less than
    cout<<"A lessThan B: "<<A.lessThan(B)<<endl;
    cout<<"A lessThan C: "<<A.lessThan(C)<<endl;
    cout<<"A lessThan D: "<<A.lessThan(D)<<endl;
    cout<<"A lessThan AX: "<<A.lessThan(AX)<<endl;
    cout<<"A lessThan AZ: "<<A.lessThan(AZ)<<endl;
    cout<<"----------------------------------------------------"<<endl;
    cout<<"A equalTo B: "<<A.equalTo(B)<<endl;
    cout<<"A equalTo C: "<<A.equalTo(C)<<endl;
    cout<<"A equalTo D: "<<A.equalTo(D)<<endl;
    cout<<"A equalTo AX: "<<A.equalTo(AX)<<endl;
    cout<<"A equalTo AZ: "<<A.equalTo(AZ)<<endl;
    cout<<"----------------------------------------------------"<<endl;
    //Comparing B with the other nums
	cout<<"B greatThan A: "<<B.greaterThan(A)<<endl;
    cout<<"B greatThan C: "<<B.greaterThan(C)<<endl;
    cout<<"B greatThan D: "<<B.greaterThan(D)<<endl;
    cout<<"B greatThan AX: "<<B.greaterThan(AX)<<endl;
    cout<<"B greatThan AZ: "<<B.greaterThan(AZ)<<endl;
    //Comparing Less than
    cout<<"B lessThan A: "<<B.lessThan(A)<<endl;
    cout<<"B lessThan C: "<<B.lessThan(C)<<endl;
    cout<<"B lessThan D: "<<B.lessThan(D)<<endl;
    cout<<"B lessThan AX: "<<B.lessThan(AX)<<endl;
    cout<<"B lessThan AZ: "<<B.lessThan(AZ)<<endl;
    cout<<"----------------------------------------------------"<<endl;
    */
    //Overflow
    int v = 112345;
    cout<<"Before overFlow: "<<v<<endl;
    A.overFlow(v);
    cout<<"New Value of v after overFlow is: "<<v<<endl;
 	//Add
	
 	LongInt E = A.add(D);
	cout<<"A+D = E: "<<E.Print()<<endl;
	LongInt F = B.add(C);
	cout<<"B+C = F: "<<F.Print()<<endl;
	LongInt G = C.add(D);
	cout<<"C+D = G: "<<G.Print()<<endl;
	LongInt H = E.add(E);
	cout<<"E+E = H: "<<H.Print()<<endl;
	LongInt I = A.add(E);
	cout<<"A+E = I: "<<I.Print()<<endl;
	LongInt J = B.add(G);
	cout<<"B+G = J: "<<J.Print()<<endl;
	LongInt K = A.subtract(D);
	cout<<"A-D = K: "<<K.Print()<<endl;
	LongInt L = C.subtract(D);
	cout<<"C-D = L: "<<L.Print()<<endl;
	LongInt M = D.subtract(C);
	cout<<"D-C = M: "<<M.Print()<<endl;
	LongInt N = H.subtract(H);
	cout<<"H-H = N: "<<N.Print()<<endl;
	system("PAUSE");
	return 0;
}
