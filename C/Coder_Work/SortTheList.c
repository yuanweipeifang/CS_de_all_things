#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node; 

int main()
{
    int n, i, j, temp;
    node *head, *temp1, *temp2; // temp1 and temp2 are used to traverse the list

    // printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    head = (node*)malloc(sizeof(node)); // create a new node and set it as the head of the list     
    head->next = NULL; // set the next pointer of the head to NULL

    for(i=0; i<n; i++)
    {
        // printf("Enter element %d: ", i+1);  
        scanf("%d", &temp);
        temp1 = (node*)malloc(sizeof(node)); // create a new node
        temp1->data = temp; // set the data of the new node
        temp1->next = NULL; // set the next pointer of the new node to NULL
        if(i==0) // if it is the first node, set it as the head of the list
            head = temp1;
        else // otherwise, append the new node to the end of the list
        {
            temp2 = head;
            while(temp2->next!= NULL) // traverse the list until the end
                temp2 = temp2->next;
            temp2->next = temp1; // append the new node to the end of the list
        }
    }

    // printf("Original List: ");
    // temp1 = head;
    // while(temp1!= NULL) // traverse the list and print the data of each node
    // {
    //     printf("%d ", temp1->data);
    //     temp1 = temp1->next;
    // }

    // bubble sort algorithm
    for(i=0; i<n-1; i++)
    {
        temp1 = head;
        for(j=0; j<n-i-1; j++)
        {
            if(temp1->data > temp1->next->data) // if the current node is greater than the next node
            {
                temp = temp1->data; // store the data of the current node
                temp1->data = temp1->next->data; // set the data of the current node to the data of the next node
                temp1->next->data = temp; // set the data of the next node to the stored data   
            }
            temp1 = temp1->next; // move to the next node
        }
    }

    temp1 = head;
    printf("Head");
    while(temp1!= NULL) // traverse the list and print the data of each node
    {
        printf("->%d", temp1->data);
        temp1 = temp1->next;
    }

    return 0;
}