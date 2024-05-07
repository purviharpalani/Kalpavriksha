#include<stdio.h>
#include<stdlib.h>

struct Node{
    void *data;
    struct Node *next;
};

void push(struct Node** head, void* data, size_t data_size){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = malloc(data_size);
    newNode->next = (*head);

    for(int i=0; i<data_size; i++){
        *(char *)(newNode->data + i) = *(char *)(data + i);
    }
    (*head) = newNode;
}

void printLL(struct Node * node, void (*ptr_type)(void *)){
    while(node!=NULL){
        (*ptr_type)(node->data);
        node = node->next;
    }
}

void printInt(void *x){
    printf(" %d", *(int *)x);
}

void printFloat(void *x){
    printf(" %f", *(float *)x);
}

int main(){
    struct Node *startNode = NULL;
    int choice;
    int size = 0;
    printf("Choose the data type of linked list to be created:\n1. int\n2. float\n");
    scanf("%d",&choice);
    if(choice == 1){
        printf("Enter the number of elements:");
        scanf("%d",&size);
        int arr[size];
        printf("Enter int elements:\n");
        unsigned int_size = sizeof(int);
        for(int i=size-1; i>=0; i--){
            scanf("%d", &arr[i]);
            push(&startNode, &arr[i], int_size);
        }

        printf("\nLinked List:\n");
        printLL(startNode, printInt);
    }
    else if(choice == 2){
        printf("Enter the number of elements:");
        scanf("%d",&size);
        float arr[size];
        printf("Enter float elements:\n");
        unsigned float_size = sizeof(float);
        for(int i=size-1; i>=0; i--){
            scanf("%f", &arr[i]);
            push(&startNode, &arr[i], float_size);
        }

        printf("\nLinked List:\n");
        printLL(startNode, printFloat);
    }
    else{
        printf("Invalid choice");
    } 
}
