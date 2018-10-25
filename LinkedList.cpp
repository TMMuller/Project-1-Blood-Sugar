#include "stdafx.h"
#include "LinkedList.h"

List::List()
	: first_(NULL)
{
}


List::List(const List & other)
	: first_(clone(other.first_))
{
}


List::~List()
{
	while (!empty())
	{
		removeFirst();
	}
}

const List & List::operator=(const List & other)
{
	// check for list = list
	if (&other != this)
	{
		// clear the current contents of this List
		this -> ~List();
		// and get a copy of other
		first_ = clone(other.first_);
	}

	return *this;
}

bool List::operator==(const List &rhs) {
	/*if(size() == 0 && rhs.size() == 0){return true;}//both empty
	if(size() != rhs.size()){return false;}//sizes not the same

	Node * lptr = this->next_;
	Node * rptr = rhs->next_;
	Double lEntry = lptr->entry_;
	Double rEntry = rptr->entry_;
	while (lptr != NULL && rptr != NULL)
	{
	if(lEntry != rEntry){
	return false;
	}
	lptr = lptr->next_;
	rptr = rptr->next_;
	lEntry = lptr->entry_;
	rEntry = rptr->entry_;
	}
	*/
	return true;
}


bool List::empty() const
{
	return first_ == NULL;
}


void List::insertAsFirst(double x)
{
	first_ = new Node(x, first_);
}


double List::removeFirst()
{
	double item = first_->entry_;
	Node * tempPtr = first_;
	first_ = first_->next_;
	delete tempPtr;
	return item;
}


void List::print(ostream & outfile) const
{
	outfile << "[ ";
	if (!empty())
	{
		// The first entry is printed separately because no comma
		// is needed.
		outfile << first_->entry_;
		Node * ptr = first_->next_;
		while (ptr != NULL)
		{
			outfile << ", " << ptr->entry_;
			ptr = ptr->next_;
		}
	}
	outfile << " ]";
}


// Iterative version of clone.
// This version walks down the linked structure making a
//   new Node for each double in the structure.
Node * List::clone(Node * ptr)
{
	if (ptr == NULL)
	{
		return NULL;
	}
	Node * first = new Node(ptr->entry_);
	Node * last = first;
	ptr = ptr->next_;
	while (ptr != NULL)
	{
		last->next_ = new Node(ptr->entry_);
		last = last->next_;
		ptr = ptr->next_;
	}
	return first;
}


//// Recursive version of clone.
//// This version handles two cases, a linked structure with
////   no Nodes, and a linked structure with one or more
////   Nodes.
//Node * List::clone( Node * ptr )
//{
//   if( ptr == NULL )
//   {
//      return NULL;
//   }
//   return new Node( ptr->entry_, clone( ptr->next_ ) );
//}


ostream & operator<<(ostream & outfile, const List & list)
{
	list.print(outfile);
	return outfile;
}


double List::size() //Finds the size/count of the linked list
{
	Node *ptr = first_;
	int size = 0;
	if (ptr == NULL)
	{
		return size;
	}
	size = 1;
	while (ptr->next_ != NULL)
	{
		size += 1;
		ptr = ptr->next_;
	}
	return size;
}

double List::sum() //Sums the values in the linked list
{
	Node * ptr = first_;
	double val(0);
	double store(0);

	while (ptr != NULL)
	{
		val += ptr->entry_;
		ptr = ptr->next_;
	}
	return val;
}

double List::Max() //Finds the max value in the linked list
{
	Node *ptr = first_;
	double max(0);

	while (ptr != NULL)
	{
		if (max < ptr->entry_)
		{
			max = ptr->entry_;
		}
		ptr = ptr->next_;
	}
	return max;
}

double List::Min()  //Finds the min value in the linked list
{
	Node *ptr = first_;
	double min(0);
	if (ptr != NULL) {
		min = ptr->entry_;
	}

	while (ptr != NULL)
	{
		if (min > ptr->entry_)
		{
			min = ptr->entry_;
		}
		ptr = ptr->next_;
	}
	return min;
}

void List::Daily_Summary() //Prints out the summary for the linked list
{
	cout << endl;
	cout << "--------- Here is the Daily Summary Thus Far -------- " << endl;
	cout << "Sum of all Blood Sugar Readings : " << sum() << endl;
	cout << "Max of all Blood Sugar Readings : " << Max() << endl;
	cout << "Min of all Blood Sugar Readings : " << Min() << endl;
	cout << "Count of all Blood Sugar Readings : " << size() << endl << endl;
}


void List::insertAsLast(double x) //Inserts new nodes at the tail of the linked list
{
	Node *ptr = first_;
	if (ptr == NULL)
	{
		first_ = new Node(x, first_);
	}
	else {
		while (ptr->next_ != NULL)
		{
			ptr = ptr->next_;
		}
		ptr->next_ = new Node(x, NULL);
	}
}


