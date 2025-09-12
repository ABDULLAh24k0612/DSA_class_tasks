#include <iostream>
using namespace std;

int main() {
    int teams;
    cout << "Enter number of teams: ";
    cin >> teams;

    int** scores = new int*[teams];
    int* sizes = new int[teams];

    for (int i = 0; i < teams; i++) {
        cout << "Enter players in team " << i + 1 << ": ";
        cin >> sizes[i];
        scores[i] = new int[sizes[i]];

        cout << "Enter scores: ";
        for (int j = 0; j < sizes[i]; j++) {
            cin >> scores[i][j];
        }
    }

    cout << "\nTeam Sums:\n";
    for (int i = 0; i < teams; i++) {
        int sum = 0;
        for (int j = 0; j < sizes[i]; j++) {
            sum += scores[i][j];
        }
        cout << "Team " << i + 1 << ": " << sum << endl;
    }

    for (int i = 0; i < teams; i++) {
        delete[] scores[i];
    }
    delete[] scores;
    delete[] sizes;

    return 0;
}
