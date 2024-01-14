#include <iostream>
#include <bits/stdc++.h>
#include<windows.h>
#include <stdio.h>
#include <conio.h>
#include<cmath>


#define LTARROW 0x4B 
#define RTARROW 0x4D 
#define UPARROW 0x48 
#define DNARROW 0x50 
#define CR 0x0d 
#define ESC 0x1b 

#define F1_Key 0x3b00
#define F2_Key 0x3c00
#define F3_Key 0x3d00
#define F4_Key 0x3e00
#define F5_Key 0x3f00
#define F6_Key 0x4000
#define F7_Key 0x4100
#define F8_Key 0x4200
#define F9_Key 0x4300
#define F10_Key 0x4400



#include <iostream>
#include <string>
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <Windows.h> // for displaying colors
#endif // Windows
using namespace std;

#define color_black      0
#define color_dark_blue  1
#define color_dark_green 2
#define color_light_blue 3
#define color_dark_red   4
#define color_magenta    5
#define color_orange     6
#define color_light_gray 7
#define color_gray       8
#define color_blue       9
#define color_green     10
#define color_cyan      11
#define color_red       12
#define color_pink      13
#define color_yellow    14
#define color_white     15


string get_textcolor_code(const int textcolor) { // Linux only
    switch(textcolor) {
        case  0: return "30"; // color_black      0
        case  1: return "34"; // color_dark_blue  1
        case  2: return "32"; // color_dark_green 2
        case  3: return "36"; // color_light_blue 3
        case  4: return "31"; // color_dark_red   4
        case  5: return "35"; // color_magenta    5
        case  6: return "33"; // color_orange     6
        case  7: return "37"; // color_light_gray 7
        case  8: return "90"; // color_gray       8
        case  9: return "94"; // color_blue       9
        case 10: return "92"; // color_green     10
        case 11: return "96"; // color_cyan      11
        case 12: return "91"; // color_red       12
        case 13: return "95"; // color_pink      13
        case 14: return "93"; // color_yellow    14
        case 15: return "97"; // color_white     15
        default: return "37";
    }
}
string get_backgroundcolor_code(const int backgroundcolor) { // Linux only
    switch(backgroundcolor) {
        case  0: return  "40"; // color_black      0
        case  1: return  "44"; // color_dark_blue  1
        case  2: return  "42"; // color_dark_green 2
        case  3: return  "46"; // color_light_blue 3
        case  4: return  "41"; // color_dark_red   4
        case  5: return  "45"; // color_magenta    5
        case  6: return  "43"; // color_orange     6
        case  7: return  "47"; // color_light_gray 7
        case  8: return "100"; // color_gray       8
        case  9: return "104"; // color_blue       9
        case 10: return "102"; // color_green     10
        case 11: return "106"; // color_cyan      11
        case 12: return "101"; // color_red       12
        case 13: return "105"; // color_pink      13
        case 14: return "103"; // color_yellow    14
        case 15: return "107"; // color_white     15
        default: return  "40";
    }
}
string get_print_color(const int textcolor) { // Linux only
    return "\033["+get_textcolor_code(textcolor)+"m";
}
string get_print_color(const int textcolor, const int backgroundcolor) { // Linux only
    return "\033["+get_textcolor_code(textcolor)+";"+get_backgroundcolor_code(backgroundcolor)+"m";
}
void print_color(const int textcolor) {
#if defined(_WIN32)
    static const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, textcolor);
#elif defined(__linux__)
    cout << get_print_color(textcolor);
#endif // Windows/Linux
}
void print_color(const int textcolor, const int backgroundcolor) {
#if defined(_WIN32)
    static const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, backgroundcolor<<4|textcolor);
#elif defined(__linux__)
    cout << get_print_color(textcolor, backgroundcolor);
#endif // Windows/Linux
}
void print_color_reset() {
#if defined(_WIN32)
    static const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, 7); // reset color
#elif defined(__linux__)
    cout << "\033[0m"; // reset color
#endif // Windows/Linux
}

