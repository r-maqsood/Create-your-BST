#include<iostream>
#include<fstream>
using namespace std;

template <class LE>
class BST;

//////////////////////////////////////////////////
	
template <class T>					//QueueADT class						
class queueADT
{
	private:
		T * queueptr;
		T retval;
	public:
		int maxsize, rear, front;
		
		queueADT()
		{
			maxsize=10;
			rear=front=0;
			queueptr=new T[maxsize];
		}
		queueADT(int size)
		{
			rear=front=0;
			queueptr=new T[size];
		}
		~queueADT()
		{
		
		}

		void enque(T a);
		T deque();
		bool isFull();
		bool isEmpty();
				
};

template <class T>
void queueADT<T>::enque(T a)
{
	if(! isFull())
		queueptr[rear]=a;
		rear=(rear+1)%maxsize;
}

template <class T>
T queueADT<T>::deque()
{
	if(! isEmpty())
		retval=queueptr[front];
		front=(front+1)%maxsize;
		return retval;
}

template <class T>
bool queueADT<T>::isFull()
{
	if((rear+1)%maxsize ==front)
		return true;
	else
		return false;
}

template <class T>
bool queueADT<T>::isEmpty ()
{
	if(rear==front)
		return true;
	else
		return false;
}

///////////////////////////////////////////////////////

template <class LE>							//TreeNode Class
class TreeNode
{
	private:
		LE element;		
		TreeNode *right;
		TreeNode *left; 
		TreeNode (const LE &elem, TreeNode *rightptr, TreeNode *leftptr)
		{
			element=elem;
			right=rightptr;
			left=leftptr;
		}
	friend class BST<LE>;
};

///////////////////////////////////////////////////

template <class LE>							//BST Class
class BST
{
	private:
		TreeNode <LE>*root;
	public:
		BST()														//Constructor
		{
			root='\0';
		}
		~BST()														//Destructor
		{
			
		}
	void insert(const LE newElement)								//Insert Function
	{
		TreeNode <LE>*temp=new TreeNode<LE>(newElement,'\0','\0');
		//temp->element =newElement;
		//temp->left='\0';
		//temp->right='\0';
		if(root=='\0')
			root=temp;
		else
		{
			TreeNode <LE>*curr=root;
			TreeNode <LE>*prev=root;
			while(curr!='\0')
			{
				if(temp->element >= curr->element)
				{
					prev=curr;
					curr=curr->right;
				}
				else
				{
					prev=curr;
					curr=curr->left;
				}
			}
			if(temp->element >=prev->element)
			{
				prev->right=temp;
				cout<<"One node inserted\n\n";
			}
			else
			{
				prev->left=temp;
				cout<<"One node inserted\n\n";								
			}
		}
	}	
	
	
	void del (const int &newElement)								//Delete Function
	{
		int c;
		c=empty();
		if (c==1)
			cout<<"BST is empty\n\n";
		else
		{
			TreeNode <LE>*curr=root;
			TreeNode <LE>*prev=root;
			while (curr!='\0' && newElement !=curr->element)
			{
				prev=curr;
				if(newElement >= prev->element)
					curr=curr->right;
				else
					curr=curr->left;
			}
			if(curr=='\0')
				cout<<"Data Not Found";
			else
			{
				TreeNode <LE> temp=curr;
				curr=curr->left;
				while(curr->right!='\0')
				{
					prev=curr;
					curr=curr->right;
				}
				TreeNode <LE>*temp1=temp;
				temp=curr;
				curr=temp1;
				prev->right=curr->left;
				delete curr;
				cout<<"One node deleted\n";
			}
		}
	}

	int empty() const												//List Empty Function?
	{	
		if(root=='\0')
			return 1;
		else
			return 0;
	}

	void printlevel()												//Level-wise printing using QueueADT
	{
		TreeNode <LE>*curr=root;
		queueADT <TreeNode<LE> *> q1;
		q1.enque(curr);
		while(!q1.isEmpty())
		{
			cout<<q1.deque();
			if(curr->left!='\0')
				q1.enque(curr->left);
			if(curr->right!='\0')
				q1.enque(curr->right);
		}
	}
};

//////////////////////////////////////////////////

void main()
{
	BST <int>b1;
	int p;
	char option;
	do
	{
		cout<<"\n\n\n\t\tWelcome to the BST MENU\n";
		cout<<"\t---------------------------------------------------"<<endl;
		cout<<"\t\tPress 1 to Enter new node\n";
		cout<<"\t\tPress 2 to Delete a node\n";
		cout<<"\t\tPress 3 to Check if BST is empty?\n";
        cout<<"\t\tPress 4 to Print Level-wise\n";
        cout<<"\t\tPress 5 to Save data\n\n\n\n";
        cout<<"\t\tPress 6 to Exit\n\n\n\n";
		cout<<"WHAT DO YOU WANT TO DO?   ";
        
		cin>>option;
		
        switch(option)
		{
		case '1':
			cout<<"\nEnter Number:   ";
			cin>>p;
			b1.insert(p);
			break;
		case '2':
			cout<<"\nEnter number:   ";
			cin>>p;
			b1.del(p);
			break;
		case '3':
			int c;
			c=b1.empty();
			if(c==1)
				cout<<"BST is empty\n\n";
			else
				cout<<"BST is not empty\n\n";
			break;
		case '4':
			b1.printlevel();
			break;
		case '5':
			char s;
			cout<<"\n\nDo you want to save data?  Y / N: ";
			cin>>s;
			if (s=='y')
				my.save();
			break;
		default:
			break;
		}
	}
	while(option!='6');
}
