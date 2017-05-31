#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <conio.h>

#include "adminAccess.h"
#include "login.h"
#include "employeeAccess.h"
#include "employeeDetails.h"

using namespace std;
void adminOptions();
void showHeading();
static int eICN;
adminAccess admin_Access;
employeeAccess employee;
login loginMenu;
void login::loginPage()
{
	system("cls");
	int loginChoice;
	cout<<"\n"<<setw(48)<<right<<"------------------";
	cout<<"\n"<<setw(48)<<right<<"  WELCOME TO EMS  ";
	cout<<"\n"<<setw(48)<<right<<"------------------";
	//cout<<"\n\n\n"<<setw(47)<<"PLEASE LOGIN...\n\n";
	cout<<"\n\n"<<setw(48)<<right<<"[1] LOGIN AS ADMIN";
	cout<<"\n"<<setw(51)<<right<<"[2] LOGIN AS EMPLOYEE";
	cout<<"\n"<<setw(38)<<right<<"[3] EXIT";
	cout<<"\n\n\n"<<setw(48)<<right<<"ENTER YOUR CHOICE ";
	cin>>loginChoice;
	
	switch (loginChoice)
	{
	case 1:
		admin_Access.mainMenu();
		break;
	case 2:
		employee.employeeMenu();
		break;
	case 3:
		exit(0);
		break;
	default:
		cout<<"\n"<<setw(56)<<right<<"____________________________";
		cout<<"\n\n"<<setw(48)<<right<<"INVALID CHOICE "<<loginChoice;
		cout<<"\n"<<setw(56)<<right<<"____________________________";
		cout<<"\n\n"<<setw(52)<<right<<"PRESS ENTER TO RENTER...";
		cin.get();
		cin.get();
		loginPage();

	}
	//int choice = getType(" Who are you?");
}

void employeeAccess::mainMenu()
{
	//Username and Password to validate credentials
	const string USERNAME = "user";
	const string PASSWORD = "123456";
	//strings in which user will enter username and password 
	string username, password;

	// Prompting user to input username
	system("cls");
	cout<<"\n"<<setw(50)<<right<<"---------------------";
	cout<<"\n"<<setw(51)<<right<<"  ADMINISTRATOR LOGIN  ";
	cout<<"\n"<<setw(50)<<right<<"---------------------";
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
			adminOptions();
	}
}
void adminOptions()
{
	int adminChoice;
	system("cls");
	cout<<"\n"<<setw(52)<<right<<"------------------------";
	cout<<"\n"<<setw(51)<<right<<"  ADMINISTRATOR MENU  ";
	cout<<"\n"<<setw(52)<<right<<"------------------------";
	cout<<"\n\n"<<setw(49)<<right<<"[1] ADD NEW EMPLOYEE\n";
	cout<<setw(56)<<right<<"[2] SEARCH EMPLOYEE PROFILE\n";
	cout<<setw(58)<<right<<"[3] VIEW ALL EMPLOYEE PROFILE\n";
	cout<<setw(56)<<right<<"[4] UPDATE EMPLOYEE PROFILE\n";
	cout<<setw(56)<<right<<"[5] DELETE EMPLOYEE PROFILE\n";
	cout<<setw(57)<<right<<"[6] CALCULATE SALARY PACKAGE\n";
	cout<<setw(39)<<right<<"[7] LOGOUT\n";
	cout<<"\n"<<setw(46)<<right<<"ENTER YOUR CHOICE ";
	cin>>adminChoice;

	switch(adminChoice)
	{
	case 1:
		{
			//admin_Access.generateICNumber();
			admin_Access.addEmployee();
			cin.get();
			adminOptions();
		}
		break;
		break;
	case 2:
		{
			admin_Access.searchEmployee();
			/*showHeading();
			admin_Access.showEmployeeTable();*/
			cin.get();
			adminOptions();
		}
		break;
	case 3:
		{
			admin_Access.viewEmployee();
			cin.get();
			adminOptions();
		}
		break;
	case 4:
		{
			admin_Access.updateEmployee();
			cin.get();
			adminOptions();
		}
		break;
	case 5:
		{
			admin_Access.deleteEmployee();
			cin.get();
			adminOptions();
		}
		break;
	case 6:
		{
			admin_Access.calculateSalary();
			cin.get();
			adminOptions();
		}
		break;
	case 7:
		{
			/*admin_Access.calculateSalary();
			cin.get();*/
			cout<<"\n"<<setw(68)<<right<<"___________________________________________________";
			cout<<"\n\n"<<setw(55)<<right<<"Are you SURE want to LOGOUT";
			cout<<"\n\n"<<setw(46)<<right<<"[Y/N] : ";
			char YN;
			cin>>YN;
			if(YN == 'Y' || YN=='y')
				loginMenu.loginPage();
			else
				adminOptions();
		}
		break;
	default:
		{
			cout<<"\n"<<setw(56)<<right<<"____________________________";
			cout<<"\n\n"<<setw(48)<<right<<"INVALID CHOICE "<<adminChoice;
			cout<<"\n"<<setw(56)<<right<<"____________________________";
			cout<<"\n\n"<<setw(52)<<right<<"PRESS ENTER TO RENTER...";
			cin.get();
			cin.get();
			adminOptions();
		}

	}
	//adminOptions();
}

