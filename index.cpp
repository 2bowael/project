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
    cout << "6. Exit\n\n";

    int num;
    cout << "Enter your choice: ";
    cin >> num;

    switch (num) {

        case 1:
            if (count >= 50) {
                cout << "You can't add any other student\n\n";
                goto return1;
            }

            cout << "Enter student name: ";
            cin >> names[count];

            cout << "Enter the Roll number: ";
            cin >> rolls[count];

            for (int i = 0; i < count; i++) {
                if (rolls[i] == rolls[count]) {
                    cout << "Roll number is already exists!\n";
                    goto end_case;
                }
            }

            total[count] = 0;

            cout << "Enter scores for 5 subjects:\n";
            for (int i = 0; i < 5; i++) {
                cin >> scores[count][i];

                if (scores[count][i] < 0 || scores[count][i] > 100) {
                    cout << "Invalid score!\n\n\n";
                    goto end_case;
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

            cout << "\n\n";
            cout << "Student added successfully!\n\n";
            
            goto return1;
        case 2:
            for (int i = 0; i < count; i++){
                cout << "\n"<< i + 1<< "."<< names[i]<< " => {Roll Number: ";
                cout << rolls[i]<< " ,Total: ";
                cout << total[i]<< " ,Average: "<< average[i];
                cout << " ,Grade: "<< grade[i]<< " }"<< "\n\n";
            }

            goto return1;
        case 3:
        case 4:
        case 5:
            int num_1;
            cout << "Enter Roll Number To Search: ";
            cin >> num_1;

            for (int i = 0; i < count; i++){
                if (rolls[i] == num_1){
                    cout << "\n"<< i + 1<< "."<< names[i]<< " => {Roll Number: ";
                cout << rolls[i]<< " ,Total: ";
                cout << total[i]<< " ,Average: "<< average[i];
                cout << " ,Grade: "<< grade[i]<< " }"<< "\n\n";
                }else {
                    cout << "==This Roll Number Isn't Exists==\n\n";
                }
            }

            goto return1;
        case 6:
            cout << "==Thanks For Tring Our App==";
            break;
        default:
            cout << "==Invalid Input!==\n\n";
            goto return1;
    }

    return1:
            int num_0;
            cout << "Enter 0 to return: ";
            cin >> num_0;
            cout << "\n\n";

            if (num_0 == 0){
               goto end_case;
            }else{
               cout << "==Invalid input!==\n\n";
               goto return1;
            }
            end_case:
            goto start;
}