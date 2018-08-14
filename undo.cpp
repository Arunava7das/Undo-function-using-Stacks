#include<stdio.h>
#include<stdlib.h>


int max = 5;
int max1 = 100;

int update_top1(int &top1)
{
	return top1--;
}


int push(int a[], int &top)
{
	int val;
	printf("Enter the value to be inserted: ");
	scanf("%d", &val);
	
	if(top==max-1)
	{
		printf("Overflow!!");
	}
	
	else
	{
		top++;
		a[top] = val;
	}
	
	return top;
}

int push1(int popped_from_a, int b[], int &top1)
{
	
	if(top1==max1-1)
	{
		printf("Overflow!!");
	}
	
	else
	{
		top1++;
		b[top1] = popped_from_a;
	}
	
	return top1;
}

int pop(int a[], int b[], int &top, int &top1)
{
	if(top==-1)
	{
		printf("Underflow!!");
	}
	
	else
	{
		printf("Deleting value %d", a[top]);
		push1(a[top], b, top1);
		top--;
	}
	
	return top;
}

int undo(int a[], int b[], int &top, int &top1)
{
	printf("Undoing.....\n");
	
	if(max==top)
	{
		printf("Nothing to undo!!\n");
	}
	
	else
	{
		top++;
		a[top] = b[top1];
		update_top1(top1);		
	}
	return top;
}


int display(int a[], int top)
{
	for(int i=top; i>=0; i--)
	{
		printf("%d\n", a[i]);
	}
}

int main()
{
	int top = -1;
	int top1 = - 1;
	
	//int max = 5;
	int a[max];

	//int max1 = 100;
	int b[max1];
	
	int s;	
	
	while(1)
	{
		printf("\nEnter options 1.PUSH \n 2.POP\n 3.PEEK\n 4.UNDO\n 5.QUIT\n");
		scanf("%d", &s);
		printf("\n\n");
		
		switch(s)
		{
			case 1:
					push(a, top);
					break;	
				
			case 2:	pop(a, b, top, top1);
					break;
			
			case 3: display(a, top);
					break;
			
				
			case 4: undo(a, b, top, top1);
					break;
					
			case 5: exit(0);
					break;
					
			default: printf("Wrong Input!!");
					break;					
		}	
	}	
}





