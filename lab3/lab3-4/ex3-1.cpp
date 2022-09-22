// ex3-1.cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};
// global variable root is used to record the head of link list
Node* root = NULL;

void InsertNode(int data);
bool DeleteNode(int data);
void Display();

int main() {
    size_t i = 0;
    while(1) {
        cout << "Please select an option:" << endl
             << "1.Insert a node" << endl
             << "2.Delete a node" << endl
             << "3.Display the list" << endl
             << "4.End" << endl;
        cin >> i;
        int data;
        switch(i)
        {
            case 1:
                cout << "Please enter the number:" << endl;
                cin >> data;
                InsertNode(data);
                break;
            case 2:
                cout << "Please enter the number:" << endl;
                cin >> data;
                if (!DeleteNode(data))
                    cout << "Failed to delete node " << data << endl;
                break;
            case 3:
                Display();
                break;
            case 4:
                return 0;
                break;
            default:
                break;
        }
    }
}

void InsertNode(int data) {
    if (root == NULL) {
        root = new Node();
        root->data = data;
        root->next = NULL;
    }
    else {
        Node *ptr = root;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }

        ptr->next = new Node();
        ptr = ptr->next;
        ptr->data = data;
        ptr->next = NULL;
    }
}

bool DeleteNode(int data) {
    Node *ptr = root;
    int length = 0;
    while (ptr != NULL) {
        ptr = ptr->next;
        length++;
    }

    if (length == 0) {
        cout << "The link list is empty." << endl;
        return 0;
    }
    else if (length == 1) {
        if (data==1) {
            delete root;
            root = NULL;
        }
        else {
            cout << "The input index is out of range." << endl;
            return 0;
        }
    }
    else {
        if (data == 1) {
            ptr = root;
            root = root->next;
            delete ptr;
        }
        else if ((data <= length) && (data >= 2)) {
            // find the element before the deleted node
            ptr = root;
            for (int i = 2; i < data; i++) {
                ptr = ptr->next;

            }
            Node *del = ptr->next;
            ptr->next = del->next;
            delete del;
        }
        else {
            cout << "The input index is out of range." << endl;
            return 0;
        }
    }

    return 1;
}

void Display() {
    Node* ptr = root;
    while (ptr != NULL) {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << endl;
}
