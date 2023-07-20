#define MAX1 60
#define MAX2 60
#define MAX3 60
#define MAX4 60
#define PI acos(-1.0)
#define Ee exp(1)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

//运算符栈
typedef struct 
{
	char elem[MAX1];
	int top; 
}Char_Setstack,*Char_Item;

//操作数栈
typedef struct 
{
	float elem[MAX2];
	int top; 
}Num_Setstack,*Num_Item;

//表达式栈
typedef struct 
{
	char elem[MAX3];
	int top;
}Exp_Setstack,*Exp_Item;

//历史记录栈
typedef struct 
{
	char elem[MAX4][MAX4];
	int top;
}RE_Setstack,*RE_Item;

Char_Item Create_Char_Stack(Char_Item s);//1.1
Num_Item Create_Number_Stack(Num_Item s);//1.2
Exp_Item Create_Exp_Stack(Exp_Item s);//1.3
RE_Item Create_Record_Stack(RE_Item s);//1.4

int Char_Empty_Stack(Char_Item s);//2.1
int Number_Empty_Stack(Num_Item s);//2.2
int Exp_Empty_Stack(Exp_Item s);//2.3

int Char_Push_Stack(Char_Item s,char chars) ;//3.1
int Number_Push_Stack(Num_Item s,float num);//3.2
int Exp_Push_Stack(Exp_Item s,char chars);//3.3
int Exp_Push_Stack_Operation(Exp_Item s,char chars);//3.4

int Char_Pop_Stack(Char_Item s,char *chars);//4.1
int Number_Pop_Stack(Num_Item s,float *num);//4.2
int Exp_Pop_Stack(Exp_Item s);//4.3

char Char_Get_Top_Stack(Char_Item s);//5.1
float Number_Get_Top_Stack(Num_Item s);//5.2

int Judge_Number(char chars);//6
char Compare_Char(char ch1,char ch2);//7

float Char_Two_Number_Identify(float num1,float num2,char chars);//8.1
float Char_One_Number_Identify(float num1,char chars,int elem);//8.2

void Delete_All(Char_Item s1,Num_Item s2,Exp_Item s3);//9
void Char_Number_Clear(void);//10
int Char_In_Chars(char chars,char Str[]);//11

void One_Behind_Operation(char chars,int elem);//12.1
void One_Previous_Operation(char chars);//12.2

void Two_Operation(char chars);//13
float factorial(float num);//14
int Optimize_print(float num1);//15
int Number_To_Char(float num1);//16

//全局变量

char ch,str;
Num_Item OP_N;
Char_Item OP_C;
Exp_Item OP_E;
RE_Item OP_R;
int LHD = 1;
int flag = 1,temp=1;

int main(void)
{	
	OP_N=Create_Number_Stack(OP_N);//操作数栈
	OP_C=Create_Char_Stack(OP_C);//运算符栈
	OP_E=Create_Exp_Stack(OP_E);//表达式栈
	OP_R=Create_Record_Stack(OP_R);//历史记录栈
	Char_Push_Stack(OP_C,'#');
	while(1)
	{
		Char_Number_Clear();//处理数据
	}
	return 0;
}

//运算符栈初始化函数----1.1
Char_Item Create_Char_Stack(Char_Item s)
{
	s=(Char_Item)malloc(sizeof(Char_Setstack));
	s->top=-1;	
	return s;
	/*不可以将压栈函数并到这个函数之中，否则会出错*/ 
}
//操作数栈初始化函数----1.2
Num_Item Create_Number_Stack(Num_Item s)
{
	s=(Num_Item)malloc(sizeof(Num_Setstack));
	s->top=-1;
	s->elem[0]=0;
	return s;
}
//表达式栈初始化函数----1.3
Exp_Item Create_Exp_Stack(Exp_Item s)
{
	s=(Exp_Item)malloc(sizeof(Exp_Setstack));
	s->top=-1;
	return s;
}
//历史记录栈初始化函数----1.4
RE_Item Create_Record_Stack(RE_Item s)
{
	s=(RE_Item)malloc(sizeof(RE_Setstack));
	s->top=0;
	return s;
}


