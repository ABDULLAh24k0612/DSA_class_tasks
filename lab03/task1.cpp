#include<iostream>
using namespace std;


class node{
	
	public :
		string data;
		node*next;
		
		node(string data){
			data=data;
			next=NULL;
		}
};

class LL{
	public:
	
	node*head;
	node*tail;
	
	LL(){
		head=tail=NULL;
	}
	
	void push_front(string data){
		
		node*newnode=new node(data);
		if(head==NULL){
			head=tail=newnode;
		}
		else{
			newnode->next=head;
			head=newnode;
		}
	}
	
	void push_end(string data){
		
		node*newnode=new node(data);
		if(head==NULL){
			head=tail=newnode;
		}
		else{
			tail->next=newnode;
			tail=newnode;
		}
	}
	string searchLL(string data){
		node*newnode=head;
			while(newnode!=NULL){
			if(newnode->data==data){
				return newnode->data;
			}
		}
	}
	
	void insert(string data,string pos){
		node*temp=head;
		node*newnode=new node(data);
		while(temp->data!=pos){
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->next=temp->next;
		
		}
	void print_LL(){
		node*newnode=head;
		while(newnode!=NULL){
			cout<< newnode->data<<endl;
			newnode=newnode->next;
		}
	}
};




int main() {
    LL library;

    
    library.push_end("Data Structures");
    library.push_end("Operating Systems");
    library.push_end("Computer Networks");
    library.push_end("Database Systems");

    
    library.push_front("Artificial Intelligence");

   
    library.push_end("Machine Learning");

    
    library.insert("Cyber Security", "Operating Systems");

    
    if (library.searchLL("Database Systems")) {
        cout << "\"Database Systems\" found in the list." << endl;
    } else {
        cout << "\"Database Systems\" not found in the list." << endl;
    }

    /
    cout << "Complete list of books:" << endl;
    library.print_LL();

    return 0;
}
