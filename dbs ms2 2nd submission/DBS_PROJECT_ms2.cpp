#include<iostream>
#include<iomanip>
#include<occi.h>

using oracle::occi::Environment;
using oracle::occi::Connection;
using namespace oracle::occi;
using namespace std;



struct Customer
{
	int custID;
	string firstName;
	string lastName;
	string address;
	string city;
	string country;
	int branchId;
	int accNum;
	int loanNum;
};

int findCustomer(Connection* conn, int customerId);
void displayCustomer(Connection* conn, struct Customer customer);
void displayAllCustomer(Connection* conn);

int main(void)
{
	Environment* env = nullptr;
	Connection* conn = nullptr;
	string str;
	string usr = "dbs211_221f27";
	string pass = "28349213";
	string srv = "myoracle12c.senecacollege.ca:1521/oracle12c";
	struct Customer customer;
	try
	{
		env = Environment::createEnvironment(Environment::DEFAULT);
		conn = env->createConnection(usr, pass, srv);
		cout << "Database Connection is successful!" << endl;
		cout << "Project Milestone 2" << endl;
		cout << "COURSE: DBS211" << endl;
		cout << "PURPOSE: DBS211 PROJECT MILESTONE - 2" << endl;
		cout << "GROUP: 14" << endl;
		cout << "GROUP MEMBER: Jay Pravinkumar Chaudhari, Yash Vipulkumar Shah, Bhavy Piyushkumar Patel" << endl;
		cout << "NAME: Jay Pravinkumar Chaudhari" << endl;
		cout << "STUDENT ID: 147268205" << endl;
		cout << "EMAIL: jpchaudhari@myseneca.ca" << endl << endl;
		cout << "NAME: Yash Vipulkumar Shah" << endl;
		cout << "STUDENT ID: 103985214" << endl;
		cout << "EMAIL: yvshah@myseneca.ca" << endl << endl;
		cout << "NAME: Bhavya Piyushkumar Patel " << endl;
		cout << "STUDENT ID: 121048219" << endl;
		cout << "EMAIL: bppatel16@myseneca.ca" << endl << endl;
		
		int input = 0;
		do
		{
			cout << "\nHR MENU";
			cout << "\n1. Find Customer";
			cout << "\n2. Display Customer";
			cout << "\n3. Display All Customer";
			cout << "\n4. Display All Branch";
			cout << "\n5. Display All Checking Account";
			cout << "\n6. Display All Saving Account";
			cout << "\n7. Display All Loan";
			cout << "\n8. Display All Payment";
			cout << "\n9. Display All Employee";
			cout << "\n10. Exit";
			cout << "\n Enter Your Choice: ";
			cin >> input;
			if (input == 1)
			{
				cout << "\n Entering choice to find an customer";
				int cust;
				cout << "\n Enter Customer Number: ";
				cin >> cust;
				if (findCustomer(conn, cust) == 1)
				{
					cout << "\n Yes the Customer Number data is there in the database\n";
				}
				else
				{
					cout << "\nSORRY! Invalid Customer Number\n";
				}
			}
			else if (input == 2)
			{
				cout << "\nEntering choice to display an Customer";
				displayCustomer(conn, customer);
			}
			else if (input == 3)
			{
				cout << "\nEntering choice to display all customers\n";
				displayAllCustomer(conn);
			}
		} while (input != 10);
	
		Statement* stmt = conn->createStatement();
		ResultSet* rs = stmt->executeQuery("SELECT customer_id, customer_fname, customer_lname, customer_address, customer_city, customer_country, branch_id, account_number, loan_number FROM customer ORDER BY customer_id");
		
		conn->terminateStatement(stmt);
		env->terminateConnection(conn);
		Environment::terminateEnvironment(env);
	}
	catch (SQLException& sqlExcp)
	{
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}
	return 0;
}



