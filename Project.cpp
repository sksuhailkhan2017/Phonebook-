//----------------------------------------PHONEBOOK BY SUHAIL KHAN-----------------------------
#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
#include<stdlib.h>
#include<ios>
#include<limits>
using namespace std;

class Node{        //CLASS FOR DOUBLY LINKED LIST 
	public:        //CONTAINING NAME,NUMBER AND EMAIL
	string name;
	string number;
	string gmail;
	Node *prev;
	Node *next;
	Node(string n,string no,string g){
		name=n;
		number=no;
		gmail=g;
		prev=NULL;
		next=NULL;
	}
};

Node *head=NULL;
Node *tail=head;
class contactnode{       //CONTACTNODE CLASS FOR THE MAINMENU AND ALL THE FUNCTIONS 
	public: 

 
	void display(Node *head){ //DISPLAY FUNCTION TO SHOW CONTACTS
			  	Node *curr=head;  //(DOUBLY LINKED LIST TRAVERSAL)
				if(curr==NULL){
				cout<<"\n N O  C O N T A C T S  F O U N D\n";
	            return;
			    }
	
			while(curr!=NULL){
				cout<<"\nNAME : "<<curr->name<<endl;
				cout<<"\nNUMBER : +91-"<<curr->number<<endl;
				cout<<"\nEMAIL : "<<curr->gmail<<endl;
				cout<<endl;
				curr=curr->next;	
			}
    }



    void takeinput(){  //TAKES INPUT OF CONTACTS 
				string num; 
				string name; 
				string gmailid;
				cout<<"\nEnter Name : ";
				cin.sync();
				getline(cin,name); 
				cin.sync();
				G:
				cout<<"\nEnter Number : ";
				cin>>num;
				if(num.length()!=10){
					cout<<"invalid Number !.\n";
					goto G;
				}
				cin.sync(); 
				cout<<"\nEnter GmailID : ";
				getline(cin,gmailid);
				Node *temp=new Node(name,num,gmailid);
				 if(head==NULL)
			    {
			        head=temp;
			    }
			    else
			    {
			       Node *ptr=head;
					while(ptr->next!=NULL)
					{
			          ptr=ptr->next;
					}
					ptr->next=temp;
					temp->prev=ptr;
			    }
    }



    void search(string x){    // SEARCH FUNCTION TO SEARCH
    	 Node *curr=head;     // A PARTICULAR CONTACT 
    	 while(curr!=NULL){   //(DOUBLY LINKED LIST TRAVERSAL)
    	 	if(curr->name==x || curr->gmail==x || curr->number==x){
    	 		cout<<"\nNAME : "<<curr->name<<endl;
				cout<<"\nNUMBER : +91-"<<curr->number<<endl;
				cout<<"\nEMAIL : "<<curr->gmail<<endl;
				cout<<endl;
				return;
			 }
    	 	curr=curr->next;
		 }
		 cout<<"NO CONTACTS FOUND\n";
	}



	bool in(string x){  //IN FUNCTION TO CHECK IF A CONTACT IS PRESENT THE PHONEBOOK OR NOT.
		Node *curr=head;
		while(curr!=NULL){
    	 	if(curr->name==x || curr->gmail==x || curr->number==x){
				return true;
			 }
    	 	curr=curr->next;
		 }
		 return false;
	}




	


	void delcontact(string x){ //DELCONTACT FUNCTION
		Node *curr=head;  // TO DELETE A CONTACT.
		                    // (DOUBLY LINKED LIST DELETION)
		while(curr!=NULL){
			if(curr->name==x){
				
				break;
			}
			curr=curr->next;
		}
		        if(curr->prev!=NULL && curr->next!=NULL)
				{
				curr->prev->next=curr->next;
				curr->next->prev=curr->prev;
				delete curr;}
				else{
					if(curr->prev==NULL && curr->next!=NULL){
						head=curr->next;
						curr->next->prev=NULL;
						delete curr;
					}
					else if(curr->prev==NULL && curr->next==NULL){
						head=NULL;
						delete curr;
					}
					else{
						curr->prev->next=NULL;
						delete curr;
					}
				}
	}




