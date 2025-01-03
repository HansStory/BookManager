#include <iostream>
#include <vector>
#include <string>

#include "BookManager.h"

using namespace std;

Book::Book() { }

Book::Book(const string& title, const string& author)
    : title(title), author(author) {
}

// 책 추가 메서드
void BookManager::addBook(const string& title, const string& author) {
    books.push_back(Book(title, author)); // push_back 사용
    cout << "책이 추가되었습니다: " << title << " by " << author << endl;
}

// 모든 책 출력 메서드
void BookManager::displayAllBooks() const {
    if (books.empty()) {
        cout << "현재 등록된 책이 없습니다." << endl;
        return;
    }

    cout << "현재 도서 목록:" << endl;
    for (size_t i = 0; i < books.size(); i++) { // 일반적인 for문 사용
        cout << "- " << books[i].title << " by " << books[i].author << endl;
    }
}

// 책 제목 검색 메서드
void BookManager::searchByTitle(const string& title) {
    if (books.empty()) {
        cout << "현재 등록된 책이 없습니다." << endl;
        return;
    }

    Book searchedBook;
    bool successFind = false;
    for (Book book : this->books)
    {
        if (book.title == title)
        {
            successFind = true;
            searchedBook = book;
            break;
        }
    }

    if (successFind)
    {
        cout << "책이름으로 책을 찾았습니다. 찾은 책 : " << searchedBook.title << " by " << searchedBook.author << endl;
    }
    else
    {
        cout << "검색된 책이 없습니다. 검색어 : " << title << endl;
    }
}

// 책 작가 검색 메서드
void BookManager::searchByAuthor(const string& author) {
    if (books.empty()) {
        cout << "현재 등록된 책이 없습니다." << endl;
        return;
    }

    vector<Book> searchedBooks;
    for (const Book& book : this->books)
    {
        if (book.author == author)
        {
            searchedBooks.push_back(book);
        }
    }

    if (searchedBooks.empty())
    {
        cout << "검색된 작가의 책이 없습니다. 검색어 : " << author << endl;
    }
    else
    {
        string authorBooksName;
        for (Book authorBook : searchedBooks)
        {
            authorBooksName += authorBook.title + ", ";
        }

        // 마지막 쉼표 제거
        if (!authorBooksName.empty()) {
            authorBooksName.erase(authorBooksName.size() - 2);
        }

        cout << author << "님의 책은 총 : " << searchedBooks.size() << "권이 검색됬습니다." << endl;
        cout << "책 이름은 : " << authorBooksName << "입니다." << endl;
    }
}