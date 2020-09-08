#include <iostream>

using namespace std;

//由于线段树是完全二叉树，我们也可以用数组来存储
const int MAXNUM = 1000;
struct SegTreeNode
{
    int val;
} segTree[MAXNUM]; //定义线段树


void build(int root, int arr[], int istart, int iend)
{
    if(istart == iend)//叶子节点
        segTree[root].val = arr[istart];
    else
    {
        int mid = (istart + iend) / 2;
        build(root*2+1, arr, istart, mid);//递归构造左子树
        build(root*2+2, arr, mid+1, iend);//递归构造右子树
        segTree[root].val = min(segTree[root*2+1].val, segTree[root*2+2].val);
    }
}
