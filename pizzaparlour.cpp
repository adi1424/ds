#include <iostream>
using namespace std;

#define MAX_ORDERS 5

// Define structure for an order
struct Order {
    int orderNumber;
    string pizzaType;
};

// Define structure for a circular queue
struct CircularQueue {
    Order orders[MAX_ORDERS];
    int front, rear;
    int orderCount;
};

// Function prototypes
void initializeQueue(CircularQueue &cq);
bool isFull(CircularQueue &cq);
bool isEmpty(CircularQueue &cq);
void enqueueOrder(CircularQueue &cq, Order newOrder);
void displayOrders(CircularQueue &cq);

int main() {
    CircularQueue cq;
    initializeQueue(cq);

    int choice;
    Order newOrder;

    do {
        // Display menu
        cout << "\nMenu:\n";
        cout << "1. Place Order\n";
        cout << "2. Display Orders\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (!isFull(cq)) {
                    cout << "Enter pizza type for the order: ";
                    cin >> newOrder.pizzaType;
                    newOrder.orderNumber = cq.orderCount + 1;
                    enqueueOrder(cq, newOrder);
                    cout << "Order placed successfully.\n";
                } else {
                    cout << "Sorry, the pizza parlour is full. Cannot accept more orders.\n";
                }
                break;
            case 2:
                displayOrders(cq);
                break;
            case 3:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 3);

    return 0;
}

// Function to initialize the circular queue
void initializeQueue(CircularQueue &cq) {
    cq.front = -1;
    cq.rear = -1;
    cq.orderCount = 0;
}

// Function to check if the circular queue is full
bool isFull(CircularQueue &cq) {
    return (cq.front == (cq.rear + 1) % MAX_ORDERS && cq.orderCount == MAX_ORDERS);
}

// Function to check if the circular queue is empty
bool isEmpty(CircularQueue &cq) {
    return (cq.front == -1 && cq.rear == -1);
}

// Function to enqueue an order into the circular queue
void enqueueOrder(CircularQueue &cq, Order newOrder) {
    if (isEmpty(cq)) {
        cq.front = 0;
        cq.rear = 0;
    } else {
        cq.rear = (cq.rear + 1) % MAX_ORDERS;
    }

    cq.orders[cq.rear] = newOrder;
    cq.orderCount++;
}

// Function to display the orders in the circular queue
void displayOrders(CircularQueue &cq) {
    if (isEmpty(cq)) {
        cout << "No orders placed yet.\n";
    } else {
        cout << "Orders:\n";
        int i = cq.front;
        do {
            cout << "Order Number: " << cq.orders[i].orderNumber << ", Pizza Type: " << cq.orders[i].pizzaType << "\n";
            i = (i + 1) % MAX_ORDERS;
        } while (i != (cq.rear + 1) % MAX_ORDERS);
    }
}
