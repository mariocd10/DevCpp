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
    cout<<"----------------------------------------------------"<<endl;
	/*Print Digits
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
    cout<<"B equalTo C: "<<B.equalTo(C)<<endl;
    cout<<"B equalTo D: "<<B.equalTo(D)<<endl;
    cout<<"B equalTo AX: "<<B.equalTo(AX)<<endl;
    cout<<"B equalTo AZ: "<<B.equalTo(AZ)<<endl;
    cout<<"----------------------------------------------------"<<endl;
    //Comparing C with the other nums
	cout<<"C greatThan A: "<<C.greaterThan(A)<<endl;
    cout<<"C greatThan C: "<<C.greaterThan(C)<<endl;
    cout<<"C greatThan D: "<<C.greaterThan(D)<<endl;
    cout<<"C greatThan AX: "<<C.greaterThan(AX)<<endl;
    cout<<"C greatThan AZ: "<<C.greaterThan(AZ)<<endl;
    //Comparing Less than
    cout<<"C lessThan A: "<<C.lessThan(A)<<endl;
    cout<<"C lessThan D: "<<C.lessThan(D)<<endl;
    cout<<"C lessThan AX: "<<C.lessThan(AX)<<endl;
    cout<<"C lessThan AZ: "<<C.lessThan(AZ)<<endl;
    cout<<"----------------------------------------------------"<<endl;
    cout<<"C equalTo D: "<<C.equalTo(D)<<endl;
    cout<<"C equalTo AX: "<<C.equalTo(AX)<<endl;
    cout<<"C equalTo AZ: "<<C.equalTo(AZ)<<endl;
    cout<<"----------------------------------------------------"<<endl;
    //Comparing D with the other nums
	cout<<"D greatThan A: "<<B.greaterThan(A)<<endl;
    cout<<"D greatThan C: "<<B.greaterThan(C)<<endl;
    cout<<"D greatThan AX: "<<B.greaterThan(AX)<<endl;
    cout<<"D greatThan AZ: "<<B.greaterThan(AZ)<<endl;
    //Comparing Less than
    cout<<"D lessThan A: "<<D.lessThan(A)<<endl;
    cout<<"D lessThan C: "<<D.lessThan(C)<<endl;
    cout<<"D lessThan AX: "<<D.lessThan(AX)<<endl;
    cout<<"D lessThan AZ: "<<D.lessThan(AZ)<<endl;
    cout<<"----------------------------------------------------"<<endl;
    cout<<"D equalTo D: "<<D.equalTo(D)<<endl;
    cout<<"D equalTo AX: "<<D.equalTo(AX)<<endl;
    cout<<"D equalTo AZ: "<<D.equalTo(AZ)<<endl;
    cout<<"----------------------------------------------------"<<endl;
    //Comparing AX with the other nums
	cout<<"AX greatThan A: "<<AX.greaterThan(A)<<endl;
    cout<<"AX greatThan C: "<<AX.greaterThan(C)<<endl;
    cout<<"AX greatThan D: "<<AX.greaterThan(D)<<endl;
    cout<<"AX greatThan AZ: "<<AX.greaterThan(AZ)<<endl;
    //Comparing Less than
    cout<<"AX lessThan A: "<<AX.lessThan(A)<<endl;
    cout<<"AX lessThan C: "<<AX.lessThan(C)<<endl;
    cout<<"AX lessThan D: "<<AX.lessThan(D)<<endl;
    cout<<"AX lessThan AX: "<<AX.lessThan(AX)<<endl;
    cout<<"AX lessThan AZ: "<<AX.lessThan(AZ)<<endl;
    cout<<"----------------------------------------------------"<<endl;
    cout<<"AX equalTo C: "<<AX.equalTo(C)<<endl;
    cout<<"AX equalTo D: "<<AX.equalTo(D)<<endl;
    cout<<"AX equalTo AX: "<<AX.equalTo(AX)<<endl;
    cout<<"AX equalTo AZ: "<<AX.equalTo(AZ)<<endl;
    cout<<"----------------------------------------------------"<<endl;
    //Comparing AZ with the other nums
	cout<<"AZ greatThan A: "<<AZ.greaterThan(A)<<endl;
    cout<<"AZ greatThan C: "<<AZ.greaterThan(C)<<endl;
    cout<<"AZ greatThan D: "<<AZ.greaterThan(D)<<endl;
    cout<<"AZ greatThan AX: "<<AZ.greaterThan(AX)<<endl;
    cout<<"AZ greatThan AZ: "<<AZ.greaterThan(AZ)<<endl;
    //Comparing Less than
    cout<<"AZ lessThan A: "<<AZ.lessThan(A)<<endl;
    cout<<"AZ lessThan C: "<<AZ.lessThan(C)<<endl;
    cout<<"AZ lessThan D: "<<AZ.lessThan(D)<<endl;
    cout<<"AZ lessThan AX: "<<AZ.lessThan(AX)<<endl;
    cout<<"AZ lessThan AZ: "<<AZ.lessThan(AZ)<<endl;
    cout<<"----------------------------------------------------"<<endl;
    cout<<"AZ equalTo C: "<<AZ.equalTo(C)<<endl;
    cout<<"AZ equalTo D: "<<AZ.equalTo(D)<<endl;
    cout<<"AZ equalTo AX: "<<AZ.equalTo(AX)<<endl;
    cout<<"AZ equalTo AZ: "<<AZ.equalTo(AZ)<<endl;
    //Overflow
    int v = 112345;
    cout<<"Before overFlow: "<<v<<endl;
    A.overFlow(v);
    cout<<"New Value of v after overFlow is: "<<v<<endl;

 	//Add
 	cout<<"----------------------------------------------------"<<endl;
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
	cout<<"----------------------------------------------------"<<endl;
	LongInt K = A.subtract(D);
	cout<<"A-D = K: "<<K.Print()<<endl;
	LongInt L = C.subtract(D);
	cout<<"C-D = L: "<<L.Print()<<endl;
	LongInt M = D.subtract(C);
	cout<<"D-C = M: "<<M.Print()<<endl;
	LongInt N = H.subtract(H);
	cout<<"H-H = N: "<<N.Print()<<endl;
	LongInt O = L.subtract(K);
	cout<<"L-K = O: "<<O.Print()<<endl;
	LongInt P = J.subtract(M);
	cout<<"J-M = P: "<<P.Print()<<endl;
	cout<<"----------------------------------------------------"<<endl;
	LongInt Q = A.multiply(D);
	cout<<"A*D = Q: "<<Q.Print()<<endl;
	LongInt R = B.multiply(C);
	cout<<"B*C = R: "<<R.Print()<<endl;
	LongInt S = D.multiply(D);
	cout<<"D*D = S: "<<S.Print()<<endl;
	LongInt T = K.multiply(E);
	cout<<"K*E = T: "<<T.Print()<<endl;
	LongInt U = F.multiply(L);
	cout<<"F*L = U: "<<U.Print()<<endl;
	LongInt V = I.multiply(J);
	cout<<"I*J = V: "<<V.Print()<<endl;
	cout<<"----------------------------------------------------"<<endl;
	*/
	
	cout<<"B/A"<<endl;
	B.divide(A);
	
	system("PAUSE");
	return 0;
}
