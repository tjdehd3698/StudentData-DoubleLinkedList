#include"double linked list.h"

int main(int argc, char* argv[]) {
    L_list  a1;
    ifstream is;
    string name;
    int id, check, num, size = 50;

    is.open(argv[1]);
    while (!is.eof()) {
        is >> id;
        if (is.eof())break;
        is >> name;
        a1.push(name, id);
    }
    is.close();

    do {
        a1.menu();
        cin >> num;
        switch (num) {
        case 1:
            cout << "�й��� �̸��� �Է��ϼ��� : ";
            cin >> id >> name;
            a1.push(name, id);
            break;
        case 2:
            if (a1.getDummylink() != nullptr && a1.getDummylink() != a1.getDummy()) {
                cout << "�й��� �Է��ϼ��� :";
                cin >> id;
                if (a1.findId(id) == 1) {
                    cout << "�Է��Ͻ� �й��� �����ϴ�." << endl;
                    break;
                }
                a1.remove(id);
                break;
            }
            else {
                cout << "�л��� �����ϴ�." << endl;
                break;
            }
        case 3:
            a1.display();
            break;
        case 4:
            a1.reverse_dis();
            break;
        case 5:
            if (a1.getDummylink() != nullptr && a1.getDummylink() != a1.getDummy()) {
                cout << "�л����� �Է��Ͻÿ�:";
                cin >> name;
                if (a1.findName(name) == 1) {
                    cout << "�Է��Ͻ� �̸��� �����ϴ�." << endl;
                    break;
                }
                a1.particular_dis(name);
                break;
            }
            else {
                cout << "�л��� �����ϴ�." << endl;
                break;
            }
        case 6:
            a1.osdata(argv[1]);
            cout << "�����մϴ�.^0^";
            break;
        }
    } while (num != 6);

    return 0;
}