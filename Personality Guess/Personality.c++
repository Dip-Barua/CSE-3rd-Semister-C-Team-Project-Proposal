#include <iostream>
#include <string>
#include <iomanip> // For std::setw and std::setfill

using namespace std;

// Function prototypes
void askQuestions();
void displayPersonalityType(int scores[]);

const int WIDTH = 50; // Total width for the centered text

int main() {
    // Print the title
    cout << setw(WIDTH) << setfill('=') << "" << setfill(' ') << endl;
    cout << setw(WIDTH / 2 + 12) << "Welcome to the Personality Test" << endl;
    cout << setw(WIDTH) << setfill('=') << "" << setfill(' ') << endl;
    
    // Print instructions
    cout << "\nPlease answer the following questions truthfully." << endl;
    cout << "For each question, select the answer that best describes you." << endl;
    cout << endl;

    askQuestions();
    
    return 0;
}

void askQuestions() {
    int scores[3] = {0}; // Scores for each personality type
    char answer;

    cout << "How do you prefer to work on projects?" << endl;
    cout << "                  1) In a team with others" << endl;
    cout << "                  2) Independently and alone" << endl;
    cout << "                  3) Collaborating with a few close colleagues" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == '1') scores[0] += 3;
    else if (answer == '2') scores[1] += 3;
    else if (answer == '3') scores[2] += 2;

    cout << endl << "What is your approach to solving problems?" << endl;
    cout << "                  1) Discussing with others to find the best solution" << endl;
    cout << "                  2) Analyzing the problem and coming up with a solution on my own" << endl;
    cout << "                  3) Gathering input from a few trusted sources" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == '1') scores[0] += 3;
    else if (answer == '2') scores[1] += 3;
    else if (answer == '3') scores[2] += 2;

    cout << endl << "How do you feel about taking risks?" << endl;
    cout << "                  1) I enjoy taking risks and facing new challenges" << endl;
    cout << "                  2) I prefer to avoid risks and stick to what I know" << endl;
    cout << "                  3) I take calculated risks after careful consideration" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == '1') scores[0] += 2;
    else if (answer == '2') scores[1] += 1;
    else if (answer == '3') scores[2] += 2;

    cout << endl << "How do you like to spend your leisure time?" << endl;
    cout << "                  1) Engaging in social activities and events" << endl;
    cout << "                  2) Reading, writing, or engaging in solitary hobbies" << endl;
    cout << "                  3) Participating in group activities or physical sports" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == '1') scores[0] += 2;
    else if (answer == '2') scores[1] += 3;
    else if (answer == '3') scores[2] += 2;

    cout << endl << "How do you react to unexpected changes?" << endl;
    cout << "                  1) Adapt quickly and look for new opportunities" << endl;
    cout << "                  2) Prefer to stick to a plan and avoid sudden changes" << endl;
    cout << "                  3) Evaluate the situation and adjust as needed" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == '1') scores[0] += 3;
    else if (answer == '2') scores[1] += 1;
    else if (answer == '3') scores[2] += 2;

    // Display the personality type based on the scores
    displayPersonalityType(scores);
}

void displayPersonalityType(int scores[]) {
    int maxIndex = 0;

    // Determine which personality type has the highest score
    for (int i = 1; i < 3; ++i) {
        if (scores[i] > scores[maxIndex]) {
            maxIndex = i;
        }
    }

    // Print the result
    cout << endl;
    cout << setw(WIDTH) << setfill('=') << "" << setfill(' ') << endl;
    cout << setw(WIDTH / 2 + 14) << "Your Personality Type:" << endl;
    cout << setw(WIDTH) << setfill('=') << "" << setfill(' ') << endl;

    switch (maxIndex) {
        case 0:
            cout << "The Social Communicator: You are outgoing, energetic, and thrive on social interactions. You enjoy working in teams and taking on new challenges. Your proactive nature makes you a natural leader." << endl;
            break;
        case 1:
            cout << "The Independent Thinker: You are introspective and prefer working alone or in a small, focused group. You value deep thinking and planning and avoid unnecessary risks. You are disciplined and self-motivated." << endl;
            break;
        case 2:
            cout << "The Balanced Integrator: You have a balanced approach to work and leisure. You are adaptable, enjoy collaboration, and take measured risks. You excel in environments that require teamwork and flexibility." << endl;
            break;
        default:
            cout << "Error in determining personality type." << endl;
    }
    cout << setw(WIDTH) << setfill('=') << "" << setfill(' ') << endl;
}
