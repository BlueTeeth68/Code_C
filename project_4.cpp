#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
int n;

struct em {
	int ID;
	char Name[50];
	float Sal; 
}; 

int xh[100];
em v[50];

char ans = 'l';

void edit(){
	printf ("\n===============================================================================================================================\n");
}


    //========================================================================================================================================================
void create (em v[],int &n) {
	FILE *f;
	n=0;
	char c[100];   
	int dem=1;           
	printf ("If you had done, press '*' to finish\n\n");                                   
	f = fopen("E:\\3020\\student name.txt", "w");                // mo file
	fprintf (f, "EmID\t\t%-20s\t\tEmsalaryLevel", "EmName");         // ghi text vao file roi xuong dong ( trong file)
	while ( strcmp(c, "CTRL_E") != 0){
        v[n].ID =dem; 
		printf ("EmName: ");fflush(stdin);
		gets (v[n].Name);
		if (strcmp(v[n].Name, "*") == 0){
			break;
		}
		printf ("EmsalaryLevel: ");
		fflush(stdin);
		gets(c);
		if (strcmp(c, "*") == 0){
			break;
		} else {
			v[n].Sal = atof(c);
		}
		if (v[n].Sal <0){
			while(v[n].Sal <0){
				printf ("\nSalary level must be a real number greater than 0!!!!!\n");
				printf ("Retype salary level: ");
		        scanf ("%f", &v[n].Sal);				
			}
		}
		fprintf (f, "\n%d\t\t%-20s\t\t%.1f", v[n].ID, v[n].Name, v[n].Sal);          // ghi vao file cac chuoi vua luu vao day roi xuong dong
		printf("\n\n");
		dem++;
		n++;
	}
	fclose (f);
	
}

void writefile(em v[], int n){                                                // ghi noi dung vao file
	FILE* f = fopen("E:\\3020\\student name.txt", "w");
	fprintf (f, "EmID\t\t%-20s\t\tEmsalaryLevel", "EmName"); 
	for (int i=0; i<n; i++){
	    fprintf (f, "\n%d\t\t%-20s\t\t%.1f", v[i].ID, v[i].Name, v[i].Sal);   
	}
	fclose(f);
}

void readfile(em v[], int &n){
    n=0;                                                // doc noi dung tu file
	char str[100];
	char c[100];
	FILE *f;
	f =fopen("E:\\3020\\student name.txt", "r");
	fgets(str, 100, f);
	while (fscanf(f, "%s",c)==1 && fscanf(f, "%s",v[n].Name)==1 && fscanf(f, "%s", str) ==1){
        v[n].ID = atoi(c);
		v[n].Sal = atof(str);
		n++;
	}
	fclose(f);
}

void showfile (){                                                           // in noi dung file ra man hinh
	char c;
	FILE* f = fopen("E:\\3020\\student name.txt", "r");
	if ( f == NULL ){
		printf ("The file E:\\3020\\student name.txt hasn't been created. \n");
	    fclose(f);
	}else {
	    while ( (c= fgetc(f)) != EOF){
	    	printf ("%c", c);
		}
	}
}
   
   //========================================================================================================================================================
   
   
void sonv(){                                                      // Dem so nhan vien
	FILE *f;
	int count =0;
	char str[100];
	f = fopen("E:\\3020\\student name.txt", "r");
	while (fgets(str, 100, f)!=NULL){
		count ++;
	}
	printf ("\nTotal of employee: %d", count-1);
	n= count -1;
	edit();
}

void maxsalary(em v[], int n){                                   // tim nhan vien co salary level cao nhat
    int count =0;
    readfile(v, n);
	float max = v[0].Sal;
	for (int i=1; i<n; i++){
		if ( max < v[i].Sal){
			max = v[i].Sal;
		}
	}
	for (int i=0; i<n; i++){
		if (v[i].Sal == max){
			xh[count] = i;
			count++;
		}
	}
	printf ("\nThe employee who has/have the highest salary level is/are: ");
	for (int i=0; i<count; i++){
		printf ("\nEmID:%d\t\tEmName:%s\t\tEmSalaryLevel:%.1f", v[xh[i]].ID,v[xh[i]].Name,v[xh[i]].Sal);
	}
		edit();
}

