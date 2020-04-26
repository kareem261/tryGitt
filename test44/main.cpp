#include <iostream>
#include <bits/stdc++.h>
#include<iterator>
#include <istream>
#include "FciVector.h"
using namespace std;
#ifndef FCIVECTOR_H_INCLUDED
#define FCIVECTOR_H_INCLUDED

#include<iterator>
#include <istream>
using namespace std;


template<class t>
   class FciVector
   {
       private:
        t*elements ;
        int numberOfElements;
        int capacityy ;

       public:
           int s;
        void subscriptError()
        {
            cout<<"there is an error\n";
        }

    FciVector ()
    {

        capacityy = 10;
        elements = new t[capacityy];
        numberOfElements =0;
    }



       int mySize()
   {

    return numberOfElements;

   }

       int capacity()
   {
       int counter = 0 ;
       int cap ;
       for(int i=0 ; i<capacityy ; i++)
       {
             cap = counter + i ;
       }

       return cap+1;
   }

       bool empty()
   {
      if (numberOfElements==0)
          return false ;
      else
          return true ;
   }

   void get_element (int position )
   {
       position--;
       cout<< elements[position]<<endl ;
   }

    t& operator[](const int& sub)
   {
      if (sub < 0 || sub >= capacityy)
         subscriptError();
       return elements[sub];
   }


    t* begin()
  {
     return &elements[0];
  }

      t& front ()
   {
       return elements[0] ;
   }

       t& back ()
   {
       return elements[numberOfElements-1] ;
   }

         void insert(int position , t value1)
   {
       position--;
       for (int i =0 ; i<numberOfElements ; i++)
       {
           if (position==i)
           {
               elements[i]=value1 ;
           }
       }
        for (int x = 0; x < numberOfElements; x++)
                 cout << elements[x] << " ";
                 cout << endl;
   }
       void push_back (t value)
   {
     //  if(numberOfElements == capacityy)
       //{
         //  t* new_element = new t [2*capacityy];
           //for(int i =0 ; i<capacityy ; i++)
           //{
             //  new_element[i] = elements[i];
           //}
           //delete[] elements ;
           //capacityy*=2;
      // }
        elements[numberOfElements] = value;
        numberOfElements++;
       for (int i = 0; i < numberOfElements; i++)
                 cout << elements[i] << " ";
                 cout << endl;
   }
     void pop_back ()
   {
     int x = capacityy;
     numberOfElements--;

           for (int i = 0; i < numberOfElements; i++)
                 cout << elements[i] << " ";
                 cout << endl;

   }

      void clear()
  {
       numberOfElements = 0 ;
       for (int x = 0; x < numberOfElements; x++)
            cout << elements[x] << " ";
            cout << endl;

  }
      void erase(int position)
   {
        position--;
           for (int i = position ; i<numberOfElements ; i++)
        {
            t tmp = elements[i];
            elements[i]=elements[i+1];
            elements[i+1] = tmp;
        }

     numberOfElements--;
         for (int x = 0; x < numberOfElements; x++)
                 cout << elements[x] << " ";
                 cout << endl;

   }



};


#endif // FCIVECTOR_H_INCLUDED



class Course
{
    private:
    string courseName;
    string courseCode;
    char courseGrade;
    float coursePoint;
    int courseYear;
    int courseSemester;


public:

    Course ()
    {

    }

      friend ostream & operator << (ostream &outt, const Course &p)
  {
      cout<<"=== Course === " <<endl;
       outt<< p.courseName <<endl;
       outt<<p.courseCode<<endl;
       outt<<p.courseGrade<<endl ;
       outt<<p.coursePoint<<endl ;
       outt<<p.courseYear<<endl ;
       outt<<p.courseSemester<<endl ;
        cout<<"=== Course end=== " <<endl;
       return outt;
  }


      friend istream &operator>>( istream  &inputt, Course &p ) {

         cout<< "enter the course name \n";
         inputt >> p.courseName;
         cout<< "enter the course code \n";
         inputt >> p.courseCode;
         cout<< "enter the course grade\n ";
         inputt >> p.courseGrade;
         cout<< "enter the course points\n ";
         inputt >> p.coursePoint;
         cout<< "enter the course year\n ";
         inputt >> p.courseYear;
         cout<< "enter the course semester\n ";
         inputt >> p.courseSemester;
         return inputt;
      }

};

