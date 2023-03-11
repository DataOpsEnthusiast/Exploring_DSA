#include <iostream>
#include <fstream>
#include <string>
 #include <cstring>
using namespace std;

int main ()
{
  ifstream MyFile("Hamza_Mehmood.txt");
char str[1000];
int wordCount=0;
string text;
  getline(MyFile, text );
  MyFile.close();

  for(int i=0;i<text.length();i++){
    str[i] = text.at(i);
  }
    char word[1000];
    int i, j, found;
    int strLen, wordLen;

   cout<<"Enter Word To Search For"<<endl;
    cin>>word;

    strLen  = strlen(str);
    wordLen = strlen(word);
    for(i=0; i<strLen - wordLen; i++)
    {
        found = 1;
        for(j=0; j<wordLen; j++)
        {

            if(str[i + j] != word[j])
            {
                found = 0;
                break;
            }
        }
        if(found == 1)
        {
            cout<<word<<" is found at index "<<i<<endl;
            wordCount++;
        }
    }
    cout<<"Occurrence of Words Are "<<wordCount;

    return 0;

}