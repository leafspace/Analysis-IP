/* Note:Your choice is C IDE */
/*二进制数包括符号位求反码补码*/
#include "stdio.h"
void main()
{
	char ch;
	int num[32], i = 0, k = 0, t, ym[32], fm[32], bm[32], cs = 1, flag;
	double sum;
	loop：scanf("%d", &sum);                                           /*此时输入的是二进制的数但是以十进制的数存储*/
	while (sum)
	{
		num[k++] = sum % 10;
		sum = sum / 10;
	}
	for (i = 0; i < k; i++)
		if (num[i] > 1)
		{
			printf("数据错误！请重输！");
			goto loop；
		}
	printf("您输入的是正数还是负数？\n");
sub:ch = getchar();
	if (ch == '+') num[k++] = 0;
	else if (ch == '-') num[k++] = 1;
	else
	{
		printf("输入错误，请重输!!");
		goto sub;
	}
	for (i = 0; i < k / 2; i++)
	{
		t = num[i];
		num[i] = num[k - 1 - i];
		num[k - 1 - i] = t;
	}
	if (!num[0])
		goto end;
	for (i = 0; i < k; i++)
		ym[i] = num[i];
	fm[0] = 1;
	for (i = 1; i < k; i++)
		fm[i] = !num[i];
	for (i = k - 1; i >= 0; i--)
	{
		bm[i] = fm[i] + cs;
		switch (bm[i])
		{
		case 1:cs = 0; break;
		case 2:bm[i] = 0; break;
		}
		if (i == 1)   flag = cs;
		if (i == 0)   if (flag == cs)  flag = 1;
		else          flag = 0;
		if (!cs)    break;
	}
	if (!flag)
	{
		printf("发生了溢出！！\n");
		goto end;
	}
end:if (ch == '+')
{
	printf("原码=反码=补码=");
	for (i = 0; i < k; i++)
		printf("%d", num[i]);
}
	else
	{
		printf("");
	}
}
