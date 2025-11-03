//Rupesh Jaiswal
//PRN : 123B1F036
//Date : 07-07-2025

#include <iostream>
#include <vector>
using namespace std;

// Structure for customer order
struct Order {
    long long timestamp;
    int orderId;
};

// Merge two sorted halves
void merge(vector<Order> &orders, int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    vector<Order> left(n1), right(n2);

    for (int i = 0; i < n1; i++) {
        left[i] = orders[start + i];
    }

    for (int j = 0; j < n2; j++) {
        right[j] = orders[mid + 1 + j];
    }

    int i = 0, j = 0, k = start;

    // Merge by comparing timestamps
    while (i < n1 && j < n2) {
        if (left[i].timestamp <= right[j].timestamp) {
            orders[k++] = left[i++];
        } else {
            orders[k++] = right[j++];
        }
    }

    while (i < n1) {
        orders[k++] = left[i++];
    }

    while (j < n2) {
        orders[k++] = right[j++];
    }
}

// Merge Sort function
void mergeSort(vector<Order> &orders, int start, int end) {
    if (start >= end) return;
    int mid = start + (end - start) / 2;
    mergeSort(orders, start, mid);
    mergeSort(orders, mid + 1, end);
    merge(orders, start, mid, end);
}

// Print the sorted orders
void printOrders(const vector<Order> &orders) {
    for (const auto &order : orders) {
        cout << "Order ID: " << order.orderId
             << ", Timestamp: " << order.timestamp << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of customer orders: ";
    cin >> n;

    vector<Order> orders(n);
    cout << "Enter Order ID and Timestamp:\n";
    for (int i = 0; i < n; i++) {
        cin >> orders[i].orderId >> orders[i].timestamp;
    }

    cout << "\nBefore Sorting:\n";
    printOrders(orders);

    mergeSort(orders, 0, n - 1);

    cout << "\nAfter Sorting by Timestamp:\n";
    printOrders(orders);

    return 0;
}

