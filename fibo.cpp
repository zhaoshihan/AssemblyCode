/**
* 回溯法解N皇后问题
* 使用一个一维数组表示皇后的位置
* 其中数组的下标表示皇后所在的行
* 数组元素的值表示皇后所在的列
* 这样设计的棋盘，所有皇后必定不在同一行，于是行冲突就不存在了
* date  : 2011-08-03
* author: liuzhiwei
**/

#include <stdio.h>  
#include <stdlib.h>  
#include <math.h>  
#include <iostream>

#define QUEEN 8     //皇后的数目  
#define INITIAL -1   //棋盘的初始值  

int a[QUEEN];    //一维数组表示棋盘  

using namespace std;
void init()  //对棋盘进行初始化  
{
	int *p;
	for (p = a; p < a + QUEEN; ++p)
	{
		*p = INITIAL;
	}
}

int valid(int row, int col)    //判断第row行第col列是否可以放置皇后  
{
	int AX;
	for (AX = 0; AX < QUEEN; AX++)   //对棋盘进行扫描  
	{
		if (a[AX] == INITIAL)
		{
			continue;
		}
		if (a[AX] == col || abs(AX - row) == abs(a[AX] - col))   //判断列冲突与斜线上的冲突  
		{
			printf("zero\n");
			return 0;
		}
	}
	printf("one\n");
	return 1;
}

void print()    //打印输出N皇后的一组解  
{
	int i, j;
	for (i = 0; i < QUEEN; ++i)
	{
		for (j = 0; j < QUEEN; ++j)
		{
			if (a[i] != j)      //a[i]为初始值  
				printf("%c ", '.');
			else                //a[i]表示在第i行的第a[i]列可以放置皇后  
				printf("%c ", '#');
		}
		printf("\n");
	}
	for (i = 0; i < QUEEN; ++i)
		printf("%d ", a[i]);
	printf("\n");
	printf("--------------------------------\n");
}

void queen()      //N皇后程序  
{
	int n = 0;
	int BX = 0, DX = 0;
	while (BX < QUEEN)
	{
		while (DX < QUEEN)        //对i行的每一列进行探测，看是否可以放置皇后  
		{
			if (valid(BX, DX))      //该位置可以放置皇后  
			{
				a[BX] = DX;        //第i行放置皇后  
				DX = 0;           //第i行放置皇后以后，需要继续探测下一行的皇后位置，所以此处将j清零，从下一行的第0列开始逐列探测  
				break;
			}
			else
			{
				++DX;             //继续探测下一列  
			}
		}
		if (a[BX] == INITIAL)         //第i行没有找到可以放置皇后的位置  
		{
			if (BX == 0)             //回溯到第一行，仍然无法找到可以放置皇后的位置，则说明已经找到所有的解，程序终止  
				break;
			else                    //没有找到可以放置皇后的列，此时就应该回溯  
			{
				--BX;
				DX = a[BX] + 1;        //把上一行皇后的位置往后移一列  
				a[BX] = INITIAL;      //把上一行皇后的位置清除，重新探测  
				continue;
			}
		}
		if (BX == QUEEN - 1)          //最后一行找到了一个皇后位置，说明找到一个结果，打印出来  
		{
			printf("answer %d : \n", ++n);
			break;
			//print();
			//不能在此处结束程序，因为我们要找的是N皇后问题的所有解，此时应该清除该行的皇后，从当前放置皇后列数的下一列继续探测。  
			//_sleep(600);  
			DX = a[BX] + 1;             //从最后一行放置皇后列数的下一列继续探测  
			a[BX] = INITIAL;           //清除最后一行的皇后位置  
			continue;
		}
		++BX;              //继续探测下一行的皇后位置  
	}
}

int main(void)
{
	init();
	queen();
	system("pause");
	return 0;
}