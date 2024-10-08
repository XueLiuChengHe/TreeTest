#include<iostream>
using namespace std;

// �������ڵ�ṹ��
struct treeNode {
    char elem; // ����������Ԫ��
    struct treeNode* left_child; // ����������
    struct treeNode* right_child; // �������Һ���
};

// ��������������ϰ�ڵ�ṹ��
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