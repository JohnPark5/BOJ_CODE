//만들다맒(이미제출했었음) 
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* leftChild, *rightChild;
}Node;

Node* NewNode(int data);
Node* ConstructTreeByRecursion(Node* root, int data);
Node* GetDataByPreorder(Node* root);
void PrintDataByPostorder(Node* root);
void FreeDataByPostorder(Node* root);

int main()
{
	Node* root = NULL;
	
	root = GetDataByPreorder(root);
	PrintDataByPostorder(root);
	FreeDataByPostorder(root);
	
	return 0;
}

Node* NewNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	
	return newNode;
}

Node* ConstructTreeByRecursion(Node* root, int data) {
	if(root == NULL) {
		root = NewNode(data);
	}
	else {
		if(data < root->data) {
			ConstructTreeByRecursion(root->leftChild, data);
		}
		else {
			ConstructTreeByRecursion(root->rightChild, data);
		}
	}
	return root;
}

Node* GetDataByPreorder(Node* root) {
	//int arr[10000] = {0,}, size = 0;
	int data=-1;
	while(1) {
		if(scanf("%d ",&data) == EOF) {
			break;
		}
		else {
			//size++;
			
			root = ConstructTreeByRecursion(root,data);
			data=-1;
		}
	}
	return root;
}

void PrintDataByPostorder(Node* root) {
	if(root == NULL) {
		return;
	}
	PrintDataByPostorder(root->leftChild);
	PrintDataByPostorder(root->rightChild);
	printf("%d\n",root->data);
}

void FreeDataByPostorder(Node* root) {
	if(root == NULL) {
		return;
	}
	FreeDataByPostorder(root->leftChild);
	FreeDataByPostorder(root->rightChild);
	free(root);
}
















