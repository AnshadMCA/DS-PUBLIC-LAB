#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void insert_at_first(struct node** head, int new_data) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

void insert_at_end(struct node** head, int new_data) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

void insert_at_pos(struct node** head, int pos, int new_data) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (pos == 1) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    struct node* last = *head;
    for (int i = 1; i < pos - 1 && last != NULL; i++) {
        last = last->next;
    }

    if (last == NULL) {
        printf("Position out of bounds\n");
        free(new_node);
        return;
    }

    new_node->next = last->next;
    last->next = new_node;
}

void delete_begin(struct node** head) {
    if (*head == NULL) return;
    struct node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void delete_last(struct node** head) {
    if (*head == NULL) return;
    struct node *last = *head, *prev = NULL;
    while (last->next != NULL) {
        prev = last;
        last = last->next;
    }
    if (prev == NULL) {
        free(*head);
        *head = NULL;
    } else {
        free(last);
        prev->next = NULL;
    }
}

void delete_pos(struct node** head, int pos) {
    if (*head == NULL) return;
    struct node* last = *head;

    if (pos == 1) {
        *head = last->next;
        free(last);
        return;
    }

    for (int i = 1; i < pos - 1 && last != NULL; i++) {
        last = last->next;
    }

    if (last == NULL || last->next == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    struct node* del = last->next;
    last->next = del->next;
    free(del);
}

void search(struct node** head, int search) {
    int i = 1;
    struct node* last = *head;
    while (last != NULL) {
        if (last->data == search) {
            printf("Element found %d at position %d\n", search, i);
            return;
        }
        last = last->next;
        i++;
    }
    printf("Element not found\n");
}

void printList(struct node* nod) {
    while (nod != NULL) {
        printf("%d ", nod->data);
        nod = nod->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    int new_data, choice = 0;

    while (choice != -1) {
        printf("Enter the choice\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Delete at beginning\n5. Delete at end\n6. Delete at position\n7. Search\n-1. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &new_data);
                insert_at_first(&head, new_data);
                printf("The Updated linked list is:\n");
                printList(head);
                break;
            case 2:
                printf("Enter the data to insert: ");
                scanf("%d", &new_data);
                insert_at_end(&head, new_data);
                printf("The Updated linked list is:\n");
                printList(head);
                break;
            case 3:
                printf("Enter the data to insert: ");
                scanf("%d", &new_data);
                int pos;
                printf("Enter the position: ");
                scanf("%d", &pos);
                insert_at_pos(&head, pos, new_data);
                printf("The Updated linked list is:\n");
                printList(head);
                break;
            case 4:
                delete_begin(&head);
                printf("The Updated linked list is:\n");
                printList(head);
                break;
            case 5:
                delete_last(&head);
                printf("The Updated linked list is:\n");
                printList(head);
                break;
            case 6:
                printf("Enter the position: ");
                scanf("%d", &pos);
                delete_pos(&head, pos);
                printf("The Updated linked list is:\n");
                printList(head);
                break;
            case 7:
                printf("Enter the number to search: ");
                int s;
                scanf("%d", &s);
                search(&head, s);
                break;
            case -1:
                printf("Exiting\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    return 0;
}

