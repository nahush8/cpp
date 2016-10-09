#include<iostream>
using namespace std;

class linkedList{

	struct Node {
		int data;
		Node *next;
	};
	Node *head;
	int size;
	//Public members
public:
	//Constructor
	linkedList(){
		head = NULL;
	}

	Node *createNode(int);
	void addNode(int);
	void printList();
	void insertNode(int,int);
	void deleteNode(int);
	int getMaxSize();
	void setMaxSize(int);
};

linkedList::Node *linkedList::createNode(int data){
	Node *newNode = new Node();
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
void linkedList::addNode(int data){
	if(	head == NULL){
		head = createNode(data);
		return;
	}
	Node* temp = head;
	while(temp -> next != NULL)
		temp = temp->next;

	Node* addedNode = createNode(data);
	temp -> next = addedNode;
}

int linkedList::getMaxSize(){return size;}

void linkedList::setMaxSize(int data){size = data;}

void linkedList::insertNode(int data, int index){

	int size = getMaxSize();
	if(index < 0 || index > size ){
		cout <<"Wrong index" <<endl;
		return;
	}

	if (index == 0){
		Node *newNode = createNode(data);
		newNode->next = head;
		head = newNode;
	}
	else if (index == size){
		Node *temp = head;
		while(temp->next != NULL)
			temp = temp->next;
		Node *newNode = createNode(data);
		newNode->next = NULL;
		temp->next = newNode;
	}
	else{
		Node *temp = head;
		while(--index != 0)
			temp = temp->next;
		Node *newNode = createNode(data);
		newNode->next = temp->next;
		temp->next = newNode;
	}

	setMaxSize(size+1);
}


void linkedList::deleteNode(int index){

	int size = getMaxSize();
	if(index < 0 || index >= size ){
		cout <<"Wrong index" <<endl;
		return;
	}


	if(index == 0){
		Node* temp = head;
		head = temp->next;
		delete temp;

	}

	else if (index ==  size-1){
		Node *temp = head;
		while(temp->next->next != NULL)
			temp = temp->next;
		Node *saveTemp = temp->next;
		temp->next = NULL;
		delete saveTemp;
	}
	else{
		Node *temp = head;
		while(--index != 0)
			temp = temp->next;
		Node *saveTemp = temp->next;
		temp->next = temp->next->next;
		delete saveTemp;

	}
	setMaxSize(size-1);

}

void linkedList::printList(){
	Node* temp = head;
	do{
		cout<<temp->data<<"\t";
		temp = temp -> next;
	}while(temp != NULL);
	cout<<endl;
}



int main(){

	int size = 0,data = -999,number = 0,pos = -1,index = -1;
	linkedList *list = new linkedList();
	do{
		cout<<"Enter the size of the list"<<endl;
		cin >> size;
		list->setMaxSize(size);
		if(size < 0)
			cout << "ENTER A VALID SIZE\n";
	}while (size <=0);
	
	for(int i = 0 ; i < size ; i++){
		cout<<"Enter the element to be added in the list\t";
		cin >> data;	
		list->addNode(data);
	}
	list->printList();
	cout<<"Enter the number to be inserted followed by the index"<<endl;
	cin>>number>>pos;
	list->insertNode(number,pos);
	list->printList();
	cout<<"Enter the index to be deleted"<<endl;
	cin>> index;
	list->deleteNode(index);
	list->printList();
return 0;
}
