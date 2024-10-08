#include<iostream>
using namespace std;

typedef struct TreeNode {
	int elem;
	struct TreeNode* left_child;
	struct TreeNode* right_child;
}BstTree;


// 创建二叉搜索树
// 两种情况首先是：空节点直接插入
// 非空节点先比较再插入（分为大于小于两种情况）
void insertBstTreeNode(BstTree * &T,int elem){
	if (T == NULL){
		BstTree* new_node = new BstTree;
		new_node->elem = elem;
		new_node->left_child = NULL;
		new_node->right_child = NULL;
		T = new_node;
	}
	else {
		if (elem < T->elem) {
			insertBstTreeNode(T->left_child,elem);
		}
		else{
			insertBstTreeNode(T->right_child,elem);
		}
	}
}


// 中序遍历二叉搜索树
void midVisitTree(BstTree* &T) {
	if (T == NULL) {
		return;
	}
	else {
		midVisitTree(T->left_child);
		cout << T->elem << endl;
		midVisitTree(T->right_child);
	}
}


// 获取对应要查询的内容的结点指针

// 删除二叉搜索树中的某个节点


// 后序删除二叉树
void deleteTree(BstTree * &T) {
	if (T == NULL) {
		return;
	}
	else {
		deleteTree(T->left_child);
		deleteTree(T->right_child);
		delete T;
		T = NULL; // 记得将该指针变量重新赋值为NULL；
	}
}

int main() {
	BstTree* new_tree = NULL;
	int* arr_test = new int[10];
	for (int i = 0; i < 10;i++) {
		cin >> arr_test[i];
	}
	for (int i = 0; i < 10; i++) {
		insertBstTreeNode(new_tree, arr_test[i]);
	}
	midVisitTree(new_tree);
	deleteTree(new_tree);
	delete []arr_test;
	return 0;
}