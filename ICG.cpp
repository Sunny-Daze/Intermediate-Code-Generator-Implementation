#include<iostream>
#include<string>
#include<fstream>
using namespace std;

#define nline "\n"
#define tab "\t"
#define sz(x) ((int)(x).length())

int replace = 0, subReplace=0;
string s;
void bind(int key){
    if(s[key+1]=='~'){
        string a = s.substr(0, key+1);
        replace++;
        string b = 't' + to_string(replace);
        string c = s.substr(key+3, sz(s)-1);
        s = a + b + c;
    }
    else if(isdigit(s[key-1]) && s[key+1]=='t'){
        string a = s.substr(0, key-2);
        replace++;
        string b = 't' + to_string(replace);
        string c = s.substr(key+3, sz(s)-1);
        s = a + b + c;
    }
    else if(isdigit(s[key-1])){
        string a = s.substr(0, key-2);
        replace++;
        string b = 't' + to_string(replace);
        string c = s.substr(key+2, sz(s)-1);
        s = a + b + c;
    }
    else if(s[key+1]=='t'){
        string a = s.substr(0, key-1);
        replace++;
        string b = 't' + to_string(replace);
        string c = s.substr(key+3, sz(s)-1);
        s = a + b + c;
    }
    else{
        string a = s.substr(0, key-1);
        replace++;
        string b = 't' + to_string(replace);
        string c = s.substr(key+2, sz(s)-1);
        s = a + b + c;
    }
}

