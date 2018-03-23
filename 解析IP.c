/* Note:Your choice is C IDE */
#include "stdio.h"
#include "math.h"
void main()
{
	int a[4][8] = { 0 }, fz[4][8] = { 0 }, b[4] = { 0 }, c[4] = { 0 }, zw[4] = { 0 }, gb[4] = { 0 }, fw[2][4] = { 0 }, zjh[4] = { 0 }, i = 0, j = 0, k = 0, t = 0, ws1 = 0, ws2 = 0, ws3 = 0;
	char ch, flag;
	printf("                                      解析IP\n");
	printf("                                                                      BY  DACK\n");
	printf("==============================================================================\n");
loop:printf("请您输入您将要运算的IP地址（请用“.”分隔）：\n");
	scanf("%3d.%3d.%3d.%3d", &b[0], &b[1], &b[2], &b[3]);
	if (b[0] > 233 || b[1] > 255 || b[2] > 255 || b[3] > 255)
	{
		printf("您输入的不是正常的A、B、C类地址，请重新输入！\n");
		goto loop;
	}
	if (b[0] >= 0 && b[0] <= 127)
	{
		k = 1; flag = 'A';
	}
	if (b[0] >= 128 && b[0] <= 191)
	{
		k = 2; flag = 'B';
	}
	if (b[0] >= 192 && b[0] <= 233)
	{
		k = 3; flag = 'c';
	}
	printf("您输入的是：%3d.%3d.%3d.%3d\n", b[0], b[1], b[2], b[3]);
	printf("您输入的IP地址为：%3c类的IP地址\n", flag);
	printf("假如有误：请输入‘N’，然后根据提示重新输入，假如正确，请输入‘Y’，并根据提示继续进行\n");
	ch = getchar(); scanf("%c", &ch);
	if (ch != 'Y'&&ch != 'y') { ch = 'N'; goto loop; }
	else    printf("请继续\n");
sub:printf("请输入子网掩码：\n");
	scanf("%3d.%3d.%3d.%3d", &c[0], &c[1], &c[2], &c[3]);
	switch (k)
	{
	case 1: if (c[0] < 255)  i = 1; break;
	case 2: if (c[0] < 255 || c[1] < 255)  i = 1; break;
	case 3: if (c[0] < 255 || c[1] < 255 || c[2] < 255)  i = 1; break;
	}
	if (i || c[0] < c[1] || c[1] < c[2] || c[2] < c[3])
	{
		printf("您输入的子网掩码不符合正常分配子网后的子网掩码的要求，请重新输入！\n");
		i = 0;
		goto sub;
	}
	printf("您输入的是：%3d.%3d.%3d.%3d\n", c[0], c[1], c[2], c[3]);
	printf("假如有误：请输入‘N’，然后根据提示重新输入，假如正确，请输入‘Y’，并根据提示继续进行\n");
	ch = getchar(); scanf("%c", &ch);
	if (ch != 'Y'&&ch != 'y') { ch = 'N'; goto sub; }
	else    printf("请继续\n");
	for (i = 0; i < 4; i++)
	{
		j = 7;
		while (b[i] != 0)
		{
			a[i][j--] = b[i] % 2;
			b[i] = b[i] / 2;
		}
	}
	printf("IP地址二进制数值：\n");
	for (i = 0; i < 4; i++)                 /*输出a中的正向IP解析二进制的数值*/
	{
		for (j = 0; j < 8; j++)
			printf("%3d", a[i][j]);
		printf("\n");
	}                                       /*输出a中的正向IP解析二进制的数值*/
	for (i = 0; i < 4; i++)
		for (j = 0; j < 8; j++)
			fz[i][j] = a[i][j];
	printf("\n");
	for (i = k; i <= 3; i++)
		while (c[i] != 0)
			c[i] = c[i] - (128 / pow(2, t++));
	ws1 = t;
	printf("\n\n划分了%2d位作为网络地址\n", ws1);
	ws1 = ws2 = ws3 = (4 - k) * 8 - ws1;
	printf("\n\n划分了%2d位作为主机地址\n", ws1);
	for (i = 3; i >= 0; i--)
		for (j = 7; j >= 0; j--)
		{
			if (ws1 == 0)  break;
			a[i][j] = 0;
			ws1--;
		}
	printf("子网地址二进制数值为：\n");
	for (i = 0; i < 4; i++)                 /*输出a中的子网地址二进制的数值*/
	{
		for (j = 0; j < 8; j++)
			printf("%3d", a[i][j]);
		printf("\n");
	}                                       /*输出a中的子网地址二进制的数值*/
	for (i = 0; i < 4; i++)
	{
		t = 0;
		for (j = 0; j < 8; j++)
			if (a[i][j] == 1)
				t = t + pow(2, 7 - j);
		zw[i] = t;
	}
	printf("子网地址十进制数值为：\n");
	for (i = 0; i < 4; i++)                 /*输出a中的正向子网地址解析十进制的数值*/
		printf("%3d   ", zw[i]);            /*输出a中的正向子网地址解析十进制的数值*/
	for (i = 3; i >= 0; i--)
		for (j = 7; j >= 0; j--)
		{
			if (ws2 == 0)   break;
			a[i][j] = 1;
			ws2--;
		}
	printf("\n");	printf("\n");	printf("\n");	printf("\n");
	printf("广播地址二进制数值为：\n");
	for (i = 0; i < 4; i++)                 /*输出a中的广播地址二进制数值*/
	{
		for (j = 0; j < 8; j++)
			printf("%3d", a[i][j]);
		printf("\n");
	}                                       /*输出a中的广播地址二进制数值*/
	for (i = 0; i < 4; i++)
	{
		t = 0;
		for (j = 0; j < 8; j++)
			if (a[i][j] == 1) t = t + pow(2, 7 - j);
		gb[i] = t;
	}
	printf("广播地址十进制数值为：\n");
	for (i = 0; i < 4; i++)                 /*输出a中的正向广播地址解析十进制的数值*/
		printf("%3d   ", gb[i]);            /*输出a中的正向广播地址解析十进制的数值*/
	for (i = 0; i < 4; i++)
	{
		fw[0][i] = zw[i];
		fw[1][i] = gb[i];
	}
	printf("\n");	printf("\n");	printf("\n");	printf("\n");
	fw[0][3] += 1;
	fw[1][3] -= 1;
	for (i = 3; i >= 0; i--)
	{
		t = 0;
		for (j = 7; j >= 0; j--)
		{
			if (ws3 == 0)  break;
			if (fz[i][j] == 1)
				t = t + pow(2, 7 - j);
			ws3--;
		}
		zjh[i] = t;
	}
	t = zjh[0] + zjh[1] + zjh[2] + zjh[3];
	printf("子网地址为：%3d.%3d.%3d.%3d\n", zw[0], zw[1], zw[2], zw[3]);
	printf("广播地址为：%3d.%3d.%3d.%3d\n", gb[0], gb[1], gb[2], gb[3]);
	printf("本子网可用的IP范围为：%3d.%3d.%3d.%3d————%3d.%3d.%3d.%3d\n", fw[0][0], fw[0][1], fw[0][2], fw[0][3], fw[1][0], fw[1][1], fw[1][2], fw[1][3]);
	printf("本IP号在本子网内的主机号为：%3d\n", t);
	printf("按任意键加回车退出");
	ch = getchar(); scanf("%c", &ch);
}


