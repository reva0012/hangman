#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <cstring>

using namespace std;
inline void type_of_word(char f);
int main(){   
    char c,h,ch,ch1,ch2;
    char word[25];
    char word2[25];
    int l,i,ng,n,k,x;
    do{
    do{
        c='\0';
        cout<<"\n\t\t HANGMAN \n\n";
        cout<<"(E) Enter a word
        \n\n(C) Computer chooses word
        \n\n(A) Add new word to list
        \n\n(Q) Quit
        \n\n\nEnter your choice (E/C/Q): ";
        cin>>ch2;
    }
        while (ch2!='C' && ch2!='c' && ch2!='E' && ch2!= 'e' && ch2!='Q' && ch2!= 'q'&& ch2!='A' && ch2!= 'a');
        if (ch2 == 'Q' || ch2=='q')  
            exit (0);
        if (ch2 == 'C' || ch2=='c'){
        ifstream fin("hangman.txt");
        if(!fin) {
        cout<<"File missing";
        system("pause"); return 0;}
        for (i=0;!fin.eof();i++)   fin.getline(word,25);
        fin.close();
        do {
        x=rand();
        }while(x>i || x<0);
        ifstream finn("hangman.txt");
        for (i=0;!finn.eof();i++)
        {finn>>c; finn.getline(word,25); if (x==i) break;}
        finn.close();
    }
    if (ch2 == 'A' || ch2=='a'){
        ofstream fout("hangman.txt",ios::app);
        if(!fout)
            cout<<"File missing";
        cin.get();
        cout<<"Choose a category: 
        \n\n(M) Movies
        \n\n(A) Actors
        \n\n(P) Sports
        \n\n(S) Songs
        \n\nEnter your choice (M/A/P/S) : ";
        cin>>h;
        cin.get();
        //clrscr();
        cout<<"\n\nThe word should not exceed 25 letters\n\nEnter the word : ";
        cin.getline(word,25);
        fout<<h<<word<<endl;
        fout.close();

    }


   if (ch2 == 'E' || ch2=='e')
     {// clrscr();
       cin.get();
       cout<<"\t\t\t Type the word :  ";
       cin.getline (word, 25);
     }
 if (ch2 == 'E' || ch2=='e' || ch2 == 'C' || ch2=='c')
{
l=strlen(word);
char choosen[25]="\0";
n=0;k=0;

 for(i=0;i<=24;i++)
   {
    if (word[i]=='\0') {word2[i]='\0';break;}
    if (word[i]==' ')  {word2[i]=' ';  n++;}
    if (word[i]!=' ')  word2[i]='-';
   }
ng=l+2-n;    
   do{
   there:  type_of_word(c);
     if (k!=0)  cout<<"\n\n\t\t\tChoosen letters : "<<choosen<<"\n";
     cout<<"\n\n\n\t\t\t      "<<word2<<"\n\n\n"<<ng<< " guesses left, choose a letter : ";
     cin>>ch; cin.get();
     for (i=0;i<25;i++) if (choosen[i]==ch) {
     cout<<"\a\t\t     !!You have choosen "<<ch<<" already!!\n";goto there;}
     ng--; choosen [k]=ch; choosen [k+1]=',';k+=2;
     for (i=0;i<=24;i++)
     if (word[i]==ch || word[i]==ch+32 || word[i]==ch-32) word2[i]=ch;
     if (!strcmp (word2,word)) {cout<<"\n\t\t\t      "<<strdup(word)
     <<"\n\n\t\t\tCongratulations\n"; break;}

    }while(ng>0 || !strcmp(word2,word));

if (strcmp(word2,word))  cout<<"\nGame Over.\n\nThe word was : "
<<strdup(word)<<endl;
}

cout<<"\nWould you like to play again? (Y: Yes\nN: No) : ";
cin>>ch1;  
cin.get();
}while (ch1=='y' || ch1=='Y');
      system("PAUSE");
      return 0;
}
inline void type_of_word(char f){    
    if (f=='m') cout<<"\t\t\t\tMOVIE";
    if (f=='a') cout<<"\t\t\t\tANIMAL";
    if (f=='p') cout<<"\t\t\t\tSPORT";
    if (f=='s') cout<<"\t\t\t\tSONG";
}