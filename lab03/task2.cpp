#include<iostream>
using namespace std;


class node{
	
	public :
		string data;
		node*next;
		
		node(string data){
			this->data=data;
			next=NULL;
		}
};

class LibraryManagemnet{
	public:
	
	node*head;
	node*tail;
	
	LibraryManagemnet (){
		head=tail=NULL;
	}
	
	void pop_front(){
		
		node*newnode=head;
		head=head->next;
        newnode->next=NULL;
        delete newnode;

        if(head==NULL){
            tail==NULL;
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
	bool searchLL(string data){
		node*newnode=head;
			while(newnode!=NULL){
			if(newnode->data==data){
				cout <<"found the data in the linked list"<< endl;
                return true;
			}
            newnode=newnode->next;
		}
        cout<< "data not found in the linked list"<< endl;
        return false;
	}

	void searchByPosition(int pos){
    node* newnode = head;
    int index = 0;

    while (newnode != NULL) {
        if (index == pos) {
            cout << "Book at position " << pos << " is: " << newnode->data << endl;
            return;
        }
        newnode = newnode->next;
        index++;
    }

    cout << "Invalid position: " << pos << ". No book found at this position." << endl;
}

	
	void print_LL(){
		node*newnode=head;
		while(newnode!=NULL){
			cout<< newnode->data<<endl;
			newnode=newnode->next;
		}
	}
};

int main(){

    int pos;
    string data;

    LibraryManagemnet l1;

    l1.push_end("book1");
    l1.push_end("book2");
    l1.push_end("book3");
    l1.push_end("book4");
    cout << "this the catalog of books"<< endl;

    l1.print_LL();
    l1.pop_front();
    cout << "book from the front was deleted"<< endl;
    l1.searchLL("book2");
    cout << "yes there is a book named book2 in a catalog"<<endl;
    l1.searchByPosition(2);
    cout << "there is book found by pos"<< endl;
    l1.print_LL();
    cout << "now this is the whole catalog of books"<< endl;
    
    return 0;
}




