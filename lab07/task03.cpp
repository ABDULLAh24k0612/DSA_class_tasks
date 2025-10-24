#include <iostream>
#include <string>
using namespace std;

const int PRODUCT_COUNT = 3;


struct Product {
    string name;
    double price;
    string description;
    bool availability;
};


void swap_products(Product& a, Product& b) {
    Product temp = a;
    a = b;
    b = temp;
}


int partition(Product arr[], int low, int high) {
    double pivot_price = arr[high].price;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].price <= pivot_price) {
            i++;
            swap_products(arr[i], arr[j]);
        }
    }
    swap_products(arr[i + 1], arr[high]);
    return (i + 1);
}


void quickSort(Product arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}



void displayProducts(const Product products[], int count, const std::string& title) {
    cout << "\n--- " << title << " ---\n";
    
    

    for (int i = 0; i < count; ++i) {
       
        cout << products[i].name;
        
        int padding = 24 - products[i].name.length();
        for (int p = 0; p < padding; ++p) {
            cout << " ";
        }
        cout << "| ";

        
        cout << products[i].price << "  | ";
        
        
        cout << (products[i].availability ? "Yes      " : "No       ") << "| ";
        
        
        cout << products[i].description << "\n";
    }
}



int main() {
    Product product_list[PRODUCT_COUNT] = {
        {"Laptop Charger", 45.99, "Universal 90W power adapter.", true},
        {"Wireless Mouse", 19.50, "Ergonomic 2.4GHz wireless mouse.", true},
        {"Mechanical Keyboard", 125.00, "Full-size keyboard with RGB.", false}
    };

    displayProducts(product_list, PRODUCT_COUNT, "Unsorted Product List");

    quickSort(product_list, 0, PRODUCT_COUNT - 1);

    displayProducts(product_list, PRODUCT_COUNT, "Product List Sorted by Price (Quick Sort)");

    return 0;
}
