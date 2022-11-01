#include <stdio.h>
#include <stdlib.h>
#define MAX 10
struct MyStack{
	int top;           //堆疊頂端
	char a[MAX];       //堆疊主體
	
	bool IsEmpty();    //判斷堆疊是否為空，是則回傳1，否則0
	bool IsFull();     //判斷堆疊是否為滿，是則回傳1，否則0
	void Push(char);   //將一個字元傳進堆疊中
	char Pop();        //將一個字元從堆疊中拿出並回傳
	MyStack()		   //建構子
	{
		top = -1;
	}
}; 

bool CheckQuote(char*);

//==========================================
int main(){
	MyStack S1;
	
	FILE *fptr=fopen("20221027.txt", "r");
	char s[80];
	while(!feof(fptr))
	{
		fscanf(fptr, "%s",s);
		printf("%s: ", s);
		
		if(CheckQuote(s))
			printf("Correct!\n");
		else
			printf("Error!\n");
		s[0]='\0';
	}
	
	return 0;	
}
//=========================================
bool MyStack::IsEmpty()
{
	if(top==-1)
		return true;
		
	else
		return false;
	
}
//=========================================
bool MyStack::IsFull()
{
	if(top==MAX-1)		
		return true;
	else
		return false;
}
//=========================================
void MyStack::Push(char ch)
{
	if(IsFull())
	{
		printf("The stack is Full! Cannot push!\n");
	}
	else
	{
		top++;
		a[top]=ch;
	}
}
//=========================================
char MyStack::Pop()
{
	char ch;
	if(IsEmpty())
	{
		printf("The stack is Empty! Cannot pop!\n");
		return 0;
	}
	else
	{
		ch=a[top];
		top--;
		return ch;	
	}	
}
//=========================================

//               [(])  [()]

/* a.遇到左括號一律丟堆疊
   b.遇到右括號看堆疊頂端元素是否與目前得右括號配對
    	如果無法配對，就錯誤
    	或是堆疊已經空了也錯誤
   c.如果輸入字串已經結束，並且堆疊還有東西，錯誤
   d.如果輸入字串已經結束，並且堆疊也空了，正確。
*/ 
//=========================================
bool CheckQuote(char *s)
{
	MyStack S;
	int i=0;
	while(s[i]!='\0')
	{
		if(s[i]=='('||s[i]=='['||s[i]=='{')
		{
			S.Push(s[i]);
		}
		else
		{
			if(S.IsEmpty())
			{
				return false;
			}
			else
			{		
				if(s[i]==')')
				{
					if(S.Pop()!='(')
						return false; 
				}
				else if(s[i]==']')
				{
					if(S.Pop()!='[')
						return false; 
				}
				else
				{
					if(S.Pop()!='{')
						return false; 
				}
			}
		}
		i++;
	}
	if(!S.IsEmpty())
		return false;
	else
		return true;
}
    

