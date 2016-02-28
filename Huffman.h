/**
 * @author 石炜贤
 * @date 2016/02/27
 *
 * 构建霍夫曼树,使用最小堆
 * 利用C++实现
 */

#ifndef HUFFMANTEST_HUFFMAN_H
#define HUFFMANTEST_HUFFMAN_H

#include <iomanip>
#include <iostream>
#include "HuffmanNode.h"
#include "MinHeap.h"

using namespace std;

template<class T>
class Huffman {
private:
    HuffmanNode<T> *mRoot; //根节点
public:
    Huffman();

    ~Huffman();

    //前序遍历"Huffman"树
    void preOrder();

    //中序遍历"Huffman"树
    void inOrder();

    //后序遍历"Huffman"树
    void postOrder();

    //创建Huffman树
    void create(T a[], int size);

    //销毁Huffman树
    void destory();

    //打印Huffman树
    void print();

private:
    //前序遍历"Huffman"树
    void preOrder(HuffmanNode<T> *tree) const;

    //中序遍历"Huffman"树
    void inOrder(HuffmanNode<T> *tree) const;

    //后序遍历"Huffman"树
    void postOrder(HuffmanNode<T> *tree) const;

    //销毁Huffman树
    void destory(HuffmanNode<T> *tree);

    //打印Huffman树
    void print(HuffmanNode<T> *tree, T key, int direction);
};

/**
 * 构造函数
 */
template<class T>
Huffman<T>::Huffman() : mRoot(NULL) { }

/**
 * 析构函数
 */
template<class T>
Huffman<T>::~Huffman() {
    destory();
}

/**
 * 前序遍历Huffman树
 */
template<class T>
void Huffman<T>::preOrder(HuffmanNode<T> *tree) const {
    if (tree != nullptr) {
        cout << tree->key << " ";
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

template<class T>
void Huffman<T>::preOrder() {
    preOrder(mRoot);
}

/**
 * 中序遍历Huffman树
 */
template<class T>
void Huffman<T>::inOrder(HuffmanNode<T> *tree) const {
    if (tree != nullptr) {
        inOrder(tree->left);
        cout << tree->key << " ";
        inOrder(tree->right);
    }
}

template<class T>
void Huffman<T>::inOrder() {
    inOrder(mRoot);
}

/**
 * 后序遍历Huffman树
 */
template<class T>
void Huffman<T>::postOrder(HuffmanNode<T> *tree) const {
    if (tree != nullptr) {
        postOrder(tree->left);
        postOrder(tree->right);
        cout << tree->key << " ";
    }
}

template<class T>
void Huffman<T>::postOrder() {
    postOrder(mRoot);
}

/**
 * 创建Huffman树
 *
 * 参数说明:
 *       a:权值数组
 *       size:数组大小
 * 返回值:
 *      Huffman数组的根节点
 */
template<class T>
void Huffman<T>::create(T *a, int size) {

    int i;
    HuffmanNode<T> *parent, *left, *right;
    //创建临时使用的最小堆
    MinHeap<T> *heap = new MinHeap<T>();
    //建立数组a对应的最小堆
    heap->create(a, size);
    for (i = 0; i < size - 1; i++) {
        left = heap->dumpFromMinimum(); //从堆中取出最小节点,赋给左孩子
        right = heap->dumpFromMinimum(); //从堆中取出最小节点,赋给右孩子
        //新建parent节点,左右孩子分别是left和right,其大小是左右孩子之和
        parent = new HuffmanNode<T>(left->key + right->key, left, right, nullptr);
        left->parent = parent;
        right->parent = parent;

        //将parent节点数据拷贝到最小堆中
        if (heap->copyOf(parent) != 0) {
            cout << "插入失败!" << endl << "结束程序" << endl;
            destory(parent);
            parent = nullptr;
            break;
        }
    }
    //将最小堆赋给mRoot
    mRoot = parent;

    //销毁最小堆
    heap->destory();
    delete heap;
}

/**
 * 销毁Huffman树
 */
template <class T>
void Huffman<T>::destory(HuffmanNode<T> *tree) {
    if(tree == nullptr)
        return;
    if (tree->left != nullptr)
        destory(tree->left);
    if (tree->right != nullptr)
        destory(tree->right);
    delete tree;
    tree = nullptr;
}

template <class T>
void Huffman<T>::destory() {
    destory(mRoot);
}

/**
 * 打印"Huffman"树
 *
 * key -- 节点的键值
 * direction -- 0:该节点为根节点
 *              -1:该节点为左孩子
 *              1:该节点为右孩子
 */
template<class T>
void Huffman<T>::print(HuffmanNode<T> *tree, T key, int direction) {
    if (tree != nullptr) {
        if (direction == 0) //tree是根节点
            cout << setw(2) << tree->key << "is root" << endl;
        else  //tree是分支点
            cout << setw(2) << tree->key << " is " << setw(2) << key << "'s " << setw(2) <<
            (direction == 1 ? "right child" : "left child") << endl;
        print(tree->left, tree->key, -1);
        print(tree->right, tree->key, 1);

    }
}

template<class T>
void Huffman<T>::print() {
    if (mRoot != nullptr)
        print(mRoot, mRoot->key, 0);
}

#endif //HUFFMANTEST_HUFFMAN_H
