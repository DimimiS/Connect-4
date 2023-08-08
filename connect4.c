#include <stdio.h>
#include <stdlib.h>

int getchoice(void);
void printarray(char arr[7][7]);
int placechoice(int choice, char arr[7][7], int p);
void createarray(char arr[7][7]);
int computerplays(char arr[7][7], int cline);
int getwinner(char arr[7][7], int choice, int line, int p);
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int choice=0, game, line, cc, cline;
	char arr[7][7];
	
	printf("Human against cpu game (input 1) or two human players game (input 2)\n");
	game=getchoice();
	createarray(arr);
	while (choice!=-1){
		printf("Player 1 input the column:\n");
		choice=getchoice();
		line=placechoice(choice-1, arr, 1);
		while (line==-1){
			printf("This column is full, choose another one:\n");
			choice=getchoice();
			line=placechoice(choice-1, arr, 1);
		}
		printarray(arr);
		if (getwinner(arr, choice, line, 1)==0){
			printf("It\'s a tie!");
			break;
		}
		else if (getwinner(arr, choice, line, 1)==1){
			printf("Player 1 won!");
			break;
		}
		else if (getwinner(arr, choice, line, 1)==2){
			printf("Player 2 won!");
			break;
		}
		if (game==1){
			printf("Computer plays:\n");
			cc=computerplays(arr, 0);
			cline=placechoice(cc, arr, 2);
			while (cline==-1){
				cc=computerplays(arr, cline);
				cline=placechoice(cc, arr, 2);
			}
		}
		else if (game==2){
			printf("Player 2 input the column:\n");
			choice=getchoice();
			line=placechoice(choice-1, arr, 2);
			while (line==-1){
				printf("This column is full, choose another one:\n");
				choice=getchoice();
				line=placechoice(choice-1, arr, 2);
			}
		}
		printarray(arr);
		if (getwinner(arr, choice, line, 2)==0){
			printf("It\'s a tie!");
			break;
		}
		else if (getwinner(arr, choice, line, 2)==1){
			printf("Player 1 won!");
			break;
		}
		else if (getwinner(arr, choice, line, 2)==2){
			if (game==1){
				printf("Computer won!");
			}
			if (game==2){
				printf("Player 2 won!");
			}
			break;
		}
	}
	
	return 0;
}

int getchoice(){
	int choice;
	
	scanf("%d", &choice);
	
	return choice;
}

void printarray(char arr[7][7]){
	int i, j;
	
	for (i=0;i<7;i++){
		printf("\t");
		for (j=0;j<7;j++){
			printf(" %c ", arr[i][j]);
		}
		printf("\n");
	}
}

int placechoice(int choice, char arr[7][7], int p){
	int j;
	
	for (j=6;j>=0;j--){
		if (p==1){	
			if (arr[j][choice]=='-' && arr[j][choice]!='*'){
				arr[j][choice]='+';
				break;
			}
			else if (arr[j][choice]!='-' && arr[j][choice]!='*' && arr[j][choice]!='+'){
				return -1;
			}
		}
		else if (p==2){
			if (arr[j][choice]=='-' && arr[j][choice]!='+'){
				arr[j][choice]='*';
				break;
			}
			else if (arr[j][choice]!='-' && arr[j][choice]!='*' && arr[j][choice]!='+'){
				return -1;
			}
		}
	}
	
	return j;
}

void createarray(char arr[7][7]){
	int i, j;
	
	for (i=0;i<7;i++){
		for (j=0;j<7;j++){
			arr[i][j]='-';
		}
	}
}

