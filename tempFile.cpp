#pragma once
#include <iostream>
#include "queue.hpp"
#include "datatype.hpp"
using namespace std;

class Heap
{

public:
	Heap_Node* root;
	Heap_Node* loc;
	Heap_Node* ploc;
	Heap()
	{
		root = NULL;

	}
	Heap_Node* last_parent()
	{
		Queue  q;
		q.push(root);
		Heap_Node* temp = q.front();
		while (!q.is_empty())
		{
			temp = q.front();
			q.pop();
			if (temp->LeftChild != NULL && temp->RightChild != NULL)
			{
				q.push(temp->LeftChild);
				q.push(temp->RightChild);
			}
			else
				break;
		}
		return temp;
	}
	int real_duplication_check(int value, Heap_Node* loc)
	{
		if (loc == NULL)
			return 0;
		if (loc->data == value)
		{
			return 1;
		}
		else
		{
			return (1 + real_duplication_check(value, loc->LeftChild));
			return (1 + real_duplication_check(value, loc->RightChild));
		}
	}
	bool is_empty()
	{
		return root == NULL;
	};

	void heapify(Heap_Node* temp)
	{
		if (temp->Parent == NULL)
		{
			return;
		}

		if (temp->Parent->data < temp->data)
		{

			if (temp->Parent == root)
			{

				if (temp == root->LeftChild)
				{

					Heap_Node* temp1 = temp->Parent;


					Heap_Node* rchild = NULL;
					if (temp1->RightChild != NULL)
					{
						rchild = temp1->RightChild;
					}
					temp1->LeftChild = temp->LeftChild;
					temp1->RightChild = temp->RightChild;
					root = temp;
					root->LeftChild = temp1;
					root->RightChild = rchild;

					root->LeftChild->Parent = root;
					if (root->RightChild != NULL)
						root->RightChild->Parent = root;
					if (temp1->LeftChild != NULL)
						temp1->LeftChild->Parent = temp1;
					if (temp1->RightChild != NULL)
						temp1->RightChild->Parent = temp1;
					root->Parent = NULL;

				}
				else if (temp == root->RightChild)
				{
					Heap_Node* temp1 = temp->Parent;
					Heap_Node* lchild = temp1->LeftChild;
					if (temp->LeftChild != NULL)
						temp1->LeftChild = temp->LeftChild;
					else
						temp1->LeftChild = NULL;
					if (temp->RightChild != NULL)
						temp1->RightChild = temp->RightChild;
					else
						temp1->RightChild = NULL;
					root = temp;
					root->RightChild = temp1;
					root->LeftChild = lchild;

					root->RightChild->Parent = root;
					root->LeftChild->Parent = root;
					if (temp1->LeftChild != NULL)
						temp1->LeftChild->Parent = temp1;
					if (temp1->RightChild != NULL)
						temp1->RightChild->Parent = temp1;
					root->Parent = NULL;

				}

			}

			else if (temp->Parent->LeftChild == temp)
			{

				if (temp->Parent->Parent->LeftChild == temp->Parent)
				{

					Heap_Node* temp1 = temp->Parent->Parent;
					Heap_Node* temp2 = temp->Parent;
					Heap_Node* lchild = NULL;
					if (temp->LeftChild != NULL)
						lchild = temp->LeftChild;
					Heap_Node* rchild = NULL;
					if (temp->RightChild != NULL)
						rchild = temp->RightChild;

					temp->LeftChild = temp->Parent;
					temp->RightChild = temp->Parent->RightChild;
					temp2->LeftChild = lchild;
					temp2->RightChild = rchild;
					temp1->LeftChild = temp;

					//updating parents
					temp1->LeftChild->Parent = temp1;
					if (temp2->LeftChild != NULL)
						temp2->LeftChild->Parent = temp2;
					if (temp2->RightChild != NULL)
						temp2->RightChild->Parent = temp2;
					temp->LeftChild->Parent = temp;
					if (temp->RightChild != NULL)
						temp->RightChild->Parent = temp;
				}
				else if (temp->Parent->Parent->RightChild == temp->Parent)
				{


					Heap_Node* temp1 = temp->Parent->Parent;
					Heap_Node* temp2 = temp->Parent;
					Heap_Node* lchild = NULL;
					if (temp->LeftChild != NULL)
						lchild = temp->LeftChild;
					Heap_Node* rchild = NULL;
					if (temp->RightChild != NULL)
						rchild = temp->RightChild;

					temp->LeftChild = temp->Parent;
					temp->RightChild = temp->Parent->RightChild;
					temp2->LeftChild = lchild;
					temp2->RightChild = rchild;
					temp1->RightChild = temp;

					//updating parents
					temp1->RightChild->Parent = temp1;
					if (temp2->LeftChild != NULL)
						temp2->LeftChild->Parent = temp2;
					if (temp2->RightChild != NULL)
						temp2->RightChild->Parent = temp2;
					temp->LeftChild->Parent = temp;
					if (temp->RightChild != NULL)
						temp->RightChild->Parent = temp;
				}
			}
			else if (temp->Parent->RightChild == temp)
			{
				if (temp->Parent->Parent->LeftChild == temp->Parent)
				{
					Heap_Node* temp1 = temp->Parent->Parent;
					Heap_Node* temp2 = temp->Parent;

					Heap_Node* lchild = NULL;
					if (temp->LeftChild != NULL)
						lchild = temp->LeftChild;
					Heap_Node* rchild = NULL;
					if (temp->RightChild != NULL)
						rchild = temp->RightChild;


					temp->RightChild = temp->Parent;
					temp->LeftChild = temp->Parent->LeftChild;
					temp2->LeftChild = lchild;
					temp2->RightChild = rchild;
					temp1->LeftChild = temp;

					//updating parents

					temp1->LeftChild->Parent = temp1;
					if (temp2->LeftChild != NULL)
						temp2->LeftChild->Parent = temp2;
					if (temp2->RightChild != NULL)
						temp2->RightChild->Parent = temp2;
					if (temp->LeftChild != NULL)
						temp->LeftChild->Parent = temp;
					temp->RightChild->Parent = temp;
				}
				else if (temp->Parent->Parent->RightChild == temp->Parent)
				{

					Heap_Node* temp1 = temp->Parent->Parent;
					Heap_Node* temp2 = temp->Parent;
					Heap_Node* lchild = NULL;
					if (temp->LeftChild != NULL)
						lchild = temp->LeftChild;
					Heap_Node* rchild = NULL;
					if (temp->RightChild != NULL)
						rchild = temp->RightChild;

					temp->RightChild = temp->Parent;
					temp->LeftChild = temp->Parent->LeftChild;
					temp2->LeftChild = lchild;
					temp2->RightChild = rchild;
					temp1->RightChild = temp;

					//updating parents
					temp1->RightChild->Parent = temp1;
					if (temp2->LeftChild != NULL)
						temp2->LeftChild->Parent = temp2;
					if (temp2->RightChild != NULL)
						temp2->RightChild->Parent = temp2;
					if (temp->LeftChild != NULL)
						temp->LeftChild->Parent = temp;
					temp->RightChild->Parent = temp;
				}
			}
		}
		else
			return;
		root->Parent = NULL;



		heapify(temp);
	}