//判断运算符栈是否空栈函数----2.1
int Char_Empty_Stack(Char_Item s)
{
	if(s->top==-1) return 1;
	else return 0;
}
//判断操作数栈是否空栈函数----2.2
int Number_Empty_Stack(Num_Item s)
{
	if(s->top==-1) return 1;
	else return 0;
}
//判断表达式栈是否空栈函数----2.3
int Exp_Empty_Stack(Exp_Item s)
{
	if(s->top==-1) return 1;
	else return 0;
}


//字符入栈函数----3.1
int Char_Push_Stack(Char_Item s,char chars) 
{
	if(s->top==MAX1-1) return 0; 
	s->top++;
	s->elem[s->top]=chars;
	return 1;	
}
//操作数入栈函数----3.2
int Number_Push_Stack(Num_Item s,float num) 
{
	if(s->top==MAX2-1) return 0; 
	s->top++;
	s->elem[s->top]=num;
	return 1;	
}
//已输入可直接打印字符入表达式栈函数----3.3
int Exp_Push_Stack(Exp_Item s,char chars)
{
	if(chars=='d'||chars=='C') return 1;
	if(s->top==MAX3-1) return 0;
	char LH_Chars[]="+-*/=()%!^";
	if(Judge_Number(chars)||Char_In_Chars(chars,LH_Chars))
	{
		s->top++;
		s->elem[s->top]=chars;
		s->elem[s->top+1]='\0';	
	}
	else
	{
		if(chars=='e')
		{
			Exp_Push_Stack_Operation(OP_E,'2');
			Exp_Push_Stack_Operation(OP_E,'.');
			Exp_Push_Stack_Operation(OP_E,'7');
			Exp_Push_Stack_Operation(OP_E,'2');
		}
		if(chars=='P')
		{
			Exp_Push_Stack_Operation(OP_E,'3');
			Exp_Push_Stack_Operation(OP_E,'.');
			Exp_Push_Stack_Operation(OP_E,'1');
			Exp_Push_Stack_Operation(OP_E,'4');
		}
		if(chars=='s')
		{
			Exp_Push_Stack_Operation(OP_E,'s');
			Exp_Push_Stack_Operation(OP_E,'i');
			Exp_Push_Stack_Operation(OP_E,'n');
		}
		if(chars=='o')
		{
			Exp_Push_Stack_Operation(OP_E,'c');
			Exp_Push_Stack_Operation(OP_E,'o');
			Exp_Push_Stack_Operation(OP_E,'s');
		}
		if(chars=='t')
		{
			Exp_Push_Stack_Operation(OP_E,'t');
			Exp_Push_Stack_Operation(OP_E,'a');
			Exp_Push_Stack_Operation(OP_E,'n');
		}
		if(chars=='D')
		{
			Exp_Push_Stack_Operation(OP_E,'a');
			Exp_Push_Stack_Operation(OP_E,'r');
			Exp_Push_Stack_Operation(OP_E,'c');	
		}
		if(chars=='N')
		{
			Exp_Push_Stack_Operation(OP_E,'I');
			Exp_Push_Stack_Operation(OP_E,'n');
		}
		if(chars=='G')
		{
			Exp_Push_Stack_Operation(OP_E,'l');
			Exp_Push_Stack_Operation(OP_E,'g');
		}
		if(chars=='S')
		{
			Exp_Push_Stack_Operation(OP_E,'s');
			Exp_Push_Stack_Operation(OP_E,'q');
			Exp_Push_Stack_Operation(OP_E,'r');
			Exp_Push_Stack_Operation(OP_E,'t');
		}
	}
	//当前动态变化栏输出接口
//	puts(s->elem);
	return 1;
}
//已输入非直接打印字符入表达式栈函数----3.4
int Exp_Push_Stack_Operation(Exp_Item s,char chars)
{
	if(s->top==MAX3-1) return 0;
	s->top++;
	s->elem[s->top]=chars;
	s->elem[s->top+1]='\0';
}


