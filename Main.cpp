#include"Classes.h"

using namespace std;
/////////////////////////////////Function Decleration////////////////////////
void Admin_Login();
void User_Login();
void Create_account();
int Customer_search(string);
void Customer_Page(int);
void Admin_page();
void Save_Customer_Data();
void Load_Customer_Data();
void Save_Book_Datas();
void Update_Saved_data();
void Load_Books_Data();
int AuthurBookCount(string Authur);
void AuthurShowBooks(string Authur);
//////////////////////////////////////////////////////////////////////////////
ofstream Save_Book_data;
ifstream Load_Book_data;
ofstream Save_Cust_data;
ifstream Load_Cust_data;
ofstream Save_order_data;
ifstream Load_Order_data;
///////////////////////////////Variables//////////////////////////////////////
customer Cust[100];
Book Boo;
admin ad;
int Cust_index = 0;
int Book_Index=0;  //always send address
int sold_Book_index = 0;
Bookshop Books;
struct order
{
	int CustomerIn;
	int BookIn;
};
order Ord[100];
int OrderIndex = 0;
/////////////////////////////////////////////////////////////////////////////
bool Load_Check = 1;
/////////////////////////////////////////////////////////////////////////////
int main()
{
	Load_Books_Data();
	if (Load_Check)
	{
		Load_Books_Data();
		Load_Customer_Data();
		Load_Check = 0;
	}
	
	do {
		system("color b2");
		system("cls");
		{cout << endl << endl << endl;
		cout << "\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
			"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
			"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
			"\xdb\xdb\xdb\n";
		cout << "\t\xdb\xdb\xdb\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
			"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
			"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
			"\xdb\xdb\xdb\n";
		cout << "\t\xdb\xdb\xdb\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2 "
			"Book Sales management "
			"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xdb\xdb"
			"\xdb\n";
		cout << "\t\xdb\xdb\xdb\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
			"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
			"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
			"\xdb\xdb\xdb\n";
		cout << "\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
			"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
			"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
			"\xdb\xdb\xdb\n";
		cout << endl; }
		cout << "\t\tA. Admin Login" << endl;
		cout << "\t\tB. User Login" << endl;
		cout << "\t\tC. Create Account" << endl;
		char Choice;
		Choice = _getch();
		switch (Choice)
		{
		case 'A':
		case 'a':
		{
			Admin_Login();
			break;
		}
		case 'B':
		case 'b':
		{
			User_Login();
			break;
		}
		case 'C':
		case 'c':
		{
			Create_account();
			break;
		}
		default:
		{
			cout << "Please Enter A valid Answer: " << endl;
			Sleep(500);
			main();
		}
		}
	} while (true);
}
void Admin_Login()
{
	system("cls");
	system("color b2");
	{cout << endl << endl << endl;
	cout << "\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
		"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
		"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
		"\xdb\xdb\xdb\n";
	cout << "\t\xdb\xdb\xdb\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
		"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
		"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
		"\xdb\xdb\xdb\n";
	cout << "\t\xdb\xdb\xdb\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2 "
		"Book Sales management "
		"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xdb\xdb"
		"\xdb\n";
	cout << "\t\xdb\xdb\xdb\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
		"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
		"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
		"\xdb\xdb\xdb\n";
	cout << "\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
		"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
		"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
		"\xdb\xdb\xdb\n";
	cout << endl; }
	retry_Username:
	cout << "\t\tEnter Username: ";
	string User="";
	getline(cin,User);
	if (User == ad.get_Username())
	{
	retry_pass:
		cout << "\t\tEnter Password: ";
		string pass="";
	
		// Password Hiding
		for (int i = 0; true;)
		{
			pass[i] = _getch();
			if (pass[i] == 13)
			{
				break;
			}
			pass.push_back(pass[i]);
			i++;
		
			cout << "*";
			
		}
		if (pass == ad.get_password())
		{
			cout << "\n\n\n\n\n\t\t\t\t\Access Granted";
			Sleep(500);
			Admin_page();
		}
		else
		{
			system("cls");
			system("color b4");
			cout << "\n\n\n\n\n\t\t\t\t\Access Denied";
			Sleep(1000);
			goto retry_pass;
		}
	}
	else
	{
		system("cls");
		system("color b4");
		cout << "\n\n\n\n\n\t\t\t\t\No UserName Found";
		cin.ignore();
		cin.clear();
		Sleep(1000);
		goto retry_Username;

	}
}
void User_Login()
{
	system("cls");
	system("color b2");
	{cout << endl << endl << endl;
	cout << "\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
		"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
		"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
		"\xdb\xdb\xdb\n";
	cout << "\t\xdb\xdb\xdb\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
		"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
		"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
		"\xdb\xdb\xdb\n";
	cout << "\t\xdb\xdb\xdb\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2 "
		"Book Sales management "
		"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xdb\xdb"
		"\xdb\n";
	cout << "\t\xdb\xdb\xdb\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
		"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
		"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
		"\xdb\xdb\xdb\n";
	cout << "\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
		"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
		"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
		"\xdb\xdb\xdb\n";
	cout << endl; }
	cout << "\t\tEnter Your Username: ";
	string UserInput;

	getline(cin, UserInput);
	int Index=Customer_search(UserInput);
	Customer_Page(Index);
}
void Create_account()
{
	system("cls");
	{cout << endl << endl << endl;
	cout << "\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
		"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
		"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
		"\xdb\xdb\xdb\n";
	cout << "\t\xdb\xdb\xdb\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
		"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
		"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
		"\xdb\xdb\xdb\n";
	cout << "\t\xdb\xdb\xdb\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2 "
		"Book Sales management "
		"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xdb\xdb"
		"\xdb\n";
	cout << "\t\xdb\xdb\xdb\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
		"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
		"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
		"\xdb\xdb\xdb\n";
	cout << "\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
		"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
		"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
		"\xdb\xdb\xdb\n";
	cout << endl; }
	Cust[Cust_index].New_customer();
	cout << "\n\n\n\t\t\t\tCustomer Added\n";
	system("pause");
	Save_Customer_Data();
	Cust_index++;
	
	main();
}
int Customer_search(string UserInput)
{
	bool User_Check;
	for (int i = 0; i <Cust_index ; i++)
	{
		User_Check = false;
		string tempUser = Cust[i].Get_username();
		if (tempUser==UserInput)
		{
			retrypass:
			cout << "\t\tEnter Password: ";
		string pass="";
	
		// Password Hiding
		for (int i = 0; true;)
		{
			pass[i] = _getch();
			if (pass[i] == 13)
			{
				break;
			}
			pass.push_back(pass[i]);
			i++;
		
			cout << "*";
			
		}
			string TPass = Cust[i].Get_password();
			if (TPass==pass)
			{
				return i;
			}
			else
			{
				cout << "wrong password: ";
				Sleep(500);
				system("cls");
				cout << "retry password";
				goto retrypass;
			}
		}
		else
		{
			User_Check = true;
		}
	}
	if (User_Check)
	{
		cout << "No user Name Found";
		Sleep(500);
		main();
	}
}

