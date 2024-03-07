#include "QuizManager.h"
#include "Question.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<Quiz> QuizManager::loadQuizzes(const std::string& filename) {
    std::vector<Quiz> quizzes;
    std::ifstream file(filename);
    std::string line, title;
    Quiz* currentQuiz = nullptr;

    while (getline(file, line)) {
        if (line.substr(0, 11) == "Quiz Title:") {
            if (currentQuiz != nullptr) {
                quizzes.push_back(*currentQuiz);
                delete currentQuiz;
            }
            title = line.substr(11);
            currentQuiz = new Quiz(title);
        }
        else if (currentQuiz && !line.empty()) {
            std::istringstream iss(line);
            std::string questionText, optionText, correctAnsStr;
            getline(iss, questionText, '|');
            getline(iss, optionText, '|');
            getline(iss, correctAnsStr); // Adjusted to read correct answer as a string
            std::vector<std::string> options;
            std::istringstream opts(optionText);
            std::string opt;
            while (getline(opts, opt, ',')) {
                options.push_back(opt);
            }
            int correctAnswer = std::stoi(correctAnsStr) - 1; // Convert from 1-indexed to 0-indexed

            currentQuiz->addQuestion(Question(questionText, options, correctAnswer));
        }
    }
    if (currentQuiz != nullptr) {
        quizzes.push_back(*currentQuiz);
        delete currentQuiz;
    }
    return quizzes;
}