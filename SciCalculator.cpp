#include<iostream>
#include<cmath>

using namespace std;

int main(){
    cout  << "\t\t\tSCIENCTIFIC CALCULATOR\n\n"
            << "\t1 : Addition\t\t\t8 : Sin\n" << "\t2 : Subtraction\t\t\t9 : Cos\n"
            << "\t3 : Multiplication\t\t10 : Tan\n" << "\t4 : Division\t\t\t11 : Cosec\n"
            << "\t5 : Exponent\t\t\t12 : Sec\n" << "\t6 : Root\t\t\t13 : Cot\n"
            << "\t7 : Log\t\t\t\t14 : Exit\n\n";

    int option;
    const double PI = 3.14159265;
    double num1, num2, result, radians;

    while (true) {
        cout << "\nEnter your OPTION : ";
        cin >> option;

        if(option >= 1 && option <= 7){
            cout << "\nEnter your 1st number : ";
            cin >> num1;
            cout << "\nEnter your 2nd number : ";
            cin >> num2;
                switch(option){
                    case 1 :
                        result = num1 + num2;
                        cout << "Your result of " << num1 << " addition to " << num2 << " is " << result;
                        break;
                    case 2 :
                        result = num1 - num2;
                        cout << "Your result of " << num1 << " subtraction to " << num2 << " is " << result;
                        break;
                    case 3 :
                        result = num1*num2;
                        cout << "Your result of " << num1 << " multiplication to " << num2 << " is " << result;
                        break;
                    case 4 :
                        result = num1/num2;
                        cout << "Your result of " << num1 << " division to " << num2 << " is " << result;
                        break;
                    case 5 :
                        result = pow(num1, num2);
                        cout << "Your result of " << num1 << " exponent to " << num2 << " is " << result;
                        break;
                    case 6 :
                        result = pow(num1, 1.0/num2);
                        cout << "Your result of " << num1 << " root to " << num2 << " is " << result;
                        break;
                    case 7 :
                        result = log(num1) / log(num2);
                        cout << "Your result of " << "Log base " << num1 << " off " << num2 << " is " << result;
                        break;
                }
        } else if (option >= 8 && option <= 13){
            cout << "\nEnter your number : ";
            cin >> num1;
                switch (option) {
                    case 8 :
                        radians = num1 * (PI / 180.0);
                        result = sin(radians);
                        break;
                    case 9 :
                        radians = num1 * (PI / 180.0);
                        result = cos(radians);
                        break;
                    case 10 :
                        radians = num1 * (PI / 180.0);
                        result = tan(radians);
                        break;
                    case 11 :
                        radians = num1 * (PI / 180.0);
                        result = 1.0 / sin(radians);
                        break;
                    case 12 :
                        radians = num1 * (PI / 180.0);
                        result = 1.0 / cos(radians);
                        break;
                    case 13 :
                        radians = num1 * (PI / 180.0);
                        result = 1.0 / tan(radians);
                        break;
                }
            cout << "Your result is " << result;
        } else if (option == 14){
            cout << "\nExit...";
            exit(0);
        } else {
            cout << "Wrong choice, Enter valid choice to play the game! (1 to 14)";
        }
    }


    return 0;
}
