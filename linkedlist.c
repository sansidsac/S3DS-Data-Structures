#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *first = NULL;
struct node *ptr = NULL;
struct node *s = NULL;

int addNode(int item)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = item;
    newNode->link = NULL;
    if (first == NULL)
        first = newNode;
    else
    {
        ptr = first;
        while (ptr->link != NULL)
            ptr = ptr->link;
        ptr->link = newNode;
    }
    return 0;
}

int deleteNode(int item)
{
    ptr = first;
    while (ptr != NULL && ptr->data != item)
    {
        s = ptr;
        ptr = ptr->link;
    }
    if (ptr->link == NULL)
    {
        free(ptr);
        s->link = NULL;
    }
    else if (ptr == first)
    {
        first = ptr->link;
        free(ptr);
    }
    else
    {
        s->link = ptr->link;
        free(ptr);
    }
}

int displayNode()
{
    ptr = first;
    while (ptr != NULL)
    {
        printf("\n%d", ptr->data);
        ptr = ptr->link;
    }
    return 0;
}

int main()
{
    int menu = 1, item;
    while (menu == 1 || menu == 2 || menu == 3)
    {
        printf("\nMenu\n.....\n1.Add element 2.Delete element 3.Display list 4.Exit\nEnter the action: ");
        scanf("%d", &menu);
        if (menu == 1)
        {
            printf("\nEnter element to be added : ");
            scanf("%d", &item);
            addNode(item);
        }
        else if (menu == 2)
        {
            printf("\nEnter element to be deleted : ");
            scanf("%d", &item);
            deleteNode(item);
        }
        else if (menu == 3)
            displayNode();
    }
    return 0;
}