	void insert(Course* obj, int value)
	{
		Heap_Node* newnode = new Heap_Node(value);
        newnode->node = obj;
		if (is_empty())
		{
			root = newnode;
			return;
		}
		Heap_Node* new_parent = last_parent();
		if (new_parent->LeftChild == NULL)
		{
			new_parent->LeftChild = newnode;
			newnode->Parent = new_parent;
		}
		else
		{
			new_parent->RightChild = newnode;
			newnode->Parent = new_parent;
		}
		heapify(newnode);

	}
	void inorder(Heap_Node* loc)
	{
		if (loc != NULL)
		{
			inorder(loc->LeftChild);
			cout << loc->data << endl;
			inorder(loc->RightChild);
		}
	}
	Heap_Node* last_node()
	{
		Queue q;
		q.push(root);
		Heap_Node* temp = q.front();
		while (!q.is_empty())
		{
			temp = q.front();
			q.pop();
			if (temp->LeftChild != NULL)
			{
				q.push(temp->LeftChild);
			}
			if (temp->RightChild != NULL)
			{
				q.push(temp->RightChild);
			}
		}
		return temp;
	}

	void downheapify(Heap_Node* temp)
	{
		root->Parent = NULL;
		Heap_Node* largest = temp;
		if (temp->LeftChild != NULL && temp->LeftChild->data > largest->data)
		{
			largest = temp->LeftChild;
		}

		if (temp->RightChild != NULL && temp->RightChild->data > largest->data)
		{
			largest = temp->RightChild;
		}
		if (largest != temp)
		{
			if (largest == root)
				return;
			if (largest == temp->LeftChild)
			{
				if (temp == root)
				{
					Heap_Node* lchild = NULL;
					Heap_Node* rchild = NULL;
					if (largest->RightChild != NULL)
						rchild = largest->RightChild;
					if (largest->LeftChild != NULL)
						lchild = largest->LeftChild;

					largest->LeftChild = temp;
					largest->RightChild = temp->RightChild;
					temp->LeftChild = lchild;
					temp->RightChild = rchild;
					root = largest;
					root->Parent = NULL;


					if (temp->LeftChild != NULL)
						temp->LeftChild->Parent = temp;
					if (temp->RightChild != NULL)
						temp->RightChild->Parent = temp;
					if (largest->RightChild != NULL)
						largest->RightChild->Parent = largest;
					largest->LeftChild->Parent = largest;

				}
				else if (temp != root)
				{
					if (temp->Parent->LeftChild == temp)
					{
						Heap_Node* temp1 = temp->Parent;
						Heap_Node* lchild = NULL;
						Heap_Node* rchild = NULL;
						if (largest->RightChild != NULL)
							rchild = largest->RightChild;
						if (largest->LeftChild != NULL)
							lchild = largest->LeftChild;

						largest->LeftChild = temp;
						largest->RightChild = temp->RightChild;
						temp->LeftChild = lchild;
						temp->RightChild = rchild;
						temp1->LeftChild = largest;

						largest->LeftChild->Parent = largest;
						if (largest->RightChild != NULL)
							largest->RightChild->Parent = largest;
						if (temp->LeftChild != NULL)
							temp->LeftChild->Parent = temp;
						if (temp->RightChild != NULL)
							temp->RightChild->Parent = temp;
						temp1->LeftChild->Parent = temp1;
					}

					else if (temp->Parent->RightChild == temp)
					{
						Heap_Node* temp1 = temp->Parent;
						Heap_Node* lchild = NULL;
						Heap_Node* rchild = NULL;
						if (largest->RightChild != NULL)
							rchild = largest->RightChild;
						if (largest->LeftChild != NULL)
							lchild = largest->LeftChild;

						largest->LeftChild = temp;
						largest->RightChild = temp->RightChild;
						temp->LeftChild = lchild;
						temp->RightChild = rchild;
						temp1->RightChild = largest;

						largest->LeftChild->Parent = largest;
						if (largest->RightChild != NULL)
							largest->RightChild->Parent = largest;
						if (temp->LeftChild != NULL)
							temp->LeftChild->Parent = temp;
						if (temp->RightChild != NULL)
							temp->RightChild->Parent = temp;
						temp1->RightChild->Parent = temp1;

					}
				}
			}
			else if (largest == temp->RightChild)
			{
				if (temp == root)
				{
					Heap_Node* lchild = NULL;
					Heap_Node* rchild = NULL;
					if (largest->RightChild != NULL)
						rchild = largest->RightChild;
					if (largest->LeftChild != NULL)
						lchild = largest->LeftChild;

					largest->LeftChild = temp->LeftChild;
					largest->RightChild = temp;
					temp->LeftChild = lchild;
					temp->RightChild = rchild;
					root = largest;
					root->Parent = NULL;


					if (temp->LeftChild != NULL)
						temp->LeftChild->Parent = temp;
					if (temp->RightChild != NULL)
						temp->RightChild->Parent = temp;
					if (largest->LeftChild != NULL)
						largest->LeftChild->Parent = largest;
					largest->RightChild->Parent = largest;
				}
				else if (temp != root)
				{
					if (temp->Parent->LeftChild == temp)
					{
						Heap_Node* temp1 = temp->Parent;
						Heap_Node* lchild = NULL;
						Heap_Node* rchild = NULL;
						if (largest->RightChild != NULL)
							rchild = largest->RightChild;
						if (largest->LeftChild != NULL)
							lchild = largest->LeftChild;

						largest->LeftChild = temp->LeftChild;
						largest->RightChild = temp;
						temp->LeftChild = lchild;
						temp->RightChild = rchild;
						temp1->LeftChild = largest;

						largest->RightChild->Parent = largest;
						if (largest->LeftChild != NULL)
							largest->LeftChild->Parent = largest;
						if (temp->LeftChild != NULL)
							temp->LeftChild->Parent = temp;
						if (temp->RightChild != NULL)
							temp->RightChild->Parent = temp;
						temp1->LeftChild->Parent = temp1;
					}

					else if (temp->Parent->RightChild == temp)
					{
						Heap_Node* temp1 = temp->Parent;
						Heap_Node* lchild = NULL;
						Heap_Node* rchild = NULL;
						if (largest->RightChild != NULL)
							rchild = largest->RightChild;
						if (largest->LeftChild != NULL)
							lchild = largest->LeftChild;

						largest->RightChild = temp;
						largest->LeftChild = temp->LeftChild;
						temp->LeftChild = lchild;
						temp->RightChild = rchild;
						temp1->RightChild = largest;

						largest->RightChild->Parent = largest;
						if (largest->LeftChild != NULL)
							largest->LeftChild->Parent = largest;
						if (temp->LeftChild != NULL)
							temp->LeftChild->Parent = temp;
						if (temp->RightChild != NULL)
							temp->RightChild->Parent = temp;
						temp1->RightChild->Parent = temp1;
					}
				}
			}

		}
		else return;
		downheapify(temp);
	}

