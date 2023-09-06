/*****************************************************************************
 ** File: Trivia.cpp
 ** Project: CMSC 202 Project 5, Spring 2022
 ** Author:  Kush Shah and CMSC202
 ** Date:    04/05/2022
 ** Email:   k216@umbc.edu
 **
 Description: CPP file for Trivia class. Includes both class definition and
 class function definitions. Loads a file of trivia questions
*****************************************************************************/

#ifndef TRIVIA_CPP
#define TRIVIA_CPP
#include "Lqueue.cpp"
#include "Question.cpp"
#include <fstream>
#include <vector>
using namespace std;

const string DEFAULT_FILE = "proj5_string.txt";
const char DELIMITER = '|';

template <class T>
class Trivia {
public:
  // Name: Default Constructor
  // Desc: Displays the title, Loads Questions and calls menu
  // Indicates if the file was not loaded.
  // Precondition: None
  // Postcondition: User is prompted with assignment menus
  Trivia(string filename= DEFAULT_FILE);
  // Name: Destructor
  // Desc: Deallocates memory allocated for the Questions and
  // resets all variables.
  // Precondition: A Trivia exists.
  // Postcondition: All dynamically allocated memory in Trivia is deleted.
  ~Trivia();
  // Name: LoadQuestions
  // Desc: Each input file will be for a specific type of question (int, double, string)
  //       Reads in Questions from a file and stores them in anLqueue.
  //       An input file will be for exactly one type of question (int, double, string)
  // Precondition: None.
  // Postcondition: Returns true if file was read. Otherwise, it returns false.
  bool LoadQuestions(string filename);
  // Name: MainMenu
  // Desc: Presents user with menu options for showing subjects and allowing
  // user to work on a subject.
  // Precondition: None.
  // Postcondition: The main menu is presented.
  void MainMenu();
  // Name: DisplaySubjects
  // Desc: Presents all Subjects with corresponding numerical identifiers.
  // Precondition: Subjects have been added.
  // Postcondition: All assignments are printed to the screen.
  void DisplaySubjects();
  // Name: StartSubject
  // Desc: Starts working on a selected Subject.
  // Displays the number of questions in subject.
  // Starts at beginning and goes through each question.
  // After all questions have been answered:
  //       displays total correct, incorrect, and percentage correct
  // Precondition: m_questions has been populated
  // Postcondition: Returns to main menu
  void StartSubject();
  // Name: AddSubject
  // Desc: Checks to see if a subject exists in m_subjects.
  //       If not, inserts subject into m_subjects.
  // Precondition: A Subject exists.
  // Postcondition: Add subject to m_subjects if new subject.
  void AddSubject(string subject);
  // Name: ChooseSubject
  // Desc: Allows a user to choose one of the subjects to work on. Lists all subjects
  // in m_subjects and allows use to choose one. Returns value - 1 (location in vector)
  // Precondition: A Subject exists.
  // Postcondition: Returns value entered minus one
  int ChooseSubject();
  // Name: QuestionsPerSubject
  // Desc: Iterates over m_questions and counts how many questions match the subject
  // passed into function
  // Precondition: A Subject exists.
  // Postcondition: Returns number of questions of a particular subject
  int QuestionsPerSubject(string subject);
  // Name: DisplayTitle
  // Desc: Displays opening Welcome message
  // Precondition: None.
  // Postcondition: Title is displayed.
  void DisplayTitle();
private:
  Lqueue<Question<T>* >* m_questions; // Holds questions using a specific data type
  vector<string> m_subjects; //Populated as file is loaded
};

//**********Implement Trivia Class Here***********

template <class T>
Trivia<T>::Trivia(string filename){
  DisplayTitle();
  if(not LoadQuestions(filename)){
    cout << "File was not loaded" << endl;
  }else{
  MainMenu();
  }
}

template <class T>
Trivia<T>::~Trivia(){

}