void samename(em v[], int n){
    readfile(v, n);
	int kt[100];
	int count =0;
	int dem;
	kt[0]=-1;
	printf ("\nYour file data: \n");
	showfile ();
	printf ("\n\nAll the ID of employee who have the same name: ");
	for ( int i=0; i<n-1; i++){
		dem=0;
		for (int k1=0; k1<= count; k1++){
			if (kt[k1]==i){
				dem ++;
			}
		}
		if (dem ==0){

		for ( int j=i; j<n; j++){

			if (strcmp(v[i].Name, v[j].Name)== 0){
				kt[count] = j;
				count++;
				dem ++;
			}
		    
		}
		if ( dem >1){
		    for (int k=count - dem; k<= count-1 ; k++){
		    	printf ("%d", v[kt[k]].ID);
		    	if (k< count-1 ){
		    		printf (",");
				}
				else printf ("; ");
			}	
		}
	}
	}
	edit();
}

void swapem(em &a,em &b)
{
	em t;
	t=a;
	a=b;
	b=t;	
}

void sort( em v[],  int n){                                         // sap xep theo thu tu tang dan luong, thay doi luu trong file
	readfile(v, n);
	for (int i=0; i<n; i++){
		for (int j=n-1; j>i; j--){
			if (v[j].Sal < v[j-1].Sal){
				swapem(v[j],v[j-1]);
			}
		}
	}
	printf ("\nYour file after sorting: \n");
	printf ("EmID\t\t%-20s\t\tEmsalaryLevel", "EmName");
	for (int i=0; i<n; i++){
		printf ("\n%d\t\t%-20s\t\t%.1f", v[i].ID, v[i].Name, v[i].Sal); 
	}
	edit();
}
 
void add(em v[], int &n){                           // them 1 phan tu vao cuoi file
 	FILE* f;
	readfile(v, n);
 	em a;
	printf ("Enter employee's ID: ");	fflush(stdin);
	scanf ("%d", &a.ID);
	if (a.ID <=0){
		while (a.ID<=0){
			printf ("\nID must be an integer number greater than 0!!!!!\n");
			printf ("Retype ID: ");
			scanf ("%d", &a.ID);
		}
	}
	fflush(stdin);
	printf ("Enter employee's name: " );	fflush(stdin);
	gets(a.Name);
	fflush(stdin);
	printf ("Enter employee's salary level: ");fflush(stdin);
	scanf ("%f", &a.Sal);
	if (a.Sal <0){
		while(a.Sal <0){
			printf ("\nSalary level must be a real number greater than 0!!!!!\n");
			printf ("Retype salary level: ");
	        scanf ("%f", &a.Sal);				
		}
	}
    if (a.ID>= v[n-1].ID ){
    	n++;
    	v[n-1] = a;
    	f =fopen ("E:\\3020\\student name.txt", "a");
    	fprintf (f, "\n%d\t\t%-20s\t\t%.1f",v[n-1].ID, v[n-1].Name, v[n-1].Sal );
    	fclose(f);
	}
	if (a.ID>0 && a.ID < v[n-1].ID){

		int dem=0;
		for ( int i=0; i<n && v[i].ID < a.ID; i++){
			dem++;
		}
		n++;
		for (int i=n-1; i> dem; i--){
			v[i]=v[i-1];
		}
		v[dem] = a;
		for ( int i=dem; i<n ;i++){
			if ( v[i].ID == v[i-1].ID)
			v[i].ID ++;
		}
        writefile(v,n);
		}
    printf ("\nThe employee has been added.");
    printf ("\nYour file:\n");
    showfile();
	edit();                                             // dang test
}

void find (em v[], int n){
	FILE* f;
	int choose=0;
	int count =0;
	readfile(v, n);
	printf ("\nDo you prefer to find by ID or Name?\nPress 1 to find by ID\nPress 2 to find by Name.\nYour choose: "); fflush (stdin);
	scanf ("%d", &choose);
	if (choose!=1 && choose!=2){
		while(choose!=1 && choose!=2){
			printf ("\nRetype a legal Option:\n");
			printf ("     Press 1 if you want to find by ID.");
			printf ("\n     Press 2 if you want to find by Name.\n");
			printf ("Retype your option: ");
			scanf ("%d", &choose);
		}
	}
	if ( choose ==1){
		int fID;
		printf ("\nFind by ID.\n\n");
		printf ("Enter ID you want to find: ");
		fflush (stdin);
		scanf("%d", &fID);
		for ( int i=0; i<n; i++){
			if (v[i].ID == fID){
				count ++;
				printf ("\n%d\t\t%s\t\t%.1f", v[i].ID, v[i].Name,v[i].Sal);
			}
		}
		if (count ==0){
			printf ("ID doesn't exist in your file.");
		}
	}
	if (choose ==2){
		char fName[50];
		printf ("\nFind by Name.\n\n");
		printf ("Enter name of employee you want to find: ");
		fflush (stdin);
		gets (fName);
		for ( int i=0; i<n; i++){
			if (strcmp(fName, v[i].Name) == 0){
				count ++;
				printf ("\n%d\t\t%s\t\t%.1f", v[i].ID, v[i].Name,v[i].Sal);
			}
		}
		if (count ==0){
			printf ("Name doesn't exist in your file.");
		}
	}
	edit();
}

