#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Node {
    friend class L_list;
    string name;
    int  id;
    Node* link;
    Node* pre;
    Node(Node* p, string n, int i, Node* l) : pre(0), link(0) {
        pre = p;  name = n; id = i; link = l;
    }
};
class L_list {
    Node* head;
    Node* scan;
    Node* dummy;
public:
    L_list() :head(0), scan(0), dummy(0) {
        head = dummy = new Node(dummy, "", NULL, dummy);
    }
    ~L_list() {
        if (dummy->pre != dummy && dummy->pre != nullptr) {
            do {
                scan = dummy->pre->pre;
                delete dummy->pre;
                dummy->pre = scan;
            } while (dummy->pre != dummy);
        }
        delete dummy;
    }
    Node* getDummylink() { return dummy->link; }
    Node* getDummy() { return dummy; }
    void push(string name, int id);
    void remove(int id);
    void display();
    void reverse_dis();
    void particular_dis(string name);
    void osdata(char* txt);
    void menu();
    int findId(int id);
    int findName(string name);
};