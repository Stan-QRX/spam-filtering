#include<string.h>
#include<string>
#include<iostream>
#include<malloc.h> 
using namespace std;
const char* ciku[] = { "打折"  ,"优惠","FUCK","123" };  //敏感词词库
int sum = 4;                             //若添加敏感词，需在这更改敏感词总数
#include"标头.h"
#define maxsum 100
int main()
{
	chuan c;
	char* d = (char*)malloc(sizeof(char) * maxsum);
	scanf("%[^\n]", d);      //  改动  1   读取字符串，遇到\n结束  这样可以读取空格之后的字符   原来的%s读到空格便会结束
	chushi(&c, maxsum, d);
	int flag = judge(c);  //判断是否为垃圾邮件，若为垃圾邮件则返回1，否则返回0
	if (flag == 1)
		printf("此邮件为垃圾邮件\n");
	else
		printf("此邮件为正常邮件\n");


	xiaohui(&c);       //  改动  2   撤销 串C  申请的动态空间

	free(d);  //撤销申请的动态空间
	d = 0;
	return 1;
}
