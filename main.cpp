#include <iostream>
#include <stack>

using namespace std;

class Wood {
private:
    string name;
    int age;
    int diameter;

public:
    Wood(string n, int a, int d) : name(n), age(a), diameter(d) {}

    void print() {
        cout << "Ten: " << name << "; Tuoi: " << age << "; Duong kinh: " << diameter << endl;
    }
};

void insertAtBottom(stack<Wood>& Woodlist, Wood& wood) {
    if (Woodlist.empty()) {
        Woodlist.push(wood);
    } else {
        Wood temp = Woodlist.top();
        Woodlist.pop();

        insertAtBottom(Woodlist, wood);

        Woodlist.push(temp);
    }
}

void insertAt(stack<Wood>& WoodList, Wood& wood, int k) {
    if (k < 1 || k > WoodList.size()) {
        cout << "Vi tri chen khong hop le! " << endl;
        return;
    } else {
        stack<Wood> temp;
        while (WoodList.size() > k) {
            temp.push(WoodList.top());
            WoodList.pop();
        }

        WoodList.push(wood);

        while (!temp.empty()) {
            WoodList.push(temp.top());
            temp.pop();
        }
    }
}

int main() {
    stack<Wood> Woodlist;
    Woodlist.push(Wood("gu", 10, 10));
    Woodlist.push(Wood("lim", 20, 20));
    Woodlist.push(Wood("soi", 10, 30));
    Woodlist.push(Wood("oc cho", 35, 15));
    Wood newWood("sua", 8, 30);

    // Chèn newWood vào vị trí thứ 2
    insertAt(Woodlist, newWood, 2);

    while (!Woodlist.empty()) {
        Woodlist.top().print();
        Woodlist.pop();
    }

    return 0;
}
