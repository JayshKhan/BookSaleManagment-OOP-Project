#include"Classes.h"

//////////////////////////////////////////////admin//////////////////////////////////////////////////////

string admin::get_Username()
{
	return Username;
}
string admin::get_password()
{
	return Password;
}

///////////////////////Customer////////////////////////////>
string customer::Get_username()
{
	return Username;
}
void customer::Set_Username(string un)
{
	this->Username = un;
}
string customer::Get_password()
{
	return Password;
}
void customer::Set_password(string p)
{
	this->Password = p;
}
string customer::get_address()
{
	return address;
}
void customer::New_customer()
{
	cout << "\t\tEnter Your Username: ";
	getline(cin, Username);
	cout << "\t\tCreate A New Password: ";
	getline(cin, Password);
	cout << "\t\tEnter Address: ";
	getline(cin, address);
	system("cls");

}
/////////////////////////Book ///////////////////////////////>
void Book::insert()
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
			"     Add Books        "
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
	cout << "\t\tEnter Book Name: ";
	getline(cin, book_name);
	
	for (int i = 0; i < book_name.length(); i++)
	{
		if (book_name[i] == 32)
		{
			book_name[i] = 95;
		}
	}
	Set_name(book_name);
	cout << "\t\tEnter Authur Name: ";
	getline(cin, Authur_name);

	set_authur(Authur_name);
	for (int i = 0; i < Authur_name.length(); i++)
	{
		if (Authur_name[i] == 32)
		{
			Authur_name[i] = 95;
		}
	}
	retryQ:
	cout << "\t\tEnter quantity: ";
	cin >> quantity;
	if (cin.fail()) {
		cin.ignore();
		cin.clear();
		cout << "Enter A Valid Quantity: ";
		Sleep(500);
		goto retryQ;
	}
	retryP:
	cout << "\t\tEnter Price Per Book: ";
	cin >> price;
	if (cin.fail()) {
		cin.ignore();
		cin.clear();
		cout << "Enter A Valid Price: ";
		Sleep(500);
		goto retryP;
	}
	cin.ignore();
}
string Book::get_name()
{
	return book_name;
}
void Book::display()
{
	cout << "***************************************************" << endl;
	cout << " Book Name:   " << book_name << endl
		<< " Authur Name: " << Authur_name << endl
		<< " Book Price:  " << price << endl
		<< " Quantity:    " << quantity << endl
		<< " Sold QUantity " << sold_quantity << endl;
	cout << "***************************************************" << endl;
}
string Book::get_aunthurname()
{
	return Authur_name;
}
double Book::get_price()
{
	return price;
}
int Book::get_quantity()
{
	return quantity;
}
void Book::Sold_Quantity()
{
	this->sold_quantity = sold_quantity + 1;
	this->quantity = quantity - 1;
}
void Book::set_price(double p)
{
	this->price = p;
}
void Book::set_quantity(int q)
{
	this->quantity = q;
}
void Book::Set_name(string n)
{
	this->book_name = n;
}
void Book::set_authur(string a)
{
	this->Authur_name = a;
}
int Book::get_sold_Quanitity()
{
	return sold_quantity;
}
void Book::set_sold_quantity(int q)
{
	this->sold_quantity = q;
}
////////////////////////////Book Shop////////////////////////////////////////
void Bookshop::Add_Book(int* Book_Index)
{
	B[*Book_Index].insert();
	*Book_Index=*Book_Index+1;
}
void Bookshop::Remove_Book(int Index,int* Total_Book)
{
	for (int i = Index; i < *Total_Book; i++)
	{
		if (i + 1 <= *Total_Book - 1)
		{
			B[i] = B[i + 1];
		}
	}
	*Total_Book = *Total_Book - 1;
	cout << "\t\tBook Removed Successfully" << endl;
	Sleep(1000);
}
int Bookshop::Search_Book(int Total_Books)
{
	char CH;
	int IndexArray[100];
	{	system("cls");
	cout << endl << endl << endl;
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
	cout << "\t\tA. Search By Book Name" << endl;
	cout << "\t\tB. Search By Author Name" << endl;
	CH = _getch();
	if (CH == 'a' || CH == 'A')
	{
		bool bookfoundcheck = false;
		cout << "\t\tEnter Book Name: ";
		string Temp_Name;
		getline(cin, Temp_Name);
		for (int i = 0; i < Temp_Name.length(); i++)
		{
			if (Temp_Name[i] == 32)
			{
				Temp_Name[i] = 95;
			}
		}

		for (int i = 0; i < Total_Books; i++)
		{
			string bookname = B[i].get_name();
			if (bookname == Temp_Name)
			{
				bookfoundcheck = true;
				cout << "***************************************************************************"
					<< endl;
				cout << "Book Name: " << B[i].get_name() << " || "
					<< " Authur Name: " << B[i].get_aunthurname() << " || "
					<< " Book Price: " << B[i].get_price() << " || "
					<< " Quantity: " << B[i].get_quantity() << endl;
				cout << "***************************************************************************"
					<< endl;
				cout << "Press C to confirm " << endl;
				char C;
				C = _getch();
				if (C == 'c' || C == 'C')
				{
					return i;
				}
			}
		}
		if (bookfoundcheck == false)
		{
			return -1;
		}
	}
	else
	{
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
	}
		cout << endl;
		cout << "\t\tEnter Auther's name: ";
		int Authurcheck = 0;
		string AuthurSearch;
		getline(cin, AuthurSearch);
		for (int i = 0; i < AuthurSearch.length(); i++) {
			if (AuthurSearch[i] == 32) {
				AuthurSearch[i] = 95;
			}
		}
		for (int i = 0; i < Total_Books; i++) {
			if (AuthurSearch == B[i].get_aunthurname()) {
				cout << "***************************************************************************"
					<< endl;
				cout <<i<<": "<< "Book Name: " << B[i].get_name()<< " || "
					<< " Authur Name: " << B[i].get_aunthurname() << " || "
					<< " Book Price: " << B[i].get_price() << " || "
					<< " Quantity: " << B[i].get_quantity() << endl;
				cout << "***************************************************************************"
					<< endl;
				IndexArray[Authurcheck] = i;
				Authurcheck++;
				
			}
		}
		if (Authurcheck != 0) {
			cout << "***************************************************************************"
				<< endl;
			cout << Authurcheck <<
				" Books Found By the Authur's Name: " << endl;
			cout << "***************************************************************************"
				<< endl;
			cout << "\n\tWhich One You Want To Buy? Enter The No Written Before Book Name: ";
		retryAuthor:
			int Index;
			cin >> Index;
			cin.ignore();
			bool BookIndexCheck = true;
			for (int k = 0; k < Authurcheck; k++)
			{
				if (Index == IndexArray[k])
				{
					cout << "***************************************************************************"
						<< endl;
					cout << Index << ": " << "Book Name: " << B[Index].get_name() << " || "
						<< " Authur Name: " << B[Index].get_aunthurname() << " || "
						<< " Book Price: " << B[Index].get_price() << " || "
						<< " Quantity: " << B[Index].get_quantity() << endl;
					cout << "***************************************************************************"
						<< endl;
					cout << "Press C to confirm " << endl;
					char C;
					C = _getch();
					if (C == 'c' || C == 'C')
					{
						return k;
					}
				}
				if(BookIndexCheck) {
					cout << "\n\t\tGive the correct input: Retry " << endl;
					goto retryAuthor;
				}
			}
			
			
		}

		if (Authurcheck == 0) {
			cout << "No Book Found Under The Given Authur name: "
				<< endl;
			return -1;
		}
		system("pause");
	}
	
	
}
/*int Bookshop::Search_Sold_Books(string Name)
	for (int i = 0 ;i < 100; i++)
	{
		if (SoldBook[i].get_name() == Name)
		{
			return i;
		}
	}
	return -1;
}*/
void Bookshop::Display_Books(int Total_Books)
{
	for (int i = 0; i < Total_Books; i++)
	{
		B[i].display();
	}
}
void Bookshop::found_book(int index)
{
	cout << "***************************************************" << endl;
	cout << " \t\t\tBook Name:   " << B[index].get_name() << endl
		<< " \t\t\tAuthur Name: " << B[index].get_aunthurname() << endl
		<< " \t\t\tBook Price:  " << B[index].get_price() << endl
		<< " \t\t\tQuantity:    " << B[index].get_quantity() << endl
		<< " \t\t\tSold Quanity " << B[index].get_sold_Quanitity() << endl;
	cout << "***************************************************" << endl;
}

