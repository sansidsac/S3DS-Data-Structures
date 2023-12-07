#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int coeff;
    int exp;
    struct node *next;
} node;

node *head1 = NULL;
node *head2 = NULL;
node *head3 = NULL;

void insert(node **head, int coeff, int exp) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->coeff = coeff;
    new_node->exp = exp;
    new_node->next = NULL;

    if (*head == NULL)
        *head = new_node;
    else if ((*head)->exp < exp) {
        new_node->next = *head;
        *head = new_node;
    } else {
        node *temp = *head;
        while (temp->next != NULL && temp->next->exp > exp)
            temp = temp->next;
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void read_poly(node **head, int n) {
    int coeff, exp;
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient: ");
        scanf("%d", &coeff);
        printf("Enter exponent: ");
        scanf("%d", &exp);
        insert(head, coeff, exp);
    }
}

void print_poly(node *head) {
    node *temp = head;
    while (temp != NULL) {
    	if (temp->coeff!=0)
       		printf("%d", temp->coeff);
        if (temp->exp != 0 && temp->coeff!=0)
            printf("x^%d", temp->exp);
        if (temp->next != NULL && temp->coeff!=0)
            printf(" + ");
        temp = temp->next;
        
    }
    printf("\n");
}

void multiply_poly(node *head1, node *head2) {
    node *temp1 = head1;
    node *temp2 = head2;

    while (temp1 != NULL) {
        temp2 = head2;
        while (temp2 != NULL) {
            int coeff = temp1->coeff * temp2->coeff;
            int exp = temp1->exp + temp2->exp;
            insert(&head3, coeff, exp);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    } 
}

void add_poly(node *head1, node *head2) {
    node *temp1 = head1;
    node *temp2 = head2;
    int coeff, exp;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->exp == temp2->exp) {
            coeff = temp1->coeff + temp2->coeff;
            exp = temp1->exp;
            insert(&head3, coeff, exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (temp1->exp > temp2->exp) {
            coeff = temp1->coeff;
            exp = temp1->exp;
            insert(&head3, coeff, exp);
            temp1 = temp1->next;
        } else {
            coeff = temp2->coeff;
            exp = temp2->exp;
            insert(&head3, coeff, exp);
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL) {
        coeff = temp1->coeff;
        exp = temp1->exp;
        insert(&head3, coeff, exp);
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        coeff = temp2->coeff;
        exp = temp2->exp;
        insert(&head3, coeff, exp);
        temp2 = temp2->next;
    }
}

void add_like_terms(node **head) {
    node *temp1 = *head;
    node *temp2 = NULL;
    int coeff, exp;
    while (temp1 != NULL) {
        temp2 = temp1->next;
        while (temp2 != NULL) {
            if (temp1->exp == temp2->exp) {
                coeff = temp1->coeff + temp2->coeff;
                exp = temp1->exp;
                temp1->coeff = coeff;
                temp1->exp = exp;
                temp2->coeff = 0;
                temp2->exp = 0;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}

int main() {
    int n1, n2;
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Enter polynomial 1\n");
        printf("2. Enter polynomial 2\n");
        printf("3. Display polynomial 1\n");
        printf("4. Display polynomial 2\n");
        printf("5. Multiply polynomial 1 and 2\n");
        printf("6. Exit\n");
        printf("Enter action: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter number of terms in polynomial 1: ");
                scanf("%d", &n1);
                printf("Enter polynomial 1:\n");
                read_poly(&head1, n1);
                break;
            case 2:
                printf("Enter number of terms in polynomial 2: ");
                scanf("%d", &n2);
                printf("Enter polynomial 2:\n");
                read_poly(&head2, n2);
                break;
            case 3:
                printf("Polynomial 1: ");
                print_poly(head1);
                break;
            case 4:
                printf("Polynomial 2: ");
                print_poly(head2);
                break;
            case 5:
                multiply_poly(head1, head2);
                add_like_terms(&head3);
                printf("Product: ");
                print_poly(head3);
                break;
            case 6:
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    } 
    while (choice != 6);
    return 0;
}
