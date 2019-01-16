/*
 * walkIn.cpp
 * 
 * Class Description: Represents the walk-in clinic patient system
 * Class Invariant: 
 *
 * Author: Kai Sackville-Hii
 * Date: January 23, 2019
 */

#include <iostream>
#include "List.h"
#include "Patient.h"

using namespace std;

int findIndexOfPatient(string cardNumber, List listCopy);

int main() 
{
    List list;
    string input = "";

    cout << "CMPT-225 Assignment 1 (January 23, 2019)" << endl
        << "(c) Walk-in Clinic Patient System, Developed by Kai Sackville-Hii." << endl
        << endl
        << "This utility will store patients medical records. There are five" << endl
        << "different actions a user can preform, entering these commands when" << endl
        << "prompted by the >>> will walk you through that actions proccess." << endl
        << endl
        << "Enter the command 'help' for documentation of each command and" << endl
        << "exactly what they do." << endl;

    // ---------- MAIN LOOP ---------- // 
    do 
    {
        cout << "\n>>> "; // user prompt
        getline(cin, input);


        // ---------- PARSING INPUT ----------//
        int indexOfSpace = -1; // index of space within input

        for(int i=0; i< input.size(); i++)
        {
            // found empty space, store it
            if(input[i] == ' ')
            {
                indexOfSpace = i;
                break;
            }
        }

        // split input on the empty space
        string command = input.substr(0, indexOfSpace);
        string payload = input.substr(indexOfSpace+1);
        cout << endl;

        // ---------- EXECUTE COMMAND ----------//
        if(command == "quit") 
        { 
            // say goodbye before user quits
            cout << "goodbye :)\n"; 
        }
        else if (command == "help")
        {
            // output help command
            cout << "Enter a command when prompted by the arrow" << endl
                << "ex: >>> <command>" << endl
                << endl
                << "where <command> is one of the following:" << endl
                << "    help           -" << endl
                << "    quit           - " << endl
                << "    add <card#>    - Adds patient, with <card#> being their care" << endl
                << "                     card number, to list." << endl
                << "    remove <card#> -" << endl
                << "    search         -" << endl
                << "    modify <card#> -" << endl
                << "    show           -" << endl;
        }
        else if(command == "add") 
        { 
            // Check that payload is not empty & that card is 10 digits
            if(payload.find_first_not_of(' ') != payload.npos && payload.size() == 10)
            {            
                Patient pNew(payload);

                string emptyVal = "To be entered"; // Input default value
                string addName = "";
                string addAddress = "";
                string addPhone = "";
                string addEmail = "";

                // Get patients info from user
                cout << "Enter patients following information. Enter empty value to" << endl
                    << "stick to default value of 'To be entered'.\n\n";

                // use getline to allow empty spaces
                cout << "Name: ";
                getline(cin, addName);
                cout << "Address: ";
                getline(cin, addAddress);
                cout << "Phone: ";
                getline(cin, addPhone);
                cout << "Email: ";
                getline(cin, addEmail);
                cout << endl;

                // set to default value if the input is all spaces
                if(addName.find_first_not_of(' ') == addName.npos) {addName = emptyVal;}
                if(addAddress.find_first_not_of(' ') == addAddress.npos) {addAddress = emptyVal;}
                if(addPhone.find_first_not_of(' ') == addPhone.npos) {addPhone = emptyVal;}
                if(addEmail.find_first_not_of(' ') == addEmail.npos) {addEmail = emptyVal;}

                // Modify patient objects members with users data (if any input, else 
                // stays default)
                pNew.setName(addName);
                pNew.setAddress(addAddress);
                pNew.setPhone(addPhone);
                pNew.setEmail(addEmail);

                list.insert(pNew);
                cout << "Patient successfully created.\n";
            }
            else
            {
                cout << "Error care card number invalid. Must have the format 'add <card#>'" << endl
                    << "where <card#> is the patients 10 digit care card number.\n";
            }
        }
        else if(command == "remove")
        {
            // check that input is not empty
            if(payload.find_first_not_of(' ') != payload.npos)
            {
                for(int it = 0; it < list.getElementCount(); it++)
                {
                    Patient patientInView = *list.valueAt(it);
                    string cardInView = patientInView.getCareCard();

                    if(cardInView == payload)
                    {
                        list.remove(patientInView);
                        cout << "Patient " << cardInView << " was removed.\n";
                    }
                }
            }   
            else
            {
                cout << "Error care card number missing. Must have the format 'remove <card#>'" << endl
                    << "where <card#> is the patients care card number.\n";
            }         
        } 
        else if(command == "show") 
        { 
            list.printAll();
        }
        else 
        { 
            cout << "Invalid command, enter 'help' to see list of valid commands.\n";
        }

    } while(input != "quit");

    return(0);
}

