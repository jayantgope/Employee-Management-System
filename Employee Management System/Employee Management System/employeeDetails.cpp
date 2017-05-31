#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;

#include "employeeDetails.h"
#include "employeeAccess.h"
#include "Login.h"

login loginMenu2;
using namespace std;

employeeAccess eUserPass;

void employeeAccess::employeeMenu()
{
	const string USERNAME = "user";
	const string PASSWORD = "123456";
	//strings in which user will enter username and password 
	string username, password;

	// Prompting user to input username
	system("cls");
	cout<<"\n"<<setw(49)<<right<<"--------------------";
	cout<<"\n"<<setw(48)<<right<<"  EMPLOYEE LOGIN  ";
	cout<<"\n"<<setw(49)<<right<<"--------------------";
	cout<<"\n\n\n"<<setw(42)<<"USERNAME : ";
	cin >> username;


	//Checking if username length is less than 4 characters then display an error message
	if(username.length() < 4)
	{
		cout<<"\n"<<setw(65)<<right<< "Username length must be atleast 4 characters long."<<endl;
		cin.get();
		mainMenu();
	}
	else  //if username length is greater than 3
	{
		//promprting user for password
		cout<<"\n"<<setw(42)<<"PASSWORD : ";
		cin >> password;
		//Checking if password length is less than 6 characters then display an error message
		if(password.length() < 6)
		{
			cout << "Password length must be atleast 6 characters long.";
		}
		else //if password length is greater than 5
		{
			//Checking if user's entered credentials are equal to actual USERNAME and PASSWORD 
			if(username == USERNAME && password == PASSWORD)
			{
				cout<<"\n\n"<<setw(52)<<"LOGIN SUCCESSFUL !!! \n"<< endl;
			}
			else
			{
				cout<<"\n\n"<<setw(54)<<"INVALID USERNAME OR PASSWORD"<< endl;
				
			}
		}
		employeeOptions();
	}

	
	/////////////////////////////////////////////////////////////////////////////////////
	/*char uname[15];
	char pass[15];
	char p=0;
	int i=0;
	
	cout<<"\n\t\tEnter User Name :-";
	cin>>uname;

	puts("\n\t\tEnter Password  :-");*/
		
	/*while(p!=13)
	{
		p=_getch();
		_putch('*');
		pass[i]=p;
		i++;
	}*/
	
	/*pass[i]='\0';

	ifstream objdata;
	objdata.open("HRStaff",ios::in|ios::out|ios::binary|ios::app);

	if(!objdata)
	{
			cout<<"\n-----Cannot Open the File-----\n";
			//return 1;
	}

	int nflag=0;
	while(!objdata.eof())
	{
		objdata.read((char *)& info, sizeof(info));
		if(strcmp(uname,info.uname)==0 )
		{
			system("cls");
			cout<<"\n\n\n\t\t****************************************";
			cout<<"\t\t\t\t\t\t\t Welcome TO EMS"<<info.uname<<endl;
			cout<<"\t\t****************************************\n"<<endl;
			info.putdata("SPS");
			cout<<"\n\tPress any key to log out...";
			nflag=1;
		}
	}	
			
	if(nflag==0)
	{
		cout<<"\n\nSorry !! Your Username & Password do not match.";
        _getch();
		logoutAll();
	}

objdata.close();*/
}



