#include <iostream>
#include<string>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//*******************Account management********************
typedef struct Account{
	
	int numbers;
	float amounts;
	string kinds;
}account;

int EnterSize(){
	int size;
	cout<<"\n\n\t\t\t\t\t\t =====ENTER SIZE OF M BANK =====\n";
	do
	{
		cout<<"\n\n\t\t\t\t Enter the number of account  you want to creat : ";
	   	cin>>size;
	}
	while( size<0);
	return size;
}
int EnterNumber(){
	int number;
	do
	{
		cout<<"\n\t\t\t\tEnter account number (4 digits) : ";
		cin>>number;
	}
	while( number < 1000 || number > 9999);
	return number;
			
}	
float EnterAmount(){
	int deposit;
	
	cout<<"\t\t\t\tEnter amount you want to deposit : ";
	cin>>deposit;
	return deposit;
}	
string EnterKind(){
	string kind;
	do{
		cout<<"\t\t\t\tWhich type you want to open (current or saving) : ";
		cin>> kind;
	}while(kind!="current" && kind!="saving");
	
	return kind;
}

//*******************function to creates Account management*******************
account CreateAccount(){
	account open;
	
	open.numbers = EnterNumber();
	open.amounts = EnterAmount();
	open.kinds   = EnterKind();
	return open;
}

void displaySimplCreateAccount( account show){
	cout<<"\t\t\t\t\tAccount No      : " <<show.numbers<<endl; cout<<"\t\t\t\t\tAccount Kind    : " <<show.kinds<<endl; cout<<"\t\t\t\t\tAccount balance : " <<show.amounts<<endl;
}
void displayCreateAccount( account show){
	cout<<"\t"<<show.numbers<<"\t\t\t"<<show.kinds<<"\t\t"<<show.amounts<<endl;
}
void CreateNumberAccount( account tab[], int size ){
	
	for( int i=0; i<=(size-1); i++)
	{
	cout<<"\n\n\t\t\t\t\t\t=====CREATE ACCOUNT No " << i+1 << "===== \n";
		tab[i] = CreateAccount();
	}
}
void displayCreateNumberAccount( account tab[], int size ){
	cout<<"\n\n\n\n\n\n\t\t\t\t\t\tDetail of Created account(s) ";
	cout<<"\n\n\t\t\t\t=========================================================\n";
	cout<<"\t\t\t\tNo.\tAccount no\t\tType\t\tBalance\n";
	cout<<"\t\t\t\t=========================================================\n";
	for( int i=0; i<=(size-1); i++)
	{
		cout<<"\n";
		cout<<"\t\t\t\t"<<i+1;
		displayCreateAccount(tab[i]);
	}
}
void SumOfmAccount( account tab[], int size ){
	int sum = 0;
	for( int i=0; i<=(size-1); i++)
	{
		sum += tab[i].amounts;
	}
	cout<<"\t\t\t\tThe sum of " << size << " account(s) : " << sum <<endl;	
}

//*******************Modify the amount of a selected account*******************	
void modifyCreateNumberAccount( account tab[], int size){
	int number;
	cout<<"\n\n\n\t\t\t\tEnter account No number : ";
	cin>> number;	
	for( int i=0; i<=(size-1); i++)
	{
		if( tab[i].numbers==number)
		{
			displayCreateNumberAccount( tab,1 ); //afficher account trouver
			cout<<"\n\n\t\t\t\t\t\t=====Modify amount=====\n\n";
			tab[i].amounts = EnterAmount(); // modifier  montant
		}
	}
	
}
void displaymodifyNumberCreateAccount( account tab[], int size ){
	cout<<"\t\t\t\t Account(s) deatail after modifying "<<endl;
	
	cout<<"\n\n\t\t\t\t=========================================================\n";
	cout<<"\t\t\t\tNo.\tAccount no\t\tType\t\tBalance\n";
	cout<<"\t\t\t\t=========================================================\n";
	
	for( int i=0; i<=(size-1); i++)
	{
	
//	cout<<"Detail of account No " << i+1;
		cout<<"\n";
		cout<<"\t\t\t\t"<<i+1;
		displayCreateAccount(tab[i]);
		cout<<"\n";
	}
	
}

