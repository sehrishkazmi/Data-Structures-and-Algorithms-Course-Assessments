// DSA Quiz # 02
#include <iostream>
#include <stack>
using namespace std;

int main(void){
	stack<int> num; 
	int arr[3] = {1,2,3};
	for (int i=0; i<3; i++){
		cout<<arr[i]<<endl;
		num.push(arr[i]);
	}
	int x = num.size(); // initial size of stack
	for (int j=0; j<x; j++){
		cout<<"Stack top:"<<num.top()<<endl;
		num.pop();
	}
	cout<<num.empty()<<endl; //it is empty now
	return 0;
}