int computerplays(char arr[7][7], int cline){
	int i, j, cc;
	
	cc=rand()%7;
	if (cline==-1){
		return cc;
	}
	for (j=6;j>=0;j--){
		for (i=0;i<4;i++){
			if (arr[j][i]=='*' && arr[j][i+1]=='*' && arr[j][i+2]=='*' && arr[j][i+3]=='-'){
				return i+3;
			}
			else if (arr[j][i]=='*' && arr[j][i+1]=='*' && arr[j][i+2]=='-' && arr[j][i+3]=='*'){
				return i+2;
			}
			else if (arr[j][i]=='*' && arr[j][i+1]=='-' && arr[j][i+2]=='*' && arr[j][i+3]=='*'){
				return i+1;
			}
			else if (arr[j][i]=='-' && arr[j][i+1]=='*' && arr[j][i+2]=='*' && arr[j][i+3]=='*'){
				return i;
			}
		}
		for (i=6;i>=3;i--){
			if (arr[i][j]=='*' && arr[i-1][j]=='*' && arr[i-2][j]=='*' && arr[i-3][j]=='-'){
				return j;
			}
		}
	}
	for (j=0;j<4;j++){
		for (i=0;i<4;i++){
			if (arr[j][i]=='*' && arr[j+1][i+1]=='*' && arr[j+2][i+2]=='*' && arr[j+3][i+3]=='-'){
				return i+3;
			}
			else if (arr[j][i]=='*' && arr[j+1][i+1]=='*' && arr[j+2][i+2]=='-' && arr[j+3][i+3]=='*'){
				return i+2;
			}
			else if (arr[j][i]=='*' && arr[j+1][i+1]=='-' && arr[j+2][i+2]=='*' && arr[j+3][i+3]=='*'){
				return i+1;
			}
			else if (arr[j][i]=='-' && arr[j+1][i+1]=='*' && arr[j+2][i+2]=='*' && arr[j+3][i+3]=='*'){
				return i;
			}
		}
		for (i=3;i<7;i++){
			if (arr[j][i]=='*' && arr[j+1][i-1]=='*' && arr[j+2][i-2]=='*' && arr[j+3][i-3]=='-'){
				return i+3;
			}
			else if (arr[j][i]=='*' && arr[j+1][i-1]=='*' && arr[j+2][i-2]=='-' && arr[j+3][i-3]=='*'){
				return i+2;
			}
			else if (arr[j][i]=='*' && arr[j+1][i-1]=='-' && arr[j+2][i-2]=='*' && arr[j+3][i-3]=='*'){
				return i+1;
			}
			else if (arr[j][i]=='-' && arr[j+1][i-1]=='*' && arr[j+2][i-2]=='*' && arr[j+3][i-3]=='*'){
				return i;
			}
		}
	}
	for (j=6;j>=0;j--){
		for (i=0;i<4;i++){
			if (arr[j][i]=='+' && arr[j][i+1]=='+' && arr[j][i+2]=='+' && arr[j][i+3]=='-'){
				if (arr[j+1][i+3]!='-'){
					return i+3;
				}
			}
			else if (arr[j][i]=='+' && arr[j][i+1]=='+' && arr[j][i+2]=='-' && arr[j][i+3]=='+'){
				if (arr[j+1][i+2]!='-'){
					return i+2;
				}
			}
			else if (arr[j][i]=='+' && arr[j][i+1]=='-' && arr[j][i+2]=='+' && arr[j][i+3]=='+'){
				if (arr[j+1][i+1]!='-'){
					return i+1;
				}
			}
			else if (arr[j][i]=='-' && arr[j][i+1]=='+' && arr[j][i+2]=='+' && arr[j][i+3]=='+'){
				if (arr[j+1][i]!='-'){
					return i;
				}
			}
		}
		for (i=6;i>=3;i--){
			if (arr[i][j]=='+' && arr[i-1][j]=='+' && arr[i-2][j]=='+' && arr[i-3][j]=='-'){
				return j;
			}
		}
	}
	for (j=0;j<4;j++){
		for (i=0;i<4;i++){
			if (arr[j][i]=='+' && arr[j+1][i+1]=='+' && arr[j+2][i+2]=='+' && arr[j+3][i+3]=='-'){
				if (arr[j+4][i+3]!='-'){
					return i+3;
				}
			}
			else if (arr[j][i]=='+' && arr[j+1][i+1]=='+' && arr[j+2][i+2]=='-' && arr[j+3][i+3]=='+'){
				if (arr[j+3][i+2]!='-'){
					return i+2;
				}
			}
			else if (arr[j][i]=='+' && arr[j+1][i+1]=='-' && arr[j+2][i+2]=='+' && arr[j+3][i+3]=='+'){
				if (arr[j+2][i+1]!='-'){
					return i+1;
				}
			}
			else if (arr[j][i]=='-' && arr[j+1][i+1]=='+' && arr[j+2][i+2]=='+' && arr[j+3][i+3]=='+'){
				if (arr[j+1][i]!='-'){
					return i;
				}
			}
		}
		for (i=3;i<4;i++){
			if (arr[j][i]=='+' && arr[j+1][i-1]=='+' && arr[j+2][i-2]=='+' && arr[j+3][i-3]=='-'){
				if (arr[j+4][i-3]!='-'){
					return i-3;
				}
			}
			else if (arr[j][i]=='+' && arr[j+1][i-1]=='+' && arr[j+2][i-2]=='-' && arr[j+3][i-3]=='+'){
				if (arr[j+3][i-2]!='-'){
					return i-2;
				}
			}
			else if (arr[j][i]=='+' && arr[j+1][i-1]=='-' && arr[j+2][i-2]=='+' && arr[j+3][i-3]=='+'){
				if (arr[j+2][i-1]!='-'){
					return i-1;
				}
			}
			else if (arr[j][i]=='-' && arr[j+1][i-1]=='+' && arr[j+2][i-2]=='+' && arr[j+3][i-3]=='+'){
				if (arr[j+1][i]!='-'){
					return i;
				}
			}
		}
	}
	for (j=6;j>=0;j--){
		for (i=0;i<4;i++){
			if (arr[j][i]=='*' && arr[j][i+1]=='*' && arr[j][i+2]=='-'){
				return i+2;
			}
			else if (arr[j][i]=='*' && arr[j][i+1]=='-' && arr[j][i+2]=='*'){
				return i+1;
			}
			else if (arr[j][i]=='-' && arr[j][i+1]=='*' && arr[j][i+2]=='*'){
				return i;
			}
		}
		for (i=6;i>=3;i--){
			if (arr[i][j]=='*' && arr[i-1][j]=='*' && arr[i-2][j]=='-'){
				return j;
			}
		}
	}
	
	
	return cc;
}

