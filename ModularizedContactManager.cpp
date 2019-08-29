#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <limits>

using namespace std;

                                                                                // function declarations
void getname();
void sort();
void sortr();
void print();
void search();
void menu();
string end();

                                                                                //variable declarations
string name[10] = {" "};
string number[10] = {};

int main()
{
    cout<< "Welcome to your Contact Manager Program"<<endl;
    menu();
    return 0;
}
                                                                                    //functions definitions
void menu()
{
    
    int menuoption = 0;
    cout<<endl<<endl<<endl<<endl;                                               //display menu options screen
    cout<<"Menu"<<endl
            <<"1. Input data"<<endl
            <<"2. Sort data Ascending"<<endl
            <<"3. Sort data Descending"<<endl
            <<"4. Print All Data"<<endl
            <<"5. Search for individual in the data"<<endl
            <<"6. End Program"<<endl;
    cout<<endl<<endl<<"Choose an option and press enter:"<<endl;

    cin>>menuoption;                                                            //get menu option
    cout<<endl<<endl<<endl<<endl;
   
    switch(menuoption)                                                          //switch to organize menu options
        {     
        case 1:
            cin.ignore(1);                                                       //ignores the option the user entered for menu, therefore not skipping first entry of names in getname function
            getname();
            break;
        case 2:
            sort();
            break;
        case 3:
            sortr();
            break;
        case 4:
            print();
            break;
        case 5:
            search();
            break;
        case 6:
            cout<<"END PROGRAM"<<endl;
            end();
            break;
        default:
            cout << "INVALID ENTRY" << endl<<"Try option 1, 2, 3, 4, 5, or 6"<<endl;;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(),'\n');                 //this ignores the max amount of characters up until \n incase the user entered a lot of characters for the cin menu option
            break;
        }
     
    menu();
}
void getname()                                                               
{
    for (int i = 0; i < 10; i += 1)                                             //loop to enter all ten names and numbers into the parallel arrays
    {               
        cout<<endl<<endl<<endl<<endl<< "Enter Name "                            
                << i + 1 << ": ";
        getline(cin, name[i]);
        cout << "Enter Phone Number "
                << i + 1 << ": ";
        getline(cin, number[i]);
        cout << endl;
    }
    
}
void sort()
{
    string temp2 = "";
    string temp = "";
    int i = 0;
    int j = 0;

    for (j = 0; j < 11; j++)                                                    // begins looping for the bubble sort method we learned, 
    {
        for (i = 0; i < 9 - j; i++)
        {
            if ( name[i] > name[i + 1] )
            {
                temp = name[i];                                                 //here the swapping starts based on the condition, in this case we want ascension, but also
                temp2 = number[i];                                              //our names and numbers to change positions so they still correlate to the original pairs
                name[i] = name[i + 1];
                number[i] = number[i +1];
                name[i + 1] = temp;
                number[i+1] = temp2;
            } 
        }
    }
}
void sortr()                                                                    //same as above function but for descending names
{
    string temp2 = "";
    string temp = "";
    int i = 0;
    int j = 0;

    for (j = 0; j < 11; j++)
    {
        for (i = 0; i < 9 - j; i++)
        {
            if ( name[i] < name[i + 1] )
            {
                temp = name[i];
                temp2 = number[i];
                name[i] = name[i + 1];
                number[i] = number[i +1];
                name[i + 1] = temp;
                number[i+1] = temp2;
            } 
        }
    }
}
void print()
{
    cout<<endl<<endl<<endl<<endl;                                                           //extra return lines help divide when something new appears on the screen so it doesn't look smashed
    int index = 0;
    cout << left << setw(15) << "First: " << setw(15) << "Number: " << endl;                // added some spacing in the print methods to make the output look a little cleaner
    for(index = 0; index < 10; index++)
    {
    cout << left << setw(12) << name[index]
    << setw(10) << number[index] << endl;
    }
}
void search()
{
    int index = -1;
    string tempName = "-2147483648";

    cout<<endl<<endl<<endl<<endl;
    cout<<"Enter Name to Search"<<endl;
    cin >> tempName;

    for(index = 0; index < 10; index++)                                         //loops through the arrays to search for a specific name
    {
        if(name[index] == tempName)
        {
            break;
        }
    }

    if(index > 9)
    {
        cout<<endl<<endl<<endl<<endl;
        cout << left << "Name: " << setw(15) << tempName << " was not found." << setw(15) << endl;
    }
        else
    {
        cout<<endl<<endl<<endl<<endl;
        cout << left << "Name: " << setw(15) << tempName << " Number: "<< setw(15) << number[index]<<endl;
    }
}
string end()                                                                            //simple function for ending the program
{
    return 0;
}