float CreateNegAmount(){
	
	float amount;
	do
	{
		cout<<"Enter negative amount : " ;
		cin>>amount;
	}while( amount > 0 );
	return amount;
}
void displayNegative( account tab[], int size ){	
	cout<<"\n\n\n\n\n\n\t\t\t\t\t Account(s) deatail with negative amount "<<endl;
	
	cout<<"\n\n\t\t\t\t=========================================================\n";
	cout<<"\t\t\t\tNo.\tAccount no\t\tType\t\tBalance\n";
	cout<<"\t\t\t\t=========================================================\n";
	
	for( int i=0; i<=(size-1); i++)
	{
		if(tab[i].amounts<0)
		{
		cout<<"\t\t\t\t"<<i+1;
		displayCreateAccount(tab[i]);
		} else cout<<"\n\n\t\t\t\t No negative amount"; break;
	}
}

//********************Client management********************
typedef struct Date{
	int Day;
	int Month;
	int Year;
}date;
int EnterDay(){
	int d;
	do{
		cout<<"\t\t\t\t Enter a day between 1 and 31    : ";
		cin>>d;
	}while(d<0 || d>31);
		
	return d;
}
int EnterMonth(){
	int m;
	do{
		cout<<"\t\t\t\t Enter a month between 1 and 12  : ";
		cin>>m;
	}while(m<0 || m>12);
		
	return m;
}
int EnterYear(){
	int y;
	do{
		cout<<"\t\t\t\t Enter a year greater than 1950  : ";
		cin>>y;
	}while(y<1950 || y>2021);
	return y;
}
date CreateDate(){
	date create;
	create.Day   = EnterDay();
	create.Month = EnterMonth();
	create.Year  = EnterYear();
	return create;
}

bool CheckDate(date d){
	if(d.Year>=1950 && d.Year<=2021)
	        
if  (1950<= d.Year && d.Year<=2021 ){
	if((d.Month==1 ||d.Month==3 ||d.Month==5 ||d.Month==7 ||d.Month==8 ||d.Month==10 ||d.Month==12) && d.Day>0&&d.Day<=31)
          return true;
        else
     if((d.Month==4 ||d.Month==6 ||d.Month==9 ||d.Month==11) && d.Day>0 && d.Day<=30)
          return true;
        else
        	if(d.Month==2){
        		if((d.Year%400==0 || (d.Year%100!=0 && d.Year%400==0)) && d.Day>0 && d.Day<=29 )
        			return true;
        		else if (d.Day>0 && d.Day<=28)
        			return true;
        		else
        			return false;
			}
			else
				return false;
	}
     return false;

}
void DisplayDate(date d,bool check){
	if(check==true){
		cout<<"\n\n\n\n\t\t\t\t\t\t=====VALID DATE=====\n\n";
		cout<<"\n\n\n\n\t\t\t\t Date : "<<d.Day<<"/"<<d.Month<<"/"<<d.Year<<"\n";
	}
	else{
			cout<<"\n\n\n\n\t\t\t\t The date is not valid \n\n";
			cout<<"\n\n\n\n\t\t\t\t=====Please enter valid date=====\n\n"<<endl;
	}
}
void DisplaySimpldate(date d){
	cout<<d.Day<<"/"<<d.Month<<"/"<<d.Year;
}
//********************Bank management********************
typedef struct Client{
	string Firstname;
	string Lastname;
	string Address;
	int RegistrationNo;
	date d;
}client;

string EnterFirstname(){
	string fname;
	cout<<"\t\t\t\tEnter first name          : ";
	cin>>fname;
	return fname;
}
string EnterLastname(){
	string lname;
	cout<<"\t\t\t\tEnter last name           : ";
	cin>>lname;
	return lname;
}
string EnterAddress(){
	string ad;
	cout<<"\t\t\t\tEnter address             : ";
	cin>>ad;
	return ad;
}
int EnterRegNumber(){
	int registr;
	cout<<"\t\t\t\tEnter registration number : ";
	cin>>registr;
	return registr;
}
client CreateClient(){
	client create;
	create.Firstname      =EnterFirstname();
	create.Lastname       =EnterLastname();
	create.Address        =EnterAddress();
	create.RegistrationNo =EnterRegNumber();
	cout<<"\n";
	cout<<"\n\n\t\t\t\t\t\t===== ENTER BIRTH DATE OF CLIENT =====\n\n " <<endl;
	cout<<"\n";
	
	create.d            =  CreateDate();
	return create;
}

