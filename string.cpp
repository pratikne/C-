#include<bits/stdc++.h>
#include<string.h>

using namespace std;


int main(){

    string s1; //Empty string initialized ""
    cout<<s1<<" "<<s1.size()<<endl;  //0

    string s2 = "Hello World";
    cout<<s2<<" "<<s2.size()<<endl;

    string s3 = s2;
    cout<<s3<<" "<<s3.size()<<endl;

    s3 = s3 + " C " + s2 + 'C' + 'B' + '1'; //Concatenation
    cout<<s3<<" "<<s3.size()<<endl;

/***
    cin>>s1; //only accepts a word(till space or enter is pressed)
    cout<<s1<<" "<<s1.size()<<endl;

    s1.clear();
    cout<<s1<<" "<<s1.size()<<endl;
***/
    getline(cin,s1);  //will accept string till enter is pressed
    cout<<s1<<" "<<s1.size()<<endl;

    s1.push_back('9');  //only accepts char
    cout<<s1<<" "<<s1.size()<<endl;

    string:: iterator it;
    for(it=s1.begin();it!=s1.end();it++){
        cout<<*it<<" ";
    }cout<<endl;

    string str;
    string str2 = "Writing ";
    string str3 = "print 10 and then 5 more";

    cout<<"APPEND FUNCTION TEST"<<endl; //adding from last
    str.append(str2);    //"Writing "
    str.append(str3,6,3); //"10 "
    str.append("dots are cool",5); //"dots "
    str.append("here: "); //"here: "
    str.append(10,'.'); //".........."
    str.append(str3.begin()+8,str3.end()); //" and then 5 more"
    cout<<str<<endl;

    cout<<"INSERT FUNCTION TEST"<<endl;
    str.clear();
    str2.clear();
    str3.clear();
    str = "to be question";
    str2 = "the ";
    str3 = "or not to be";

    //append ke aage bas position dedo of the string you want to insert
    str.insert(6,str2); //"to be the question"
    str.insert(6,str3,3,4); //"to be not the question"
    str.insert(10,"that is cool",8); //"to be not that is the question"
    str.insert(10,"to be "); //"to be not to be that is the question"
    str.insert(15,1,':'); //"to be not to be: that is the question"
    it = str.insert(str.begin()+5,'$'); //"to be$ not to be: that is the question"
    str.insert(str.end(),3,'.'); //"to be$ not to be: that is the question..."
    cout<<*it<<endl; //element at that iterator
    str.insert(it+2,str3.begin(),str3.begin()+3);  //"to be$ (or )not to be: that is the question..."
    cout<<str<<endl;


    cout<<"ERASE FUNCTION TEST"<<endl;
    str.clear();
    str = "This is an example sentence.";
    str.erase(10,8); //"This is an sentence"
    str.erase(str.begin()+9); //"This is a sentence"
    str.erase(str.begin()+5,str.end()-10); //"This sentence"
    cout<<str<<endl;

    cout<<"REPLACE FUNCTION TEST"<<endl;
    str.clear();
    str = "this is a test string.";
    str2 = "n example";
    str3 = "sample phrase";
    string str4 = "useful.";

    str.replace(9,5,str2); //"this is an example string."
    str.replace(19,6,str3,7,6); //"this is an example phrase."
    str.replace(8,10,"just a"); //"this is just a phrase."
    str.replace(8,6,"a shortleg",7); //"this is a short phrase."
    str.replace(22,1,3,'!'); //"this is a short phrase!!!"
    cout<<str<<endl;

    str.replace(str.begin(),str.end()-3,str3); //"sample phrase!!!"
    str.replace(str.begin(),str.begin()+6,"replace"); //"replace phrase!!!"
    str.replace(str.begin()+8,str.begin()+14,"is coolness",7); //"replace is cool!!!"
    cout<<str<<'\n';
    str.replace(str.begin()+12,str.end()-4,5,'O'); //"replace is cOOOOOl!!!"
    str.replace(str.begin()+11,str.end(),str4.begin(),str4.end()); //"replace is useful."
    cout<<str<<'\n';  //endl = '\n'

    cout<<"SWAP/COMPARE FUNCTION TEST"<<endl;
    str2 = "qwerty";
    cout<<"Before swap : "<< str << " | " << str2 <<endl;
    cout<<str.compare(str2)<<endl;
    str.swap(str2);
    cout<<"Before swap : "<< str << " | " << str2 <<endl;
    cout<<str.compare(str2)<<endl;  //0 if equal, -ve if first<second, +ve if first>second;

    cout<<"SUBSTR FUNCTION TEST"<<endl;
    string t = str2.substr(0);   //"replace is useful."
    cout<<t<<endl;
    t = str2.substr(1);   //"eplace is useful."
    t = str2.substr(2,5);   //"place"
    cout<<t<<endl;

    int pos = str2.find("place");   //gives starting index i.e 2
    pos = str2.find('e');   //finds starting position of e i.e 1..if not found..gives -1(npos)
    cout<<pos<<endl;
    if(str2.find('x') == string::npos)
        cout<<"Not found"<<endl;

    pos = str2.find('e'); //by default..starting from 0th pos
    if(pos != string::npos){
        cout<<"Found 'e'at pos "<<pos<<endl;
    }
    pos = str2.find('e',pos+1);
    if(pos != string::npos){
        cout<<"Next 'e' Found at pos "<<pos<<endl;
    }
    
    pos = str2.rfind('e');   //finds last position of e i.e 13
    cout<<pos<<endl;
    return 0;
}