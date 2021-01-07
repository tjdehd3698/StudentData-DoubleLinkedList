#include"double linked list.h"

void L_list::push(string name, int id){
        Node* newNode;
        newNode = new Node(0,name, id, 0);

        if (dummy->link == nullptr) {
            dummy->link = newNode;
            dummy->pre = newNode;
            newNode->link = dummy;
            newNode->pre = dummy;
        }
        else {
            if (dummy->link->id > newNode->id) {
                dummy->link->pre = newNode;
                newNode->link = dummy->link;
                newNode->pre = dummy;
                dummy->link = newNode;
            }
            else {
                scan = dummy->link;
                while ((scan->id < newNode->id)&&(scan->link != dummy)) {
                    scan = scan->link;
                }
                if (scan->id > newNode->id) {
                    newNode->link = scan;
                    newNode->pre = scan->pre;
                    scan->pre->link = newNode;
                    scan->pre = newNode;
                }
                else {
                    scan->link = newNode;
                    newNode->link = dummy;
                    newNode->pre = scan;
                    dummy->pre = newNode;
                }
            }
        }
    }
void L_list::remove(int id) {
    scan = dummy->link;
    while (scan->id != id) {
        scan = scan->link;
    }
    if (scan->link == dummy) {
        scan->pre->link = dummy;
        scan->link->pre = scan->pre;
        delete scan;
    }
    else {
        scan->pre->link = scan->link;
        scan->link->pre = scan->pre;
        delete scan;
    }
}
void L_list::display() {
    scan = dummy->link;
    cout << endl;
    while (scan != dummy && scan != nullptr) {
        cout << scan->id << " " << scan->name << " ";
        scan = scan->link;
        cout << endl;
    }
    cout << endl;
}
void L_list::reverse_dis() {
    scan = dummy->pre;
    cout << endl;
    while (scan != dummy && scan != nullptr) {
        cout << scan->id << " " << scan->name << " ";
        scan = scan->pre;
        cout << endl;
    }
    cout << endl;
}
void L_list::particular_dis(string name) {  //Ư���л����� ���
    Node* check;
    scan = dummy->link;
    cout << endl;
    while (scan->name != name) {
        scan = scan->link;
    }
    check = scan;
    do{
        cout << scan->id << " " << scan->name << " ";
        scan = scan->link;
        if (scan == dummy)scan = scan->link;
        cout << endl;
    } while (scan != check);
}
void L_list::osdata(char* txt) {
    ofstream os;
    scan = dummy->link;
    os.open(txt);
    while (scan != dummy && scan != nullptr) {
        os << scan->id << " " << scan->name;
        if(scan->link!=dummy)os << endl;
        scan = scan->link;
    }
    os.close();
}
void L_list::menu() {
    cout << "====================================" << endl;
    cout << "(1)�� �л� �Է�" << endl;
    cout << "(2) �л� ����" << endl;
    cout << "(3) �й� ������ ��ü ��� " << endl;
    cout << "(4) �й� �������� ��ü ��� " << endl;
    cout << "(5) Ư�� �л����� ��ü ��� " << endl;
    cout << "(6) ���Ͽ� �����ϰ� ���� " << endl;
    cout << "====================================" << endl;
    cout << "���ϴ� ����� �����ϼ��� : ";
}
int L_list::findId(int id) {
    scan = dummy->link;
    while ((scan != dummy) && (scan->id != id)) {
        scan = scan->link;
    }
    if (scan == dummy) return 1;
    else return 0;
}
int L_list::findName(string name) {
    scan = dummy->link;
    while ((scan != dummy) && (scan->name != name)) {
        scan = scan->link;
    }
    if (scan == dummy) return 1;
    else return 0;
}