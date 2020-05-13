#include<iostream>
#include<fstream>
#include<string>
using namespace std;

const char MYLETTER = 'k'; // change this to first letter of your last name
const int MAXDIGIT = 8;    // change this to max digit of your student id


const int MAX_WORDS = 128960; // do not change this; max words in file

int readWordsFromFile(string words[], string textFileName) {

    int countWords = 0;

    ifstream inputFile;
    inputFile.open(textFileName);

    if (!inputFile) {
        // could not open the file
        cout << "Error: not able to open file (check path!):"
            << textFileName << endl;
    }
    else {
        // was able to open the file
        // in a while loop, keep reading names from the file
        // and keep track of the array index (as well as name count)
        // while reading, make sure we are not exceeding MAX_NAMES
        string word;
        int i = 0;
        while (inputFile >> word && (countWords < MAX_WORDS)) {
            words[i] = word;
            i++;
            countWords++;
        }
        inputFile.close();
    }


    return countWords;

}

int countWordsWithK(string wordArray[], int wordCount) {
    /*Counter for words that has "k" in it*/
    int counter = 0;
    for (int x = 0; x < wordCount; x++) {
        string stringEle = wordArray[x];
        int stringLength = stringEle.size();
        for (int i = 0; i < stringLength; i++) {
            if (stringEle[i] == MYLETTER) {
                counter++;
                break;
            }
        }
    }
    return counter;
}

int countWordsWithKOnce(string wordArray[], int wordCount) {
    //This function counts words that has only one 'k'
    //Same word counter from the first function
    int countWordWithK_Once = 0;
    //However, this function also has a counter for character k
    int kCounter = 0;

    for (int x = 0; x < wordCount; x++) {
        string stringEle = wordArray[x];
        int stringLength = stringEle.length();
        for (int i = 0; i < stringLength; i++) {
            if (stringEle[i] == MYLETTER) {
                kCounter++;
                                                                           
            }            
        }
        
    }    
    return countWordWithK_Once;
}





int main() {

    string wordsArray[MAX_WORDS]; // can hold up to MAX_WORDS words
    string fileName = "C:\\Users\\Jeffrey\\Desktop\\words.txt"; // name of the file

    int wordCount; // keeps count of number of words read from file

    wordCount = readWordsFromFile(wordsArray, fileName);
    // count of words that contains MYLETTER 1 or more times.
    int answer1 = 0;
    int firstAnswer = countWordsWithK(wordsArray, wordCount);
    answer1 = firstAnswer;    
    // count of words that contains MYLETTER only once.
    int answer2 = 0;
    int secondAnswer = countWordsWithKOnce(wordsArray, wordCount);
    answer2 = secondAnswer;
    // sum of scrabble scores of all words such that the word:
    // contains MYLETTER and the word has a scrabble score > MAXDIGIT
    int answer3 = 0;

    // write code to figure out answers 1-3


    // print the answers
    cout << answer1 << endl;
    cout << answer2 << endl;
    cout << answer3 << endl;

    return 0;
}