#include"tree_test.h"

int main()
{
    //brTree* br_tree = NULL;
    //preCreateTree(br_tree);
    //preViewTree(br_tree);
    //midViewTree(br_tree);
    //beViewTree(br_tree);
    //deleteTree(br_tree);

 /*   BstTree* new_tree = NULL;
    int* arr_test = new int[10];
    for (int i = 0; i < 10; i++) {
        cin >> arr_test[i];
    }
    for (int i = 0; i < 10; i++) {
        insertBstTreeNode(new_tree, arr_test[i]);
    }
    midViewTree(new_tree);
    BstTree* goal_node = searchTreeNode(new_tree, 10);
    cout << goal_node->elem << endl;
    deleteTree(new_tree);
    delete[]arr_test;*/

    BstTree* new_tree = NULL;
    int* arr_test = new int[3];
    for (int i = 0; i < 3; i++) {
        cin >> arr_test[i];
    }
    for (int i = 0; i < 3; i++) {
        insertBstTreeNode(new_tree, arr_test[i]);
    }
    cout <<endl<< getTreeBalence(new_tree) << endl;
    midViewTree(new_tree);

    int n = 0;
    cin >> n;

    insertBstTreeNode(new_tree, n);
    cout << endl << getTreeBalence(new_tree) << endl;
    midViewTree(new_tree);

    //cout << new_tree->right_child->elem<<"=============="<<endl;

    int m = 0;
    cin >> m;

    deleteBstTreeNode(new_tree, m);
    cout <<endl<< getTreeBalence(new_tree) << endl;
    midViewTree(new_tree);

    deleteTree(new_tree);

    return 0;
}
