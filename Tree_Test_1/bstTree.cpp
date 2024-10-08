#include<iostream>
using namespace std;

typedef struct TreeNode {
	int elem;
	struct TreeNode* left_child;
	struct TreeNode* right_child;
}BstTree;


// ��������������
// ������������ǣ��սڵ�ֱ�Ӳ���
// �ǿսڵ��ȱȽ��ٲ��루��Ϊ����С�����������
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


// �����������������
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


// ��ȡ��ӦҪ��ѯ�����ݵĽ��ָ��

// ɾ�������������е�ĳ���ڵ�


// ����ɾ��������
void deleteTree(BstTree * &T) {
	if (T == NULL) {
		return;
	}
	else {
		deleteTree(T->left_child);
		deleteTree(T->right_child);
		delete T;
		T = NULL; // �ǵý���ָ��������¸�ֵΪNULL��
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