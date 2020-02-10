/*��������Ҫ��2���ѵ㣬��һ���ǳ�ʼ������ѣ��ڶ����ǽ���Ԫ���γ������
д���Ǵ󶥶�
1.����Ҫ�������ǿ�ʼ������һ������ǰ�ƣ��Ƶ�a[0],��ʱ��a[0]�����ֵ����ʱ���˶��Ѿ���ʼ�ɹ�
2.a[0]��Ϊ��󶥣���a[0]�����һ��Ԫ��a[len-1]�������Ͳ��ÿ������һ��ֵ�ˣ�������ʱ�Ķ��Ѿ�������
�����ˡ�
3.��˿�ʼ��a[0]����֧·��������a[0]Ϊ 0--len-1 ���ֵ,���� a[0]��a[len-2]��ֵ����ʱ��a[len-2]��a[len-1]
Ϊ����ġ�
4.����ѭ����ֱ��a[1]�ź���a[0]�Ͳ������ˡ�*/

#include<stdio.h>
//�������ǿ�ʼ�����õ�����
void adjustMaxHeap(int a[], int len, int parentNodeIndex)
{
	// ��¼�ȸ��ڵ������ӻ����Һ��ӵ�����
	int targetIndex = -1;
	// ��ȡ���Һ��ӵ�����
	int leftChildIndex = 2 * parentNodeIndex + 1;
	int rightChildIndex = 2 * parentNodeIndex + 2;
	//���û���ӽڵ㣬�ͷ���
	if (leftChildIndex >= len)
	{
		return;
	}
	//����ڵ㣬û���ҽڵ�
	if (rightChildIndex >= len)
	{
		targetIndex = leftChildIndex;
	}
	//����ڵ㣬���ҽڵ�
	else {
		targetIndex = (a[leftChildIndex] > a[rightChildIndex]) ? leftChildIndex : rightChildIndex;
	}
	//���бȽϺͻ���
	if (a[targetIndex] > a[parentNodeIndex])
	{
		int tmp;
		tmp = a[targetIndex];
		a[targetIndex] = a[parentNodeIndex];
		a[parentNodeIndex] = tmp;
		//�ڳ�ʼ����ʱ���ò����±ߵ���䣬�ڴ������±���ʱ���������ǹؼ�
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
		//�ؼ����
		adjustMaxHeap(a, i, 0);
	}
	for (int j = 0; j < len; j++)
	{
		printf("\t%d", a[j]);
	}
	return 0;
}