void employeeAccess::employeeOptions()
{
	int adminChoice;
	system("cls");
	cout<<"\n"<<setw(51)<<right<<"-----------------------";
	cout<<"\n"<<setw(48)<<right<<"  EMPLOYEE MENU  ";
	cout<<"\n"<<setw(51)<<right<<"-----------------------";
	cout<<"\n\n"<<setw(45)<<right<<"[1] VIEW PROFILE\n";
	cout<<setw(52)<<right<<"[2] VIEW SALARY PACKAGE\n";
	cout<<setw(39)<<right<<"[3] LOGOUT\n";
	cout<<"\n"<<setw(46)<<right<<"ENTER YOUR CHOICE ";
	cin>>adminChoice;

	switch(adminChoice)
	{
	case 1:
		{
			//admin_Access.generateICNumber();
			//admin_Access.addEmployee();
			viewEmployeeProfile();
			cin.get();
			employeeOptions();
		}
		break;
	case 2:
		{
			//admin_Access.registerEmployee();
			/*showHeading();
			admin_Access.showEmployeeTable();*/
			viewEmployeeSalary();
			cin.get();
			employeeOptions();
		}
		break;
	case 3:
		loginMenu2.loginPage();
		break;

	default:
		{
			cout<<"\n"<<setw(56)<<right<<"____________________________";
			cout<<"\n\n"<<setw(48)<<right<<"INVALID CHOICE "<<adminChoice;
			cout<<"\n"<<setw(56)<<right<<"____________________________";
			cout<<"\n\n"<<setw(52)<<right<<"PRESS ENTER TO RENTER...";
			cin.get();
			cin.get();
			employeeOptions();
		}

	}
	//adminOptions();
}

void employeeAccess::viewEmployeeProfile()
{
	system("cls");
			cout<<"\n"<<setw(54)<<right<<"---------------------------";
			cout<<"\n"<<setw(53)<<right<<"  VIEW EMPLOYEE PROFILE  ";
			cout<<"\n"<<setw(54)<<right<<"---------------------------";
			ifstream fin;
			int eID;
			fin.open("employeeDetails.txt",ios::in|ios::binary);
			cout<<"\n\n"<<setw(48)<<right<<"ENTER YOUR ID : ";
			cin>>eID;
			if(!fin)
			cout<<"File not found";
			else
			{
				fin.read(reinterpret_cast<char*>(this) ,sizeof(*this));
				while(!fin.eof())
				{
					if(eICNumber == eID)
					{
						showEmployee();
						cout<<"\n\n"<<setw(63)<<right<<"Press ENTER to go back to Main Menu...";
						break;
					}
					fin.read((char*)this,sizeof(*this));
				}
				if(fin.eof())
					cout<<"\n"<<setw(50)<<right<<"  RECORD NOT FOUND  ";
			}
			fin.close();
			cin.get();
		
}
void employeeAccess::calculateSalary()
{
	system("cls");
			cout<<"\n"<<setw(54)<<right<<"---------------------------";
			cout<<"\n"<<setw(53)<<right<<"  VIEW EMPLOYEE SALARY  ";
			cout<<"\n"<<setw(54)<<right<<"---------------------------";
			ifstream fin;
			int eID;
			fin.open("employeeDetails.txt",ios::in|ios::binary);
			cout<<"\n\n"<<setw(51)<<right<<"ENTER EMPLOYEE ID : ";
			cin>>eID;
			if(!fin)
			cout<<"File not found";
			else
			{
				fin.read((char*)(this) ,sizeof(*this));
				while(!fin.eof())
				{
					if(eICNumber == eID)
					{
						showEmployee();
						
						double basicSalary, finalSalary;

						if(strcmp(eDesignation,"CEO") == 0)
						{
							basicSalary= 50000;
							finalSalary = basicSalary + (0.70 * basicSalary) + (basicSalary * 0.20);
							
						}
						else if(strcmp(eDesignation,"MD") == 0)
						{
							basicSalary= 35000;
							finalSalary = basicSalary + (0.50 * basicSalary) + (basicSalary * 0.20);
						}
						else if(strcmp(eDesignation,"MGR") == 0)
						{
							basicSalary= 30000;
							finalSalary = basicSalary +(0.50 * basicSalary) + (basicSalary * 0.20);
						}
						else if(strcmp(eDesignation,"GM") == 0)
						{
							basicSalary=28000;
							finalSalary = basicSalary +(0.40 * basicSalary) + (basicSalary * 0.15);
						}
						else if(strcmp(eDesignation,"AM") == 0)
						{
							basicSalary=25000;
							finalSalary = basicSalary +(0.40 * basicSalary) + (basicSalary * 0.15);
						}
						else if(strcmp(eDesignation,"SV") == 0)
						{
							basicSalary=15000;
							finalSalary = basicSalary +(0.35 * basicSalary) + (basicSalary * 0.15);
						}
						else if(strcmp(eDesignation,"LBR") == 0)
						{
							basicSalary=10000;
							finalSalary = basicSalary + (0.30 * basicSalary) + (basicSalary * 0.10);
						}
						cout<<"\n\n"<<setw(54)<<right<<"EMPLOYEE SALARY PACKAGE IS : "<<finalSalary;
						cout<<"\n"<<setw(68)<<right<<"___________________________________________________";
						cout<<"\n\n"<<setw(63)<<right<<"Press ENTER to go back to Main Menu...";
						break;
					}
					fin.read((char*)this,sizeof(*this));
				}
				if(fin.eof())
					cout<<"\n"<<setw(50)<<right<<"  RECORD NOT FOUND  ";
			}
			fin.close();
			cin.get();
}

