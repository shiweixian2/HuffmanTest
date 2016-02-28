/**
 * @author 石炜贤
 * @date 2016/02/27
 *
 * 构建霍夫曼树,使用最小堆
 */

#ifndef HUFFMANTEST_HUFFMANNODE_H
#define HUFFMANTEST_HUFFMANNODE_H

template <class T>
class HuffmanNode{
public:
    T key;  //权值
    HuffmanNode *left; //左孩子
    HuffmanNode *right; //右孩子
    HuffmanNode *parent; //父节点

    /**
     * 构造函数
     */
    HuffmanNode(){}
    HuffmanNode(T value, HuffmanNode *l, HuffmanNode *r, HuffmanNode *p):key(value),left(l),right(r),parent(p){}

};

#endif //HUFFMANTEST_HUFFMANNODE_H