//字符出栈函数----4.1
int Char_Pop_Stack(Char_Item s,char *chars)
{
	if(Char_Empty_Stack(s)) return 0;
	*chars=s->elem[s->top];
	s->top--;
	return 1;
} 
//操作数出栈函数----4.2
int Number_Pop_Stack(Num_Item s,float *num)
{
	if(Number_Empty_Stack(s))  return 0;
	*num=s->elem[s->top];
	s->top--;
	return 1;
}
//表达式栈出栈函数(退格键)----4.3
int Exp_Pop_Stack(Exp_Item s)
{
	if(Exp_Empty_Stack(s)) return 0;
	s->elem[s->top]='\0';
	s->top--;
	return 1;
}


//取运算符栈顶元素----5.1
char Char_Get_Top_Stack(Char_Item s)
{
	if(Char_Empty_Stack(s)) return '0';
	return s->elem[s->top];
}
//取操作数栈顶元素----5.2
float Number_Get_Top_Stack(Num_Item s)
{
	if(Number_Empty_Stack(s)) return 0;
	return s->elem[s->top];
}


//判断输入字符是不是数字字符----6
int Judge_Number(char chars)
{
	if(chars>='0'&&chars<='9'||chars=='.') return 1;
	else return 0;
}

//比较两个符号的优先级----7
char Compare_Char(char ch1,char ch2)
{
	if(ch1=='+'||ch1=='-')
	{
		char LH_chars[]="+-)=";
		if(Char_In_Chars(ch2,LH_chars)) return '>';
		else return '<';
	}
	if(ch1=='*'||ch1=='/'||ch1=='^')
	{
		char LH_chars[]="(sotNGS";
		if(Char_In_Chars(ch2,LH_chars)) return '<';
		else return '>';
	}
	if(ch1=='(')
	{
		if(ch2==')'||ch2=='=')
		{
			if(ch2==')') return '&';
			if(ch2=='=') return '0';
		}
		else return '<';
	}
	if(ch1==')')
	{
		if(ch2=='(') return '0';
		else return '>';
	}
	if(ch1=='#')
	{
		if(ch2==')'||ch2=='=')
		{
			if(ch2==')') return '0';
			if(ch2=='=') return '&';
		}
		else return '<';
	}
	char LHA_chars[]="sotNGS";
	if(Char_In_Chars(ch1,LHA_chars))
	{
		if(ch2=='(') return '<';
		else return '>';
	}
	if(ch1=='D') return '<';
}



//字符数字识别二目运算函数----8.1
float Char_Two_Number_Identify(float num1,float num2,char chars)
{
	if (chars == '+') return num1 + num2;
	if (chars == '-') return num2 - num1;
	if (chars == '*') return num1 * num2;
	if (chars == '/')
	{
		if (num1 == 0)
		{
			LHD = 0;
			return 0;
		}
		return num2 / num1;
	}
	if (chars == '^') return pow(num2, num1);
	return 0;
}
//字符数字识别一目运算函数----8.2
float Char_One_Number_Identify(float num1,char chars,int elem)
{
	if (chars == 's' && elem == 1) return sin(num1);
	if (chars == 's' && elem == 0)
	{
		if (num1 < -1 || 1 < num1)
		{
			LHD = 0;
			return 0;
		}
		return asin(num1);
	}
	if (chars == 'o' && elem == 1) return cos(num1);
	if (chars == 'o' && elem == 0)
	{
		if (num1 < -1 || 1 < num1)
		{
			LHD = 0;
			return 0;
		}
		return acos(num1);
	}
	if (chars == 't' && elem == 1) 
	{
		if (num1==PI/2)
		{
			LHD = 0;
			return 0;
		}
		return tan(num1);
	}
	if (chars == 't' && elem == 0) return atan(num1);
	if (chars == 'N')
	{
		if (num1 <= 0)
		{
			LHD = 0;
			return 0;
		}
		return log(num1);
	}
	if (chars == 'G')
	{
		if (num1 <= 0)
		{
			LHD = 0;
			return 0;
		}
		return log10(num1);
	}
	if (chars == 'S')
	{
		if (num1 < 0)
		{
			LHD = 0;
			return 0;
		}
		return sqrt(num1);
	}
	return 0;
}


