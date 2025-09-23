#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
typedef char BTDataType;
// ¶þ²æÊ÷½áµã
typedef struct BinTreeNode {
    struct BinTreeNode* left;
    struct BinTreeNode* right;
    BTDataType data;
} BinTNode;

BinTNode* creatTree(char* arr, int* pi) {
    if (arr[*pi] == '#') {
        (*pi)++;
        return NULL;
    }
    BinTNode* root = (BinTNode*)malloc(sizeof(BinTNode));
    root->data = arr[(*pi)++];
    root->left = creatTree(arr, pi);
    root->right = creatTree(arr, pi);
    return root;
}
void InOrder(BinTNode* root) {
    if (root == NULL)
        return;
    InOrder(root->left);
    printf("%c ", root->data);
    InOrder(root->right);
}
//int main() {
//    char arr[100];
//    scanf("%s", arr);
//    int i = 0;
//    BinTNode* root = creatTree(arr, &i);
//    InOrder(root);
//    return 0;
//}