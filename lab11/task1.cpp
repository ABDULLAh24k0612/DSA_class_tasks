#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node(string d) { data = d; next = NULL; }
};

class HashTable {
public:
    int size;
    Node** table;

    HashTable(int s) {
        size = s;
        table = new Node*[size];
        for(int i=0;i<size;i++) table[i] = NULL;
    }

    int hashFunc(string s) {
        int sum=0;
        for(char c:s) sum += c;
        return sum % size;
    }

    void insertString(string s) {
        int index = hashFunc(s);
        Node* n = new Node(s);
        n->next = table[index];
        table[index] = n;
    }

    void display() {
        for(int i=0;i<size;i++) {
            cout<<i<<" : ";
            Node* temp = table[i];
            while(temp) {
                cout<<temp->data<<" -> ";
                temp = temp->next;
            }
            cout<<"NULL\n";
        }
    }
};

int main() {
    HashTable h(10);
    h.insertString("apple");
    h.insertString("banana");
    h.insertString("cat");
    h.insertString("dog");
    h.display();
}