//当前显示清空函数(AC键)----9
void Delete_Current(Char_Item s1,Num_Item s2,Exp_Item s3)
{
	s1->top=0;
	s2->top=-1;
	s3->top=-1;
	s3->elem[0]='\0';
}

//栈区清算函数----10
void Char_Number_Clear(void)
{
	int i;
	temp=1;
	float data;
	char x;
	flag:
		str=ch;
		ch=getchar();
		Exp_Push_Stack(OP_E,ch);
	data=0;
	while(ch!='='||Char_Get_Top_Stack(OP_C)!='#')
	{
		//退格功能块
		if(ch=='d')
		{
			if (Judge_Number(str)||str=='e'||str=='P')
			{
				if (Number_Get_Top_Stack(OP_N) == PI || Number_Get_Top_Stack(OP_N) == Ee) temp = 2;
				for (i = 0; i <= temp + 1; i++)
				{
					Exp_Pop_Stack(OP_E);
				}
			}
			else
			{
				Exp_Pop_Stack(OP_E);
			}
			//退格功能键接口
//			puts(OP_E->elem);
			if(Judge_Number(str))
			{
				float a;
				Number_Pop_Stack(OP_N,&a);
			}
			else
			{
				char a;
				Char_Pop_Stack(OP_C,&a);
			}
			str=ch;
			ch=getchar();
			while(ch=='d')
			{
				ch=getchar();
			}
			Exp_Push_Stack(OP_E,ch);
			continue;
		}

		//AC功能块
		if(ch=='C')
		{
			Delete_Current(OP_C,OP_N,OP_E);
			goto flag;
		}

		if(ch=='!'||ch=='%')
		{
			One_Previous_Operation(ch);
			str=ch;
			ch=getchar();
			Exp_Push_Stack(OP_E,ch);
			continue;
		}

		if(ch=='D')
		{
			Char_Push_Stack(OP_C,'D');
			str=ch;
			ch=getchar();
			Exp_Push_Stack(OP_E,ch);
			continue;
		}


//修改点，判断增多
		if(Judge_Number(ch)||ch=='P'||ch=='e'||(str=='('&&ch=='-'))
		{
			int elem=1,i=-1;
			if(ch=='P')
			{
				data=PI;
				Number_Push_Stack(OP_N,data);
				str='P';
				ch=getchar();
				Exp_Push_Stack(OP_E,ch);
				continue;
			}
			if(ch=='e')
			{
				data=Ee;
				Number_Push_Stack(OP_N,data);
				str='e';
				ch=getchar();
				Exp_Push_Stack(OP_E,ch);
				continue;
			}
			if(ch=='-')
			{
				Number_Push_Stack(OP_N,-1);
				Char_Push_Stack(OP_C,'*');
				str=ch;
				ch=getchar();
				Exp_Push_Stack(OP_E,ch);
				continue;
			}
			data=ch-'0';
			str=ch;
			ch=getchar();
			Exp_Push_Stack(OP_E,ch);
			while(Judge_Number(ch))
			{
				if(ch=='.') 
				{
					elem=0;
					str=ch;
					ch=getchar();
					Exp_Push_Stack(OP_E,ch);
					temp++;
					continue;
				}
				
				if(elem==1)//整数处理部分
				{
					data=data*10+ch-'0';
					str=ch;
					ch=getchar();
					Exp_Push_Stack(OP_E,ch);
					temp++;
				}
				else//小数处理部分
				{
					data=data+(ch-'0')*pow(10,i);
					i--;
					str=ch;
					ch=getchar();
					Exp_Push_Stack(OP_E,ch);
					temp++;
				}												
			}
			Number_Push_Stack(OP_N,data);
			temp=1;
		}	
		else
		{
			switch(Compare_Char(Char_Get_Top_Stack(OP_C),ch))
			{
				case '<':
				{
					Char_Push_Stack(OP_C,ch);
					str=ch;
					ch=getchar();
					Exp_Push_Stack(OP_E,ch);
					break;
				}
				case '&':
				{
					Char_Pop_Stack(OP_C,&x);
					str=ch;
					ch=getchar();
					Exp_Push_Stack(OP_E,ch);
					break;
				}
				case '>':
				{
					int elem=1;
					char op1,op2;
					char LH_Chars[]="+-*/^";
					Char_Pop_Stack(OP_C,&op1);
					op2=Char_Get_Top_Stack(OP_C);
					if(op2=='D')//判断反三角函数
					{
						elem=0;
						Char_Pop_Stack(OP_C,&op2);//删除arc
					}

					if(Char_In_Chars(op1,LH_Chars))
					{
						Two_Operation(op1);
						break;
					}
					else
					{
						One_Behind_Operation(op1,elem);
						break;
					}					
				}
			}
		}
	}
	Optimize_print(Number_Get_Top_Stack(OP_N));//优化输出(输出当前运算的结果)
	Number_To_Char(Number_Get_Top_Stack(OP_N));//整合数据(含历史记录)
	Delete_Current(OP_C,OP_N,OP_E);
	getchar();
}

