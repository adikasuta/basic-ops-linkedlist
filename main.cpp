#include <stdio.h>
#include <stdlib.h>

struct node{
	int value;
	struct node *next;
} typedef Node;

void printList(Node* n){
	printf("\n");
    while (n != NULL) {
        printf("%d,",n->value);
        n = n->next;
    }
}

int getSize(Node* n){
	int size=0;
    while (n != NULL) {
        size++;
        n = n->next;
    }
    return size;
}

void add(Node **head, int value, int index){
	Node * temp1 = (Node*)malloc(sizeof(Node));
	temp1->value = value;
	temp1->next = NULL;
	if(index==1){
		temp1->next = *head;
		*head = temp1;
		return;
	}
	Node * temp2 = *head;
	for(int i=0; i<index-2;i++){
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
}

void addHead(Node **head, int value){
	return add(head,value,1);
}

void addTail(Node **head, int value){
	return add(head,value,getSize(*head)+1);
}


void deleteNode(Node **head, int index){
	Node *temp1 = *head;
	
	if(index == 1){
		*head = temp1->next;
		free(temp1);
		return;
	}
	
	for(int i=0;i<index-2;i++){
		temp1 = temp1->next;
	}
	
	Node *temp2 = temp1->next;
	temp1->next = temp2->next;
	free(temp2);
}

int main(void) {
	Node *list = NULL;
	add(&list, 1,1);
	add(&list, 2,1);
	add(&list, 3,3);
	addTail(&list, 4);
	addTail(&list, 5);
	addTail(&list, 6);
	addHead(&list, 0);
	addHead(&list, -1);
	printList(list);
	
	deleteNode(&list, 4);
	deleteNode(&list, 1);
	printList(list);
	return 0;
}
