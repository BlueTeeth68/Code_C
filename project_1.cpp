#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


int a[100], b[100],m,n;

void gan(int a[], int b[], int &n, int &m){
	m=n;
	for (int i=0; i <n; i++){
		b[i]=a[i];
	}
}

void edit(){
	printf ("===============================================================================================================================\n");
}

void input(int n){
	for (int i=0; i<n; i++){
		printf ("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

void output( int n){
	printf ("\nThe array after modifying is: \n");
	for ( int i=0; i<n; i++){
		printf ("a[%d] = %d\n",i, a[i]);
	}
	edit();
}

void find (int a[], int n){
	printf ("\nFIND:\n\n");
	int v, dem=0;
	printf("Please enter the value that you want to find: ");
	scanf("%d", &v);
	for (int i=0; i<n; i++){
		if(a[i] == v){
			dem++;
		}
	}
	if(dem==0){
		printf ("\nThe array doesn't have any element that has value %d.", v);
	}else {
		printf("\nThe position in array has value %d is/are: ", v);
		for (int i=0; i<n; i++){
		if(a[i] == v){
			printf("%5d", i);
		}
	}
	}
	printf ("\n");
	edit();
}

void add(int a[], int &n){
	gan(a,b,n,m);
	printf ("\nADD:\n\n");
	int p, v;
	printf("\nEnter the position that you want to add: ");
	scanf("%d", &p);
	if (p<0 || p>n){
		while(p<0 || p>n){
			printf ("\nERROR!!!\nPlease retype a legal position from your keyboard (0 <= p <= %d): ", n);
			scanf("%d", &p);
		}
	}
	printf ("\nEnter the value that you want to add: ");
	scanf("%d", &v);
	n++;
	for (int i=n-1; i>p; i--){
		a[i]=a[i-1];
	}
	a[p]= v;
	output(n);
}

void Delete(int a[], int &n){
	gan(a,b,n,m);
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

 void menu(){
 	printf ("\n                                             ***MENU***");
 	printf ("\n                                ************************************");
 	printf ("\n                                *  1. FIND.                        *");
	printf ("\n                                *  2. ADD.                         *");
	printf ("\n                                *  3. DELETE.                      *");
 	printf ("\n                                *  4. EXIT.                        *");
	printf ("\n                                *  5. HELP.                        *");
	printf ("\n                                *  6. RESTORE.                     *");
	printf ("\n                                ************************************");
 }
 
 void check(int *c){
	while(*c <=0 || *c >6){
		printf("ERROR!!!\nPlease retype an legal number (1 <= n <= 6): "); scanf("%d", c);
		printf("\n");
	}
}
 
void ask(){
	char ans;
	printf("\nDo you want to continue? (Y/N):  ");	fflush(stdin); scanf("%c", &ans);
		if(ans=='Y'||ans=='y'){
		printf("\n\n\n");
		menu();
	}else if(ans=='N'||ans=='n'){
			exit(0);
		}else {
			printf ("\nERROR!!!\nPlease retype a legal option:\n      Press Y/y if you want to continue.\n      Press N/n if you want to exit the program.\n\n");
			ask();
		}
}
 
 
int main(){
 	int choose;
 	printf ("                                          ONE-DIMENSIONAL ARRAY MODIFYING PROGRAM\n\n\n");
 	printf("Fisrt, you must create a new array. \n");
	printf("\nEnter the number of element in the array: ");
	scanf("%d", &n);
 	input(n);
 	gan (a,b,n,m);
	menu();
	
 	do{
	printf("\nEnter your choose: "); scanf("%d", &choose);
	check(&choose);
	printf("\n");
	if (choose == 1){
		find(a,n);
		ask();
	}
	if (choose == 2){
		add(a,n);
		ask();
	}
	if(choose == 3){
		Delete(a,n);
		ask();
	}
	if (choose == 4){
		exit(0);
	}
	if (choose ==5){
		printf ("\nHELP:\n\n");
		printf ("  This is a simple program help you to modify an available one-dimension array\n");
		printf ("with three operations:\n");
		printf ("  1. FIND: find and show on the screen all the positions in the array that have\nvalue you want to find.\n");
		printf ("  2. ADD: add a value into a position (from 0) of the array and show the new \narray on the screen.\n");
		printf ("  3. DELETE: delete a value at a position (from 0) of the array amd show the new\narray on the screen.\n");
		printf ("  4. EXIT: exit the program.\n");
		printf ("  6. RESTORE: return to the value of array at the latest changes.\n");
		printf ("  Press a number from 1 to 5 to choose your option from menu.\n");
		edit();
	    ask();	
	}
	if(choose == 6){
		gan(b,a,m,n);
		printf ("The array after restore:\n");
		for ( int i=0; i<n; i++){
		printf ("a[%d] = %d\n",i, a[i]);
	}
	edit();
	ask();
	}
}
while(1<= choose && choose <=6);    
  getch();
 }
