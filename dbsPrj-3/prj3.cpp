/******************************************************************************************

Group 14 :Online Banking System
Members :
Name: Jay Chaudhari Email: jpchaudhari@myseneca.ca			  Student Id: 147268205
Name: Bhavy Patel   Email: bppatel16@myseneca.ca			  Student Id: 121048219
Name:Yash Shah		Email: yvshah@myseneca.ca			      Student Id: 103985214
Milestone 2
DATE: 02-04-2022

*******************************************************************************************/

#include<iostream>
#include<iomanip>
#include<occi.h>

using oracle::occi::Environment;
using oracle::occi::Connection;
using namespace oracle::occi;
using namespace std;


//******************************************************************************************

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
void insertCustomer(Connection* conn, Customer* cus);
void updateCustomer(Connection* conn, int loanNum);
void deleteCustomer(Connection* conn, int customerID);

//******************************************************************************************

struct Employee
{
	int empId;
	string name;
	string empNum;
	int branchId;
};

int findEmployee(Connection* conn, int empId);
void displayEmployee(Connection* conn, struct Employee employee);
void displayAllEmployee(Connection* conn);
void insertEmployee(Connection* conn, Employee* emp);
void deleteEmployee(Connection* conn, int employeeID);
void updateEmployee(Connection* conn, int employeeID);

//******************************************************************************************

struct Account
{
	int accNum;
	string balance;
	string date;
	string accType;
	int userId;
	string pass;
};
int findAccount(Connection* conn, int acc);
void displayAccount(Connection* conn, Account account);
void displayAllAccount(Connection* conn);
void insertAccount(Connection* conn, Account* acc);
void updateAccount(Connection* conn, int accNum);
void deleteAccount(Connection* conn, int accNum);

//******************************************************************************************