void employeeAccess::viewEmployeeSalary()
{
	system("cls");
			cout<<"\n"<<setw(54)<<right<<"---------------------------";
			cout<<"\n"<<setw(50)<<right<<"  VIEW YOUR SALARY  ";
			cout<<"\n"<<setw(54)<<right<<"---------------------------";
			ifstream fin;
			int eID;
			fin.open("employeeDetails.txt",ios::in|ios::binary);
			cout<<"\n\n"<<setw(50)<<right<<"ENTER EMPLOYEE ID : ";
			cin>>eID;
			if(!fin)
			cout<<"File not found";
			else
			{
				fin.read(reinterpret_cast<char*>(this) ,sizeof(*this));
				while(!fin.eof())
				{
					if(eICNumber == eID)
					{
						showEmployee();
						
						double basicSalary, finalSalary;

						if(strcmp(eDesignation,"CEO") == 0)
						{
							basicSalary= 50000;
							finalSalary = basicSalary + (0.70 * basicSalary) + (basicSalary * 0.20);
							
						}
						else if(strcmp(eDesignation,"MD") == 0)
						{
							basicSalary= 35000;
							finalSalary = basicSalary + (0.50 * basicSalary) + (basicSalary * 0.20);
						}
						else if(strcmp(eDesignation,"MGR") == 0)
						{
							basicSalary= 30000;
							finalSalary = basicSalary +(0.50 * basicSalary) + (basicSalary * 0.20);
						}
						else if(strcmp(eDesignation,"GM") == 0)
						{
							basicSalary=28000;
							finalSalary = basicSalary +(0.40 * basicSalary) + (basicSalary * 0.15);
						}
						else if(strcmp(eDesignation,"AM") == 0)
						{
							basicSalary=25000;
							finalSalary = basicSalary +(0.40 * basicSalary) + (basicSalary * 0.15);
						}
						else if(strcmp(eDesignation,"SV") == 0)
						{
							basicSalary=15000;
							finalSalary = basicSalary +(0.35 * basicSalary) + (basicSalary * 0.15);
						}
						else if(strcmp(eDesignation,"LBR") == 0)
						{
							basicSalary=10000;
							finalSalary = basicSalary + (0.30 * basicSalary) + (basicSalary * 0.10);
						}
						cout<<"\n\n"<<setw(50)<<right<<"YOUR SALARY PACKAGE IS : "<<finalSalary;
						cout<<"\n"<<setw(68)<<right<<"___________________________________________________";
						cout<<"\n\n"<<setw(63)<<right<<"Press ENTER to go back to Main Menu...";
						break;
					}
					fin.read((char*)this,sizeof(*this));
				}
				if(fin.eof())
					cout<<"\n"<<setw(50)<<right<<"  RECORD NOT FOUND  ";
			}
			fin.close();
			cin.get();
}

