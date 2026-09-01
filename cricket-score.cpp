
#include <iostream>
#include <string>

using namespace std;

// Quick struct to track the star player of the match
struct Batsman {
    string name;
    int runs, balls;
};

int main() {
    string team1, team2; 
    int score1, score2;
    Batsman star;

    // Grab team scores and our star batter's stats
    cout << "Enter Team 1 & total score: ";
    cin >> team1 >> score1;
    cout << "Enter Star Batsman (Name, Runs, Balls): ";
    cin >> star.name >> star.runs >> star.balls;
    cout << "Enter Team 2 & total score: ";
    cin >> team2 >> score2;

    // Calculate strike rate safely inline
    double sr = star.balls > 0 ? (star.runs * 100.0) / star.balls : 0;

    // Print the combined match summary
    cout << "\n=== FINAL SCORECARD ===\n";
    cout << team1 << ": " << score1 << " vs " << team2 << ": " << score2 << "\n";
    cout << "Star: " << star.name << " | " << star.runs << " runs off " << star.balls << " balls (SR: " << sr << ")\n";
    cout << "=======================\n";

    // Crown the winner
    if (score1 > score2) cout << "🏆 " << team1 << " wins by " << (score1 - score2) << " runs!\n";
    else if (score2 > score1) cout << "🏆 " << team2 << " wins the chase!\n";
    else cout << "🤝 It's a dead heat!\n";

    return 0;
}