////////////////////////////////////////////////////////////////////////////Welcome Screen Pages//////////////////////////////
void Customer_Page(int Customer_Index)
{
	char choice1;
	do {
		system("cls");
		system("color b2");
		{cout << endl << endl << endl;
		cout << "\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
			"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
			"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
			"\xdb\xdb\xdb\n";
		cout << "\t\xdb\xdb\xdb\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
			"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
			"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
			"\xdb\xdb\xdb\n";
		cout << "\t\xdb\xdb\xdb\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2 "
			"Book Sales management "
			"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xdb\xdb"
			"\xdb\n";
		cout << "\t\xdb\xdb\xdb\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
			"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
			"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
			"\xdb\xdb\xdb\n";
		cout << "\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
			"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
			"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
			"\xdb\xdb\xdb\n";
		cout << endl; }
		cout << "\t\t\t\t Welcome " << Cust[Customer_Index].Get_username() << endl;
		cout << "\t\tA. Buy Book" << endl;
		cout << "\t\tB. Search Book" << endl;
		cout << "\t\tC. Best Selling" << endl;
		cout << "\t\tD. Logout" << endl;
		

		choice1 = _getch();
		switch (choice1)
		{
		case 'A':
		case 'a': {
			system("cls");
			{cout << endl << endl << endl;
			cout << "\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
				"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
				"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
				"\xdb\xdb\xdb\n";
			cout << "\t\xdb\xdb\xdb\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
				"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
				"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
				"\xdb\xdb\xdb\n";
			cout << "\t\xdb\xdb\xdb\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2 "
				"    Buy Books         "
				"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xdb\xdb"
				"\xdb\n";
			cout << "\t\xdb\xdb\xdb\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
				"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
				"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
				"\xdb\xdb\xdb\n";
			cout << "\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
				"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
				"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
				"\xdb\xdb\xdb\n";
			cout << endl; }
			cout << Book_Index;
			int Buy_Book_index = Books.Search_Book(Book_Index);
			if (Buy_Book_index == -1)
			{
				cout << "No Book Found";
			}
			else {
				Books.Buy_Book(Buy_Book_index, &sold_Book_index);
				Ord[OrderIndex].BookIn = Buy_Book_index;
				Ord[OrderIndex].CustomerIn = Customer_Index;
				OrderIndex++;
				Update_Saved_data();
			}
			system("pause");
			break;
		}
		case 'B':
		case 'b': {
			int searched_index = Books.Search_Book(Book_Index);
			cout << "************************************************************" << endl;
			Books.found_book(searched_index);
			cout << "************************************************************" << endl;
			cout << AuthurBookCount(Books.B[searched_index].get_aunthurname()) << " Found By the Same Auther press y to show them all" << endl;
			cout << "************************************************************" << endl;
			char CH;
			CH = _getch();
			if (CH == 'y' || CH == 'Y')
			{
				AuthurShowBooks(Books.B[searched_index].get_aunthurname());
			}
			system("pause");
			break;
		}
		case 'C':
		case 'c': {
			int Max = 0;
			int Indexofbook;
			bool check = true;
			for (int i = 0; i < Book_Index; i++)
			{
				if (Books.B[i].get_sold_Quanitity() > Max)
				{
					Max = Books.B[i].get_sold_Quanitity();
					Indexofbook = i;
					check = false;
				}
			}
			if (check)
			{
				cout << "No Book Found";
			}
			else
			{
				Books.found_book(Indexofbook);
			}
			system("pause");
			break;
		}
		case 'D':
		case 'd': {
			Save_Book_Datas();
		}
		case 'E':
		case 'e': {
			main();
		}
		}
	} while (choice1 != 'D' || choice1 != 'd');
}
void Admin_page()
{
	system("color b2");
	char choice;
	do {
		system("cls");
		{cout << endl << endl << endl;
		cout << "\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
			"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
			"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
			"\xdb\xdb\xdb\n";
		cout << "\t\xdb\xdb\xdb\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
			"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
			"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
			"\xdb\xdb\xdb\n";
		cout << "\t\xdb\xdb\xdb\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2 "
			"Book Sales management "
			"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xdb\xdb"
			"\xdb\n";
		cout << "\t\xdb\xdb\xdb\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
			"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
			"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
			"\xdb\xdb\xdb\n";
		cout << "\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
			"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
			"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
			"\xdb\xdb\xdb\n";
		cout << endl; }
		cout << "\t\t\t\tWelcome " << ad.get_Username() << endl;
		cout << "\n\t\tA. Add Book " << endl;
		cout << "\t\tB. Remove Book" << endl;
		cout << "\t\tC. Search Book" << endl;
		cout << "\t\tD. View Book" << endl;
		cout << "\t\tE. View Order" << endl;
		cout << "\t\tF. View Sold Books" << endl;
		cout << "\t\tG. Out of stock Books" << endl;
		cout << "\t\tH. Update Book" << endl;
		cout << "\t\tI. See Users" << endl;
		cout << "\t\tJ. Log Out" << endl;
		
		choice = _getch();
		switch (choice)
		{
		case 'A':
		case 'a': {
			system("cls");
			Books.Add_Book(&Book_Index);
			Save_Book_Datas();
			break;
		}
		case 'B':
		case 'b': {
			system("cls");
			int To_delete_Index = -1;
			To_delete_Index = Books.Search_Book(Book_Index);
			if (To_delete_Index == -1)
			{
				cout << "No Book Found" << endl;
			}
			Books.Remove_Book(To_delete_Index, &Book_Index);
			break;
		}
		case 'C':
		case 'c': {
			system("cls");
			int Searched_Index = Books.Search_Book(Book_Index);
			if (Searched_Index == -1)
			{
				cout << "No Book Found" << endl;
			}
			else
			Books.found_book(Searched_Index);
			system("pause");
			break;
		}
		case 'D':
		case 'd': {
			system("cls");
			Books.Display_Books(Book_Index);
			system("pause");
			break;
		}

		case 'E':
		case 'e': {
			system("cls");
			
		/*	for (int i = 0; i < OrderIndex; i++)
			{
				int inde = i;
				cout << Cust[Ord[i].CustomerIn].Get_username() << " Ordered Following Books: " << endl;
				Books.found_book(Ord[i].BookIn);
				for (int k = inde + 1; k < OrderIndex; k++)
				{
					if (Ord[inde].CustomerIn == Ord[k].CustomerIn)
					{
						cout << endl;
						Books.found_book(Ord[i + 1].BookIn);
						i++;
						
					}
					k++;
				}
				i++;
			}*/

			for (int i = 0; i < OrderIndex; i++)
			{
				cout << "____________________________________________________________________" << endl;
				cout << Ord[i].CustomerIn<<" "<<Cust[Ord[i].CustomerIn].Get_username() << " ----> Bought -----> " << Books.B[Ord[i].BookIn].get_name()<<endl;
				cout << "____________________________________________________________________" << endl;
			}
			system("pause");
			break;
		}

		case 'F':
		case 'f': {
			system("cls");
			for (int i = 0; i < OrderIndex; i++)
			{
				Books.B[Ord[i].BookIn].display();
			}
			system("pause");
			break;
		}
		case 'G':
		case 'g': {
			system("cls");
			for (int i = 0; i < Book_Index; i++)
			{
				int temp_Quantity = Books.B[i].get_quantity();
				if (temp_Quantity < 5)
				{
					Books.found_book(i);
				}
			}
			system("pause");
			break;
		}
		case 'H':
		case 'h': {
			system("cls");
			int To_Update_Index = Books.Search_Book(Book_Index);
			Books.Update_Book(To_Update_Index);
			Update_Saved_data();
			system("pause");
			break;
		}
		case 'I':
		case 'i': {
			system("cls");
			{cout << endl << endl << endl;
			cout << "\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
				"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
				"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
				"\xdb\xdb\xdb\n";
			cout << "\t\xdb\xdb\xdb\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
				"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
				"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
				"\xdb\xdb\xdb\n";
			cout << "\t\xdb\xdb\xdb\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2 "
				"      User View       "
				"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xdb\xdb"
				"\xdb\n";
			cout << "\t\xdb\xdb\xdb\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
				"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
				"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
				"\xdb\xdb\xdb\n";
			cout << "\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
				"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
				"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
				"\xdb\xdb\xdb\n";
			cout << endl; }
			cout << "*****************************************************************" << endl;
			for (int i = 0; i < Cust_index; i++)
			{
				cout << i + 1 << ". " << Cust[i].Get_username() << endl;
			}
			cout << "*****************************************************************" << endl;
			system("pause");
			break;
		}
		case 'J':
		case 'j': {
			main();
		}
		}
	} while (choice != 'J' || choice != 'j');
	
}