//字符包含函数----11
int Char_In_Chars(char chars,char Str[])
{
	int i=0,loge=strlen(Str);
	for(;i<loge;i++)
	{
		if(chars==Str[i])  return 1;
	}
	return 0;
}


//一目_近后运算函数----12.1
void One_Behind_Operation(char chars,int elem)
{
	float data,num1;
	Number_Pop_Stack(OP_N,&num1);
	data=Char_One_Number_Identify(num1,chars,elem);
	Number_Push_Stack(OP_N,data);
}
//一目_近前运算函数----12.2
void One_Previous_Operation(char chars)
{
	float data,num1;
	Number_Pop_Stack(OP_N,&num1);
	if(chars=='!') Number_Push_Stack(OP_N,factorial(num1));
	if(chars=='%') Number_Push_Stack(OP_N,num1/100.0);
}


//二目运算函数----13
void Two_Operation(char chars)
{
	float data,num1,num2;
	Number_Pop_Stack(OP_N,&num1);
	Number_Pop_Stack(OP_N,&num2);
	data=Char_Two_Number_Identify(num1,num2,chars);
	Number_Push_Stack(OP_N,data);
}

//阶乘函数----14
float factorial(float num)
{
	int Num=(int)num;
	if(Num==1||Num==2) return Num;
	return Num*factorial(Num-1);
}

//优化输出功能函数----15
int Optimize_print(float num1)
{
	int num2=num1/1;
	//单次计算完毕输出接口
	if(num1==num2) 
	{
		printf("%d\n",num2);
		return 1;
	}
	else 
	{
		printf("%.2f\n",num1);
		return 0;
	}
}

//数字变字符串入表达式栈+整合历史记录函数----16
int Number_To_Char(float num1)
{
	int i=0,j,k,num2=num1*100;
	int num;
	char str1[10]={'0','0'};
	if(LHD)
	{
		if(num1<0)
		{
			Exp_Push_Stack_Operation(OP_E,'-');
			num1*=-1;
		}
		if(0<num1&&num1<1)
		{
			Exp_Push_Stack_Operation(OP_E,'0');
		}	
		
		if(num2==0)
		{
			Exp_Push_Stack_Operation(OP_E,'0');
			strcpy(OP_R->elem[OP_R->top],OP_E->elem);
			puts(OP_R->elem[OP_R->top]);
			OP_R->top++;
			return 1;
		}
		while(num2!=0)
		{
			num=num2%10;
			str1[i]=num+'0';
			i++;
			num2=(num2-num)/10;
		}
		for(j=i-1;j>1;j--,k++)
		{
			Exp_Push_Stack_Operation(OP_E,str1[j]);
		}
		if(str1[0]!='0'||str1[1]!='0')
		{
			Exp_Push_Stack_Operation(OP_E,'.');
			Exp_Push_Stack_Operation(OP_E,str1[1]);
			Exp_Push_Stack_Operation(OP_E,str1[0]);
		}
		strcpy(OP_R->elem[OP_R->top],OP_E->elem);
		OP_R->top++;
	}
	else
	{
		LHD=1;
	}
	//历史记录输出接口
	for(i=0;i<OP_R->top;i++)
	{
		puts(OP_R->elem[i]);
	}
	return 1;
}


