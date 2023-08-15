#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

void encryptDecrypt(char *input,char *output){
	char key[]={'K','C','Q'};
	int keyLength = sizeof(key)/sizeof(*key);
	int i;
	
	for (i=0;i<strlen(input); i++){
		output[i]=input[i] ^ key[i%keyLength];}} 

int main(int argc, char** argv) {
	string progPassword="liza11",password, ent_Password,oldUsername, option,username;
	char encrypted[100], decrypted[100], choice;
	int Attempts=0;
	
  
  	while(true){
		cout<<"1. Save account"<<endl;
		cout<<"2. Access saved password"<<endl;
		cout<<"3. Exit program"<<endl;
		cout<<"choose option: ";
		cin>>choice;
		cin.ignore();
		
		
		if(choice=='1'){
		    cout<<"\n";
			ofstream file("accounts.txt", ios::app);
			cout<<"Enter Username: ";
			getline(cin, username);
			cout<<"Enter Password: ";
			getline(cin, password);
			encryptDecrypt(&password[0], encrypted);
			file<<username<<" "<<encrypted<<endl;
			file.close();
			cout<<" "<<endl;
			cout<<"Username :"<<username<<endl;
			cout<<"Password :"<<password<<endl;
			cout<<"Are you sure to want to save the above account details? Yes/No\n";
			cin>>option;
			if(option=="YES"||option=="Yes"||option=="yes"){
			cout<<"Account saved";break;}
			else cout<<"Account saving cancelled";break;}
		
	
		else if(choice=='2'){
		     cout<<"\n";
			ifstream file("accounts.txt");
			bool found=false;
			cout<<"Enter the username: ";
			getline(cin, oldUsername);
			while(file>>username>>encrypted){
				encryptDecrypt(encrypted,decrypted);
				if(oldUsername==username){
					found=true;
	while(true){
		cout<<"Enter program password: ";
		cin>>ent_Password;
		if(ent_Password==progPassword){cout<<"The password for "<<username<<" is "<<decrypted<<endl;return 0;
		}
		if(ent_Password!=progPassword){ Attempts++;
		if(Attempts>=3){cout<<"Too many attempts. Exiting...\n";
		return 0;}
			cout<<"Incorrect password inputed.Kindly try again. "; continue;}
				
			}}
					file.close();
					if(oldUsername!=username||!found){
				cout<<"Username not available."; return 0;}}}
				
	
		
		else if(choice=='3'){cout<<"\n";
			cout<<"Thank you for your visit.\nProgram Quiting..."; break;}
		else cout<<"\nInvalid choice Input.\nKindly Try Again.\n";
		}}

	

	
	

