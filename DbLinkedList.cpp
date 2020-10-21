#include"DbLinkedList.h"
DbLinkedList::Node::Node(){
    link = NULL;
	plink = NULL;
}
DbLinkedList::Node::Node(Book b,Member m, Staff s){
    this->B = b;
    this->M = m;
    this->S = s;
    link = NULL;
	plink = NULL;
}
void DbLinkedList::Node::setBook(Book b){
	this->B = b;
}
void DbLinkedList::Node::setMember(Member m){
	this->M = m;
}
void DbLinkedList::Node::setStaff(Staff s){
	this->S = s;
}
DbLinkedList::DbLinkedList(){
    this->head=NULL;
    this->tail=NULL;
    count=0;
}
DbLinkedList::~DbLinkedList(){
	for(int i=1;i<count;i++){
		Node *tmp = this->head;
		tmp =this->head->link;
		delete tmp;
		tmp = NULL;
	}
	this->head = NULL;
	this->tail = NULL;
}
void DbLinkedList::AddBook(Book b){
	Node *NewNode = new Node();
	NewNode->setBook(b);
	if(head == NULL){
		head = NewNode;
		tail = NewNode;
		count++;
	}else{
		tail->link = NewNode;
		NewNode->plink = tail;
		tail = NewNode;
		count++;
	}
}
void DbLinkedList::AddMember(Member m){
	Node *NewNode = new Node();
	NewNode->setMember(m);
	if(head == NULL){
		head = NewNode;
		tail = NewNode;
		count++;
	}else{
		tail->link = NewNode;
		NewNode->plink = tail;
		tail = NewNode;
		count++;
	}
}
<<<<<<< HEAD

=======
void DbLinkedList::ShowCategory(string cate){
	for(Node *temp=head;temp!=NULL;temp=temp->link){
		if(temp->B.getCate()==cate){
			cout<<temp->B.getIdBook()<<left<<setw(10)<<temp->B.getNameBook()<<left<<setw(20)
			<<temp->B.getAuthor()<<left<<setw(10)<<endl;
		}
	}
}
>>>>>>> e2e9d5f76e29b6c875471f45104b7e6440b11735
