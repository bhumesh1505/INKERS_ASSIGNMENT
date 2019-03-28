#include <bits/stdc++.h>
#include "mySTL.h"
using namespace std;

int main ()
{
    bool done = false;
    node *head = NULL;
    while(!done)
    {
        int select;
        cout << endl;
        cout << "Enter options :" << endl;
        cout << "0 for Stop" << endl;
        cout << "1 for enter File path" << endl;
        cout << "2 for sort based on size " << endl;
        cout << "3 for sort based on name " << endl;
        cout << "4 for sort based on access date" << endl;
        cout << "5 for print linked list" << endl;
        cin >> select;
        switch(select)
        {
            case 0:{
                        done = true;
                        break;
                }
            case 1:{
                        char path[1000];
                        cout << "Enter file path: " << endl;
                        cin >> path;
                        storeAttributes(&head,path);
                        break;
                }
            case 2:{
                        mySort(&head,"size");
                        cout << "List is sorted according to Size of file" << endl;
                        break;
                }
            case 3:{
                        mySort(&head,"name");
                        cout << "List is sorted according to Name of files" << endl;
                        break;
                }
            case 4:{
                        mySort(&head,"accessDate");
                        cout << "List is sorted according to Access Date of files" << endl;
                        break;
                }
            case 5:{
                        printList(head);
                        break;
                }
            default:{
                        cout << "Please select valid options only" << endl;
                        break;
                }
        }
    }
    
    return 0;
}
