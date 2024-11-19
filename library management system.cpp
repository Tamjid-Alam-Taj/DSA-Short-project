#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    int id;
    string title;
    string author;

    void display() const {
        cout << "ID: " << id << "\nTitle: " << title << "\nAuthor: " << author << endl;
    }
};

class Library {
private:
    vector<Book> books;
    const string filename = "library_data.txt";

    void saveToFile() {
        ofstream file(filename);
        for (const auto& book : books) {
            file << book.id << "\n" << book.title << "\n" << book.author << "\n";
        }
        file.close();
    }

    void loadFromFile() {
        ifstream file(filename);
        if (!file.is_open()) return;

        Book book;
        while (file >> book.id) {
            file.ignore(); // Ignore the newline after ID
            getline(file, book.title);
            getline(file, book.author);
            books.push_back(book);
        }
        file.close();
    }

public:
    Library() {
        loadFromFile();
    }

    ~Library() {
        saveToFile();
    }

    void addBook() {
        Book book;
        cout << "Enter Book ID: ";
        cin >> book.id;
        cin.ignore();
        cout << "Enter Book Title: ";
        getline(cin, book.title);
        cout << "Enter Book Author: ";
        getline(cin, book.author);
        books.push_back(book);
        cout << "Book added successfully!\n";
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "No books available.\n";
            return;
        }
        for (const auto& book : books) {
            book.display();
            cout << "-----------------\n";
        }
    }

    void searchBook() {
        string query;
        cout << "Enter title or author to search: ";
        cin.ignore();
        getline(cin, query);

        bool found = false;
        for (const auto& book : books) {
            if (book.title.find(query) != string::npos || book.author.find(query) != string::npos) {
                book.display();
                cout << "-----------------\n";
                found = true;
            }
        }
        if (!found) {
            cout << "No matching books found.\n";
        }
    }

    void deleteBook() {
        int id;
        cout << "Enter Book ID to delete: ";
        cin >> id;

        auto it = books.begin();
        while (it != books.end()) {
            if (it->id == id) {
                it = books.erase(it);
                cout << "Book deleted successfully!\n";
                return;
            } else {
                ++it;
            }
        }
        cout << "Book not found.\n";
    }
};

int main() {
    Library library;
    int choice;

    do {
        cout << "\n--- Library Management System ---\n";
        cout << "1. Add Book\n2. Display All Books\n3. Search Book\n4. Delete Book\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.displayBooks();
                break;
            case 3:
                library.searchBook();
                break;
            case 4:
                library.deleteBook();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