template <class T>
bool Trivia<T>::LoadQuestions(string filename){
  if(filename != ""){
    //Declaring how the txt file is separated
    string question;
    string subject;
    string answerType;
    string difficulty;
    string gettingAnswer;
    int convertedDifficulty;
    T answer;
    Question<T>* toAsk;

    //Question queue is a pointer to the type
    //Lqueue Question<T> pointers. Lqueue will have data
    //that are just Question<T> pointers
    Lqueue<Question<T>*> *questionQueue = new Lqueue<Question<T>*>();


    //opens ifstream named filename
    ifstream triviaText(filename);

    while(getline(triviaText, subject, DELIMITER)){
      getline(triviaText, question, DELIMITER);
      getline(triviaText, answerType, DELIMITER);

      //converts difficulty from string to int
      getline(triviaText, difficulty, DELIMITER);
      convertedDifficulty = stoi(difficulty);
      
      triviaText >> answer;

      //adds subject to subject vector
      m_subjects.push_back(subject);

      //creates a question object
      toAsk = new Question(subject, question, answerType, convertedDifficulty, answer);
      questionQueue -> Push(toAsk);

    }

    triviaText.close();
    return true;


  }else{
    return false;
  }

}

template <class T>
void Trivia<T>::MainMenu(){
  int choice = 0;

  while(choice <= 0 or choice > 3){
    cout << "Choose an option" << endl;
    cout << "1. Display Subjects" << endl;
    cout << "2. Start Subject" << endl;
    cout << "3. Quit" << endl;

    cin >> choice;
  }

  if(choice == 1){
    DisplaySubjects();
  }else if(choice == 2){
    StartSubject();
  }else if(choice == 3){
    cout << "Thank you for trying UMBC Trivia" << endl;
  }
}

template <class T>
void Trivia<T>::DisplaySubjects(){
  int numSubjects = m_subjects.size();
  cout << "Possible Subjects:" << endl;

  for(int i = 0; i < numSubjects; i++){
    cout << i + 1 << ". " << m_subjects[i] << endl;
  }
  
}

template <class T>
void Trivia<T>::StartSubject(){
  int subjectIndex;
  int numQuestions;
  int correct = 0;
  int incorrect = 0;
  subjectIndex = ChooseSubject();
  numQuestions = QuestionsPerSubject(m_subjects[subjectIndex]);

  cout << "There are " << numQuestions << " in this subject." << endl;

  Question<T>* currQuestion = nullptr;
  Node<T>* 

  //iterates through the linked list
  while(curr != nullptr){
    currQuestion = curr -> GetData();
    cout << currQuestion << endl;

    //checks to see if answer is correct or not
    if(currQuestion -> CheckAnswer() == true){
      cout << "Correct" << endl;
      correct += 1;
    }else if(currQuestion -> CheckAnswer() == false){
      cout << "Incorrect" << endl;
    }

    //move curr to next place
    curr = curr -> GetNext();
  }
   
  //when done, set currQuestion to nullptr
  //Also, show percentage of questions you got correct
  currQuestion = nullptr;

  double result;
  result = double(correct) / double(correct + incorrect);

}

template <class T>
void Trivia<T>::AddSubject(string subject){

}

template <class T>
int Trivia<T>::ChooseSubject(){
  int numSubjects = m_subjects.size();
  int choice = 0;

  while(choice <= 0 or choice > numSubjects){
    cout << "What subject would you like to attempt? " << endl;
    DisplaySubjects();
    cin >> choice;
  }
  return (choice - 1);
}

template <class T>
int Trivia<T>::QuestionsPerSubject(string subject){
  int numQuestions = 0;
  Question<T>* currQuestion = nullptr;
  Node<T>* curr = m_questions -> m_head;

  //iterate through question queue
  //if node matches the subject, increment index
  while(curr != nullptr){
    currQuestion = curr -> GetData();
    if(currQuestion -> m_subject == subject){
      numQuestions += 1;
    }

    curr = curr -> GetNext();

  }

  currQuestion = nullptr;
  return numQuestions;
}


template <class T>
void Trivia<T>::DisplayTitle(){
  cout << "Welcome to UMBC Trivia!" << endl;
}


#endif
