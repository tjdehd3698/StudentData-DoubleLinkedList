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
            cout << "학번과 이름을 입력하세요 : ";
            cin >> id >> name;
            a1.push(name, id);
            break;
        case 2:
            if (a1.getDummylink() != nullptr && a1.getDummylink() != a1.getDummy()) {
                cout << "학번을 입력하세요 :";
                cin >> id;
                if (a1.findId(id) == 1) {
                    cout << "입력하신 학번이 없습니다." << endl;
                    break;
                }
                a1.remove(id);
                break;
            }
            else {
                cout << "학생이 없습니다." << endl;
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
                cout << "학생명을 입력하시오:";
                cin >> name;
                if (a1.findName(name) == 1) {
                    cout << "입력하신 이름이 없습니다." << endl;
                    break;
                }
                a1.particular_dis(name);
                break;
            }
            else {
                cout << "학생이 없습니다." << endl;
                break;
            }
        case 6:
            a1.osdata(argv[1]);
            cout << "종료합니다.^0^";
            break;
        }
    } while (num != 6);

    return 0;
}