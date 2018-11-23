/**
* ���ݷ���N�ʺ�����
* ʹ��һ��һά�����ʾ�ʺ��λ��
* ����������±��ʾ�ʺ����ڵ���
* ����Ԫ�ص�ֵ��ʾ�ʺ����ڵ���
* ������Ƶ����̣����лʺ�ض�����ͬһ�У������г�ͻ�Ͳ�������
* date  : 2011-08-03
* author: liuzhiwei
**/

#include <stdio.h>  
#include <stdlib.h>  
#include <math.h>  
#include <iostream>

#define QUEEN 8     //�ʺ����Ŀ  
#define INITIAL -1   //���̵ĳ�ʼֵ  

int a[QUEEN];    //һά�����ʾ����  

using namespace std;
void init()  //�����̽��г�ʼ��  
{
	int *p;
	for (p = a; p < a + QUEEN; ++p)
	{
		*p = INITIAL;
	}
}

int valid(int row, int col)    //�жϵ�row�е�col���Ƿ���Է��ûʺ�  
{
	int AX;
	for (AX = 0; AX < QUEEN; AX++)   //�����̽���ɨ��  
	{
		if (a[AX] == INITIAL)
		{
			continue;
		}
		if (a[AX] == col || abs(AX - row) == abs(a[AX] - col))   //�ж��г�ͻ��б���ϵĳ�ͻ  
		{
			printf("zero\n");
			return 0;
		}
	}
	printf("one\n");
	return 1;
}

void print()    //��ӡ���N�ʺ��һ���  
{
	int i, j;
	for (i = 0; i < QUEEN; ++i)
	{
		for (j = 0; j < QUEEN; ++j)
		{
			if (a[i] != j)      //a[i]Ϊ��ʼֵ  
				printf("%c ", '.');
			else                //a[i]��ʾ�ڵ�i�еĵ�a[i]�п��Է��ûʺ�  
				printf("%c ", '#');
		}
		printf("\n");
	}
	for (i = 0; i < QUEEN; ++i)
		printf("%d ", a[i]);
	printf("\n");
	printf("--------------------------------\n");
}

void queen()      //N�ʺ����  
{
	int n = 0;
	int BX = 0, DX = 0;
	while (BX < QUEEN)
	{
		while (DX < QUEEN)        //��i�е�ÿһ�н���̽�⣬���Ƿ���Է��ûʺ�  
		{
			if (valid(BX, DX))      //��λ�ÿ��Է��ûʺ�  
			{
				a[BX] = DX;        //��i�з��ûʺ�  
				DX = 0;           //��i�з��ûʺ��Ժ���Ҫ����̽����һ�еĻʺ�λ�ã����Դ˴���j���㣬����һ�еĵ�0�п�ʼ����̽��  
				break;
			}
			else
			{
				++DX;             //����̽����һ��  
			}
		}
		if (a[BX] == INITIAL)         //��i��û���ҵ����Է��ûʺ��λ��  
		{
			if (BX == 0)             //���ݵ���һ�У���Ȼ�޷��ҵ����Է��ûʺ��λ�ã���˵���Ѿ��ҵ����еĽ⣬������ֹ  
				break;
			else                    //û���ҵ����Է��ûʺ���У���ʱ��Ӧ�û���  
			{
				--BX;
				DX = a[BX] + 1;        //����һ�лʺ��λ��������һ��  
				a[BX] = INITIAL;      //����һ�лʺ��λ�����������̽��  
				continue;
			}
		}
		if (BX == QUEEN - 1)          //���һ���ҵ���һ���ʺ�λ�ã�˵���ҵ�һ���������ӡ����  
		{
			printf("answer %d : \n", ++n);
			break;
			//print();
			//�����ڴ˴�����������Ϊ����Ҫ�ҵ���N�ʺ���������н⣬��ʱӦ��������еĻʺ󣬴ӵ�ǰ���ûʺ���������һ�м���̽�⡣  
			//_sleep(600);  
			DX = a[BX] + 1;             //�����һ�з��ûʺ���������һ�м���̽��  
			a[BX] = INITIAL;           //������һ�еĻʺ�λ��  
			continue;
		}
		++BX;              //����̽����һ�еĻʺ�λ��  
	}
}

int main(void)
{
	init();
	queen();
	system("pause");
	return 0;
}