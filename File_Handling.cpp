#include<fstream>
#include<iostream>
using namespace std;
class Student {
    private:
        int Rno;
        char Name[100];
        float Percentage;
        char Pass;
    public:
        void get_data();
        void put_data();
        int returnRno();
};

void Student::get_data() {
    cout<<"Enter Roll No. : ";
    cin>>Rno;
    cout<<"Enter Student Name (Use underscore _ for spaces): ";
    cin>>Name;
    cout<<"Enter Percentage : ";
    cin>>Percentage;
    if(Percentage >= 33)
        Pass = 'P';
    else
        Pass = 'F';
}

void Student::put_data() {
    cout<<"\nRoll No : "<<Rno;
    cout<<"\nName : "<<Name;
    cout<<"\nPercentage : "<<Percentage;
    cout<<"\nPass Status : "<<Pass;
}
int Student::returnRno() {
    return Rno;
}

int main() {
    Student s, s1;
    int ch = 1;
    fstream f,t;            //f for main file   and     t for temprary file
    system("cls");
    while(true)
    {
        cout<<"\n\nChoices : ";
        cout<<"\n\t1. Enter new record";
        cout<<"\n\t2. Delete a record";
        cout<<"\n\t3. Modify a record";
        cout<<"\n\t4. See all records";
        cout<<"\n\t5. See a particular record";
        cout<<"\n\t\t Press 0 for exiting : \n\t\t\t\t\t";
        cin>>ch;
        if(ch == 1)
        {
            f.open("StudentRecords.txt", ios::in | ios::out);
            s.get_data();
            f.read((char *)&s, sizeof(s));
            f.close();
        }
        else if(ch == 2)
        {
            f.open("StudentRecords.txt", ios::in | ios::out);
            int r;
            cout<<"Enter roll number of record to be deleted: ";
            cin>>r;
            t.open("temp.txt", ios::in | ios::out);
            f.seekg(0);
            while(f)
            {
                f.read((char *)&s, sizeof(s));
                if(r != s.returnRno())
                {
                    t.write((char *)&s, sizeof(s));
                }
            }
            f.close();
            t.close();
            remove("StudentRecords.txt");
            rename("temp.txt", "StudentRecords.txt");   
            cout<<"\nRecord Deleted\n";
        }
        else if(ch == 3)
        {
            int r;
            cout<<"Enter roll no of the record to be modified: ";
            cin>>r;
            cout<<"Now Enter New Data: \n";
            s1.get_data();
            f.open("StudentRecords.txt", ios::in | ios:: out);
            t.open("temp.txt", ios::in | ios::out);
            f.seekg(0);
            while(f)
            {
                f.read((char *)&s, sizeof(s));
                if(r == s.returnRno())
                {
                    t.write((char * )&s1, sizeof(s1));
                }
                else
                {
                    t.write((char *)&s, sizeof(s));
                }
            }
            f.close();
            t.close();
            remove("StudentRecords.txt");
            rename("temp.txt", "StudentRecords.txt");
        }
        else if(ch == 4)
        {
            f.open("StudentRecords.txt", ios::in | ios:: out);
            f.seekg(0);
            while(f)
            {
                f.read((char *)&s, sizeof(s));
                s.put_data();
            }
            f.close();
        }
        else if(ch == 5)
        {
            int r;
            cout<<"\nEnter Roll No of record to be shown : ";
            cin>>r;
            f.open("StudentRecords.txt", ios::in | ios:: out);
            f.seekg(0);
            f.read((char *)&s, sizeof(s));
            if(r == s.returnRno())
            {
                s.put_data();
            }
            f.close();
        }
        else if(ch == 0)
        {
            break;
        }
        else
        {
            cout<<"\nWrong Choice!!!\nTry Again ...\n";
        }
    }
}