/*此排序主要有2个难点，第一个是初始化无序堆，第二个是交换元素形成有序堆
写的是大顶堆
1.首先要从下三角开始遍历，一层层的往前推，推到a[0],此时的a[0]是最大值。这时，此堆已经初始成功
2.a[0]即为最大顶，把a[0]与最后一个元素a[len-1]交换，就不用考虑最后一个值了，但是这时的堆已经不符合
性质了。
3.因此开始从a[0]往下支路换，换到a[0]为 0--len-1 最大值,交换 a[0]和a[len-2]的值，这时，a[len-2]和a[len-1]
为有序的。
4.不断循环，直到a[1]排好序，a[0]就不用排了。*/

#include<stdio.h>
//从下三角开始交换得到最大堆
void adjustMaxHeap(int a[], int len, int parentNodeIndex)
{
	// 记录比父节点大的左孩子或者右孩子的索引
	int targetIndex = -1;
	// 获取左、右孩子的索引
	int leftChildIndex = 2 * parentNodeIndex + 1;
	int rightChildIndex = 2 * parentNodeIndex + 2;
	//如果没有子节点，就返回
	if (leftChildIndex >= len)
	{
		return;
	}
	//有左节点，没有右节点
	if (rightChildIndex >= len)
	{
		targetIndex = leftChildIndex;
	}
	//有左节点，有右节点
	else {
		targetIndex = (a[leftChildIndex] > a[rightChildIndex]) ? leftChildIndex : rightChildIndex;
	}
	//进行比较和互换
	if (a[targetIndex] > a[parentNodeIndex])
	{
		int tmp;
		tmp = a[targetIndex];
		a[targetIndex] = a[parentNodeIndex];
		a[parentNodeIndex] = tmp;
		//在初始化堆时，用不到下边的语句，在从上往下遍历时，这个语句是关键
		adjustMaxHeap(a, len, targetIndex);
	}


}
void initHeap(int a[], int len)
{
	for (int i = (len - 1) / 2; i >= 0; i--)
	{
		adjustMaxHeap(a, len, i);
	}
}
int main()
{
	int a[8] = { 1,8,31,4,16,5,2,0 };
	int len = 8;
	initHeap(a, len);

	for (int i = len - 1; i > 0; i--)
	{
		int tmp;
		if (a[i] < a[0])
		{
			tmp = a[0];
			a[0] = a[i];
			a[i] = tmp;
		}
		//关键语句
		adjustMaxHeap(a, i, 0);
	}
	for (int j = 0; j < len; j++)
	{
		printf("\t%d", a[j]);
	}
	return 0;
}