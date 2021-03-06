// LinkedList_Hockman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;


struct node //creating node head structure 
{
	int data; //data stored in each node
	node *next; //pointer in each node pointing to the next one
};

class LinkedList
{
private:
	int counter;
	node *head, *tail; //pointer references to head and tail
public:
	LinkedList() //pointing to NULL on both head and tail
	{
		head = NULL;
		tail = NULL;
	}

	void createnode(int value) //creating a node at the end of the LL
	{
		node *temp = new node;
		temp->data = value;
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
	}

	int displayCounter()
	{
		counter += 1;
		return counter;
	}

	void display() //printing out all values in the LL
	{
		node *temp;
		temp = head;
		while (temp != NULL) //looping until temp hits the end of the list (which is the NULL pointer)
		{
			cout << temp->data << "\t";
			temp = temp->next;
			
			counter += 1;
		}
		counter += 2;
		cout << endl;
	}

	int addStart(int value) //adding a value at the start of the LL
	{
		node *temp = new node;
		temp->data = value;
		temp->next = head;
		head = temp;

		temp = head;
		int sizeCount = 0;

		counter += 1;

		if (temp == NULL) //searching for the null pointer 
		{
			return 0;
		}
		else
		{
			while (temp != NULL)
			{
				temp = temp->next;
				sizeCount++;

				counter += 1;
			}

			counter += 1;
			return sizeCount;
		}
	}

	int addPos(int pos, int value) //adding a value at a certain position 
	{
		node *pre= new node;
		node *current = new node;
		node *temp = new node;
		current = head;

		counter += 1;

		for (int i = 1; i < pos; i++)
		{
			pre = current;
			current = current->next;

			counter++;
		}

		temp->data = value;
		pre->next = temp;
		temp->next = current;


		temp = head;
		int sizeCount = 0;

		if (temp == NULL) //searching for the null pointer 
		{
			return 0;
		}
		else
		{
			while (temp != NULL)
			{
				temp = temp->next;
				sizeCount++;

				counter++;
			}
			counter += 6;

			return sizeCount;
		}
	}

	int deleteStart() //deleting at the start of the LL
	{
		node *temp = new node;
		temp = head;
		head = head->next;
		delete temp;


		temp = head;
		int sizeCount = 0;

		counter += 7;
		
		if (temp == NULL) //searching for the null pointer 
		{
			return 0;
		}
		else
		{
			while (temp != NULL)
			{
				temp = temp->next;
				sizeCount++;

				counter++;
			}
			return sizeCount;
		}
	}

	int deleteLast() //deleting at the end of the LL
	{
		node *current = new node;
		node *previous = new node;
		current = head;
		while (current->next != NULL)
		{
			previous = current;
			current = current->next;
		}

		tail = previous;
		previous->next = NULL;
		delete current;

		node *temp = new node;
		temp = head;
		int sizeCount = 0;

		if (temp == NULL) //searching for the null pointer 
		{
			return 0;
		}
		else
		{
			while (temp != NULL)
			{
				temp = temp->next;
				sizeCount++;
				counter++;
			}
			counter += 10;
			return sizeCount;
		}
	}

	int deletePos(int pos) //deleting at a certain position 
	{
		node *current = new node;
		node *previous = new node;
		current = head;
		for (int i = 1; i < pos; i++)
		{
			previous = current;
			current = current->next;
		}
		previous->next = current->next;


		node *temp = new node;
		temp = head;
		int sizeCount = 0;

		if (temp == NULL) //searching for the null pointer 
		{
			return 0;
		}
		else
		{
			while (temp != NULL)
			{
				temp = temp->next;
				sizeCount++;

				counter++;
			}
			counter += 8;
			return sizeCount;
		}
	}

	int size() //iterating and find the size of the list 
	{
		node *temp;
		temp = head;
		int sizeCount = 0;

		if (temp == NULL) //searching for the null pointer 
		{
			return 0;
		}
		else
		{
			while (temp != NULL)
			{
				temp = temp->next;
				sizeCount++;

				counter++;
			}
			counter += 3;
			return sizeCount;
		}
	}

	int isEmpty() //finding the null and returning 1 if its teh first one and 0 if it is not 
	{
		node *temp;
		temp = head;
		if (temp->next == NULL)
		{
			counter += 2;
			return 1;
		}
		else
		{
			counter += 2;
			return 0;
		}
	}

	int get(int pos) //finding a value at a certain position 
	{
		node *temp;
		temp = head;
		int count = 1;

		while (count < pos)
		{
			temp = temp->next;
			count++;

			counter++;
		}
		counter += 3;
		return temp->data;
	}

	int set(int pos, int value) //finds a value and sets it to the value passed into it
	{
		node *temp;
		temp = head;
		int count = 1;
		int oldVal = 0;

		while (count < pos)
		{
			temp = temp->next;
			count++;

			counter++;
		}
		oldVal = temp->data;
		temp->data = value;
		
		counter += 5;
		return oldVal;
	}
};