void println(const string& s="") {
    cout << s << endl;
}
void print(const string& s="") {
    cout << s;
}
void print(const string& s, const int textcolor) {
    print_color(textcolor);
    cout << s;
    print_color_reset();
}
void print(const string& s, const int textcolor, const int backgroundcolor) {
    print_color(textcolor, backgroundcolor);
    cout << s;
    print_color_reset();
}
void print_no_reset(const string& s, const int textcolor) { // print with color, but don't reset color afterwards (faster)
    print_color(textcolor);
    cout << s;
}
void print_no_reset(const string& s, const int textcolor, const int backgroundcolor) { // print with color, but don't reset color afterwards (faster)
    print_color(textcolor, backgroundcolor);
    cout << s;
}
<<<<<<< Updated upstream
int main() {

    int v,vv,vh,n;
    double te,tet,tim,g=9.8;
    print("Enter V0 : ", color_light_blue, color_black);

    cin>>v;
    print("Enter theta :", color_light_blue, color_black);

    cin>>te;


    print("Enter the number of environments to check :", color_light_blue, color_black);
    cin>>n;
    double gg[n];
    gg[0]=9.82;
    for (int i=1;i!=n;i++){
        print("Enter environment`s gravity : ", color_light_blue, color_black);
        cin>> gg[i];
=======

// for getch

#ifdef __MINGW32__
#include <conio.h>
const int UP_KEY = 72;
const int DOWN_KEY = 80;
const int ENTER_KEY = 13;
const int RIGHT_KEY = 77;
const int LEFT_KEY = 75;
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
#include <termios.h>
const int UP_KEY = 65;
const int DOWN_KEY = 66;
const int RIGHT_KEY = 67;
const int LEFT_KEY = 68;
const int ENTER_KEY = int('\n');
int getch(void);
#endif

#if defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    return ch;
}
#endif

void clean()
{
#if defined _WIN32
    system("cls");
    // clrscr(); // including header file : conio.h
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    // std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
#elif defined(__APPLE__)
    system("clear");
#endif
}
//...
// output map
void map_output(int x, int y, int **table, int xx, int yy, int **path)
{

    for (int i = 0; i < x * 2 + 1; i++)
    {
        cout << endl;

        if (i % 2 != 0)
        {

            for (int j = 0; j < y * 2 + 1; j++)
            {
                if (j % 2 == 0)
                {
                    if (j == 0)
                    {
                        cout << "|  ";
                    }
                    else
                    {
                        cout << "  |  ";
                    }
                }
                else
                {
                    if ((i - 1) / 2 == xx && (j - 1) / 2 == yy)
                    {
                        print(to_string(table[(i - 1) / 2][(j - 1) / 2]), color_pink, color_black);
                    }
                    else
                    {
                        print(to_string(table[(i - 1) / 2][(j - 1) / 2]), color_white, color_black);
                    }
                    // if(color ==2){
                    // print(to_string(table[(i-1)/2][(j-1)/2]), color_blue, color_black);
                    // }
                    // if(color ==3){
                    // print(to_string(table[(i-1)/2][(j-1)/2]), color_gray, color_black);
                    // }
                    // if(color ==4){
                    // print(to_string(table[(i-1)/2][(j-1)/2]), color_green, color_black);
                    // }
                }
            }
        }
        else
        {
            for (int j = 0; j < y * 6 + 1; j++)
            {
                cout << "-";
            }
        }
>>>>>>> Stashed changes
    }
<<<<<<< Updated upstream



    tet=te*3.14/180;
    string s[10]={"color_pink","color_green"};




        
    cout<<"\n";    
    print("V vertical = V0 * Sin(theta) = ", color_green, color_black);
    // cout<<sin(te);
    // cout<<"V vertical = V0 * Sin(theta) = ";
    vv=sin(tet) *v;
    printf("%.2f",sin(tet) *v);
    print("  m/s", color_green, color_black);    
    cout<<"\n";
    print("V Horizontal = V0 * Cos(theta) = ", color_green, color_black);
    vh=cos(tet) *v;
     printf("%.2f",cos(tet) *v);
    print("  m/s", color_green, color_black);     
    // cout<<sin(90);
    // cout<<sin(30);
    // tim=vv*2/g;
     cout<<"\n";   
    for (int i = 0; i < n; i++)
    {
        


cout<<"\n";
    print("gravity : ", color_red, color_black);    
    printf("%.2f",gg[i]);
        print("  m/s^2", color_red, color_black);  
     cout<<"\n";   
    print("Time : ", color_blue, color_black);    
    printf("%.2f",sin(tet) *v*2/gg[i]);
    // cout<<" "<<gg[i]<<" "<<sin(tet)*2*v/gg[i];
    print("  s", color_blue, color_black);   
    cout<<"\n";


    print("Peak height : ", color_orange, color_black); 
    printf("%.2f",sin(tet) *v*sin(tet) *v/2/gg[i]);
        print("  m", color_orange, color_black);   
    cout<<"\n";


    print("delta X : ", color_pink, color_black);    
    printf("%.2f",sin(tet) *v*2/gg[i]*cos(tet) *v);   
        print("  m", color_pink, color_black); 
        cout<<"\n";
    }
    



    println();
    return 0;
}
=======
}

int main()
{
    int x, y, l;
    cout << "Enter number of lines : ";
    cin >> x;
    cout << "Enter number of columns : ";
    cin >> y;
    cout << "Enter length of the path : ";
    cin >> l;
    int **path = new int *[l];
    for (int i = 0; i < l; i++)
    {
        *(path + i) = new int[2];
        for (int j = 0; j < 2; j++)
        {
            path[i][j] = x;
        }
    }

    int **table = new int *[x];
    for (int i = 0; i < x; i++)
    {
        *(table + i) = new int[y];
        for (int j = 0; j < y; j++)
        {
            table[i][j] = 0;
        }
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {

            table[i][j] = 0;
            // cout<<table[i][j];
        }
    }
    // int** t=new int* [x];
    int xx = 0, yy = 0;
    map_output(x, y, table, xx, yy, path);
    char q;
    for (size_t i = 0; i < l;)
    {

        q = getch();
        clean();
        // cout<<int(q);
        if ((int)q == 72 && xx - 1 >= 0)
        {
            path[i][0] = xx;
            path[i][1] = yy;
            xx = xx - 1;
            map_output(x, y, table, xx, yy, path);
            i++;
        }
        else if ((int)q == 80 && (xx + 1) < x)
        {
            path[i][0] = xx;
            path[i][1] = yy;
            xx = xx + 1;
            map_output(x, y, table, xx, yy, path);
            i++;
        }
        else if ((int)q == 77 && yy + 1 < y)
        {
            path[i][0] = xx;
            path[i][1] = yy;
            yy = yy + 1;
            map_output(x, y, table, xx, yy, path);
            i++;
        }
        else if ((int)q == 75 && yy - 1 >= 0)
        {
            path[i][0] = xx;
            path[i][1] = yy;
            yy = yy - 1;
            map_output(x, y, table, xx, yy, path);
            i++;
        }
        else
        {
            map_output(x, y, table, xx, yy, path);
            print("\nInvalid move!!\nPlease try again", color_red, color_black);
        }
    }
}
>>>>>>> Stashed changes
