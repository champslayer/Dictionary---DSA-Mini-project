#include<bits/stdc++.h>
using namespace std;
const int TS=10;
class node{
     public:
     string word,Meaning,Sentence;
     node *next;
     node(){
          word="";
          Meaning="";
          Sentence="";
          next=NULL;
     }
};

class spell{
     private:
     node Table[26][TS];
     public:
     void addValue(string Input,string Meaning,string Sentence){
          int count=0;
          for(int i=1;i<Input.length();i++){
               count=count+int(Input[i])*int(Input[i])+5*int(Input[i])+5;
          }
          count=count%TS;
          if(Table[Input[0]-'a'][count].word==""){
               Table[Input[0]-'a'][count].Meaning = Meaning;
               Table[Input[0]-'a'][count].word = Input;
               Table[Input[0]-'a'][count].next = NULL;
               Table[Input[0]-'a'][count].Sentence = Sentence;
          }
          else{
               node *ptr=Table[Input[0]-'a'][count].next;
               if(ptr==NULL){
                    node *x = new node();
                    Table[Input[0]-'a'][count].next=x;
                    x->word    = Input;
                    x->Meaning = Meaning;
                    x->Sentence = Sentence;
                    x->next    = NULL;         
               }
               else{
                    while(ptr->next!=NULL){
                         ptr=ptr->next;
                    }
                    node *x = new node();
                    ptr->next  = x;
                    x->word    = Input;
                    x->Meaning = Meaning;
                    x->Sentence = Sentence;
                    x->next    = NULL;
               }
          }
     }

     void Search(string Input){
          int count=0;
          for(int i=1;i<Input.length();i++){
               count=count+int(Input[i])*int(Input[i])+5*int(Input[i])+5;
          }
          count=count%TS;
          int comp = 0;
          node *ptr = &Table[Input[0]-'a'][count];
          while(ptr!= NULL){
               comp++;
               if( ptr->word == Input ){
                    cout<<"Word Found."<<endl<<"Meaning - "<<ptr->Meaning<<endl<<"A sentence for reference -> ( "<<ptr->Sentence<<" )"<<endl<<endl;
                    return;
               }
               ptr=ptr->next;
          }
          cout<<"Word Not Found in Database."<<endl;
     }

     void SearchChar(char inp){
          for(int i=0;i<10;i++){
               node *ptr = &Table[inp-'a'][i];
               while(ptr!= NULL && ptr->word!=""){
                    cout<<ptr->word<<endl<<"Meaning - "<<ptr->Meaning<<endl<<"A sentence for reference -> ( "<<ptr->Sentence<<" )"<<endl<<endl;
                    ptr=ptr->next;
               }
          }
     }
};

int main(){
     spell spellCheck;
     int i=1;
     ifstream File("Words.txt",ios::in);
     
     if ( !File ) {
          cout <<"Error opening file for input"<< endl ;
          return -1 ;
     } 
     
     string Word1,Word2,Word3;
     while(!File.eof()){
          getline(File,Word1);
          getline(File,Word2);
          getline(File,Word3);
          if(Word1!=""){
               cout<<Word1<<" -> "<<Word2<<endl<<"A sentence for reference -> ( "<<Word3<<" )"<<endl<<endl;
               spellCheck.addValue(Word1,Word2,Word3);
          }
     }

     while(i!=0){
          cout<<"0 For EXIT\n1 For SEARCHING A WORD\n2 For DISPLAY ALL WORD WITH SPECIFIC STARTING LETTER\nInput The Choice - ";
          cin>>i;
          if(i==1){
               cout<<"Enter the Word - ";
               string a;
               cin>>a;
               cout<<endl;
               spellCheck.Search(a);
               cout<<"Press 1 to Continue - ";
          }
          if(i==2){
               char x;
               cout<<"Input the char value ";
               cin>>x;
               spellCheck.SearchChar(x);
          }
     }
}