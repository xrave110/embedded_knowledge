#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NUM_CHARS 256

typedef struct trienode
{
    struct trienode *children[NUM_CHARS]; // LUT
    bool terminal;                        // if it is the end of the branch
} trienode;

trienode *createNode()
{
    trienode *newnode = malloc(sizeof(*newnode));

    for (int i = 0; i < NUM_CHARS; i++)
    {
        newnode->children[i] = NULL;
    }
    newnode->terminal = false;
    return newnode;
}

bool trieInsert(trienode **root, char *signedtext)
{
    if (*root == NULL)
    {
        *root = createNode();
    }
    unsigned char *text = (unsigned char *)signedtext;
    trienode *tmp = *root;
    int length = strlen(signedtext);
    printf("___%s___\n", signedtext);
    for (int i = 0; i < length; i++)
    {
        if (tmp->children[text[i]] == NULL)
        {
            printf("%c\n", text[i]);
            // create a new node
            tmp->children[text[i]] = createNode();
        }
        tmp = tmp->children[text[i]];
    }
    if (tmp->terminal)
    {
        return false;
    }
    else
    {
        tmp->terminal = true;
        return true;
    }
}

void printTrieRec(trienode *node, unsigned char *prefix, int length)
{
    unsigned char newprefix[length + 2];
    memcpy(newprefix, prefix, length);
    newprefix[length + 1] = 0;

    // Base case
    if (node->terminal)
    {
        printf("WORD: %s\n", prefix);
    }

    for (int i = 0; i < NUM_CHARS; i++)
    {
        if (node->children[i] != NULL)
        {
            newprefix[length] = i;
            printTrieRec(node->children[i], newprefix, length + 1);
        }
    }
}

void printTrie(trienode *root)
{
    if (root == NULL)
    {
        printf("Trie is empty\n");
    }
    printTrieRec(root, NULL, 0);
}

int main()
{
    trienode *root = NULL;
    // printf("Root->children[67]: %p\n", root->children[0]);
    /**
     *           ROOT
     *      /       /   \
     *     K       C     H
     *    /       /       \
     *   I       A         A
     *  / \       \         \
     * T   N       T         P
     *              \         \
     *               T         P
     *                \         \
     *                 L         Y
     *                  \
     *                   E
     * */
    trieInsert(&root, "KIT");
    trieInsert(&root, "CATTLE");
    trieInsert(&root, "KIN");
    trieInsert(&root, "CAT");
    trieInsert(&root, "HAPPY");
    printTrie(root);
}