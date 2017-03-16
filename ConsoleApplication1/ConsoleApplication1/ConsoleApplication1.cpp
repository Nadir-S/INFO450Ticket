// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


class TicketClass
{
private:
	static int iD;
	string issueStatus = "";
	string issueType;
	string issuePriority;
	string callerName = "";
	string descriptIssue = "";
	int numImpacted = 0;

public:

	TicketClass()
	{
		iD += 1;
		issueStatus = "OPEN";
	}

	void SetIssueStatus(string i)
	{
		issueStatus = i;
	}

	void SetIssueType(string i)
	{
		issueType = i;
	}

	void SetIssuePrioriy(string i)
	{
		issuePriority = i;
	}

	void SetCallerName(string i)
	{
		callerName = i;
	}

	void SetDescriptionIssue(string i)
	{
		descriptIssue = i;
	}

	void SetNumImpacted(int i)
	{
		numImpacted = i;
	}

	int CaptureTicket(TicketClass tArray[], int arrLength, int acount)
	{
		string userInput;
		bool again = true;
		static int counter = 0;
		do
		{
			cout << "........................" << endl;
			cout << "Open new ticket? Enter Y to continue" << endl;
			getline(cin, userInput);
			//cin >> userInput;
			if ((userInput == "Y") || (userInput == "y"))
			{
				TicketClass temp[100];
				TicketClass ticket;
				again = true;
				string input = "";
				string charInput;
				cout << "What is the name of the caller? " << endl;
				string cString = "";
				getline(cin, cString);
				ticket.SetCallerName(cString);
				cout << "Issue Type? S=Server, A=Application, C=Access" << endl;
				getline(cin, charInput);
				//cin >> charInput;
				if ((charInput == "S") || (charInput == "s"))
				{
					ticket.SetIssueType("Server");
				}
				else if ((charInput == "A") || (charInput == "a"))
				{
					ticket.SetIssueType("Application");
				}
				else if ((charInput == "C") || (charInput == "c"))
				{
					ticket.SetIssueType("Access");
				}

				cout << "Description of Issue?" << endl;
				string dString = "";
				getline(cin, dString);
				ticket.SetDescriptionIssue(dString);
				cout << "How many users impacted?" << endl;
				int itemp;
				cin >> itemp;
				cin.ignore();
				ticket.SetNumImpacted(itemp);
				if (ticket.numImpacted < 10)
					ticket.issuePriority = "LOW";
				else if ((ticket.numImpacted >= 10) && (ticket.numImpacted < 50))
					ticket.issuePriority = "MED";
				else if (ticket.numImpacted >= 50)
					ticket.issuePriority = "HIGH";
				cout << "Your Issue ID is " << ticket.iD << endl;


				temp[counter] = ticket;
				tArray[counter] = temp[counter];
				counter++;

			}
			else
			{
				again = false;
			}

			arrLength = counter;

		} while (again);

		acount = counter;
		return counter;
	}

	void ShowTickets(TicketClass tArray[], int arrLength, int counter)
	{
		cout << "........................" << endl;
		cout << "Ticket Listings:" << endl;
		cout << "........................" << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << "Ticket ID: " << tArray[i].iD << " " << "Type: " << tArray[i].issueType << endl;
			cout << "Status: " << tArray[i].issueStatus << endl;
			cout << "Description: " << tArray[i].descriptIssue << endl;
			cout << "User: " << tArray[i].callerName << endl;
			cout << "Users Impacted: " << tArray[i].numImpacted << endl;
			cout << "Priority: " << tArray[i].issuePriority << endl;
			cout << "........................" << endl;
		}
	}

	void CloseTicket(TicketClass ticket)
	{
		ticket.issueStatus = "CLOSED";
		cout << "Ticket #1 has been closed" << endl;
	}
};

int main()
{
	int counter = 0;
	TicketClass temp;
	int arrLength = 100;
	TicketClass tArray[100];

	int tmp = temp.CaptureTicket(tArray, arrLength, counter);
	temp.ShowTickets(tArray, tmp, counter);
	TicketClass firstT = tArray[0];
	temp.CloseTicket(firstT);
}


