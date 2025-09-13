#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node*next;

    node(int num){

        data=num;
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

    node* getHead() {
    return head;
}

    int* linkedListToArray(node* head, int& size) {
    size = 0;
    node* temp = head;

    
    while (temp != NULL) {
        size++;
        temp = temp->next;
    }

    int* arr = new int[size];

    
    temp = head;
    for (int i = 0; i < size; i++) {
        arr[i] = temp->data;
        temp = temp->next;
    }

    return arr;
}

node* arrayToLinkedList(int arr[], int size) {
    if (size == 0) return NULL;

    node* head = new node(arr[0]);
     tail = head;

    for (int i = 1; i < size; i++) {
        tail->next = new node(arr[i]);
        tail = tail->next;
    }

    return head;
}


void bubbleSort(int arr[], int n) {
    
    for (int i = 0; i < n - 1; i++) {
       
        for (int j = 0; j < n - 1 - i; j++) {
            
            if (arr[j] > arr[j + 1]) {
                
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
 void concatenate(LL& secondList) {
        if (head == nullptr) {
            
            head = secondList.head;
            return;
        }

        node* temp = head;
        while (temp->next != nullptr){
		
            temp = temp->next;
        }
        temp->next = secondList.head;
    }

		
    node* findMiddle(node* head) {
        if (head == NULL || head->next == NULL)
            return head;

        node* slow = head;
        node* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
	void RemoveDuplicateFromSortedLL() {
    node* curr = head;

    if (curr == NULL) return;

    while (curr->next != NULL) {
        if (curr->data == curr->next->data) {
            
            node* nodeToDelete = curr->next;
            curr->next = curr->next->next; 
            delete nodeToDelete;
        } else {
            curr = curr->next;
        }
    }
}

void removeDuplicateFromUnsortedLL() {
    node* curr = head;

    
    while (curr != NULL) {
        node* prev = curr;
        node* temp = curr->next;

        
        while (temp != NULL) {
            if (curr->data == temp->data) {
                
                node* toDelete = temp;
                prev->next = temp->next;   
                temp = temp->next;         
                delete toDelete;           
            } else {
                
                prev = temp;
                temp = temp->next;
            }
        }

        
        curr = curr->next;
    }
}

node* merge(node* left, node* right) {
        node* dummy = new node(-1);
        node* tail = dummy;

        while (left != NULL && right != NULL) {
            if (left->data < right->data) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }

        if (left != NULL) tail->next = left;
        else tail->next = right;

        node* result = dummy->next;
        delete dummy;
        return result;
    }
void printList() {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
void insertAtEnd(int val) {
    node* newNode = new node(val);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}


};
int main() {
    // Create first linked list
    LL list1;
    list1.insertAtEnd(4);
    list1.insertAtEnd(2);
    list1.insertAtEnd(5);
    list1.insertAtEnd(2);  
    list1.insertAtEnd(1);

    cout << "List 1 before sorting: ";
    list1.printList();

    // Convert LL to array for sorting
    int size1;
    int* arr1 = list1.linkedListToArray(list1.getHead(), size1);
    list1.bubbleSort(arr1, size1);
    node* sortedHead1 = list1.arrayToLinkedList(arr1, size1);
    delete[] arr1;

    cout << "List 1 after sorting: ";
    node* temp = sortedHead1;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    // Assign the sorted list back to list1
    list1 = LL(); // reset list1
    for (int i = 0; i < size1; i++) {
        list1.insertAtEnd(arr1[i]);
    }

    // Remove duplicates from sorted list
    list1.RemoveDuplicateFromSortedLL();
    cout << "List 1 after removing duplicates: ";
    list1.printList();

    // Find middle
    node* middle = list1.findMiddle(list1.getHead());
    if (middle != NULL)
        cout << "Middle of List 1: " << middle->data << endl;

    // Create second linked list
    LL list2;
    list2.insertAtEnd(6);
    list2.insertAtEnd(3);
    list2.insertAtEnd(4);
    list2.insertAtEnd(6); 

    cout << "\nList 2 before removing duplicates: ";
    list2.printList();

    // Remove duplicates from unsorted list2
    list2.removeDuplicateFromUnsortedLL();
    cout << "List 2 after removing duplicates: ";
    list2.printList();

    // Sort list2 (same process)
    int size2;
    int* arr2 = list2.linkedListToArray(list2.getHead(), size2);
    list2.bubbleSort(arr2, size2);
    node* sortedHead2 = list2.arrayToLinkedList(arr2, size2);
    delete[] arr2;

    cout << "List 2 after sorting: ";
    temp = sortedHead2;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    // Merge the two sorted linked lists
    node* mergedHead = list1.merge(sortedHead1, sortedHead2);
    cout << "\nMerged Sorted List: ";
    temp = mergedHead;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}

