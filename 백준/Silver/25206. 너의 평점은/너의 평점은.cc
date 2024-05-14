#include <iostream>
#include <string>
using namespace std;

double gradeValue(string grade) {
    if (grade == "A+") return 4.5;
    else if (grade == "A0") return 4.0;
    else if (grade == "B+") return 3.5;
    else if (grade == "B0") return 3.0;
    else if (grade == "C+") return 2.5;
    else if (grade == "C0") return 2.0;
    else if (grade == "D+") return 1.5;
    else if (grade == "D0") return 1.0;
    else if (grade == "F") return 0.0;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string subject, grade;
    double score;
    double cnt = 0, sum = 0;
    for (int i = 0; i < 20; i++) {
        cin >> subject >> score >> grade;
        if (grade == "P") {
            continue;
        }
        cnt += score;
        sum += (gradeValue(grade) * score);
    }
    cout << sum / cnt;
}