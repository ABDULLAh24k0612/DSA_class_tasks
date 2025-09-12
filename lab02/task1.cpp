#include<iostream>
using namespace std;
class DynamicArray{

    public:
    int size;
    int *arr;
    int count;


    DynamicArray(){
        size=0;
        arr=NULL;
        count=0;
    }

    DynamicArray(int size):size(size){

        arr=new int[size];
        count=0;


    }

    void push(int val){


        if(count<size){

            arr[count++]=val;
        }
        else{

            int Size=size*2;
            int *temp=new int[size];

            for(int i=0;i<size;++i){
                temp[i]=arr[i];
            }

            delete []arr;
            arr=new int[Size];

            for(int i=0;i<size;++i){
                arr[i]=temp[i];
            }

            arr[count++]=val;
            size=Size;
            
            
        }
    }

    void printing(){
        
        for(int i=0;i<count;++i){
            cout<<arr[i]<<" ";
        }

    }

    ~DynamicArray(){
        delete []arr;
        arr=NULL;
    }
};
int main(){

    int size;
    cout<<"Enter the size of array: "<<endl;
    cin>>size;
    DynamicArray d(size);
     int n;
  for(int i=0;i<size;i++){
  	cout << "enter the elements of the array"<< endl;
  	cin>>n;
  	d.push(n);
  }
    d.printing();
    cout<<endl;
    cout << "array is full enter new element"<< endl;
    cout << "resize array for the new element "<< endl;
    cin >> n;
    d.push(n);
    d.printing();




}