void DisplayCreateClient( client show){
	
	cout<<"\t\t\t\t\tFirst name      : " <<show.Firstname<<endl;
	cout<<"\t\t\t\t\tLast name       : "<<show.Lastname<<endl;
	cout<<"\t\t\t\t\tAddress         : "<<show.Address<<endl;
	cout<<"\t\t\t\t\tRegistration No : "<<show.RegistrationNo<<endl;
	cout<<"\t\t\t\t\tBirth date      : "<<show.d.Day<<"/"<<show.d.Month<<"/"<<show.d.Year<<endl;
}
void ModifyCreateClient(client cli){
	CreateClient();
}
void CreateNumberclient( client tab[], int size ){
	
	for( int i=0; i<=(size-1); i++)
	{
	cout<<"\n\n\n\t\t\t\t\t\t=====CREATE CLIENT No " << i+1 << "=====\n\n\n";
		tab[i] = CreateClient();
	}
}
void ModifyNClient(client tab[],int size){
	
	for( int i=0; i<=(size-1); i++){
		tab[i]=CreateClient();
	}
}
void displayCreateNumberClient( client tab[], int size ){
	for( int i=0; i<=(size-1); i++)
	{
		DisplayCreateClient(tab[i]);
	}
}


typedef struct BankFormular{
	client  Person;
	account AccNo;
}bank;

bank CreateBankFormular(){
	bank create;
	create.Person = CreateClient();
	cout<<"\n\n\t\t\t\t===== ACCOUNT DETAIL(S) ====="<<endl;
	create.AccNo  = CreateAccount();
	return create;
}
void DisplayCreateBankFormular( bank b ){
    DisplayCreateClient(b.Person); cout<<"\n"<<endl;	displaySimplCreateAccount( b.AccNo);
}
int EnterClientSize(){
	int size;
	cout<<"\n\n\t\t\t\t\t\t =====ENTER SIZE OF N CLENT(S) =====\n";
	do{
		cout<<"\n\n\t\t\t\tEnter the number of client : ";
		cin>>size;
	}while( size<1 );
	return size;
}
void CreateArray(bank tab[],int size){

	for( int i=0; i<=(size-1); i++){
		cout<<"\n\n\t\t\t\t===== CREATE ACCOUNT No " << i+1 << " ===== \n\n" ;
		tab[i] = CreateBankFormular();	
	}
}
void DisplayCreateArray(bank tab[],int size){
	
	cout<<"\n\n\t\t\t\t\t\t===== CLIENT ACCOUNT(S) DETAILS ===== \n\n"<<endl;
	for( int i=0; i<=(size-1); i++){
	    cout<<"\n\n\t\t\t\t\t\t===== CLIENT DETAIL "<<i+1<< " =====\n\n";
		 DisplayCreateBankFormular(tab[i]);	
	}
}

