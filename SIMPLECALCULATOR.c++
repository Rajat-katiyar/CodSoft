#include <iostream>

int main() {
    double num1, num2, result;
    char op;

    std::cout << "Calculator Program" << std::endl;
    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter the operator (+, -, *, /): ";
    std::cin >> op;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                std::cout << "Error: Division by zero is not allowed." << std::endl;
                return 1; // Exit with an error code
            }
            break;
        default:
            std::cout << "Error: Invalid operator." << std::endl;
            return 1; // Exit with an error code
    }

    std::cout << "Result: " << num1 << " " << op << " " << num2 << " = " << result << std::endl;

    return 0;
}

