#include"tree_test.h"
// 二叉树练习
// 先序建立二叉树
void preCreateTree(brTree*& T) { // 这里使用引用类型的指针T(这里也可以使用二重指针但是那样就显得很麻烦了)是因为要在函数内改变指针的指向
    char n;
    cout << "please input the brTree elem:" << endl;
    cin >> n;
    if (n == '#') {
        // #表示二叉树节点为空
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

// 创建二叉搜索树
// 两种情况首先是：空节点直接插入
// 非空节点先比较再插入（分为大于小于两种情况）
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

        // 获取该节点的平衡因子
        int tree_balence = getTreeBalence(T);
        //cout << tree_balence << endl;


        // 这里要注意插入的过程中没有等于0的情况但是在删除的时候可能出现等于0的情况
        // 首先是LL型失衡
        if (tree_balence > 1 && getTreeBalence(T->left_child) > 0) {
            rightRound(T);
        }
        // LR型失衡
        if (tree_balence > 1 && getTreeBalence(T->left_child) < 0) {
            leftRound(T->left_child);
            rightRound(T);
        }

        // RR型失衡
        if (tree_balence < -1 && getTreeBalence(T->right_child) < 0) {
            leftRound(T);
            //cout << T->elem << T->left_child << T->right_child << endl;
        }
        // RL型失衡
        if (tree_balence < -1 && getTreeBalence(T->right_child) > 0) {
            rightRound(T->left_child);
            leftRound(T);
        }

    }
}

// 获取对应要查询的内容的结点指针


// 左旋转函数
void leftRound(BstTree*& T) {
    if (T == NULL) {
        return;
    }
    else {

        //cout << "===============" << endl;

        // 1、旧根的右孩子作为新根
        // 2、旧根作为新根的左子树
        // 3、新根如果有左子树那么左子树作为旧根的右子树
        BstTree* new_root = T->right_child;
        BstTree* new_node = new_root->left_child;

        new_root->left_child = T;
        T->right_child = new_node;
        T = new_root;


    }
}

// 右旋转函数
void rightRound(BstTree*& T) {
    if (T == NULL) {
        return;
    }
    else {
        // 1、旧根的左孩子作为新根
        // 2、旧根作为新根的右孩子
        // 3、旧根如果有右子树就作为旧根的左子树
        BstTree* new_root = T->left_child;
        BstTree* new_node = new_root->right_child;

        new_root->right_child = T;
        T->left_child = new_node;
        T = new_root;

    }
}


// 获取树高度的函数
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

// 比较两个数的大小并返回其中最大的数
int max(int a, int b) {
    return a >= b ? a : b;
}

// 获取二叉树对应节点的平衡因子
int getTreeBalence(BstTree*& T) {
    if (T == NULL) {
        // 记得加上空指针判断否则有可能传出去的是空指针导致异常。
        return 0;
    }
    else {
        return getHightTree(T->left_child) - getHightTree(T->right_child);
    }
}


// 采用递归的方式
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

//// 采用非递归的方式
//BstTree* searchTreeNodeTest(BstTree*& T, int elem) {
//
//}

// 删除二叉搜索树中的某个节点
void deleteBstTreeNode(BstTree*& T, int elem) {
    if (T == NULL) {
        // 如果是空树则直接返回
        cout << endl << "Not Finding the elem that you want to delete" << endl;
        return;
    }
    else {
        if (elem > T->elem) {
            // 如果要删除的节点大于当前节点则继续想右子树递归
            deleteBstTreeNode(T->right_child, elem);
        }
        else if (elem < T->elem) {
            // 若要删除的节点小于当前节点则继续向左子树递归
            deleteBstTreeNode(T->left_child, elem);
        }
        else {
            // 若要删除的节点是当前节点则进行删除操作
            // 分为三种情况
            // 1、要删除的节点是叶子节点
            if (T->left_child == NULL && T->right_child == NULL) {
                BstTree* node_sign = T;
                T = NULL;
                delete node_sign;
            }

            // 2、要删除的节点有左子树或者有右子树
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
            // 3、要删除的节点既有右子树也有左子树
            else {
                BstTree* node_sign = T->right_child;
                while (node_sign->left_child != NULL) {
                    node_sign = node_sign->left_child;
                }
                T->elem = node_sign->elem;
                deleteBstTreeNode(T->right_child, node_sign->elem);
                /* 在使用指针的应用的时候要注意这个应用是谁的应用，比如说上面的deleteBstTreeNode函数中的指针应用要分辨好是
                   对父亲节点中的左右孩子指针的应用还是对这个孩子节点本身的指针的应用这是有区别的，可能造成空指针的问题。
                */
            }

        }
        if (T != NULL) {
            // 获取该节点的平衡因子判断是否平衡状态被打破，并作出调整
            int balance = getTreeBalence(T);
            // 1、发生LL型失衡
            if (balance > 1 && getTreeBalence(T->left_child) > 0) {
                rightRound(T);
            }
            // 2、发生LR型失衡
            if (balance > 1 && getTreeBalence(T->left_child) <= 0) {
                leftRound(T->left_child);
                rightRound(T);
            }
            // 3、发生RR型失衡
            if (balance < -1 && getTreeBalence(T->right_child) < 0) {
                leftRound(T);
            }
            // 4、发生RL型失衡
            if (balance < -1 && getTreeBalence(T->right_child) >= 0) {
                rightRound(T->right_child);
                leftRound(T);
            }
        }
    }
}

// 先序遍历二叉树
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

// 中序遍历二叉树
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

// 后序遍历二叉树
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

// 后序删除二叉树
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