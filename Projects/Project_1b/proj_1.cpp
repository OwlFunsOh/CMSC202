#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

//Global Constants
const int NUM_HASHTAGS = 20;

//function declarations

//The function below prints out the opening message when first started
void introMessage();

//The function below asks the user to enter a file with the hashtags
//It prompts again if the file does not exist
//no input. returns filename
string hashtagFile();

//The function below checks to see is a file is empty or not
//input filename. returns true if file is empty
bool isEmpty(string fileName);

//The function below asks the user to enter a file that we want to parse
//It prompts again if the file does not exist
//no input. returns filename
string parsingFile();

//The function below will load all hashtag into an array and return that array
//Input: filename and empty hashtag array. Output: array of Hashtags
void loadHashtags(string fileName, string hashtagArray[NUM_HASHTAGS]);

//The function below will split the hashtag and the actual message into 2 arrays
//input: file name, empty message array, empty hashtag array
//No output
void loadMessage(string fileName, string messagesArray[NUM_HASHTAGS], string parseHashtagsArray[NUM_HASHTAGS]);

//The function below will take in all the arrays and display the messages that have 
//matching hashes next to them. 
//input: hashes array, messages array, and parse hashtag array
//output: none
void displayMatchingHashtags(string hashesArray[NUM_HASHTAGS], string messagesArray[NUM_HASHTAGS],
 string parseHashesArray[NUM_HASHTAGS]);

//displays all hashes and how many of those hashes were found in the message
//input: hashtag array and parse hashtags array
//output: none
void displayAllHashes(string hashtagArray[NUM_HASHTAGS], string parseHashtagArray[NUM_HASHTAGS]);

int main(){

    bool quit = false;
    while(not quit){
        //introduction message
        introMessage();

        //Get's valid hashtag and parse file name
        string hashtagFileName = hashtagFile();
        string parseFileName = parsingFile();

        //check to see if a file is empty. reprompts if it is empty
        while(isEmpty(hashtagFileName)){
            cout << "The file is empty" << endl;
            hashtagFileName = hashtagFile();
        }

        cout << "Your file was imported!" << endl;

        while(isEmpty(parseFileName)){
            cout << "The file is empty" << endl;
            parseFileName = parsingFile();
        }

        cout << "Your file was imported!" << endl;

        //make messages arrays
        string parseHashesArray[NUM_HASHTAGS];
        string messageHashtagsArray[NUM_HASHTAGS];
        loadMessage(parseFileName, messageHashtagsArray, parseHashesArray);

        //making a hashtag array
        string hashtagArray[NUM_HASHTAGS];
        loadHashtags(hashtagFileName, hashtagArray);

        //displaying hashtags with matching hashes
        displayMatchingHashtags(hashtagArray, messageHashtagsArray, parseHashesArray);

        //displaying hash count
        displayAllHashes(hashtagArray, parseHashesArray);
        
        string userAnswer = "";
        bool validResponse = false;
        while(not validResponse){
            cout << "Would you like to analyze another file?" << endl;
            cin >> userAnswer;
            if(userAnswer == "y"){
                quit = false;
                validResponse = true;
            }else if (userAnswer == "n"){
                quit = true;
                validResponse = true;
            }else{
                cout << "Invalid response" << endl;
            }
        }
    }
    return 0;
}

void introMessage(){
    cout << "Welcome to the Hashtag Analyzer" << endl;
    cout << "You will choose a file of hashtags to search for" << endl;
    cout << "Then you will choose a file to search for a hashtags" << endl;
}

string hashtagFile(){
    string fileName;
    cout << "Please enter the file with the hashtags you would like to use: " << endl;
    cin >> fileName;

    //declares and opens hashtag file
    ifstream hashtagFile(fileName);

    while(!(hashtagFile.is_open())){
        cout << "File doesn't exist" << endl;
        cout << "Please enter the file with the hastags you would like to use: " << endl;
        cin >> fileName;

        hashtagFile.open(fileName);
    }

    hashtagFile.close();
    return fileName;
}

bool isEmpty(string fileName){
    //opens file
    ifstream hashtagFile(fileName);

    //if first line is empty, return true
    //if it is not empty, return false
    string temp;
    getline(hashtagFile, temp);

    hashtagFile.close();
    if(temp == ""){
        return true;
    }else{
        return false;
    }
}

string parsingFile(){
    string fileName;
    cout << "Please enter the file with the messages you would like to parse: " << endl;
    cin >> fileName;

    //declares and opens parse file
    ifstream parseFile(fileName);

    while(!(parseFile.is_open())){
        cout << "File doesn't exist" << endl;
        cout << "Please enter the file with the messages you would like to parse: " << endl;
        cin >> fileName;

        parseFile.open(fileName);
    }

    parseFile.close();
    return fileName;
}

void loadHashtags(string fileName, string hashtagArray[NUM_HASHTAGS]){

    //open up the file
    ifstream hashtagFile(fileName);

    //creates a temp variable to get each line
    string temp = "";

    //iterate through each line and add temp as an element
    for(int i = 0; i < NUM_HASHTAGS; i++){
        getline(hashtagFile, temp);
        hashtagArray[i] = temp;
    }
    hashtagFile.close();
    cout << NUM_HASHTAGS << " hashtags loaded" << endl;
}

void loadMessage(string fileName, string messagesArray[NUM_HASHTAGS], string parseHashtagsArray[NUM_HASHTAGS]){
    string hashtagTemp = "";
    string messageTemp = "";
    int counter = 0;
    
    ifstream messageFile(fileName);

    while(getline(messageFile, hashtagTemp)){
        getline(messageFile, messageTemp);
        messagesArray[counter] = messageTemp;
        parseHashtagsArray[counter] = hashtagTemp;
        counter += 1;
    }

    cout << counter << " messages loaded" << endl;
}

void displayMatchingHashtags(string hashesArray[NUM_HASHTAGS], string messagesArray[NUM_HASHTAGS],
 string parseHashesArray[NUM_HASHTAGS]){
    //counter below for numbering purposes
    int counter = 1;
    for(int i = 0; i < NUM_HASHTAGS; i++){
        for(int j = 0; j < NUM_HASHTAGS; j++){
            if(parseHashesArray[i] == hashesArray[j]){
                cout << counter << ". " << parseHashesArray[i] << " " << messagesArray[i] << endl;
                counter += 1;
            }
        }
    }

 }

 void displayAllHashes(string hashtagArray[NUM_HASHTAGS], string parseHashtagArray[NUM_HASHTAGS]){
    int numHashesArray[NUM_HASHTAGS];

    for(int i = 0; i < NUM_HASHTAGS; i++){
        numHashesArray[i] = 0;
        for(int j = 0; j < NUM_HASHTAGS; j++){
            if(hashtagArray[i] == parseHashtagArray[j]){
                numHashesArray[i] += 1;
            }
        }

        //cout << i + 1 << ". \t" << hashtagArray[i] << setw(10) << numHashesArray[i] << endl;
        cout << setw(15);
        cout << i + 1 << ". ";
        cout << setw(15);
        cout << hashtagArray[i];
        cout << setw(15);
        cout << numHashesArray[i] << endl;

    }
 }