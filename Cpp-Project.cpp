//DEV C++
//Computer Science Project
using namespace std;
//---------------------------------------------
// >>> HEADER FILES
//---------------------------------------------
#include<fstream>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<process.h>
//---------------------------------------------
// >>> CLASSES USED
//---------------------------------------------
class book
{
    char bno[5]; //book number(4 digit)
    char bname[15]; //book name
    char bauthor[15]; //book author
    int status; //book's status:is issued? 0 or 1
public:
    book();
    void ibook(); //input book detail
    void obook(); //show book detail
    void mbook(); //modify book detail
    char* retbno(); //return book number
    char* retbname(); //return book name
    int retstatus(); //return book status
    void statuson(); //switch on the status
    void statusoff(); //switch off the status
};
class student
{
    char sno[6]; //student number(5 digit)
    char sname[15]; //student name
    char sbno[5]; //student's book number(4 digit)
    char sbid[9]; //student's book issue date(6 character)
    int status; //student's status:already have a book? 0 or 1
public:
    student();
    void istudent(); //input student detail
    void ostudent(); //show student detail
    void mstudent(); //modify student detail
    char* retsno(); //return student's admission number 
    char* retsname(); //return student's name
    char* retsbno(); //return student's book number
    void getsbno(char bno[]); //get student's book number
    void getsbid(char date[]); //get student's book issue date
    char* retsbid(); //return student's book issue date
    int retstatus(); //return student status
    void statuson(); //switch on the status
    void statusoff(); //switch off the status
};
class summary
{
public:
    char date[9]; //date of issue/deposit(6 character
    char desc[10]; //description i.e. issue/deposit
    char sno[6]; //student number(5 digit)
    char bno[5]; //student's book number(4 digit)
    char sname[15]; //student's name
    char bname[15]; //book's name
};
//---------------------------------------------
// >>> FUNCTIONS FOR THE FILE BOOK
//---------------------------------------------
void ibfile(); //function to write in book's record file
void subfile(); //function to show unique record from book's record file
void sabfile(); //function to show all record from book's record file
void mbfile(); //function to modify a record from book's record file
void dbfile(); //function to delete a record from book's record file
//---------------------------------------------
// >>> FUNCTION FOR THE FILE STUDENT
//---------------------------------------------
void isfile(); //function to write in student's record file
void susfile(); //function to show unique record from student's record file
void sasfile(); //function to show all record from student's record file
void msfile(); //function to modify a record from student's record file
void dsfile(); //function to delete a record from student's record file
//---------------------------------------------
// >>> MAIN FUNCTIONS
//---------------------------------------------
void book_issue(); //function to issue book
void book_deposit(); //function to deposit book
void admin_menu(); //function for the admin
void opt(); //funtion for options
void further(int,int); //function for further operation
void osummary(); //function to show summary [part of admin_menu]
void combine(char[],char[],char[]);
 //function to combine student's number and name[part of osummary]
