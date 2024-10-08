#include<iostream>
using namespace std;

// 二叉树节点结构体
struct treeNode {
    char elem; // 二叉树数据元素
    struct treeNode* left_child; // 二叉树左孩子
    struct treeNode* right_child; // 二叉树右孩子
};

// 二叉排序树的练习节点结构体
struct TreeNode {
    int elem;
    struct TreeNode* left_child;
    struct TreeNode* right_child;
};

typedef struct treeNode brTree;
typedef struct TreeNode BstTree;

void leftRound(BstTree*& T);
void insertBstTreeNode(BstTree*& T, int elem);
void preCreateTree(brTree*& T);
void insertBstTreeNode(BstTree*& T, int elem);
void rightRound(BstTree*& T);
int getHightTree(BstTree*& T);
int getTreeBalence(BstTree*& T);
BstTree* searchTreeNode(BstTree*& T, int elem);
void deleteBstTreeNode(BstTree*& T, int elem);
void preViewTree(brTree* &T);
void midViewTree(brTree* &T);
void midViewTree(BstTree* &T);
void beViewTree(brTree* &T);
void deleteTree(brTree * &T);
void deleteTree(BstTree*& T);