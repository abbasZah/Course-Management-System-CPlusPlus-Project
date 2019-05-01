#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
using namespace std;

struct FeedBack
{
	string feedback;
};
void Loading(void);
void delay(unsigned int mseconds);
void gotoxy(int x, int y);
void Heading(void);
void FirstWindow(void);
void SecondWindow(void);
void Student(void);
void Student_Menu(void);
void Student_Course_Menu(void);
void availablecourses(void);
void RoadMap(void);
void Feedback(void);
void Faculty_Menu(void);
void Notification(void);
void availablecoursesforFac(void);


int main()
{
	system("COLOR 1E");
	Loading();
	FirstWindow();
SecGoto:	SecondWindow();
	char SecWinChoice = getchar(); system("CLS");
	if (SecWinChoice == '1')//STUDENT START////STUDENT START////STUDENT START////STUDENT START////STUDENT START////STUDENT START////STUDENT START////STUDENT START//
	{
	StuGoto:				Student(); char StudentWinChoice = getchar(); system("CLS");
		if (StudentWinChoice == '1')// Existing Student ~ // Existing Student ~ // Existing Student ~
		{
		login:						Heading();
			string Username, Password;
			cout << "\n\n\t\t\t\t\t\t";

			for (int rep = 1; rep <= 7; rep++) cout << char(219); cout << " STUDENT "; for (int rep = 1; rep <= 7; rep++) cout << char(219);

			cout << "\n\n\n\n";
			ofstream temp;
			temp.open("Registration.txt", ios::app);
			temp.close();

		Reenter:	cout << "\n\t\t\t\t\t\t   Username : "; cin >> Username;
			cout << "\n\t\t\t\t\t\t   Password : "; cin >> Password;

			ifstream reading;
			reading.open("Registration.txt");

			string userline;
			int userflag = 0, passflag = 0;
			while (!reading.eof())
			{
				getline(reading, userline);
				if (userline == Username)
				{
					userflag = 1;
					break;
				}
			}
			string passline;
			while (!reading.eof())
			{
				getline(reading, passline);
				if (passline == Password)
				{
					passflag = 1;
					break;
				}
			}
			if (userflag == 1 && passflag == 1)
			{
				cout << "\n\n\n\t\t\t\t\t"; for (int rep = 1; rep <= 38; rep++) cout << char(219);
				cout << "\n\t\t\t\t\t" << char(219) << char(219) << "\t\t\t\t    " << char(219) << char(219);
				cout << "\n"; for (int rep = 1; rep <= 41; rep++) cout << char(219); cout << char(219) << " You have logged in successfully! " << char(219) << char(219); for (int rep = 1; rep <= 42; rep++) cout << char(219);
				cout << "\n\t\t\t\t\t" << char(219) << char(219) << "\t\t\t\t    " << char(219) << char(219);
				cout << "\n\t\t\t\t\t"; for (int rep = 1; rep <= 38; rep++) cout << char(219);
				cout << "\n\t\t\t\t\t\t\t  ";
				delay(1000);
				system("CLS");
			MainMenuForProfile:				Student_Menu();// STUDENT MENU ~ // STUDENT MENU ~ // STUDENT MENU ~ // STUDENT MENU ~ //

				cout << "\n"; for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;
			MainMenuReenter: cout << "\n\t\t\t\t\t\tEnter Your Choice : ";


				short int MainMenuCh;
				cin >> MainMenuCh;

				if (MainMenuCh == 1)
				{
					system("cls");
					ifstream readingprofile;
					readingprofile.open("Registration.txt");

					string a, b, c, d, e; long long aa, bb;
					string profileline;

					while (!readingprofile.eof())
					{
						getline(readingprofile, profileline);
						if (profileline == Username)
						{
							Heading(); cout << "\n\n\t\t\t\t\t\t";

							for (int rep = 1; rep <= 7; rep++) cout << char(219); cout << " PROFILE "; for (int rep = 1; rep <= 7; rep++) cout << char(219);


							cout << "\n\n\n\t\t\t\t\tUsername :\t\t"; cout << profileline << endl;
							cout << "\n\t\t\t\t\tPassword :\t\t"; readingprofile >> a;		cout << a << endl;
							cout << "\n\t\t\t\t\tFirst Name :\t\t"; readingprofile >> b;		cout << b << endl;
							cout << "\n\t\t\t\t\tLast Name :\t\t"; readingprofile >> c;		cout << c << endl;
							cout << "\n\t\t\t\t\tEmail :\t\t\t"; readingprofile >> d;		cout << d << endl;
							cout << "\n\t\t\t\t\tCNIC :\t\t\t";							readingprofile >> aa;		cout << aa << endl;
							cout << "\n\t\t\t\t\tPhone No :\t\t"; readingprofile >> bb;		cout << bb << endl;
							break;
						}
					}
					cout << "\n"; for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;
					cout << "\n\t\t\t\t\t\tEnter B for Back : ";
					char choose;
				profilechoice:						cin >> choose;
					if (choose == 'B' || choose == 'b')
					{
						system("cls");
						goto MainMenuForProfile;
					}
					else
					{
						cout << "\n\t\t\tInvalid Choice, Enter Again : ";
						goto profilechoice;
					}

				}//End of Option 1
				else  if (MainMenuCh == 2)//MY CoURSES ~ //MY CoURSES ~ //MY CoURSES ~ //MY CoURSES ~ //MY CoURSES ~
				{
				addcourseback:
					system("cls");
					Student_Course_Menu();

					ofstream temp3;
					temp3.open("Courses.txt", ios::app);
					temp3.close();

				CourseChoice:					short int Coursechoice; cin >> Coursechoice;

					if (Coursechoice == 1)//><ADD CORSES START><><ADD CORSES START><><ADD CORSES START><><ADD CORSES START><><ADD CORSES START><><ADD CORSES START><><ADD CORSES START><><ADD CORSES START><><ADD CORSES START><><ADD CORSES START><><ADD CORSES START><><ADD CORSES START><
					{
						ofstream CourseWrite;
						CourseWrite.open("Courses.txt", ios::app);

						ifstream reading2;
						reading2.open("Courses.txt");
						string uline; bool flag2 = 0;
						while (!reading2.eof())
						{
							getline(reading2, uline);
							if (uline == Username)
								flag2 = 1;
						}
						if (flag2 == 1)
						{
							system("cls");
							Heading();

							cout << "\n\n\n\n\n\n\n\t\t\t\t\t"; for (int rep = 1; rep <= 36; rep++) cout << char(219);
							cout << "\n\t\t\t\t\t" << char(219) << char(219) << "\t\t\t\t  " << char(219) << char(219);
							cout << "\n\t\t\t\t\t"; cout << char(219) << char(219) << "  You have Already Registered!  " << char(219) << char(219);
							cout << "\n\t\t\t\t\t" << char(219) << char(219) << "\t\t\t\t  " << char(219) << char(219);
							cout << "\n\t\t\t\t\t"; for (int rep = 1; rep <= 36; rep++) cout << char(219);
							cout << "\n\t\t\t\t\t\t\t  ";
							delay(1000);
							goto addcourseback;
						}
						else
						{

							system("cls");
							Heading();
							cout << "\n\n\t\t\t\t\t\t";

							for (int rep = 1; rep <= 7; rep++) cout << char(219); cout << " ADD COURSES "; for (int rep = 1; rep <= 7; rep++) cout << char(219);

							cout << "\n";

							availablecourses();
							cout << "\n________________________________________________________________________________________________________________________\n\n";
							cout << "\t\t\t\t\t\tAdd Your (Five) Courses\n";


							CourseWrite << Username << endl;

							string CourseID, CourseTitle, InstructorName, Section;
							for (int i = 1; i <= 5; i++)
							{
								cout << "\n\t\t\t\t\t\t\tCourse # " << i << endl;
								cout << "\t\t\t\t\tCourse ID :\t\t"; cin >> CourseID; CourseWrite << CourseID << endl;
								cin.ignore();
								cout << "\t\t\t\t\tCourse Title :\t\t"; getline(cin, CourseTitle); CourseWrite << CourseTitle << endl;
								cout << "\t\t\t\t\tInstructor Name :\t"; getline(cin, InstructorName); CourseWrite << InstructorName << endl;
								cout << "\t\t\t\t\tSection :\t\t"; cin >> Section; CourseWrite << Section << endl;

							}
							cout << "\n\n\t\t\t\t\t"; for (int rep = 1; rep <= 36; rep++) cout << char(219);
							cout << "\n\t\t\t\t\t" << char(219) << char(219) << "\t\t\t\t  " << char(219) << char(219);
							cout << "\n\t\t\t\t\t"; cout << char(219) << char(219) << "   Course Added Successfully!   " << char(219) << char(219);
							cout << "\n\t\t\t\t\t" << char(219) << char(219) << "\t\t\t\t  " << char(219) << char(219);
							cout << "\n\t\t\t\t\t"; for (int rep = 1; rep <= 36; rep++) cout << char(219);
							cout << "\n\t\t\t\t\t\t\t  ";
							delay(2000);
							goto addcourseback;

						}


					}//><ADD CORSES END><><ADD CORSES END><><ADD CORSES END><><ADD CORSES END><><ADD CORSES END><><ADD CORSES END><><ADD CORSES END><><ADD CORSES END><><ADD CORSES END><><ADD CORSES END><
					else if (Coursechoice == 2)
					{
						fstream readingdropcourse;
						readingdropcourse.open("Courses.txt");

						int flag6 = 0; string line6, line7;
						while (!readingdropcourse.eof())
						{
							getline(readingdropcourse, line6);
							if (line6 == Username)
								flag6 = 1;
						}

						if (flag6 == 1)
						{

							system("cls");
							Heading();

							cout << "\n\n\n\n\n\n\n\t\t\t        "; for (int rep = 1; rep <= 52; rep++) cout << char(219);
							cout << "\n\t\t\t\t" << char(219) << char(219) << "\t\t\t\t\t          " << char(219) << char(219);
							cout << "\n\t\t\t\t"; cout << char(219) << char(219) << " Courses Will Drop Automatically After 6 Month! " << char(219) << char(219);
							cout << "\n\t\t\t\t" << char(219) << char(219) << "\t\t\t\t\t          " << char(219) << char(219);
							cout << "\n\t\t\t        "; for (int rep = 1; rep <= 52; rep++) cout << char(219);
							cout << "\n\t\t\t\t\t\t\t  ";
							delay(2000);        goto addcourseback;

						}
						else
						{
							system("cls");
							Heading();

							cout << "\n\n\n\n\n\n\n\t\t\t\t\t"; for (int rep = 1; rep <= 36; rep++) cout << char(219);
							cout << "\n\t\t\t\t\t" << char(219) << char(219) << "\t\t\t\t  " << char(219) << char(219);
							cout << "\n\t\t\t\t\t"; cout << char(219) << char(219) << " Register Add Your Course First " << char(219) << char(219);
							cout << "\n\t\t\t\t\t" << char(219) << char(219) << "\t\t\t\t  " << char(219) << char(219);
							cout << "\n\t\t\t\t\t"; for (int rep = 1; rep <= 36; rep++) cout << char(219);
							cout << "\n\t\t\t\t\t\t\t  ";
							delay(1000);        goto addcourseback;
						}


					}// END OF DROP COURSE // END OF DROP COURSE // END OF DROP COURSE // END OF DROP COURSE // END OF DROP COURSE // END OF DROP COURSE // END OF DROP COURSE 
					else if (Coursechoice == 3)//><SHOW CORSES START><><SHOW CORSES START><><SHOW CORSES START><><SHOW CORSES START><><SHOW CORSES START><><SHOW CORSES START><><SHOW CORSES START><><SHOW CORSES START><
					{
						ifstream readingcourse;
						readingcourse.open("Courses.txt");

						string array[20];
						string courseline;
						int flag3 = 0;

						while (!readingcourse.eof())
						{
							getline(readingcourse, courseline);
							if (courseline == Username)
								flag3 = 1;
						}
						if (flag3 == 1)
						{
							readingcourse.clear();		readingcourse.seekg(0, ios::beg);
							while (!readingcourse.eof())
							{
								string courseline3;
								getline(readingcourse, courseline3);
								if (courseline3 == Username)
								{
									system("cls");
									Heading();
									cout << "\n\n\t\t\t\t\t\t";

									for (int rep = 1; rep <= 7; rep++) cout << char(219); cout << " COURSES "; for (int rep = 1; rep <= 7; rep++) cout << char(219);

									cout << "\n";
									cout << "\n";
									cout << "________________________________________________________________________________________________________________________\n\n";
									cout << "\t\t Course ID\t\t Course Title\t\tInstructor Name\t\t Section\n";
									cout << "________________________________________________________________________________________________________________________\n\n";

									for (int i = 1; i <= 5; i++)
									{
										cout << "\n\t\t"; getline(readingcourse, array[i]);		cout << array[i];
										cout << "\t\t"; getline(readingcourse, array[i]);		cout << array[i];
										cout << "\t\t"; getline(readingcourse, array[i]);		cout << array[i];
										cout << "\t\t"; getline(readingcourse, array[i]);		cout << array[i] << endl;

									}

									cout << "\n"; for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;
									cout << "\n\t\t\t\t\t\tEnter B for Back : ";
									char choose;
								B_Choise:						    cin >> choose;
									if (choose == 'B' || choose == 'b')
									{
										system("cls");
										goto addcourseback;
									}
									else
									{
										cout << "\n\t\t\tInvalid Choice, Enter Again : ";
										goto B_Choise;
									}
								}
							}
						}
						else
						{
							system("cls");
							Heading();

							cout << "\n\n\n\n\n\n\n\t\t\t\t\t"; for (int rep = 1; rep <= 36; rep++) cout << char(219);
							cout << "\n\t\t\t\t\t" << char(219) << char(219) << "\t\t\t\t  " << char(219) << char(219);
							cout << "\n\t\t\t\t\t"; cout << char(219) << char(219) << "  Register Your Course First !  " << char(219) << char(219);
							cout << "\n\t\t\t\t\t" << char(219) << char(219) << "\t\t\t\t  " << char(219) << char(219);
							cout << "\n\t\t\t\t\t"; for (int rep = 1; rep <= 36; rep++) cout << char(219);
							cout << "\n\t\t\t\t\t\t\t  ";
							delay(1000);        goto addcourseback;
						}

					}//><SHOW CORSES END><><SHOW CORSES END><><SHOW CORSES END><><SHOW CORSES END><><SHOW CORSES END><><SHOW CORSES END><><SHOW CORSES END><><SHOW CORSES END><><SHOW CORSES END><><SHOW CORSES END><
					else if (Coursechoice == 4)
					{
						system("CLS");
						goto MainMenuForProfile;
					}
					else
					{
						cout << "\n\t\t\tInvalid Choice, Enter Again : ";
						goto CourseChoice;
					}


				}
				else if (MainMenuCh == 3)
				{
					system("CLS");
					Heading();
					RoadMap();
					cout << "\n\t\t\t\t\t\tEnter B for Back : ";
					char choose;
				BackChoise:						    cin >> choose;
					if (choose == 'B' || choose == 'b')
					{
						system("cls");
						goto MainMenuForProfile;
					}
					else
					{
						cout << "\n\t\t\tInvalid Choice, Enter Again : ";
						goto BackChoise;
					}
				}
				else if (MainMenuCh == 4)///FeedBack //FeedBack //FeedBack //FeedBack //FeedBack //FeedBack 
				{
					system("cls");
					Feedback();

					ofstream writefeedback("Feedback.txt", ios::app);
					FeedBack stu;

					writefeedback << Username << endl;
					cin.ignore();
					cout << "\tUMT Students Feedback : -\n\n\t\t\t\t";
					getline(cin, stu.feedback);

					writefeedback << stu.feedback;

					system("cls");
					Heading();

					cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t"; for (int rep = 1; rep <= 36; rep++) cout << char(219);
					cout << "\n\t\t\t\t\t" << char(219) << char(219) << "\t\t\t\t  " << char(219) << char(219);
					cout << "\n\t\t\t\t\t"; cout << char(219) << char(219) << "    Submitted Successfully!     " << char(219) << char(219);
					cout << "\n\t\t\t\t\t" << char(219) << char(219) << "\t\t\t\t  " << char(219) << char(219);
					cout << "\n\t\t\t\t\t"; for (int rep = 1; rep <= 36; rep++) cout << char(219);
					cout << "\n\t\t\t\t\t\t\t  ";

					delay(1000);
					system("cls");
					goto MainMenuForProfile;

				}///FeedBack //FeedBack //FeedBack //FeedBack //FeedBack //FeedBack 
				else if (MainMenuCh == 5)
				{
					system("CLS");
					goto SecGoto;
				}////MY COURSES END ~
				else
				{
					cout << "\t\t\t\tInvalid Choice..!";
					goto MainMenuReenter;
				}//Else of Student Menu

			}//end of login successully
			else
			{
				cout << "\n\t\t\t\t\t   Invalid Username or Password..!\n";
				goto Reenter;
			}//end of invalid username or password

		}//end of existing student// Existing Student ~ // Existing Student ~ // Existing Student ~ // Existing Student ~

		else if (StudentWinChoice == '2')// New Student ~// New Student ~// New Student ~
		{
		anotherstuGOTO:			Heading();
			string FirstName, LastName, Email, Username, Password;
			long long CNIC, PhoneNo;
			ofstream writing;
			writing.open("Registration.txt", ios::app);

			cout << "\n\n\t\t\t\t\t\t";
			for (int rep = 1; rep <= 7; rep++) cout << char(219); cout << " STUDENT "; for (int rep = 1; rep <= 7; rep++) cout << char(219);
			cout << "\n\n\n\n";

			cout << "\n\tSet : (Enter Carefully Without Space)\n";
			cout << "\n\t\t\t\t\t\tUsername : "; cin >> Username;
			ifstream another;
			another.open("Registration.txt");
			int anotherflag = 0;
			while (!another.eof())
			{
				string anotherline;
				getline(another, anotherline);
				if (Username == anotherline)
				{
					anotherflag = 1;
				}
			}
			if (anotherflag == 1)
			{
				system("cls");
				Heading();

				cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t"; for (int rep = 1; rep <= 36; rep++) cout << char(219);
				cout << "\n\t\t\t\t\t" << char(219) << char(219) << "\t\t\t\t  " << char(219) << char(219);
				cout << "\n\t\t\t\t\t"; cout << char(219) << char(219) << "     Username Already Exist     " << char(219) << char(219);
				cout << "\n\t\t\t\t\t" << char(219) << char(219) << "\t\t\t\t  " << char(219) << char(219);
				cout << "\n\t\t\t\t\t"; for (int rep = 1; rep <= 36; rep++) cout << char(219);
				cout << "\n\t\t\t\t\t\t\t  ";

				delay(1000);
				system("cls");
				goto anotherstuGOTO;
			}
			another.close();
			writing << endl;
			writing << Username << endl;



			cout << "\n\t\t\t\t\t\tPassword : "; cin >> Password;			writing << Password << endl;
			cout << "\n\tRegistration : (Enter Carefully Without Space)\n";
			cout << "\n\t\t\t\t\t\tFirst Name : ";	cin >> FirstName;		writing << FirstName << endl;
			cout << "\n\t\t\t\t\t\tLast Name : ";		cin >> LastName;	writing << LastName << endl;
			cout << "\n\t\t\t\t\t\tEmail : ";			cin >> Email;		writing << Email << endl;
			cout << "\n\t\t\t\t\t\tCNIC : ";			cin >> CNIC;		writing << CNIC << endl;
			cout << "\n\t\t\t\t\t\tPhone No. (PAK +92) :";		cin >> PhoneNo;	writing << PhoneNo << endl;

			cout << "\n\n\t\t\t\t\t"; for (int rep = 1; rep <= 36; rep++) cout << char(219);
			cout << "\n\t\t\t\t\t" << char(219) << char(219) << "\t\t\t\t  " << char(219) << char(219);
			cout << "\n\t\t\t\t\t"; cout << char(219) << char(219) << "         Account Created!       " << char(219) << char(219);
			cout << "\n\t\t\t\t\t" << char(219) << char(219) << "\t\t\t\t  " << char(219) << char(219);
			cout << "\n\t\t\t\t\t"; for (int rep = 1; rep <= 36; rep++) cout << char(219);
			cout << "\n\t\t\t\t\t\t\t  ";
			delay(1500);
			getchar();
			system("CLS"); goto login;
		}// New Student ~// New Student ~// New Student ~// New Student ~// New Student ~
		else { goto StuGoto; }//none

	}//STUDENT END////STUDENT END////STUDENT END////STUDENT END////STUDENT END////STUDENT END////STUDENT END////STUDENT END////STUDENT END////STUDENT END////STUDENT END////STUDENT END////STUDENT END//








	else if (SecWinChoice == '2')//FACULTY PART ~ FACULTY PART ~ FACULTY PART ~ FACULTY PART ~ FACULTY PART ~ FACULTY PART ~ FACULTY PART ~ 
	{
	FacGoto:		Student(); char FacultyWinChoice;
		cin >> FacultyWinChoice;
		system("CLS");


		if (FacultyWinChoice == '1')// Existing Faculty ~ // Existing Faculty ~ // Existing Faculty ~
		{
		Faclogin:						Heading();
			string Username, Password;
			cout << "\n\n\t\t\t\t\t\t";

			for (int rep = 1; rep <= 7; rep++) cout << char(219); cout << " FACULTY "; for (int rep = 1; rep <= 7; rep++) cout << char(219);

			cout << "\n\n\n\n";

			ofstream temp;
			temp.open("Fac Registration.txt", ios::app);
			temp.close();

		Reenterforfac:	cout << "\n\t\t\t\t\t\t   Username : "; cin >> Username;
			cout << "\n\t\t\t\t\t\t   Password : "; cin >> Password;

			ifstream reading;
			reading.open("Fac Registration.txt");

			string userline;
			int userflag = 0, passflag = 0;
			while (!reading.eof())
			{
				getline(reading, userline);
				if (userline == Username)
				{
					userflag = 1;
					break;
				}
			}
			string passline;
			while (!reading.eof())
			{
				getline(reading, passline);
				if (passline == Password)
				{
					passflag = 1;
					break;
				}
			}
			if (userflag == 1 && passflag == 1)
			{
				cout << "\n\n\n\t\t\t\t\t"; for (int rep = 1; rep <= 38; rep++) cout << char(219);
				cout << "\n\t\t\t\t\t" << char(219) << char(219) << "\t\t\t\t    " << char(219) << char(219);
				cout << "\n"; for (int rep = 1; rep <= 41; rep++) cout << char(219); cout << char(219) << " You have logged in successfully! " << char(219) << char(219); for (int rep = 1; rep <= 42; rep++) cout << char(219);
				cout << "\n\t\t\t\t\t" << char(219) << char(219) << "\t\t\t\t    " << char(219) << char(219);
				cout << "\n\t\t\t\t\t"; for (int rep = 1; rep <= 38; rep++) cout << char(219);
				cout << "\n\t\t\t\t\t\t\t  ";
				delay(1000);
				system("CLS");
			MainMenuForProfile2:				Faculty_Menu();// FACULTY MENU ~  FACULTY MENU ~  FACULTY MENU ~  FACULTY MENU ~  FACULTY MENU ~  FACULTY MENU ~ 

				cout << "\n"; for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;
			MainMenuReenter2: cout << "\n\t\t\t\t\t\tEnter Your Choice : ";


				short int MainMenuCh;
				cin >> MainMenuCh;

				if (MainMenuCh == 1)
				{
					system("cls");
					ifstream readingprofile;
					readingprofile.open("Fac Registration.txt");

					string a, b, c, d, e; long long aa, bb;
					string profileline;

					while (!readingprofile.eof())
					{
						getline(readingprofile, profileline);
						if (profileline == Username)
						{
							Heading(); cout << "\n\n\t\t\t\t\t\t";

							for (int rep = 1; rep <= 7; rep++) cout << char(219); cout << " PROFILE "; for (int rep = 1; rep <= 7; rep++) cout << char(219);


							cout << "\n\n\n\t\t\t\t\tUsername :\t\t"; cout << profileline << endl;
							cout << "\n\t\t\t\t\tPassword :\t\t"; readingprofile >> a;		cout << a << endl;
							cout << "\n\t\t\t\t\tFirst Name :\t\t"; readingprofile >> b;		cout << b << endl;
							cout << "\n\t\t\t\t\tLast Name :\t\t"; readingprofile >> c;		cout << c << endl;
							cout << "\n\t\t\t\t\tEmail :\t\t\t"; readingprofile >> d;		cout << d << endl;
							cout << "\n\t\t\t\t\tCNIC :\t\t\t";							readingprofile >> aa;		cout << aa << endl;
							cout << "\n\t\t\t\t\tPhone No :\t\t"; readingprofile >> bb;		cout << bb << endl;
							break;
						}
					}
					cout << "\n"; for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;
					cout << "\n\t\t\t\t\t\tEnter B for Back : ";
					char choose;
				profilechoice2:						cin >> choose;
					if (choose == 'B' || choose == 'b')
					{
						system("cls");
						goto MainMenuForProfile2;
					}
					else
					{
						cout << "\n\t\t\tInvalid Choice, Enter Again : ";
						goto profilechoice2;
					}

				}//End of Option 1
				else  if (MainMenuCh == 2)//MY CoURSES ~ //MY CoURSES ~ //MY CoURSES ~ //MY CoURSES ~ //MY CoURSES ~
				{
				addcourseback2:
					system("cls");
					Student_Course_Menu();

					ofstream temp2;
					temp2.open("Fac Courses.txt", ios::app);
					temp2.close();

				CourseChoice2:					short int Coursechoice; cin >> Coursechoice;

					if (Coursechoice == 1)//><ADD CORSES START><><ADD CORSES START><><ADD CORSES START><><ADD CORSES START><><ADD CORSES START><><ADD CORSES START><><ADD CORSES START><><ADD CORSES START><><ADD CORSES START><><ADD CORSES START><><ADD CORSES START><><ADD CORSES START><
					{
						ofstream CourseWrite;
						CourseWrite.open("Fac Courses.txt", ios::app);

						ifstream reading2;
						reading2.open("Fac Courses.txt");
						string uline; bool flag2 = 0;
						while (!reading2.eof())
						{
							getline(reading2, uline);
							if (uline == Username)
								flag2 = 1;
						}
						if (flag2 == 1)
						{
							system("cls");
							Heading();

							cout << "\n\n\n\n\n\n\n\t\t\t\t\t"; for (int rep = 1; rep <= 36; rep++) cout << char(219);
							cout << "\n\t\t\t\t\t" << char(219) << char(219) << "\t\t\t\t  " << char(219) << char(219);
							cout << "\n\t\t\t\t\t"; cout << char(219) << char(219) << "  You have Already Registered!  " << char(219) << char(219);
							cout << "\n\t\t\t\t\t" << char(219) << char(219) << "\t\t\t\t  " << char(219) << char(219);
							cout << "\n\t\t\t\t\t"; for (int rep = 1; rep <= 36; rep++) cout << char(219);
							cout << "\n\t\t\t\t\t\t\t  ";
							delay(1000);
							goto addcourseback2;
						}
						else
						{

							system("CLS");
							Heading();
							cout << "\n\n\t\t\t\t\t\t";

							for (int rep = 1; rep <= 7; rep++) cout << char(219); cout << " ADD COURSES "; for (int rep = 1; rep <= 7; rep++) cout << char(219);

							cout << "\n";

							availablecoursesforFac();
							cout << "\n________________________________________________________________________________________________________________________\n\n";
							cout << "\t\t\t\t\t\tAdd Your (Three) Courses\n";



							CourseWrite << Username << endl;

							string CourseID, CourseTitle, InstructorName, Section;
							for (int i = 1; i <= 3; i++)
							{
								cout << "\n\t\t\t\t\t\t\tCourse # " << i << endl;
								cout << "\t\t\t\t\tCourse ID :\t\t"; cin >> CourseID; CourseWrite << CourseID << endl;
								cin.ignore();
								cout << "\t\t\t\t\tCourse Title :\t\t"; getline(cin, CourseTitle); CourseWrite << CourseTitle << endl;
								cout << "\t\t\t\t\tSection :\t\t"; cin >> Section; CourseWrite << Section << endl;

							}
							cout << "\n\n\t\t\t\t\t"; for (int rep = 1; rep <= 36; rep++) cout << char(219);
							cout << "\n\t\t\t\t\t" << char(219) << char(219) << "\t\t\t\t  " << char(219) << char(219);
							cout << "\n\t\t\t\t\t"; cout << char(219) << char(219) << "   Course Added Successfully!   " << char(219) << char(219);
							cout << "\n\t\t\t\t\t" << char(219) << char(219) << "\t\t\t\t  " << char(219) << char(219);
							cout << "\n\t\t\t\t\t"; for (int rep = 1; rep <= 36; rep++) cout << char(219);
							cout << "\n\t\t\t\t\t\t\t  ";
							delay(2000);
							goto addcourseback2;

						}


					}//><ADD CORSES END><><ADD CORSES END><><ADD CORSES END><><ADD CORSES END><><ADD CORSES END><><ADD CORSES END><><ADD CORSES END><><ADD CORSES END><><ADD CORSES END><><ADD CORSES END><
					else if (Coursechoice == 2)
					{
						fstream readingdropcourse;
						readingdropcourse.open("Fac Courses.txt");

						int flag6 = 0; string line6, line7;
						while (!readingdropcourse.eof())
						{
							getline(readingdropcourse, line6);
							if (line6 == Username)
								flag6 = 1;
						}

						if (flag6 == 1)
						{

							system("cls");
							Heading();

							cout << "\n\n\n\n\n\n\n\t\t\t        "; for (int rep = 1; rep <= 52; rep++) cout << char(219);
							cout << "\n\t\t\t\t" << char(219) << char(219) << "\t\t\t\t\t          " << char(219) << char(219);
							cout << "\n\t\t\t\t"; cout << char(219) << char(219) << " Courses Will Drop Automatically After 6 Month! " << char(219) << char(219);
							cout << "\n\t\t\t\t" << char(219) << char(219) << "\t\t\t\t\t          " << char(219) << char(219);
							cout << "\n\t\t\t        "; for (int rep = 1; rep <= 52; rep++) cout << char(219);
							cout << "\n\t\t\t\t\t\t\t  ";
							delay(1000);        goto addcourseback2;

						}
						else
						{
							system("cls");
							Heading();

							cout << "\n\n\n\n\n\n\n\t\t\t\t\t"; for (int rep = 1; rep <= 36; rep++) cout << char(219);
							cout << "\n\t\t\t\t\t" << char(219) << char(219) << "\t\t\t\t  " << char(219) << char(219);
							cout << "\n\t\t\t\t\t"; cout << char(219) << char(219) << " Register Add Your Course First " << char(219) << char(219);
							cout << "\n\t\t\t\t\t" << char(219) << char(219) << "\t\t\t\t  " << char(219) << char(219);
							cout << "\n\t\t\t\t\t"; for (int rep = 1; rep <= 36; rep++) cout << char(219);
							cout << "\n\t\t\t\t\t\t\t  ";
							delay(1000);        goto addcourseback2;
						}


					}// END OF DROP COURSE // END OF DROP COURSE // END OF DROP COURSE // END OF DROP COURSE // END OF DROP COURSE // END OF DROP COURSE // END OF DROP COURSE 
					else if (Coursechoice == 3)//><SHOW CORSES START><><SHOW CORSES START><><SHOW CORSES START><><SHOW CORSES START><><SHOW CORSES START><><SHOW CORSES START><><SHOW CORSES START><><SHOW CORSES START><
					{
						ifstream readingcourse;
						readingcourse.open("Fac Courses.txt");

						string array[9];
						string courseline;
						int flag3 = 0;

						while (!readingcourse.eof())
						{
							getline(readingcourse, courseline);
							if (courseline == Username)
								flag3 = 1;
						}
						if (flag3 == 1)
						{
							readingcourse.clear();		readingcourse.seekg(0, ios::beg);
							while (!readingcourse.eof())
							{
								string courseline3;
								getline(readingcourse, courseline3);
								if (courseline3 == Username)
								{
									system("cls");
									Heading();
									cout << "\n\n\t\t\t\t\t\t";

									for (int rep = 1; rep <= 7; rep++) cout << char(219); cout << " COURSES "; for (int rep = 1; rep <= 7; rep++) cout << char(219);

									cout << "\n";
									cout << "\n";
									cout << "________________________________________________________________________________________________________________________\n\n";
									cout << "\t\t Course ID\t\t Course Title\t\t Section\n";
									cout << "________________________________________________________________________________________________________________________\n\n";

									for (int i = 1; i <= 3; i++)
									{
										cout << "\n\t\t"; getline(readingcourse, array[i]);		cout << array[i];
										cout << "\t\t"; getline(readingcourse, array[i]);		cout << array[i];
										cout << "\t\t"; getline(readingcourse, array[i]);		cout << array[i] << endl;

									}

									cout << "\n"; for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;
									cout << "\n\t\t\t\t\t\tEnter B for Back : ";
									char choose;
								B2_Choise:						    cin >> choose;
									if (choose == 'B' || choose == 'b')
									{
										system("cls");
										goto addcourseback2;
									}
									else
									{
										cout << "\n\t\t\tInvalid Choice, Enter Again : ";
										goto B2_Choise;
									}
								}
							}
						}
						else
						{
							system("cls");
							Heading();

							cout << "\n\n\n\n\n\n\n\t\t\t\t\t"; for (int rep = 1; rep <= 36; rep++) cout << char(219);
							cout << "\n\t\t\t\t\t" << char(219) << char(219) << "\t\t\t\t  " << char(219) << char(219);
							cout << "\n\t\t\t\t\t"; cout << char(219) << char(219) << "  Register Your Course First !  " << char(219) << char(219);
							cout << "\n\t\t\t\t\t" << char(219) << char(219) << "\t\t\t\t  " << char(219) << char(219);
							cout << "\n\t\t\t\t\t"; for (int rep = 1; rep <= 36; rep++) cout << char(219);
							cout << "\n\t\t\t\t\t\t\t  ";
							delay(1000);        goto addcourseback2;
						}

					}//><SHOW CORSES END><><SHOW CORSES END><><SHOW CORSES END><><SHOW CORSES END><><SHOW CORSES END><><SHOW CORSES END><><SHOW CORSES END><><SHOW CORSES END><><SHOW CORSES END><><SHOW CORSES END><
					else if (Coursechoice == 4)
					{
						system("CLS");
						goto MainMenuForProfile2;
					}
					else
					{
						cout << "\n\t\t\tInvalid Choice, Enter Again : ";
						goto CourseChoice2;
					}


				}

				else if (MainMenuCh == 3)///Notification Notification Notification Notification Notification Notification 
				{
					Notification();
					delay(1000);
					system("cls");
					goto MainMenuForProfile2;

				}///Notification Notification Notification Notification Notification Notification 
				else if (MainMenuCh == 4)
				{
					system("CLS");
					goto SecGoto;
				}////MY COURSES END ~
				else
				{
					cout << "\t\t\t\tInvalid Choice..!";
					goto MainMenuReenter2;
				}//Else of Student Menu

			}
			else
			{
				cout << "\n\t\t\t\t\t   Invalid Username or Password..!\n";
				goto Reenterforfac;
			}//end of invalid username or password

		}//end of faculty existring
		else	if (FacultyWinChoice == '2')// Existing Faculty ~ // Existing Faculty ~ // Existing Faculty ~
		{
		anotherfacGOTO:	Heading();
			string FirstName, LastName, Email, Username, Password;
			long long CNIC, PhoneNo;
			ofstream writing;
			writing.open("Fac Registration.txt", ios::app);

			cout << "\n\n\t\t\t\t\t\t";
			for (int rep = 1; rep <= 7; rep++) cout << char(219); cout << " FACULTY "; for (int rep = 1; rep <= 7; rep++) cout << char(219);
			cout << "\n\n\n\n";

			cout << "\n\tSet : (Enter Carefully Without Space)\n";
			cout << "\n\t\t\t\t\t\tUsername : "; cin >> Username;


			ifstream another;
			another.open("Fac Registration.txt");
			int anotherflag = 0;
			while (!another.eof())
			{
				string anotherline;
				getline(another, anotherline);
				if (Username == anotherline)
				{
					anotherflag = 1;
				}
			}
			if (anotherflag == 1)
			{
				system("cls");
				Heading();

				cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t"; for (int rep = 1; rep <= 36; rep++) cout << char(219);
				cout << "\n\t\t\t\t\t" << char(219) << char(219) << "\t\t\t\t  " << char(219) << char(219);
				cout << "\n\t\t\t\t\t"; cout << char(219) << char(219) << "     Username Already Exist     " << char(219) << char(219);
				cout << "\n\t\t\t\t\t" << char(219) << char(219) << "\t\t\t\t  " << char(219) << char(219);
				cout << "\n\t\t\t\t\t"; for (int rep = 1; rep <= 36; rep++) cout << char(219);
				cout << "\n\t\t\t\t\t\t\t  ";

				delay(1000);
				system("cls");
				goto anotherfacGOTO;
			}
			another.close();


			writing << endl;
			writing << Username << endl;
			cout << "\n\t\t\t\t\t\tPassword : "; cin >> Password;			writing << Password << endl;
			cout << "\n\tRegistration : (Enter Carefully Without Space)\n";
			cout << "\n\t\t\t\t\t\tFirst Name : ";	cin >> FirstName;		writing << FirstName << endl;
			cout << "\n\t\t\t\t\t\tLast Name : ";		cin >> LastName;	writing << LastName << endl;
			cout << "\n\t\t\t\t\t\tEmail : ";			cin >> Email;		writing << Email << endl;
			cout << "\n\t\t\t\t\t\tCNIC : ";			cin >> CNIC;		writing << CNIC << endl;
			cout << "\n\t\t\t\t\t\tPhone No. (PAK +92) :";		cin >> PhoneNo;	writing << PhoneNo << endl;

			cout << "\n\n\t\t\t\t\t"; for (int rep = 1; rep <= 36; rep++) cout << char(219);
			cout << "\n\t\t\t\t\t" << char(219) << char(219) << "\t\t\t\t  " << char(219) << char(219);
			cout << "\n\t\t\t\t\t"; cout << char(219) << char(219) << "         Account Created!       " << char(219) << char(219);
			cout << "\n\t\t\t\t\t" << char(219) << char(219) << "\t\t\t\t  " << char(219) << char(219);
			cout << "\n\t\t\t\t\t"; for (int rep = 1; rep <= 36; rep++) cout << char(219);
			cout << "\n\t\t\t\t\t\t\t  ";
			delay(1500);
			getchar();
			system("CLS"); goto Faclogin;
		}
		else { goto FacGoto; }//none









	}//FACULTY PART ~FACULTY PART ~FACULTY PART ~FACULTY PART ~FACULTY PART ~FACULTY PART ~FACULTY PART ~FACULTY PART ~
	else { goto SecGoto; }

	cout << endl; system("pause");
	return 0;
}














