#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include<strstream>
#include<sstream>
#include<bits/stdc++.h>
#include<conio.h>

using namespace std;

class RandomDisplay;
class Displayy;
class BuyCar;
class Registration;
class Admin;
class Update;
class UserManual;


class RandomDisplay
{
public:
     virtual void display() { }
};

class Displayy: public RandomDisplay
{
public:
     void display()
     {
          cout<<"\n\n";

     string line;

     ifstream myfile ("item.txt", ios::in);

     if (myfile.is_open())
          {
               while ( getline (myfile,line) )
               {
                    cout << line << '\n';
     }
     myfile.close();
     }
     else
          cout << "Unable to open file";
     }
};

class Registration{
    //int n=0,i;
    string name;

public:
     //int cost;
     string car,cost;
     void Car(string x,string y)
{
     car=x;
     cost =y;
}
void file_write()     {
       ofstream outf("item4.txt");
       ofstream fout("item2.txt", ios::app);
       cout<<endl<<"Registration : "<<endl;
       cout<<"Owner name:  ";
       //cin>>name;
       cin.ignore();
       getline(cin,name);

       cout<<"\n";

      outf<<name<<",";
      fout<<name<<",";

      outf<<car<<",";
      fout<<car<<",";

      outf<<cost<<"\n";
      fout<<cost<<"\n";

      outf.close();
      fout.close();
      }
      void file_read()
      {
      ifstream inf("item4.txt");

      getline(inf,name,',');
      getline(inf,car,',');
      getline(inf,cost);

     cout<<"\n";


      cout<<"Owner Name: "<<name<<"\n";

      cout<<"Car:  "<<car<<"\n";

      cout<<"Price:  "<<cost<<" "<<"Taka"<<"\n\n\n";


      inf.close();
      }

      };



class Update
{
public:
     void update_recode(int x,string y)
{

	// File pointer
	fstream fin, fout;

	// Open an existing record
	fin.open("item.txt", ios::in);

	// Create a new file to store updated data
	fout.open("itemnew.txt", ios::out);

	int count = 0, i;
	char sub;
	int index;
	string line, word,temp;
	vector<string> row;
	string position;

	while (fin>>temp) {
          if (fin.is_open())
          {

		row.clear();

		getline(fin, line);
		stringstream s(line);

		while (getline(s, word, '.')) {
			row.push_back(word);
		}
		stringstream p(row[0]);
		int pos=0;
		p>>pos;

		int row_size = row.size();

		if (pos == x) {
               count = 1;
			stringstream convert;

			// sending a number as a stream into output string
			convert << x;

			position= convert.str();

			 //the str() converts number into string
			row[4] = y;

			if (!fin.eof()) {
				for (i = 0; i < row_size - 1; i++) {

					if(i==4)
                         {
                              fout <<" . " << y<<"\n\n";
                         }
                         else
                         {
                              fout << ". "<<row[i] ;
                         }
				}


                         if(i==4)
                         {
                              fout <<".            " << y<<"\n\n";
                         }
                         else
                         {
                              fout << ". " << row[row_size - 1] << "\n\n";

                         }
			}
		}
		else {
			if (!fin.eof()) {
				for (i = 0; i < row_size - 1; i++) {

                              fout <<". "<< row[i] ;
                              //cout<<"2"<<endl;

				}


                              fout << ". " << row[row_size - 1] << "\n\n";
                              //cout<<" "<< row[0]<<"\n"<<row[3]<<"4"<<endl;

			}
		}
		if (fin.eof())
			break;
	}
	}
	if (count == 0)
		cout << "Record not found\n";

	fin.close();
	fout.close();

	// removing the existing file
	remove("item.txt");

	// renaming the updated file with the existing file name
	rename("itemnew.txt", "item.txt");
}

};


