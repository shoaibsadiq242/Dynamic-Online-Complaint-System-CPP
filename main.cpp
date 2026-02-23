#include <iostream>
#include <string>
using namespace std;

struct Complaint {
    int id;
    string name;
    string category;
    int priority;
    string status;
};

/* ================= DYNAMIC QUEUE ================= */
class Queue {
private:
    Complaint* arr;
    int front;
    int rear;
    int capacity;

    void resize() {
        int newCapacity = capacity * 2;
        Complaint* newArr = new Complaint[newCapacity];

        int j = 0;
        for (int i = front; i <= rear; i++) {
            newArr[j++] = arr[i];
        }

        delete[] arr;
        arr = newArr;
        front = 0;
        rear = j - 1;
        capacity = newCapacity;
    }

public:
    Queue(int size = 2) {
        capacity = size;
        arr = new Complaint[capacity];
        front = -1;
        rear = -1;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    void enqueue(Complaint c) {
        if (rear == capacity - 1)
            resize();

        if (front == -1)
            front = 0;

        arr[++rear] = c;
    }

    Complaint dequeue() {
        Complaint temp;
        temp.id = -1;

        if (isEmpty()) {
            cout << "No complaints to process.\n";
            return temp;
        }

        temp = arr[front++];
        return temp;
    }
};

/* ================= DYNAMIC STACK ================= */
class Stack {
private:
    Complaint* arr;
    int top;
    int capacity;

    void resize() {
        int newCapacity = capacity * 2;
        Complaint* newArr = new Complaint[newCapacity];

        for (int i = 0; i <= top; i++)
            newArr[i] = arr[i];

        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

public:
    Stack(int size = 2) {
        capacity = size;
        arr = new Complaint[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(Complaint c) {
        if (top == capacity - 1)
            resize();

        arr[++top] = c;
    }

    void display() {
        if (top == -1) {
            cout << "No resolved complaints.\n";
            return;
        }

        for (int i = top; i >= 0; i--) {
            cout << "ID: " << arr[i].id
                << " | Name: " << arr[i].name << endl;
        }
    }
};

/* ================= SYSTEM ================= */
class ComplaintSystem {
private:
    Queue pending;
    Stack resolved;

    Complaint* allComplaints;
    int total;
    int capacity;

    void resize() {
        int newCapacity = capacity * 2;
        Complaint* newArr = new Complaint[newCapacity];

        for (int i = 0; i < total; i++)
            newArr[i] = allComplaints[i];

        delete[] allComplaints;
        allComplaints = newArr;
        capacity = newCapacity;
    }

    bool isIdUnique(int id) {
        for (int i = 0; i < total; i++)
            if (allComplaints[i].id == id)
                return false;
        return true;
    }

public:
    ComplaintSystem(int size = 2) {
        capacity = size;
        total = 0;
        allComplaints = new Complaint[capacity];
    }

    ~ComplaintSystem() {
        delete[] allComplaints;
    }

    void addComplaint() {
        Complaint c;

        cout << "\nEnter Complaint ID: ";
        cin >> c.id;

        if (!isIdUnique(c.id)) {
            cout << "ID already exists!\n";
            return;
        }

        cout << "Enter Name: ";
        cin >> c.name;

        cout << "Enter Category: ";
        cin >> c.category;

        cout << "Enter Priority (1=High,2=Medium,3=Low): ";
        cin >> c.priority;

        c.status = "Pending";

        if (total == capacity)
            resize();

        pending.enqueue(c);
        allComplaints[total++] = c;

        cout << "Complaint Added Successfully!\n";
    }

    void editComplaint() {
        int id;
        cout << "Enter Complaint ID to Edit: ";
        cin >> id;

        for (int i = 0; i < total; i++) {
            if (allComplaints[i].id == id) {

                cout << "Enter New Name: ";
                cin >> allComplaints[i].name;

                cout << "Enter New Category: ";
                cin >> allComplaints[i].category;

                cout << "Enter New Priority: ";
                cin >> allComplaints[i].priority;

                cout << "Complaint Updated!\n";
                return;
            }
        }

        cout << "Complaint Not Found.\n";
    }

    void processComplaint() {
        Complaint c = pending.dequeue();
        if (c.id == -1)
            return;

        c.status = "Resolved";

        for (int i = 0; i < total; i++)
            if (allComplaints[i].id == c.id)
                allComplaints[i].status = "Resolved";

        resolved.push(c);
        cout << "Complaint ID " << c.id << " Resolved.\n";
    }

    void analytics() {
        int high = 0, medium = 0, low = 0;

        for (int i = 0; i < total; i++) {
            if (allComplaints[i].priority == 1) high++;
            else if (allComplaints[i].priority == 2) medium++;
            else if (allComplaints[i].priority == 3) low++;
        }

        cout << "\nHigh: " << high
            << "\nMedium: " << medium
            << "\nLow: " << low
            << "\nTotal: " << total << endl;
    }

    void showResolved() {
        resolved.display();
    }
};

/* ================= MAIN ================= */
int main() {
    ComplaintSystem system;

    int choice;

    do {
        cout << "\n===== Online Complaint System =====\n";
        cout << "1. Add Complaint\n";
        cout << "2. Edit Complaint\n";
        cout << "3. Process Complaint\n";
        cout << "4. Analytics\n";
        cout << "5. Show Resolved History\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: system.addComplaint(); break;
        case 2: system.editComplaint(); break;
        case 3: system.processComplaint(); break;
        case 4: system.analytics(); break;
        case 5: system.showResolved(); break;
        case 6: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}