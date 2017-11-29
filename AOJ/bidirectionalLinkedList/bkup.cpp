#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
#include <utility>
#include <queue>
#include <algorithm>

typedef int type;
using namespace std;
const bool isDebug = true;

struct bl_node{
    type item;
    struct bl_node *next;
    struct bl_node *prev;
};

bl_node boundNode = {-1, NULL, NULL};
bl_node *head;
bl_node *tail;

void init(){
    head = &boundNode;
    tail = &boundNode;
}

void insert(  type item){
    bl_node *newNode = (bl_node *)malloc(sizeof(bl_node));
    newNode->item = item;
    newNode->next = head;
    newNode->prev = &boundNode;
    

    //初めの1個のときだけ、headもtailも同じものを指す
    if(head==&boundNode){ 
        tail = newNode; 
        if(isDebug) printf("FIRST ONE CREATED\n");
    }
    else{ 
        head->prev = newNode;
        if(isDebug) printf("NOT FIRST ONE CREATED\n");
    }
    
    head = newNode;
}

void deleteItem(type item){
    bl_node *currentNode = head;
    while(currentNode != &boundNode){
        if(currentNode->item == item){
            bl_node *cnext = currentNode->next;
            bl_node *cprev = currentNode->prev;

            cnext->prev = cprev;
            cprev->next = cnext;
            if(currentNode == head){
                head = cnext;
            }else if(currentNode == tail){
                tail = cprev;
            }
            free(currentNode);
            return;
        }
        currentNode = currentNode->next;
    }
}

void deleteFirst(){
    if(head == &boundNode) return;

    bl_node *cnext = head->next;
    cnext->prev = &boundNode;

    if(head == tail){
        tail = cnext;
    }
    free(head);
    head = cnext;
}

void deleteLast(){
    if(tail == &boundNode) return;

    bl_node *cprev = tail->prev;
    cprev->next = &boundNode;

    if(head == tail){
        head = cprev;
    }
    free(tail);
    tail = cprev;
}


void traceHE(){
    if(head == &boundNode) return;

    bl_node *cnode = head;
    while(cnode != &boundNode){
        printf("%d", cnode->item);
        cnode = cnode->next;
        if(cnode != &boundNode) printf(" ");
    }
    printf("\n");
}

int n;


void solve(){
    cin >> n;

    init();

    for(int i=0; i<n; i++){
        string command;
        cin >> command;
        
        type item;
        if(command == "insert"){
            if(isDebug) printf("insert\n");
            cin >> item;
            insert(item);
        }else if(command == "delete"){
            if(isDebug) printf("delete\n");
            cin >> item;
            deleteItem(item);
        }else if(command == "deleteFirst"){
            if(isDebug) printf("deleteFirst\n");
            deleteFirst();
        }else if(command == "deleteLast"){
            if(isDebug) printf("deleteLast\n");
            deleteLast();
        }else{
            printf("COMMAND ANOMALY\n");
        }
        if(isDebug) traceHE();
        if(isDebug) printf("\n");
    }

    traceHE();    
}

int main(){
    solve();
    return 0;
}