	Course* get_max()
	{
		if (is_empty())
		{
			cout << "Heap is empty\n";
			return NULL;
		}
		Course* result = root->node;
		if (root->RightChild == NULL && root->LeftChild == NULL)
		{
			delete root;
			root = NULL;
			return result;
		}

		Heap_Node* last = last_node();
		if (last == root->RightChild)
		{
			Heap_Node* tempo1 = root->RightChild;
			tempo1->LeftChild = root->LeftChild;
			delete root;
			root = tempo1;
			root->LeftChild->Parent = root;
			root->RightChild = NULL;
			root->Parent = NULL;
			return result;
		}
		if (last == root->LeftChild)
		{
			Heap_Node* tempo1 = root;
			root = root->LeftChild;
			delete tempo1;
			root->Parent = NULL;
			return result;
		}
		// swapping last and root node and deleting the root node
		if (last->Parent->LeftChild == last)
		{
			Heap_Node* temp1 = root;
			last->LeftChild = root->LeftChild;
			last->RightChild = root->RightChild;
			last->Parent->LeftChild = NULL;
			root = last;
			root->Parent = NULL;
			if (root->LeftChild != NULL)
				root->LeftChild->Parent = root;
			if (root->RightChild != NULL)
			{
				root->RightChild->Parent = root;
			}
			delete temp1;
		}
		else if (last->Parent->RightChild == last)
		{
			Heap_Node* temp1 = root;
			last->LeftChild = root->LeftChild;
			last->RightChild = root->RightChild;
			last->Parent->RightChild = NULL;
			root = last;
			root->Parent = NULL;
			if (root->LeftChild != NULL)
				root->LeftChild->Parent = root;
			if (root->RightChild != NULL)
			{
				root->RightChild->Parent = root;
			}
			delete temp1;
		}
		Heap_Node* temp = root;
		downheapify(temp);

		return result;

	}

    void returnList(LinkedList *obj)
{
    Course *temp = get_max();
    while(!is_empty())
    {
        if (temp != NULL)
        {
            obj->insert(temp);
        }
        temp = get_max();
    }
}

};
