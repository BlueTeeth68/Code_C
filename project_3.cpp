#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

typedef struct student {
	char ID[20];
	char Name[30];
	float GPA;
};
int ktr=0;
char ch[100];
float checkGPA;
char choose[100];
char ans ='h';

student a[100], b[100];
int n=0, m;

void edit(){
	printf ("\n===============================================================================================================================\n");
}

void ktGPA(char c[] ){                                        // Ep nguoi dung nhap so thuc 
    int l = strlen(c) - 1;
    int count =0;
    int dem = 0;                                   // bien dem so so khong co trong chuoi, neu bang chieu dai chuoi thi n=0 => nhap lai
	for(int i=0; i<l ; i++){
    	int x = c[i];
    	if (x<48 || x >57){
    		count ++;
		}
		if(c[i] == '.'){
			dem ++;
		}
	}
	    if (count > 0 || dem >1){
   		printf ("\nERROR!!!\nInput a float number that is greater than 0 and less than 10!!!! \n   Retype GPA:  ");
   		fgets(c, sizeof(c), stdin);
   		fflush(stdin);
   		ktGPA (c);
}
    
}


void InputOneStd(student &p){
	char c[100];
	printf ("\nEnter Student's ID: ");
	fflush(stdin);
	gets(p.ID);
	printf ("Enter student's Name:");
	fflush(stdin);
	gets(p.Name);
	printf ("Enter Student's GPA: ");    /* chi duoc nhap so thuc, khong duoc nhap ki tu. Y tuong: dung 1 string de kiem tra day nhap vao co phai so thuc 
                                     	khong (chi chua cac ki tu tu 0-> 9 va chi co nhieu nhat 1 dau ".") bang cach dung 2 bien dem.
                                     									 	sau do chuyen tu string sang float bang ham atof(string) */
	fgets(c, sizeof(c), stdin);
	ktGPA(c);
	p.GPA = atof(c);
	
}


void checkInput(student p[], int i){
	for (int j=0; j<=i; j++){
			int count =0;
			if (i==0 && j==0){
				if (p[i].GPA>10 || p[i].GPA <0){
				printf ("\nGPA must be between [0,10].");
				count ++;
			}
			if (count >0){
				printf ("\nRetype information for this student: \n");
					InputOneStd(p[i]);
					checkInput(p,i);
			}
			}else if (i>j){
			if (strcmp(p[j].ID, p[i].ID) == 0){
				printf ("\nThis ID has already existed in your list.");
				count ++;
			}
			if (p[i].GPA>10 || p[i].GPA <0){
				printf ("\nGPA must be between [0,10].");
				count ++;
			}
			if (count >0){
				printf ("\nRetype information for this student: \n\n");
					InputOneStd(p[i]);
					checkInput(p,i);
			}
		}
		}
}
void InputStd (student p[], int &n){
	for ( int i=0; i<n; i++){
		InputOneStd(p[i]);
		checkInput(p,i);
	}
}

void OutputOneStd(student p){
	printf ("\nStudent's ID: %s", p.ID);
	printf ("\nStudent's Name: %s", p.Name); 
	printf ("\nStdent's GPA: %.2f\n", p.GPA);
}

void OutputStd(student p[], int m){
	for (int i=0; i<n; i++){
		OutputOneStd(p[i]);
	}
	edit();
}

void dg(student x){
	printf ("\nEvaluate: ");
	if (x.GPA >=8 && x.GPA <=10){
		printf ("Very Good!!!");
	}
	else if (x.GPA >=7 && x.GPA <8){
		printf ("Good!!");
	}else if (x.GPA >=6 && x.GPA <7){
		printf ("Above Average!");
	}else if (x.GPA >=5 && x.GPA <6){
		printf ("Average.");
	}
	else printf ("Weak.");
	printf ("\n");
}

void find(student p[], int n){
	int kt;
	printf ("\nDo you prefer to find students following ID or Name?  ");
	printf ("\nPress:\n1: Find following ID.\n2: Find following Name.");
	printf ("\nEnter your choose: ");
	scanf ("%d", &kt);
	if (kt!=1 && kt!=2){
		while(kt!=1 && kt!=2){
			printf ("\nRetype a legal Option:\n");
			printf ("     Press 1 if you want to find by ID.");
			printf ("\n     Press 2 if you want to find by Name.\n");
			printf ("Retype your option: ");
			scanf ("%d", &kt);
		}
	}
	if (kt == 1){
		char fID[20];
		int count =0;
		printf ("\n\nEnter student's ID: ");
		fflush(stdin);
		gets (fID);
		for (int i=0; i<n; i++){
			if (strcmp(p[i].ID,fID) == 0){
				count++;
				printf ("\n");
				OutputOneStd(p[i]);
				dg(p[i]);
			}
		}
		if(count ==0){
			printf ("This ID is not exist in your list.\nPlease check again.");
		}
	}
	if (kt == 2){
		char fName[30];
		int count =0;
		printf ("\n\nEnter student's Name: ");
		fflush(stdin);
		gets(fName);
		for (int i=0; i<n;i++){
			if (strcmp(p[i].Name,fName) == 0){
				count++;
				printf ("\n");
				OutputOneStd(p[i]);
				dg(p[i]);
			}
		}
		if(count ==0){
			printf ("This name is not exist in your list.\nPlease check again.");
		}
	}
	edit();
}

void swap(student &x, student &y){
	student tg= x;
	x = y;
	y = tg;
}

void sort (student p[], int &n){
	for (int i=0; i<n; i++){
		for (int j=n-1; j>i; j--){
			if (p[j].GPA<p[j-1].GPA){
				swap (p[j], p[j-1]);
			}
		}
	}
	printf ("The list after sort: \n");
	OutputStd(p, n);
}

