#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node {
    int umur;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

Node* newNode(int umur) {
    Node* createNode = (Node*)malloc(sizeof(Node));
    createNode->umur = umur;
    createNode->next = NULL;
    return createNode;
}

void pushHead(int umur) {
    Node* toInsert = newNode(umur);
    if (head == NULL) {
        head = toInsert;
        tail = toInsert;
    } else {
        toInsert->next = head;
        head = toInsert;
    }
}

void pushTail(int umur) {
    Node* toInsert = newNode(umur);
    if (tail == NULL) {
        tail = toInsert;
        head = toInsert;
    } else {
        tail->next = toInsert;
        tail = toInsert;
    }
}

void pushMid(int umur) {
    Node* toInsert = newNode(umur);
    if (head == NULL) {
        head = toInsert;
        tail = toInsert;
    } else if (head->umur > umur) {
        pushHead(umur);
    } else if (tail->umur < umur) {
        pushTail(umur);
    } else {
        Node* curr = head;
        while (curr->next != NULL && curr->next->umur > toInsert->umur) {
            curr = curr->next;
        }
        toInsert->next = curr->next;
        curr->next = toInsert;
    }
}

void print() {
    Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->umur);
        curr = curr->next;
    }
    printf("\n");
}

void popHead() {
    if (head == NULL) return;
    Node* temp = head->next;
    free(head);
    head = temp;
}

void popTail() {
    if (tail == NULL) return;
    if (head == tail) {
        popHead();
        return;
    }
    Node* curr = head;
    while (curr->next != tail) {
        curr = curr->next;
    }
    free(tail);
    tail = curr;
    tail->next = NULL;
}

void popMid(int key) {
    if (head == NULL) {
        puts("No data");
        return;
    }
    if (head->umur == key) {
        popHead();
        return;
    }
    Node* curr = head;
    while (curr->next != NULL && curr->next->umur != key) {
        curr = curr->next;
    }
    if (curr->next != NULL) {
        Node* del = curr->next;
        curr->next = del->next;
        free(del);
    } else {
        printf("%d not found\n", key);
    }
}

int main() {
    pushHead(30);
    pushTail(40);
    pushMid(35);
    pushHead(20);
    pushTail(50);
    print();
    
    popHead();
    popTail();
    popMid(35);
    print();
    
    return 0;
}