int getwinner(char arr[7][7],int choice, int line, int p){
	int i, j, c=0, k=0;

	choice=choice-1;
	line=line-1;
	if (p==1){
		for (j=6;j>=0;j--){
			for (i=0;i<7;i++){
				if (arr[j][i]=='+'){
					c++;
				}
				else if (arr[j][i]!='+'){
					c=0;
				}
				if (arr[i][j]=='+'){
					k++;
				}
				else if (arr[i][j]!='+'){
					k=0;
				}
				if (c==4 || k==4){
					return 1;	
				}
			}
			k=0;
			c=0;
		}
		for (i=0;i<7;i++){
			for (j=0;j<4;j++){
				if (arr[i][j]=='+' && arr[i+1][j+1]=='+' && arr[i+2][j+2]=='+' && arr[i+3][j+3]=='+'){
					return 1;
				}
			}
			for (j=3;j<7;j++){
				if (arr[i][j]=='+' && arr[i+1][j-1]=='+' && arr[i+2][j-2]=='+' && arr[i+3][j-3]=='+'){
					return 1;
				}
			}
		}
	}
	
	else if (p==2){
		for (j=6;j>=0;j--){
			for (i=0;i<7;i++){
				if (arr[j][i]=='*'){
					c++;
				}
				else if (arr[j][i]!='*'){
					c=0;
				}
				if (arr[i][j]=='*'){
					k++;
				}
				else if (arr[i][j]!='*'){
					k=0;
				}
				if (c==4 || k==4){
					return 2;	
				}
			}
			k=0;
			c=0;
		}
		for (i=0;i<7;i++){
			for (j=0;j<4;j++){
				if (arr[i][j]=='*' && arr[i+1][j+1]=='*' && arr[i+2][j+2]=='*' && arr[i+3][j+3]=='*'){
					return 2;
				}
			}
			for (j=3;j<7;j++){
				if (arr[i][j]=='*' && arr[i+1][j-1]=='*' && arr[i+2][j-2]=='*' && arr[i+3][j-3]=='*'){
					return 2;
				}
			}
		}
	}
	c=0;
	for (i=0;i<7;i++){
		for (j=0;j<7;j++){
			if (arr[i][j]!='-'){
				c++;
			}
		}
	}
	if (c==49){
		return 0;
	}
	
	return 3;
}