int main(void)
{
	Environment* env = nullptr;
	Connection* conn = nullptr;
	string str;
	string usr = "dbs211_221f27";
	string pass = "28349213";
	string srv = "myoracle12c.senecacollege.ca:1521/oracle12c";
	struct Customer customer;
	struct Employee employee;
	struct Account account;
	try
	{
		env = Environment::createEnvironment(Environment::DEFAULT);
		conn = env->createConnection(usr, pass, srv);

		cout << "GROUP 14 || DBS211NFF - NFFL || DATE: 02 - 04 - 2022 ||  " << endl;
		cout << "Name: Jay Chaudhari\tEmail: jpchaudhari@myseneca.ca\tStudent Id: 147268205\nName: Yash Shah       \tEmail: yvshah@myseneca.ca\tStudent Id: 103985214\nName: Bhavy Patel\tEmail: bppatel16@myseneca.ca\tStudent Id: 121048219" << endl;
		int input = 0;
		do
		{
			cout << "\n\t\t\t\t|=====================================|";
			cout << "\n\t\t\t\t| WELCOME TO OUR ONLINE BANKING SYSTEM|";
			cout << "\n\t\t\t\t|                                     |";
			cout << "\n\t\t\t\t|=====================================|";
			cout << "\n\t\t\t\t| Select From the Following options:  |";			//coding part done by:
			cout << "\n\t\t\t\t|-------------------------------------|";
			cout << "\n\t\t\t\t|1. Find Customer                     |";			// CUSTOMER TABLE Implemented By: Jay Chaudhari
			cout << "\n\t\t\t\t|2. Find Employee                     |";			// EMPLOYEE TABLE Implemented By: Bhavya Patel
			cout << "\n\t\t\t\t|3. Find Account                      |";			// Account  TABLE Implemented By: Yash Shah
			cout << "\n\t\t\t\t|4. Display Customer                  |";			
			cout << "\n\t\t\t\t|5. Display Employee                  |";			
			cout << "\n\t\t\t\t|6. Display Account                   |";			
			cout << "\n\t\t\t\t|7. Display All Customer              |";			
			cout << "\n\t\t\t\t|8. Display All Employee              |";			
			cout << "\n\t\t\t\t|9. Display All Account               |";			
			cout << "\n\t\t\t\t|10. Insert Employee                  |";			
			cout << "\n\t\t\t\t|11. Update Employee                  |";			
			cout << "\n\t\t\t\t|12. Delete Employee                  |";			
			cout << "\n\t\t\t\t|13. Insert Customer                  |";			
			cout << "\n\t\t\t\t|14. Update Customer                  |";			
			cout << "\n\t\t\t\t|15. Delete Customer                  |";			
			cout << "\n\t\t\t\t|16. Insert Account                   |";			
			cout << "\n\t\t\t\t|17. Update Account                   |";			
			cout << "\n\t\t\t\t|18. Delete Account                   |";			
			cout << "\n\t\t\t\t|-------------------------------------|";
			cout << "\n\t\t\t\t|0. Exit                              |";
			cout << "\n\t\t\t\t|=====================================|";
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
					cout << "\nValid Customer Number\n";
				}
				else
				{
					cout << "\nInvalid Customer Number\n";
				}
			}
			else if (input == 2)
			{
				cout << "\n Entering choice to find an employee";
				int emp;
				cout << "\n Enter Employee ID: ";
				cin >> emp;
				if (findEmployee(conn, emp) == 1)
				{
					cout << "\nValid Employee Number\n";
				}
				else
				{
					cout << "\nInvalid Employee Number\n";
				}
			}
			
			else if (input == 3)
			{

				cout << "\n Entering choice to find in an Account";
				int acc;
				cout << "\n Enter Account Number: ";
				cin >> acc;
				if (findAccount(conn, acc) == 1)
				{
					cout << "\nValid Account Number\n";
				}
				else
				{
					cout << "\nInvalid Account Number\n";
				}
			}
			else if (input == 4)
			{
				cout << "\nEntering choice to display an Customer";
				displayCustomer(conn, customer);
			}
			else if (input == 5)
			{
				cout << "\nEntering choice to display all employees\n";
				displayEmployee(conn, employee);
			}
			else if (input == 6)
			{
				cout << "\nEntering choice to display all employees\n";
				displayAccount(conn, account);
			}
			else if (input == 7)
			{
				cout << "\nEntering choice to display all customer\n";
				displayAllCustomer(conn);
			}
			else if (input == 8)
			{
				cout << "\nEntering choice to display all employees\n";
				displayAllEmployee(conn);
			}
			else if (input == 9)
			{
				cout << "\nEntering choice to display all employees\n";
				displayAllAccount(conn);
			}
			else if (input == 10)
			{
				struct Employee tempEmp;
				cout << "\nEntering to Insert in Employee\n";
				cout << "Employee ID:";
				cin >> tempEmp.empId;
				cout << "Employee Name: ";
				cin >> tempEmp.name;
				cout << "Employee Num: ";
				cin >> tempEmp.empNum;
				cout << "Branch ID: ";
				cin >> tempEmp.branchId;
				insertEmployee(conn, &tempEmp);
			}
			else if (input == 11)
			{
				int empId;
				cout << "\nEntering the Employee ID to Upadte the employee: ";
				cin >> empId;
				updateEmployee(conn,empId);
			}
			else if (input == 12)
			{
				int empID;
				cout << "\nEntering Employee ID to delete from the employee table: ";
				cin >> empID;
				deleteEmployee(conn,empID);
			}
			else if (input == 13)
			{
			struct Customer tempCuss;
			cout << "\nEntering to Insert in Customer\n";
			cout << "Customer ID:";
			cin >> tempCuss.custID;
			cout << "Customer First Name: ";
			cin >> tempCuss.firstName;
			cout << "Customer Last Name: ";
			cin >> tempCuss.lastName;
			cout << "Customer Address: ";
			cin >> tempCuss.address;
			cout << "Customer City: ";
			cin >> tempCuss.city; 
			cout << "Customer Country: ";
			cin >> tempCuss.country;
			cout << "Customer BranchID: ";
			cin >> tempCuss.branchId;
			cout << "Customer AccNum: ";
			cin >> tempCuss.accNum;
			cout << "Customer LoanNum: ";
			cin >> tempCuss.loanNum;
			insertCustomer(conn, &tempCuss);
			}
			else if (input == 14)
			{
			int cusID;
			cout << "\nEntering the Customer ID to Upadte the Customer: ";
			cin >> cusID;
			updateCustomer(conn, cusID);
			}
			else if (input == 15)
			{
			int cusID;
			cout << "\nEntering Customer ID to delete from the Customer table: ";
			cin >> cusID;
			deleteEmployee(conn, cusID);
			}
			else if (input == 16)
			{
			struct Account tempAcc;
			cout << "\nEntering to Insert in Account\n";
			cout << "Account Number:";
			cin >> tempAcc.accNum;
			cout << "Account Balance: ";
			cin >> tempAcc.balance;
			cout << "Account Date: ";
			cin >> tempAcc.date;
			cout << "Account Type: ";
			cin >> tempAcc.accType;
			cout << "Account UserID: ";
			cin >> tempAcc.userId;
			cout << "Account Password: ";
			cin >> tempAcc.pass;
			insertAccount(conn, &tempAcc);
			}
			else if (input == 17)
			{
			int accNum;
			cout << "\nEntering the Account Number to Upadte the Account: ";
			cin >> accNum;
			updateAccount(conn, accNum);
			}
			else if (input == 18)
			{
			int accNum;
			cout << "\nEntering Account Number to delete from the Account table: ";
			cin >> accNum;
			deleteAccount(conn, accNum);
			}
		} while (input != 0);

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