int AuthurBookCount(string Authur) {
	int AuthurCount = 0;
	for (int i = 0; i < Book_Index; i++) {
		if (Authur == Books.B[i].get_aunthurname()) {
			AuthurCount++;
		}
	}
	return AuthurCount;
}
void AuthurShowBooks(string Authur) {
	system("cls");
	{cout << endl << endl << endl;
	cout << "\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
		"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
		"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
		"\n";
	cout << "\t\xdb\xdb\xdb\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
		"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
		"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xdb\xdb\xdb"
		"\n";
	cout << "\t\xdb\xdb\xdb\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2     "
		"Book  Search      "
		"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xdb\xdb\xdb"
		"\n";
	cout << "\t\xdb\xdb\xdb\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
		"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2"
		"\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xdb\xdb\xdb"
		"\n";
	cout << "\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
		"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
		"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
		"\n";
	cout << endl; }
	cout << "\t\tBooks By The Same Authur" << endl;
	for (int i = 0; i < Book_Index; i++) {
		if (Authur == Books.B[i].get_aunthurname()) {
			cout << "***************************************************************************"
				<< endl;
			cout << "Book Name: " << Books.B[i].get_name() << " || "
				<< " Authur Name: " << Books.B[i].get_aunthurname() << " || "
				<< " Book Price: " << Books.B[i].get_price() << " || "
				<< " Quantity: " << Books.B[i].get_price() << endl;
			cout << "***************************************************************************"
				<< endl;
		}
	}
}
////////////////////////////////////////////////////////////////////////////Save Data/////////////////////////////////////////
void Save_Customer_Data()
{
	//Save Customer_Data
	Save_Cust_data.open("Customer.txt",ios::app);
		string TempName = Cust[Cust_index].Get_username();
		string TempPass = Cust[Cust_index].Get_password();
		for (int i = 0; i < TempName.length(); i++)
		{
			if (TempName[i] == 32)
			{
				TempName[i] = 95;
			}
		}
		for (int i = 0; i < TempPass.length(); i++)
		{
			if (TempPass[i] == 32)
			{
				TempPass[i] = 95;
			}
		}
		Save_Cust_data << TempName << endl << TempPass << endl;
		Save_Cust_data.close();
}
void Save_Book_Datas()
{
	Save_Book_data.open("TestBook.txt", ios::app);
	string Bname = Books.B[Book_Index - 1].get_name();
	string Aname = Books.B[Book_Index - 1].get_aunthurname();
	Save_Book_data << endl
		<< Books.B[Book_Index - 1].get_name() << endl
		<< Books.B[Book_Index - 1].get_aunthurname() << endl
		<< Books.B[Book_Index - 1].get_price() << endl
		<< Books.B[Book_Index - 1].get_quantity() << endl
		<< Books.B[Book_Index - 1].get_sold_Quanitity();
	Save_Book_data.close();
}
void Update_Saved_data()/*To Save Everytime User Make Changes in value*/
{
	Save_Book_data.open("TestBook.txt");
	for (int i = 0; i < Book_Index - 1; i++)
	{
		Save_Book_data << endl
			<< Books.B[i].get_name() << endl
			<< Books.B[i].get_aunthurname() << endl
			<< Books.B[i].get_price() << endl
			<< Books.B[i].get_quantity() << endl
			<< Books.B[i].get_sold_Quanitity();
	}
	Save_Book_data.close();
	Save_order_data.open("Order.txt");
	for (int i = 0; i < OrderIndex-1; i++)
	{
		Save_order_data
			<< Ord[i].CustomerIn << endl
			<< Ord[i].BookIn << endl;
	}
	Save_order_data.close();

}
///////////////////////////////////////////////////////////////////////////Load Data/////////////////////////////////////////
void Load_Books_Data()
{
	Book_Index = 0;
	OrderIndex = 0;
	Load_Book_data.open("TestBook.txt");
	for (int i = 0; !Load_Book_data.eof(); i++)
	{
		string Bname, Aname;
		double price;
		int Quantity, sold_quantity;
		Load_Book_data >> Bname;
		Load_Book_data >> Aname;
		Load_Book_data >> price;
		Load_Book_data >> Quantity;
		Load_Book_data >> sold_quantity;
		Books.B[i].Set_name(Bname);
		Books.B[i].set_authur(Aname);
		Books.B[i].set_price(price);
		Books.B[i].set_quantity(Quantity);
		Books.B[i].set_sold_quantity(sold_quantity);
		Book_Index++;
	}
	Load_Book_data.close();
	Load_Order_data.open("Order.txt");
	for (int i = 0; !Load_Order_data.eof(); i++)
	{
		Load_Order_data >> Ord[i].CustomerIn;
		Load_Order_data >> Ord[i].BookIn; 
		if (!Load_Order_data.eof()) {
			OrderIndex++;
		}
	}
	Load_Order_data.close();
	/*//Arranging
	for (int i = 0; i < OrderIndex; i++)
	{
		for (int k = i+1; k <OrderIndex ; k++)
		{
			if (Ord[i].CustomerIn > Ord[k].CustomerIn)
			{
				order temp = Ord[i];
				Ord[i] = Ord[k];
				Ord[k] = Ord[i];
			}
		}
	}*/
}
void Load_Customer_Data()
{
	//load Customeer data
	Load_Cust_data.open("Customer.txt");
	for (int i = 0;! Load_Cust_data.eof(); i++)
	{
		string TempName;
		string TempPass;
		Load_Cust_data >> TempName;
		Load_Cust_data >> TempPass;
		Cust[i].Set_Username(TempName);
		Cust[i].Set_password(TempPass);
		Cust_index++;
	}
	Load_Cust_data.close();
}
