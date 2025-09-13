#include<iostream>
using namespace std;


class node {
public:
    int number;
    node* prev;
    node* next;

    node(int num) {
        number = num;
        prev = next = NULL;
    }
};


class Train {
private:
    node* head;
    node* tail;

public:
    Train() {
        head = tail = NULL;
    }

    
    void addCompartment(int number) {
        node* newnode = new node(number);
        if (head == NULL) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        cout << "Compartment " << number << " added at the end.\n";
    }

    
    void removeFirstCompartment() {
        if (head == NULL) {
            cout << "Train is empty. No compartment to remove.\n";
            return;
        }

        node* temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL;  

        cout << "Compartment " << temp->number << " removed from front.\n";
        delete temp;
    }

    
    void searchCompartment(int number) {
        node* temp = head;
        while (temp != NULL) {
            if (temp->number == number) {
                cout << "Compartment " << number << " found in the train.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Compartment " << number << " not found.\n";
    }

   
    void displayTrain() {
        if (head == NULL) {
            cout << "Train is empty.\n";
            return;
        }

        node* temp = head;
        cout << "Train compartments (front to end): ";
        while (temp != NULL) {
            cout << temp->number << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    Train train;

    
    train.addCompartment(101);
    train.addCompartment(102);
    train.addCompartment(103);

   
    train.displayTrain();

    
    train.searchCompartment(102);
    train.searchCompartment(200);  

    
    train.removeFirstCompartment();

   
    train.displayTrain();

    return 0;
}