/*
void employeeAccess::registerEmployee()
{
	system("cls");
		cout<<"\n"<<setw(54)<<right<<"-------------------------";
		cout<<"\n"<<setw(52)<<right<<"  REGISTER EMPLOYEE  ";
		cout<<"\n"<<setw(54)<<right<<"-------------------------";
		int id,r=0;
		fstream file;
		file.open("employeeDetails.txt",ios::in|ios::out|ios::ate|ios::binary);
		cout<<"\n\n"<<setw(50)<<right<<"Enter Employee ID : ";
		cin>>id;
		file.seekg(0);
		if(!file)
             cout<<"File not found";
		else
		{
			file.read((char*)this,sizeof(*this));
        
			while(!file.eof())
			{
			   r++;
			   if(eICNumber==id)
			   {
					//showHeading();

					showEmployee();
					cout<<"\n\n"<<setw(54)<<right<<"Assign Username & Password";
					cout<<"\n"<<setw(68)<<right<<"___________________________________________________";
					assignUser();
					assignPass();

					ofstream fout;
    fout.open("employeeDetails.txt",ios::out|ios::app|ios::binary);
    if(!fout)
            cout<<"File can not open";
    else
		fout.write((char*)this, sizeof(*this));
	cout<<"\n"<<setw(68)<<right<<"___________________________________________________";
	cout<<"\n\n"<<setw(50)<<right<<"  EMPLOYEE ADDED  ";
    fout.close();


					cout<<"\n"<<setw(68)<<right<<"___________________________________________________";
					cout<<"\n\n"<<setw(70)<<right<<"Do you want SAVE changes you made to Employee Profile?";
					cout<<"\n\n"<<setw(46)<<right<<"[Y/N] : ";
					char saveChanges;
					cin>>saveChanges;
					if(saveChanges == 'y' || saveChanges == 'Y' || saveChanges == 'Yes' || saveChanges == 'YES')
					{
						file.seekp((r-1)*sizeof(employeeAccess),ios::e+);
						file.write((char*)this,sizeof(*this));
						cout<<"\n"<<setw(68)<<right<<"___________________________________________________";
						cout<<"\n\n"<<setw(55)<<right<<"  EMPLOYEE RECORD UPDATED  ";
						cin.get();
						break;
					}
				}
				file.read((char*)this,sizeof(*this));
			}
			if(file.eof())
            cout<<"\n"<<setw(50)<<right<<"  RECORD NOT FOUND  ";
			
     }     
     file.close();
}
void employeeAccess::assignUser()
{
	string tempUserName;
	cout<<"\n\n"<<right<<setw(30)<<" ";
	cout<<setw(20)<<left<<"ASSIGN USERNAME:";
	gets(eUsername);
	if(!validateAlpha(&eUsername))
	{
		assignUserPass();
	}
}
void employeeAccess::assignPass()
{
	cout<<"\n"<<right<<setw(30)<<" ";
	cout<<setw(20)<<left<<"ASSIGN PASSWORD:";
	gets(ePassword);
	if(strlen(ePassword)<6)
		{
			cout<<"Password is too short. "<<endl;
			assignPass();
		}
		fflush(stdin);
}

bool employeeAccess::validateAlpha(char* a)
{
bool rslt=true;
int b;
size_t i =0;
for(std::size_t i =0;i<strlen(a);i++)
	{b=(int)a[i];
	if (b>0&&b<48||b>122&&b<127||(b>57&&b<65)||(b>90&&b<97))
	rslt=false;
	}
if (rslt==false)
cout<<endl<<"\t\t**** Special Characters NOT ALLOWED ****"<<endl;
	return rslt;
}
/*employeeDetails::employeeDetails(string e_Name, string e_Qualification, string e_Gender)
{
	setEName(e_Name);
	setEQualification(e_Qualification);
	setEGender(e_Gender);
}

//=====================================================================

void employeeDetails::setEName(string e_Name)
{
	eName = e_Name;
}

string employeeDetails::getEName() const
{
	return eName;
}

//=====================================================================

void employeeDetails::setEQualification(string e_Qualification)
{
	eQualification = e_Qualification;
}

string employeeDetails::getEQualification() const
{
	return eQualification;
}

//=====================================================================

void employeeDetails::setEGender(string employee_Gender)
{
	eGender = employee_Gender;
}

string employeeDetails::getEGender() const
{
	return eGender;
}*/

