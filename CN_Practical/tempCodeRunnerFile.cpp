    #include<bits/stdc++.h>
    using namespace std;

    void Num_ch(string s){
        int count = s.length();
        cout<<"Number of characters are -> ";
        cout<<count<<endl;
    }
    void charStuffing(string data, char esc, char flag ){
        string ans = "";
        ans = ans+flag;
        for(int i = 0; i<data.length(); i++){
            if(data[i] == flag){
                ans = ans+esc;
            }
            ans = ans+data[i];
        }
        ans = ans+flag;
        cout<<" After  Character stuffing the output ->  "<<ans<<endl;
    }

    void bitStuffing(string data){
        string ans = "";
        int count = 0;
        for(int i = 0; i<data.length(); i++){
            ans = ans+data[i];
            if(data[i] == '1'){
                count++;
                if(count == 5){
                    ans = ans+'0';
                    count = 0;
                }
            }else{
                count = 0;
            }
        }
        cout<<"Data after the bit stuffing is -> "<<ans<<endl;
    }


    int main(){

        cout<<"Enter 1 for character count"<<endl;
        cout<<"Enter 2 for charStuffing count"<<endl;
        cout<<"Enter 3 for bitStuffing count"<<endl;

        int n;
        cin>>n;

        string data;

        switch (n)
        {
    case 1 :cout<<"Enter the data->";
                    cin>>data;
                Num_ch(data);
            break;
    case 2 : cout<<"Enter the data->";
                cin>> data;
                cout<<"Enter the ESC char ->";
                char esc;
                cin>>esc;
                cout<<"Enter the Flag char ->";
                char flag;
                cin>>flag;
                charStuffing(data, esc, flag);
            break;
        case 3 : cout<<"Enter the data for bit Stuffing";
                cin>> data;
                bitStuffing(data);
            break;
            default: cout<<"please enter a valid number between 1 to 3";
        }
    }