class student
{
private:

   string sname;
   int sid;
   string sdepartment;
   FciVector<Course>obj;

public:

    student()
    {

    }


  friend ostream & operator << (ostream &out, student &c)
  {
       out<<c.sname<<endl;
       out<<c.sid<<endl;
       out<<c.sdepartment<<endl ;
       for(int i = 0 ; i< c.obj.mySize(); i++ ){
         out <<c.obj[i]<<endl;
       }
       return out;
  }


      friend istream &operator>>( istream  &input, student &c ) {

          int num ;

         cout<< "enter the student name \n";
         input >> c.sname;
         cout<< "enter the student id \n";
         input >> c.sid;
         cout<< "enter the student departmeent\n ";
         input >> c.sdepartment;
         cout<< "enter the number of courses\n ";
         input>> num ;

         for (int i=0 ; i<num ; i++)
         {
             Course oob;
             cout<< "Enter Course #" <<i+1<< "info:" <<endl ;
             input>>oob;
             c.obj.push_back(oob);

         }


         return input;
      }

};
void main_menu ()
{
    cout<< "Insert type of vector you would like to create: \n";
    cout<< "1. list of integer \n";
    cout<< "2. list of character \n";
    cout<< "3. list of string \n";
    cout<< "4. list of float \n";
    cout<< "5. list of students \n";
    cout<< "6. Exit \n";

}
void sub_menu ()
{
    int choose ;
    cout<< "What kind of operation would you like to perform? \n";
    cout<< "1. Add element.\n";
    cout<< "2. Remove last element.\n";
    cout<< "3. Insert element at certain position.\n";
    cout<< "4. Erase element from a certain position.\n";
    cout<< "5. Clear.\n";
    cout<< "6. Display first element.\n";
    cout<< "7. Display last element.\n";
    cout<< "8. Display element at certain position.\n";
    cout<< "9. Display vector size.\n";
    cout<< "10. Display vector capacity.\n";
    cout<< "11. Is empty?\n";

}


