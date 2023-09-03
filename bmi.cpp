#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate BMI
double calculateBMI(double weight, double height) {
    // Convert height from feet and inches to inches
    height = (height * 12);

    // Calculate BMI
    double bmi = (weight / (height * height)) * 703;
    return bmi;
}

// Function to classify BMI
string classifyBMI(double bmi) {
    if (bmi < 18.5) {
        return "Underweight";
    } else if (bmi < 24.9) {
        return "Normal Weight";
    } else if (bmi < 29.9) {
        return "Overweight";
    } else {
        return "Obese";
    }
}

int main() {
    double weight, heightFeet, heightInches;

    cout << "Welcome to the Advanced BMI Calculator!" << endl;
    cout << "Enter your weight (in pounds): ";
    cin >> weight;
    
    cout << "Enter your height (in feet and inches): ";
    cin >> heightFeet >> heightInches;

    double bmi = calculateBMI(weight, heightFeet + heightInches / 12.0);

    cout << "Your BMI is: " << bmi << endl;
    cout << "Classification: " << classifyBMI(bmi) << endl;

    return 0;
}
