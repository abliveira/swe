#include <iostream>
using namespace std;

class sort {
    private:
        int n = 5, m[100]; /*eg: enter 1 3 2 4 5 for sorting */
    public:
        void input();
        void algorithm();
        void display();

};
void sort::input() {
    for (int i = 0; i < n; i++)
        cin >> m[i];
}
void sort::algorithm() {
    int temp, j;
    for (int i = 1; i < n; i++) {
        j = i;
        while (j >= 1) {
            if (m[j] < m[j-1]) {
                temp = m[j];
                m[j] = m[j-1];
                m[j-1] = temp;
            }
            j--;
        }
    }
}
void sort::display() {
    cout << "Array after sorting";
    for (int i = 0; i < n; i++)
        cout << m[i];
}

int main() {
    sort s, *sp;
    sp = &s;
    sp->input();
    sp->algorithm();
    sp->display();
    return 0;
}