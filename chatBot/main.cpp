#include <bits/stdc++.h>
using namespace std;

//chatBot
//Hi,
//Im sisi your best friend :)

bool isReserved ( string word) {

    if ( word == "What" ||
          word == "What's" ||
          word == "is" ||
          word == "are" ||
          word == "'re" ||
          word == "?" ||
          word == "your" ||
          word == "Where" ||
          word == "i" ||
          word == "my" ||
          word == "im" ||
          word == "how"
       )
            return true;
            return false;

}


string getWord (string q , int startfrom) {

    string word;

    while ( !isspace(q[startfrom]) && startfrom < q.size() ) {
            word += q[startfrom];
            startfrom++;
    }

    return word;
}

bool isExist (string word , string q) {

    for (int i = 0; i < q.size(); i++ ) {
        string t = getWord (q , i );
        if ( t == word )
            return true;
        else
            i += t.size();
    }
    return false;
}
int  getIndexTheIndexOfAns ( string q , vector <string> qs) {

    for ( int i = 0; i < qs.size(); i++ ) {
        for ( int j = 0; j < q.size(); j++ ) {
            string word = getWord ( q , j );
            if ( isExist( word , qs[i] ) && !isReserved( word) )
                 return i;
            else
                j += word.size() ;

        }

    }

    return -1;

}

int main() {

    vector <string> questions {

       "What's your name ?"
       , "How old 're you ?"
       , "Where're you from ?"
       , "Your favorite color ?"
       , "Your favorite team ?"
       , "Your favorite food ?"
    };

    vector <string> answring;

    //About sisi & Greating
    cout << "Hi,\nIm sisi your best friend :) \nWhat's up dude? \n";

    string input;
    cin >> input;
    cout << '\n';

    //Getting info. about the friend
    cout << "To be your best friend i need to ask you some questions, can i do ? [Y/N] \n";
    cin >> input;

    if ( input == "y" || input == "Y" ) {


        //Print the questions
        for ( auto question : questions){
            cout << question << '\n';
            cin >> input;
            answring.push_back(input);
        }

         cout << '\n';
         cout << "You are really a wonderful person!\n";
         cout << "Now you can test me if im your best friend or not ')\n";
         cout << "Lets' do it! Ask me\n";
         cout << "NOTE : ANY TIME YOU WANT TO EXIT ENTER --> E";
         cout << '\n';


         //Asking sisi
         cin.ignore();

         while ( getline( cin , input ) && input != "E"  && input != "e" ) {

         if ( input.size() ) {

                int posOfAnswer = getIndexTheIndexOfAns ( input , questions );
                if ( posOfAnswer != -1 )
                    cout << answring[posOfAnswer] << '\n';
                else {

                    cout << "Sorry, I don't know the answer to this question :(\n";
                    cout << "Can you tell me the answer dude? pls ')  ";
                    questions.push_back (input);
                    cout << "[Y/N]" << '\n';
                    cin >> input;

                    if ( input == "y" || input == "Y" ) {
                            cout << "Thanks, i swear i will be your best friend!\n";
                            cout << "Tell me the answer\n";
                            cin >> input;
                            answring.push_back(input);
                    }
                    else {
                        questions.pop_back();
                        cout << ":(\n";
                        cout << "If you want to turn off me you know what to do '(\n";
                    }

                }
            }
         }

         cout << "I will miss you " << answring[0] << '\n';

        }
    else
        cout << "I will miss you my best friend" << '\n';


    return 0;
}