int findCustomer(Connection * conn, int customerId){ 
	Statement* stmt = conn->createStatement();
	ResultSet* rs = stmt->executeQuery("SELECT customer_id, customer_fname, customer_lname, customer_address, customer_city, customer_country, branch_id, account_number, loan_number FROM customer WHERE customer_id =" + to_string(customerId));
	if (rs->next())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void displayCustomer(Connection* conn, Customer customer)
{
	int ecode;
	bool correctCode = false;
	do
	{
		cout << "\nEnter Customer ID: ";
		cin >> ecode;
		if (!cin || findCustomer(conn, ecode) != 1)
		{
			correctCode = false;
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\nInvalid Customer number\n";
		}
		else
		{
			correctCode = true;
			cout << "\nValid Input";
			cout << "\nSearch in table ..." << endl;
			try
			{
				Statement* stmt2 = conn->createStatement();
				ResultSet* rs2 = stmt2->executeQuery("SELECT customer_id, customer_fname, customer_lname, customer_address, customer_city, customer_country, branch_id, account_number, loan_number FROM customer WHERE customer_id=" + to_string(ecode));
				while (rs2->next())
				{
					cout << "\n-------------- Customer Information --------------" << endl;
					
					customer.custID = rs2->getInt(1);
					customer.firstName = rs2->getString(2);
					customer.lastName = rs2->getString(3);
					customer.address = rs2->getString(4);
					customer.city = rs2->getString(5);
					customer.country = rs2->getString(6);
					customer.branchId = rs2->getInt(1);
					customer.accNum = rs2->getInt(1);
					customer.loanNum = rs2->getInt(1);
					cout << "\n";
					cout << "Customer Id: ";
					cout << customer.custID;

					cout << "\n";
					cout << "Customer First Name: ";
					cout << customer.firstName;

					cout << "\n";
					cout << "Customer Last Name: ";
					cout << customer.lastName;

					cout << "\n";
					cout << "Customer address: ";
					cout << customer.address;

					cout << "\n";
					cout << "Customer city: ";
					cout << customer.city;

					cout << "\n";
					cout << "Customer country: ";
					cout << customer.country;

					cout << "\n";
					cout << "Customer branch id: ";
					cout << customer.branchId;

					cout << "\n";
					cout << "Customer account Number: ";
					cout << customer.accNum;

					cout << "\n";
					cout << "Custome Loan num: ";
					cout << customer.loanNum << endl;
				}
			}
			catch (SQLException& sqlExcp)
			{
				cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
			}//check this line 
		}
	} while (correctCode == false); //check this line 
};


void displayAllCustomer(Connection * conn)
{
	try
	{
		Statement* stmt3 = conn->createStatement();
		ResultSet* rs2 = stmt3->executeQuery("SELECT customer_id, customer_fname, customer_lname, customer_address, customer_city, customer_country, branch_id, account_number, loan_number FROM customer");
		cout.width(10);
		cout.setf(ios::left);
		cout << "#custId";
		cout.unsetf(ios::left);
		cout << " ";
		cout.width(15);
		cout.setf(ios::left);
		cout << "FirstName";
		cout.width(12);
		cout.setf(ios::left);
		cout << "LastName";
		
		cout.width(14);
		cout.setf(ios::left);
		cout << "address";
		//cout << " ";
		cout.width(20);
		cout.setf(ios::left);
		cout << "city";
		//cout << " ";
		cout.width(30);
		cout.setf(ios::left);
		cout << "country";
		cout.width(17);
		cout.setf(ios::left);
		cout << "branch id";
		cout.width(12);
		cout.setf(ios::left);
		cout << "account number";
		cout.width(15);
		cout.setf(ios::left);
		cout << "loan number" << endl;
		cout.unsetf(ios::left);
		Customer cust;
		while (rs2->next())
		{
			cust.custID = rs2->getInt(1);
			cust.firstName = rs2->getString(2);
			cust.lastName = rs2->getString(3);
			cust.address = rs2->getString(4);
			cust.city = rs2->getString(5);
			cust.country = rs2->getString(6);
			cust.branchId = rs2->getInt(1);
			cust.accNum = rs2->getInt(1);
			cust.loanNum = rs2->getInt(1);

			cout << " ";
			cout.width(10);
			cout.setf(ios::left);
			cout << cust.custID;
			cout.unsetf(ios::left);
			cout.width(15);
			cout.setf(ios::left);
			cout << cust.firstName;
			cout.unsetf(ios::left);
			
			cout.width(12);
			cout.setf(ios::left);
			cout << cust.lastName;
			cout.unsetf(ios::left);
			
			cout.width(14);
			cout.setf(ios::left);
			cout << cust.address;
			cout.unsetf(ios::left);
			
			cout.width(20);
			cout.setf(ios::left);
			cout << cust.city;
			cout.unsetf(ios::left);
			
			cout.width(30);
			cout.setf(ios::left);
			cout << cust.country;
			cout.unsetf(ios::left);
			
			cout.width(17);
			cout.setf(ios::left);
			cout << cust.branchId;
			cout.unsetf(ios::left);
			
			cout.width(12);
			cout.setf(ios::left);
			cout << cust.accNum;
			cout.unsetf(ios::left);
	
			cout.width(15);
			cout.setf(ios::left);
			cout << cust.loanNum;
			cout.unsetf(ios::left);
			cout << endl;
		}
	}
	catch (SQLException& sqlExcp)
	{
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}
}
