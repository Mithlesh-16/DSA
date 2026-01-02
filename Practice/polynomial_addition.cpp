#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int coeff;
    int power;
    Node* next;

    Node(int c, int p) {
        coeff = c;
        power = p;
        next = NULL;
    }
};

void insertTerm(Node* &head, int coeff, int power) {                // Insert at end (maintains order if user inputs sorted terms)
    Node* newNode = new Node(coeff, power);

    if (!head) {
        head = newNode;
        return;
    }

    Node* curr = head;
    while (curr->next)
        curr = curr->next;
    curr->next = newNode;
}

void printPoly(Node* head) {                        // Print polynomial nicely
    if(!head){
        cout << "0\n";
        return;
    }

    while (head) {
        cout << head->coeff << "x^" << head->power;
        if (head->next) cout << " + ";
        head = head->next;
    }
    cout << endl;
}

Node* addPolynomials(Node* p1, Node* p2) {                 // Actual addition
    Node* result = NULL;
    Node* tail = NULL;

    while (p1 && p2) {
        if (p1->power == p2->power) {
            int sumCoeff = p1->coeff + p2->coeff;
            if (sumCoeff != 0) {
                insertTerm(result, sumCoeff, p1->power);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->power > p2->power) {
            insertTerm(result, p1->coeff, p1->power);
            p1 = p1->next;
        }
        else {
            insertTerm(result, p2->coeff, p2->power);
            p2 = p2->next;
        }
    }

    while (p1) {                            // Append remaining terms
        insertTerm(result, p1->coeff, p1->power);
        p1 = p1->next;
    }

    while (p2) {
        insertTerm(result, p2->coeff, p2->power);
        p2 = p2->next;
    }

    return result;
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;

    // Example polynomial 1: 3x^3 + 4x^2 + 2x + 1
    insertTerm(poly1, 3, 3);
    insertTerm(poly1, 4, 2);
    insertTerm(poly1, 2, 1);
    insertTerm(poly1, 1, 0);

    // Example polynomial 2: 5x^2 + 2x + 7
    insertTerm(poly2, 5, 2);
    insertTerm(poly2, 2, 1);
    insertTerm(poly2, 7, 0);

    cout << "Polynomial 1: ";
    printPoly(poly1);

    cout << "Polynomial 2: ";
    printPoly(poly2);

    Node* result = addPolynomials(poly1, poly2);

    cout << "\nResult: ";
    printPoly(result);

    return 0;
}