//---------------------------------------------
// >>> INTRODUCING MYSELF 
//---------------------------------------------
void myself();
//--------------------------------------------------
fstream BK,SD,SM; //BK:book, SD:student, SM:summary ->three files
book b; //variable b by class book
student s; //variable s by class student
summary sm;
//--------------------------------------------------
//---------------------------------------------
// >>> MAINS
//---------------------------------------------
int main()
{
    int c;
    myself();
    do
    {
        cout<<"\n";
        cout<<"---------------------------------------------\n"
            <<"|Main Menu| \n"
            <<"---------------------------------------------\n";
        cout<<"Choose from the following options : \n";
        cout<<"1.Book Issue\n"
            <<"2.Book Deposit\n"
            <<"3.Administrator Menu\n"
            <<"4.Exit\n";
        cout<<"\nEnter your choice : ";
        cin>>c;
        cin.ignore();
        switch(c)
        {
            case 1: book_issue();
                    break;
            case 2: book_deposit();
                    break;
            case 3: admin_menu();
                    break;
            case 4: exit(0);
            default: cout<<"\n|WRONG INPUT|\n";
        }
    } while(c!=4);
}
//---------------------------------------------
// >>> FUNCTION'S DEFINITION
//---------------------------------------------
//related to class book
void book::ibook()
{
    cout<<"Enter the book's number : ";
    gets(bno);
    cout<<"Enter the book's name : ";
    gets(bname);
    cout<<"Enter the book's author name : ";
    gets(bauthor);
}
void book::obook()
{
    cout<<"\nBook's number : "<<bno;
    cout<<"\nBook's name : "<<bname;
    cout<<"\nBook's author : "<<bauthor<<endl;
}
void book::mbook()
{
    cout<<"Enter the book's new name : ";
    gets(bname);
    cout<<"Enter the book's new author name : ";
    gets(bauthor);
}
char* book::retbno()
{
    return bno;
}
char* book::retbname()
{
    return bname;
}
int book::retstatus()
{
    return status;
}
book::book()
{
    status=0;
}
void book::statuson()
{
    status=1;
}
void book::statusoff()
{
    status=0;
}
//related to class student
void student::istudent()
{
    cout<<"Enter the admission number of the student : ";
    gets(sno);
    cout<<"Enter the name of the student : ";
    gets(sname);
}
void student::ostudent()
{
    cout<<"\nAdmssion number of the student is : "<<sno;
    cout<<"\nName of the student is : "<<sname<<endl;
}
void student::mstudent()
{
    cout<<"Enter the new name of the student : ";
    gets(sname);
}
char* student::retsno()
{
    return sno;
}
char* student::retsname()
{
    return sname;
}
char* student::retsbno()
{
    return sbno;
}
void student::getsbno(char bno[])
{
    strcpy(sbno,bno);
}
void student::getsbid(char date[])
{
    strcpy(sbid,date);
}
char* student::retsbid()
{
    return sbid;
}
int student::retstatus()
{
    return status;
}
student::student()
{
    status=0;
}
void student::statuson()
{
    status=1;
}
void student::statusoff()
{
    status=0;
}
//related to book
void ibfile()
{
    cout<<"\n";
    cout<<"---------------------------------------------\n"
        <<"|Inserting Book Record| \n"
        <<"---------------------------------------------";
    char c;
    BK.open("book.dat",ios::in|ios::out|ios::app|ios::binary);
    do
    {
        cout<<"\nEnter the details of the book : \n";
        b.ibook();
        BK.write((char*)&b,sizeof(b));
        cout<<"\nDo you want to add more records(Y/N) : ";
        cin>>c;
        cin.ignore();
    } while(c=='Y'||c=='y');
    BK.close();
}
void subfile()
{
    cout<<"\n";
    cout<<"---------------------------------------------\n"
        <<"|Showing Specific Book Record| \n"
        <<"---------------------------------------------";
    char c,bno[5];
    int found;
    do
    {
        found=0;
        BK.open("book.dat",ios::in|ios::out|ios::binary);
        cout<<"\nEnter the book number of the book you want to be shown : ";
        gets(bno);
        BK.read((char*)&b,sizeof(b));
        while(!BK.eof())
        {
            if(strcmpi(b.retbno(),bno)==0)
            {
                found=1;
                cout<<"\nDetails of the book are as follows : \n";
                b.obook();
            }
            BK.read((char*)&b,sizeof(b));
        }
        if(found==0)
            cout<<"\nBook's record do not exist.\n";
        cout<<"\nDo you want to search for more records(Y/N) : ";
        cin>>c;
        cin.ignore();
        BK.close();
    } while(c=='Y'||c=='y');
}
void sabfile()
{
    cout<<"\n";
    cout<<"---------------------------------------------\n"
        <<"|Showing All Book Record| \n"
        <<"---------------------------------------------\n";
    BK.open("book.dat",ios::in|ios::out|ios::binary);
    cout<<"Details of all the books are as follows : \n";
    BK.read((char*)&b,sizeof(b));
    while(!BK.eof())
    {
        b.obook();
        BK.read((char*)&b,sizeof(b));
    }
    BK.close();
}
void mbfile()
{
    cout<<"\n";
    cout<<"---------------------------------------------\n"
        <<"|Modifying Specific Book Record| \n"
        <<"---------------------------------------------";
    char c,bno[5];
    int found;
    do
    {
        found=0;
        BK.open("book.dat",ios::in|ios::out|ios::ate|ios::binary);
        BK.seekg(0,ios::beg);
        cout<<"\nEnter the book number of the book to be modified : ";
        gets(bno);
        BK.read((char*)&b,sizeof(b));
        while(!BK.eof())
        {
            if(strcmpi(b.retbno(),bno)==0)
            {
                found=1;
                cout<<"\nPrevious details of the book : ";
                b.obook();
                cout<<"\nEnter the new details of the book : \n";
                b.mbook();
                BK.seekg(-1*sizeof(b),ios::cur);
                BK.write((char*)&b,sizeof(b));
                cout<<"\nNew details of the book are : ";
                b.obook();
            }
            BK.read((char*)&b,sizeof(b));
        }
        if(found==0)
            cout<<"\nBook's record do not exist.\n";
        cout<<"\nDo you want to modify more records(Y/N) : ";
        cin>>c;
        cin.ignore();
        BK.close();
    } while(c=='Y'||c=='y');
}
void dbfile()
{
    cout<<"\n";
    cout<<"---------------------------------------------\n"
        <<"|Deleting Specific Book Record| \n"
        <<"---------------------------------------------";
    char c,bno[5];
    int found;
    ofstream T;
    do
    {
        found=0;
        T.open("temp.dat",ios::out|ios::binary);
        BK.open("book.dat",ios::in|ios::out|ios::binary);
        cout<<"\nEnter the book number of the book to be deleted : ";
        gets(bno);
        BK.read((char*)&b,sizeof(b));
        while(!BK.eof())
        {
            if(strcmpi(b.retbno(),bno)!=0)
            {
                T.write((char*)&b,sizeof(b));
            }
            else
                found=1;
            BK.read((char*)&b,sizeof(b));
        }
        if(found==1)
            cout<<"\nRecord successfully deleted.\n";
        if(found==0)
            cout<<"\nBook's record do not exist.\n";
        cout<<"\nDo you want to delete more records(Y/N) : ";
        cin>>c;
        cin.ignore();
        T.close();
        BK.close();
        remove("book.dat");
        rename("temp.dat","book.dat");
    } while(c=='Y'||c=='y');
}
//related to student
void isfile()
{
    cout<<"\n";
    cout<<"---------------------------------------------\n"
        <<"|Inserting Student Record| \n"
        <<"---------------------------------------------";
    char c;
    SD.open("student.dat",ios::in|ios::out|ios::app|ios::binary);
    do
    {
        cout<<"\nEnter the details of the student : \n";
        s.istudent();
        SD.write((char*)&s,sizeof(s));
        cout<<"\nDo you want to add more records(Y/N) : ";
        cin>>c;
        cin.ignore();
    } while(c=='Y'||c=='y');
    SD.close();
}
void susfile()
{
    cout<<"\n";
    cout<<"---------------------------------------------\n"
        <<"|Showing Specific Student Record| \n"
        <<"---------------------------------------------";
    char c,sno[6];
    int found;
    do
    {
        found=0;
        SD.open("student.dat",ios::in|ios::out|ios::binary);
        cout<<"\nEnter the student's admission number, you want to be shown : ";
        gets(sno);
        SD.read((char*)&s,sizeof(s));
        while(!SD.eof())
        {
            if(strcmpi(s.retsno(),sno)==0)
            {
                found=1;
                cout<<"\nDetails of the student are as follows : \n";
                s.ostudent();
            }
            SD.read((char*)&s,sizeof(s));
        }
        if(found==0)
            cout<<"\nStudent's record do not exist.\n";
        cout<<"\nDo you want to search for more records(Y/N) : ";
        cin>>c;
        cin.ignore();
        SD.close();
    } while(c=='Y'||c=='y');
}
void sasfile()
{
    cout<<"\n";
    cout<<"---------------------------------------------\n"
        <<"|Showing All Student Record| \n"
        <<"---------------------------------------------\n";
    SD.open("student.dat",ios::in|ios::out|ios::binary);
    cout<<"Details of all the students are as follows : \n";
    SD.read((char*)&s,sizeof(s));
    while(!SD.eof())
    {
        s.ostudent();
        SD.read((char*)&s,sizeof(s));
    }
    SD.close();
}
void msfile()
{
    cout<<"\n";
    cout<<"---------------------------------------------\n"
        <<"|Modifying Specific Student Record| \n"
        <<"---------------------------------------------";
    char c,sno[6];
    int found;
    do
    {
        found=0;
        SD.open("student.dat",ios::in|ios::out|ios::ate|ios::binary);
        SD.seekg(0,ios::beg);
        cout<<"\nEnter the student's admission number, you want to be modified : ";
        gets(sno);
        SD.read((char*)&s,sizeof(s));
        while(!SD.eof())
        {
            if(strcmpi(s.retsno(),sno)==0)
            {
                found=1;
                cout<<"\nPrevious details of the student : ";
                s.ostudent();
                cout<<"\nEnter the new details of the student : \n";
                s.mstudent();
                SD.seekg(-1*sizeof(s),ios::cur);
                SD.write((char*)&s,sizeof(s));
                cout<<"\nNew details of the student are : ";
                s.ostudent();
            }
            SD.read((char*)&s,sizeof(s));
        }
        if(found==0)
            cout<<"\nStudent's record do not exist.\n";
        cout<<"\nDo you want to modify more records(Y/N) : ";
        cin>>c;
        cin.ignore();
        SD.close();
    } while(c=='Y'||c=='y');
}
void dsfile()
{
    cout<<"\n";
    cout<<"---------------------------------------------\n"
        <<"|Deleting Specific Student Record| \n"
        <<"---------------------------------------------";
    char c,sno[6];
    int found;
    ofstream T;
    do
    {
        found=0;
        T.open("temp.dat",ios::out|ios::binary);
        SD.open("student.dat",ios::in|ios::out|ios::binary);
        cout<<"\nEnter the student's admission number, to be deleted : ";
        gets(sno);
        SD.read((char*)&s,sizeof(s));
        while(!SD.eof())
        {
            if(strcmpi(s.retsno(),sno)!=0)
            {
                T.write((char*)&s,sizeof(s));
            }
            else
                found=1;
            SD.read((char*)&s,sizeof(s));
        }
        if(found==1)
            cout<<"\nRecord successfully deleted.\n";
        if(found==0)
            cout<<"\nStudent's record do not exist.\n";
        cout<<"\nDo you want to delete more records(Y/N) : ";
        cin>>c;
        cin.ignore();
        T.close();
        SD.close();
        remove("student.dat");
        rename("temp.dat","student.dat");
    } while(c=='Y'||c=='y');
}
//related to main
void book_issue()
{
    cout<<"\n";
    cout<<"---------------------------------------------\n"
        <<"|Book Issue| \n"
        <<"---------------------------------------------\n";
    BK.open("book.dat",ios::in|ios::out|ios::ate|ios::binary);
    BK.seekg(0,ios::beg);
    SD.open("student.dat",ios::in|ios::out|ios::ate|ios::binary);
    SD.seekg(0,ios::beg);
    SM.open("summary.dat",ios::in|ios::out|ios::app|ios::binary);
    char bno[5],sno[6],date[9];
    int founds,foundb;
    founds=foundb=0;
    cout<<"Enter the admission number of the student : ";
    gets(sno);
    SD.read((char*)&s,sizeof(s));
    while(!SD.eof())
    {
        if(strcmpi(s.retsno(),sno)==0)
        {
            founds=1;
            if(s.retstatus()==0)
            {
                cout<<"Enter the book number : ";
                gets(bno);
                BK.read((char*)&b,sizeof(b));
                while(!BK.eof())
                {
                    if(strcmpi(b.retbno(),bno)==0)
                    {
                        foundb=1;
                        if(b.retstatus()==0)
                        {
                            cout<<"\nDetails of the book are : ";
                            b.obook();
                            b.statuson();
                            s.statuson();
                            cout<<"\nNow, just enter today's date as DD/MM/YY : ";
                            gets(date);
                            s.getsbid(date);
                            s.getsbno(bno);
                            strcpy(sm.date,date);
                            strcpy(sm.desc,"Issue");
                            strcpy(sm.sno,s.retsno());
                            strcpy(sm.sname,s.retsname());
                            strcpy(sm.bno,b.retbno());
                            strcpy(sm.bname,b.retbname());
                            SM.write((char*)&sm,sizeof(sm));
                            SD.seekp(-1*sizeof(s),ios::cur);
                            SD.write((char*)&s,sizeof(s));
                            BK.seekp(-1*sizeof(s),ios::cur);
                            BK.write((char*)&b,sizeof(b));
                            cout<<"\nBook issued successfully.\n"
                                <<"\nStudent have to return this book after 15 days.\n"
                                <<"After 15 days fine will be added @ Rs.10/day.\n";
                        }
                        else
                        {
                            cout<<"\nEnquire about it. \n"
                                <<"This book is already issued to someone else.\n";
                        }
                    }
                    BK.read((char*)&b,sizeof(b));
                }
                if(foundb==0)
                    cout<<"\nBook do not exist in record.\n";
            }
            else
                cout<<"\nStudent hadn't return the previous book.\n";
        }
        SD.read((char*)&s,sizeof(s));
    }
    if(founds==0)
        cout<<"\nStudent do not exist in record.\n";
    BK.close();
    SD.close();
    SM.close();
}
void book_deposit()
{
    cout<<"\n";
    cout<<"---------------------------------------------\n"
        <<"|Book Deposit| \n"
        <<"---------------------------------------------\n";
    SD.open("student.dat",ios::in|ios::out|ios::ate|ios::binary);
    SD.seekg(0,ios::beg);
    BK.open("book.dat",ios::in|ios::out|ios::ate|ios::binary);
    BK.seekg(0,ios::beg);
    SM.open("summary.dat",ios::in|ios::out|ios::app|ios::binary);
    char bno[5],sno[6],date[9];
    int founds,foundb;
    founds=foundb=0;
    cout<<"Enter the admission number of the student : ";
    gets(sno);
    SD.read((char*)&s,sizeof(s));
    while(!SD.eof())
    {
        if(strcmpi(s.retsno(),sno)==0)
        {
            founds=1;
            if(s.retstatus()==1)
            {
                cout<<"Enter the book number : ";
                gets(bno);
                BK.read((char*)&b,sizeof(b));
                while(!BK.eof())
                {
                    if(strcmpi(b.retbno(),bno)==0)
                    {
                        foundb=1;
                        if(b.retstatus()==1)
                        {
                            cout<<"\nDetails of the book are : ";
                            b.obook();
                            b.statusoff();
                            s.statusoff();
                            cout<<"\nNow, just enter today's date as DD/MM/YY : ";
                            gets(date);
                            s.getsbid(date);
                            strcpy(sm.date,date);
                            strcpy(sm.desc,"Deposit");
                            strcpy(sm.sno,s.retsno());
                            strcpy(sm.sname,s.retsname());
                            strcpy(sm.bno,b.retbno());
                            strcpy(sm.bname,b.retbname());
                            SM.write((char*)&sm,sizeof(sm));
                            SD.seekp(-1*sizeof(s),ios::cur);
                            SD.write((char*)&s,sizeof(s));
                            BK.seekp(-1*sizeof(s),ios::cur);
                            BK.write((char*)&b,sizeof(b));
                            cout<<"\nBook deposited successfully.\n";
                        }
                        else
                        {
                            cout<<"\nSomething went wrong. \n"
                                <<"This book is already returned to library.\n";
                        }
                    }
                    BK.read((char*)&b,sizeof(b));
                }
                if(foundb==0)
                    cout<<"\nBook do not exist in record.\n";
            }
            else
                cout<<"\nStudent hadn't issued any book.\n";
        }
        SD.read((char*)&s,sizeof(s));
    }
    if(founds==0)
        cout<<"\nStudent do not exist in record.\n";
    SD.close();
    BK.close();
    SM.close();
}

