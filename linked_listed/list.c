#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
} node_t;

void printList(node_t *head)
{
    node_t *tmp = head;
    printf("The list: ");
    while (tmp != NULL)
    {
        printf("%d-", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");
}

node_t *createNewNode(int val)
{
    node_t *result = malloc(sizeof(node_t));
    result->val = val;
    result->next = NULL;
    return result;
}

void insertAtHead(node_t **head, node_t *nodeToInsert)
{
    nodeToInsert->next = *head;
    *head = nodeToInsert;
}

void insertAfterNode(node_t *nodeToInsertAfter, node_t *newNode)
{
    newNode->next = nodeToInsertAfter->next;
    nodeToInsertAfter->next = newNode;
}

node_t *findNode(node_t *head, int val)
{
    node_t *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->val == val)
        {
            printf("Found a node with value %d\n", tmp->val);
            return tmp;
        }
        tmp = tmp->next;
    }
    printf("Not found a node with value \n");
    return NULL;
}

void deleteList(node_t *head)
{
    while (head != NULL)
    {
        node_t *tmp = head;
        printf("List %d\n", tmp->val);
        head = head->next;
        free(tmp);
    }
}

int main(int argc, char **argv)
{
    node_t *head = NULL;
    node_t *tmp;

    for (unsigned i = 0; i < 25; i++)
    {
        tmp = createNewNode(i);
        insertAtHead(&head, tmp);
    }
    tmp = findNode(head, 16);
    insertAfterNode(tmp, createNewNode(66));
    printList(head);
    deleteList(head);
    return 0;
}