class Admin: public Displayy,public Update
{
public:
    void MainAdmin()
    {

 A:    int x,i=1;
      char bacck;
     cout<<"\n\n"<<"        1. Register a new car"<<"\n"<<"        2.Update Car data"<<"\n"<<"        3.See Buyer List"<<"\n"<<"        4.Back to Main"<<"\n\n"<<"        "<<"Press 1 / 2 / 3 / 4 :   ";
     cin>>x;
     switch(x)
     {

     case 1:
     {
     //void update_record()
     {
          system("cls");

     display();
	// File pointer
	fstream fin, fout;

	// Open an existing record
	fin.open("item.txt", ios::in);

	// Create a new file to store updated data
	fout.open("itemnew.txt", ios::out);

	int count = 0, i;
	int index;
	string line, word,sl,brand,model,cost,remain;
	vector<string> row;

	cout << "Enter serial no: ";
	cin >> sl;
	row.push_back(sl);

	// Get the data to be updated
	cout << "Enter Brand: ";
	cin >> brand;
	row.push_back(brand);

	cin.ignore();
	cout << "Enter model: ";
	getline(cin,model);
	row.push_back(model);

	cout << "Enter Price: ";
	//cin >> cost;
	getline(cin,cost);
	row.push_back(cost);

	cout << "Enter item available: ";
	cin >> remain;
	row.push_back(remain);

     if (fin.is_open())
          {
               while ( getline (fin,line) )
               {
                    fout << line << '\n';
     }
     fin.close();
    // fout.close();
     }
     else
          cout << "Unable to open file";

     fout<<".       "<<row[0];
     fout<<".            "<<row[1];
     fout<<"        .          "<<row[2];
     fout<<"      .               "<<row[3];
     fout<<"      .            "<<row[4]<<"\n\n";

	fout.close();

	// removing the existing file
	remove("item.txt");

	// renaming the updated file with the existing file name
	rename("itemnew.txt", "item.txt");
	cout<<"\n\n"<<"     Update Complete!  "<<"\n\n";
	display();

     cout<<"\n\n"<<"  Do you want to back?  Y/N :   ";
     cin>>bacck;

     if(bacck=='Y')
     {
          system("cls");
          goto A;
     }
     else
     {
          exit(0);
     }


}
      break;

     }

     case(2):
     {
          system("cls");
          display();
          int no;
          string rem;
          cout<<"\n\n"<<"    Enter the serial no of the car you want to update: ";
          cin>>no;
          cout<<"\n\n"<<"    Enter total available car : ";
          cin>>rem;

          update_recode(no,rem);
          cout<<"\n\n"<<"     Update Complete!  "<<"\n\n";
          display();
          cout<<"\n\n"<<"  Do you want to back?  Y/N :   ";
          cin>>bacck;

     if(bacck=='Y')
     {
          system("cls");
          goto A;
     }
     else
     {
          exit(0);
     }


       break;
     }
     case(3):
     {
         // void file_read()
      {
           system("cls");
           string name,car,cost;
      ifstream inf("item2.txt");
      while(!inf.eof())
      {

      getline(inf,name,',');
      getline(inf,car,',');
      getline(inf,cost);

     cout<<"\n";


      cout<<"Owner Name: "<<name<<"\n";

      cout<<"Car:  "<<car<<"\n";

      cout<<"Price:  "<<cost<<"Taka"<<"\n\n\n";

      }
      inf.close();
      cout<<"\n\n"<<"  Do you want to back?  Y/N :   ";
      cin>>bacck;

     if(bacck=='Y')
     {
          system("cls");
          goto A;
     }
     else
     {
          exit(0);
     }

      }
      break;
     }
     case(4):
     {
          system("cls");
          break;
     }
     }



    }
};


