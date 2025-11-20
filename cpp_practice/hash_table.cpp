#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

const int SIZE = 10;
vector<node*> hashTable(SIZE, NULL);

//------------------HASH FUNCTION------------------
int hashFunc(int key){
    return key % SIZE;
}

//------------------INSERT------------------
void insertVal(int key){
    int index = hashFunc(key);
    node* newNode = new node(key);

    if(hashTable[index] == NULL){
        hashTable[index] = newNode;
    }
    else{
        node* temp = hashTable[index];
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    cout << key << " inserted at index " << index << endl;
}

//------------------SEARCH------------------
bool searchVal(int key){
    int index = hashFunc(key);
    node* temp = hashTable[index];

    while(temp != NULL){
        if(temp->data == key){
            cout << key << " found at index " << index << endl;
            return true;
        }
        temp = temp->next;
    }

    cout << key << " not found" << endl;
    return false;
}

//------------------DELETE------------------
void deleteVal(int key){
    int index = hashFunc(key);
    node* temp = hashTable[index];
    node* prev = NULL;

    if(temp == NULL){
        cout << "No element present at index " << index << endl;
        return;
    }

    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        cout << key << " not found in table" << endl;
        return;
    }

    if(prev == NULL){
        hashTable[index] = temp->next;
    }
    else{
        prev->next = temp->next;
    }

    delete temp;
    cout << key << " deleted successfully" << endl;
}

//------------------DISPLAY------------------
void display(){
    cout << "\nHash Table State:\n";
    for(int i = 0; i < SIZE; i++){
        cout << i << " -> ";
        node* temp = hashTable[i];
        while(temp){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
    cout << endl;
}

//------------------MAIN (MENU DRIVEN)------------------
int main(){
    while(true){
        cout << "\nMENU\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        int choice;
        cin >> choice;
        if(choice == 1){
            int val;
            cout << "Enter value to insert: ";
            cin >> val;
            insertVal(val);}
        else if(choice == 2){
            int val;
            cout << "Enter value to search: ";
            cin >> val;
            searchVal(val);}
        else if(choice == 3){
            int val;
            cout << "Enter value to delete: ";
            cin >> val;
            deleteVal(val);
        }
        else if(choice == 4){
            display();
        }
        else if(choice == 5){
            break;
        }
        else{
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
