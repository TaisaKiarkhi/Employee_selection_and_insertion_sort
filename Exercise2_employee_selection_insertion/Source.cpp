#include <iostream>
using namespace std;
#include <vector>

class EmInfo {
public:
	int ID;
	string First_Name;
	string Last_Name;

	EmInfo(int ID, string first="none", string last="none") {
		this->ID = ID;
		First_Name = first;
		Last_Name = last;
	}
};

class EmployeeList {
public:
	vector<EmInfo> list;

	void selection_sort(); 

	template <typename T>
	void swap_fun(T&a, T&b);
	void print();
	void insertion_sort();


};



int main() {

	EmInfo a(64, "Alex", "Last Name");
	EmInfo b(25, "Nina", "Last Name");
	EmInfo c(12, "Maria", "Last Name");
	EmInfo d(22, "Harald", "Last Name");
	EmInfo e(11, "Ola", "Last Name");
	EmInfo f(88, "Ol", "Last Name");
	EmInfo g(2, "O", "Last Name");
	EmInfo dd(0, "Olaaaaaa", "Last Name");
	EmInfo cc(4, "Olaaaaaaaaaaaaa", "Last Name");
	EmInfo ee(43, "OOOOla", "Last Name");

	EmployeeList list;
	list.list.push_back(a);
	list.list.push_back(b);
	list.list.push_back(c);
	list.list.push_back(d);
	list.list.push_back(e);
	list.list.push_back(f);
	list.list.push_back(g);
	list.list.push_back(dd);
	list.list.push_back(cc);
	list.list.push_back(ee);

	/*list.selection_sort();*/
	list.insertion_sort();
	list.print();



	return 0;
}

void EmployeeList::selection_sort()
{
	
	for (int i = 0; i < list.size(); i++) {
		int temp_small_ind{ i };
		for (int j=i; j < list.size(); j++) {

			
                    if (list[j].ID < list[temp_small_ind].ID) {
				 
					temp_small_ind = j ; //store the smallest value of the array so far
				
			} 
			
		}
		swap_fun(list[i].ID, list[temp_small_ind].ID);
	
	}
}

void EmployeeList::print()
{
	for (int i = 0; i < list.size(); i++) {
		cout << list[i].ID << " ";
	}
}

void EmployeeList::insertion_sort()
{
	for (int i = 0; i < list.size(); i++) {
		int temp{ i };
		for (int j = i; j >= 0; j--) {


			if (j + 1 > list.size()-1)
				break;

			else if (list.at(j).ID > list.at(j + 1).ID) {
				temp = j + 1;
				swap_fun(list.at(j).ID, list.at(j+1).ID);
			}
			
		}
	}
}

template<typename T>
void EmployeeList::swap_fun(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
