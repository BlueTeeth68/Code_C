#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

float a[100];
int n;
char ans = 'l';

void edit(){
	printf ("\n===============================================================================================================================\n");
}


void input(int n){
	for (int i=0; i<n; i++){
		printf ("a[%d] = ", i);	
		scanf("%f", &a[i]);
		if (a[i]<0 || a[i] >10){
			while(a[i]<0 || a[i] >10){
				printf ("\nInvalid mark!!!\nRetype a legal mark (0 <= mark <= 10): \na[%d] = ", i);
				scanf ("%f", &a[i]);
			}
		}
	}
}

void output( int n){
	printf ("\nYour mark table is: \n");
	for ( int i=0; i<n; i++){
		printf ("\na[%d] = %.2f",i, a[i]);
	}
	printf ("\n");
	edit();
}

void Max(float a[], int n){
	float max = a[0];
	for (int i=0; i<n; i++){
		if (max < a[i]){
			max = a[i];
		}
	}
	printf ("\nMaximum mark is: %.2f", max);
	edit();
}

void ave(float a[], int n){
	float tb, sum=0;
	for (int i=0; i<n; i++){
		sum+=a[i];
	}
	tb = float(sum)/n;
	printf ("\nThe average marks: %f", tb);
	printf ("\nThe marks that satisfy the requirement is/are: ");
	for (int i=0; i<n; i++){
		if (a[i] >= tb){
			printf ("%.2f\t", a[i]);
		}
	}
	edit();
}

void add(float a[], int &n){
	printf ("\nADD:\n\n");
	int p;
	float v;
	printf("\nEnter the position that you want to add: ");
	scanf("%d", &p);
	if (p<0 || p>n){
		while(p<0 || p>n){
			printf ("\nERROR!!!\nPlease retype a legal position from your keyboard (0 <= p <= %d): ", n);
			scanf("%d", &p);
		}
	}
	printf ("\nEnter the mark that you want to add: ");
	scanf("%f", &v);
	n++;
	for (int i=n-1; i>p; i--){
		a[i]=a[i-1];
	}
	a[p]= v;
	output(n);
}

void del(float a[], int &n){
	printf ("\nDELETE:\n\n");
	int p;
	printf("\nEnter the position that you want to delete: ");
	scanf("%d", &p);
	if (p<0 || p>=n){
		while(p<0 || p>=n){
			printf ("\nERROR!!!\nPlease retype a legal position from your keyboard (0 <= p <= %d): ", n-1);
			scanf("%d", &p);
		}
	}
	for (int i=p; i<n-1; i++){
		a[i]=a[i+1];
	}
	n--;
                                
	output(n);
} 

void sort(float a[], int n){
	for (int i=0; i<n; i++){
		for (int j=n-1; j>i; j--){
			if (a[j] < a[j-1]){
				float tg=a[j];
				a[j] = a[j-1];
				a[j-1] = tg;
			}
		}
	}
	output(n);
}

void compare(float a[], int n){
	float x,y;
	int count =0;
	printf ("\nEnter two float number a,b (a<b): ");
	scanf ("%f %f", &x,&y);
	if (x >= y){
		while(x>=y){
			printf ("\nRetype legal float number (a < b)");
			scanf ("%f %f", &x, &y);
		}
	}
	printf ("\nThe marks that satisfy the requirement a <= mark <= b is/are:  ");
	for ( int i=0; i<n; i++){
		
		if (a[i] >= x && a[i] <= y){
			printf ("%.2f  ", a[i]);
			count ++;
		}
	}
	if (count == 0){
		printf ("There is no mark in the table satisfy the requirement!");
	}
	edit();
}

void menu(){
 	printf ("\n                                             ***MENU***");
 	printf ("\n                                ************************************");
 	printf ("\n                                *  1. SHOW.                        *");
	printf ("\n                                *  2. MAX.                         *");
	printf ("\n                                *  3. MARKS >= AVE.                *");
 	printf ("\n                                *  4. ADD.                         *");
	printf ("\n                                *  5. DELETE.                      *");
	printf ("\n                                *  6. SORT.                        *");
	printf ("\n                                *  7. SHOW a <= MARKS <= b .       *");
	printf ("\n                                *  8. HELP.                        *");
	printf ("\n                                *  9. EXIT.                        *");
	printf ("\n                                ************************************");
 }
 
 void check(int *c){
	while(*c <=0 || *c >9){
		printf("ERROR!!!\nPlease retype an legal number (1 <= n <= 9): "); scanf("%d", c);
		printf("\n");
	}
}

void ask(){

	printf("\nDo you want to continue? (Y/N):  ");	fflush(stdin); scanf("%c", &ans);
		if(ans=='Y'||ans=='y'){
		      
		}
		else if(ans=='N'||ans=='n'){
			printf("\n\n\n");
			menu();
			
	}else {
			printf ("\nERROR!!!\nPlease retype a legal option:\n      Press Y/y if you want to continue this option.\n      Press N/n if you want to return to menu.\n\n");
			ask();
		}
}

int main(){
 	int choose;
 	printf("Fisrt, you must create a marks table. \n");
	printf("\nEnter the number of marks in the table: ");
	scanf("%d", &n);
	printf ("\nEnter marks of your table (0<= mark <=10): \n");
 	input(n);
	menu();
	
 	do{
	if ( ans!= 'Y' && ans != 'y' )
	{
	printf("\nEnter your choose: "); scanf("%d", &choose);
	check(&choose);
	printf("\n");
	}
	
	if (choose == 1){
		output(n);
		ask();
	}
	if (choose == 2){
		Max(a,n);
		ask();
	}
	if(choose == 3){
		ave(a,n);
		ask();
	}
	if (choose == 4){
		add(a,n);
		ask();
	}
	if (choose == 5){
		del(a,n);
		ask();
	}
	if (choose == 6){
		sort(a,n);
		ask();
	}
	if (choose == 7){
		compare(a,n);
		ask();
	}
	if (choose ==8){
		printf ("\nHELP:\n\n");
		printf ("This simple program helps you to create and manage a mark table with these option:\n");
		printf ("1. Show your mark table into screen after creating.\n");
		printf ("2. Find the maximum mark in the table.\n");
		printf ("3. Show the average into screen and find all marks that greater than or equal to average.\n");
		printf ("4. Add a mark into your table.\n");
		printf ("5. Delete a mark from your table.\n");
		printf ("6. Sort the table (ascending order).\n");
		printf ("7. Input 2 float numbers a and b (a<b) and show marks that are greater than or equal to a and\nless than or equal to b.\n");
		edit();
	    ask();	
	}
	if(choose == 9){
		exit(0);
	}
}
while(1<= choose && choose <=9);    
  getch();
 }
