/* # Name : Abdelrahman Adel Abdelaziem Ahmed.

# ID : 20211059 .

# The Game Number : 9 --> Kayles game .

# Idea of the Game : There are two players each player can remove one or two number from the list
# if he want to remove 2 numbers they must be adjacent numbers until any player will remove the last
# Number he will win . */

# include <iostream>
# include <vector>
# include<bits/stdc++.h>
using namespace std;

vector < int > list_numbers ;
int player_number = 2 ;
int number_of_digit , number_1 , number_2, arbitrary;
int turn ;

// This Function till the user notes , idea of the game and the important rules of game .

void start_game()
{
    cout <<"\nWelcome to Kayles Game :) \n\nImportant Instructions ...\n\n"
        "1- If you will input two numbers you should input adjacent Numbers"
        "\n2- If you want to input two Numbers you should enter Number ( 2 ) and ( 1 ) to input one Number"
        "\n3- if you want to remove 2 numbers they must be adjacent Numbers"
        "\n4- you must input numbers which are in the list of numbers "
        "\n5- The player who take the last Number or Numbers he will win"
        "\n\nEnjoy :) \n" << endl ;
}

// This Function print the list_numbers .

void print_list_numbers()
{
    for (int list_number : list_numbers)

        cout << list_number << "   " ;

    cout << endl ;
}

// This Function fill the list_numbers by numbers , and I return the list to use it .

vector<int> list_numbers_fill ()
{
    // Here I ask the user to enter limit number of the list_numbers .
    cout << "please enter arbitrary number: " << endl;

    cin >> arbitrary ;

    // This for loop is fill the list_numbers by numbers .

    for (int i = 0 ; i < arbitrary + 1 ; i++)

        // I used push_back function to append i in the list_numbers .

        list_numbers.push_back(i) ;

    // Here I print the list_numbers to the user .

    print_list_numbers() ;

    // Here I return the list to use it .

    return list_numbers ;
}

/* This Function Check is the length of the list_numbers 0 or no , and if it 0 it will print .

the user who won if not it will complete the game .*/

void check_win(vector<int> list_numbers)
{
    /* Here I check if length of the list_number is 0 or no .

    First condition is yes .*/

    if (list_numbers.empty())
    {
        // Here I till to the user that player number [ player_number ] is won and the game is over .

        cout << "Player " << player_number << " : Won !\n" << endl ;

        cout << "The Game is over :) " << endl ;

    }
}

// This Function remove the Numbers which the user input and print list_numbers_print .

void remove_numbers (int number_of_digit, int number_1, int number_2=0)
{
/* Here I check if the number_of_digit equal 1 or 2 the first condition is number_of_digit equal 1

so I remove one number from the list list_numbers .*/

    if (number_of_digit == 1 )
    {
        // Here I remove the number from the list list_numbers by remove builtin function .

        remove(list_numbers.begin(), list_numbers.end(), number_1) ;

        // Here I remove last number in the list because remove builtin function increase the list by number in the last .

        list_numbers.pop_back() ;

        // Here I print the list_numbers to show to the user the remaining numbers .

        print_list_numbers() ;

        // Here I call check_win function to check if the player won or no .

        check_win(list_numbers) ;

    }

        // The second condition is the number_of_digit equal 2 , so I remove two numbers from the list .

    else
    {
        // Here I remove the first number from the list list_numbers .

        remove(list_numbers.begin(), list_numbers.end(),number_1) ;

        // Here I remove last number in the list because remove builtin function increase the list by number in the last .

        list_numbers.pop_back() ;

        //Here I remove the second number from the list list_numbers .

        remove(list_numbers.begin(), list_numbers.end(),number_2) ;

        // Here I remove last number in the list because remove builtin function increase the list by number in the last .

        list_numbers.pop_back() ;

        // Here I print the list_numbers_print to show to the user the removed numbers and the remaining numbers .

        print_list_numbers() ;

        // Here I call check_win function to check if the player won or no .

        check_win(list_numbers);
    }

}


void number_of_digit_1(int number_of_digit)
{
    // Here I increase turn vy 1 to change from even to odd or versa .

    turn ++ ;

    // This if statement check is number_of_digit 1 or else .

    if (number_of_digit == 1){

        // Here if the number_of_digit is 1 this mean that the player wants to remove only 1 number from the list_numbers .*/

        cout << "Player " << player_number << " : Please enter the number ... " << endl ;

        // Here I ask the user to input the number which he wants to remove .

        cin >> number_1 ;

        /*Here the role of while is stay loop if the players input incorrect number [ Not exist in the list_numbers ]

        but if they input correct number the compiler will exit of the while and call remove_numbers function

        and its condition is True to make it stay looping until the user enter a correct number .*/

        while (true)
        {
            // Here I make sure if user input a correct number [ Exist in the list_numbers ] or no .


            if (count(list_numbers.begin(), list_numbers.end(), number_1))
            {
                /* If the user input a correct number [ Exist in the list_numbers ] I call remove_numbers function
                 * to remove the number from list_numbers and break from while loop .*/

                remove_numbers(number_of_digit, number_1) ;

                break;
            }
            else
            {
                /*If the user input an incorrect number [ Not exist in the list_numbers ] so I till to him

                the number is incorrect , and I ask him to try again to input a correct number.*/

                cout << "this num is not in the list please choose again" << endl;
                cout << "Player " << player_number << " : Please enter the number ... " << endl ;
                cin >> number_1 ;
            }
        }
    }
}

