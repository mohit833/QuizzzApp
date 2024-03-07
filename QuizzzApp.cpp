
#include "UserManager.h"
#include "QuizManager.h"
#include "UserProgressTracker.h"
#include <iostream>

int main() {
    UserManager userManager;
    QuizManager quizManager;
    UserProgressTracker progressTracker;
    std::string username, password;

    std::cout << "Do you want to log in or register? (login/register): ";
    std::string action;
    std::cin >> action;

    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    if (action == "register") {
        userManager.registerUser(username, password);
    }
    else if (action == "login") {
        if (!userManager.authenticateUser(username, password)) {
            std::cout << "Login failed. Please check your credentials.\n";
            return 1;
        }
    }
    else {
        std::cout << "Invalid action.\n";
        return 1;
    }

    auto quizzes = quizManager.loadQuizzes("quiz.txt");
    std::cout << "Quizzes loaded: " << quizzes.size() << "\n";

    int quizChoice = 1;
    while (quizChoice != 0) {
        std::cout << "\nAvailable quizzes:\n";
        for (size_t i = 0; i < quizzes.size(); ++i) {
            std::cout << i + 1 << ": " << quizzes[i].title << "\n";
        }
        std::cout << "Select a quiz to take (or enter 0 to exit): ";
        std::cin >> quizChoice;
        if (quizChoice < 0 || quizChoice > quizzes.size()) {
            std::cout << "Invalid choice. Please try again.\n";
            continue;
        }
        if (quizChoice == 0) {
            break;
        }

        int score = quizzes[quizChoice - 1].startQuiz();
        progressTracker.updateScore(username, score, quizzes[quizChoice - 1].title);

        std::cout << "Would you like to view your scores? (yes/no): ";
        std::string viewScores;
        std::cin >> viewScores;
        if (viewScores == "yes") {
            progressTracker.viewScores(username);
        }
    }

    std::cout << "Thank you for using the Quiz Application. Goodbye!\n";
    return 0;
}