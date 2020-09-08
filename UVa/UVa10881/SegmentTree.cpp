#include <iostream>

using namespace std;

//�����߶�������ȫ������������Ҳ�������������洢
const int MAXNUM = 1000;
struct SegTreeNode
{
    int val;
} segTree[MAXNUM]; //�����߶���


void build(int root, int arr[], int istart, int iend)
{
    if(istart == iend)//Ҷ�ӽڵ�
        segTree[root].val = arr[istart];
    else
    {
        int mid = (istart + iend) / 2;
        build(root*2+1, arr, istart, mid);//�ݹ鹹��������
        build(root*2+2, arr, mid+1, iend);//�ݹ鹹��������
        segTree[root].val = min(segTree[root*2+1].val, segTree[root*2+2].val);
    }
}