int main(){
    ofstream coutf;
    coutf.open("output.txt");
    cout << "Note -> Use '~' for representing negation!" << nline << nline;
    cout << "Enter the expresesion -> ";
    cin >> s;

    int n=0;
    for(auto x : s)
        if(x=='/' || x=='*' || x=='+' || x=='-' || x=='~' || x=='=')
            n++;

    string ans[n][4];
    int indRow=0, indCol=0;
    for(int i=0;i<sz(s);i++){
        if(s[i] == '/'){
            if(s[i+1] == '~'){
                ans[indRow][indCol] = '~';
                ans[indRow][++indCol] = s[i+2];
                ans[indRow][++indCol] = '_';
                ans[indRow][++indCol] = 't' + to_string(++subReplace);
                bind(i);
                indCol = 0;
                indRow++;
                ans[indRow][indCol] = s[i];
                ans[indRow][++indCol] = s[i-1];
                ans[indRow][++indCol] = 't' + to_string(s[i+2]-'0');
                ans[indRow][++indCol] = 't' + to_string(++subReplace);
                indCol = 0;
                indRow++;
                bind(i);
                i=1;
            }
            else if(isdigit(s[i-1]) && s[i+1]=='t'){
                ans[indRow][indCol] = s[i];
                ans[indRow][++indCol] = 't' + to_string(s[i-1]-'0');
                ans[indRow][++indCol] = 't' + to_string(s[i+2]-'0');
                ans[indRow][++indCol] = 't' + to_string(++subReplace);
                indCol = 0;
                indRow++;
                bind(i);
                i=1;
            }
            else if(isdigit(s[i-1])){
                ans[indRow][indCol] = s[i];
                ans[indRow][++indCol] = 't' + to_string(s[i-1]-'0');
                ans[indRow][++indCol] = s[i+1];
                ans[indRow][++indCol] = 't' + to_string(++subReplace);
                indCol = 0;
                indRow++;
                bind(i);
                i=1;
            }
            else if(s[i+1] == 't'){
                ans[indRow][indCol] = s[i];
                ans[indRow][++indCol] = s[i-1];
                ans[indRow][++indCol] = 't' + to_string(s[i+2]-'0');
                ans[indRow][++indCol] = 't' + to_string(++subReplace);
                indCol = 0;
                indRow++;
                bind(i);
                i=1;
            }
            else{
                ans[indRow][indCol] = s[i];
                ans[indRow][++indCol] = s[i-1];
                ans[indRow][++indCol] = s[i+1];
                ans[indRow][++indCol] = 't' + to_string(++subReplace); 
                indCol=0;
                indRow++;
                bind(i);
                i=1;
            }
        }
    }

       for(int i=0;i<sz(s);i++){
        if(s[i] == '*'){
            if(s[i+1] == '~'){
                ans[indRow][indCol] = '~';
                ans[indRow][++indCol] = s[i+2];
                ans[indRow][++indCol] = '_';
                ans[indRow][++indCol] = 't' + to_string(++subReplace);
                bind(i);
                indCol = 0;
                indRow++;
                ans[indRow][indCol] = s[i];
                ans[indRow][++indCol] = s[i-1];
                ans[indRow][++indCol] = 't' + to_string(s[i+2]-'0');
                ans[indRow][++indCol] = 't' + to_string(++subReplace);
                indCol = 0;
                indRow++;
                bind(i);
                i=1;
            }
            else if(isdigit(s[i-1]) && s[i+1]=='t'){
                ans[indRow][indCol] = s[i];
                ans[indRow][++indCol] = 't' + to_string(s[i-1]-'0');
                ans[indRow][++indCol] = 't' + to_string(s[i+2]-'0');
                ans[indRow][++indCol] = 't' + to_string(++subReplace);
                indCol = 0;
                indRow++;
                bind(i);
                i=1;
            }
            else if(isdigit(s[i-1])){
                ans[indRow][indCol] = s[i];
                ans[indRow][++indCol] = 't' + to_string(s[i-1]-'0');
                ans[indRow][++indCol] = s[i+1];
                ans[indRow][++indCol] = 't' + to_string(++subReplace);
                indCol = 0;
                indRow++;
                bind(i);
                i=1;
            }
            else if(s[i+1] == 't'){
                ans[indRow][indCol] = s[i];
                ans[indRow][++indCol] = s[i-1];
                ans[indRow][++indCol] = 't' + to_string(s[i+2]-'0');
                ans[indRow][++indCol] = 't' + to_string(++subReplace);
                indCol = 0;
                indRow++;
                bind(i);
                i=1;
            }
            else{
                ans[indRow][indCol] = s[i];
                ans[indRow][++indCol] = s[i-1];
                ans[indRow][++indCol] = s[i+1];
                ans[indRow][++indCol] = 't' + to_string(++subReplace); 
                indCol=0;
                indRow++;
                bind(i);
                i=1;
            }
        }
    }

   for(int i=0;i<sz(s);i++){
        if(s[i] == '+'){
            if(s[i+1] == '~'){
                ans[indRow][indCol] = '~';
                ans[indRow][++indCol] = s[i+2];
                ans[indRow][++indCol] = '_';
                ans[indRow][++indCol] = 't' + to_string(++subReplace);
                bind(i);
                indCol = 0;
                indRow++;
                ans[indRow][indCol] = s[i];
                ans[indRow][++indCol] = s[i-1];
                ans[indRow][++indCol] = 't' + to_string(s[i+2]-'0');
                ans[indRow][++indCol] = 't' + to_string(++subReplace);
                indCol = 0;
                indRow++;
                bind(i);
                i=1;
            }
            else if(isdigit(s[i-1]) && s[i+1]=='t'){
                ans[indRow][indCol] = s[i];
                ans[indRow][++indCol] = 't' + to_string(s[i-1]-'0');
                ans[indRow][++indCol] = 't' + to_string(s[i+2]-'0');
                ans[indRow][++indCol] = 't' + to_string(++subReplace);
                indCol = 0;
                indRow++;
                bind(i);
                i=1;
            }
            else if(isdigit(s[i-1])){
                ans[indRow][indCol] = s[i];
                ans[indRow][++indCol] = 't' + to_string(s[i-1]-'0');
                ans[indRow][++indCol] = s[i+1];
                ans[indRow][++indCol] = 't' + to_string(++subReplace);
                indCol = 0;
                indRow++;
                bind(i);
                i=1;
            }
            else if(s[i+1] == 't'){
                ans[indRow][indCol] = s[i];
                ans[indRow][++indCol] = s[i-1];
                ans[indRow][++indCol] = 't' + to_string(s[i+2]-'0');
                ans[indRow][++indCol] = 't' + to_string(++subReplace);
                indCol = 0;
                indRow++;
                bind(i);
                i=1;
            }
            else{
                ans[indRow][indCol] = s[i];
                ans[indRow][++indCol] = s[i-1];
                ans[indRow][++indCol] = s[i+1];
                ans[indRow][++indCol] = 't' + to_string(++subReplace); 
                indCol=0;
                indRow++;
                bind(i);
                i=1;
            }
        }
    }

       for(int i=0;i<sz(s);i++){
        if(s[i] == '-'){
            if(s[i+1] == '~'){
                ans[indRow][indCol] = '~';
                ans[indRow][++indCol] = s[i+2];
                ans[indRow][++indCol] = '_';
                ans[indRow][++indCol] = 't' + to_string(++subReplace);
                bind(i);
                indCol = 0;
                indRow++;
                ans[indRow][indCol] = s[i];
                ans[indRow][++indCol] = s[i-1];
                ans[indRow][++indCol] = 't' + to_string(s[i+2]-'0');
                ans[indRow][++indCol] = 't' + to_string(++subReplace);
                indCol = 0;
                indRow++;
                bind(i);
                i=1;
            }
            else if(isdigit(s[i-1]) && s[i+1]=='t'){
                ans[indRow][indCol] = s[i];
                ans[indRow][++indCol] = 't' + to_string(s[i-1]-'0');
                ans[indRow][++indCol] = 't' + to_string(s[i+2]-'0');
                ans[indRow][++indCol] = 't' + to_string(++subReplace);
                indCol = 0;
                indRow++;
                bind(i);
                i=1;
            }
            else if(isdigit(s[i-1])){
                ans[indRow][indCol] = s[i];
                ans[indRow][++indCol] = 't' + to_string(s[i-1]-'0');
                ans[indRow][++indCol] = s[i+1];
                ans[indRow][++indCol] = 't' + to_string(++subReplace);
                indCol = 0;
                indRow++;
                bind(i);
                i=1;
            }
            else if(s[i+1] == 't'){
                ans[indRow][indCol] = s[i];
                ans[indRow][++indCol] = s[i-1];
                ans[indRow][++indCol] = 't' + to_string(s[i+2]-'0');
                ans[indRow][++indCol] = 't' + to_string(++subReplace);
                indCol = 0;
                indRow++;
                bind(i);
                i=1;
            }
            else{
                ans[indRow][indCol] = s[i];
                ans[indRow][++indCol] = s[i-1];
                ans[indRow][++indCol] = s[i+1];
                ans[indRow][++indCol] = 't' + to_string(++subReplace); 
                indCol=0;
                indRow++;
                bind(i);
                i=1;
            }
        }
    }

    ans[indRow][indCol] = s[1];
    ans[indRow][++indCol] = 't' + to_string(s[3]-'0');
    ans[indRow][++indCol] = '_';
    ans[indRow][++indCol] = s[0];
    indRow++;
    indCol=0;

    coutf << tab << "==========================================================" << nline;
    coutf << tab << "   Operator" << tab << "    Argument1" << tab << "    Argument2" << tab << "      Result" << nline;
    coutf << tab << "==========================================================" << nline;
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            coutf << tab << tab << ans[i][j] << tab << tab;
        }
        coutf << nline << tab << "----------------------------------------------------------" << nline;
    }
    cout << nline << "->Compilation Successfull<-" << nline;
    cout << nline << "Check 'output.txt' for the output";
    coutf.close();
    return 0;
}