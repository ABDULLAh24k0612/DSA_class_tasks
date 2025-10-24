#include <iostream>
using namepace std;


struct Node {
    int data;
    Node* next;
};


void push(Node** head_ref, int new_data) {
    Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}


void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    scout << endl;
}


Node* getTail(Node* head) {
    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        current = current->next;
    }
    return current;
}


Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    
    Node* pivot = end;
    Node* current = head;
    Node* prev = NULL;

   
    Node* less_head = NULL;
    Node* less_tail = NULL;
    Node* greater_head = NULL;
    Node* greater_tail = NULL;

    while (current != pivot) {
        if (current->data < pivot->data) {
           
            if (less_head == NULL) {
                less_head = current;
            } else {
                less_tail->next = current;
            }
            less_tail = current;
        } else {
           
            if (greater_head == NULL) {
                greater_head = current;
            } else {
                greater_tail->next = current;
            }
            greater_tail = current;
        }
        current = current->next;
    }

    
    if (less_tail) less_tail->next = NULL;
    if (greater_tail) greater_tail->next = NULL;
    
    
    if (less_head != NULL) {
        *newHead = less_head; 
        less_tail->next = pivot;
        pivot->next = greater_head;
    } else {
        *newHead = pivot; 
        pivot->next = greater_head;
    }

    
    if (greater_tail != NULL) {
        *newEnd = greater_tail;
    } else {
        *newEnd = pivot;
    }
    
    return pivot; 


Node* quickSortRec(Node* head, Node* end) {
    
    if (head == NULL || head == end) {
        return head;
    }

    Node* newHead = NULL; 
    Node* newEnd = NULL;   
    
    Node* pivot = partition(head, end, &newHead, &newEnd);

    
    if (pivot == newHead) {
        
        pivot->next = quickSortRec(pivot->next, newEnd);
        return pivot;
    }

    
    Node* temp = newHead;
    while (temp->next != pivot) {
        temp = temp->next;
    }
    
    temp->next = NULL;
    
    
    newHead = quickSortRec(newHead, temp);

    
    Node* tail_less = getTail(newHead);

    
    tail_less->next = pivot;

   
    pivot->next = quickSortRec(pivot->next, newEnd);

    return newHead;
}


void quickSort(Node** head_ref) {
    
    Node* tail = getTail(*head_ref);
    
   
    *head_ref = quickSortRec(*head_ref, tail);
}

 

int main() {
    Node* head = nullptr;
    
    
    int arr[] = {3, 5, 1, 9, 8, 7, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        push(&head, arr[i]);
    }

    std::cout << "Original list: ";
    printList(head);

    
    quickSort(&head);

    std::cout << "Sorted output: ";
    printList(head);

    
    Node* current = head;
    while(current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