/* This Function take from the user the Number and Check that if the numbers is

adjacent and both of them in the list_numbers Number_Of_Digit is 2 and Call remove function .*/

void number_of_digit_2(int number_of_digit)
{

    // Here I increase turn vy 1 to change from even to odd or versa .

    turn ++ ;

    // This if statement check is number_of_digit 1 or else .

    if (number_of_digit == 2)
    {

        // Here if the number_of_digit is 2 this mean that the player wants to remove 2 numbers from the list_numbers .*/

        cout << "Player " << player_number << " : Please enter the two numbers ... " << endl ;

        // Here I ask the user to input the numbers which he wants to remove .

        cout << "The First number ..." ;
        cin >> number_1 ;
        cout << "The Second number..." ;
        cin >> number_2 ;


        while (true)
        {
            // Here I make sure if user input a correct numbers [ Exist in the list_numbers ] or no .
            // And if the user enter adjacent numbers or no .

            if (((number_1 - number_2 == 1 ) || (number_1 - number_2 == - 1 ))
                && (count(list_numbers.begin(), list_numbers.end(), number_1)) &&
                (count(list_numbers.begin(), list_numbers.end(), number_2)))
            {
                /* If the user input a correct number [ Exist in the list_numbers ] I call remove_numbers function
                 * to remove the number from list_numbers and break from while loop .*/

                remove_numbers(number_of_digit, number_1, number_2) ;

                break;
            }
            else
            {
                /*If the user input an incorrect number [ Not exist in the list_numbers ] so I till to him

                the number is incorrect , and I ask him to try again to input a correct number.*/

                cout << "this num is not in the list please choose again" << endl;
                cout << "Player " << player_number << " : Please enter the two numbers ... " << endl ;
                cout << "The First ..." ;
                cin >> number_1 ;
                cout << "The Second ... " ;
                cin >> number_2 ;
            }
        }
    }
}

/*This Function is the main Function it takes from user Number_Of_Digit and Call

Function number_of_di_1 if user input 1 and number_of_di_2 if user input 2 .*/

void main_game()
{
    /*Here the role of while is stay loop if the players input incorrect numbers

    but if they input correct numbers the compiler will exit of the while and call number_of_digit functions

    and its condition is len(list_numbers) != 0 as if the length of list_numbers become 0 that mean

    each of player won .*/

    while (!list_numbers.empty())
    {
        /* Turn variable its role is to change player number than example [if turn is 0 ( Even ) --> 0 % 2 = 0

        so player number become 1 , and I add to turn 1 every time, so it will become 1( Odd ) --> 1 % 2 = 1

        so player number become 2 and so on until game over] . */

        // Here is the check of turn is even or odd .

        if (turn % 2 == 0)

            // If turn Even player number = 1 .

            player_number = 1 ;

        else
            // If turn Even player number = 2 .

            player_number = 2 ;

        // Here I ask the user to input the number_of_digits which he wants to remove 1 or 2 .

        cout << "Player " << player_number << " : Did you want to remove 1 or 2 numbers ..." << endl;

        cin >> number_of_digit;

        /* There are two value to number_of_digit 1 or 2 , so I made if statement .

        Here first condition .*/

        if (number_of_digit == 1) {

            //Here if user input 1 it will call number_of_digit_1 and pass to her number_of_digit_1 .

            number_of_digit_1(number_of_digit);

            //This is second condition .

        } else if (number_of_digit == 2) {

            //Here if user input 2 it will call number_of_digit_2 and pass to her number_of_digit_2 .

            number_of_digit_2(number_of_digit);

        }
            //This else statement if the user input an incorrect number .

        else

            //Here i till the user the number is incorrect , so I ask him to input a correct number again .

            cout << "Invalid number ...\nPlease enter a correct number ..." << endl;
    }
}


int main()
{
    /* Here I call start_game Function to print to the user the Notes sentences
    then call list_numbers_fill Function to fill the list by numbers
    then I call main_game to start the game . */

    start_game() ;
    list_numbers_fill() ;
    main_game() ;
}
