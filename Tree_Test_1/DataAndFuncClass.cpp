#include"tree_test.h"
// ��������ϰ
// ������������
void preCreateTree(brTree*& T) { // ����ʹ���������͵�ָ��T(����Ҳ����ʹ�ö���ָ�뵫���������Եú��鷳��)����ΪҪ�ں����ڸı�ָ���ָ��
    char n;
    cout << "please input the brTree elem:" << endl;
    cin >> n;
    if (n == '#') {
        // #��ʾ�������ڵ�Ϊ��
        T = NULL;
        return;
    }
    else {
        brTree* tree_node = new brTree;
        tree_node->elem = n;
        T = tree_node;
        preCreateTree(T->left_child);
        preCreateTree(T->right_child);
    }
}

// ��������������
// ������������ǣ��սڵ�ֱ�Ӳ���
// �ǿսڵ��ȱȽ��ٲ��루��Ϊ����С�����������
void insertBstTreeNode(BstTree*& T, int elem) {
    if (T == NULL) {
        BstTree* new_node = new BstTree;
        new_node->elem = elem;
        new_node->left_child = NULL;
        new_node->right_child = NULL;
        T = new_node;
    }
    else {
        if (elem < T->elem) {
            insertBstTreeNode(T->left_child, elem);
        }
        else if (elem > T->elem) {
            insertBstTreeNode(T->right_child, elem);
        }
        else {
            return;
        }

        // ��ȡ�ýڵ��ƽ������
        int tree_balence = getTreeBalence(T);
        //cout << tree_balence << endl;


        // ����Ҫע�����Ĺ�����û�е���0�����������ɾ����ʱ����ܳ��ֵ���0�����
        // ������LL��ʧ��
        if (tree_balence > 1 && getTreeBalence(T->left_child) > 0) {
            rightRound(T);
        }
        // LR��ʧ��
        if (tree_balence > 1 && getTreeBalence(T->left_child) < 0) {
            leftRound(T->left_child);
            rightRound(T);
        }

        // RR��ʧ��
        if (tree_balence < -1 && getTreeBalence(T->right_child) < 0) {
            leftRound(T);
            //cout << T->elem << T->left_child << T->right_child << endl;
        }
        // RL��ʧ��
        if (tree_balence < -1 && getTreeBalence(T->right_child) > 0) {
            rightRound(T->left_child);
            leftRound(T);
        }

    }
}

// ��ȡ��ӦҪ��ѯ�����ݵĽ��ָ��


// ����ת����
void leftRound(BstTree*& T) {
    if (T == NULL) {
        return;
    }
    else {

        //cout << "===============" << endl;

        // 1���ɸ����Һ�����Ϊ�¸�
        // 2���ɸ���Ϊ�¸���������
        // 3���¸��������������ô��������Ϊ�ɸ���������
        BstTree* new_root = T->right_child;
        BstTree* new_node = new_root->left_child;

        new_root->left_child = T;
        T->right_child = new_node;
        T = new_root;


    }
}

// ����ת����
void rightRound(BstTree*& T) {
    if (T == NULL) {
        return;
    }
    else {
        // 1���ɸ���������Ϊ�¸�
        // 2���ɸ���Ϊ�¸����Һ���
        // 3���ɸ����������������Ϊ�ɸ���������
        BstTree* new_root = T->left_child;
        BstTree* new_node = new_root->right_child;

        new_root->right_child = T;
        T->left_child = new_node;
        T = new_root;

    }
}


// ��ȡ���߶ȵĺ���
int getHightTree(BstTree*& T) {
    if (T == NULL) {
        return 0;
    }
    else {
        int left_child_depth = getHightTree(T->left_child);
        int right_child_depth = getHightTree(T->right_child);
        int depth = 1 + (left_child_depth > right_child_depth ? left_child_depth : right_child_depth);
        return depth;
    }
}

// �Ƚ��������Ĵ�С����������������
int max(int a, int b) {
    return a >= b ? a : b;
}

// ��ȡ��������Ӧ�ڵ��ƽ������
int getTreeBalence(BstTree*& T) {
    if (T == NULL) {
        // �ǵü��Ͽ�ָ���жϷ����п��ܴ���ȥ���ǿ�ָ�뵼���쳣��
        return 0;
    }
    else {
        return getHightTree(T->left_child) - getHightTree(T->right_child);
    }
}


// ���õݹ�ķ�ʽ
BstTree* searchTreeNode(BstTree*& T, int elem) {
    if (T == NULL) {
        return NULL;
    }
    else {
        if (elem > T->elem) {
            searchTreeNode(T->right_child, elem);
        }
        else if (elem < T->elem) {
            searchTreeNode(T->left_child, elem);
        }
        else {
            return T;
        }
    }
}

//// ���÷ǵݹ�ķ�ʽ
//BstTree* searchTreeNodeTest(BstTree*& T, int elem) {
//
//}

