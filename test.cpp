#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
	
	int num = 12345678;
	int count=0;
	int tmp=num;
	
	while(tmp>0){
		tmp /= 10;
		count++;
		cout<<tmp<<endl;
	}
	
	cout<<num;
	cout<<count;
	string c;
	cin>>c;
	return 0;
}
