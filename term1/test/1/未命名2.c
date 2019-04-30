#include<stdio.h>
#include <stdlib.h>
typedef struct _node {
    void *data;
    struct _node *next;
} Node;
typedef struct _linkedlist {
    Node *head;
    Node *tail;
} LinkedList;
void initialize_list (LinkedList *list);
void add_(LinkedList *list,Node *pre);
void delete_next(LinkedList *list, Node *pre);
void find_(LinkedList *list,Node *pre,int n);
int is_empty(LinkedList *list);
int is_singleton(LinkedList *list);


int main(){
	int time=0,i=0,j=0;
	char operation=0;
    LinkedList list;
    initialize_list(&list);
    Node pointer;
	for(scanf("%d",&time);time>0;time--){
		while(operation=='\n'||operation==' ')scanf("%c",&operation);
		if(operation=='D'){
			scanf("%d",&i);
			find_(&list,&pointer,i);
			delete_next(&list,&pointer);
		}
		if(operation=='A'){
			scanf("%d",&i);
			find_(&list,&pointer,i);
			add_(&list,&pointer);
		}
		if(operation=='S'){
		}
		if(operation=='P'){
			pointer.next=list.head;
			while(pointer!=list.tail){
				find_(&list,&pointer,1);
				printf("%c",pointer->data);
			}
			printf("\n");
		}
	}
	return 0;
}

void initialize_list(LinkedList *list) {
    list->head = NULL;
    list->tail = NULL;
}

int is_empty(LinkedList *list) {
    return list->head == NULL;
}

int is_singleton(LinkedList *list) {
    return (list->head != NULL)
           && (list->head == list->tail);
}

void add_(LinkedList *list,Node *pre) {
	char data;
	scanf("%c",&data);
    Node *node =(Node *) malloc(sizeof(Node));
    node->data = data;

    if (is_empty(list)) {
        list->head = node;
        node->next=node;
	} else {
    node->next=pre->next;
	pre->next=node;
	}
}


void delete_next(LinkedList *list, Node *pre) {
    if (is_empty(list))
        return;

    if (is_singleton(list)) {
        list->head = NULL;
        list->tail = NULL;
        free(pre);
        return;
    }

    Node *node = pre->next;
    pre->next = node->next;

    if (node == list->head) {
        list->head = node->next;
    }

    if (node == list->tail) {
        list->tail = pre;
    }

    free(node);
}
void find_(LinkedList *list,Node *pre,int n){
    if (!is_empty(list)){
    	pre->next=list->tail;
		while(n>0){
			pre->next=pre->next->next;
		}
	}
}