void topGPA(student p[], int &n){
	if(n>=3){
	for ( int i=0; i<n; i++){
		for (int j=n-1; j>i; j--){
			if (p[j].GPA<p[j-1].GPA){
				swap (p[j], p[j-1]);
			}
		}
	
	}
	printf ("\nTop 3 student who have highest GPA: ");
		for (int i=1;i<4; i++ ){
			OutputOneStd(p[n-i]);
			printf ("\n");
		}
	}else {
		printf ("Your list doesn't have enough student to use this function!");
	}
	edit();
}

void copy(student x[], student y[], int &m, int &n){
	m=n;
	for (int i=0; i<n;i++){
		strcpy(x[i].ID,y[i].ID);;
		strcpy(x[i].Name, y[i].Name);
		x[i].GPA = y[i].GPA;
	}
}


void menu(){
 	printf ("\n                                                  ***MENU***");
 	printf ("\n                                **********************************************");
 	printf ("\n                                *  1. CREATE NEW LIST.                       *");
	printf ("\n                                *  2. FIND AND EVALUATE.                     *");
	printf ("\n                                *  3. SORT.                                  *");
 	printf ("\n                                *  4. SHOW TOP 3.                            *");
	printf ("\n                                *  5. HELP.                                  *");
	printf ("\n                                *  6. EXIT.                                  *");
	printf ("\n                                **********************************************");
 }
 
 void check(char a[]){
	while(strcmp(a, "1")!=0 && strcmp(a,"2")!=0 && strcmp(a, "3") != 0 && strcmp(a, "4")!=0 && strcmp(a, "5")!=0 && strcmp(a, "6") != 0){
		printf("ERROR!!!\nPlease retype an legal option (1 <= n <= 6): "); gets(a);
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

void ktn(char c[] ){                                        // Ep nguoi dung nhap so tu nhien
    int l = strlen(c) - 1;
    int count =0;
    int dem0 = 0;                                   // bien dem so so khong co trong chuoi, neu bang chieu dai chuoi thi n=0 => nhap lai
	for(int i=0; i<l ; i++){
    	int x = c[i];
    	if (x<48 || x >57){
    		count ++;
		}
		if(c[i] == '0'){
			dem0 ++;
		}
	}
	    if (count > 0 || dem0 == l){
   		printf ("\nERROR!!!\nInput an integer number that is greater than 0!!!! \n   Retype the number of student:  ");
   		fgets(c, sizeof(c), stdin);
   		fflush(stdin);
   		ktn (c);
}
    
}

int main(){
  	
	menu();
	int count =0;
	do{
	if ( ans!= 'Y' && ans != 'y' )
	{
	printf("\nEnter your choose: ");
	fflush(stdin); gets(choose);
	check(choose);
	printf("\n");
	}
	if (n==0 ){
	if(strcmp(choose, "2") ==0 || strcmp(choose, "3") ==0 || strcmp(choose, "4")==0){
	printf("\nWe realize that you have not had a student list.\nFist you must create a student list.\n");
    printf("\nEnter the number of student in the list: "); fflush(stdin);
	fgets(ch, sizeof(ch), stdin);   /*Khong cho nhap chuoi ki tu hoac so thap phan vao ban phim*/ 
	ktn(ch);
	n = atoi(ch);
	InputStd(a, n);
	printf ("\n\n\n");
	menu();
	count++;
	}

	}
	if(count ==0){
	if (strcmp(choose,"1")==0){
		char tl ;
		printf ("\nIf you create new list, all data in your latest table will be deleted.\nDo you want to create new list? (Y/N):"); fflush(stdin); scanf ("%c", &tl);
		
		 if (tl !='n' && tl!= 'N' && tl!='y' && tl!='Y'){
			while(tl !='n'&& tl!= 'N'&& tl!='y'&&tl!='Y'){
			printf ("\nERROR!!!\nPlease retype a legal option:\n     Press Y/y to start create\n     Press N/n to return menu\n");
			printf ("Enter your choose: ");
			fflush(stdin);
			scanf ("%c", &tl);
		}
	}
		if (tl == 'N' || tl =='n'){
			menu(); 
			tl = 'y';
		}else if (tl =='Y' || tl == 'y'){
			printf ("\nEnter the number of student in the table: ");
		     fflush(stdin);
	         fgets(ch, sizeof(ch), stdin);   /*Khong cho nhap chuoi ki tu hoac so thap phan vao ban phim*/ 
	         ktn(ch);
	         n = atoi(ch);
		InputStd(a,n);
		printf ("\n\nYour list student: \n");
		OutputStd(a,n);
		printf ("\n\n\n");
		menu();
		}
	}
	if (strcmp(choose, "2")==0){
		find(a, n);
		ask();
	}
	if(strcmp(choose, "3")==0){
		sort(a,n);
		ask();
	}
	if (strcmp(choose, "4")==0){
		topGPA(a,n);
		ask();
	}
	
	if (strcmp(choose, "5")==0){
		printf ("About this program:\n");
		printf ("\nThis is a simple program that help you do some actions on a student list that you input.");
		printf ("\n1.Create a new student list.");
		printf ("\n2.Find student following name or ID and show a linguistic term about that student.");
		printf ("\n3.Sort the list following GPA in ascending order.");
		printf ("\n4.Show top 3 student who have highest GPA if the list have at least 3 student.\n");
		edit();
		ask();
	}
	if (strcmp(choose, "6")==0){
		exit(0);
	} 
	}
}
    while(strcmp(choose, "1")>=0 && strcmp(choose, "6") <= 0);  
    getch();  
}