void DisplaySumAmount(bank tab[],int size){
	for( int i=0;i<size;i++)
	cout<<"\n\t\t\t\t The sum amount of Client "<<i+1<<" is : "<<tab[i].AccNo.amounts<<"\n";
}
float GreaterAmount(bank tab[],int size){
	float a =tab[0].AccNo.amounts;
	
	for( int i=0; i<size; i++){
		if( tab[i].AccNo.amounts>a )
		a = tab[i].AccNo.amounts;
	}
	return a;
}
void DisplayGreaterSum(bank tab[], int size, float a){
	cout<<"\n\n\t\t\t\t\t========== GREATER SUM AMOUNT ==========\n\n";
	for( int i=0; i<size; i++){
		if( tab[i].AccNo.amounts==a ){
			DisplayCreateBankFormular( tab[i] );
		}
	}
}
float LowerAmount(bank tab[],int size){
	float b = tab[0].AccNo.amounts;
	
	for( int i=0; i<size ;i++ ){
		if ( tab[i].AccNo.amounts<b && tab[i].AccNo.amounts>0 )
		b = tab[i].AccNo.amounts;
	}
	return b;
}
void DisplayLowerSum(bank tab[],int size,float b){
	cout<<"\n\n\t\t\t\t\t========== LOWER SUM AMOUNT ==========\n\n";
	for( int i=0; i<size; i++ ){
		if( tab[i].AccNo.amounts==b ){
			cout<<"\n";
			DisplayCreateBankFormular(tab[i]);
		}
	}
}
void DisplayNegSumAmount(bank tab[],int size){
     cout<<"\n\n\t\t\t\t\t========== NEGATIVE SUM AMOUNT ==========\n\n";
	for( int i=0; i<size; i++ ){
		if (tab[i].AccNo.amounts<0 ){
		DisplayCreateBankFormular( tab[i] );
		}
	}
}
void DisplaySort( bank b ){
	cout<<"\t\t\t\t First name : " << b.Person.Firstname<<endl;
	cout<<"\t\t\t\t Last name  : " << b.Person.Lastname<<endl;
	cout<<"\t\t\t\t Balance    : " << b.AccNo.amounts<<endl;
}
void SortDescSum( bank tab[], int size ){
	
	bank b;
	for( int i=0; i<size; i++ ){
		for( int j=i+1; j<size; j++ ){
			if( tab[i].AccNo.amounts < tab[j].AccNo.amounts ){
				b=tab[i];
				tab[i]=tab[j];
				tab[j]=b;
			}
		}
	}
	cout<<"\n\n\t\t\t========== Client list(s) starting by the greater sum amount ========== ";
	for( int i=0; i<size; i++ ){
	cout<<"\n\n\t\t\t\t\t===== CLIENT No "<<i+1<< " =====\n";
		cout<<"\n";
		DisplaySort(tab[i]);
	}
}
void DisplayIntroduction(){
	cout<<" \n\n\n\n\n\t\t\t\t****************** "<<endl;
	cout<<"	\t\t\t*  GROUP MEMBERS *\n";
	cout<<" \t\t\t\t****************** "<<endl;
	cout<<"\n\n\t\t\t\t1.KWIZERA Ibrahim"<<endl;
	cout<<"\t\t\t\t2.MAKEMO Alain Tresor"<<endl;
	cout<<"\t\t\t\t3.MANIMPA Tonny Tresor"<<endl;
	cout<<"\t\t\t\t4.MPENDEKERE Jobert"<<endl;
	cout<<"\t\t\t\t5.MPUNDU Alain Jordy"<<endl;
	cout<<"\n\n\n\n\n\n\t\t\t\tPress any letter or number to continue : " ;
	char c;
	cin>>c;
	system("cls");
}
//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************


