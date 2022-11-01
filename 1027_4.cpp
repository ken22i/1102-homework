#include <stdio.h>
#include <stdlib.h>
#define MAX 60
struct MyStack{
	int top;           //���|����
	char a[MAX];       //���|�D��
	
	bool IsEmpty();    //�P�_���|�O�_���šA�O�h�^��1�A�_�h0
	bool IsFull();     //�P�_���|�O�_�����A�O�h�^��1�A�_�h0
	void Push(char);   //�N�@�Ӧr���Ƕi���|��
	char Pop();        //�N�@�Ӧr���q���|�����X�æ^��
	MyStack()		   //�غc�l
	{
		top = -1;
	}
	
}; 


MyStack deles(MyStack);
//==========================================
int main(){
	MyStack S1;
	MyStack S2;
	int i=0;
	FILE *fptr=fopen("input.txt", "r");
	char s[80];
	
	
	fscanf(fptr, "%[^\n]%*c",s);
	printf("%s \n", s);
	while(s[i]!='\0'){
		S1.Push(s[i]);
			i++;
	}
	
	fscanf(fptr, "%[^\n]%*c",s);
	printf("%s \n", s);
	while(s[i]!='\0'){
		S2.Push(s[i]);
			i++;
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

/* a.�J�쥪�A���@�ߥ���|
   b.�J��k�A���ݰ��|���ݤ����O�_�P�ثe�o�k�A���t��
    	�p�G�L�k�t��A�N���~
    	�άO���|�w�g�ŤF�]���~
   c.�p�G��J�r��w�g�����A�åB���|�٦��F��A���~
   d.�p�G��J�r��w�g�����A�åB���|�]�ŤF�A���T�C
*/ 
//=========================================
MyStack deles(MyStack s){
	MyStack result;
	char tem1,tem2;
	while(!s.IsEmpty()){
		tem1=s.Pop();
		if(tem1=='s'){
			while(tem2!='e'){
				tem2=s.Pop();
			}
			result.Push(tem2);
		}
		else{
			result.Push(tem1);
		}
	}
	return result;
	
}
    