//******************************************************************************************

int findCustomer(Connection* conn, int customerId)
{
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

//******************************************************************************************

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
					customer.branchId = rs2->getInt(7);
					customer.accNum = rs2->getInt(8);
					customer.loanNum = rs2->getInt(9);
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
			}
		}
	} while (correctCode == false);
}

//******************************************************************************************

void displayAllCustomer(Connection* conn)
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
		cout << "accNumber";
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
			cust.branchId = rs2->getInt(7);
			cust.accNum = rs2->getInt(8);
			cust.loanNum = rs2->getInt(9);

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


//******************************************************************************************


int findEmployee(Connection* conn, int emp)
{
	Statement* stmt = conn->createStatement();
	ResultSet* rs = stmt->executeQuery("SELECT * From employee Where employee_id=" + to_string(emp));
	if (rs->next())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//******************************************************************************************

void displayEmployee(Connection* conn, Employee employee)
{
	int ecode;
	bool correctCode = false;
	do
	{
		cout << "\nEnter employee number: ";
		cin >> ecode;
		if (!cin || findEmployee(conn, ecode) != 1)
		{
			correctCode = false;
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\nInvalid Employee number\n";
		}
		else
		{
			correctCode = true;
			cout << "\nValid Input";
			cout << "\nSearch in table ..." << endl;
			try
			{
				Statement* stmt2 = conn->createStatement();
				ResultSet* rs2 = stmt2->executeQuery("SELECT * FROM employee where employee_id =" + to_string(ecode));
				while (rs2->next())
				{
					cout << "\n-------------- Employee Information --------------" << endl;
					employee.empId = rs2->getInt(1);
					employee.name = rs2->getString(2);
					employee.empNum = rs2->getString(3);
					employee.branchId = rs2->getInt(4);
					cout << "\n";
					cout << "Employee Id: ";
					cout << employee.empId;

					cout << "\n";
					cout << "Employee First Name: ";
					cout << employee.name;

					cout << "\n";
					cout << "Employee Employee Number: ";
					cout << employee.empNum;

					cout << "\n";
					cout << "Employee Branch ID: ";
					cout << employee.branchId << endl;
				}
			}
			catch (SQLException& sqlExcp)
			{
				cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
			}
		}
	} while (correctCode == false);
};

//******************************************************************************************


void displayAllEmployee(Connection* conn)
{
	try
	{
		Statement* stmt3 = conn->createStatement();
		ResultSet* rs2 = stmt3->executeQuery("SELECT * FROM employee");
		cout.width(10);
		cout.setf(ios::left);
		cout << "EmployeeID";
		cout.unsetf(ios::left);
		cout << " ";
		cout.width(15);
		cout.setf(ios::left);
		cout << "Name";
		cout.unsetf(ios::left);
		cout.width(12);
		cout.setf(ios::left);
		cout << "EmpNum";
		cout.unsetf(ios::left);
		cout.width(20);
		cout.setf(ios::left);
		cout << "Branch ID";
		cout.unsetf(ios::left);
		cout << endl;
		Employee employee;
		while (rs2->next())
		{
			employee.empId = rs2->getInt(1);
			employee.name = rs2->getString(2);
			employee.empNum = rs2->getString(3);
			employee.branchId = rs2->getInt(4);

			cout << " ";
			cout.width(10);
			cout.setf(ios::left);
			cout << employee.empId;
			cout.unsetf(ios::left);
			cout.width(15);
			cout.setf(ios::left);
			cout << employee.name;
			cout.unsetf(ios::left);

			cout.width(12);
			cout.setf(ios::left);
			cout << employee.empNum;
			cout.unsetf(ios::left);

			cout.width(20);
			cout.setf(ios::left);
			cout << employee.branchId;
			cout.unsetf(ios::left);
			cout << endl;
		}
	}
	catch (SQLException& sqlExcp)
	{
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}
}


//******************************************************************************************

int findAccount(Connection* conn, int acc)
{
	Statement* stmt = conn->createStatement();
	ResultSet* rs = stmt->executeQuery("SELECT * FROM account WHERE account_number=" + to_string(acc));
	if (rs->next())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//******************************************************************************************

void displayAccount(Connection* conn, Account account)
{
	int ecode;
	bool correctCode = false;
	do
	{
		cout << "\nEnter Payment number: ";
		cin >> ecode;
		if (!cin || findAccount(conn, ecode) != 1)
		{
			correctCode = false;
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\nInvalid Account number\n";
		}
		else
		{
			correctCode = true;
			cout << "\nValid Input";
			cout << "\nSearch in table ..." << endl;
			try
			{
				Statement* stmt2 = conn->createStatement();
				ResultSet* rs2 = stmt2->executeQuery("select *from account where account_number =" + to_string(ecode));
				while (rs2->next())
				{
					cout << "\n-------------- Account Information --------------" << endl;
					account.accNum = rs2->getInt(1);
					account.balance = rs2->getString(2);
					account.date = rs2->getString(3);
					account.accType = rs2->getString(4);
					account.userId = rs2->getInt(5);
					account.pass = rs2->getString(6);
					cout << "\n";
					cout << "Account No: ";
					cout << account.accNum;

					cout << "\n";
					cout << "Account Balance: ";
					cout << account.balance;

					cout << "\n";
					cout << "Account Creating Date: ";
					cout << account.date;

					cout << "\n";
					cout << "Account Type: ";
					cout << account.accType;

					cout << "\n";
					cout << "User ID: ";
					cout << account.userId;

					cout << "\n";
					cout << "Account Password: ";
					cout << account.pass << endl;
				}
			}
			catch (SQLException& sqlExcp)
			{
				cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
			}
		}
	} while (correctCode == false);
}

//******************************************************************************************

void displayAllAccount(Connection* conn)
{
	try
	{
		Statement* stmt3 = conn->createStatement();
		ResultSet* rs2 = stmt3->executeQuery("SELECT * FROM account");
		cout.width(10);
		cout.setf(ios::left);
		cout << "AccountNo ";
		cout.unsetf(ios::left);
		cout << " ";
		cout.width(15);
		cout.setf(ios::left);
		cout << "Balance";
		cout.unsetf(ios::left);
		cout.width(12);
		cout.setf(ios::left);
		cout << "Date";
		cout.unsetf(ios::left);
		cout.width(20);
		cout.setf(ios::left);
		cout << "accountType";
		cout.width(15);
		cout.setf(ios::left);
		cout << "userID";
		cout.unsetf(ios::left);
		cout.width(15);
		cout.setf(ios::left);
		cout << "Password";
		cout.unsetf(ios::left);
		cout << endl;
		Account account;
		while (rs2->next())
		{
			account.accNum = rs2->getInt(1);
			account.balance = rs2->getString(2);
			account.date = rs2->getString(3);
			account.accType = rs2->getString(4);
			account.userId = rs2->getInt(5);
			account.pass = rs2->getString(6);

			cout << " ";
			cout.width(10);
			cout.setf(ios::left);
			cout << account.accNum;
			cout.unsetf(ios::left);
			cout.width(15);
			cout.setf(ios::left);
			cout << account.balance;
			cout.unsetf(ios::left);

			cout.width(12);
			cout.setf(ios::left);
			cout << account.date;
			cout.unsetf(ios::left);

			cout.width(20);
			cout.setf(ios::left);
			cout << account.accType;
			cout.unsetf(ios::left);

			cout.width(15);
			cout.setf(ios::left);
			cout << account.userId;
			cout.unsetf(ios::left);

			cout.width(15);
			cout.setf(ios::left);
			cout << account.pass;
			cout.unsetf(ios::left);
			cout << endl;
		}
	}
	catch (SQLException& sqlExcp)
	{
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}
}

//******************************************************************************************

void insertEmployee(Connection* conn, Employee* emp) {
	try {
		Statement* stmt = conn->createStatement();
		stmt->setSQL("INSERT INTO EMPLOYEE VALUES (:1, : 2, : 3, : 4)");
		stmt->setInt(1, emp->empId);
			stmt->setString(2, emp->name);
		stmt->setString(3, emp->empNum);
		stmt->setInt(4, emp->branchId);
		stmt->executeUpdate();
		cout << "\nThe new employee is added successfully." << endl;
	}
	catch (SQLException& sqlExcp)
	{
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}
}

void updateEmployee(Connection* conn, int employeeID)
{
	try
	{
		string name = "";
		cout << "Employee Name: ";
		cin >> name;
		Statement* stmt = conn->createStatement();
		stmt->setSQL("UPDATE employee SET employee_name=:1 WHERE employee_id=:2");
		stmt->setString(1, name);
		stmt->setInt(2, employeeID);
		stmt->executeUpdate();
		cout << "The employee's Branch ID is updated succesfully." << endl;
	}
	catch (SQLException& sqlExcp)
	{
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}
}

void deleteEmployee(Connection* conn, int employeeID)
{
	struct Customer temp;
	if (findEmployee(conn, employeeID) == 1)
	{
		Statement* stmt = conn->createStatement();
		stmt->setSQL("DELETE FROM EMPLOYEE WHERE employee_id=:1");
		stmt->setInt(1, employeeID);
		stmt->executeUpdate();
		conn->commit();
		conn->terminateStatement(stmt);
		cout << "The Employee with ID " << employeeID << " is deleted successfully." << endl;
	}
	else
	{
		cout << "The Employee with ID " << employeeID << " does not exist." << endl;
	}
}

void insertCustomer(Connection* conn, Customer* cus) {
	try {
		Statement* stmt = conn->createStatement();
		stmt->setSQL("INSERT INTO CUSTOMER VALUES (:1, : 2, : 3, : 4, :5, :6, :7, :8, :9)");
		stmt->setInt(1, cus->custID);
		stmt->setString(2, cus->firstName);
		stmt->setString(3, cus->lastName);
		stmt->setString(4, cus->address);
		stmt->setString(5, cus->city);
		stmt->setString(6, cus->country);
		stmt->setInt(7, cus->branchId);
		stmt->setInt(8, cus->accNum);
		stmt->setInt(9, cus->loanNum);
		stmt->executeUpdate();
		cout << "\nThe new customer is added successfully." << endl;
	}
	catch (SQLException& sqlExcp)
	{
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}
}

void updateCustomer(Connection* conn, int loanNum)
{
	try
	{
		int accNum;
		cout << "Customer Loan Number: ";
		cin >> accNum;
		Statement* stmt = conn->createStatement();
		stmt->setSQL("UPDATE customer SET account_number=:1 WHERE loan_number=:2");
		stmt->setInt(1, accNum);
		stmt->setInt(2, loanNum);
		stmt->executeUpdate();
		cout << "The customer's Loan Number is updated succesfully." << endl;
	}
	catch (SQLException& sqlExcp)
	{
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}
}

void deleteCustomer(Connection* conn, int customerID)
{
	struct Customer temp;
	if (findCustomer(conn, customerID) == 1)
	{
		Statement* stmt = conn->createStatement();
		stmt->setSQL("DELETE FROM CUSTOMER WHERE customer_id=:1");
		stmt->setInt(1, customerID);
		stmt->executeUpdate();
		conn->commit();
		conn->terminateStatement(stmt);
		cout << "The Customer with ID " << customerID << " is deleted successfully." << endl;
	}
	else
	{
		cout << "The Customer with ID " << customerID << " does not exist." << endl;
	}
}

void insertAccount(Connection* conn, Account* acc) {
	try {
		Statement* stmt = conn->createStatement();
		stmt->setSQL("INSERT INTO ACCOUNT VALUES (:1, :2, :3, :4, :5, :6)");
		stmt->setInt(1, acc->accNum);
		stmt->setString(2, acc->balance);
		stmt->setString(3, acc->date);
		stmt->setString(4, acc->accType);
		stmt->setInt(5, acc->userId);
		stmt->setString(6, acc->pass);
		stmt->executeUpdate();
		cout << "\nThe new Account is added successfully." << endl;
	}
	catch (SQLException& sqlExcp)
	{
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}
}

void updateAccount(Connection* conn, int accNum)
{
	try
	{
		int userId;
		cout << "Account userID: ";
		cin >> userId;
		Statement* stmt = conn->createStatement();
		stmt->setSQL("UPDATE account SET userid=:1 WHERE account_number=:2");
		stmt->setInt(1, userId);
		stmt->setInt(2, accNum);
		stmt->executeUpdate();
		cout << "The Account's Branch ID is updated succesfully." << endl;
	}
	catch (SQLException& sqlExcp)
	{
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}
}

void deleteAccount(Connection* conn, int accNum)
{
	struct Customer temp;
	if (findEmployee(conn, accNum) == 1)
	{
		Statement* stmt = conn->createStatement();
		stmt->setSQL("DELETE FROM ACCOUNT WHERE account_number=:1");
		stmt->setInt(1, accNum);
		stmt->executeUpdate();
		conn->commit();
		conn->terminateStatement(stmt);
		cout << "The Account with Number " << accNum << " is deleted successfully." << endl;
	}
	else
	{
		cout << "The Account with Number " << accNum << " does not exist." << endl;
	}
}