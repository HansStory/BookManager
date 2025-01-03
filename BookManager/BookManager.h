#pragma once
#include <string>

using namespace std;

class Book {
public:
    string title;
    string author;

    Book();
    Book(const string& title, const string& author);
};

class BookManager {
private:
    vector<Book> books;

public:
    void addBook(const string& title, const string& author);
    void displayAllBooks() const;
    void searchByTitle(const string& title);
    void searchByAuthor(const string& author);
};