void admin_menu() {
    const int password = 12345;
    char c;
    int c1, c2;
    int pwd;

again:
    cout << "Enter the admin password: ";
    cin >> pwd;

    if (pwd == password) {
        do {
            cout << "\n";
            cout << "---------------------------------------------\n";
            cout << "| Administrator Menu |\n";
            cout << "---------------------------------------------\n";
            cout << "1. Book's record\n";
            cout << "2. Student's record\n";
            cout << "3. View summary\n";
            cout << "4. Back to Menu\n";
            cout << "\nEnter your choice: ";
            cin >> c1;

            switch (c1) {
                case 1:
                case 2:
                    cout << "\nNow, what do you want to do?\n";
                    opt();
                    cout << "\nEnter your choice: ";
                    cin >> c2;
                    cin.ignore();
                    further(c1, c2);
                    break;
                case 3:
                    osummary();
                    break;
                case 4:
                    return;
                default:
                    cout << "\n| WRONG INPUT |\n";
            }
        } while (0 == 0);
    }
    else {
        cout << "\nWARNING: You have entered the wrong password.\n";
        cout << "\nDo you want to try again? (Y/N): ";
        cin >> c;

        if (c == 'Y' || c == 'y')
            goto again;
        else
            cout << "\nGoing back to the main menu...\n";
    }
}

