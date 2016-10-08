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
	if(index > size+1){
		cout <<"  check the index again " <<endl;
		return;
	}

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

	int size,data;
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
	list->insertNode(10,8);	

return 0;
}
