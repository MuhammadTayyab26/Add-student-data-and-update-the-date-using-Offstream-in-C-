#include<iostream>
using namespace std;
#include<conio.h>
#include<fstream>
struct student
{
	int rollno;
	char name[30];
	int marks;
};
int main()
{
	student *s=new student[3];
		ofstream ofs("Student.bin");
		int i=0;
		for(i=0;i<3;i++)
		{
			cout<<"enter Rollno"<<endl;
			cin>>(s+i)->rollno;
			cout<<"enter Name"<<endl;
			cin>>(s+i)->name;
			cout<<"enter Marks"<<endl;
			cin>>(s+i)->marks;
			ofs.write(reinterpret_cast<char*>(&(s[i])),sizeof(s[i]));
		}
		ofs.close();
	ifstream ifs("Student.bin");
	for(i=0;i<3;i++)
	{
		ifs.read(reinterpret_cast<char*>(&(s[i])),sizeof(s[i]));
	}
	ifs.close();
	int Mod_rollno;
	int loc=-1;
	cout<<"Enter rollno you want to modify"<<endl;
	cin>>Mod_rollno;
	ofstream ofs1("temp.bin");
	for(i=0;i<3;i++)
	{
		if((s+i)->rollno==Mod_rollno)
		{
				cout<<"enter Rollno"<<endl;
				cin>>(s+i)->rollno;
				cout<<"enter Name"<<endl;
				cin>>(s+i)->name;
				cout<<"enter Marks"<<endl;
				cin>>(s+i)->marks;
		}
		else
		{
			loc=i;
		}
			ofs1.write(reinterpret_cast<char*>(&(s[i])),sizeof(s[i]));
	}
	if(loc==-1)
	{
		cout<<"No record found"<<endl;
	}
	else
	{
		ifstream ifs1("temp.bin");
		ofstream ofs2("student.bin");
		student *s1=new student[3];
		cout<<endl;
		cout<<endl;
		cout<<"!!!! modified data !!!!"<<endl;
		for(i=0;i<3;i++)
		{
			ifs1.read(reinterpret_cast<char*>(&(s1[i])),sizeof(s1[i]));
			ofs2.write(reinterpret_cast<char*>(&(s1[i])),sizeof(s1[i]));
			cout<<"Rollno : "<<(s+i)->rollno<<endl;
			cout<<"Name : "<<(s+i)->name<<endl;
			cout<<"Marks : "<<(s+i)->marks<<endl;
		}
			cout<<"!!! Data Has been modified !!!"<<endl;
	}
	getch();
	return 0;
}
