#include <iostream>
//Preprocessor Directive(instruction to compiler) initiated by #
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    //Print welcome messages to terminal 
    std::cout << "\n\nWelcome to Code Hack. This program will test your ability to problem solve using mathematics...\nYou are on Difficulty Level " << Difficulty;
    //standard (Namespace)  Scope operator(::)  C out(Character Output)  <<(Insertion Operator)     this line is known as an expression statement
    std::cout << "\nSeparate each code with a space...\n";
    //must enter expression statement in order to display something 
    // \n new line escape sequence creates a new line
}

bool PlayGame(int Difficulty)
//bool means PlayGame must return a boolean value
{

    PrintIntroduction(Difficulty);
    //Declare 3 number codes using UpperCamelCase as this is used in Unreal Engine
    const int CodeA = rand() % Difficulty + Difficulty;
    //Variable Decleration   int=variable type  CodeA=Variable Name   =rand() =initializing the variable by giving it a value
    const int CodeB = rand() % Difficulty + Difficulty;
    //rand() creates a random number in the range 0-32767
    const int CodeC = rand() % Difficulty + Difficulty;
    //% (Modulus Operator) divides the number by the modulus amount eg. 4 and returns the remainder
    //+ Difficulty stops the number from being 0 when the number is generated as it adds the level to the random number generated

    const int CodeSum = CodeA + CodeB + CodeC;
    //creates a variable thats equal to the sum of CodeA, CodeB and CodeC
    const int CodeMultiply = CodeA * CodeB * CodeC;


    //Print sum and multiply to the terminal
    std::cout << std::endl;
    //creates break so that variable a is displayed on a new line
    std::cout << "+ There are 3 numbers in the code" << std::endl;
    std::cout << "\n+ The codes add up to: "<< CodeSum << std::endl;
    //displays variable sum which is 
    std::cout << "\n+ The codes multiply to give: " << CodeMultiply << std::endl;

    //Stored played guess
    //separates guesses so that the answer isnt mixed into one
    int GuessA, GuessB, GuessC;
    //cin (Character Input) means awaiting character input from the terminal
    std::cin >> GuessA >> GuessB >> GuessC;
    //awaits guess A and picks up everything until a space is found
    //>>(Extraction Operator)

    //initializes two variables that take the guesses and add/multiply them 
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessMultiply = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessMultiply == CodeMultiply)
    //if statements use a (condition) checks is GuessSum is equal to CodeSum using ==(equality operator) and GuessMultiply is equal to CodeMultiply using &&(Logical Operator)
    {
        //executes the contents of the block of code is condition is met
        std::cout << "\n*** Well done! You have cracked the code. Keep going! ***";
        return true;
        //this returns a true boolean value as the player has won
    }
    else
    //if condition is not met, else will run 
    {
        std::cout <<  "\n*** You entered the wrong code.. Try again! ***";
        return false;
        //this returns a false boolean value as the player has lost
    }
}

int main()
//integer main function. returns an integer. 
//must start function with a return type to determine what will be returned
//parenthesis used to pass arguments in the function 
{
    srand(time(NULL)); 
    //creates a random sequence based on the time of day

    int LevelDifficulty = 1;
    //creates a variable for the level difficulty which will be passsed to the other functions using parameters (inside the parenthesis)
    int const MaxDifficulty = 5;
    //creates a variable that defines the max amount of levels the game will have

    while (LevelDifficulty <= MaxDifficulty)
    //while loop checks if condition is met and rund code block until condition is not met
    {
    bool blevelComplete = PlayGame(LevelDifficulty);
    //this triggers the play game funciton to run is the level is completed
    std::cin.clear();
    //this clears any errors
    std::cin.ignore();
    //this discards the buffer

    if (blevelComplete)
    //if the level is complete, run code blocl
    {
        ++LevelDifficulty;
        //adds one to the level difficulty
    }
    

    }
    std::cout <<  "\n*** You did it, you've completed the test. Impressive stuff ***";

return 0;
}


//terminal  cl codeHack.cpp  compiles code and adds files
//codeHack.exe to run code