class BuyCar : public Displayy, public Registration,public Update
{
public:
     void Display()
     {

 A:   display();

       string line;

     fstream myfile,fout;

     myfile.open("item.txt", ios :: in);

///   DIsplay on Console

     int a,check,count=0;

     cout<<endl<<endl<<"            Select a car: ";

     cin>>a;

     cout<<endl<<endl<<endl;

     	vector<string> row;
	string word, temp;

	while (myfile >> temp) {
         // for(int i=0;;i++)
          if (myfile.is_open())
          {
		row.clear();

		getline(myfile, line);

		stringstream s(line);

		while (getline(s, word, '.')) {

			row.push_back(word);
		}

		stringstream p(row[0]);
		p>>check;

		if (check == a) {

			count = 1;
			cout << "Serial Number: " << row[0] << "\n";
			cout << "Brand: " << row[1] << "\n";
			cout << "Model: " << row[2] << "\n";
			cout << "Price: " << row[3] << "\n";
			cout << "Item Remaining: " << row[4] << "\n";

               cout<<endl<<endl<<"         DO you Want to buy? Y/N"<<"    ";

               char p;

               cin>>p;

               switch(p)
               {
               case('Y'):
                    {
                         stringstream r(row[4]);
                         int avail=0;
		               r>>avail;
		               if(avail==0)
                         {
                              cout<<"\n\n"<<"     Sorry item unavailable!"<<"\n\n";
                              cout<<"        Want to buy another car?: 1. Yes   2. No ";
                              int f;

                              cin>>f;

                              if(f==1)
                              {
                                   system("cls");
                                  goto A;
                              }
                              else if(f==2)
                              {
                                   system("cls");
                                  break;
                              }
                         }

                         else
                         {

                         Car(row[2],row[3]);
                         file_write();

                         cout<<"Confirming...."<<endl;
                         file_read();

                         stringstream q(row[4]);
                         int item=0;
                         q>>item;
                         item=item-1;
                        // cout<<"Item remaining: "<<item<<endl;
                         string itemstr;
                         stringstream it;
                         it<<item;
                         itemstr=it.str();

                         myfile.close();
                         update_recode(a,itemstr);

                         cout<<"\n";

                         cout<<"        Confgratulations!!  Your Car is confirmed. Pay your money & take your key"<<endl<<endl;

                         cout<<"        Want to buy another car?: 1. Yes   2. No ";
                         int f;

                         cin>>f;


                         if(f==1)
                         {
                              system("cls");
                              goto A;
                         }
                         else if(f==2)
                         {
                              system("cls");
                              break;
                         }
                    }
                    }

               case('N'):
                    {
                         system("cls");
                         goto A;
                    }

                    }


			break;
          }

		}
	}




     if (count == 0)
		cout << "Record not found\n";
     //myfile.close();
     cout<<"End";



}
};



class UserManual: public Admin, public BuyCar
{
public:
     void Manual()
     {
          while(1)
          {

B:     cout<<"\n\n"<<"              01.  Admin"<<"\n"<<"              02.  User"<<"\n"<<"              03.  Exit"<<"\n\n";
     cout<<"    Press 1/2/3:      ";
     int option;
     cin>>option;
     if(option==1)
     {
C:          cout<<"\n\n"<<"   Password:     ";
          string pass;
          cin>>pass;
          if(pass=="Himel")
          {
               system("cls");
              cout<<"\n\n"<<"     Entering to the ADMIN Panel  "<<"\n\n";
              MainAdmin();
          }
          else
          {
               cout<<"\n\n\t"<<"Wrong Password"<<"\n\n\t"<<"Please try again!"<<"\n\n";
               goto C;
          }


     }
     else if(option==2)
     {
          system("cls");
          Display();
     }
     else if(option==3)
     {
          exit(0);
     }
     else
     {
          cout<<"   Wrong Choice "<<"\n";
          goto B;
     }
     }
     }
};




int main ()
{

     cout<<"\n\n\t\t\t\t\tWelcome To HIMEL's Car House\t\t\t\t\t\t\t\t\n\n";

     RandomDisplay Random,*ptr;

     Displayy Dis;

     ptr= &Dis;

     ptr->display();

     UserManual u;
     u.Manual();


  return 0;
  }
