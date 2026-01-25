#include <iostream>
using namespace std;

int main() {

    string names[50];
    int rolls[50];
    int scores[50][5];
    double total[50];
    double average[50];
    char grade[50];

    int count = 0; //Students count


    start:
    cout << "===== STUDENT GRADE TRACKER =====\n";
    cout << "1. Add Student\n";
    cout << "2. View Students\n";
    cout << "3. Update Scores\n";
    cout << "4. Delete Student\n";
    cout << "5. Search Student\n";
    cout << "6. Exit\n\n\n";

    int num;
    cout << "Enter your choice: ";
    cin >> num;

    switch (num) {

        case 1:
            if (count >= 50) {
                cout << "You can't add any other student\n";
                break;
            }

            cout << "Enter student name: ";
            cin >> names[count];

            cout << "Enter the Roll number: ";
            cin >> rolls[count];

            for (int i = 0; i < count; i++) {
                if (rolls[i] == rolls[count]) {
                    cout << "Roll number is already exists!\n";
                    goto end_case1;
                }
            }

            total[count] = 0;

            cout << "Enter scores for 5 subjects:\n";
            for (int i = 0; i < 5; i++) {
                cin >> scores[count][i];

                if (scores[count][i] < 0 || scores[count][i] > 100) {
                    cout << "Invalid score!\n";
                    goto end_case1;
                }

                total[count] += scores[count][i];
            }

            average[count] = total[count] / 5.0;

            if (average[count] >= 90) grade[count] = 'A';
            else if (average[count] >= 80) grade[count] = 'B';
            else if (average[count] >= 70) grade[count] = 'C';
            else if (average[count] >= 60) grade[count] = 'D';
            else grade[count] = 'F';

            count++;
            cout << "Student added successfully!\n";

            end_case1:
            goto start;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        default:
            cout << "==Invalid Input==";
            break;
    }

}
