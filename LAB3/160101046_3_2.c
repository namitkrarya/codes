#include <stdio.h>
#include <stdlib.h>

//function checks if there are exactly two 'L' on the boundary!
int check_boundary(int row, int col, char c[row][col]){
	int counter=0;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
		if(c[i][j]=='L'&&(i==0||i==row-1||j==col-1||j==0))counter++;
		}	
	}
	if(counter==2)return 1;
	else return 0;
}

//function checks if there is exactly one path available to submit!
int check_path(int row, int col, char c[row][col],int p, int q,int xr, int xc, char dir, int * counter2,int *counter1){
	
	if(c[p][q]=='P'){(*counter1)++;return 0;}
	int x;
	char way;
	if(p==xr&&q==xc){(*counter2)++;return 1;}
	if((c[p+1][q]=='L'||c[p+1][q]=='P')&&dir!='D'){
		if(*counter1>=1)return 0;
		way = 'U';	
		c[p][q] = 'P';										//once a location is passed, it turns to 'P' so that we know that it has been traveresed if we encounter it again
		x = check_path(row, col, c, p+1, q, xr, xc, way, counter2, counter1);
		if(x==1&&(*counter2)>1)return 1;
	}
	if((c[p-1][q]=='L'||c[p-11][q]=='P')&&dir!='U'){
		if(*counter1>=1)return 0;
		way = 'D';
		c[p][q] = 'P';
		x = check_path(row, col, c, p-1, q, xr, xc, way,counter2,counter1);
		if(x==1&&(*counter2)>1)return 1;
	}
	if((c[p][q+1]=='L'||c[p][q+1]=='P')&&dir!='R'){
		if(*counter1>=1)return 0;
		way = 'L';
		c[p][q] = 'P';
		x = check_path(row, col, c, p, q+1, xr, xc, way,counter2,counter1);
		if(x==1&&(*counter2)>1)return 1;
	}
	if((c[p][q-1]=='L'||c[p][q-1]=='P')&&dir!='L'){
		if(*counter1>=1)return 0;
		way = 'R';
		c[p][q] = 'P';
		x = check_path(row, col, c, p, q-1, xr, xc, way,counter2,counter1);
		if(x==1&&(*counter2)>1)return 1;
		}
	if(*counter2==1&&*counter1==0)return 1;
	return 0;
}

//main function
int main(){
	int row, col;
	while(1){
		printf("Enter number of rows and coloumns :\n");
		scanf("%d %d", &row, &col);
		//stops taking input if both rows and coloumns are 0
		if(row==0&&col==0)break;
		if(row<=0||col<=0){
			printf("Wrong Input!\n");
			continue;
		}
		char c[row][col];
		char temp;
		scanf("%c", &temp);
		//taking the input and storing in a 2-D array
		//Do not enter a space after entering each row otherwise the input will not get stored properly
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				scanf("%c", &c[i][j]);							//enter only 'L' or 'T'
			}
			scanf("%c", &temp);
		}
		int i,j;
		int counter=0;
		int er,ec,xr,xc;
		//finds the entry and exit points for the jungle from the boundary
		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				if(c[i][j]=='L'&&(i==0||i==row-1||j==col-1||j==0))counter++;
				if(c[i][j]=='L'&&(i==0||i==row-1||j==col-1||j==0)&&counter==1){
					er = i;
					ec = j;
				}
				if(c[i][j]=='L'&&(i==0||i==row-1||j==col-1||j==0)&&counter==2){
					xr = i;
					xc = j;
				}
			}
		}
		//dir stores the direction where you don't have to go after moving forward
		char dir;
		int counter1=0;
		int counter2=0;
		if(er==0)dir = 'U';
		if(ec==0)dir = 'L';
		if(er==row-1)dir = 'D';
		if(ec==col-1)dir = 'R';
		if(check_boundary(row,col,c)){
			if(check_path(row, col, c, er, ec, xr, xc, dir, &counter2, &counter1)){
				if(counter2==1&&counter1==0){
					printf("Submitted!\n");
				}
				else printf("Bad Luck!\n");
			}
			else printf("Bad Luck!\n");	
		}
		else printf("Bad Luck!\n");
	}
	return 0;
}