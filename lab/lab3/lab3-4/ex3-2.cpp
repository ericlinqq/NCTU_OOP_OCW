// ex3-2.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void init();
void EnterIndex(int &now, int &index1, int &index2);
bool Check(int &now, int &index1, int &index2);
void ShowAnswer();

struct Answer {
    char alphabet[18] = {0};
    int index[18][2] = {{0}, {0}};
}answer, record;

char Card[36] = {0};
char myCard[36] = {0};

int main() {
    // initialize random seed
    srand(time(NULL));

    // intial card desk
    init();

    // Enter index
    int index1, index2, now = 0;
    while (now <= 18) {
        if (now < 18)
            EnterIndex(now, index1, index2);
        Check(now, index1, index2);
    }

    return 0;
}

void init() {
    // Store all the capital alphabet into one array
    char alphabet[26] = {0};
    for (int i = 0; i < 26; i++) {
        alphabet[i] = 'A' + i;
    }

    // Put the alphabet into the card desk
    for (int i=0, j=0, k=0; i < 18; i++) {
        // chose an unique alphabet
        j = rand()%26;
    
        while (alphabet[j] == 0) {
            j = rand()%26;
        }

        answer.alphabet[i] = alphabet[j];
        alphabet[j] = 0;

        // choose two unique indexes
        k = rand()%36;

        while (Card[k] != 0) {
            k = rand()%36;
        }

        Card[k] = answer.alphabet[i];
        answer.index[i][0] = k+1;

        while (Card[k] != 0) {
            k = rand()%36;
        }

        Card[k] = answer.alphabet[i];
        answer.index[i][1] = k+1; 
    }
}

void EnterIndex(int &now, int &index1, int &index2) {
    // Enter the first index
cout << "Please enter card index (start from 1, enter 0 to show the answer): ";
    cin >> index1;
    // if enter 0, show the answer
    if (index1 == 0) {
        index2 = 0;
        ShowAnswer();
    }
    // index out of range
    else if ((index1 > 36) || (index1 < 0)) {
        cout << "Index out of range" << endl;
    }
    else {
        // show the card desk
        for (int i = 0; i < 6; i++) {   // row major
            for (int j = 0; j < 6; j++) {
                if ((6*i+j+1 == index1) || (myCard[6*i+j] != 0)) {
                    cout << Card[6*i+j] << " ";
                }
                else {
                    cout << "*" << " ";
                }          
            }
            cout << endl;
        }
        cout << endl;

        // Enter the second index
        cout << "Please enter card index: (start from 1, enter 0 to show the answer)";
        cin >> index2;
        
        if (index2 == 0) {
            index1 = 0;
            ShowAnswer();
        }
        else if ((index2 > 36) || (index2 < 0)) {
            cout << "Index out of range" << endl;
        }
        else {
            // show the card desk
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 6; j++) {
                    if ((6*i+j+1 == index1) || (6*i+j+1 == index2) || (myCard[6*i+j] != 0)) {
                        cout << Card[6*i+j] << " ";
                    }
                    else {
                        cout << "*" << " ";
                    }
                }
                cout << endl;
            }
            cout << endl;
        }
    }
}

bool Check(int &now, int &index1, int &index2) {
    // Not finished
    if (index1 == 0 && index2 == 0) {
        return 0;
    }

    if (now < 18) {
        // Correct
        if (Card[index1-1] == Card[index2-1]) {
            cout << "Good Job!" << endl;
            // set myCard, record
            myCard[index1-1] = myCard[index2-1] = record.alphabet[now] = Card[index1-1];
            record.index[now][0] = index1;
            record.index[now][1] = index2;
            now++;
            cout << "now: " << now << endl;
        }
        else {
            cout << "Try Again!" << endl;
        }
    }
    // finish the game
    else if (now == 18) {
        cout << "Congratulations!" << endl;
        now++;
    }
    else {
        cout << "ERROR..." << endl;
    }
    return 1;
}

void ShowAnswer() {
    // show the answer list
    cout << "answer: " << endl;
    for (int i = 0; i < 18; i++) {
        cout << answer.alphabet[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 18; i++) {
        cout << answer.index[i][0] << " ";
    }
    cout << endl;

    for (int i = 0; i < 18; i++) {
        cout << answer.index[i][1] << " ";
    }
    cout << endl;
    
    //show the answer card desk
    cout << "Card:" << endl;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cout << Card[6*i+j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