	void mainmenu(){
				cout<<"************************************* P H O N E B O O K *************************************\n ENTER YOUR NAME : ";
				  string name_of_user;
				  getline(cin,name_of_user);
				  cout<<"\n||||||||||||||||||||||||||||||||||||| Welcome "<<name_of_user<<" |||||||||||||||||||||||||||||||||||||\n";
				  R:
				  cout<<"\n************************************* C O N T A C T S *************************************\n SELECT AN OPTION :\n 0.SHOW PHONEBOOK\n 1.ADD CONTACTS\n 2.SEARCH CONTACT\n 3.DELETE CONTACT\n 4.UPDATE CONTACT\n ";
				   int option;
				  cin>>option;
				  switch(option){
				  	case 0 : //show phonebook
						display(head);
						char ch0;
						cout<<"DO YOU WANT TO CONTINUE (y/n) :";
						cin>>ch0;
						if(ch0=='y')
						 goto R;
						else
						 break;
				  	case 1 : //add contacts
				  	    int number_of_contacts;
				  	    cout<<"\nNUMBER OF CONTACTS TO ADD : ";
						cin>>number_of_contacts;
						cin.sync();
						while(number_of_contacts!=0)
				  	    {   
						    takeinput();	    
							cin.sync();
							cout<<endl;
					        number_of_contacts--;
						}
					    char ch1;
						cout<<"DO YOU WANT TO CONTINUE (y/n) :";
						cin>>ch1;
						if(ch1=='y')
						 goto R;
						else
						 break;
				  	case 2 : //search contact
					 {  SEARCH:
						int search_options;
						string search_name,search_number,search_gmail;
						cout<<"1.SEARCH BY NAME : \n2.SEARCH BY NUMBER : \n3.SEARCH BY GMAILID : \n";
						cin>>search_options;
				  	    switch(search_options){
				  	    	case 1:
				  	    		cout<<"ENTER NAME :\n";
				  	    		cin>>search_name;
				  	    		search(search_name);
				  	    		char ch21;
								cout<<"DO YOU WANT TO CONTINUE (y/n) :";
								cin>>ch21;
								if(ch21=='y')
								 goto R;
								else
								 break;
				  	    	case 2:
				  	    		cout<<"ENTER NUMBER : \n";
				  	    		cin>>search_number;
				  	    		search(search_number);
				  	    		char ch22;
								cout<<"DO YOU WANT TO CONTINUE (y/n) :";
								cin>>ch22;
								if(ch22=='y')
								 goto R;
								else
								 break;
				  	    	case 3:
				  	    		cout<<"ENTER GMAILID :\n";
				  	    		cin>>search_gmail;
				  	    		search(search_gmail);
				  	    		char ch23;
								cout<<"DO YOU WANT TO CONTINUE (y/n) :";
								cin>>ch23;
								if(ch23=='y')
								 goto R;
								else
								 break;
				  	        default:
								char ans1;
						    	cout<<"I N V A L I D  O P T I O N\n Do you want to continue (y/n) : ";
						    	cin>>ans1;
						    	if(ans1=='y') goto SEARCH;
						    	else break;	
						  }
						 goto R;
				     }
				case 3 : // delete contact
				  { DELETE:
				  	string delete_name;
				    cout<<"ENTER THE NAME TO DELETE : ";
				    cin>>delete_name;
				    if(in(delete_name)){
				    	 delcontact(delete_name);
				    	char delans;
						cout<<"DELETED SUCCESSFULLY !\nDo you want to continue deleting? (y/n) : ";
						cin>>delans;
						if(delans=='y'){
							goto DELETE;
						}
						else{
						   goto R;	
						}
					}
					else{
						char delans;
						cout<<"NO CONTACT FOUND \nDo you want to continue deleting? (y/n) : ";
						cin>>delans;
						if(delans=='y'){
							goto DELETE;
						}
						else{
						   goto R;	
						}
					}
				  	goto R;
				  }
				case 4 : //update contact
				   {  UPDATE:
				   	
				     string contact_to_update;
					 cout<<"ENTER THE NAME OF THE PERSON TO UPDATE :\n";
				     cin>>contact_to_update;
				     if(in(contact_to_update))
					 {
					 	 Node *ptr=head;
					 while(ptr!=NULL)
				     {  
					   if(ptr->name==(contact_to_update))
				   	 {
					 int update_no;
				   	 cout<<"1.UPDATE NAME\n 2.UPDATE NUMBER\n 3.UPDATE EMAIL\n";
				   	 cin>>update_no;
					 switch(update_no){
					 	case 1 :
					 		{
							 string updated_name;
							 cin.sync();
					 		cout<<"ENTER NAME\n";
					 		cin>>updated_name;
					 		ptr->name=updated_name;
					 		cout<<"UPDATED SUCCESSFULLY ! \n";
					 		search(updated_name);
					 		break;
					 	    }
					    case 2 :
					    	{
							string updated_number;
							cin.sync();
					 		cout<<"ENTER NUMBER\n";
					 		cin>>updated_number;
					 		ptr->number=updated_number;
							cout<<"UPDATED SUCCESSFULLY ! \n";
					 		search(updated_number);
					 		break;
					 	    }
					    case 3 :
					    	{
							string updated_email;
							cin.sync();
					 		cout<<"ENTER EMAIL\n";
					 		cin>>updated_email;
					 	    ptr->gmail=updated_email;
					 		cout<<"UPDATED SUCCESSFULLY ! \n";
					 		search(updated_email);
					 		break;
					 	    }
						default:
						  char ans4;
						    	cout<<"I N V A L I D  O P T I O N\n Do you want to continue (y/n) : ";
						    	cin>>ans4;
						    	if(ans4=='y') goto UPDATE;
						    	else break;	
					 }
					 goto R;}
					 ptr=ptr->next;
				}}
				else{
						char ans4;
						cout<<"CONTACT DOESN'T EXIST \n Do you want to continue (y/n) : ";
					    cin>>ans4;
					    if(ans4=='y') goto UPDATE;
					    else goto R;
		
						}
					}
				default :
				    	char ans;
				    	cout<<"I N V A L I D  O P T I O N\n Do you want to continue (y/n) : ";
				    	cin>>ans;
				    	if(ans=='y') goto R;
				    	else break;
				  }
			}
};

int main(){
	  contactnode c;
	  c.mainmenu(); 
	  return 0; 
}