/*int employeeAccess::generateICNumber()
{
    ifstream fin;
	employeeAccess temp;
    int id = 0;
    fin.open("employeeDetails.txt",ios::in|ios::binary);
    if(!fin)
	{
           return(id+1);
	}
    else
    {
        fin.read((char*)&temp, sizeof(temp));
        while(!fin.eof())
        {
			id=temp.eICNumber;
			fin.read((char*)&temp, sizeof(temp));
        }
        id++;
		 cout<<id;
		// eICNumber = id;
		 return(id);
    }
}*/


void employeeAccess::addEmployee()
{
	/*cout<<"\n\n"<<setw(49)<<right<<"Employee Name: \t";
	cin>>eName;*/
	//employeeAccess employee;
	system("cls");
	cout<<"\n"<<setw(54)<<right<<"--------------------------";
	cout<<"\n"<<setw(53)<<right<<"  ADD EMPLOYEE PROFILE  ";
	cout<<"\n"<<setw(54)<<right<<"--------------------------";
	//eICNumber = generateICNumber();
	//cout<<"here";
	//eICN++;
	//eICNumber = eICN;
	ifstream fin;
	employeeAccess temp;
    int id = 0;
    fin.open("employeeDetails.txt",ios::in|ios::binary);
    if(!fin)
	{
           id = id+1;
	}
    else
    {
        fin.read((char*)&temp, sizeof(temp));
        while(!fin.eof())
        {
			id=temp.eICNumber;
			fin.read((char*)&temp, sizeof(temp));
        }
        id++;
	}

	eICNumber = id;

	getEmployeeDetails();
	ofstream fout;
    fout.open("employeeDetails.txt",ios::out|ios::app|ios::binary);
    if(!fout)
            cout<<"File can not open";
    else
		fout.write((char*)this, sizeof(*this));
	cout<<"\n"<<setw(68)<<right<<"___________________________________________________";
	cout<<"\n\n"<<setw(50)<<right<<"  EMPLOYEE ADDED  ";
    fout.close();
	cin.get();
	cin.get();
	adminOptions();
}

void employeeAccess::viewEmployee()
{
	system("cls");
	cout<<"\n"<<setw(54)<<right<<"---------------------------";
	cout<<"\n"<<setw(53)<<right<<"  VIEW EMPLOYEE PROFILE  ";
	cout<<"\n"<<setw(54)<<right<<"---------------------------";
    ifstream fin;
	fin.open("employeeDetails.txt",ios::in|ios::binary);
     if(!fin)
             cout<<"File not found";
     else
     {
		 showHeading();
         fin.read((char*)this,sizeof(*this));
         while(!fin.eof())
         {
			 showEmployeeTable();
			fin.read((char*)this,sizeof(*this));
         }
     }
     fin.close();
	 cin.get();
	 cin.get();
}



