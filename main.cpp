/**
 * 测试类
 */

#include "Huffman.h"
using namespace std;

int main() {

    int a[] = {5, 6, 8, 7, 15};
    int i, len = sizeof(a) / (sizeof(a[0]));
    Huffman<int> *tree = new Huffman<int>();

    cout << "==添加数组: ";
    for (i = 0; i < len; i++)
        cout << a[i] << " ";
    cout << endl;

    //构造Huffman树
    tree->create(a, len);

    cout << "前序遍历:" << endl;
    tree->preOrder();
    cout << endl;

    cout << "中序遍历:" << endl;
    tree->inOrder();
    cout << endl;

    cout << "后序遍历:" << endl;
    tree->postOrder();
    cout << endl;

    cout << "树的详细信息:" << endl;
    tree->print();

    //销毁二叉树
    tree->destory();

    return 0;
}