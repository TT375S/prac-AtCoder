#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
const bool DEBUG = false;

struct Tnode{
  int key;
  Tnode *l;
  Tnode *r;
  Tnode *p;
};

void preorder(Tnode *currentNode){
    printf(" %d", currentNode->key);
		if(currentNode->l != NULL) preorder(currentNode->l);
    if(currentNode->r != NULL) preorder(currentNode->r);
}

void inorder(Tnode *currentNode){
    if(currentNode->l != NULL) inorder(currentNode->l);
		printf(" %d", currentNode->key);
    if(currentNode->r != NULL) inorder(currentNode->r);
}

//rootNodeと新しいノードを渡すと、新しいrootNodeのポインタを返す
Tnode* Tinsert(Tnode *rootNode, Tnode *newNode){
  Tnode *parent;
  Tnode *currentNode = rootNode;
  //newNodeを突っ込むべき場所を探す
  while(currentNode != NULL){
    parent = currentNode;
    if(newNode->key < currentNode->key) currentNode = currentNode->l;
    else currentNode = currentNode->r;
  }
  newNode->p = parent;

  //rootNodeがカラならこいつが最初の一個
  if(parent == NULL) return newNode;
  //大小を見て接続方法変える
  else if(newNode->key < parent->key) parent->l = newNode;
  else parent->r = newNode;
  return rootNode;
}

bool Tfind(Tnode *rootNode, int key){
  Tnode *currentNode = rootNode;
  while(currentNode != NULL){
    if(DEBUG) printf("Tfind: %d l:%d r:%d\n", currentNode->key, currentNode->l == NULL, currentNode->r == NULL);
    
    if(currentNode->key == key) return true;

    if(currentNode->key > key) currentNode = currentNode->l;
    else currentNode = currentNode->r;
  }

  return false;
}

int main(){
  int n;
  cin >> n;

  Tnode *rootNode;
  rootNode = NULL;

  for(int i = 0; i<n; i++){
    string tmpCommand;
		cin >>   tmpCommand;
	  
		int tmpOp;
		switch(tmpCommand.c_str()[0]){
			//findのとき
			case 'f':
				cin >> tmpOp;
				if(Tfind(rootNode, tmpOp)) printf("yes\n");
				else printf("no\n");
				break;
			//printのとき
			case 'p':
				inorder(rootNode);
				printf("\n");
        preorder(rootNode);
        printf("\n");
				break;
			//insertのとき
			case 'i':
				cin >> tmpOp;
        Tnode *tmpNewNode = (Tnode *) malloc(sizeof(Tnode));
        
        tmpNewNode->key = tmpOp;
        tmpNewNode->l = NULL;
        tmpNewNode->r = NULL;
        tmpNewNode->p = NULL;
				
        rootNode = Tinsert(rootNode, tmpNewNode); 
				break;
		}  
	}
  
  return 0;
}
