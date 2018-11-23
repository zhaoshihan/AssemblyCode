# AssemblyCode
微机接口的汇编语言作业

## 如何运行?

1. 将tasm文件夹放在D盘根目录下
2. 打开DosBox，运行：
    
    `mount d d:\tasm`

     	`d:`

	`cd bin`

	`tasm [yourfile].asm`

	`tlink [yourfile].obj io.obj`

	`直接运行：[yourfile].exe`

	`调试运行：debug [yourfile].exe`

3. 这里需要说明的是文件名最好是英文小写，且字数不要太长，否则会有莫名其妙的错误

## 解题思路

### 求100以内的质数

这里用的是最基本的两重循环，寻找所有因数个数，取因数个数为2的数字打印。由于是100以内的输出，所以参考书上代码即可完成。


### 求前30位斐波那契数

这里的难点是第30位斐波那契数是83240，已经超出16位寄存器的最大范围，为此我使用了24位的数组`DB 3 dup(0)`这里的除法采用32位被除数，依次将数据放入AL,AH,DL寄存器，将DH置0再进行除法。为了方便起见，所有的结果都直接用（十进制）5位数来表示了。不断向十进制转换并输出万，千，百，十，个位是这道题的难点。


### 求八皇后问题的所有解

这里必须使用非递归的解题形式。具体的代码可以参见queen.cpp，使用一维数组来记录行列值，然后不断回溯探测出所有的解。这期间因为采用字`DW`形式造成数组`QUEEN[BX]`的存取出现问题，8086应该是默认以字节`DB`为单位进行寻址的。因此将所有的单位统一成`DB`格式，问题解决。
