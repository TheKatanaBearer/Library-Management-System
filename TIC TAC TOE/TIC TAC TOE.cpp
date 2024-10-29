//
//
#include <iostream>
#include<string>
using namespace std;
const int MAX_BOOKS = 50;
const int MAX_MEMBERS = 50;
const int MAX_ISSUES = 100;
//int main()
//{
//
//	int x[5]= { 1, 2, 3, 4, 5 }; 
//
//
//	int* ptr = x;
//
//
//	for (int i = 0; i < 2; i++) {
//		int temp = *(ptr + i);
//
//		*(ptr + i) = *(ptr + 4 - i);
//		*(ptr + 4 - i) = temp;
//
//	}
//	int i;
//	for (i = 0; i < 5; i++)
//		cout << x[i] << " ";
//
//}

//int* reverse(int*);
//int main() {
//	int x[5] = { 1,2,3,4,5 };
//
//	int i;
//	int* ptr=  reverse(x);
//
//	for (i = 0; i < 5; i++)
//		cout << *(ptr + i) << " ";
//
//}
//
//int* reverse(int* pt) {
//
//	int i;
//	for (i = 0; i < 2; i++) {
//		int temp = *(pt + i);
//		*(pt + i) = *(pt + 4 - i);
//		*(pt + 4 - i) = temp;
//
//	}
//
//	return pt;
//
//}


struct book {
	int id;
	string title;
	int copies;
};

struct member {
	int id;
	string name;
	int booksissued;
};

struct issue {
	int bookid;
	int memberid;
};


void addbook(book books[], int& bookcount) {
    if (bookcount >= MAX_BOOKS) {
        cout << "the library is full..cannot add anymore books ";
        return;
    }

    cout << "enter the book id " << endl;
    cin >> books[bookcount].id;

    cin.ignore();
    getline(cin, books[bookcount].title);
    cout << "enter the number of copies of this book that u are adding " << endl;

    cin >> books[bookcount].copies;

    bookcount++;

    cout << "the book has been added successfully \n";

}
    void addmember(member members[], int& membercount) {
        if (membercount >= MAX_MEMBERS) {
            cout << "the library membership is full ";
            return;
        }

        cout << "enter the members id " << endl;
        cin >> members[membercount].id;

        cin.ignore();

        cout << "enter the members name ";
        getline(cin, members[membercount].name);


        members[membercount].booksissued = 0;
        membercount++;

        cout << "the memebr has been added succesfully into the database " << endl;

    }


    void issuebook(book books[], int& bookcount, member members[], int& membercount, issue issues[], int& issuecount) {
        if (issuecount >= MAX_ISSUES) {
            cout << "issue log is full , cannot issue more books " << endl;
            return;
        }

        int bookid;
        int memberid;

        cout << "enter bookid to issue " << endl;
        cin >> bookid;

        cout << "enter the memberid to check who is issuing " << endl;

        cin >> memberid;

        int bookindex = -1;

        for (int i = 0; i < bookcount; i++) {
            if (books[i].id == bookid) {
                bookindex = i;
                break;
            }
        }

        if (bookindex == -1) {
            cout << "the books are not available \n";
            return;
        }

        else if (books[bookindex].copies <= 0) {
            cout << "no copies of the book are available " << endl;

            return;
        }

        int memberindex = -1;
        for (int i = 0; i < membercount; i++) {
            if (members[i].id == memberid) {
                memberindex = i;
                break;
            }

        }

        if (memberindex == -1) {
            cout << "the member is not found \n";
            return;
        }

        else if (members[memberindex].booksissued >= 5) {
            cout << "member has already issued the max number of books" << endl;
        }

        books[bookindex].copies--;

        members[memberindex].booksissued++;

        issues[issuecount].bookid = bookid;
        issues[issuecount].memberid = memberid;

        issuecount++;

        cout << "the book has been issued successfully\n ";



    }


    void returnbook(book books[], int& bookcount, member members[], int& membercount, issue issues[], int& issuecount) {


        int bookid;
        int memberid;

        cout << "enter the book id to return " << endl;
        cin >> bookid;


        cout << "enter the member id that u want to check " << endl;
        cin >> memberid;

        for (int i = 0; i < issuecount; i++) {
            if (issues[i].bookid == bookid && issues[i].memberid == memberid) {
                for (int j = 0; j < bookcount; j++) {
                    if (books[j].id == bookid) {
                        books[j].copies++;
                        break;
                    }
                }



                for (int k = 0; k < membercount; k++) {
                    if (members[k].id == memberid) {
                        members[k].booksissued--;
                        break;
                    }
                }


                //array deletion

                for (int h = i; h < issuecount - 1; h++) {
                    issues[h] = issues[h + 1];
                }

                issuecount--;
                cout << "the book has been returned successfully \n";
                return;
            }
        }

        cout << "no matching issue found\n ";

    }

    void displayBooks(const book books[], int bookCount) {
        cout << "Books in library:\n";
        for (int i = 0; i < bookCount; i++) {
            cout << "Book ID: " << books[i].id << ", Title: " << books[i].title << ", Copies: " << books[i].copies << "\n";
        }
    }

    void displayMembers(const member members[], int memberCount) {
        cout << "Library Members:\n";
        for (int i = 0; i < memberCount; i++) {
            cout << "Member ID: " << members[i].id << ", Name: " << members[i].name << ", Books Issued: " << members[i].booksissued << "\n";
        }
    }

    void displayIssues(const issue issues[], int issueCount) {
        cout << "Issued Books:\n";
        for (int i = 0; i < issueCount; i++) {
            cout << "Book ID: " << issues[i].bookid << ", Member ID: " << issues[i].memberid << "\n";
        }
    }



   




int main() {

	book books[MAX_BOOKS];
	int bookCount = 0;

	member members[MAX_MEMBERS];
	int memberCount = 0;

	issue issues[MAX_ISSUES];
	int issueCount = 0;

	int choice;
	
	while (true) {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Add Member\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Display Books\n";
        cout << "6. Display Members\n";
        cout << "7. Display Issues\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addbook(books, bookCount);
            break;
        case 2:
            addmember(members, memberCount);
            break;
        case 3:
            issuebook(books, bookCount, members, memberCount, issues, issueCount);
            break;
        case 4:
            returnbook(books, bookCount, members, memberCount, issues, issueCount);
            break;
        case 5:
            displayBooks(books, bookCount);
            break;
        case 6:
            displayMembers(members, memberCount);
            break;
        case 7:
            displayIssues(issues, issueCount);
            break;
        case 8:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice. Please ";

        }
    }
	


}