//DEFINITION/////DEFINITION/////DEFINITION/////DEFINITION/////DEFINITION/////DEFINITION/////DEFINITION/////DEFINITION/////DEFINITION/////DEFINITION/////DEFINITION/////

void Heading(void)
{
	cout << "\n";
	for (int rep = 1; rep <= 120; rep++) cout << char(219); cout << endl;
	cout << "\n\n\t\t\t\t\t\tCOURSE MANAGEMENT SYSTEM \t\t\n\n\n";
	for (int rep = 1; rep <= 120; rep++) cout << char(219); cout << endl;
}
void FirstWindow(void)
{
	cout << "\n\n\n\n\n\n\n";
	for (int rep = 1; rep <= 120; rep++) cout << char(219); cout << endl;
	cout << "\n";
	cout << "\n\t"; for (int i = 1; i <= 3; i++)cout << " "; cout << " " << char(220); for (int i = 1; i <= 8; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << " "; for (int i = 1; i <= 4; i++)cout << char(220); for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 4; i++)cout << char(220); for (int i = 1; i <= 6; i++)cout << " "; cout << char(220); for (int i = 1; i <= 8; i++)cout << char(219); cout << "\t\t\t     COURSE MANAGEMENT SYSTEM";
	cout << "\n\t"; for (int i = 1; i <= 3; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 4; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << char(219); cout << " "; cout << char(220); for (int i = 1; i <= 2; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << char(223); for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << char(223); for (int i = 1; i <= 2; i++)cout << char(219); cout << char(220); for (int i = 1; i <= 3; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 4; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << char(219);
	cout << "\n\t"; for (int i = 1; i <= 3; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 4; i++)cout << " "; cout << char(219) << char(223) << " " << " "; for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << " ";/**/for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << " ";/**/for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << " ";/**/for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 4; i++)cout << " ";/**/cout << char(219) << char(223) << " ";
	cout << "\n\t"; for (int i = 1; i <= 3; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 4; i++)cout << " "; for (int i = 1; i <= 4; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << char(219); cout << "\t\t\t  Developed By : Abbas Zaheer & Muhammad Shahrukh";
	cout << "\n\t"; for (int i = 1; i <= 3; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 4; i++)cout << " "; for (int i = 1; i <= 4; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << char(219); cout << " " << char(223); for (int i = 1; i <= 11; i++)cout << char(219);
	cout << "\n\t"; for (int i = 1; i <= 3; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 4; i++)cout << " "; cout << char(219) << char(220) << " " << " "; for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << " ";/**/for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << " ";/**/for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << " ";/**/for (int i = 1; i <= 3; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << " ";/**/for (int i = 1; i <= 3; i++)cout << char(219); cout << "\t\t\tSubmitted To : Muhammad Aizaz Akmal";
	cout << "\n\t"; for (int i = 1; i <= 3; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 4; i++)cout << " "; cout << char(219) << char(219) << char(219) << " "; for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << " ";/**/for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << " ";/**/for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << " "; cout << " " << char(220) << char(219); for (int i = 1; i <= 3; i++)cout << " ";/**/cout << char(219) << char(219) << char(219);
	cout << "\n\t"; for (int i = 1; i <= 3; i++)cout << " "; for (int i = 1; i <= 8; i++)cout << char(219); cout << char(223); for (int i = 1; i <= 3; i++)cout << " "; cout << char(223) << char(219); for (int i = 1; i <= 3; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << " "; cout << char(219) << char(223); for (int i = 1; i <= 3; i++)cout << " "; cout << char(220); for (int i = 1; i <= 8; i++)cout << char(219); cout << char(223); cout << "\t\t\t\t   Section : V10";


	cout << "\n\n\n"; for (int rep = 1; rep <= 120; rep++) cout << char(219); cout << endl;
	cout << "\n\t\t\t\t\tEnter Any Key To Continue... : ";
	getchar();
	system("CLS");
}
void SecondWindow(void)
{
	Heading();
	cout << "\n\n\n\n";
	cout << "\t\t\t\t\t\t      1. Student\n\n";
	cout << "\t\t\t\t\t\t      2. Faculty\n";
	cout << "\n\n\n"; for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;
	cout << "\n\t\t\t\t\t\tEnter Your Choice : ";

}
void Student(void)
{
	Heading();
	cout << "\n\n\n\n";
	cout << "\t\t\t\t\t\t      1. Existing\n\n";
	cout << "\t\t\t\t\t\t      2. New\n";
	cout << "\n\n\n"; for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;
	cout << "\n\t\t\t\t\t\tEnter Your Choice : ";
}
void Student_Menu(void)
{
	Heading();
	cout << "\n\n\t\t\t\t\t\t";

	for (int rep = 1; rep <= 5; rep++) cout << char(219); cout << " STUDENT MENU "; for (int rep = 1; rep <= 5; rep++) cout << char(219);

	cout << "\n\n\n\n";

	cout << "\t\t\t\t\t\t      1. Profile\n\n";
	cout << "\t\t\t\t\t\t      2. Courses\n\n";
	cout << "\t\t\t\t\t\t      3. Road Map\n\n";
	cout << "\t\t\t\t\t\t      4. Feedback\n\n";
	cout << "\t\t\t\t\t\t      5. Logout\n\n";

}
void delay(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock());
}
void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void Student_Course_Menu(void)
{
	Heading();

	cout << "\n\n\t\t\t\t\t\t";
	for (int rep = 1; rep <= 7; rep++) cout << char(219); cout << " My Courses "; for (int rep = 1; rep <= 7; rep++) cout << char(219);
	cout << "\n\n\n";

	cout << "\t\t\t\t\t\t      1. Add Course\n\n";
	cout << "\t\t\t\t\t\t      2. Drop Course\n\n";
	cout << "\t\t\t\t\t\t      3. Show Courses\n\n";
	cout << "\t\t\t\t\t\t      4. Back\n\n";
	cout << "\n\n\n"; for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;
	cout << "\n\t\t\t\t\t\tEnter Your Choice : ";
}
void availablecourses(void)
{
	cout << "\n";
	cout << "________________________________________________________________________________________________________________________\n\n";
	cout << "\t Course ID\t Course Title\t\t\t\tInstructor Name\t\t\t\t Section\n";
	cout << "________________________________________________________________________________________________________________________\n\n";

	cout << "\n\t EN20521 \t Communication Skills/English III\t Adil Najam\t\t\t\t V10";
	cout << "\n\t CC2211w \t Programming Fundamentals\t\t Akbar S. Ahmed\t\t\t\t C24";
	cout << "\n\t CC2111w \t English-II\t\t\t\t Anees Tauqeer\t\t\t\t V10";
	cout << "\n\t MA3150 \t Linear Algebra\t\t\t\t Ata ul Haq Qasmi\t\t\t V10";
	cout << "\n\t CC2715w\t Basic Electronics\t\t\t Ayesha Jalal\t\t\t\t C3";
	cout << "\n\t CC1111w \t Pakistan Studies\t\t\t Farogh Naseem\t\t\t\t F3";
	cout << "\n\t CC16611w \t Digital Logic and Design\t\t Hina Jalal\t\t\t\t FD8";
	cout << "\n\t SS171  \t Object Oriented Programming\t\t Farogh Naseem\t\t\t\t K9";
	cout << "\n\t CC1391w \t Probability and Statistics\t\t Dr Muhammad Naeem\t\t\t N5";
	cout << "\n\t SS171 \t\t Software Engineering\t\t\t Dr Riaz Ahmad\t\t\t\t H3";
	cout << "\n\t PH121 \t\t Introduction to Database Systems\t Tahir Hussain\t\t\t\t J3";
	cout << "\n\t CC6111w \t Computer and Communication Networks\t Masroor Elahi\t\t\t\t J6";
	cout << "\n\t MA210 \t\t Theory of Automata\t\t\t Ahmed Memon\t\t\t\t Z3";
	cout << "\n\t HG210 \t\t Calculus II\t\t\t\t Dr. Niaz Ahmed\t\t\t\t W5\n\n";


}
void RoadMap(void)
{
	cout << "\n";
	cout << "________________________________________________________________________________________________________________________\n\n";
	cout << "Semester\t Course ID\t Course Title\t\t\tCredit Hour\t Course Type\t\t Course Category\n";
	cout << "________________________________________________________________________________________________________________________\n\n";
	cout << "Fall 2017\n";
	cout << "\t\t CC1111w\tIntroduction to Computing\t 4\t\t Core Course\t\t Theory+Lab\n";
	cout << "\t\t CC1311w\tDiscrete Structures\t\t 3\t\t Core Course\t\t Theory\n";
	cout << "\t\t EN110\t\tEnglish I\t\t\t 3\t\t Core Course\t\t Theory\n";
	cout << "\t\t MA100\t\tCalculus I\t\t\t 3\t\t Core Course\t\t Theory\n";
	cout << "\t\t HM150\t\tIslamic Studies/Ethics\t\t 3\t\t Core Course\t\t Theory\n";
	cout << "\n\n\n";

	cout << "Spring 2018\n";
	cout << "\t\t CC1111w\tProgramming Fundamentals\t 4\t\t Core Course\t\t Theory+Lab\n";
	cout << "\t\t MA210\t\tLinear Algebra\t\t\t 3\t\t Core Course\t\t Theory\n";
	cout << "\t\t EN112\t\tEnglish-II\t\t\t 3\t\t Core Course\t\t Theory\n";
	cout << "\t\t PH121\t\tBasic Electronics\t\t 4\t\t Core Course\t\t Theory+Lab\n";
	cout << "\t\t SC330\t\tBusiness Ethics\t\t\t 3\t\t Elective Course\t Theory\n";
	cout << "\t\t SS171\t\tPakistan Studies\t\t 2\t\t Core Course\t\t Theory\n";
	cout << "\n\n\n";

	cout << "Fall 2018\n";
	cout << "\t\t CC2111w\tObject Oriented Programming\t 4\t\t Core Course\t\t Theory+Lab\n";
	cout << "\t\t CC2211w\tDigital Logic and Design\t 4\t\t Core Course\t\t Theory+Lab\n";
	cout << "\t\t CS390\t\tSoftware Engineering\t\t 3\t\t Core Course\t\t Theory\n";
	cout << "\t\t EN201\t\tCommunication Skills/English III 3\t\t Core Course\t\t Theory\n";
	cout << "\t\t MA150\t\tProbability and Statistics\t 3\t\t Core Course\t\t Theory\n";
	cout << "\t\t MK210\t\tPrinciples of Marketing\t\t 3\t\t Elective Course\t Theory\n";
	cout << "\n\n\n";

	cout << "Spring 2019\n";
	cout << "\t\t CC2411w\tData Structures and Algorithms\t 4\t\t Core Course\t\t Theory+Lab\n";
	cout << "\t\t CC2711w\tSoftware Engineering\t\t 3\t\t Core Course\t\t Theory\n";
	cout << "\t\t CS2221w\tAssembly Language\t\t 3\t\t Core Course\t\t Theory+Lab\n";
	cout << "\t\t MA103\t\tCalculus II\t\t\t 3\t\t Core Course\t\t Theory\n";
	cout << "\t\t SD420\t\tForeign Language\t\t 3\t\t Elective Course\t Theory\n";
	cout << "\n\n\n";

	cout << "Fall 2019\n";
	cout << "\t\t CC2421w\tIntroduction to Database Systems 4\t\t Core Course\t\t Theory+Lab\n";
	cout << "\t\t CC3611w\tCommunication  Networks\t\t 4\t\t Core Course\t\t Theory+Lab\n";
	cout << "\t\t EN114\t\tEnglish IV\t\t\t 3\t\t Core Course\t\t Theory\n";
	cout << "\t\t CS3141w\tTheory of Automata\t\t 3\t\t Core Course\t\t Theory\n";
	cout << "\t\t LM150\t\tPsychology\t\t\t 3\t\t Elective Course\t Theory\n";
	cout << "\n\n"; for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;
}
void Feedback(void)
{
	Heading();
	cout << "\n\n\t\t\t\t\t\t";
	for (int rep = 1; rep <= 7; rep++) cout << char(219); cout << " FEEDBACK "; for (int rep = 1; rep <= 7; rep++) cout << char(219);
	cout << "\n\t";
}
void Faculty_Menu(void)
{
	Heading();
	cout << "\n\n\t\t\t\t\t\t";

	for (int rep = 1; rep <= 5; rep++) cout << char(219); cout << " FACULTY MENU "; for (int rep = 1; rep <= 5; rep++) cout << char(219);

	cout << "\n\n\n\n";

	cout << "\t\t\t\t\t\t      1. Profile\n\n";
	cout << "\t\t\t\t\t\t      2. Courses\n\n";
	cout << "\t\t\t\t\t\t      3. Notification\n\n";
	cout << "\t\t\t\t\t\t      4. Logout\n\n";

}
void Notification(void)
{
	system("cls");
	Heading();

	cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t"; for (int rep = 1; rep <= 36; rep++) cout << char(219);
	cout << "\n\t\t\t\t\t" << char(219) << char(219) << "\t\t\t\t  " << char(219) << char(219);
	cout << "\n\t\t\t\t\t"; cout << char(219) << char(219) << "         No Notifcation         " << char(219) << char(219);
	cout << "\n\t\t\t\t\t" << char(219) << char(219) << "\t\t\t\t  " << char(219) << char(219);
	cout << "\n\t\t\t\t\t"; for (int rep = 1; rep <= 36; rep++) cout << char(219);
	cout << "\n\t\t\t\t\t\t\t  ";


}
void availablecoursesforFac(void)
{
	cout << "\n";
	cout << "________________________________________________________________________________________________________________________\n\n";
	cout << "\t Course ID\t Course Title\t\t\t\t Section\n";
	cout << "________________________________________________________________________________________________________________________\n\n";

	cout << "\n\t EN20521 \t Communication Skills/English III\t\t\t\t V10";
	cout << "\n\t CC2211w \t Programming Fundamentals\t\t\t\t C24";
	cout << "\n\t CC2111w \t English-II\t\t\t\t V10";
	cout << "\n\t MA3150 \t Linear Algebra\t\t\t V10";
	cout << "\n\t CC2715w\t Basic Electronics\t\t\t\t C3";
	cout << "\n\t CC1111w \t Pakistan Studies\t\t\t\t F3";
	cout << "\n\t CC16611w \t Digital Logic and Design\t\t\t\t FD8";
	cout << "\n\t SS171  \t Object Oriented Programming\t\t\t\t K9";
	cout << "\n\t CC1391w \t Probability and Statistics\t\t\t N5";
	cout << "\n\t SS171 \t\t Software Engineering\t\t\t\t H3";
	cout << "\n\t PH121 \t\t Introduction to Database Systems\t\t\t\t J3";
	cout << "\n\t CC6111w \t Computer and Communication Networks\t\t\t\t J6";
	cout << "\n\t MA210 \t\t Theory of Automata\t\t\t\t Z3";
	cout << "\n\t HG210 \t\t Calculus II\t\t\t\t W5\n\n";
}
void Loading(void)
{
	cout << "\n\n\n\n\n\n";
	cout << "\n\n\n\t\t\t\t\t\tCOURSE MANAGEMENT SYSTEM";
	cout << "\n\n\n\n\n\n";
	cout << "\n\t\t\t\t\t\t\t";
	cout << "Loading...\n";

	cout << "\n"; for (int rep = 1; rep <= 120; rep++) cout << "_"; cout << endl;
	cout << "\n\n"; for (int rep = 1; rep <= 120; rep++) cout << "_"; cout << endl << endl;

	gotoxy(0, 15);

	cout << "\n\n\n\n\n  ";
	for (int rep = 1; rep <= 5; rep++) { cout << char(219); delay(60); }
	for (int rep = 1; rep <= 10; rep++) { cout << char(219); delay(50); }
	for (int rep = 1; rep <= 25; rep++) { cout << char(219); delay(40); }
	for (int rep = 1; rep <= 76; rep++) { cout << char(219); delay(15); }


	delay(700);

	system("CLS");
	Beep(700, 100);
}
//DEFINITION/////DEFINITION/////DEFINITION/////DEFINITION/////DEFINITION/////DEFINITION/////DEFINITION/////DEFINITION/////DEFINITION/////DEFINITION/////DEFINITION/////
