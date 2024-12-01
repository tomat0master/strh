#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


/**
 * @brief 返回左子树位置
*/
inline int leftChild(int i) {
    return 2 * i + 1;
}


/**
 * @brief 向下维护i位置节点的最大堆性质
*/
template <typename Comparable>
void percDown(vector<Comparable> &a, int i, int n) {
    int child;
    Comparable tmp;
    for (tmp = move(a[i]); leftChild(i) < n; i = child) {
        child = leftChild(i);
        if (child != n - 1 && a[child] < a[child + 1])
            ++child;
        if (tmp < a[child])
            a[i] = move(a[child]);
        else
            break;
    }
    a[i] = move(tmp);
}

/**
 * @brief 对序列进行堆排序
*/
template <typename Comparable>
void heapsort(vector<Comparable> &a) {
    for (int i = a.size() / 2 - 1; i >= 0; --i) { 
        percDown(a, i, a.size());
    }   //  先构建MAXheap，从非叶子节点开始依次向上维护
    for (int j = a.size() - 1; j > 0; --j) {
        std::swap(a[0], a[j]); 
        percDown(a, 0, j);
    }   //  把根节点即最大元素放到最后，再维护，循环得到升序序列
}