void employeeAccess::searchEmployee()
{
	int choice;
	system("cls");
	cout<<"\n"<<setw(54)<<right<<"---------------------------";
	cout<<"\n"<<setw(54)<<right<<"  SEARCH EMPLOYEE PROFILE  ";
	cout<<"\n"<<setw(54)<<right<<"---------------------------";
	cout<<"\n\n"<<setw(51)<<right<<"[1] SEARCH BY IC NUMBER\n";
	cout<<setw(53)<<right<<"[2] SEARCH BY DESIGNATION\n";
	cout<<setw(52)<<right<<"[3] SEARCH BY DEPARTMENT\n";
	cout<<setw(39)<<right<<"[4] GO BACK\n";
	cout<<"\n"<<setw(45)<<right<<"ENTER YOUR CHOICE ";
	cin>>choice;
	switch(choice)
	{
	case 1:
		{
			system("cls");
			cout<<"\n"<<setw(54)<<right<<"---------------------------";
			cout<<"\n"<<setw(54)<<right<<"  SEARCH EMPLOYEE PROFILE  ";
			cout<<"\n"<<setw(54)<<right<<"---------------------------";
			ifstream fin;
			int eID;
			fin.open("employeeDetails.txt",ios::in|ios::binary);
			cout<<"\n\n"<<setw(50)<<right<<"Enter Employee ID : ";
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
		}break;

	case 2:
		{
			system("cls");
			cout<<"\n"<<setw(54)<<right<<"---------------------------";
			cout<<"\n"<<setw(54)<<right<<"  SEARCH EMPLOYEE PROFILE  ";
			cout<<"\n"<<setw(54)<<right<<"---------------------------";
			ifstream fin;
			string designation;
			fin.open("employeeDetails.txt",ios::in|ios::binary);
			cout<<"\n\n"<<setw(50)<<right<<"Enter Designation : ";
			cin>>designation;
			if(!fin)
				cout<<"File not found";
			else
			{
				fin.read((char*)this ,sizeof(*this));
				showHeading();
				while(!fin.eof())
				{
					
					if(designation == eDesignation)
					{
						showEmployeeTable();
					}
					fin.read((char*)this,sizeof(*this));	
				}
				if(fin.eof())
				{
					//cout<<"\n"<<setw(50)<<right<<"  RECORD NOT FOUND  ";
				}
			}
			fin.close();
			cin.get();
			cin.get();
		}break;

	case 3:
		{
			system("cls");
			cout<<"\n"<<setw(54)<<right<<"---------------------------";
			cout<<"\n"<<setw(54)<<right<<"  SEARCH EMPLOYEE PROFILE  ";
			cout<<"\n"<<setw(54)<<right<<"---------------------------";
			ifstream fin;
			string department;
			fin.open("employeeDetails.txt",ios::in|ios::binary);
			cout<<"\n\n"<<setw(50)<<right<<"Enter Department : ";
			cin>>department;
			if(!fin)
				cout<<"File not found";
			else
			{
				fin.read(reinterpret_cast<char*>(this) ,sizeof(*this));
				showHeading();
				while(!fin.eof())
				{
					if(eDepartment == department)
					{
						showEmployeeTable();
					}
					fin.read((char*)this,sizeof(*this));
				}
				if(fin.eof())
				{
					//cout<<"\n"<<setw(50)<<right<<"  RECORD NOT FOUND  ";
				}
			}
			fin.close();
			cin.get();
			cin.get();
		}break;
	case 4:
		adminOptions();
	default:
		cout<<"\n"<<setw(56)<<right<<"____________________________";
		cout<<"\n\n"<<setw(48)<<right<<"INVALID CHOICE "<<choice;
		cout<<"\n"<<setw(56)<<right<<"____________________________";
		cout<<"\n\n"<<setw(52)<<right<<"PRESS ENTER TO RENTER...";
		cin.get();
		cin.get();
	}
	searchEmployee();

}

