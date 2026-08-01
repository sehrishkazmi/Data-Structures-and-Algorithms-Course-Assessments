// ASSIGNMENT # 01 - Q1
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

vector<vector<int>> getInput(int n){
	vector<vector<int>> matrix(n, vector<int>(n));
	cout<< "\nEnter "<< (n*n) << " integers:"<<endl;
	
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cout<<"Element ["<<i<<"]["<<j<<"]: ";
			cin>> matrix[i][j];
		}
	}
	return matrix;
}

long long Sum(const vector<vector<int>>& matrix){
	long long sum = 0;
	int n = matrix.size();
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			sum += matrix[i][j];
		}
	}
	return sum;
}

void computing(int n){
	//matrix created
	vector <vector<int>> matrix = getInput(n);
	
	// summation function called
	long long sum = Sum(matrix);
	 
	//display
	cout<<"\n--------------------------------"<<endl;
	cout<<"Entered "<<n<<"x"<<n<<" Matrix: "<<endl;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cout<<matrix[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"\nSum of all "<<(n*n)<<" Elements = "<<sum<<endl;
}

int main(void){
	rep:
	int n;
	cout<<"Enter the dimension (n) for the nxn matrix: ";
	if (!(cin>>n) || n<=0){ //I need to add a && n not a number statement here
		cout<<"Invalid Entry please enter a positive integer."<<endl;
		cin.clear(); // Clear the error flag on cin
    	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid characters from buffer
		goto rep;
	}
	computing(n);
	return 0;
}