#include <iostream>
#include <iomanip>

using namespace std;


const double ABSOLUTE_ZERO_C = -273.15;
const double FREEZING_POINT_C = 0.0;

// --- Conversion Functions ---
// These are defined BEFORE main() so the compiler knows they exist.

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

double celsiusToKelvin(double celsius) {
    return celsius - ABSOLUTE_ZERO_C; // Adding to negative -273.15
}

double kelvinToCelsius(double kelvin) {
    return kelvin + ABSOLUTE_ZERO_C;
}

double fahrenheitToKelvin(double fahrenheit) {
    double celsius = fahrenheitToCelsius(fahrenheit);
    return celsiusToKelvin(celsius);
}

double kelvinToFahrenheit(double kelvin) {
    double celsius = kelvinToCelsius(kelvin);
    return celsiusToFahrenheit(celsius);
}


void displayTemperatureFacts(double celsius) {
    cout << "\nInteresting facts about this temperature:" << endl;
    
    if (celsius < ABSOLUTE_ZERO_C) {
        cout << "This is below absolute zero—physically impossible!" << endl;
    } else if (celsius == ABSOLUTE_ZERO_C) {
        cout << "This is absolute zero!" << endl;
    } else if (celsius == FREEZING_POINT_C) {
        cout << "This is the freezing point of water." << endl;
    } else if (celsius == 100.0) {
        cout << "This is the boiling point of water." << endl;
    } else if (celsius >= 20.0 && celsius <= 30.0) {
        cout << "This is a comfortable room temperature." << endl;
    } else {
        cout << "This is a standard operating temperature." << endl;
    }
}

// --- The Main Executive ---
int main() {
    cout << "=======================================" << endl;
    cout << "       TEMPERATURE CONVERTER           " << endl;
    cout << "=======================================" << endl;

    bool keepRunning = true;
    while (keepRunning) {
        cout << "\n1. C to F | 2. F to C | 3. C to K | 4. K to C | 5. F to K | 6. K to F | 7. Exit" << endl;
        cout << "Choice: ";
        
        int choice;
        cin >> choice;
        
        if (choice == 7) {
            keepRunning = false;
            cout << "Exiting system..." << endl;
            break;
        }

        double inputTemp, result, celsiusEquivalent;
        cout << "Enter temperature: ";
        cin >> inputTemp;

        switch (choice) {
            case 1:
                result = celsiusToFahrenheit(inputTemp);
                celsiusEquivalent = inputTemp;
                cout << inputTemp << " C = " << fixed << setprecision(2) << result << " F" << endl;
                break;
            case 2:
                result = fahrenheitToCelsius(inputTemp);
                celsiusEquivalent = result;
                cout << inputTemp << " F = " << fixed << setprecision(2) << result << " C" << endl;
                break;
            case 3:
                result = celsiusToKelvin(inputTemp);
                celsiusEquivalent = inputTemp;
                cout << inputTemp << " C = " << fixed << setprecision(2) << result << " K" << endl;
                break;
            case 4:
                result = kelvinToCelsius(inputTemp);
                celsiusEquivalent = result;
                cout << inputTemp << " K = " << fixed << setprecision(2) << result << " C" << endl;
                break;
            case 5:
                result = fahrenheitToKelvin(inputTemp);
                celsiusEquivalent = fahrenheitToCelsius(inputTemp);
                cout << inputTemp << " F = " << fixed << setprecision(2) << result << " K" << endl;
                break;
            case 6:
                result = kelvinToFahrenheit(inputTemp);
                celsiusEquivalent = kelvinToCelsius(inputTemp);
                cout << inputTemp << " K = " << fixed << setprecision(2) << result << " F" << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
                continue;
        }
        displayTemperatureFacts(celsiusEquivalent);
    }
    return 0;
}