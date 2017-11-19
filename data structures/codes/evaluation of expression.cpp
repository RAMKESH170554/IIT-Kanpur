/* --pseudo code--
Algorithm to convert Infix To Postfix
Let, X is an arithmetic expression written in infix notation. This algorithm finds the equivalent postfix expression Y.

Push “(“onto Stack, and add “)” to the end of X.
Scan X from left to right and repeat Step 3 to 6 for each element of X until the Stack is empty.
If an operand is encountered, add it to Y.
If a left parenthesis is encountered, push it onto Stack.
If an operator is encountered ,then:
Repeatedly pop from Stack and add to Y each operator (on the top of Stack) which has the 
same precedence as or higher precedence than operator.
Add operator to Stack.
[End of If]
If a right parenthesis is encountered ,then:
Repeatedly pop from Stack and add to Y each operator (on the top of Stack) until a left parenthesis is encountered.
Remove the left Parenthesis.
[End of If]
END.

my code does not take input in float type but in integer type
*/

#include<stdio.h>
#include<string.h>
#include<ctype.h> 
#include<stdlib.h>

int in[1000],po[1000]; char stack[1000];
int top, i, l;

int check(char a){
	int k = ( a == '+')+(a == '-')+( a == '/')+(a == '%')+(a == '*')+(a == '^')+(a == '#');
	return k;
}

int checko(char a){
	int k = ( a == '/')+(a == '%')+(a == '*')+( a == '+')+(a == '-');
	return k;
}

int pre(char symbol)
{
	if(symbol == '*')
	{
		return(2);
	}
	else if(symbol == '^' || symbol == '#')								// highest precedence
	{
		return(4);
	}
	else if(symbol == '%' || symbol == '/')			 
	{
		return(3);
	}
	else if(symbol == '+' || symbol == '-')          /* lowest precedence */
	{
		return(1);
	}
	else 
	{
		return(0);
	}
}


void post_expr(int in[], int n){
	i = 0; l = 0; top = -1;
	//strcat(in,")");
	in[n] = ')';
	in[n+1] = 0;
	stack[++top] = '(';
	
	while(i <= n){
		char u = (char)in[i];
		
		if(u == '('){
			
			if(in[i+1] == '-')
				in[i+1] = '^';
			if(in[i+1] == '+')
				in[i+1] = '#';
				
			stack[++top] = u;
		}				
		
		if((!check(u))&&(u != ')')&&(u != '(')){
			if(in[i] >= 0)
				po[l++] = in[i];
			else{
				po[l++] = 0;
				po[l++] = abs(in[i]);
				po[l++] = '-';
			}
		}
			
		if(check(u)){
			if((u == '^' || u == '#') && (in[i-1] == '^' || in[i-1] == '#')){
				stack[++top] = u;
			}
			else{
			while(pre(stack[top]) >= pre(u))
				po[l++] = stack[top--];

			stack[++top] = u;
			}
		}

		if(u == ')'){

			while(stack[top] != '(')
				po[l++] = stack[top--];

			top--;
		}
		
	i = i+1;		
	}
}

float evaluate(int po[],int n){
	l=0;
	//int x = 1;
	top = -1;
	float stack[1000];
	float value;
	while(l<n){
		if(check((char)po[l])){
			switch((char)po[l]){
				case '+':
					value = stack[top-1] + stack[top];
					stack[--top] = value;
					break;
				case '-':
					value = stack[top-1] - stack[top];
					stack[--top] = value;
					break;
				case '*':
					value = stack[top-1] * stack[top];
					stack[--top] = value;
					break;
				case '/':
					value = stack[top-1] / stack[top];
					stack[--top] = value;
					break;
				case '%':
					value = (int)stack[top-1] % (int)stack[top];
					stack[--top] = value;
					break;
				case '^':
					value = 0 - stack[top];
					stack[top] = value;
					break;
			}
		}
		else{
			stack[++top] = po[l]/100;
		}
		l++;
	}
	return stack[top];
}

int checkmal(int in[], int n){
	i = 0;
	int counter = 0;
	if(check((char)in[0]) && (in[0] != '^')&&(in[0] != '#'))
		return 1;
	if(check((char)in[n-1]))
		return 1;
	if((char)in[0] == ')')
		return 1;
	if((char)in[n-1] == '(')
		return 1;
	while(i < n){
		if((in[i] == '-' || in[i] == '+' || in[i] == '^' || in[i] == '#')*(in[i+1] == '^' || in[i+1] == '#'))
			{
				i++;
				continue;
			}
		else{	
		if(checko((char)in[i]) && checko((char)in[i+1]))
			return 1;
		if((in[i] == '#' || in[i] == '^') && checko((char)in[i+1]))
			return 1;
		if((char)in[i] == ')')
			counter++;
		if((char)in[i] == '(')
			counter--;
		i++;
		}
	}
	if(counter != 0)
		return 1;
	return 0;
}

//  11 4 * ( 3 + 5 ) / 7 % 3 
//  11 94 * ( 35 + -5 ) / 17 % 3 
//  14 94 * ( 35 + ( - 5 ) ) / 17 % 3

int main(){
	//printf("%s\n","PLEASE Enter with \"space\" and end with e");
	
	i = 0;
	char c[100];
	int test = 0;
	scanf("%d",&test);
	while(i < test){
		scanf("%s",c);
		int n = strlen(c);
//		if((c[n-1] == '-')&&((i == 0) || (in[i-1] == '('))){
//			in[i++] = '^';
//			scanf("%s",c);
//			n = strlen(c);
//		}
//		if(c[n-1] == 'e')
//			break;
		if((c[n-1] == '-' || c[n-1] == '+')*(i>0)*(check((char)in[i-1]))){
			if(c[0] == '-')
				in[i] = '^';
			else
				in[i] = '#';
			i++;
			continue;
		}
		if(isdigit(c[n-1]))
			in[i] = atoi(c)*100;
		else
			in[i] = c[0];
		i++;
	}
	if(in[0] == '-')
		in[0] = '^';
	if(in[0] == '+')
		in[0] = '#';
		
	in[i] = 0;
	int n = i;
//	for(int h =0; h<n;h++)
//	printf("%d ", in[h]);
	if(checkmal(in,n) == 0){	
		post_expr(in,n);

	if(top>0)
		printf("Malformed expression");
	else{
		po[l] = 0;
				
	    for(int h=0;h<l;h++){
	    	char u = po[h];
	    	if(check(u) && (u != '^') && (u != '#'))
	    		printf("%c ",u);
	    	else if(po[h] == 0)
	    		continue;
	    	else if(po[h] == '^')
	    		printf("- ");
	    	else if(po[h] == '#')
	    		printf("+ ");
	    	else
	    		printf("%d ",po[h]/100);
		}
		
		float value = evaluate(po,l);
	    printf("\n%lf",value);
	}
}
	else
		printf("Malformed expression");
		
return 0;
}
