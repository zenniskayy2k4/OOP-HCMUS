#include "CIntArray.h"
#include <iostream>
using namespace std;
//Ho va ten: Bui Le Anh Khoa
//MSSV: 22120160
//Lop: 22_3, ca N3
int main() {
	int n = 0; cout << "Enter the amount of element in array: ";
	cin >> n;
	CIntArray a(n);
	a.InputArray();
	cout << "Default Array: "; a.OutputArray(); cout << endl;
	
	CIntArray UniqueArray = a.Remove();
	cout << "Array after remove duplicate element(s): "; UniqueArray.OutputArray(); cout << endl;
	
	cout << "Input the pos delete: "; int pos; cin >> pos;
	CIntArray RemoveIndexFromArray = a.Remove(pos);
	cout << "Array after delete index at the " << pos << " position: "; RemoveIndexFromArray.OutputArray(); cout << endl;
	
	cout << "Input the numbers of element to delete from array: "; int numbers; cin >> numbers;
	cout << "Input the starting postion to delete: "; int k; cin >> k;
	CIntArray RemoveNFromK = a.Remove(numbers, k);
	cout << "Array after remove " << numbers << " element(s) from element at " << k << " postion: ";
	RemoveNFromK.OutputArray(); cout << endl;



	int old_val = 0, new_val = 0;
	cout << "Enter old value to replace: "; cin >> old_val;
	cout << "Enter new value: "; cin >> new_val;
	CIntArray ReplaceArray = a.Replace(old_val, new_val);
	cout << "Array after replacing " << old_val << " with " << new_val << ": ";
	ReplaceArray.OutputArray(); cout << endl;

	int val_add_head; cout << "Enter the value you want to add at the head of the array: "; cin >> val_add_head;
	CIntArray a_add_head = a.AddHead(val_add_head);
	cout << "Array after adding at head: "; a_add_head.OutputArray(); cout << endl;

	int val_add_tail; cout << "Enter the value you want to add at the tail of the array: "; cin >> val_add_tail;
	CIntArray a_add_tail = a.AddTail(val_add_tail);
	cout << "Array after adding at tail: "; a_add_tail.OutputArray(); cout << endl;

	int val_insert = 0, index_insert = 0; cout << "Enter value you want to insert into array: "; cin >> val_insert;
	cout << "Enter the position of the element you want to insert to the array: "; cin >> index_insert;
	CIntArray InsertArray = a.Insert(val_insert, index_insert);
	cout << "Array after inserting " << val_insert << " at the " << index_insert << " postition: ";
	InsertArray.OutputArray(); cout << endl;


	cout << "Max element in array: " << a.Max() << endl;
	cout << "Min element in array: " << a.Min() << endl;
	
	CIntArray AscendingArray = a.Ascending();
	cout << "Array after sorting ascending: "; AscendingArray.OutputArray(); cout << endl;
	
	CIntArray DescendingArray = a.Descending();
	cout << "Array after sorting descending: "; DescendingArray.OutputArray(); cout << endl;

	cout << (a.IsSymmetry() ? "Array is symmetric" : "Array is not symmetric") << endl;
	
	CIntArray MoveForwardArray_1 = a.MoveForward();
	cout << "Array after moving forward by 1 unit: "; MoveForwardArray_1.OutputArray(); 
	cout << endl;
	
	int n_move_forward_step = 0; cout << "Enter step to move forward: "; cin >> n_move_forward_step;
	CIntArray MoveForwardArray_n = a.MoveForward(n_move_forward_step);
	cout << "Array after moving forward by " << n_move_forward_step << " unit(s): "; 
	MoveForwardArray_n.OutputArray(); cout << endl;
	
	CIntArray MoveBehindArray_1 = a.MoveBehind();
	cout << "Array after moving behind by 1 unit: "; MoveBehindArray_1.OutputArray(); 
	cout << endl;
	
	int n_move_behind_step; cout << "Enter step to move behind: "; cin >> n_move_behind_step;
	CIntArray MoveBehindArray__n = a.MoveBehind(n_move_behind_step);
	cout << "Array after moving behind by " << n_move_behind_step << " unit(s): "; 
	MoveBehindArray__n.OutputArray(); cout << endl;
	
	CIntArray InvertArray = a.Invert();
	cout << "Inverted Array: "; InvertArray.OutputArray(); cout << endl;
	
	int key = 0; cout << "Enter value of key to find appearance frequency: "; cin >> key;
	int frequencyKey = a.Appearance(key);
	cout << "Appearance frequency of " << key << " in the array: " << frequencyKey << endl;
	return 0;
}