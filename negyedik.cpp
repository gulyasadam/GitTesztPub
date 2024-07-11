// Negyedik labor.cpp : This file contains the 'main' function. Program
// execution begins and ends there.
//

/*
s[i], a.at[i]
+ : "cica"+"cica"=cicamica
string s = "cica"
if (s1==s2)
myStr.length()
.cstr()
.copy(char* s, mennyit, honnan=0)
insert(mit, hova)
s.replace(hova, mennyit, mivel)
int s.compare(m�sik string)
"abcdef".substring(2,3) => cde   //honnan, mennyit
size_t s1.find("bcd") keres�s, ha nem tal�l string::npos
*/
#include <iostream>
#include <string>
#include <tchar.h>

using namespace std;

class Splitter
{
    string s; // input
public:
    static string delim;
    Splitter() { s = ""; }
    // konstruktor NEM sz�mol, csak elrakja az adatokat
    Splitter(string input) : s(input){};
    int wordCount() const
    {
        bool inWord, wordChar; // �llapotv�ltoz�k
        unsigned int i;
        int wordCharVar = 0;
        inWord = false;

        for (i = 0; i < s.length(); i++)
        {
            wordChar = delim.find(s[i]) == string::npos;

            if (!inWord && wordChar)
            { // 1-es state
                inWord = true;
            }
            if (inWord && !wordChar)
            { // 3-as state
                inWord = false;
                wordCharVar++;
            }

        } // v�gig�rt�nk a mondaton
        if (inWord)
            wordCharVar++;
        return wordCharVar;
    }
    string wordAt(int wordIndex) const
    {
        bool inWord, wordChar; // �llapotv�ltoz�k
        unsigned int i, start;
        int wordCountVar = 0;
        inWord = false;

        for (i = 0; i < s.length(); i++)
        {
            wordChar = delim.find(s[i]) == string::npos;

            if (!inWord && wordChar)
            { // 1-es state
                inWord = true;
                start = i;
            }
            if (inWord && !wordChar)
            { // 3-as state
                inWord = false;
                if (wordCountVar == wordIndex)
                    return s.substr(start, i - start);
                wordCountVar++;
            }

        } // v�gig�rt�nk a mondaton
        if (inWord && wordCountVar == wordIndex)
            return s.substr(start, s.length() - start);
        return ""; // non-existent index
    }
};

string Splitter::delim = " ,.!?-";

int main()
{
    Splitter *SplitterInstance; // dinamikus p�ld�ny
    string mySentence;          // comment
    int wordCountVar, i;

    // setlocale(LC_ALL, "hun")

    cout << "Please input a sentence! :";
    getline(cin, mySentence);
    SplitterInstance = new Splitter(mySentence);
    // a dinamikus p�ld�nyban is benne van a static adattag
    cout << "CHARACTER USED AS DELIMINATORS: " << SplitterInstance->delim
         << endl;
    wordCountVar = SplitterInstance->wordCount();
    cout << "THIS SENTENCE CONTAINS " << wordCountVar << " WORDS" << endl;

    for (i = 0; i < 10; i++)
    {
        mySentence = SplitterInstance->wordAt(i);
        if (mySentence == "cica")
            mySentence.replace(0, 1, "m");
        cout << " WORD " << i << ": " << mySentence << endl;
    }

    delete SplitterInstance;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add
//   Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project
//   and select the .sln file
