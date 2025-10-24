
#include <iostream>
#include <string>
using namespace std;


    string name;
    int score;
    Node* next;
};


void insert(Node*& head, string name, int score) {
    Node* newNode = new Node{name, score, NULL};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}


int getMax(Node* head) {
    int maxVal = head->score;
    while (head) {
        if (head->score > maxVal)
            maxVal = head->score;
        head = head->next;
    }
    return maxVal;
}


int getDigit(int number, int exp) {
    return (number / exp) % 10;
}


Node* countingSort(Node* head, int exp) {

    Node* buckets[10] = {NULL};
    Node* bucketTails[10] = {NULL};

    
    Node* curr = head;
    while (curr) {
        int digit = getDigit(curr->score, exp);
        Node* nextNode = curr->next;
        curr->next = NULL;

        if (!buckets[digit]) {
            buckets[digit] = bucketTails[digit] = curr;
        } else {
            bucketTails[digit]->next = curr;
            bucketTails[digit] = curr;
        }
        curr = nextNode;
    }

    
    Node* newHead = NULL;
    Node* tail = NULL;
    for (int i = 0; i < 10; i++) {
        if (buckets[i]) {
            if (!newHead)
                newHead = buckets[i];
            else
                tail->next = buckets[i];
            tail = bucketTails[i];
        }
    }

    return newHead;
}


void radixSort(Node*& head) {
    int maxVal = getMax(head);
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        head = countingSort(head, exp);
}


void display(Node* head) {
    cout << "\nSorted Student List (Ascending by Score):\n";
    cout << "------------------------------------------\n";
    while (head) {
        cout << head->name << " - " << head->score << endl;
        head = head->next;
    }
}

int main() {
    Node* head =NULL;

    // Example Data (you can modify or make it user input)
    insert(head, "Alice", 85);
    insert(head, "Bob", 70);
    insert(head, "Charlie", 95);
    insert(head, "David", 40);
    insert(head, "Ella", 60);
    insert(head, "Frank", 100);
    insert(head, "Grace", 78);
    insert(head, "Hank", 55);

    cout << "Before Sorting (Name - Score):\n";
    Node* temp = head;
    while (temp) {
        cout << temp->name << " - " << temp->score << endl;
        temp = temp->next;
    }

    
    radixSort(head);

    
    display(head);

    return 0;
}
