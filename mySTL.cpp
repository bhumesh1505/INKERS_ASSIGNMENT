#include "mySTL.h"
bool operator <(const timespec& lhs, const timespec& rhs)
{
    if (lhs.tv_sec == rhs.tv_sec)
        return lhs.tv_nsec < rhs.tv_nsec;
    else
        return lhs.tv_sec < rhs.tv_sec;
}
void printList(node *head)
{
    while(head!=NULL)
    {
        cout << "path :" << head->path << endl;
        cout << "name :" << head->name << endl;

        cout << "protection mode : " << head->st_mode << endl;
        cout << "inode number : " << head->st_ino << endl;
        cout << "total file size, in bytes :" << head->st_size << endl;
        cout << "time of last access :" << ctime(&(head->st_atim.tv_sec));
        cout << "time of last modification :" << ctime(&(head->st_mtim.tv_sec));
        cout << endl;
        head = head->next;
    }
}
void storeAttributes(node **head,char *path)
{
    struct stat FileAttrib;
    
    if (stat(path, &FileAttrib) < 0){
        cout << "File Error Message = " << strerror(errno) << endl;
    }
    else{
        node *newFile = (node*)malloc(sizeof(node));
        if(newFile)
        {
            newFile->next = NULL;

            char *path1 = new char[strlen(path)];
            strcpy(path1,path);
            newFile->path = path1;

            string name="";
            int len = strlen(path) - 1;
            while(len>=0 && path[len] != '/')
            {
                name = path[len] +  name;
                len--;
            }
            newFile->name = name;

            newFile->st_mode = FileAttrib.st_mode ;
            newFile->st_ino = FileAttrib.st_ino;
            newFile->st_size = FileAttrib.st_size;
            newFile->st_atim = FileAttrib.st_atim;
            newFile->st_mtim = FileAttrib.st_mtim;
        }
        newFile->next = *head; // insert new node at start of linked list
        *head = newFile; // change the head 
    }
}
node *Divide(node *p)
{
	node *q,*slow,*fast;
	slow = p;
	fast = p->next->next; // size is greater than equal to 2
	while(fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
		if(fast != NULL)
		{
			fast = fast->next;
		}
	}
	q = slow->next;
	slow->next = NULL;

	return q;
}

node *merge(node *p , node *q , string select )
{
	node *head,*tail;
	if(p != NULL && q != NULL)
	{

		if( (select == "size" && p->st_size < q->st_size ) || (select == "name" && p->name < q->name ) || (select == "accessDaate" &&  p->st_atim < q->st_atim  ) )
		{
			head = p;
			p = p->next;
		}
		else
		{
			head = q;
			q = q->next;
		}
		tail = head;
	}
	while(p && q)
	{

		if( (select == "size" && p->st_size < q->st_size ) || (select == "name" && p->name < q->name ) || (select == "accessDaate" && p->st_atim < q->st_atim ) )
		{
			tail = tail->next = p;
			p = p->next;
		}
		else
		{
			tail = tail->next = q;
			q = q->next;
		}
	}
	if(p)
	{
		tail->next = p;
	}
	if(q)
	{
		tail->next = q;
	}
	return head;
}
node *mergeSort(node *lptr , string select)
{
	node *head,*head1,*head2;
	head = head1 = lptr;
	if(head != NULL && head->next != NULL)
	{
		head2 = Divide(head1);

		head1 = mergeSort(head1 , select);
		head2 = mergeSort(head2 , select);
		head = merge(head1,head2 , select);
	}
	return head;
}
void mySort(node **head , string select)
{
	*head = mergeSort(*head , select );
}