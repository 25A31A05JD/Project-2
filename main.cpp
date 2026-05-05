#include <iostream>
using namespace std;

struct Item {
    int id;
    string name;
    int quantity;
    float price;
    Item* next;
};

class Inventory {
private:
    Item* head;

public:
    Inventory() {
        head = NULL;
    }

    // Add Item
    void addItem(int id, string name, int quantity, float price) {
        Item* newItem = new Item{id, name, quantity, price, NULL};

        if (head == NULL) {
            head = newItem;
        } else {
            Item* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newItem;
        }
        cout << "Item added successfully\n";
    }

    // Display Items
    void display() {
        if (head == NULL) {
            cout << "Inventory is empty\n";
            return;
        }

        Item* temp = head;
        while (temp != NULL) {
            cout << "ID: " << temp->id
                 << " | Name: " << temp->name
                 << " | Qty: " << temp->quantity
                 << " | Price: " << temp->price << endl;
            temp = temp->next;
        }
    }

    // Search Item
    void search(int id) {
        Item* temp = head;
        while (temp != NULL) {
            if (temp->id == id) {
                cout << "Found: " << temp->name << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Item not found\n";
    }

    // Update Quantity
    void update(int id, int qty) {
        Item* temp = head;
        while (temp != NULL) {
            if (temp->id == id) {
                temp->quantity = qty;
                cout << "Updated successfully\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Item not found\n";
    }

    // Delete Item
    void deleteItem(int id) {
        if (head == NULL) return;

        if (head->id == id) {
            Item* del = head;
            head = head->next;
            delete del;
            cout << "Deleted\n";
            return;
        }

        Item* temp = head;
        while (temp->next != NULL && temp->next->id != id)
            temp = temp->next;

        if (temp->next == NULL) {
            cout << "Item not found\n";
            return;
        }

        Item* del = temp->next;
        temp->next = temp->next->next;
        delete del;
        cout << "Deleted\n";
    }
};

int main() {
    Inventory inv;
    int choice, id, qty;
    string name;
    float price;

    while (true) {
        cout << "\n1.Add 2.Display 3.Search 4.Update 5.Delete 6.Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter ID Name Qty Price:\n";
                cin >> id >> name >> qty >> price;
                inv.addItem(id, name, qty, price);
                break;

            case 2:
                inv.display();
                break;

            case 3:
                cout << "Enter ID:\n";
                cin >> id;
                inv.search(id);
                break;

            case 4:
                cout << "Enter ID and new Qty:\n";
                cin >> id >> qty;
                inv.update(id, qty);
                break;

            case 5:
                cout << "Enter ID:\n";
                cin >> id;
                inv.deleteItem(id);
                break;

            case 6:
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}