// ɾ�������������е�ĳ���ڵ�
void deleteBstTreeNode(BstTree*& T, int elem) {
    if (T == NULL) {
        // ����ǿ�����ֱ�ӷ���
        cout << endl << "Not Finding the elem that you want to delete" << endl;
        return;
    }
    else {
        if (elem > T->elem) {
            // ���Ҫɾ���Ľڵ���ڵ�ǰ�ڵ���������������ݹ�
            deleteBstTreeNode(T->right_child, elem);
        }
        else if (elem < T->elem) {
            // ��Ҫɾ���Ľڵ�С�ڵ�ǰ�ڵ���������������ݹ�
            deleteBstTreeNode(T->left_child, elem);
        }
        else {
            // ��Ҫɾ���Ľڵ��ǵ�ǰ�ڵ������ɾ������
            // ��Ϊ�������
            // 1��Ҫɾ���Ľڵ���Ҷ�ӽڵ�
            if (T->left_child == NULL && T->right_child == NULL) {
                BstTree* node_sign = T;
                T = NULL;
                delete node_sign;
            }

            // 2��Ҫɾ���Ľڵ���������������������
            else if (T->left_child == NULL && T->right_child != NULL) {
                BstTree* node_sign = T->right_child;
                T->elem = T->right_child->elem;
                T->left_child = T->right_child->left_child;
                T->right_child = T->right_child->right_child;
                delete node_sign;
                node_sign = NULL;
            }
            else if (T->left_child != NULL && T->right_child == NULL) {
                BstTree* node_sign = T->left_child;
                T->elem = T->left_child->elem;
                T->right_child = T->left_child->right_child;
                T->left_child = T->left_child->left_child;
                delete node_sign;
                node_sign = NULL;
            }
            // 3��Ҫɾ���Ľڵ����������Ҳ��������
            else {
                BstTree* node_sign = T->right_child;
                while (node_sign->left_child != NULL) {
                    node_sign = node_sign->left_child;
                }
                T->elem = node_sign->elem;
                deleteBstTreeNode(T->right_child, node_sign->elem);
                /* ��ʹ��ָ���Ӧ�õ�ʱ��Ҫע�����Ӧ����˭��Ӧ�ã�����˵�����deleteBstTreeNode�����е�ָ��Ӧ��Ҫ�ֱ����
                   �Ը��׽ڵ��е����Һ���ָ���Ӧ�û��Ƕ�������ӽڵ㱾���ָ���Ӧ������������ģ�������ɿ�ָ������⡣
                */
            }

        }
        if (T != NULL) {
            // ��ȡ�ýڵ��ƽ�������ж��Ƿ�ƽ��״̬�����ƣ�����������
            int balance = getTreeBalence(T);
            // 1������LL��ʧ��
            if (balance > 1 && getTreeBalence(T->left_child) > 0) {
                rightRound(T);
            }
            // 2������LR��ʧ��
            if (balance > 1 && getTreeBalence(T->left_child) <= 0) {
                leftRound(T->left_child);
                rightRound(T);
            }
            // 3������RR��ʧ��
            if (balance < -1 && getTreeBalence(T->right_child) < 0) {
                leftRound(T);
            }
            // 4������RL��ʧ��
            if (balance < -1 && getTreeBalence(T->right_child) >= 0) {
                rightRound(T->right_child);
                leftRound(T);
            }
        }
    }
}

// �������������
void preViewTree(brTree*& T) {
    if (T == NULL) {
        return;
    }
    else {
        cout << T->elem << endl;
        preViewTree(T->left_child);
        preViewTree(T->right_child);
    }
}

// �������������
void midViewTree(brTree*& T) {
    if (T == NULL) {
        return;
    }
    else {
        midViewTree(T->left_child);
        cout << T->elem << endl;
        midViewTree(T->right_child);
    }
}
void midViewTree(BstTree*& T) {
    if (T == NULL) {
        return;
    }
    else {
        midViewTree(T->left_child);
        cout << T->elem << endl;
        midViewTree(T->right_child);
    }
}

// �������������
void beViewTree(brTree*& T) {
    if (T == NULL) {
        return;
    }
    else {
        beViewTree(T->left_child);
        beViewTree(T->right_child);
        cout << T->elem << endl;
    }
}

// ����ɾ��������
void deleteTree(brTree*& T) {
    if (T == NULL) {
        return;
    }
    else {
        deleteTree(T->left_child);
        deleteTree(T->right_child);
        //cout << T->elem << endl;
        brTree* node_sign = T;
        T = NULL;
        delete node_sign;

    }
}
void deleteTree(BstTree*& T) {
    if (T == NULL) {
        return;
    }
    else {
        deleteTree(T->left_child);
        deleteTree(T->right_child);
        //cout << T->elem << endl;
        BstTree* node_sign = T;
        T = NULL;
        delete node_sign;

    }
}