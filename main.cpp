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
	cout << "3. Show Top 3\n";
	cout << "4. Show Students Average\n";
	cout << "5. Update Scores\n";
	cout << "6. Delete Student\n";
	cout << "7. Search Student\n";
	cout << "8. Exit\n\n";

	int num;

	while (true)
	{
		cout << "Enter Your Choice: ";
		
		if (cin >> num)
		{

			switch (num) {

			case 1:
				if (count >= 50) {
					cout << "==You Can't Cdd Any Other Student!==\n\n";
					goto return1;
				}
				
				cout << "Enter Student Name: ";
				cin >> names[count];
				
				cout << "Enter The Roll Number: ";
				cin >> rolls[count];
				
				for (int i = 0; i < count; i++) {
					if (rolls[i] == rolls[count]) {
						cout << "==Roll Number Already Exists!==\n";
						goto return1;
					}
				}
				
				total[count] = 0;
				
				cout << "Enter Sores For 5 Subjects:\n";
				for (int i = 0; i < 5; i++) {
					cin >> scores[count][i];
					
					if (scores[count][i] < 0 || scores[count][i] > 100) {
						cout << "Invalid Score!\n\n";
						goto return1;
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
				cout << "==Student Added Successfully!==\n\n";
				
                return1:
				int num_0;
				
				while (true)
				{
					cout <<  "Enter 0 To Return: ";
					
					if (cin >> num_0) {
						if (num_0 == 0) {
							cout << "\n\n";
							goto start;
							
						} else {
							cout << "\n==Invalid input!==\n\n";
							goto return1;
							
						}
					} else {
						cout << "\n==Invalid input!==\n";
						cout << "==Please put an integer==\n\n";
						cin.clear();
						cin.ignore(10000, '\n');
						
						goto return1;
					}
				}
				
				
				goto start;
				
				
				case 2:
				for (int i = 0; i < count; i++) {
					cout << "\n"<< i + 1<<"_" <<names[i]<< " => [Roll Number : ";
					cout << rolls[i] << " / Total : ";
					cout << total[i] << " / Average : "<< average[i];
					cout << " / Grade : " << grade[i] << " ]" << "\n\n";
				}
				
				if (count == 0) {
					cout << "\n==There Is No Students Yet!==\n\n";
				}

				goto return1;
				
				case 3: {
					
					if (count == 0)
					{
						cout << "\n==There Is No student Yet!==\n\n";
						goto return1;
					}
					
					
					if (count < 3) {
						cout << "\n==Not Enough Students!==\n\n";
						goto return1;
					}
					
					for (int i = 0; i < count - 1; i++)
					{
						for (int j = 0; j < count - i - 1; j++)
						{
							if (average[j] < average[j + 1])
							{
								swap(average[j], average[j + 1]);
								swap(names[j], names[j + 1]);
								swap(rolls[j], rolls[j + 1]);
								swap(total[j], total[j + 1]);
								swap(grade[j], grade[j + 1]);
							}
							
						}
						
					}
					
					cout << "===There Are The Top 3 Students===\n\n";
					cout << "The First Is: " << names[0] << " The Average Is: " << average[0] << ".\n";
					cout << "The Second Is: " << names[1] << " The Average Is: " << average[1] << ".\n";
					cout << "The Third Is: " << names[2] << " The Average Is: " << average[2] << ".\n";
					
					goto return1;
					
				}
				
				case 4: {
					if (count == 0) {
						cout << "\n==There Is No student Yet!==\n\n";
						goto return1;
					}
					else if (count == 1){
						cout << "\n==There Are Not Enough Students!==\n\n";
						goto return1;
					}
	
					double avg = 0;
	
					cout << "The Average Is: \n";
	
					for (int i = 0; i < count; i++)
					{
						avg += average[i];
					}
					
					cout << "=[ " << avg / count << " ]=\n\n";
					goto return1;
				}

				case 5: {
				int num1;
				bool mark = false;
				cout << "Enter Roll Number To Update Scores: ";
				cin >> num1;
				for (int i = 0; i < count; i++) {
					if (rolls[i] == num1) {
						mark = true;

                        putscores:
						cout << "Enter New Scores For 5 Subjects:\n";
						total[i] = 0;

						for (int j = 0; j < 5; j++) {
							cin >> scores[i][j];

							if (scores[i][j] < 0 || scores[i][j] > 100) {
								cout << "==Invalid Score!==\n";
								cout << "==Put It Again==\n\n";
								goto putscores;
							}

							total[i] += scores[i][j];
						}

						average[i] = total[i] / 5.00;

						if (average[i] >= 90) {
							grade[i] = 'A';
						}
						else if (average[i] >= 80) {
							grade[i] = 'B';
						}
						else if (average[i] >= 70) {
							grade[i] = 'C';
						}
						else if (average[i] >= 60) {
							grade[i] = 'D';
						}
						else {
							grade[i] = 'F';
						}

						cout << "\n==Scores Updated Successfully!==\n\n";
						goto return1;
					}
				}

				if(!mark) {
					cout << "\n==This Roll Number Doesn't Exist!==\n\n";
				}

				goto return1;
			}

			case 6: {
				int rollDel;
				cout << "Enter Roll Number To Delete: ";
				cin >> rollDel;

				bool found = false;

				for (int i = 0; i < count; i++) {
					if (rolls[i] == rollDel) {
						found = true;

						for (int j = i; j < count - 1; j++) {
							names[j] = names[j + 1];
							rolls[j] = rolls[j + 1];
							total[j] = total[j + 1];
							average[j] = average[j + 1];
							grade[j] = grade[j + 1];

							for (int k = 0; k < 5; k++) {
								scores[j][k] = scores[j + 1][k];
							}
						}

						count--;
						cout << "\n==Student deleted successfully!==\n\n";
						goto return1;
					}
				}

				if (!found) {
					cout << "\n==This Roll Number Doesn't Exist!==\n\n";
				}
				
				goto return1;
			}
			
			case 7: {
				if (count == 0) {
					cout << "\n==There Is No student Yet!==\n\n";
					goto return1;
				}
				
				int ser;
				bool rol = false;
				
				cout << "\nEnter Roll Number To Srearch: ";
				cin >> ser;
				
				
				for (int i = 0; i < count; i++) {
					if (rolls[i] == ser) {
						rol = true;
						
						cout << "\nName: " << names[i];
					    cout << "\nRoll: " << rolls[i];
					    cout << "\nScores: ";
						
					    for (int j = 0; j < 5; j++) {
							cout << scores[i][j] << " ";
					    }
						
					    cout << "\nAverage: " << average[i];
					    cout << "\nGrade: " << grade[i] << "\n";
					    goto return1;
				    }
			    }
				
				if (!rol) {
					cout << "\n==This Roll Number Doesn't Exist!==\n\n";
				}

				goto return1;
			}


			case 8: {
				cout << "\n==Thanks For Tring Our App==\n\n";
				return 0;
			}


			default:
				cout << "\n==Invalid input!==\n\n";
				goto return1;
			}

		} else {
			cout << "\n==Invalid input!==\n";
			cout << "==Please put an integer==\n\n";
			cin.clear();
			cin.ignore(10000, '\n');

			goto return1;
		}

	}

}