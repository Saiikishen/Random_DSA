#include <iostream>
using namespace std;

int* create_arr(int *size){
	int* arr = new int[*size];
	for(int i = 0; i < *size;i++){
		cout<<"Enter number: ";
		cin>>arr[i];
	}
	return arr;
}

void display_arr(int *size,int *arr){
	for (int i=0; i < *size;i++){
		cout<<arr[i]<<" ";
	}
}

int* rev_arr(int *size, int *arr){
	for(int i=0; i < *size/2; i++){
		int j = (*size - 1 - i);
		arr[i] = arr[i]^arr[j];
		arr[j] = arr[i]^arr[j];
		arr[i] = arr[i]^arr[j];
	}
	return arr;
}
int main()
{
	int size;
	
	cout<<"enter the size of array"<<endl;
	cin>>size;
	int* myArray = create_arr(&size);
	display_arr(&size,myArray);
	rev_arr(&size,myArray);
	cout<<"\n";
	display_arr(&size,myArray);

}
