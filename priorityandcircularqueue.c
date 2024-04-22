#include <stdio.h>
#include <stdlib.h>
int cqueuefront = 0, cqueuerear = 0, cqueuesize, cqueue[10];
int pqueuefront = -1, pqueuerear = -1, pqueuesize;
struct priorityqueuestruct
{
    int item;
    int prio;
} pqueue[10];

void insertpriorityqueue(int item, int prio)
{
    if (pqueuefront == -1)
    {
        pqueuefront = 0;
    }
    pqueuerear++;
    if (pqueuerear == pqueuesize)
    {
        printf("\nQueue full");
    }
    else
    {
        pqueue[pqueuerear].item = item;
        pqueue[pqueuerear].prio = prio;
        for (int i = pqueuerear; i > 0; i++)
        {
            if (pqueue[i].prio > pqueue[i - 1].prio)
            {
                int temp = pqueue[i].item;
                pqueue[i].item = pqueue[i - 1].item;
                pqueue[i - 1].item = temp;
                temp = pqueue[i].prio;
                pqueue[i].prio = pqueue[i - 1].prio;
                pqueue[i - 1].prio = temp;
            }
            else
            {
                break;
            }
        }
    }
}

void deletepriorityqueue()
{
    if (pqueuefront == -1 || pqueuefront > pqueuerear)
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nDeleted element is %d of priority %d", pqueue[pqueuefront].item, pqueue[pqueuefront].prio);
        pqueuefront++;
    }
}

void displaypriorityqueue()
{
    if (pqueuefront == -1 || pqueuefront > pqueuerear)
    {
        printf("\nQueue is empty");
    }
    else
    {
        for (int i = pqueuefront; i <= pqueuerear; i++)
        {
            printf("\n%d of priority %d", pqueue[i].item, pqueue[i].prio);
        }
    }
}
void priorityqueue()
{
    int op = 0;
    printf("\nEnter size of priority queue: ");
    scanf("%d", &pqueuesize);
    while (op != 4)
    {
        printf("\n\nOperations\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter operation: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\nEnter the element to be inserted: ");
            int item;
            scanf("%d", &item);
            printf("\nEnter the priority of the element: ");
            int prio;
            scanf("%d", &prio);
            insertpriorityqueue(item, prio);
            break;
        case 2:
            deletepriorityqueue();
            break;
        case 3:
            displaypriorityqueue();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nInvalid operation\n");
            break;
        }
    }
}

void insertcircularqueue(int item)
{
    if (cqueuefront == (cqueuerear + 1) % cqueuesize)
    {
        printf("\nQueue full");
    }
    else
    {
        cqueuerear = (cqueuerear + 1) % cqueuesize;
        cqueue[cqueuerear] = item;
    }
}

void deletecircularqueue()
{
    if (cqueuefront == cqueuerear)
    {
        printf("\nQueue empty");
    }
    else
    {
        cqueuefront = (cqueuefront + 1) % cqueuesize;
        int item = cqueue[cqueuefront];
        printf("\nThe deleted element is %d", item);
    }
}

void displaycircularqueue()
{
    int i = (cqueuefront + 1) % cqueuesize;
    printf("\nQueue elements are: ");
    while (i != (cqueuerear + 1) % cqueuesize)
    {
        printf("\n%d", cqueue[i]);
        i = (i + 1) % cqueuesize;
    }
}
void circularqueue()
{
    int op = 0;
    printf("\nEnter size of circular queue: ");
    scanf("%d", &cqueuesize);
    while (op != 4)
    {
        printf("\n\nOperations\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter operation: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\nEnter the element to be inserted: ");
            int item;
            scanf("%d", &item);
            insertcircularqueue(item);
            break;
        case 2:
            deletecircularqueue();
            break;
        case 3:
            displaycircularqueue();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nInvalid operation\n");
            break;
        }
    }
}
int main()
{
    int choice;
    printf("Menu\n1.Circular Queue\n2.Priority Queue\n3.Exit\nChoose queue type: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("\nCircular Queue\n");
        circularqueue();
        break;
    case 2:
        printf("\n\nPriority Queue\n");
        priorityqueue();
        break;
    case 3:
        printf("Exiting\n");
        break;
    default:
        printf("Invalid choice\n");
    }
    return 0;
}