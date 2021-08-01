typedef struct chuan1
{
	char* str;
	int chang;
	int maxchang;

}chuan;
int  chushi(chuan* s, int max, char* d) //动态数组方法
{
	if (max < strlen(d))
	{
		printf("初始化错误，MAX太小\n");
		return 0;
	}
	s->str = (char*)malloc(sizeof(char) * max + 1);
	//for (int n = 0; n < strlen(d); n++)
		//s->str[n] = d[n];
	strcpy(s->str, d);
	s->chang = strlen(d);
	s->maxchang = max;
	return 1;
}
void xiaohui(chuan* s)
{
	free(s->str);
	s->str = 0;
	
}

int bf(chuan s, int start, const char* z) //s主串   z子串  成功返回子串在主串的首字符下标(  >=0  )，否则返回-1  
// n 为  总体 比较中子串在主串的首字符下标， i为主串正在匹配的字符下标  j为子串正在匹配的字符下标，  
{
	int i = start;
	int n = i;
	int j = 0;
	while (i<s.chang )
	{
		if (s.str[i] == z[j])
		{

			i++;
			j++;
			if (strlen(z) == j) //子串完了并且在主串中找到了子串，则返回子串在主串的首字符(  >=0  )
				return i - j;
		}
		else
		{
			n++;
			i = n;
			j = 0;
		}
	}
	return -1;
}
int judge(chuan c)  
{
	char* a=0;
	int flag = 0;  // flag==0 非垃圾邮件     ==1 垃圾邮件
	int tag = 0;    // tag==0  汉字   ==1  字母
	for (int i = 0; i < sum; i++)
	{
		if (64 < (int)ciku[i][0] && 123 > (int)ciku[i][0])
			tag = 1;
		if (bf(c, 0, ciku[i]) != -1)
		{
			flag = 1;
			break;
		}
		if (tag == 1)
		{
             a = (char*)malloc(1 * sizeof(ciku[i]) + 1);
			strcpy(a, ciku[i]);
		
			if (islower(ciku[i][0]))   //是小写字母的话
			{
				strupr(a);
			}
			else
			{
				strlwr(a);
			}
			if (bf(c, 0, a) != -1)
			{
				flag = 1;
				break;
			}
		}
		
		
	}
	free(a);
	//a=0;  //局部变量指针
	return flag;
	
}


