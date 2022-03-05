#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>
#include<conio.h>
using namespace std;
///////////////////////////////////Declaring variable

///////////////////////////////////
class admin
{
	string Username="Jaysh";
	string Password="khan";
public:
	string get_Username();
	string get_password();
};
//////////////////////////////////

class customer
{
private:
	string Username;
	string Password;
	string address;
	int no_of_orders=0;
public:
	void New_customer();
	string Get_username();
	void Set_Username(string);
	string Get_password();
	void Set_password(string);
	string get_address();
};
////////////////////////////////////
class Book
{
private:
	string book_name;
	string Authur_name;
	int quantity;
	double price;
	int sold_quantity=0;
public:
	void Sold_Quantity();
	int get_sold_Quanitity();
	void insert();
	string get_name();
	void Set_name(string);
	void set_authur(string);
	string get_aunthurname();
	double get_price();
	void set_sold_quantity(int);
	void set_price(double);
	void set_quantity(int);
	int get_quantity();
	void display();
};
//////////////////////////////////
class Bookshop
{
public:
	Book B[100];
	void Buy_Book(int,int*);
	void Update_Book(int);
	void Add_Book(int*);
	void Remove_Book(int,int*);
	int Search_Book(int);
	void Display_Books(int);
	void found_book(int);
};
/////////////////////////////////
