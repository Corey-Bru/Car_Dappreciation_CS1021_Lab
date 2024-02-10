#include <iomanip>
#include <iostream>

/*
 * car_model_year: Takes no parameters and prompts the user to enter
 * the model year of the car they are listing. The model year of the
 * car is returned as an integer (`int`).
 *
 * returns: the model year of the code as entered by the user (`int`).
 */
int car_model_year() {
  int model_year{0};
  std::cout << "What is the model year of the car? ";
  std::cin >> model_year;
  return model_year;
}

/*
 * car_accidents: Takes no parameters and prompts the user to enter
 * the number of accidents the car has been in. The number of accidents
 * is returned as an integer (`int`).
 *
 * returns: the number of accidents as entered by the user (`int`).
 */
int car_accidents() {
  int accidents{0};
  std::cout << "How many accidents has the car been in? ";
  std::cin >> accidents;
  return accidents;
}

/*
 * car_msrp: Takes no parameters and prompts the user to enter
 * the car's MSRP. The car's MSRP is returned as a floating-point
 * number (`double`).
 *
 * returns: the car's MSRP as entered by the user (`double`).
 */
double car_msrp() {
  double msrp{0.0};
  std::cout << "How much did you pay for the car? ";
  std::cin >> msrp;
  return msrp;
}

/*
 * car_has_premium_options: Takes no parameters and prompts the user
 * to enter whether the car has premium options. The presence of premium
 * options on the car is return as a Boolean (`bool`).
 *
 * returns: whether the car has premium option as entered by the user (`bool`).
 */
bool car_has_premium_options() {
  std::string has_options_string{""};
  std::cout << "Does your car have premium options (yes/no)? ";
  std::cin >> has_options_string;
  if (has_options_string == "yes") {
    return true;
  } else {
    return false;
  }
}

/*
 * print_eligible_message: Takes a single parameter (the car's resale value
 * as a floating-point number [`double`]) and prints a nice message telling
 * the user their car is eligible for sale through dappreciation and its price.
 *
 * returns: nothing
 */
void print_eligible_message(double resale_price) {
  std::cout << std::fixed << std::setprecision(2)
            << "dappreciation will list your car for $" << resale_price
            << ".\n";
}

/*
 * print_ineligible_message: Takes no parameters and prints a nice message telling
 * the user their car is ineligible for sale through dappreciation.
 *
 * returns: nothing
 */
void print_ineligible_message() {
  std::cout << "Unfortunately your car is ineligible for the dappreciation "
               "platform.\n";
}

/*
* The code has 8 constants to calculate the resale value of a used car.
* The program uses the functions car_model_year, car_accidents, car_msrp and car_has_premium_options
* to gather user input.
* The program then goes through various number of test cases to calculate the resale value of the vehicle.
* One test case tests the eligibility of the car by seeing if the car is older than 10 years or has more than 3 accidents.
* After, carMSRP is calculated by multiplying the msrp by the resale percentage 
* Finally a function called print_eligible_message is used to output the resale value of the vehicle.
*/

int main() {
//Constants 
    double const baseLine_Tier1 = 0.85;
    double const baseLine_Tier2 = 0.63;
    double const baseLine_Tier3 = 0.45;
    double const wreckPercent_Tier1 = 0.02;
    double const wreckPercent_Tier2 = 0.10;
    double const wreckPercent_Tier3 = 0.20;
    double const premiumBonus = 0.05;
    int const currentYear = 2023;
//Inputs 
    int carAge = currentYear - car_model_year();
    int carAccidents = car_accidents();
    /*
    * uses the function car_has_premium_options() where the function returns a boolean output.
    * The function returns a boolean output by prompting a yes/no answer from the user.
    * yes is true and no is false.
    */
    bool carPremium = car_has_premium_options();
    double carMSRP = car_msrp();

    double resalePercent = 0;
//test cases 
    if ((carAge > 10) || (carAccidents > 3)) {
        print_ineligible_message();
        return 0;
    }
    if (carAge <= 4) {
        resalePercent = baseLine_Tier1;
    } else if (carAge <= 8) {
        resalePercent = baseLine_Tier2;
    } else {
        resalePercent = baseLine_Tier3;
    }
    if (carAccidents == 1) {
        resalePercent -= wreckPercent_Tier1;
    } else if (carAccidents == 2) {
        resalePercent -= wreckPercent_Tier2;
    } else if (carAccidents == 3) {
        resalePercent -= wreckPercent_Tier3;
    }
    if (carPremium) {
        resalePercent += premiumBonus;
    }
    carMSRP *= resalePercent;
    //output 
    print_eligible_message(carMSRP);

    return 0;
}
