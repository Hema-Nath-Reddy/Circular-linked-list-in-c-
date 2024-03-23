#include<iostream>
using namespace std;
struct node{
	node* link;
	int data;
};
class circular{
	node* head=NULL;
	node* tail=NULL;
	public:
		void insertbeg(int data){
			node* newnode=new node();
			newnode->data=data;
			if(head==NULL){
				newnode->link=NULL;
				head=tail=newnode;	
			}else{
				newnode->link=head;
				head=newnode;
				tail->link=newnode;
			}	
			cout<<"Insertion of "<<data<<" at beginning is successful."<<endl;
		}
		void insertmiddle(){
			if(head==NULL){
				cout<<"Empty list."<<endl;
			}else if(head->link==NULL){
				cout<<"Only one node is present."<<endl;
			}else{
				int index;
				cout<<"Enter the index: ";
				cin>>index;
				if(index>count()||index<0){
					cout<<"Invalid index."<<endl;
				}else{
					int data;
					cout<<"Enter the data: ";
					cin>>data;
					int c=1;
					node* temp=head;
					node* newnode=new node();
					newnode->data=data;
					while(c!=index){
						c++;
						temp=temp->link;	
					}
					node* temp2=temp->link;
					temp->link=newnode;
					newnode->link=temp2;
					cout<<"Insertion of "<<data<<" at index "<<index<<" is successful."<<endl;
				}
			}
		}
		void insertend(int data){
			node* newnode=new node();
			newnode->data=data;
			if(head==NULL){
				newnode->link=NULL;
				head=tail=newnode;
			}else{
				tail->link=newnode;
				newnode->link=head;
				tail=newnode;
			}
			cout<<"Insertion of "<<data<<" at end is successful."<<endl;
		}
		void deletebeg(){
			if(head==NULL){
				cout<<"Empty list."<<endl;
			}else{
				node* temp=head;
				head=head->link;
				tail->link=head;
				delete temp;
				cout<<"Deletion at beginning succesful."<<endl;
			}
		}
		void deletemiddle(){
			if(head==NULL){
				cout<<"Empty list."<<endl;
			}else if(head->link==NULL){
				deletebeg();
			}else{
				int index;
				cout<<"Enter the index: ";
				cin>>index;
				if(index>count()||index<0){
					cout<<"Invalid index."<<endl;
				}else{
					int c=1;
					node* temp=head;
					while(c!=index){
						temp=temp->link;
						c++;
					}
					node* temp2=temp->link;
					temp->link=temp2->link;
					delete temp2;
					cout<<"Deletion at index "<<index<<" is successful."<<endl;
				}
			}
		}
		void deletend(){
			if(head==NULL){
				cout<<"Empty list."<<endl;
			}else{
				node* temp=head;
				do{
					temp=temp->link;
				}while(temp->link!=tail);
				node* temp2=tail;
				temp->link=head;
				delete temp2;
				tail=temp;
				cout<<"Deletion at end successful."<<endl;
			}
		}
		void display(){
			if(head==NULL){
				cout<<"Empty list."<<endl;
			}else{
				node* temp=head;
				do{
					cout<<temp->data<<endl;
					temp=temp->link;
				}while(temp!=head);
			}
		}
		int count(){
			if(head==NULL){
				return 0;
			}else if(head->link==NULL){
				return 1;
			}else{
				int c=0;
				node* temp=head;
				do{
						c++;
					temp=temp->link;
				
				}while(temp!=head);
				return c;
			}
		}
		int search(){
			if(head==NULL){
				return -1;
			}else{
				int key;
				cout<<"Enter the key element: ";
				cin>>key;
				node* temp=head;
				int c=1;
				int index=-1;
				do{
					temp=temp->link;
					if(temp->data==key){
						index=c;
						break;
					}
					c++;
				}while(temp!=head);
				return index;
			}	
		}
};
int main(){
	circular c;
	int choice;
	int result;
	cout<<"Welcome to Circular Linked List demonstration."<<endl;
	do{
		cout<<endl<<"1. Insert at beginning."<<endl;
		cout<<"2. Insert at middle."<<endl;
		cout<<"3. Insert at end."<<endl;
		cout<<"4. Delete at beginning."<<endl;
		cout<<"5. Delete at middle."<<endl;
		cout<<"6. Delete at end."<<endl;
		cout<<"7. Display the list."<<endl;
		cout<<"8. Count the number of nodes."<<endl;
		cout<<"9. Search for a key element."<<endl;
		cout<<"10. Exit."<<endl<<endl;
		cout<<"Enter choice: ";
		cin>>choice;
		switch(choice){
			case 1:
				int data;
				cout<<"Enter the element: ";
				cin>>data;
				c.insertbeg(data);
				break;
			case 2:
				c.insertmiddle();
				break;
			case 3:
				int element;
				cout<<"Enter the data: ";
				cin>>element;
				c.insertend(element);
				break;
			case 4:
				c.deletebeg();
				break;
			case 5:
				c.deletemiddle();
				break;
			case 6:
				c.deletend();
				break;
			case 7:
				c.display();
				break;
			case 8:
				cout<<"The number of nodes are: "<<c.count()<<endl;
				break;
			case 9:
				 result=c.search();
				if(result==-1){
					cout<<"The entered key element is not present in the list."<<endl;
				}else{
					cout<<"The index of the key element is: "<<result<<endl;
				}
				break;
			case 10:
				cout<<"Exiting..."<<endl;
				break;
			default:
    			cout << "Enter your choice from 1-10." << endl;
    		break;
		}
	}while(choice!=10);
	return 0;
}