int main(int argc, char** argv) {
    DisplayIntroduction();
	int size=9;
	account tab[size];
	client tabi[size];
	bank tabu[size];
	int menu;
	int submenu_1;
	int submenu_2;
	int submenu_3;
	do
	{
		cout<<"\n\n\n\n\t\t\t\t  =========== MAIN MENU ==========="<<endl;
		cout<<"\n\n\t\t\t\t\t 1. Account management";
		cout<<"\n\n\t\t\t\t\t 2. Client management";
		cout<<"\n\n\t\t\t\t\t 3. Bank management"<<"\n";
		cout<<"\n\t\t\t\t\t 4. Exit"<<endl;
		cout<<"\n\t\t\t\t\t    Select Your Option (1-3) : ";
		cin>>menu;
		system("cls");
		
		switch (menu)
		{
			case 1 :
					do
					{
						cout<<"\n\n\n\n\t\t\t\t  =========== ACCOUNT MANAGEMENT ==========="<<endl;
						cout<<"\n\n\t\t\t\t1. Enter the number m >0 of account"<<"\n";
						cout<<"\t\t\t\t2. Create  m accounts "<<"\n";	
						cout<<"\t\t\t\t3. Display m accounts"<<"\n";
						cout<<"\t\t\t\t4. Modify the amount of selected account"<<"\n";
						cout<<"\t\t\t\t5. Display sum of m accounts"<<"\n";
						cout<<"\t\t\t\t6. Dispaly the accounts with negative amount"<<"\n";
						cout<<"\t\t\t\t7. Exit"<<"\n";
						cout<<"\n\t\t\t\t Select Your Option (1-7) ";
						cin>>submenu_1;
						
						system("cls");// command which help to clear screen (console)
						switch(submenu_1){
							case 1 :
									size=EnterSize();
									tab[size];
									system("cls");
								break;
							case 2 :
							 		CreateNumberAccount( tab, size);
									system("cls");	
							    break;
							case 3 : 
								    displayCreateNumberAccount(tab,size);
								    do{
								    	cout<<"\n\n\n\n\n\n\t\t\t\tPress 0 to go to submenu  " ;
								    	cin>>submenu_1;
									}while(submenu_1 != 0 );
								    system("cls");
								break;
							case 4 : 
									modifyCreateNumberAccount(tab, size); system("cls"); 
								break;
							case 5 :
									displayCreateNumberAccount(tab,size);
									cout<<"\n";
									SumOfmAccount( tab,size );
									do{
									    cout<<"\n\n\n\n\n\n\n\n\t\t\t\tPress 0 to go to submenu  " ;
									    cin>>submenu_1;
									}while(submenu_1 != 0 ); system("cls");
								break;
							case 6 : displayNegative( tab,size ); 
									do{
									    cout<<"\n\n\n\n\n\n\n\n\t\t\t\tPress 0 to go to submenu  " ;
									    cin>>submenu_1;
									}while(submenu_1 != 0 ); system("cls");
							break;
									
				
							case 7 : 	break;
							 default :cout<<"\a"; 
						}
					} while(submenu_1 != 7 );	break;	
					
			case 2:
					do{
						cout<<"\n\n\n\n\t\t\t\t  =========== CLIENT MANAGEMENT ==========="<<endl;
						cout<<"\t\t\t\t1. Create a date"<<"\n";
						cout<<"\t\t\t\t2. Display the created date "<<"\n";	
						cout<<"\t\t\t\t3. Create a client"<<"\n";
						cout<<"\t\t\t\t4. Display client characteristics"<<"\n";
						cout<<"\t\t\t\t5. Change client characteristics"<<"\n";
						cout<<"\t\t\t\t6. Display m bank client account characteristics"<<"\n";
						cout<<"\t\t\t\t7. Modify the amount of a selected client account"<<"\n";
						cout<<"\t\t\t\t8. Display the sum of m client amount accounts"<<"\n";
						cout<<"\t\t\t\t9. Return";
						cout<<"\n\t\t\t\t Select Your Option (1-9) : ";
						cin>>submenu_2;
						system("cls");
						
							date dat;
							client tabl[1],cli;
							bool check;
						switch(submenu_2){
							case 1 :
							 {
							 	
							 	cout<<"\n\n\n\n\t\t\t\t\t\t=====CREATE DATE=====\n\n";
							   	dat = CreateDate();
								system("cls");

							 }break;
							
							case 2 :
								
								check=CheckDate(dat);
		        				DisplayDate(dat,check);
		        				do{
									cout<<"\n\n\n\n\n\n\t\t\t\tPress 0 to go to submenu  " ;
								    cin>>submenu_2;
								}while(submenu_2 != 0 ); system("cls");
								break;
							case 3 :
							 	{
							 		CreateNumberclient( tabi, 1 );
							 		cout<<"\n\n\t\t\t\t\t\t===== CREATE CLIENT M BANK ACCOUNT ===== ";
							 		size=EnterSize();
									tab[size];
							 		CreateNumberAccount( tab, size);
							 		system("cls");
						    	}	break;
		
							case 4 : 
										cout<<"\n\n\t\t\t\t\t\t===== CLIENT DETAIL =====\n\n";
										displayCreateNumberClient( tabi, 1 );
										do{
									    	cout<<"\n\n\n\n\n\n\t\t\tPress 0 to go to submenu  " ;
									    	cin>>submenu_2;
										}while(submenu_2 != 0 );
									    system("cls");
								 break;
							case 5 :
									ModifyNClient(tabi, 1);
								 break;
							case 6 : 
									cout<<"\n\n\n\t\t\t\t\t===== CLIENT DETAIL =====\n\n\n";
									displayCreateNumberClient( tabi, 1 );
									displayCreateNumberAccount(tab,size);
									do{
									    	cout<<"\n\n\n\n\n\n\t\t\tPress 0 to go to submenu  " ;
									    	cin>>submenu_2;
										}while(submenu_2 != 0 ); system("cls");
								break;
							case 7 : 
									modifyCreateNumberAccount( tab, size);
									system("cls");
								break;
							case 8 : 
									cout<<"\n\n\n\n\n\n\t\t\t\t\t\t===== SUM OF M CLIENT ACCOUNT =====\n\n \n\n";
									SumOfmAccount( tab, size );
									do{
								    	cout<<"\n\n\n\n\n\n\t\t\tPress 0 to go to submenu  " ;
								    	cin>>submenu_2;
									}while(submenu_2 != 0 ); system("cls");
								break;
							
							case 9: 
								break;
							default :cout<<"\a";
						}
					}while(submenu_2 != 9 );	
				break;
			case 3 :
					do
					{
						
						cout<<"\n\n\n\n\t\t\t\t  =========== BANK MANAGEMENT ==========="<<endl;
						cout<<"\n\n\t\t\t\t1. Enter the number n (> 1) of client"<<"\n";
						cout<<"\t\t\t\t2. Create an array of n clients and their m accounts"<<"\n";	
						cout<<"\t\t\t\t3. Display the characteristics of n clients and their accounts"<<"\n";
						cout<<"\t\t\t\t4. Display the sum amount of each client "<<"\n";
						cout<<"\t\t\t\t5. Display the client having the greater sum amount"<<"\n";
						cout<<"\t\t\t\t6. Display the client having the lower sum amount"<<"\n";
						cout<<"\t\t\t\t7. Display the client having negative sum amoun"<<"\n";
						cout<<"\t\t\t\t8. Display all clients starting by those having the greater sum amount"<<"\n";
						cout<<"\t\t\t\t9. Return";
						cout<<"\n\t\t\t\t Select Your Option (1-9) : ";
						cin>>submenu_3;
						system("cls");
						
						switch(submenu_3)
						{
							case 1 : 
									size = EnterClientSize();
									system("cls");
								break;
							case 2 :
									CreateArray(tabu,size);
									system("cls");
							   break;
							case 3 :
									DisplayCreateArray(tabu,size);
									do{
									    cout<<"\n\n\t\t\tPress 0 to go to submenu  " ;
									    cin>>submenu_3;
									}while(submenu_3 != 0 ); system("cls");
								break;
							case 4 :
									 DisplaySumAmount( tabu,size);
									 do{
									    cout<<"\n\n\t\t\tPress 0 to go to submenu  " ;
									    cin>>submenu_3;
									}while(submenu_3 != 0 ); system("cls");
								break;
							case 5 :
									{
										float great=GreaterAmount( tabu, size);
										DisplayGreaterSum( tabu, size, great);
									 do{
									    cout<<"\n\n\t\t\tPress 0 to go to submenu  " ;
									    cin>>submenu_3;
									}while(submenu_3 != 0 ); system("cls");
								break;
									}
							case 6 :
									{
										float lower=LowerAmount( tabu, size);
										DisplayLowerSum(tabu, size , lower);
										do{
										    cout<<"\n\n\n\n\t\t\tPress 0 to go to submenu  " ;
										    cin>>submenu_3;
										}while(submenu_3 != 0 ); system("cls");
									}
								break;
							case 7 :
									DisplayNegSumAmount( tabu, size);
									do{
									    cout<<"\n\n\n\n\t\t\tPress 0 to go to submenu  " ;
									    cin>>submenu_3;
									}while(submenu_3 != 0 ); system("cls");
							 break;
						case 8 :
								SortDescSum(tabu, size);
								do{
									    cout<<"\n\n\n\n\t\t\tPress 0 to go to submenu  " ;
									    cin>>submenu_3;
									}while(submenu_3 != 0 ); system("cls");
							break;
							case 9 : break;
							default :cout<<"\a"; break;
						}
					}
					while(submenu_3 != 9 );
				break;
				
					case 4:
					cout<<"\n\n\n\n\n\t\t\t\t====== THANKS FOR VISITING OUR SYSTEM ======";
				break;
			default : cout<<"\a"; break;
		}
	}
	while( menu!= 4 );
	
	return 0;
}