int main()
{
	LinkedList obj; //initializing starting list with preset values 
	obj.createnode(22);
	obj.createnode(34);
	obj.createnode(17);
	obj.createnode(90);
	obj.display();
	cout << '\n' << "This is the original list" << endl;


	ofstream myfile; //opening file to work with 
	myfile.open("LinkedListOutput.txt");

	int selection = 0;
	int selectionTwo = 0;
	int findVal = 0;
	int insertVal = 0;

	while (true) //user input loop
	{
		cout << "This is the menu to interact with the linked list" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "Enter 1 for a check if the LL is empty" << '\n' << "Enter 2 for a report of the size" << '\n' << "Enter 3 to get a value at a position" << '\n' << "Enter 4 to set a value at a position" << '\n' << "Enter 5 to add a value" << '\n' << "Enter 6 to remove a value" << '\n' << "Enter 7 to end program" << endl;
		cin >> selection;

		myfile << "This is the menu to interact with the linked list" << endl;
		myfile << "-------------------------------------------------" << endl;
		myfile << "Enter 1 for a check if the LL is empty" << '\n' << "Enter 2 for a report of the size" << '\n' << "Enter 3 to get a value at a position" << '\n' << "Enter 4 to set a value at a position" << '\n' << "Enter 5 to add a value" << '\n' << "Enter 6 to remove a value" << '\n' << "Enter 7 to end program" << endl;
		

		if (selection == 1)
		{
			cout << "1 if empty, 0 if not: " << endl;
			myfile << "1 if empty, 0 if not: " << endl;
			myfile << obj.isEmpty() << endl;
		}
		if (selection == 2)
		{
			cout << "The size of the linked list is " << endl;
			myfile << "The size of the linked list is " << endl;
			myfile << obj.size() << endl;
		}
		if (selection == 3)
		{
			cout << "Enter a position to find the value there: " << endl;
			myfile << "Enter a position to find the value there: " << endl;
			cin >> findVal;
			myfile << findVal << endl;
			cout << "The value at position " << findVal << " is " << obj.get(findVal) << endl;
			myfile << "The value at position " << findVal << " is " << obj.get(findVal) << endl;
		}
		if (selection == 4)
		{
			cout << "Enter a position to set the value there: " << endl;
			myfile << "Enter a position to set the value there: " << endl;
			cin >> findVal;
			myfile << findVal << endl;

			cout << "Enter the value to set there: " << endl;
			myfile << "Enter the value to set there: " << endl;
			cin >> insertVal;
			myfile << insertVal << endl;
			cout << "Reterning old value: " << obj.set(findVal, insertVal) << endl;
			myfile << "Reterning old value: " << obj.set(findVal, insertVal) << endl;
		}
		if (selection == 5)
		{
			cout << "Please enter 1 to insert at the beginning, 2 to insert at the end, or 3 to insert at a position: " << endl;
			cin >> selectionTwo;

			myfile << "Please enter 1 to insert at the beginning, 2 to insert at the end, or 3 to insert at a position: " << endl;
			myfile << selectionTwo << endl;

			if (selectionTwo == 1)
			{
				cout << "Enter the value to add: " << endl;
				cin >> insertVal;

				myfile << "Enter the value to add: " << endl;
				myfile << insertVal;

				cout << obj.addStart(insertVal) << endl;

				obj.display();
				cout << endl;
				myfile << endl;
			}
			if (selectionTwo == 2)
			{
				cout << "Enter the value to add: " << endl;
				cin >> insertVal;

				myfile << "Enter the value to add: " << endl;
				myfile << insertVal << endl;

				obj.createnode(insertVal);
				obj.display();
			}
			if (selectionTwo == 3)
			{
				cout << "Enter the value to add: " << endl;
				cin >> insertVal;
				myfile << "Enter the value to add: " << endl;
				myfile << insertVal << endl;

				cout << "Enter the position to add at: " << endl;
				cin >> findVal;
				myfile << "Enter the position to add at: " << endl;
				myfile << findVal << endl;

				cout << obj.addPos(findVal, insertVal) << endl;

				obj.display();
			}
		}
		if (selection == 6)
		{
			cout << "Please enter 1 to delete at the beginning, 2 to delete at the end, or 3 to delete at a position: " << endl;
			cin >> selectionTwo;

			myfile << "Please enter 1 to delete at the beginning, 2 to delete at the end, or 3 to delete at a position: " << endl;
			myfile << selectionTwo;

			if (selectionTwo == 1)
			{
				cout << obj.deleteStart() << endl;
				obj.display();
			}
			if (selectionTwo == 2)
			{
				cout << obj.deleteLast() << endl;
				obj.display();
			}
			if (selectionTwo == 3)
			{
				cout << "Enter the position to delete that node: " << endl;
				cin >> findVal;
				myfile << "Enter the position to delete that node: " << endl;
				myfile << findVal;

				cout << obj.deletePos(findVal) << endl;

				obj.display();
			}

		}
		if (selection == 7)
		{
			break;
		}
	}

	cout << "The total counter was" << obj.displayCounter() << endl;
	myfile << "The total counter was" << obj.displayCounter() << endl;

	cout << "Ending program" << endl;
	myfile << "Ending program" << endl; //ending message and closing file 
	system("pause");
	myfile.close();
	return 0;
}
