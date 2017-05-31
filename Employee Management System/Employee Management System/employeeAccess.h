#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class employeeAccess
{
public:
	virtual void mainMenu();
	void getEmployeeDetails();
	void addEmployee();
	void registerEmployee();
	void showEmployee();
	void showEmployeeTable();
	void viewEmployee();
	void updateEmployee();
	void deleteEmployee();
	void searchEmployee();
	void generateICNumber();
	void assignUser();
	void assignPass();
	void employeeMenu();
	void employeeOptions();
	void viewEmployeeProfile();
	void viewEmployeeSalary();
	void calculateSalary();
	void getName();
	void getPassword();
	void getGender();
	void getQualification();
	void getDesignation();
	void getDepartment();
	void getDateJoined();
	void getMaritalStatus();
	bool validateAlpha(char*);

protected:
	 

private:
	int eICNumber;
	string /*eDesignation,*/ eDateJoined, eNationality, eDOB;// ePassword, eUsername; 
	char eUsername[15], ePassword[15], eName[20], eGender[5], eQualification[20], eDesignation[10], eDepartment[10], eMaritalStatus[5];
	//char eName[25];

};
#endif