void Bookshop::Buy_Book(int Book_Index,int* total_Sold_Books)
{
	B[Book_Index].Sold_Quantity();             //to increment in sold quantity and decrement in actual quantity
	*total_Sold_Books = *total_Sold_Books + 1;
  

}

void Bookshop::Update_Book(int Book_index)
{
	cout << "\t\tWhat You Want To Update?\n\t\t A. Quantity \n\t\t B.Price ";
	char choice;
	cin >> choice;
	if (choice == 'a' || choice == 'A')
	{
		retryQ2:
		cout << "\t\tEnter New Quantity: ";
		int Temp_Q;
		cin >> Temp_Q;
		if (cin.fail()) {
			cin.ignore();
			cin.clear();
			cout << "Enter A Valid Quantity: ";
			Sleep(500);
			goto retryQ2;
		}
		B[Book_index].set_quantity(Temp_Q);
	}
	else if (choice == 'b' || choice == 'B')
	{
		retryP2:
		cout << "\t\tEnter New Price: ";
		double Temp_P;
		cin >> Temp_P;
		if (cin.fail()) {
			cin.ignore();
			cin.clear();
			cout << "\t\tEnter A Valid Price: ";
			Sleep(500);
			goto retryP2;
		}
		B[Book_index].set_price(Temp_P);
	}
	else
		cout << "Wrong Choice" << endl;
}