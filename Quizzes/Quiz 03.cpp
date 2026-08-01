#include <iostream>
using namespace std;

class CircularQueue{
	char* arr; // fixed array
	int currentSize; // no. of elements in queue
	int cap;  // capacity of the queue
	int f=0;  // front index
	int r=-1; // rear index

public:
	// initializing queue
	CircularQueue (int size){
		cap = size;
		arr = new char[cap];
		currentSize = 0;
		f = 0;
		r = -1;
	}
	void push(char data){
		if (currentSize == cap){
			cout << "FULL CAPACITY\nCannot Push"<<endl;
			return;
		}
		
		// there is capacity, enqueue
		r = (r+1)%cap; 
		cout<<"r is "<<r<<endl;
		arr[r]=data;
		currentSize++;
	}
	
	void pop(){
		if (empty()){
			cout<<"EMPTY\nNothing to Pop"<<endl;
		}
		
		// not empty, dequeue
		f = (f+1)%cap;
		cout<<"f is "<<f<<endl;
		currentSize--;
	}
	char front(){
		if (empty()){
			cout<<"EMPTY\nNothing to Show"<<endl;
		}
		return arr[f];
	}
	
	bool empty(){
		return currentSize == 0;	
	}
	void display(){
		if (empty()){
			cout<<"QUEUE EMPTY"<<endl;
			return;
		}
		int index = f;
		for (int i=0; i<currentSize; i++){
			cout<<" "<<arr[index]<<" ";
			index = (index + 1)%cap; // Wrap around using capacity
		}
		cout<<" "<<endl;
	}
};
int main(){
	CircularQueue Q1(5);
	
	Q1.push('A');
	cout<<"Enqueue A:"<<endl;	
	Q1.display();
	
	Q1.push('B');
	cout<<"Enqueue B:"<<endl;	
	Q1.display();
	
	Q1.push('C');
	cout<<"Enqueue C:"<<endl;
	Q1.display();
	
	Q1.push('D');
	cout<<"Enqueue D:"<<endl;
	Q1.display();
	
	Q1.pop();
	cout<<"Dequeue:"<<endl;
	Q1.display();
	
	Q1.pop();
	cout<<"Dequeue:"<<endl;
	Q1.display();
	
	
	Q1.push('E');
	cout<<"Enqueue E:"<<endl;
	Q1.display();
	
	Q1.push('F');
	cout<<"Enqueue F:"<<endl;
	Q1.display();
	
	Q1.push('G');
	cout<<"Enqueue G:"<<endl;
	Q1.display();
	
	cout<<"Front: "<<Q1.front()<<endl;
	return 0;
}