/*
プライオリティキュー
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C&lang=jp
*/

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

Tnode* Tfind(Tnode *rootNode, int key){
  Tnode *currentNode = rootNode;
  while(currentNode != NULL){
    if(DEBUG) printf("Tfind: %d l:%d r:%d\n", currentNode->key, currentNode->l != NULL, currentNode->r != NULL);
    
    if(currentNode->key == key) return currentNode;

    if(currentNode->key > key) currentNode = currentNode->l;
    else currentNode = currentNode->r;
  }

  return NULL;
}

void Tmin(Tnode *currentNode, Tnode **minNode){
    if(currentNode->l != NULL) {
      Tmin(currentNode->l, minNode);
    }
    if(*minNode == NULL) *minNode = currentNode;
    if(currentNode->r != NULL){
      return Tmin(currentNode->r, minNode);
    }
}

Tnode* TdeleteByPointer(Tnode *rootNode, Tnode *targetNode){
  if(rootNode == NULL ) return NULL;
  if(targetNode == NULL) return rootNode;

  if(DEBUG) printf("TdeleteByPointer key:%d l:%d r:%d\n", targetNode->key, targetNode->l != NULL, targetNode->r != NULL);

  //削除したいノードに子がないなら削除して、親がもつポインタもNULLにする
  if(targetNode->l == NULL && targetNode->r == NULL) {
    if(targetNode->p != NULL) {
      if(targetNode == targetNode->p->l ) targetNode->p->l = NULL;
      else targetNode->p->r = NULL;
    }
    
    if(targetNode == rootNode) rootNode =NULL;
    free(targetNode);
    return rootNode;  
  }

  //削除したいノードが1つだけ子を持つなら、その子の親を削除したいノードの親にし、削除したいノードの親の子を、削除したいノードの子にして、削除したいノードを消す
  if(targetNode->l == NULL || targetNode->r == NULL){
    Tnode *parent = targetNode->p;
    Tnode *child = (targetNode->l != NULL ? targetNode->l : targetNode->r);  
    
    if(DEBUG) printf("ENTER PisNULL:%d\n", parent == NULL);

    //削除したノードが根だった場合
    if(parent == NULL) {
      rootNode = child;
      child->p = NULL;
    }
    else{
      //子の親をつなぎ替える
      child-> p = parent;
      //親の子をつなぎ替える
      if(targetNode ==  parent->l) parent->l = child;
      else parent->r = child;
    }
    free(targetNode);
    return rootNode;  
  }
  
  //削除したいノードが2つ子を持つ場合、中間順巡回で次になるノードのキーをもち、そのノードを削除する
  if(targetNode->l != NULL && targetNode->r != NULL){
    Tnode *nextNode;
    Tmin(targetNode->r, &nextNode);

    targetNode->key = nextNode->key;
    return TdeleteByPointer(rootNode, nextNode); 
  }
  
}

Tnode *Tdelete(Tnode *rootNode, int key){
  Tnode *targetNode = Tfind(rootNode, key);
  if(targetNode == NULL ){
    printf("NOT FOUND\n");
    return rootNode;
  }

  return TdeleteByPointer(rootNode, targetNode); 
}

Tnode * Tmax(Tnode *rootNode){
  Tnode *currentNode = rootNode;
  Tnode *previousNode = NULL;
  while(currentNode != NULL){
    previousNode = currentNode;
    currentNode = currentNode->r;
  }

  return previousNode;
}

int main(){
  Tnode *rootNode;
  rootNode = NULL;

  while(1){
    string tmpCommand;
		cin >>   tmpCommand;
	  if(DEBUG) printf("%s\n", tmpCommand.c_str());
		int tmpOp;
    //end命令
		if(tmpCommand.c_str()[0] == 'e' && tmpCommand.c_str()[1] == 'n') break;
    //extract命令
    else if(tmpCommand.c_str()[0] == 'e'){
        Tnode* tmpMaxNode = Tmax(rootNode);
        if(tmpMaxNode == NULL) printf("MAX ERROR\n");
        printf("%d\n", tmpMaxNode->key);
        rootNode = TdeleteByPointer(rootNode, tmpMaxNode);
        if(DEBUG) printf("end extract\n");
    }
    //insert命令
    else if(tmpCommand.c_str()[0] == 'i'){
				cin >> tmpOp;
        if(DEBUG) printf("insert %d\n", tmpOp);
        Tnode* tmpNewNode = (Tnode *) malloc(sizeof(Tnode));
        
        tmpNewNode->key = tmpOp;
        tmpNewNode->l = NULL;
        tmpNewNode->r = NULL;
        tmpNewNode->p = NULL;
				
        rootNode = Tinsert(rootNode, tmpNewNode);
    }else{
      printf("INPUT ERROR\n");
    }
	}
  
  return 0;
}
