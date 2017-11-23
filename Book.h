/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Book.h
 * Author: dennis
 *
 * Created on November 23, 2017, 6:32 PM
 */

#ifndef BOOK_H
#define BOOK_H
#include <istream>
#include <ostream>
using std::ostream;
using std::istream;
using std::string;
using std::cout;
using std::cin;
using std::vector;

class Book {
public:

    Book() : name(""), year(0) {
    }
    Book(string n, int y) : name{n}, year{y}
    {
    }

    bool operator<(const Book &b) {
        return this->year < b.year;
    }

    bool operator>(const Book &b) {
        return this->year > b.year;
    }

    friend ostream &operator<<(ostream &output, Book &b) {
        output << b.name << " " << b.year;
        return output;
    }

    friend istream &operator>>(istream &input, Book &b) {
        getline(input, b.name);
        cin >> b.year;
        return input;
    }

    bool operator==(const Book &b) const {
        return (this->year == b.year) && (this->name == b.name);
    }
private:
    string name;
    int year;



};

#endif /* BOOK_H */