void opt() {
    cout << "1. Create a record\n";
    cout << "2. Display specific record\n";
    cout << "3. Display all records\n";
    cout << "4. Modify a record\n";
    cout << "5. Delete a record\n";
}

void further(int c1, int c2) {
    if (c1 == 1) {
        switch (c2) {
            case 1:
                ibfile();
                break;
            case 2:
                subfile();
                break;
            case 3:
                sabfile();
                break;
            case 4:
                mbfile();
                break;
            case 5:
                dbfile();
                break;
            default:
                cout << "\n| WRONG INPUT |\n";
        }
    }
    else if (c1 == 2) {
        switch (c2) {
            case 1:
                isfile();
                break;
            case 2:
                susfile();
                break;
            case 3:
                sasfile();
                break;
            case 4:
                msfile();
                break;
            case 5:
                dsfile();
                break;
            default:
                cout << "\n| WRONG INPUT |\n";
        }
    }
}

void osummary() {
    cout << "\n";
    cout << "---------------------------------------------\n";
    cout << "| Summary |\n";
    cout << "---------------------------------------------\n";
    cout << "=========================================================\n";
    cout << setw(7) << "Date" << setw(15) << "Description" << setw(22) << "Student's No./Name" << setw(22) << "Book's No./Name\n";
    cout << "=========================================================\n";
    char snn[20], bnn[20];
    SM.open("summary.dat", ios::in | ios::out | ios::binary);
    SM.read((char*)&sm, sizeof(sm));

    while (!SM.eof()) {
        combine(sm.sno, sm.sname, snn);
        combine(sm.bno, sm.bname, bnn);
        cout << sm.date << setw(14) << sm.desc << setw(22) << snn << setw(21) << bnn << endl;
        SM.read((char*)&sm, sizeof(sm));
    }

    SM.close();
}

void combine(char a[], char b[], char x[]) {
    strcpy(x, a);
    strcat(x, " / ");
    strcat(x, b);
}

void myself() {
    cout << "Hi! Project by Harsh Mishra." << endl;
}