#include <iostream>
#include <string>
#include <fstream>
#include <iomanip> 
#include <conio.h>
using namespace std;
int advcounter = 0,maxpasschange = 0;
string addstofile;

class input
{
    string message,mhistory,dhistory;
    string password,password1;
    string add_pass;
    int pass_length;
    int strlength,az = 0,passmessagechk=0;
    char cho;
    string key = "#$21!&"; 
    string code_is_encrypted= "$!#25*&"; 
    string passwordFromFile, chkpass, passwordbyuser;
    string encryptedpass;
    string passwordhast2 = "140256";
    string passwordhast1 = "789256";


public:
    
    int i = 0,learn_more;
    int codemessage()
    {
    
    char loop;

    
    while (1) {
        cout << "---------------------------------------------" << endl;
        cout << "|          Welcome to EncryptX              |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "Enter Your Message (Enter\033[0;31m ##\033[0m for Advanced Options): ";        
        fflush(stdin);
        getline(cin, message);
        strlength = message.length();
        if (message.empty())
        {
            system("cls");
            cout<<"\033[0;31m";
            cout<<"Please Enter Message"<<endl;
            cout<<"\033[0m";
        }
        else if(message[0] == ' ')
        {
        system("cls");
        cout<<"\033[0;31m";
        cout << "Your Message Cannot Starts With White Spaces" <<endl;
        cout<<"\033[0m";
        }
        else if((message[0] != '$' && message[1] != '!' && message[2] != '#' && message[3] != '2' && message[4] != '5' && message[5] != '*' && message[6] != '&') && strlength > 170)
        {
            cout<<"\033[0;31m"<<endl;
            system("cls");
            cout<<"Your Message Should be 170 Letters or less"<<endl;
            cout<<"\033[0m";
            // codemessage();
        }
        else if((message[i] == '$' && message[i+1] == '!' && message[i+2] == '#' && message[i+3] == '2' && message[i+4] == '5' && message[i+5] == '*' && message[i+6] == '&') && strlength > 4080)
        {
            cout<<"\033[0;31m"<<endl;
            system("cls");
            cout<<"The Encrypted Message Is Too Long. It Appears To Be Combined."<<endl;
            cout<<"\033[0m";
        }
        else{
            strlength = message.length();
            break;
        }
    }

    if((message[i] == '$' && message[i+1] == '!' && message[i+2] == '#' && message[i+3] == '2' && message[i+4] == '5' && message[i+5] == '*' && message[i+6] == '&') && (message[i+7] == '#' && message[i+8] == '$' && message[i+9] == '2' && message[i+10] == '1' && message[i+11] == '!' && message[i+12] == '&')  )
    {
            passmessagechk++;
            cout<<"This message is Password Protected\n";
            pass_protect();

    }  

    else if (message[i] == '$' && message[i+1] == '!' && message[i+2] == '#' && message[i+3] == '2' && message[i+4] == '5' && message[i+5] == '*' && message[i+6] == '&' && message != key )    
    {   
        passmessagechk = 0;
        if(passmessagechk == 0){
        dhistory += "\033[0;34m\033[1m\033[4mYour Entered Encrypted Message\033[0m\n";
        dhistory += message; 
        dhistory += "\n\033[0;34m\033[1m\033[4mYour Decrypted Message\033[0m\n";
        }
        decrypt(strlength);
    }

        else{
        if(message == "##" && message[2] == '\0' && advcounter == 0)
        {
            login();
        }
        else if(message == "##" && message[2] == '\0' && advcounter >=  1)
        {
            advopt();
        }
        else
        {
        cout<<"Your Message Length:"<<"\033[0;32m"<<strlength<<"\033[0m";
        cout<<"\n\033[0;33mSelect your Preference\033[0m\n\033[0;34m1.Encrypt\n\033[0;35m2.Password Encrypt\n\033[0;32m3.Exit\n\033[0mChoice: ";
        cin>>cho;

        if(cho == '1') //$!#25*&
        {
        if(message[i] == '$' && message[i+1] == '!' && message[i+2] == '#' && message[i+3] == '2' && message[i+4] == '5' && message[i+5] == '*' && message[i+6] == '&')
        {
            cout<<"\033[0;31m";        
            cout<<"This message is already encrypted :)";
            cout<<"\033[0m";
        }   
        else 
        {  
        mhistory += "\033[0;34m\033[1m\033[4mYour Entered Message\033[0m\n";
        mhistory += message; 
        mhistory += "\n\033[0;34m\033[1m\033[4mYour Encrypted Message\033[0m\n";    
        encrypt(strlength);
        }
        }
        else if(cho == '2')
        {
        if(message[i] == '$' && message[i+1] == '!' && message[i+2] == '#' && message[i+3] == '2' && message[i+4] == '5' && message[i+5] == '*' && message[i+6] == '&')
        {
            cout<<"\033[0;31m";        
            cout<<"This message is already encrypted :)";
            cout<<"\033[0m";
        }   
        else{
            add_pass_func();
        }
        }
        else if(cho == '3')
        {
            exit(0);
        }
        else
        {
            cout<<"\033[0;31m";
            cout<<"Invalid Input";
            cout<<"\033[0m";
        }
   
    }
    }
    }
    // Adding password 
    void add_pass_func()
    {
        char ch;
        do{
            add_pass.clear();
        cout<<"Enter 4 Digit Security Pin: ";
        while (true) {
        ch = getch();
        if (ch == 13) { 
        break;
        } else if (ch == 8) { 
        if (!add_pass.empty()) {
        cout << "\b \b";
        add_pass.pop_back();
        }
        } else {
        cout << '*';
        add_pass += ch;
        }
        }
        pass_length = add_pass.length();
        cout<<endl;
        }while(pass_length != 4 || !isdigit(add_pass[0]) || !isdigit(add_pass[1]) || !isdigit(add_pass[2]) || !isdigit(add_pass[3]));
        cout<<endl;
        encrypt(strlength);
    }

    //  Checking Password
     void pass_protect()
     {  
        char ch;
        int a = 0;
        int passlength;
        while(1)
        {
        do{
            password.clear();
            fflush(stdin);
        cout<<"Enter password : ";
        
                while (true) {
                    ch = getch();
                    if (ch == 13) { 
                    break;
                    } else if (ch == 8) { 
                    if (!password.empty()) {
                    cout << "\b \b";
                    password.pop_back();
                    }
                    } else {
                    cout << '*';
                    password += ch;
                    }
                    }


        // getline(cin,password);
        passlength = password.length();
        cout<<endl;
        if(passlength > 4 )
        {        
                cout << "\033[0;31mIncorrect password.\033[0m" << endl;
                a++;
                if(a == 3)
                {
    
                cout<<"\033[0;31mToo Many unsuccessful attempt!!Try back later :)\033[0m";
                break;
            }
        }
        }while(passlength>4);
        int key_start = strlength - 20;  
        if(message[key_start+2] == password[0] && message[key_start+7] == password[1] && message[key_start+12] == password[2] && message[key_start+17] == password[3] )
        {
            decrypt(strlength-20);
            break;
        }
        else
        {   a++;
            cout << "\033[0;31mIncorrect password.\033[0m" << endl;
            if(a == 3)
            {
                cout<<"\033[0;31mToo Many unsuccessful attempt!!Try back later :)\033[0m";
                break;
                return ;
            }
        }
        }
     }

    void encrypt(int strlength) 
    {
        string code_is_our_encp = "-!9%&#&``>";   
        string salt1 = "!~$%34*^`";
        string salt2 = "%^&78!~.";
        string salt3 = "~!^&89!*";
        string salt4 = "!@#&*^%$~7";
        string salt5 = "(*&^%$#@!~5";
        string salt6 = "!~&$%^*#!2";
        string salt7 = "#$%~*!^&1";
        // system("cls");
        cout<<"\033[0;33mYour Encryted Message:\033[0m\n\n";
        mhistory += code_is_encrypted;
        cout<<code_is_encrypted;
        if(cho == '2')
        {
            cout<<key;
        }
        for (i = 0; i < strlength; i++) 
        {
            if(message[i] == ' ')
            {
                mhistory += "&!*3*!";
                cout<<"&!*3*!";
            }
            else 
            if (message[i] == '0') 
            {
                mhistory += "#@^10@";
                cout << "#@^10@";
            } 
            else 
            if (message[i] == '1') 
            {
                mhistory += "#@^21~";
                cout << "#@^21~";
            }  
            else 
            if (message[i] == '2') 
            {
                mhistory += "$@^42~";
                cout << "$@^42~";
            }           
            else 
            if (message[i] == '3') 
            {
                mhistory += "#@^63@" ;
                cout << "#@^63@";
            }  
            else 
            if (message[i] == '4') 
            {
                mhistory += "#@^-84";
                cout << "#@^-84";
            }  
            else 
            if (message[i] == '5') 
            {
                mhistory += "#*^16~" ;
                cout << "#*^16~";
            }  
            else 
            if (message[i] == '6') 
            {
                mhistory += "#@^28~";
                cout << "#@^28~";
            }  
            else 
            if (message[i] == '7') 
            {
                mhistory += "#@`25~";
                cout << "#@`25~";
            }  
            else 
            if (message[i] == '8') 
            {
                mhistory += "#@^17~";
                cout << "#@^17~";
            } 
            else 
            if (message[i] == '9') 
            {
                mhistory += "#@^99~";
                cout << "#@^99~";
            }   
            else 
            if (message[i] == 'A') 
            {
                mhistory += "#@^21@";
                cout << "#@^21@";
            } 
            else
            if(message[i] == 'B') 
            {
                mhistory += "@&^22$";
                cout << "@&^22$";
            }
            else
            if(message[i] == 'C') 
            {
                mhistory += "!@$23^";
                cout << "!@$23^";
            }
            else
            if(message[i] == 'D') 
            {
                mhistory += ")!$31-";
                cout << ")!$31-";
            }
            else
            if(message[i] == 'E') 
            {
                mhistory += "~/%32!" ;
                cout << "~/%32!";
            }
            else
            if(message[i] == 'F') 
            {
                mhistory += "=!#33#";
                cout << "=!#33#";
            }
            else
            if(message[i] == 'G') 
            {
                mhistory += "?!@41%";
                cout << "?!@41%";
            }
            else
            if(message[i] == 'H') 
            {
                mhistory += "^@,42&" ;
                cout << "^@,42&";
            } 
            else
            if(message[i] == 'I') 
            {
                mhistory += "{/!43&";
                cout << "{/!43&";
            } 
            else 
             if(message[i] == 'J') 
            {
                mhistory += ".`$51@" ;
                cout << ".`$51@";
            }
            else
            if(message[i] == 'K') 
            {
                mhistory += "-{,52~" ;
                cout << "-{,52~";
            }  
            else 
            if(message[i] == 'L') 
            {
                mhistory += "#x:53`" ;
                cout << "#x:53`";
            } 
            else 
            if(message[i] == 'M') 
            {
                mhistory += "<!~61/";
                cout << "<!~61/";
            } 
            else 
            if(message[i] == 'N') 
            {
                mhistory +=  "<?-62_";
                cout << "<?-62_";
            } 
            else 
            if(message[i] == 'O') 
            {
                mhistory += "!`~63-";
                cout << "!`~63-";
            } 
            else 
            if(message[i] == 'P') 
            {
                mhistory += "!`~63-" ;
                cout << "#&^71/";
            }
            else                     
            if(message[i] == 'Q') 
            {
                mhistory += "-%^72!";
                cout << "-%^72!";
            }
            else  
            if(message[i] == 'R') 
            {
                mhistory += "`~/73^";
                cout << "`~/73^";
            } 
            else 
            if(message[i] == 'S') 
            {
                mhistory += "{>#74`";
                cout << "{>#74`";
            } 
            else 
            if(message[i] == 'T') 
            {
                mhistory += "<?=81-" ;
                cout << "<?=81-";
            } 
            else 
            if(message[i] == 'U') 
            {
                mhistory += "!@/82+";
                cout << "!@/82+";
            }
            else  
            if(message[i] == 'V') 
            {
                mhistory += "#;@83)";
                cout << "#;@83)";
            } 
            else 
            if(message[i] == 'W') 
            {
                mhistory += "#$^91)" ;
                cout << "#$^91)";
            } 
            else 
            if(message[i] == 'X') 
            {
                mhistory += "!#%92^";
                cout << "!#%92^";
            } 
            else 
            if(message[i] == 'Y') 
            {
                mhistory += "@$^93%";
                cout << "@$^93%";
            } 
            else 
            if(message[i] == 'Z') 
            {
                mhistory += "#^(94$";
                cout << "#^(94$"; 
            } 
            else 
            if (message[i] == 'a') 
            {
                mhistory += "#@*21@";
                cout << "#@*21@";
            } 
            else
            if(message[i] == 'b') 
            {
                mhistory += "@&^22*" ;
                cout << "@&^22*";
            }
            else
            if(message[i] == 'c') 
            {
                mhistory += "*@$23^";
                cout << "*@$23^";
            }
            else
            if(message[i] == 'd') 
            {
                mhistory += ")!*31-";
                cout << ")!*31-";
            }
            else
            if(message[i] == 'e') 
            {
                mhistory += "~/%32*";
                cout << "~/%32*";
            }
            else
            if(message[i] == 'f') 
            {
                mhistory += "*!#33#";
                cout << "*!#33#";
            }
            else
            if(message[i] == 'g') 
            {
                mhistory += "?!@41*";
                cout << "?!@41*";
            }
            else
            if(message[i] == 'h') 
            {
                mhistory += "^@*42&";
                cout << "^@*42&";
            } 
            else
            if(message[i] == 'i') 
            {
                mhistory += "*/!43&";
                cout << "*/!43&";
            } 
            else 
             if(message[i] == 'j') 
            {
                mhistory += "*`$51@" ;
                cout << "*`$51@";
            }
            else
            if(message[i] == 'k') 
            {
                mhistory += "-*,52~";
                cout << "-*,52~";
            }  
            else 
            if(message[i] == 'l') 
            {
                mhistory += "#*:53`";
                cout << "#*:53`";
            } 
            else 
            if(message[i] == 'm') 
            {
                mhistory += "*!~61/" ;
                cout << "*!~61/";
            } 
            else 
            if(message[i] == 'n') 
            {
                mhistory += "<?*62_";
                cout << "<?*62_";
            } 
            else 
            if(message[i] == 'o') 
            {
                mhistory += "!~*63~";
                cout << "!~*63~"; 
            } 
            else 
            if(message[i] == 'p') 
            {
                mhistory += "#&*71/";
                cout << "#&*71/";
            }
            else                     
            if(message[i] == 'q') 
            {
                mhistory += "*%^72!";
                cout << "*%^72!";
            }
            else  
            if(message[i] == 'r') 
            {
                mhistory += "*~/73^";
                cout << "*~/73^";
            } 
            else 
            if(message[i] == 's') 
            {
                mhistory += "*>#74`";
                cout << "*>#74`";
            } 
            else 
            if(message[i] == 't') 
            {
                mhistory += "<?`81*";
                cout << "<?`81*";
            } 
            else 
            if(message[i] == 'u') 
            {
                mhistory += "!@/82*"; 
                cout << "!@/82*";
            }
            else  
            if(message[i] == 'v') 
            {
                mhistory += "#;@83*"; 
                cout << "#;@83*";
            } 
            else 
            if(message[i] == 'w') 
            {
                mhistory += "#$*91)";
                cout << "#$*91)";
            } 
            else 
            if(message[i] == 'x') 
            {
                mhistory += "!#%92*";
                cout << "!#%92*";
            } 
            else 
            if(message[i] == 'y') 
            {
                mhistory += "*$^93%";
                cout << "*$^93%";
            } 
            else 
            if(message[i] == 'z') 
            {
                mhistory += "#^*94$";
                cout << "#^*94$";
            }   
            // Symbol   
            else if(message[i] == '~')
            {
                mhistory += "@!#02!";
                cout<<"@!#02!";
            }
            else if(message[i] == '`')
            {
                mhistory += "@!#04!";
                cout<<"@!#04!";
            }
            else if(message[i] == '!')
            {
                mhistory += "@!#06!" ;
                cout<<"@!#06!";
            }
            else if(message[i] == '@')
            {
                mhistory += "@!#08!" ;
                cout<<"@!#08!";
            }
            else if(message[i] == '#')
            {
                mhistory += "@!~10!";
                cout<<"@!~10!";
            }
            else if(message[i] == '$')
            {
                mhistory += "@!~12!" ;
                cout<<"@!~12!";
            }
            else if(message[i] == '%')
            {
                mhistory += "@!~14!";
                cout<<"@!~14!";
            }
            else if(message[i] == '^')
            {
                mhistory += "@!~62!" ;
                cout<<"@!~62!";
            }
            else if(message[i] == '&')
            {
                mhistory += "@!~64!" ;
                cout<<"@!~64!";
            }
            else if(message[i] == '*')
            {
                mhistory += "@!~68!" ;
                cout<<"@!~68!";
            }
            else if(message[i] == '(')
            {
                mhistory += "@!~61!";
                cout<<"@!~61!";
            }
            else if(message[i] == ')')
            {
                mhistory += "@!~65!";
                cout<<"@!~65!";
            }
            else if(message[i] == '-')
            {
                mhistory += "@!@45," ;
                cout<<"@!@45,";
            }
            else if(message[i] == '_')
            {
                mhistory += "@!@46,";
                cout<<"@!@46,";
            }
            else if(message[i] == '=')
            {
                mhistory += "@!@47," ;
                cout<<"@!@47,";
            }
            else if(message[i] == '+')
            {
                mhistory += "@!*45,";
                cout<<"@!*45,";
            }
            else if(message[i] == '{')
            {
                mhistory += "@!@45?" ;
                cout<<"@!@45?";
            }
            else if(message[i] == '[')
            {
                mhistory += "@!@47?";
                cout<<"@!@47?";
            }
            else if(message[i] == '}')
            {
                mhistory += "@!@45*";
                cout<<"@!@45*";
            }
            else if(message[i] == ']')
            {
                mhistory += "@*@45?";
                cout<<"@*@45?";
            }
            else if(message[i] == '|')
            {
                mhistory += "@!^45?";
                cout<<"@!^45?";
            }
            else if(message[i] == '\\')
            {
                mhistory += "*#?78/";
                cout<<"*#?78/";
            }
            else if(message[i] == ':')
            {
                mhistory += "@!@41+";
                cout<<"@!@41+";
            }
            else if(message[i] == ';')
            {
                mhistory += "*!@45?";
                cout<<"*!@45?";
            }
            else if(message[i] == '"')
            {
                mhistory += "*#@40?";
                cout<<"*#@40?";
            }
            else if(message[i] == '\'')
            {
                mhistory += "*#@19?";
                cout<<"*#@19?";
            }
            else if(message[i] == ',')
            {
                mhistory += "*$%40?";
                cout<<"*$%40?";
            }
            else if(message[i] == '<')
            {
                mhistory += "*#@78?";
                cout<<"*#@78?";
            }
            else if(message[i] == '>')
            {
                mhistory += "*#?78#";
                cout<<"*#?78#";
            }
            else if(message[i] == '.')
            {
                mhistory += "-#@40?";
                cout<<"-#@40?";
            }
            else if(message[i] == '?')
            {
                mhistory += "*#@41?";
                cout<<"*#@41?";
            }
            else if(message[i] == '/')
            {
                mhistory += "*#@69?";
                cout<<"*#@69?";
            }
            else
            {
            cout<<endl<<endl<<message[i];
            }
            if(i < 1 && i > 2 )
            {
                mhistory += salt1+salt3;
                cout<<salt1<<salt3;

            }
            else if(i > 1 && i < 2)
            {
                mhistory += salt2+salt4;
                cout<<salt2<<salt4;
            }
            else 
            {
                mhistory += salt3+salt4;
                cout<<salt3<<salt4;
            }

        }
        if(cho == '2')
        {
        cout<<"#7"<<add_pass[0]<<"$&"<<"!3"<<add_pass[1]<<"*%"<<"&8"<<add_pass[2]<<"@#"<<"%6"<<add_pass[3]<<"*?";
        }

        if(cho == '1')
        {
        ofstream messagefile;
        messagefile.open("MessageHistory.txt",ios::app);
        mhistory += "\n\n";
        messagefile<<mhistory;
        messagefile.close();
        }
        
    }
void decrypt(int strlength)
       {
        
        int i = 0,a = 0;

        cout<<"\n\033[0;33mYour Decrypted Message:\033[0m\n";
        while (i < strlength) 
        { 
        // #$21!&
        if (message[i] == '#' && message[i + 1] == '$' && message[i + 2] == '2' && message[i + 3] == '1' && message[i + 4] == '!' && message[i + 5] == '&') {
            i+=6;
        }

        // Check for the specific pattern ~!#25*&
        if (message[i] == '$' && message[i + 1] == '!' && message[i + 2] == '#' && message[i + 3] == '2' && message[i + 4] == '5' && message[i + 5] == '*' && message[i + 6] == '&') {
            i+=7;
        }
        else if (message[i] == '&') {
            if (message[i + 1] == '!' && message[i + 2] == '*' && message[i + 3] == '3' && message[i + 4] == '*' && message[i+5] == '!') {
                if(passmessagechk == 0){
                    dhistory+=" ";
                }
                cout << ' '; 
                i += 6;
            } 
        } 
        // Salt ignore code
        // salt1
        else if (message[i] == '%' && message[i + 1] == '^' && message[i + 2] == '&' && message[i + 3] == '7' &&message[i + 4] == '8' && message[i + 5] == '!' && message[i + 6] == '~' && message[i + 7] == '.') {
                    i += 8;   
        }
        // salt2 !~$%34*^`
        else if (message[i] == '!' && message[i + 1] == '~' && message[i + 2] == '$' && message[i + 3] == '%' && message[i + 4] == '3' && message[i + 5] == '4' && message[i + 6] == '*' && message[i + 7] == '^' && message[i + 8] == '`') {
                    i += 9;
        }
        // salt3 ~!^&89!*
        else if (message[i] == '~' && message[i + 1] == '!' && message[i + 2] == '^' && message[i + 3] == '&' &&message[i + 4] == '8' && message[i + 5] == '9' && message[i + 6] == '!' && message[i + 7] == '*'){               
                    i += 8;  
        }
        // salt 4 !@#&*^%$~7
        else if (message[i] == '!' && message[i + 1] == '@' && message[i + 2] == '#' && message[i + 3] == '&' &&message[i + 4] == '*' && message[i + 5] == '^' && message[i + 6] == '%' && message[i + 7] == '$' && message[i + 8] == '~' && message[i+9] == '7') {
                i += 10;
        }
        // salt 5 (*&^%$#@!~5
        else if (message[i] == '*' && message[i + 1] == '&' && message[i + 2] == '^' && message[i + 3] == '%' &&message[i + 4] == '$' && message[i + 5] == '#' && message[i + 6] == '@' && message[i + 7] == '!' && message[i + 8] == '~' && message[i+9] == '5') {
                i += 10;
        }
        // salt 6 !~&$%^*#!2
        else if (message[i] == '!' && message[i + 1] == '~' && message[i + 2] == '&' && message[i + 3] == '$' &&message[i + 4] == '%' && message[i + 5] == '^' && message[i + 6] == '*' && message[i + 7] == '#' && message[i + 8] == '!' && message[i+9] == '2') {
                i += 10;
        }
        // salt 7 #$%~*!^&1
        else if (message[i] == '#' && message[i + 1] == '$' && message[i + 2] == '%' && message[i + 3] == '~' &&message[i + 4] == '*' && message[i + 5] == '!' && message[i + 6] == '^' && message[i + 7] == '&' && message[i + 8] == '1') {
                i += 9;
        }
        // upper case decryption
        else if (message[i] == '#' && message[i + 1] == '@' && message[i + 2] == '^' && message[i + 3] == '2' && message[i + 4] == '1' && message[i + 5] == '@') {
                if(passmessagechk == 0){
                    dhistory+="A";
                }
            cout << 'A';
            i += 6;
        } 
        else if (message[i] == '@' && message[i + 1] == '&' && message[i + 2] == '^' && message[i + 3] == '2' && message[i + 4] == '2' && message[i + 5] == '$') {
            cout << 'B';
                if(passmessagechk == 0){
                    dhistory+="B";
                }
            i += 6; 
        } 
        else if (message[i] == '!' && message[i + 1] == '@' && message[i + 2] == '$' && message[i + 3] == '2' && message[i + 4] == '3' && message[i + 5] == '^') {
            cout << 'C';
                if(passmessagechk == 0){
                    dhistory+="C";
                }
            i += 6;
        } 
        else if (message[i] == ')' && message[i + 1] == '!' && message[i + 2] == '$' && message[i + 3] == '3' && message[i + 4] == '1' && message[i + 5] == '-') {
            cout << 'D'; 
                if(passmessagechk == 0){
                    dhistory+="D";
                }
            i += 6;
        } 
        else if (message[i] == '~' && message[i + 1] == '/' && message[i + 2] == '%' && message[i + 3] == '3' && message[i + 4] == '2' && message[i + 5] == '!') {
            cout << 'E'; 
                if(passmessagechk == 0){
                    dhistory+="E";
                }
            i += 6;
        } 
        else if (message[i] == '=' && message[i + 1] == '!' && message[i + 2] == '#' && message[i + 3] == '3' && message[i + 4] == '3' && message[i + 5] == '#') {
            cout << 'F'; 
                if(passmessagechk == 0){
                    dhistory+="F";
                }
            i += 6;
        } 
        else if (message[i] == '?' && message[i + 1] == '!' && message[i + 2] == '@' && message[i + 3] == '4' && message[i + 4] == '1' && message[i + 5] == '%') {
            cout << 'G'; 
                if(passmessagechk == 0){
                    dhistory+="G";
                }
            i += 6;
        } 
        else if (message[i] == '^' && message[i + 1] == '@' && message[i + 2] == ',' && message[i + 3] == '4' && message[i + 4] == '2' && message[i + 5] == '&') {
            cout << 'H'; 
                if(passmessagechk == 0){
                    dhistory+="H";
                }
            i += 6;
        } 
        else if (message[i] == '{' && message[i + 1] == '/' && message[i + 2] == '!' && message[i + 3] == '4' && message[i + 4] == '3' && message[i + 5] == '&') {
            cout << 'I'; 
                if(passmessagechk == 0){
                    dhistory+="I";
                }
            i += 6;
        } 
        else if (message[i] == '.' && message[i + 1] == '`' && message[i + 2] == '$' && message[i + 3] == '5' && message[i + 4] == '1' && message[i + 5] == '@') {
            cout << 'J'; 
                if(passmessagechk == 0){
                    dhistory+="J";
                }
            i += 6;
        } 
        else if (message[i] == '-' && message[i + 1] == '{' && message[i + 2] == ',' && message[i + 3] == '5' && message[i + 4] == '2' && message[i + 5] == '~') {
            cout << 'K'; 
                if(passmessagechk == 0){
                    dhistory+="K";
                }
            i += 6;
        }  
        else if (message[i] == '#' && message[i + 1] == 'x' && message[i + 2] == ':' && message[i + 3] == '5' && message[i + 4] == '3' && message[i + 5] == '`') {
            cout << 'L'; 
                if(passmessagechk == 0){
                    dhistory+="L";
                }
            i += 6;
        }   
        else if (message[i] == '<' && message[i + 1] == '!' && message[i + 2] == '~' && message[i + 3] == '6' && message[i + 4] == '1' && message[i + 5] == '/') {
            cout << 'M'; 
                if(passmessagechk == 0){
                    dhistory+="M";
                }
            i += 6;
        }   
        else if (message[i] == '<' && message[i + 1] == '?' && message[i + 2] == '-' && message[i + 3] == '6' && message[i + 4] == '2' && message[i + 5] == '_') {
            cout << 'N'; 
                if(passmessagechk == 0){
                    dhistory+="N";
                }
            i += 6;
        }   
        else if (message[i] == '!' && message[i + 1] == '`' && message[i + 2] == '~' && message[i + 3] == '6' && message[i + 4] == '3' && message[i + 5] == '-') { 
            cout << 'O'; 
                if(passmessagechk == 0){
                    dhistory+="O";
                }
            i += 6;
        }   
        else if (message[i] == '#' && message[i + 1] == '&' && message[i + 2] == '^' && message[i + 3] == '7' && message[i + 4] == '1' && message[i + 5] == '/') { 
            cout << 'P'; 
                if(passmessagechk == 0){
                    dhistory+="P";
                }
            i += 6;
        }   
        else if (message[i] == '-' && message[i + 1] == '%' && message[i + 2] == '^' && message[i + 3] == '7' && message[i + 4] == '2' && message[i + 5] == '!') {
            cout << 'Q'; 
                if(passmessagechk == 0){
                    dhistory+="Q";
                }
            i += 6;
        }     
        else if (message[i] == '`' && message[i + 1] == '~' && message[i + 2] == '/' && message[i + 3] == '7' && message[i + 4] == '3' && message[i + 5] == '^') {
            cout << 'R'; 
                if(passmessagechk == 0){
                    dhistory+="R";
                }
            i += 6;
        }   
        else if (message[i] == '{' && message[i + 1] == '>' && message[i + 2] == '#' && message[i + 3] == '7' && message[i + 4] == '4' && message[i + 5] == '`') {
            cout << 'S'; 
                if(passmessagechk == 0){
                    dhistory+="S";
                }
            i += 6;
        }   
        else if (message[i] == '<' && message[i + 1] == '?' && message[i + 2] == '=' && message[i + 3] == '8' && message[i + 4] == '1' && message[i + 5] == '-') {
            cout << 'T'; 
                if(passmessagechk == 0){
                    dhistory+="T";
                }
            i += 6;
        }   
        else if (message[i] == '!' && message[i + 1] == '@' && message[i + 2] == '/' && message[i + 3] == '8' && message[i + 4] == '2' && message[i + 5] == '+') {
            cout << 'U'; 
                if(passmessagechk == 0){
                    dhistory+="U";
                }
            i += 6;
        }   
        else if (message[i] == '#' && message[i + 1] == ';' && message[i + 2] == '@' && message[i + 3] == '8' && message[i + 4] == '3' && message[i + 5] == ')') {
            cout << 'V'; 
                if(passmessagechk == 0){
                    dhistory+="V";
                }
            i += 6;
        }   
        else if (message[i] == '#' && message[i + 1] == '$' && message[i + 2] == '^' && message[i + 3] == '9' && message[i + 4] == '1' && message[i + 5] == ')') {
            cout << 'W'; 
                if(passmessagechk == 0){
                    dhistory+="W";
                }
            i += 6;
        }   
        else if (message[i] == '!' && message[i + 1] == '#' && message[i + 2] == '%' && message[i + 3] == '9' && message[i + 4] == '2' && message[i + 5] == '^') {
            cout << 'X'; 
                if(passmessagechk == 0){
                    dhistory+="X";
                }
            i += 6;
        }   
        else if (message[i] == '@' && message[i + 1] == '$' && message[i + 2] == '^' && message[i + 3] == '9' && message[i + 4] == '3' && message[i + 5] == '%') {
            cout << 'Y'; 
                if(passmessagechk == 0){
                    dhistory+="Y";
                }
            i += 6;
        }  
        else if (message[i] == '#' && message[i + 1] == '^' && message[i + 2] == '(' && message[i + 3] == '9' && message[i + 4] == '4' && message[i + 5] == '$') {
            cout << 'Z';  
                if(passmessagechk == 0){
                    dhistory+="Z";
                }
            i += 6;
        }   
        // Number Decryption Starting from here
        else if (message[i] == '#' && message[i + 1] == '@' && message[i + 2] == '^' && message[i + 3] == '1' && message[i + 4] == '0' && message[i + 5] == '@') {
            cout << '0'; 
            if(passmessagechk == 0){
            dhistory+="0";
            }
            i += 6;
        }  
        else if (message[i] == '#' && message[i + 1] == '@' && message[i + 2] == '^' && message[i + 3] == '2' && message[i + 4] == '1' && message[i + 5] == '~') {
            cout << '1';
            if(passmessagechk == 0){
            dhistory+="1";
            } 
            i += 6;
        }  
        else if (message[i] == '$' && message[i + 1] == '@' && message[i + 2] == '^' && message[i + 3] == '4' && message[i + 4] == '2' && message[i + 5] == '~') {
            cout << '2'; 
            if(passmessagechk == 0){
            dhistory+="2";
            }
            i += 6;
        }  
        else if (message[i] == '#' && message[i + 1] == '@' && message[i + 2] == '^' && message[i + 3] == '6' && message[i + 4] == '3' && message[i + 5] == '@') {
            cout << '3';
            if(passmessagechk == 0){
            dhistory+="3";
            } 
            i += 6;
        }  
        else if (message[i] == '#' && message[i + 1] == '@' && message[i + 2] == '^' && message[i + 3] == '-' && message[i + 4] == '8' && message[i + 5] == '4') {
            cout << '4'; 
            if(passmessagechk == 0){
            dhistory+="4";
            }
            i += 6;
        }  
        else if (message[i] == '#' && message[i + 1] == '*' && message[i + 2] == '^' && message[i + 3] == '1' && message[i + 4] == '6' && message[i + 5] == '~') {
            cout << '5';
            if(passmessagechk == 0){
            dhistory+="5";
            } 
            i += 6;
        }  
        else if (message[i] == '#' && message[i + 1] == '@' && message[i + 2] == '^' && message[i + 3] == '2' && message[i + 4] == '8' && message[i + 5] == '~') {
            cout << '6'; 
            if(passmessagechk == 0){
            dhistory+="6";
            }
            i += 6;
        }  
        else if (message[i] == '#' && message[i + 1] == '@' && message[i + 2] == '`' && message[i + 3] == '2' && message[i + 4] == '5' && message[i + 5] == '~') {
            cout << '7'; 
            if(passmessagechk == 0){
            dhistory+="7";
            }
            i += 6;
        }  
        else if (message[i] == '#' && message[i + 1] == '@' && message[i + 2] == '^' && message[i + 3] == '1' && message[i + 4] == '7' && message[i + 5] == '~') {
            cout << '8'; 
            if(passmessagechk == 0){
            dhistory+="8";
            }
            i += 6;
        }  
        else if (message[i] == '#' && message[i + 1] == '@' && message[i + 2] == '^' && message[i + 3] == '9' && message[i + 4] == '9' && message[i + 5] == '~') {
            cout << '9'; 
            if(passmessagechk == 0){
            dhistory+="9";
            }
            i += 6;
        }

        // lower case decryption
        else if (message[i] == '#' && message[i + 1] == '@' && message[i + 2] == '*' && message[i + 3] == '2' && message[i + 4] == '1' && message[i + 5] == '@') {
            cout << 'a';
            if(passmessagechk == 0){
            dhistory+="a";
            }
            i += 6;
        } 
        else if (message[i] == '@' && message[i + 1] == '&' && message[i + 2] == '^' && message[i + 3] == '2' && message[i + 4] == '2' && message[i + 5] == '*') {
            cout << 'b';
            if(passmessagechk == 0){
            dhistory+="b";
            }
            i += 6; 
        } 
        else if (message[i] == '*' && message[i + 1] == '@' && message[i + 2] == '$' && message[i + 3] == '2' && message[i + 4] == '3' && message[i + 5] == '^') {
            cout << 'c';
            if(passmessagechk == 0){
            dhistory+="c";
            }
            i += 6;
        } 
        else if (message[i] == ')' && message[i + 1] == '!' && message[i + 2] == '*' && message[i + 3] == '3' && message[i + 4] == '1' && message[i + 5] == '-') {
            cout << 'd'; 
            if(passmessagechk == 0){
            dhistory+="d";
            }
            i += 6;
        } 
        else if (message[i] == '~' && message[i + 1] == '/' && message[i + 2] == '%' && message[i + 3] == '3' && message[i + 4] == '2' && message[i + 5] == '*') {
            cout << 'e'; 
            if(passmessagechk == 0){
            dhistory+="e";
            }
            i += 6;
        } 
        else if (message[i] == '*' && message[i + 1] == '!' && message[i + 2] == '#' && message[i + 3] == '3' && message[i + 4] == '3' && message[i + 5] == '#') {
            cout << 'f'; 
            if(passmessagechk == 0){
            dhistory+="f";
            }
            i += 6;
        } 
        else if (message[i] == '?' && message[i + 1] == '!' && message[i + 2] == '@' && message[i + 3] == '4' && message[i + 4] == '1' && message[i + 5] == '*') {
            cout << 'g'; 
            if(passmessagechk == 0){
            dhistory+="g";
            }
            i += 6;
        } 
        else if (message[i] == '^' && message[i + 1] == '@' && message[i + 2] == '*' && message[i + 3] == '4' && message[i + 4] == '2' && message[i + 5] == '&') {
            cout << 'h';
            if(passmessagechk == 0){
            dhistory+="h";
            }
            i += 6;
        } 
        else if (message[i] == '*' && message[i + 1] == '/' && message[i + 2] == '!' && message[i + 3] == '4' && message[i + 4] == '3' && message[i + 5] == '&') {
            cout << 'i';
            if(passmessagechk == 0){
            dhistory+="i";
            } 
            i += 6;
        } 
        else if (message[i] == '*' && message[i + 1] == '`' && message[i + 2] == '$' && message[i + 3] == '5' && message[i + 4] == '1' && message[i + 5] == '@') {
            cout << 'j'; 
            if(passmessagechk == 0){
            dhistory+="j";
            }
            i += 6;
        } 
        else if (message[i] == '-' && message[i + 1] == '*' && message[i + 2] == ',' && message[i + 3] == '5' && message[i + 4] == '2' && message[i + 5] == '~') {
            cout << 'k'; 
            if(passmessagechk == 0){
            dhistory+="k";
            }
            i += 6;
        }  
        else if (message[i] == '#' && message[i + 1] == '*' && message[i + 2] == ':' && message[i + 3] == '5' && message[i + 4] == '3' && message[i + 5] == '`') {
            cout << 'l';
            if(passmessagechk == 0){
            dhistory+="l";
            } 
            i += 6;
        }   
        else if (message[i] == '*' && message[i + 1] == '!' && message[i + 2] == '~' && message[i + 3] == '6' && message[i + 4] == '1' && message[i + 5] == '/') {
            cout << 'm'; 
            if(passmessagechk == 0){
            dhistory+="m";
            }
            i += 6;
        }   
        else if (message[i] == '<' && message[i + 1] == '?' && message[i + 2] == '*' && message[i + 3] == '6' && message[i + 4] == '2' && message[i + 5] == '_') {
            cout << 'n'; 
            if(passmessagechk == 0){
            dhistory+="n";
            }
            i += 6;
        }   
        else if (message[i] == '!' && message[i + 1] == '~' && message[i + 2] == '*' && message[i + 3] == '6' && message[i + 4] == '3' && message[i + 5] == '~') { 
            cout << 'o'; 
            if(passmessagechk == 0){
            dhistory+="o";
            } 
            i += 6;
        }   
        else if (message[i] == '#' && message[i + 1] == '&' && message[i + 2] == '*' && message[i + 3] == '7' && message[i + 4] == '1' && message[i + 5] == '/') { 
            cout << 'p'; 
            if(passmessagechk == 0){
            dhistory+="p";
            }
            i += 6;
        }   
        else if (message[i] == '*' && message[i + 1] == '%' && message[i + 2] == '^' && message[i + 3] == '7' && message[i + 4] == '2' && message[i + 5] == '!') {
            cout << 'q';
            if(passmessagechk == 0){
            dhistory+="q";
            } 
            i += 6;
        }     
        else if (message[i] == '*' && message[i + 1] == '~' && message[i + 2] == '/' && message[i + 3] == '7' && message[i + 4] == '3' && message[i + 5] == '^') {
            cout << 'r';
            if(passmessagechk == 0){
            dhistory+="r";
            } 
            i += 6;
        }   
        else if (message[i] == '*' && message[i + 1] == '>' && message[i + 2] == '#' && message[i + 3] == '7' && message[i + 4] == '4' && message[i + 5] == '`') {
            cout << 's';
            if(passmessagechk == 0){
            dhistory+="s";
            } 
            i += 6;
        }   
        else if (message[i] == '<' && message[i + 1] == '?' && message[i + 2] == '`' && message[i + 3] == '8' && message[i + 4] == '1' && message[i + 5] == '*') {
            cout << 't'; 
            if(passmessagechk == 0){
            dhistory+="t";
            }
            i += 6;
        }   
        else if (message[i] == '!' && message[i + 1] == '@' && message[i + 2] == '/' && message[i + 3] == '8' && message[i + 4] == '2' && message[i + 5] == '*') {
            cout << 'u'; 
            if(passmessagechk == 0){
            dhistory+="u";
            }
            i += 6;
        }   
        else if (message[i] == '#' && message[i + 1] == ';' && message[i + 2] == '@' && message[i + 3] == '8' && message[i + 4] == '3' && message[i + 5] == '*') {
            cout << 'v'; 
            if(passmessagechk == 0){
            dhistory+="v";
            }
            i += 6;
        }   
        else if (message[i] == '#' && message[i + 1] == '$' && message[i + 2] == '*' && message[i + 3] == '9' && message[i + 4] == '1' && message[i + 5] == ')') {
            cout << 'w'; 
            if(passmessagechk == 0){
            dhistory+="w";
            }
            i += 6;
        }   
        else if (message[i] == '!' && message[i + 1] == '#' && message[i + 2] == '%' && message[i + 3] == '9' && message[i + 4] == '2' && message[i + 5] == '*') {
            cout << 'x'; 
            if(passmessagechk == 0){
            dhistory+="x";
            }
            i += 6;
        }   
        else if (message[i] == '*' && message[i + 1] == '$' && message[i + 2] == '^' && message[i + 3] == '9' && message[i + 4] == '3' && message[i + 5] == '%') {
            cout << 'y'; 
            if(passmessagechk == 0){
            dhistory+="y";
            }
            i += 6;
        }  
        else if (message[i] == '#' && message[i + 1] == '^' && message[i + 2] == '*' && message[i + 3] == '9' && message[i + 4] == '4' && message[i + 5] == '$') {
            cout << 'z'; 
            if(passmessagechk == 0){
            dhistory+="z";
            }
            i += 6;
        }
        // Symbol 
        else if (message[i] == '@' && message[i + 1] == '!' && message[i + 2] == '#' && message[i + 3] == '0' && message[i + 4] == '2' && message[i + 5] == '!') {
            cout << '~'; 
            if(passmessagechk == 0){
            dhistory+="~";
            }
            i += 6;
        }
        else if (message[i] == '@' && message[i + 1] == '!' && message[i + 2] == '#' && message[i + 3] == '0' && message[i + 4] == '4' && message[i + 5] == '!') {
            cout << '`'; 
            if(passmessagechk == 0){
            dhistory+="`";
            }
            i += 6;
        }
        else if (message[i] == '@' && message[i + 1] == '!' && message[i + 2] == '#' && message[i + 3] == '0' && message[i + 4] == '6' && message[i + 5] == '!') {
            cout << '!'; 
            if(passmessagechk == 0){
            dhistory+="!";
            }
            i += 6;
        }
        else if (message[i] == '@' && message[i + 1] == '!' && message[i + 2] == '#' && message[i + 3] == '0' && message[i + 4] == '8' && message[i + 5] == '!') {
            cout << '@'; 
            if(passmessagechk == 0){
            dhistory+="@";
            }
            i += 6;
        }
        else if (message[i] == '@' && message[i + 1] == '!' && message[i + 2] == '~' && message[i + 3] == '1' && message[i + 4] == '0' && message[i + 5] == '!') {
            cout << '#'; 
            if(passmessagechk == 0){
            dhistory+="#";
            }
            i += 6;
        }
        else if (message[i] == '@' && message[i + 1] == '!' && message[i + 2] == '~' && message[i + 3] == '1' && message[i + 4] == '2' && message[i + 5] == '!') {
            cout << '$';
            if(passmessagechk == 0){
            dhistory+="$";
            } 
            i += 6;
        }
        else if (message[i] == '@' && message[i + 1] == '!' && message[i + 2] == '~' && message[i + 3] == '1' && message[i + 4] == '4' && message[i + 5] == '!') {
            cout << '%';
            if(passmessagechk == 0){
            dhistory+="%";
            } 
            i += 6;
        }
        else if (message[i] == '@' && message[i + 1] == '!' && message[i + 2] == '~' && message[i + 3] == '6' && message[i + 4] == '2' && message[i + 5] == '!') {
            cout << '^'; 
            if(passmessagechk == 0){
            dhistory+="^";
            }
            i += 6;
        }
        else if (message[i] == '@' && message[i + 1] == '!' && message[i + 2] == '~' && message[i + 3] == '6' && message[i + 4] == '4' && message[i + 5] == '!') {
            cout << '&'; 
            if(passmessagechk == 0){
            dhistory+="&";
            }
            i += 6;
        }
        else if (message[i] == '@' && message[i + 1] == '!' && message[i + 2] == '~' && message[i + 3] == '6' && message[i + 4] == '8' && message[i + 5] == '!') {
            cout << '*';
            if(passmessagechk == 0){
            dhistory+="*";
            } 
            i += 6;
        }
        else if (message[i] == '@' && message[i + 1] == '!' && message[i + 2] == '~' && message[i + 3] == '6' && message[i + 4] == '1' && message[i + 5] == '!') {
            cout << '('; 
            if(passmessagechk == 0){
            dhistory+="(";
            }
            i += 6;
        }
        else if (message[i] == '@' && message[i + 1] == '!' && message[i + 2] == '~' && message[i + 3] == '6' && message[i + 4] == '5' && message[i + 5] == '!') {
            cout << ')';
            if(passmessagechk == 0){
            dhistory+=")";
            } 
            i += 6;
        }
        else if (message[i] == '@' && message[i + 1] == '!' && message[i + 2] == '@' && message[i + 3] == '4' && message[i + 4] == '5' && message[i + 5] == ',') {
            cout << '-'; 
            if(passmessagechk == 0){
            dhistory+="-";
            }
            i += 6;
        }
        else if (message[i] == '@' && message[i + 1] == '!' && message[i + 2] == '@' && message[i + 3] == '4' && message[i + 4] == '6' && message[i + 5] == ',') {
            cout << '_'; 
            if(passmessagechk == 0){
            dhistory+="_";
            }
            i += 6;
        }
        else if (message[i] == '@' && message[i + 1] == '!' && message[i + 2] == '@' && message[i + 3] == '4' && message[i + 4] == '7' && message[i + 5] == ',') {
            cout << '='; 
            if(passmessagechk == 0){
            dhistory+="=";
            }
            i += 6;
        }
        else if (message[i] == '@' && message[i + 1] == '!' && message[i + 2] == '*' && message[i + 3] == '4' && message[i + 4] == '5' && message[i + 5] == ',') {
            cout << '+'; 
            if(passmessagechk == 0){
            dhistory+="+";
            }
            i += 6;
        }
        else if (message[i] == '@' && message[i + 1] == '!' && message[i + 2] == '@' && message[i + 3] == '4' && message[i + 4] == '5' && message[i + 5] == '?') {
            cout << '{'; 
            if(passmessagechk == 0){
            dhistory+="{";
            }
            i += 6;
        }
        else if (message[i] == '@' && message[i + 1] == '!' && message[i + 2] == '@' && message[i + 3] == '4' && message[i + 4] == '7' && message[i + 5] == '?') {
            cout << '['; 
            if(passmessagechk == 0){
            dhistory+="[";
            }
            i += 6;
        }
        else if (message[i] == '@' && message[i + 1] == '!' && message[i + 2] == '@' && message[i + 3] == '4' && message[i + 4] == '5' && message[i + 5] == '*') {
            cout << '}'; 
            if(passmessagechk == 0){
            dhistory+="}";
            }
            i += 6;
        }
        else if (message[i] == '@' && message[i + 1] == '*' && message[i + 2] == '@' && message[i + 3] == '4' && message[i + 4] == '5' && message[i + 5] == '?') {
            cout << ']';
            if(passmessagechk == 0){
            dhistory+="]";
            } 
            i += 6;
        }
        else if (message[i] == '@' && message[i + 1] == '!' && message[i + 2] == '^' && message[i + 3] == '4' && message[i + 4] == '5' && message[i + 5] == '?') {
            cout << '|';
            if(passmessagechk == 0){
            dhistory+="|";
            } 
            i += 6;
        }
        else if (message[i] == '*' && message[i + 1] == '#' && message[i + 2] == '?' && message[i + 3] == '7' && message[i + 4] == '8' && message[i + 5] == '/') {
            cout << '\\'; 
            if(passmessagechk == 0){
            dhistory+="\\";
            }
            i += 6;
        }
        else if (message[i] == '@' && message[i + 1] == '!' && message[i + 2] == '@' && message[i + 3] == '4' && message[i + 4] == '1' && message[i + 5] == '+') {
            cout << ':'; 
            if(passmessagechk == 0){
            dhistory+=":";
            }
            i += 6;
        }
        else if (message[i] == '*' && message[i + 1] == '#' && message[i + 2] == '@' && message[i + 3] == '4' && message[i + 4] == '0' && message[i + 5] == '?') {
            cout << '"';
            if(passmessagechk == 0){
            dhistory+='"';
            } 
            i += 6;
        }
        else if (message[i] == '*' && message[i + 1] == '!' && message[i + 2] == '@' && message[i + 3] == '4' && message[i + 4] == '5' && message[i + 5] == '?') {
            cout << ';'; 
            if(passmessagechk == 0){
            dhistory+=";";
            }
            i += 6;
        }
        else if (message[i] == '*' && message[i + 1] == '$' && message[i + 2] == '%' && message[i + 3] == '4' && message[i + 4] == '0' && message[i + 5] == '?') {
            cout << ','; 
            if(passmessagechk == 0){
            dhistory+=",";
            }
            i += 6;
        }
        else if (message[i] == '*' && message[i + 1] == '#' && message[i + 2] == '@' && message[i + 3] == '1' && message[i + 4] == '9' && message[i + 5] == '?') {
            cout << '\'';
            if(passmessagechk == 0){
            dhistory+="\'";
            } 
            i += 6;
        }
        else if (message[i] == '*' && message[i + 1] == '#' && message[i + 2] == '@' && message[i + 3] == '7' && message[i + 4] == '8' && message[i + 5] == '?') {
            cout << '<'; 
            if(passmessagechk == 0){
            dhistory+="<";
            }
            i += 6;
        }
        else if (message[i] == '*' && message[i + 1] == '#' && message[i + 2] == '?' && message[i + 3] == '7' && message[i + 4] == '8' && message[i + 5] == '#') {
            cout << '>'; 
            if(passmessagechk == 0){
            dhistory+=">";
            }
            i += 6;
        }
        else if (message[i] == '*' && message[i + 1] == '#' && message[i + 2] == '@' && message[i + 3] == '6' && message[i + 4] == '9' && message[i + 5] == '?') {
            cout << '/'; 
            if(passmessagechk == 0){
            dhistory+="/";
            }
            i += 6;
        }
        else if (message[i] == '-' && message[i + 1] == '#' && message[i + 2] == '@' && message[i + 3] == '4' && message[i + 4] == '0' && message[i + 5] == '?') {
            cout << '.'; 
            if(passmessagechk == 0){
            dhistory+=".";
            }
            i += 6;
        }
        else if (message[i] == '*' && message[i + 1] == '#' && message[i + 2] == '@' && message[i + 3] == '4' && message[i + 4] == '1' && message[i + 5] == '?') {
            cout << '?'; 
            if(passmessagechk == 0){
            dhistory+="?";
            }
            i += 6;
        }

        else {
            cout<<message[i]<<message[i+1]<<message[i+2]<<message[i+3]<<message[i+4]<<message[i+5];
            i+=6;
            a++;
        }
        if(a >= 1){
        cout << "\x1B[31m";//Red color code
        cout << "\n";
        cout << "-----------------------------------------\n";
        cout << "|                ERROR                  |\n";
        cout << "-----------------------------------------\n";
        cout << "We have encountered an issue with your encrypted message:\n";
        cout << "Unfortunately, we found some invalid characters that do not exist in our database.\n";
        cout << "We apologize for the inconvenience and are actively working to resolve this.\n";
        cout << "Thank you for your understanding.";
        cout << "\x1B[0m"; // default color code
        a = 0;
        }
        }

        ofstream dfile;
        dfile.open("DMessageHistory.txt",ios::app);
        dfile << dhistory;
        dfile.close();
    }

void login() {
    int ax = 0,chklength;
    char ch;

    chkpass.clear();
    passwordbyuser.clear();
        fflush(stdin);
        cout << "Enter Your 6 Digit Pin: ";
    while (true) {
        ch = getch();
        if (ch == 13) {
            break;
        } else if (ch == 8) { 
            if (!chkpass.empty()) {
                chkpass.pop_back(); 
                cout << "\b \b"; 
            }
        } else {
            chkpass += ch;
            cout << '*'; 
        }

    }
        // getline(cin, chkpass);
        chklength = chkpass.length();
        fflush(stdin);

        if (chklength == 6) {
            EncryptPassword();
            if(ax == 0){
            account();
            }

            if (passwordbyuser == passwordFromFile) {
                ::advcounter++;
                fflush(stdin);
                advopt();
            }
            else
            {
                 system("cls");
        chkpass.clear();
        passwordbyuser.clear();
        cout << "\x1B[31mIncorrect Password\n\x1B[0m";
        fflush(stdin);
        codemessage();
            }
        }
        else{
        system("cls");
        chkpass.clear();
        passwordbyuser.clear();
        cout << "\x1B[31mIncorrect Password\n\x1B[0m";
        fflush(stdin);
        codemessage();
        }
}
    void EncryptPassword()
    {
        for (int i = 0; i < 6; i++)
        {
            passwordbyuser += passwordhast1 + chkpass[i] + "14047147019" + passwordhast2;
        }
    }
    void account()
    {
        passwordFromFile.clear();
        string onlypasswordFromFile;
        onlypasswordFromFile.clear();
        ifstream openandcheck;
        openandcheck.open("login_detail.txt");
        if(openandcheck.fail())
        {
            cout << "\x1B[31m";
            cout<<"Error!! While Opening File!!";
            cout << "\x1B[0m";
            exit(0);
        }
        getline(openandcheck, onlypasswordFromFile);
        for(int i = 0 ; i < 144 ; i++)
        {
            passwordFromFile += onlypasswordFromFile[i];
        }
        openandcheck.close();
        az++;
    }
    void advopt()
    {
        string conti;
        char advcho,ch;
        int passwordlength;
        system("cls");
        fflush(stdin);
        cout<<"-------------------------------------------"<<endl;
        cout<<"|         Welcome to Advance Option       |"<<endl;
        cout<<"-------------------------------------------"<<endl;
        fflush(stdin);
        cout<<"\033[0;33m\033[1m\033[4mSelect Your Preference\n\033[0;34m1.Encryption and Decryption History\n\033[0;35m2.Change Login Pin\n\033[0;31m3.Clear Encryption or Decryption Message History\n\033[0;34m4.Credits\n\033[0;32m5.Exit Advance Option\033[0m\nChoice:";
        cin>>advcho;
        if(advcho == '1')
        {
            system("cls");
            cout<<"--------------------------------------------------------"<<endl;
            cout<<"|               Select Your Preference                 |"<<endl;
            cout<<"--------------------------------------------------------"<<endl;
            char checkmate;
            cout<<"\033[0;35m1.Encryption History\033[0m\n\033[0;36m2.Decryption History\033[0m\n\033[0;31m3.Back To Menu\033[0m\n\033[0;32mChoice: \033[0m";
            cin >> checkmate;
            string messagehistory,chkempty;
            if(checkmate == '1'){
            system("cls");
            cout<<"--------------------------------------------------------"<<endl;
            cout<<"|               Message And Encryption History         |"<<endl;
            cout<<"--------------------------------------------------------"<<endl;
            ifstream openfile;
            openfile.open("MessageHistory.txt");
            getline(openfile,chkempty);
            openfile.close();

            cout<<"\033[0;31m\033[1m\033[4mNote\033[0m\033[0;31m:Password Message And Password Encrypted Message Are Not Stored Due Security Reasons \033[0m "<<endl;
            cout<<"\n\033[0;33m\033[4mYour Message and Encryption History:\033[0m"<<endl<<endl; 

            if(chkempty.empty())
            {
                cout << "\033[0;35m\nYour Message History Is Empty\033[0m" <<endl;
            }
            else{
            ifstream openmessage;
            if(openmessage.fail())
            {
                cout<<"Something Went Wrong While Display History"<<endl;
                exit(0);
            }
            else{
            openmessage.open("MessageHistory.txt");
            while (getline(openmessage, messagehistory))
            {
            cout << messagehistory <<endl;
            }
            }

            openmessage.close();
            }
            cout<<"\033[0;32mDo You Wants To Continue To Advance Option:\033[0m ";
            cin>>conti;
            if(conti == "Y" || conti == "y")
            {
                system("cls");
                advopt();
            }
            else{
                system("cls");
                codemessage();
            }
            }
            else if(checkmate == '2')
            {
            string dmessage,dmessagechk;
            system("cls");
            cout<<"--------------------------------------------------------"<<endl;
            cout<<"|               Decrypted Message History              |"<<endl;
            cout<<"--------------------------------------------------------"<<endl;
            cout<<"\033[0;31m\033[1m\033[4mNote\033[0m\033[0;31m:Password Message And Password Encrypted Message Are Not Stored Due Security Reasons \033[0m "<<endl;
            cout<<"\n\033[0;33m\033[4mYour Message and Encryption History:\033[0m"<<endl<<endl; 
            ifstream Dfile;
            Dfile.open("DMessageHistory.txt",ios::app);
            if(Dfile.fail())
            {
                cout << "\x1B[Something Went Wrong While Displaying History\n\x1B[0m";
                exit(0);
            }
            getline(Dfile,dmessagechk);
            Dfile.close();
            if(dmessagechk.empty())
            {
                cout << "\033[0;35m\nYour Decrypted Message History Is Empty\033[0m" <<endl;
            }
            else{
                ifstream openagain;
                openagain.open("DmessageHistory.txt",ios::app);
                while(getline(openagain,dmessage)){
                cout<<dmessage;
                cout<<endl;
                }
            }
            cout<<"\033[0;32mDo You Wants To Continue To Advance Option[y/n]:\033[0m ";
            cin>>conti;

            if(conti == "Y" || conti == "y")
            {
            system("cls");
            advopt();
            }
            }
            else if(checkmate == '3')
            {
                system("cls");
                advopt();
            }
            else{
                cout<<"\033[0;31mInvalid Input\033[0m";
            if(conti == "Y" || conti == "y")
            {
            system("cls");
            advopt();
            }
            }

        }
        else if(advcho == '2')
        {
                if(::maxpasschange != 0)
                {
                cout<<"Passowrd Already Changed For this Time!!"<<endl;
                cout<<"\033[0;32mDo You Wants To Continue To Advance Option[y/n]:\033[0m ";
                cin>>conti;
                if(conti == "Y" || conti == "y")
                {
                system("cls");
                advopt();
                }
                else{
                system("cls");
                codemessage();
                }
                }
                else if(::maxpasschange == 0)
                {
                string passwordx,spassadd,spassed;
                system("cls");
                ifstream login;
                login.open("login_detail.txt");
                getline(login,spassed);
                login.close();
                int spasslen = spassed.length();
                for(int i = 144 ; i < spasslen;i++)
                {
                    spassadd += spassed[i];
                }
                do{
                ifstream outFile("login_detail.txt",ios::trunc);
                password1.clear();
                passwordx.clear();
                cout<<"----------------------------------------------"<<endl;
                cout<<"|                Change Pin                  |"<<endl;
                cout<<"----------------------------------------------"<<endl;
                // fflush(stdin);
                cout << "Create Your 6 Digit Login Pin: ";
                    while (true) {
                    ch = getch();
                    if (ch == 13) { 
                    break;
                    } else if (ch == 8) { 
                    if (!passwordx.empty()) {
                    cout << "\b \b";
                    passwordx.pop_back();
                    }
                    } else {
                    cout << '*';
                    passwordx += ch;
                    }
                    }
                    password1 = passwordx;
                    passwordlength = password1.length();
                    cout<<endl;

                if(passwordlength != 6 )
                {
                    system("cls");
                    cout<<"\033[0;31mPlease Enter 6 Digit Pin\033[0m"<<endl;
                }
                } while (passwordlength != 6 || !isdigit(password1[0]) || !isdigit(password1[1]) || !isdigit(password1[2]) || !isdigit(password1[3]) || !isdigit(password1[4]) || !isdigit(password1[5]));

                EncryptPasswordandStore();
                ofstream fileopen;
                fileopen.open("login_detail.txt",ios::app);
                fileopen << spassadd;
                fileopen.close();
                cout<<"Password Change Successfully";
                ::maxpasschange++;
                cout<<endl;
                }
                cout<<"\033[0;32mDo You Wants To Continue To Advance Option[y/n]:\033[0m ";
                cin>>conti;
                if(conti == "Y" || conti == "y")
                {
                system("cls");
                advopt();
                }
                else{
                system("cls");
                codemessage();
                }
        }

        else if(advcho == '3')
                {
                char clear;
                system("cls");
                cout<<"----------------------------------------------"<<endl;
                cout<<"|           Select Your Preference           |"<<endl;
                cout<<"----------------------------------------------"<<endl;
                cout<<"\033[0;35m1.Clear Encrypt History\033[0m\n\033[0;36m2.Clear Decrypt History\033[0m\n\033[0;31m3.Clear Both History\n\033[0;35m4.Back\n\033[0;32mChoice:\033[0m";
                cin >> clear;
                if (clear == '1') {
                string messageInfile;
                ifstream checkfile("MessageHistory.txt");
                
                if (checkfile.is_open()) {
                    getline(checkfile, messageInfile);
                    checkfile.close();
                } else {
                    cout << "\033[0;31mError: Unable to open MessageHistory.txt\033[0m\n";
                    return;
                }

                if (messageInfile.empty()) {
                    cout << "\033[0;35mYour Message History Is Empty\033[0m\n";
                    cout << "\033[0;32mDo You Want To Continue To Advance Option [y/n]:\033[0m ";
                    cin >> conti;

                    if (conti == "Y" || conti == "y") {
                        system("cls"); // Use "clear" for Unix-based systems
                        advopt();
                    } else {
                        system("cls"); // Use "clear" for Unix-based systems
                        codemessage();
                    }
                } else {
                    ofstream file("MessageHistory.txt", ios::trunc);

                    if (file.is_open()) {
                        file.close();
                        cout << "\033[0;35mHistory Cleared Successfully!!\033[0m\n";
                    } else {
                        cout << "\033[0;31mError: Unable to open MessageHistory.txt for writing\033[0m\n";
                    }

                    cout << "\033[0;32mDo You Want To Continue To Advance Option [y/n]:\033[0m ";
                    cin >> conti;

                    if (conti == "Y" || conti == "y") {
                        system("cls"); // Use "clear" for Unix-based systems
                        advopt();
                    } else {
                        system("cls"); // Use "clear" for Unix-based systems
                        codemessage();
                    }
                }
            }

                else if(clear == '2')
                {
                    string checkd;
                    ifstream openfiled;
                    openfiled.open("DMessageHistory.txt",ios::app);
                    getline(openfiled,checkd);
                    openfiled.close();
                    if(checkd.empty())
                    {
                        cout<<"\033[0;35mYour Message History Is Empty\033[0m\n";
                    cout<<"\033[0;32mDo You Wants To Continue To Advance Option[y/n]:\033[0m ";
                    cin>>conti;
                    if(conti == "Y" || conti == "y")
                    {
                    system("cls");
                    advopt();
                    }
                    else{
                    system("cls");
                    codemessage();
                }
                    }
                    else{
                    ofstream file("DMessageHistory.txt",ios::trunc);
                    cout<<"\033[0;35mHistory Cleared Succesfull!!\033[0m\n";
                    cout<<"\033[0;32mDo You Wants To Continue To Advance Option[y/n]:\033[0m ";
                    cin>>conti;
                    cout<<"\033[0;32mDo You Wants To Continue To Advance Option[y/n]:\033[0m ";
                    cin>>conti;
                    if(conti == "Y" || conti == "y")
                    {
                    system("cls");
                    advopt();
                    }
                    else{
                    system("cls");
                    codemessage();
                }
            }
        }
                else if(clear == '3')
                {
                    string file1, file2;

                    ifstream fileemesssage;
                    fileemesssage.open("MessageHistory.txt",ios::app);
                    getline(fileemesssage,file1);
                    fileemesssage.close();

                    ifstream filedmesssage;
                    filedmesssage.open("DMessageHistory.txt",ios::app);
                    getline(filedmesssage,file2);
                    filedmesssage.close();

                    if(file1.empty() && file2.empty())
                    {
                        ofstream fe1i("MessageHistory.txt",ios::trunc);
                        ofstream fe2i("DMessageHistory.txt",ios::trunc);
                    cout<<"\033[0;35mBoth History id empty\033[0m\n";
                    cout<<"\033[0;32mDo You Wants To Continue To Advance Option[y/n]:\033[0m ";
                    cin>>conti;
                    if(conti == "Y" || conti == "y")
                    {
                    system("cls");
                    advopt();
                    }
                    else{
                    system("cls");
                    codemessage();
                    }
                }
                else if(file1.empty() && !file2.empty())
                    {
                        ofstream fe1ii("MessageHistory.txt",ios::trunc);
                        ofstream fe21ii("DMessageHistory.txt",ios::trunc);
                    cout<<"\033[0;nEncrypted Message History is Empty\nDecrypted History Cleared Successfully\033[0m\n";
                    cout<<"\033[0;32mDo You Wants To Continue To Advance Option[y/n]:\033[0m ";
                    cin>>conti;
                    if(conti == "Y" || conti == "y")
                    {
                    system("cls");
                    advopt();
                    }
                    else{
                    system("cls");
                    codemessage();
                    }
                }
                else if(!file1.empty() && file2.empty())
                    {
                        ofstream fe1iii("MessageHistory.txt",ios::trunc);
                        ofstream f21iii("DMessageHistory.txt",ios::trunc);
                    cout<<"\033[0;nDecrypted Message History is Empty\nnEncrypted History Cleared Successfully\033[0m\n";
                    cout<<"\033[0;32mDo You Wants To Continue To Advance Option[y/n]:\033[0m ";
                    cin>>conti;
                    if(conti == "Y" || conti == "y")
                    {
                    system("cls");
                    advopt();
                    }
                    else{
                    system("cls");
                    codemessage();
                    }
                }
                else{
                    ofstream f1("MessageHistory.txt",ios::trunc);
                    ofstream f2("DMessageHistory.txt",ios::trunc);
                    cout<<"\033[0;35mHistory Cleared Succesfull!!\033[0m\n";
                    cout<<"\033[0;32mDo You Wants To Continue To Advance Option[y/n]:\033[0m ";
                    cin>>conti;
                    if(conti == "Y" || conti == "y")
                    {
                    system("cls");
                    advopt();
                    }
                    else{
                    system("cls");
                    codemessage();
                }
                }
                }
                else if(clear == '4')
                {
                    system("cls");
                    advopt();
                }
        else 
        {
            cout<<"\033[0;31mInvalid Input\033[0m";
        }
                
    }
        else if(advcho == '4')
        {
            credits();
        }
        else if(advcho == '5')
        {
            system("cls");
            codemessage();
        }
        else 
        {
            cout<<"\033[0;31mInvalid Input\033[0m";
        }
    } 

        void EncryptPasswordandStore()
        {
        for (int i = 0; i < 6; i++)
        {
            encryptedpass += passwordhast1 + password1[i] + "14047147019" + passwordhast2;
        }
        ofstream InputInFile;
        InputInFile.open("login_detail.txt");
        if(InputInFile.fail())
        {
            cout << "\x1B[31m";
            cout<<"Error!! While Opening File!!";
            cout << "\x1B[0m";
            exit(0);
        }
        InputInFile << encryptedpass;
        InputInFile.close();
    }
void credits() 
{
    system("cls");

    cout << "-----------------------------------------\n";
    cout << "|            Developer Credits          |\n";
    cout << "-----------------------------------------\n";
    cout<<endl;
    cout << left << setw(30) << "Name of Developer:" << "Abhinav Thakur" << endl;
    cout << left << setw(30) << "Developer Role:" << "Development and Execution" << endl;
    cout <<left <<setw(30) << "Team Name:"<<"Group 9"<<endl;
    cout <<left <<setw(30) << "Course:"<<"Computer Engineering"<<endl<<endl;
    cout << left << setw(30) << "Name of Developer:" << "Aditya Toke" << endl;
    cout << left << setw(30) << "Developer Role:" << "Testing and Debuging" << endl;
    cout <<left <<setw(30) << "Team Name:"<<"Group 9"<<endl;
    cout <<left <<setw(30) << "Course:"<<"Computer Engineering"<<endl<<endl;
    cout << left << setw(30) << "Name of Developer:" << "Vinnet Khemani" << endl;
    cout << left << setw(30) << "Developer Role:" << "Testing and Debuging" << endl;
    cout <<left <<setw(30) << "Team Name:"<<"Group 9"<<endl;
    cout <<left <<setw(30) << "Course:"<<"Computer Engineering"<<endl<<endl;
    cout<<endl;
    cout << "-----------------------------------------\n";
}
       
};


class Login:public input
{
protected:
    string password, passwordFromFile, chkpass, passwordbyuser, secondary, secondaryenc, secondarypassword, forgotfromfile,storepasswordchk,fpasssec,secondarypassword1,secondary1;
    string encryptedpass;
    string passwordhast2 = "140256";
    string passwordhast1 = "789256";
    int chks=0;

public:
void advlog()
{
    // string advpass;
    fflush(stdin);
    cout<<"Enter Your Password: ";
    getline(cin,passwordbyuser);
    int passwordlength = passwordbyuser.length();
    if(passwordlength != 4)
    {
                cout<<"\033[0;31m";
                cout << "Incorrect Password";
                cout<<"\033[0m";
                exit(0);
    }
            EncryptPassword();
            if (passwordbyuser == passwordFromFile)
            {
                system("cls");
                codemessage();
            }
            else
            {
                cout<<"\033[0;31m";
                cout << "Incorrect Password";
                cout<<"\033[0m";
                exit(0);
            }
            }



    void account()
    {
        string passp;
        ifstream infile("login_detail.txt",ios::app);
        if(!infile){
        ofstream openpassfile;
        openpassfile.open("login_detail.txt");
        if(openpassfile.fail())
        {
            cout<<"Error!! Please Try Later";
        }
        openpassfile.close();
        }
        
        ifstream openandcheck;
        openandcheck.open("login_detail.txt");
        if(openandcheck.fail())
        {
            cout << "\x1B[31m";
            cout<<"Error!! While Opening File!!";
            cout << "\x1B[0m";
            exit(0);
        }
        getline(openandcheck, passp);
        int passplength = passp.length();
        for(int i = 0; i < passplength - 96 ; i++)
        {
            passwordFromFile += passp[i]; 
        }
        storepasswordchk = passwordFromFile;
        openandcheck.close();

        if (passwordFromFile.empty())
        {
            remove("MessageHistory.txt");
            EnterPassword();
            
        }
        else
        {
            login();
        }
    }

    void EnterPassword()
    {
        int passwordlength, secondarylength;
        string fpassemt;
        char ch;
        fflush(stdin);
        do
        {
        if(chks == 1)
        {
            ofstream file("login_detail.txt",ios::trunc);
            cout<<"-------------------------------------------------------"<<endl;
            cout<<"|                Create New Password                  |"<<endl;
            cout<<"-------------------------------------------------------"<<endl;
        }
        else{
            cout<<"-------------------------------------------------------"<<endl;
            cout<<"|               New User Login Form                   |"<<endl;
            cout<<"-------------------------------------------------------"<<endl;

        }
            password.clear();
            fflush(stdin);
            cout << "Create Your 6 Digit Login Pin: ";

            while (true) {
            ch = getch();
            if (ch == 13) {
            break;
            } else if (ch == 8) { 
            if (!password.empty()) {
            password.pop_back(); 
            cout << "\b \b"; 
            }
            } else {
            password += ch;
            cout << '*'; 
            }
            }
            passwordlength = password.length();
            if(passwordlength != 6)
            {
                system("cls");
                cout<<"\033[0;31mPlease Enter 6 Digit Pin\033[0m";
            }
            cout<<endl;
        } while (passwordlength != 6 || !isdigit(password[0]) || !isdigit(password[1]) || !isdigit(password[2]) || !isdigit(password[3]) || !isdigit(password[4]) || !isdigit(password[5]));

        
        if(chks == 1)
        {
            EncryptPasswordandStore();
            ofstream fileopen;
            fileopen.open("login_detail.txt",ios::app);
            fileopen << fpasssec;
            fileopen.close();
            cout<<fpasssec<<endl;
            cout<<"\033[0;32mPassword Created Successfully\033[0m";
        }

        if(chks != 1)
        {
        do
        {
            secondary.clear();
            system("cls");
            cout<<"--------------------------------------------------------------------------------"<<endl;
            cout<<"|           Enter Secondary Password In Case You Forgot Your Password          |" << endl;
            cout<<"--------------------------------------------------------------------------------"<<endl;
            fflush(stdin);
            cout << "Create Your 4 Digit Secondary Pin: ";
            fflush(stdin);

            while (true) {
            ch = getch();
            if (ch == 13) {
            break;
            } else if (ch == 8) { 
            if (!secondary.empty()) {
            secondary.pop_back(); 
            cout << "\b \b"; 
            }
            } else {
            secondary += ch;
            cout << '*'; 
            }
            }
            secondarylength = secondary.length();
            if(secondarylength != 4)
            {
            system("cls");
            cout<<"\033[0;31mPlease Enter 4 Digit Pin\033[0m"<<endl;
            }
        } while (secondarylength != 4 || secondary == password || !isdigit(secondary[0]) || !isdigit(secondary[1]) || !isdigit(secondary[2]) || !isdigit(secondary[3]));
    }
    if(chks != 1){
    cout<<endl;
    EncryptPasswordandStore();
    EncryptsecondaryPasswordandStore();
    cout<<"\033[0;32mYour Login Detail Created Successfully\nYou Can Login Agian\033[0m";
    exit(0);
    }
    }

void login()
{
    string takepassword;
    int chkpasslength;
    int ax = 0;
    char ch;
    
    while (true)
    {
        cout << "-------------------------------------------------------" << endl;
        cout << "|                Existing User Login                  |" << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "Login[* for Forgot Password]" << endl;
        cout << "Enter Your 6 Digit Pin: ";
        
        fflush(stdin);
        takepassword.clear();
        passwordbyuser.clear();
        
        while (true)
        {
            ch = getch();
            if (ch == 13)
            {
                break;
            }
            else if (ch == 8)
            {
                if (!takepassword.empty())
                {
                    cout << "\b \b";
                    takepassword.pop_back();
                }
            }
            else
            {
                cout << '*';
                takepassword += ch;
            }
        }
        
        chkpasslength = takepassword.length();

        if (ax == 5)
        {
                cout << "\x1B[31m";
                cout << "\nToo Many Unsuccessful Attempts!! Try Again Later" << endl;
                cout << "\x1B[0m";
                exit(0); 
                        }
        
        if (takepassword[0] == '*')
        {
            forgotpassword();
            // continue;
        }
        if (chkpasslength != 6 || chkpasslength > 6  || chkpasslength < 6)
        {
            ax++;
            if (ax == 3 || ax >= 5)
            {
                cout << "\033[0;31m";
                system("cls");
                cout << "Press * for Forgot Password!!" << endl;
                cout << "Incorrect Password" << endl;
                cout << "\033[0m";
            }
            else
            {
                system("cls");
                cout << "\033[0;31mIncorrect Password\033[0m" << endl;
            }
        }
        else
        {
            chkpass.clear();
            chkpass = takepassword;
            EncryptPassword();
            
            if (passwordbyuser == passwordFromFile)
            {
                system("cls");
                codemessage();
                break; 
            }
                ax++;
                system("cls");
                cout << "\033[0;31mIncorrect Password\033[0m" << endl;
                
            
        }
    }
}

    void EncryptPasswordandStore()
    {
        for (int i = 0; i < 6; i++)
        {
            encryptedpass += passwordhast1 + password[i] + "14047147019" + passwordhast2;
        }
        ofstream InputInFile;
        InputInFile.open("login_detail.txt",ios::app);
        if(InputInFile.fail())
        {
            cout << "\x1B[31m";
            cout<<"Error!! While Opening File!!";
            cout << "\x1B[0m";
            exit(0);
        }
        InputInFile << encryptedpass;
        InputInFile.close();
    }

    void EncryptPassword()
    {
        for (int i = 0; i < 6; i++)
        {
            passwordbyuser += passwordhast1 + chkpass[i] + "14047147019" + passwordhast2;
        }
    }

    void EncryptsecondaryPasswordandStore()
    {
        char chklogin;
        for (int i = 0; i < 4; i++)
        {
            secondaryenc += passwordhast1 + secondary[i] + "14047147019" + passwordhast2;
        }
        ofstream SecondaryHashing;
        SecondaryHashing.open("login_detail.txt",ios::app);
        if(SecondaryHashing.fail())
        {
            cout << "\x1B[31m";
            cout<<"Error!! While Opening File!!";
            cout << "\x1B[0m";
            exit(0);
        }
        SecondaryHashing << secondaryenc;
        SecondaryHashing.close();
    }
void EncryptSecondaryPassword(const string& input, string& result) {
    result = "";  // Initialize the result inside the function
    for (int i = 0; i < 4; i++) {
        result += passwordhast1 + input[i] + "14047147019" + passwordhast2;
    }
}
void forgotpassword() {
    int a = 0;
    char ch;
    string secondarypassword1;

    // Read fpass from the file
    string fpass;
    ifstream openforgot("login_detail.txt");
    if (!openforgot.is_open()) {
        cerr << "\x1B[31mError!! While Opening File!!\x1B[0m" << endl;
        exit(1);
    }
    openforgot.ignore(144);  // Assuming you're skipping characters as before
    getline(openforgot, fpass, '\n');
    openforgot.close();

    system("cls");
    while (a < 5) {
    cout << "-------------------------------------------------" << endl;
    cout << "|               Forgot Password                 |" << endl;
    cout << "-------------------------------------------------" << endl;

    cout << "Enter Your Secondary Password: ";

        secondary1 = "";  

        while (true) {
            ch = getch();
            if (ch == 13) {
                break;
            } else if (ch == 8) {
                if (!secondary1.empty()) {
                    cout << "\b \b";
                    secondary1.pop_back();
                }
            } else {
                cout << '*';
                secondary1 += ch;
            }
        }

        int spasslength = secondary1.length();

        if (spasslength == 4) {
            EncryptSecondaryPassword(secondary1, secondarypassword1);
            if (secondarypassword1 == fpass) {
                fpasssec = fpass;
                chks++;
                EnterPassword();
                // cout << "Password Created Successfully!!!\nYou can login Using It:";
                exit(0);
            } else {
                system("cls");
                cout << "\x1B[31mIncorrect Secondary Password\x1B[0m" << endl;
                a++;
                if (a == 5) {
                    resetAll();
                }
            }
        } else {
            system("cls");
            cout << "\x1B[31mIncorrect Secondary Password\x1B[0m" << endl;
            a++;
            if (a == 5) {
                resetAll();
            }
        }
    }
}

void resetAll(){
            system("cls");
            char cho;
            int clear = 0;
            fflush(stdin);
        cout<<"-------------------------------------------------"<<endl;
        cout<<"|               Forgot Password                 |"<<endl;
        cout<<"-------------------------------------------------"<<endl;
            cout << "\033[1m\033[0;33m\033[4mIncase You Forgot Your Password You Need To Reset This Entire Program To Default!!!\033[0m"<< endl;
            cout << "\033[0;31mFollowing Things Should Keep In Mind\033[0m\n1.This Will Remove Your Entire Message History\n2.You Can Never Restore It Again\nDo You Want To Reset This Program [Y/N]:";
            cin >> cho;
            if (cho == 'y' || cho == 'Y')
            {
                 ofstream f1("DMessageHistory.txt",ios::trunc);
                 ofstream f2("login_detail.txt",ios::trunc);
                 ofstream f3("MessageHistory.txt",ios::trunc);   
                if(f2.fail() || f3.fail()){
                cout<<"\033[0;31mSomething Went wrong\033[0m"<<endl;
                exit(0);
                }         
                else{
                cout << "\033[0;32mProgram Reset Successful\033[0m" << endl;
                exit(0);
                }
            }
            else{
                exit(0);
            }
        }

};

int main() {
    char cho;
    int i = 0, max = 2;
    input* obj = new input[max];
    Login check;
    system("cls");

    check.account();
    while(1) {
        cout<<"\x1B[32m";
        cout << "\nDo You Want To Continue [y/n]: ";
        cout << "\x1B[0m";
        cin >> cho;
        fflush(stdin);
        if (cho == 'y' || cho == 'Y') {
            system("cls");
            obj[i].codemessage();
        } else {
            break;
        }
        i++;
        if (i == max) {
            max *= 2; 
            input* newObj = new input[max];
            for (int j = 0; j < i; j++) {
                newObj[j] = obj[j];
            }
            delete[] obj;
            obj = newObj;
        }
    }
    delete[] obj;
    return 0;
}