void employeeAccess::updateEmployee()
{
		system("cls");
		cout<<"\n"<<setw(54)<<right<<"---------------------------";
		cout<<"\n"<<setw(54)<<right<<"  UPDATE EMPLOYEE PROFILE  ";
		cout<<"\n"<<setw(54)<<right<<"---------------------------";
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
					cout<<"\n\n"<<setw(55)<<right<<"Re-enter Employee Details";
					cout<<"\n"<<setw(68)<<right<<"___________________________________________________";
					getEmployeeDetails();
					cout<<"\n"<<setw(68)<<right<<"___________________________________________________";
					cout<<"\n\n"<<setw(70)<<right<<"Do you want SAVE changes you made to Employee Profile?";
					cout<<"\n\n"<<setw(46)<<right<<"[Y/N] : ";
					char saveChanges;
					cin>>saveChanges;
					if(saveChanges == 'y' || saveChanges == 'Y' || saveChanges == 'Yes' || saveChanges == 'YES')
					{
						file.seekp((r-1)*sizeof(employeeAccess),ios::beg);
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

void employeeAccess::deleteEmployee()
{
	system("cls");
	cout<<"\n"<<setw(54)<<right<<"---------------------------";
	cout<<"\n"<<setw(54)<<right<<"  DELETE EMPLOYEE PROFILE  ";
	cout<<"\n"<<setw(54)<<right<<"---------------------------";
	ifstream fin;
     ofstream fout;
     int id;
     char x;
     fin.open("employeeDetails.txt",ios::in|ios::binary);
     fout.open("tempFile.txt",ios::out|ios::app|ios::binary);
     cout<<"\n\n"<<setw(50)<<right<<"Enter Employee ID : ";
     cin>>id;
     if(!fin)
             cout<<"File not found";
     else
     {
         fin.read((char*)this,sizeof(*this));
         while(!fin.eof())
         {
          if(eICNumber == id)
          {
			cout<<"\n"<<setw(68)<<right<<"___________________________________________________";
            cout<<"\n\n"<<setw(55)<<right<<"RECORD YOU WANT TO DELETE IS";
            //showHeading();
            showEmployee();
			cout<<"\n\n"<<setw(67)<<right<<"Are you SURE want to delete this Employee Profile?";
			cout<<"\n\n"<<setw(46)<<right<<"[Y/N] : ";
            fflush(stdin);
            cin>>x;
            if(x=='n')
                         fout.write((char*)this,sizeof(*this));
            else
			{
				cout<<"\n"<<setw(68)<<right<<"___________________________________________________";
                cout<<"\n\n"<<setw(55)<<right<<"  EMPLOYEE RECORD DELETED  ";
				cin.get();
			}
						
          }
          else
              fout.write((char*)this,sizeof(*this));
          fin.read((char*)this,sizeof(*this));
         }
         fin.close();
         fout.close();     
        
                      system("erase employeeDetails.txt");
                    //  getch();
                      system("rename tempFile.txt employeeDetails.txt");
	 }
}

void employeeAccess::getEmployeeDetails()
{
	getName();

	getPassword();

	getGender();
	
	getQualification();

	getDesignation();

	getDepartment();

	getDateJoined();

	cout<<"\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Nationality:";
	cin>>eNationality;

	cout<<"\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Date of Birth";
	cout<<"\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"[DD/MM/YYYY]:";
	cin>>eDOB;

	getMaritalStatus();

}

void employeeAccess::showEmployee()
{
	/*cout<<left;
	cout<<"\n"<<setw(15)<<eICNumber<<setw(10)<<eName<<setw(10)<<eGender<<setw(15)<<eQualification<<setw(15)<<eDesignation;
	cout<<"\n"<<setw(11)<<"EMPLOYEE ID"<<setw(15)<<"NAME"<<setw(6)<<"GENDER"<<setw(15)<<"QUALIFICATION"<<setw(15)<<"DESIGNATION"<<setw(15)<<"DEPARTMENT"<<setw(10)<<"DOJ"<<setw(15)<<"DESIGNATION"<<setw(15)<<"NATIONALITY"<<setw(10)<<"DOB"<<setw(15)<<"MARITAL STATUS\n";
	*/

	cout<<"\n"<<setw(68)<<right<<"___________________________________________________";

	cout<<"\n\n"<<right<<setw(25)<<"";
	cout<<setw(30)<<left<<"Employee ID:";
	cout<<eICNumber;
	
	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Name:";
	cout<<eName;

	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Password:";
	cout<<ePassword;

	cout<<"\n\n"<<right<<setw(25)<<" ";
    cout<<setw(30)<<left<<"Employee Gender:";
	cout<<eGender;

	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Qualification:";
	cout<<eQualification;

	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Designation:";
	cout<<eDesignation;

	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Department";
	cout<<eDepartment;

	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Date of Joining:";
	cout<<eDateJoined;

	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Nationality:";
	cout<<eNationality;

	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Date of Birth:";
	cout<<eDOB;

	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Marital Status:";
	cout<<eMaritalStatus;
	cout<<"\n\n"<<setw(68)<<right<<"___________________________________________________";
	//cout<<"\n\n"<<setw(68)<<right<<"---------------------------------------------------";
}

void employeeAccess::showEmployeeTable()
{
	//cout<<"\n"<<setw(15)<<eICNumber<<setw(10)<<eName<<setw(10)<<eGender<<setw(15)<<eQualification<<setw(15)<<eDesignation;
	cout<<"\n"<<setw(5)<<eICNumber<<setw(10)<<eName<<setw(5)<<eGender<<setw(10)<<eQualification<<setw(8)<<eDesignation<<setw(6)<<eDepartment<<setw(10)<<eDateJoined<<setw(10)<<eNationality<<setw(10)<<eDOB<<setw(5)<<eMaritalStatus;
}

void showHeading()
{
    cout<<left;
	cout<<"\n\n"<<setw(70)<<left<<"________________________________________________________________________________";
    cout<<"\n"<<setw(5)<<"EID"<<setw(10)<<"NAME"<<setw(5)<<"SEX"<<setw(10)<<"QLF."<<setw(8)<<"DESIG."<<setw(6)<<"DPMT."<<setw(10)<<"DOJ"<<setw(10)<<"NATION"<<setw(10)<<"DOB"<<setw(5)<<"M_STS";
	cout<<"\n"<<setw(70)<<left<<"________________________________________________________________________________";
	cin.get();
}

void employeeAccess::getName()
{
	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Name:";
    fflush(stdin);
	gets(eName);
	for (int i=0; i<20; i++)
	{
		int b=(int)eName[i];
		if (b>0&&b<48||b>122&&b<127||(b>57&&b<65)||(b>90&&b<97))
		{
			cout<<setw(68)<<right<<"___________________________________________________";
			cout<<"\n\n"<<right<<setw(25)<<" ";
			cout<<setw(30)<<left<<"Name cannot contain SPECIAL CHARACTERS...";
			cout<<"\n"<<setw(68)<<right<<"___________________________________________________";
			getName();
		}
	}	
}

void employeeAccess::getPassword()
{
	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Create Password (> 5 char):";
	gets(ePassword);
	if(strlen(ePassword) <6)
	{
		
		cout<<setw(68)<<right<<"___________________________________________________";
		cout<<"\n\n"<<right<<setw(25)<<" ";
		cout<<setw(30)<<left<<"Password is too short...try again";
		cout<<"\n"<<setw(68)<<right<<"___________________________________________________";
		getPassword();
	}
}

void employeeAccess::getGender()
{
	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Enter Gender [M/F]:";
	fflush(stdin);
	gets(eGender);
	if((strcmp(eGender,"M")!=0 && strcmp(eGender,"m")!=0 && strcmp(eGender,"F")!=0 && strcmp(eGender,"f")!=0))
	{
		cout<<setw(68)<<right<<"___________________________________________________";
		cout<<"\n\n"<<right<<setw(25)<<" ";
		cout<<setw(30)<<left<<"Invalid Gender Status...Enter [M/UF]"<<eGender;
		cout<<"\n"<<setw(68)<<right<<"___________________________________________________";
		getGender();
	}

}

void employeeAccess::getQualification()
{
	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Qualification:";
	cin>>eQualification;
	for (int i=0; i<20; i++)
	{
		int b=(int)eQualification[i];
		if (b>0&&b<48||b>122&&b<127||(b>57&&b<65)||(b>90&&b<97))
		{
			cout<<setw(68)<<right<<"___________________________________________________";
			cout<<"\n\n"<<right<<setw(25)<<" ";
			cout<<setw(30)<<left<<"Password is too short...try again";
			cout<<"\n"<<setw(68)<<right<<"___________________________________________________";
			getName();
		}
	}	

}

void employeeAccess::getDesignation()
{
	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Designation:";
	cout<<"\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"(CEO/MD/MGR/GM/AM/SPV/LBR):";
	fflush(stdin);
	gets(eDesignation);
	if((strcmp(eDesignation,"CEO")!=0) && (strcmp(eDesignation,"MD")!=0) && (strcmp(eDesignation,"MGR")!=0)&& (strcmp(eDesignation,"GM")!=0)&& (strcmp(eDesignation,"AM")!=0) && (strcmp(eDesignation,"SPV")!=0)&& (strcmp(eDesignation,"LBR")!=0))
	{
		cout<<setw(68)<<right<<"___________________________________________________";
		cout<<"\n\n"<<right<<setw(17)<<" ";
		cout<<setw(30)<<left<<"Enter Valid Designation (CEO/MD/MGR/GM/AM/SPV/LBR)";
		cout<<"\n"<<setw(68)<<right<<"___________________________________________________";
		getDesignation();
	}
}

void employeeAccess::getDepartment()
{
	cout<<"\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Department";
	cout<<"\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"(HR/MKT/PRO/QA):";
	fflush(stdin);
	gets(eDepartment);
	if((strcmp(eDepartment,"HR")!=0) && (strcmp(eDepartment,"MKT")!=0) && (strcmp(eDepartment,"PRO")!=0)&& (strcmp(eDepartment,"QA")!=0))
	{
		cout<<setw(68)<<right<<"___________________________________________________";
		cout<<"\n\n"<<right<<setw(17)<<" ";
		cout<<setw(30)<<left<<"Enter Valid Department (HR/MKT/PRO/QA)";
		cout<<"\n"<<setw(68)<<right<<"___________________________________________________";
		getDepartment();
	}

}

void employeeAccess::getDateJoined()
{
	cout<<"\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Date of Joining";
	cout<<"\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"[DD/MM/YYYY]:";
	cin>>eDateJoined;
}

void employeeAccess::getMaritalStatus()
{
	cout<<"\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Marital Status [M/U]:";
	fflush(stdin);
	gets(eMaritalStatus);
	if((strcmp(eMaritalStatus,"M")!=0 && strcmp(eMaritalStatus,"m")!=0 && strcmp(eMaritalStatus,"U")!=0 && strcmp(eMaritalStatus,"u")!=0))
	{
		cout<<setw(68)<<right<<"___________________________________________________";
		cout<<"\n\n"<<right<<setw(25)<<" ";
		cout<<setw(30)<<left<<"Invalid Marital Status...Enter [M/U]"<<eMaritalStatus;
		cout<<"\n"<<setw(68)<<right<<"___________________________________________________";
		getMaritalStatus();
	}

}
void main()
{
	loginMenu.loginPage();
	cin.get();
	getch();
}