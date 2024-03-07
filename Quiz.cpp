#include "Quiz.h"
#include <iostream>

Quiz::Quiz(std::string t) : title(std::move(t)) {}

void Quiz::addQuestion(const Question& question) {
    questions.push_back(question);
}

int Quiz::startQuiz() {
    int score = 0;
    std::cout << "\nStarting Quiz: " << title << "\n";
    for (const auto& q : questions) {
        std::cout << q.text << "\n";
        for (size_t i = 0; i < q.options.size(); ++i) {
            std::cout << i + 1 << ": " << q.options[i] << "\n";
        }
        int answer;
        std::cout << "Your answer (number): ";
        std::cin >> answer;
        // Debug print statements (Optional)
        // std::cout << "Debug: Correct answer index (0-indexed) = " << q.correctAnswer << std::endl;
        // std::cout << "Debug: User's choice (converted to 0-indexed) = " << (answer - 1) << std::endl;

        if (answer - 1 == q.correctAnswer) {
            std::cout << "Correct!\n";
            score++;
        }
        else {
            std::cout << "Wrong. The correct answer was: " << q.options[q.correctAnswer] << " (" << (q.correctAnswer + 1) << ").\n";
        }
    }
    std::cout << "Your score: " << score << "/" << questions.size() << "\n";
    return score;
}