void del(em v[], int &n)
{
	int count =0;
	int x;
	readfile(v, n);
	printf("Input ID: ");
	scanf ("%d", &x);
	for (int i=1; i<=n; i++)
	{
		if (x == v[i].ID )
		{
			for (int j=i; j<=n; j++)
			{
				v[j]=v[j+1];
			}
			count++;
			n--;
			printf("\n\nYour new list: \n");
			writefile(v,n);
			showfile();
		}
	}
	
	if (count==0)
	{
		printf("Employee not found!");
	}
	edit();
}

void menu(){
 	printf ("\n                                                  ***MENU***");
 	printf ("\n                                **********************************************");
 	printf ("\n                                *  1. CREATE                                 *");
 	printf ("\n                                *  2. ADD                                    *");
	printf ("\n                                *  3. DELETE                                 *");
	printf ("\n                                *  4. FIND                                   *");
 	printf ("\n                                *  5. SORT                                   *");
	printf ("\n                                *  6. STATISTIC                              *");
	printf ("\n                                *  7. EXIT.                                  *");
	printf ("\n                                **********************************************");
 }	

void menu2(){
 	printf ("\n                                                ***STATICTIS***");
 	printf ("\n                                **********************************************");
 	printf ("\n                                *  1. TOTAL OF EMPLOYEE                      *");
	printf ("\n                                *  2. SAME NAME                              *");
	printf ("\n                                *  3. MAX SALARY LEVEl                       *");
 	printf ("\n                                *  4. MENU                                   *");
	printf ("\n                                **********************************************");
	
}


void check(int *c){
	while(*c <=0 || *c >7){
		printf("ERROR!!!\nPlease retype an legal number (1 <= n <= 7): "); scanf("%d", c);
		printf("\n");
	}
}

void check1(int *c){
	while(*c <=0 || *c >4){
		printf("ERROR!!!\nPlease retype an legal number (1 <= n <= 4): "); scanf("%d", c);
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

void statistic(){
	int ch;
	menu2();
	
	do{
	if ( ans!= 'Y' && ans != 'y' )
	{
	printf("\nEnter your choose: "); scanf("%d", &ch);
	check1(&ch);
	printf("\n");
	}
	
	if (ch == 1){
		sonv();
		menu2();
	}
	if (ch == 2){
		samename(v,n);
		menu2();
	}
	if(ch == 3){
		maxsalary(v, n);
		menu2();
	}
	if(ch == 4){
		ans = 'l';
		printf("\n\n\n");
		ch=5;
		menu();
	}
}
while(1<= ch && ch <=4);    
}


int main(){
	FILE *f;
	n=0;
	char str[100];
	f = fopen("E:\\3020\\student name.txt", "r");
	while (fgets(str, 100, f)!=NULL){
		n++;
	}
	n= n-1;
	fclose(f);
    int choose;

	menu();
	f = fopen("E:\\3020\\student name.txt", "r");
	if ( f == NULL || n<=0){
		while(f == NULL || n<=0){
		printf ("\a\nYour file hasn't exist or it doesn't have data.\nYou must input data into your file first.\n");
		create(v, n);
	}
		printf ("\nYour file has been created.");
		edit();
	}
	
 	do{
	if ( ans!= 'Y' && ans != 'y' )
	{
	printf("\nEnter your choose: "); scanf("%d", &choose);
	check(&choose);
	printf("\n");
	}
	if (choose ==1){
		create(v, n);
		printf ("\nYour file has been created.");
		edit();
		printf ("\n\n\n");
		menu();
	}
	if (choose == 2){
		add(v,n);
		ask();
	}
	if (choose == 3){
		del(v,n);
		ask();
	}
	if(choose == 4){
		find(v,n);
		ask();
	}
	if (choose == 5){
		sort(v,n);
		ask();
	}
	if (choose == 6){
		statistic();
	}
	
	if(choose == 7){
		exit(0);
	}
}
while(1<= choose && choose <=7);    
    getch();
}

