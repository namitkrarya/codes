#include<stdio.h>
char s[100];
int k=0;
char top;
void push(char a){
	s[k] = a;
	k++;
}
char pop(){
	k--;
	top = s[k];
	s[k] = '\0';
	return top;
}
int main(){
	push('a');
	push('b');
	push('c');
	pop();
	pop();
	printf("%c\n", pop());
	if(s[0]=='\0'){
		printf("Nice");
	}
}