int main()
{
    label2:
    int choice , sub_choice , num_elements;
    main_menu();
    cin>>choice;
    if(choice==1)
    {

        char f ;
        FciVector<int>obj;
        cout<< "A vector of integer was created successfully.\n";
        int y ;
        label:
         sub_menu();
         cin>>sub_choice ;
        if (sub_choice==1)
        {
            int s ;
            cout<< "enter the number of elements \n";
            cin>> num_elements ;
            cout<< "Enter Elements: \n" ;
            for(int i=0 ; i<num_elements ; i++)
            {
                cin>>s;
                obj.push_back(s);
            }

            cout<< "Would you like to perform other operations? (Y/N) \n";
            cin>>f;
            if (f == 'Y')
            goto label ;
            else
                goto label2 ;

        }

        if(sub_choice == 2)
        {
            obj.pop_back();
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label ;
             else
                goto label2 ;
        }

        if (sub_choice == 3)
        {
            int p , value1;
            cout<< "enter the element position \n";
            cin>>p;
            cout<< "enter the value \n";
            cin>>value1 ;
            obj.insert(p , value1);
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label ;
             else
                goto label2 ;

        }

        if (sub_choice == 4)
        {
            int p ;
            cout<< "enter the element position \n";
            cin>>p ;
            obj.erase(p);
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label ;
             else
                goto label2 ;

        }

        if(sub_choice==5)
        {
          obj.clear();
          cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label ;
             else
                goto label2 ;
        }

        if (sub_choice == 6)
        {
            cout<<obj.front();
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label ;
             else
                goto label2 ;
        }

        if (sub_choice == 7)
        {
            cout<<obj.back();
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label ;
             else
                goto label2 ;
        }

        if(sub_choice == 8)
        {
            int l ;
            cout<< "enter the position you wanna to display \n";
            cin>>l;
          obj.get_element(l);
          cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label ;
             else
                goto label2 ;
        }

        if (sub_choice == 9)
        {
            cout<<obj.mySize();
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label ;
             else
                goto label2 ;
        }

        if (sub_choice == 10)
        {
            cout<<obj.capacity();
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label ;
             else
                goto label2 ;
        }

        if (sub_choice == 11)
        {
            cout<< obj.empty();
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label ;
             else
                goto label2 ;
        }

        }

    if (choice==2)    //char choice
    {
        char f ;
        FciVector<char>obj;
        cout<< "A vector of character was created successfully.";
        label3:
        sub_menu();
         cin>>sub_choice ;
        if (sub_choice==1)
        {
            char s ;
            cout<< "enter the number of elements \n";
            cin>> num_elements ;
            cout<< "Enter Elements: \n" ;
            for(int i=0 ; i<num_elements ; i++)
            {
                cin>>s;
                obj.push_back(s);
            }

            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label3 ;
            else
                goto label2 ;

        }

        if(sub_choice == 2)
        {
            obj.pop_back();
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label3 ;
             else
                goto label2 ;
        }

        if (sub_choice == 3)
        {
            int p ;
            char value1;
            cout<< "enter the element position \n";
            cin>>p;
            cout<< "enter the value \n";
            cin>>value1 ;
            obj.insert(p , value1);
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label3 ;
             else
                goto label2 ;

        }

        if (sub_choice == 4)
        {
            int p ;
            cout<< "enter the element position \n";
            cin>>p ;
            obj.erase(p);
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label3 ;
             else
                goto label2 ;

        }

        if(sub_choice==5)
        {
          obj.clear();
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label3 ;
             else
                goto label2 ;
        }

        if (sub_choice == 6)
        {
            cout<<obj.front();
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label3 ;
             else
                goto label2 ;
        }

        if (sub_choice == 7)
        {
            cout<<obj.back();
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label3 ;
             else
                goto label2 ;
        }

        if(sub_choice == 8)
        {
            int l ;
            cout<< "enter the position you wanna to display \n";
            cin>>l;
          obj.get_element(l);
          cout<< "Would you like to perform other operations? (Y/N) \n" ;
           cin>>f;
            if (f == 'Y')
            goto label3 ;
             else
                goto label2 ;
        }

        if (sub_choice == 9)
        {
            cout<<obj.mySize();
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label3 ;
             else
                goto label2 ;
        }

        if (sub_choice == 10)
        {
            cout<<obj.capacity();
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label3 ;
             else
                goto label2 ;
        }

        if (sub_choice == 11)
        {
            cout<< obj.empty();
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label3 ;
             else
                goto label2 ;
        }

        }

        if (choice == 3) //string vector
        {
            FciVector<string>obj ;
          cout<< "A vector of strings was created successfully.\n";
          char f ;
          label4:
          sub_menu();
         cin>>sub_choice ;
        if (sub_choice==1)
        {
            string s ;
            cout<< "enter the number of elements \n";
            cin>> num_elements ;
            cout<< "Enter Elements: \n" ;
            for(int i=0 ; i<num_elements ; i++)
            {
                cin>>s;
                obj.push_back(s);
            }

            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label4 ;
            else
                goto label2 ;

        }

        if(sub_choice == 2)
        {
            obj.pop_back();
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label4 ;
             else
                goto label2 ;
        }

        if (sub_choice == 3)
        {
            int p ;
            string value1;
            cout<< "enter the element position \n";
            cin>>p;
            cout<< "enter the value \n";
            cin>>value1 ;
            obj.insert(p , value1);
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label4 ;
             else
                goto label2 ;

        }

        if (sub_choice == 4)
        {
            int p ;
            cout<< "enter the element position \n";
            cin>>p ;
            obj.erase(p);
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label4 ;
             else
                goto label2 ;

        }

        if(sub_choice==5)
        {
         obj.clear();
         cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label4 ;
             else
                goto label2 ;
        }

        if (sub_choice == 6)
        {
            cout<<obj.front();
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label4 ;
             else
                goto label2 ;
        }

        if (sub_choice == 7)
        {
            cout<<obj.back();
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label4 ;
             else
                goto label2 ;
        }

        if(sub_choice == 8)
        {
            int l ;
            cout<< "enter the position you wanna to display \n";
            cin>>l;
          obj.get_element(l);
          cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label4 ;
             else
                goto label2 ;

        }

        if (sub_choice == 9)
        {
            cout<<obj.mySize();
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label4 ;
             else
                goto label2 ;
        }

        if (sub_choice == 10)
        {
            cout<<obj.capacity();
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label4 ;
             else
                goto label2 ;
        }

        if (sub_choice == 11)
        {
            cout<< obj.empty();
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label4 ;
             else
                goto label2 ;
        }
        }

        if (choice == 4) //vector of floats
        {
         char f ;
         FciVector<float>obj ;
         cout<< "A vector of floats was created successfully.\n";
         label5:
         sub_menu();
         cin>>sub_choice ;
        if (sub_choice==1)
        {
            float s ;
            cout<< "enter the number of elements \n";
            cin>> num_elements ;
            cout<< "Enter Elements: \n" ;
            for(int i=0 ; i<num_elements ; i++)
            {
                cin>>s;
                obj.push_back(s);
            }

            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label5 ;
            else
                goto label2 ;

        }

        if(sub_choice == 2)
        {
            obj.pop_back();
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label5 ;
             else
                goto label2 ;
        }

        if (sub_choice == 3)
        {
            int p ;
            float value1;
            cout<< "enter the element position \n";
            cin>>p;
            cout<< "enter the value \n";
            cin>>value1 ;
            obj.insert(p , value1);
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label5 ;
             else
                goto label2 ;

        }

        if (sub_choice == 4)
        {
            int p ;
            cout<< "enter the element position \n";
            cin>>p ;
            obj.erase(p);
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label5 ;
             else
                goto label2 ;

        }

        if(sub_choice==5)
        {
         obj.clear();
         cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label5 ;
             else
                goto label2 ;
        }

        if (sub_choice == 6)
        {
            cout<<obj.front();
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label5 ;
             else
                goto label2 ;
        }

        if (sub_choice == 7)
        {
            cout<<obj.back();
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label5 ;
             else
                goto label2 ;
        }

        if(sub_choice == 8)
        {
            int l ;
            cout<< "enter the position you wanna to display \n";
            cin>>l;
          obj.get_element(l);
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label5 ;
             else
                goto label2 ;
        }

        if (sub_choice == 9)
        {
            cout<<obj.mySize();
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label5 ;
             else
                goto label2 ;
        }

        if (sub_choice == 10)
        {
            cout<<obj.capacity();
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label5 ;
             else
                goto label2 ;
        }

        if (sub_choice == 11)
        {
            cout<< obj.empty();
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label5 ;
             else
                goto label2 ;
        }
        }

        if (choice == 5) // vector of student
        {
            char f ;
            FciVector<student>obj ;
            cout<< "A vector of student was created successfully.\n";
            label6:
            sub_menu();
         cin>>sub_choice ;
        if (sub_choice==1)
        {
            student s ;
            cout<< "enter the number of elements \n";
            cin>> num_elements ;
            cout<< "Enter Elements: \n" ;
            for(int i=0 ; i<num_elements ; i++)
            {
                student s ;
                cin>>s;
                obj.push_back(s);
            }

            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label6 ;
            else
                goto label2 ;

        }

        if(sub_choice == 2)
        {
            obj.pop_back();
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label6 ;
             else
                goto label2 ;
        }

        if (sub_choice == 3)
        {
            int p ;
            student value1;
            cout<< "enter the element position \n";
            cin>>p;
            cout<< "enter the value \n";
            cin>>value1 ;
            obj.insert(p , value1);
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label6 ;
             else
                goto label2 ;

        }

        if (sub_choice == 4)
        {
            int p ;
            cout<< "enter the element position \n";
            cin>>p ;
            obj.erase(p);
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label6 ;
             else
                goto label2 ;

        }

        if(sub_choice==5)
        {
         obj.clear();
         cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label6 ;
             else
                goto label2 ;
        }

        if (sub_choice == 6)
        {
            cout<<obj.front();
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label6 ;
             else
                goto label2 ;
        }

        if (sub_choice == 7)
        {
            cout<<obj.back();
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label6 ;
             else
                goto label2 ;
        }

        if(sub_choice == 8)
        {
            int l ;
            cout<< "enter the position you wanna to display \n";
            cin>>l;
          obj.get_element(l);
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label6 ;
             else
                goto label2 ;
        }

        if (sub_choice == 9)
        {
            cout<<obj.mySize();
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label6 ;
             else
                goto label2 ;
        }

        if (sub_choice == 10)
        {
            cout<<obj.capacity();
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label6 ;
             else
                goto label2 ;
        }

        if (sub_choice == 11)
        {
            cout<< obj.empty();
            cout<< "Would you like to perform other operations? (Y/N) \n" ;
            cin>>f;
            if (f == 'Y')
            goto label6 ;
             else
                goto label2 ;
        }
        }

    }
