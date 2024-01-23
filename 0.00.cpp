#include <bits/stdc++.h>
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <chrono>
#include <filesystem>
#include <string>
#include <ctime>
#include <sys/stat.h>
#include <conio.h>


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


#define color_black 0
#define color_dark_blue 1
#define color_dark_green 2
#define color_light_blue 3
#define color_dark_red 4
#define color_magenta 5
#define color_orange 6
#define color_light_gray 7
#define color_gray 8
#define color_blue 9
#define color_green 10
#define color_cyan 11
#define color_red 12
#define color_pink 13
#define color_yellow 14
#define color_white 15


#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#endif


using namespace std;
namespace fs = filesystem;


string get_textcolor_code(const int textcolor)
{ // Linux only
    switch (textcolor)
    {
    case 0:
        return "30"; // color_black      0
    case 1:
        return "34"; // color_dark_blue  1
    case 2:
        return "32"; // color_dark_green 2
    case 3:
        return "36"; // color_light_blue 3
    case 4:
        return "31"; // color_dark_red   4
    case 5:
        return "35"; // color_magenta    5
    case 6:
        return "33"; // color_orange     6
    case 7:
        return "37"; // color_light_gray 7
    case 8:
        return "90"; // color_gray       8
    case 9:
        return "94"; // color_blue       9
    case 10:
        return "92"; // color_green     10
    case 11:
        return "96"; // color_cyan      11
    case 12:
        return "91"; // color_red       12
    case 13:
        return "95"; // color_pink      13
    case 14:
        return "93"; // color_yellow    14
    case 15:
        return "97"; // color_white     15
    default:
        return "37";
    }
}


string get_backgroundcolor_code(const int backgroundcolor)
{ // Linux only
    switch (backgroundcolor)
    {
    case 0:
        return "40"; // color_black      0
    case 1:
        return "44"; // color_dark_blue  1
    case 2:
        return "42"; // color_dark_green 2
    case 3:
        return "46"; // color_light_blue 3
    case 4:
        return "41"; // color_dark_red   4
    case 5:
        return "45"; // color_magenta    5
    case 6:
        return "43"; // color_orange     6
    case 7:
        return "47"; // color_light_gray 7
    case 8:
        return "100"; // color_gray       8
    case 9:
        return "104"; // color_blue       9
    case 10:
        return "102"; // color_green     10
    case 11:
        return "106"; // color_cyan      11
    case 12:
        return "101"; // color_red       12
    case 13:
        return "105"; // color_pink      13
    case 14:
        return "103"; // color_yellow    14
    case 15:
        return "107"; // color_white     15
    default:
        return "40";
    }
}


string get_print_color(const int textcolor)
{ // Linux only
    return "\033[" + get_textcolor_code(textcolor) + "m";
}


string get_print_color(const int textcolor, const int backgroundcolor)
{ // Linux only
    return "\033[" + get_textcolor_code(textcolor) + ";" + get_backgroundcolor_code(backgroundcolor) + "m";
}


void print_color(const int textcolor)
{
#if defined(_WIN32)
    static const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, textcolor);
#elif defined(__linux__)
    cout << get_print_color(textcolor);
#endif // Windows/Linux
}


void print_color(const int textcolor, const int backgroundcolor)
{
#if defined(_WIN32)
    static const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, backgroundcolor << 4 | textcolor);
#elif defined(__linux__)
    cout << get_print_color(textcolor, backgroundcolor);
#endif // Windows/Linux
}


void print_color_reset()
{
#if defined(_WIN32)
    static const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, 7); // reset color
#elif defined(__linux__)
    cout << "\033[0m"; // reset color
#endif // Windows/Linux
}


void println(const string &s = "")
{
    cout << s << endl;
}


void print(const string &s = "")
{
    cout << s;
}


void print(const string &s, const int textcolor)
{
    print_color(textcolor);
    cout << s;
    print_color_reset();
}


void print(const string &s, const int textcolor, const int backgroundcolor)
{
    print_color(textcolor, backgroundcolor);
    cout << s;
    print_color_reset();
}


void print_no_reset(const string &s, const int textcolor)
{ // print with color, but don't reset color afterwards (faster)
    print_color(textcolor);
    cout << s;
}


void print_no_reset(const string &s, const int textcolor, const int backgroundcolor)
{ // print with color, but don't reset color afterwards (faster)
    print_color(textcolor, backgroundcolor);
    cout << s;
}


#ifdef __MINGW32__
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

// inja baraye declare
bool find(int **table, int l, int x, int y, int xx, int yy, int i, int **path, int sum, bool end);
void history_menu_out(int x);
void history_menu();
void output_last_ten();
void save_data(string player_name, string time, string result, string file_name, string date);
void users_list();
void output_list_user(int i);
void output_amar(string s);
void leaderboard();
bool give_path(int **&path, int l, int x, int y, int xx, int yy, int h);
int input_number(string s);
bool gand(int **path, int xx, int yy, int l, int x, int y);
string find_path();
void map_output(int x, int y, int **table, int xx, int yy, int **path, int l);
string map_save(int x, int y, int **table, int xx, int yy, int **path, int l);
void create_map(string s);
void clean();
void read_file(string s, string ss);
void playground(int **table, int l, int x, int y, string file_name);
bool is_on_the_path(int **path, int xx, int yy, int l);
bool make_path(int **path, int xx, int yy, int l, int x, int y, int **table, int maxv, int minv, int maxb, int minb);
bool gandz(int **path, int xx, int yy, int l, int x, int y, int uc, int rc, int dc, int lc);
void menu(int n);
void select_file(string ss);
void output_list(int i);


struct info
{
    string name;
    int wr;
    double tt;
};


vector<pair<int, string>> users;
vector<pair<int, string>> ps;
vector<pair<int, string>> ul;


int main()
{
    string ad;
    cout << "Welcome to Maze Maverick\n";
    char q;
    int x = 1;
    menu(1);
    while (true)
    {
        q = getch();
        clean();
        if ((int)q == 72 && x - 1 > 0)
        {
            x--;
        }
        else if ((int)q == 80 && (x + 1) <= 9)
        {
            x++;
        }
        else if ((int)q == 13)
        {
            if (x == 1)
            {
                create_map("Easy");
            }
            if (x == 2)
            {
                create_map("Hard");
            }
            if (x == 3)
            {
                select_file("play");
            }
            if (x == 4)
            {
                cout << "Please enter your file address : ";
                cin >> ad;
                read_file(ad, "play");
            }
            if (x == 5)
            {
                select_file("find");
                // cin>>x;
            }
            if (x == 6)
            {
                cout << "Please enter your file address : ";
                cin >> ad;
                read_file(ad, "find");
            }
            if (x == 7)
            {
                history_menu();
            }
            if (x == 8)
            {
                leaderboard();
            }
            if (x == 9)
            {
                exit(0);
            }
            x = 1;
            clean();
        }
        else
        {
        }
        menu(x);
    }

    return 0;
}


bool find(int **table, int l, int x, int y, int xx, int yy, int i, int **path, int sum, bool end)
{
    char q;
    if ((xx == x - 1 && yy == y - 1) || (i == l))
    {
        if ((float)sum / 2 == table[x - 1][y - 1] && i == l && (xx == x - 1 && yy == y - 1))
        {
            clean();
            map_output(x, y, table, xx, yy, path, l);
            cout << "\nPress (Backspace) to return";
            cout << "\nPress any key to show other results if exist";
            q = getch();
            if (q == 8)
            {
                return 1;
            }
            return 0;
        }
        else
        {
            return 0;
        }
    }
    if ((is_on_the_path(path, xx + 1, yy, l) || xx + 1 >= x || table[xx + 1][yy] == 0) && (is_on_the_path(path, xx - 1, yy, l) || xx - 1 < 0 || table[xx - 1][yy] == 0) && (is_on_the_path(path, xx, yy + 1, l) || yy + 1 >= y || table[xx][yy + 1] == 0) && (is_on_the_path(path, xx, yy - 1, l) || yy - 1 < 0 || table[xx][yy - 1] == 0))
    {
        return 0;
    }

    if (yy + 1 < y && !is_on_the_path(path, xx, yy + 1, l) && table[xx][yy + 1] != 0)
    {
        path[i][0] = xx;
        path[i][1] = yy;
        yy = yy + 1;

        sum += table[xx][yy];
        i++;
        if (find(table, l, x, y, xx, yy, i, path, sum, 0))
        {
            return 1;
        }

        i--;
        path[i][0] = x;
        path[i][1] = y;
        sum = sum - table[xx][yy];
        yy = yy - 1;
    }
    if (xx - 1 >= 0 && !is_on_the_path(path, xx - 1, yy, l) && table[xx - 1][yy] != 0)
    {
        path[i][0] = xx;
        path[i][1] = yy;
        xx = xx - 1;
        sum += table[xx][yy];
        i++;
        if (find(table, l, x, y, xx, yy, i, path, sum, 0))
        {
            return 1;
        }
        i--;
        path[i][0] = x;
        path[i][1] = y;
        sum = sum - table[xx][yy];
        xx = xx + 1;
    }
    if ((xx + 1) < x && !is_on_the_path(path, xx + 1, yy, l) && table[xx + 1][yy] != 0)
    {
        path[i][0] = xx;
        path[i][1] = yy;
        xx = xx + 1;
        sum += table[xx][yy];
        i++;
        if (find(table, l, x, y, xx, yy, i, path, sum, 0))
        {
            return 1;
        }
        i--;
        path[i][0] = x;
        path[i][1] = y;
        sum = sum - table[xx][yy];
        xx = xx - 1;
    }
    if (yy - 1 >= 0 && !is_on_the_path(path, xx, yy - 1, l) && table[xx][yy - 1] != 0)
    {

        path[i][0] = xx;
        path[i][1] = yy;
        yy = yy - 1;

        sum += table[xx][yy];
        i++;
        if (find(table, l, x, y, xx, yy, i, path, sum, 0))
        {
            return 1;
        }
        i--;
        path[i][0] = x;
        path[i][1] = y;
        sum = sum - table[xx][yy];
        yy = yy + 1;
    }
    return 0;
}


void history_menu_out(int x)
{

    if (x == 1)
    {
        print("Back to menu", color_green, color_black);
        cout << "\n";
    }
    else
    {
        cout << "Back to menu\n";
    }
    if (x == 2)
    {
        print("History of players", color_green, color_black);
        cout << "\n";
    }
    else
    {
        cout << "History of players\n";
    }
    if (x == 3)
    {
        print("Last 10 games", color_green, color_black);
        cout << "\n";
    }
    else
    {
        cout << "Last 10 games\n";
    }
}


void history_menu()
{
    clean();
    char q;
    int x = 1;
    history_menu_out(x);
    while (1)
    {

        q = getch();

        if ((int)q == 72 && x - 1 > 0)
        {
            x--;
        }
        else if ((int)q == 80 && (x + 1) <= 3)
        {
            x++;
        }
        if (q == 13)
        {
            if (x == 1)
            {
                return;
            }
            else if (x == 2)
            {
                users_list();
            }
            else if (x == 3)
            {
                output_last_ten();
            }
        }
        clean();
        history_menu_out(x);
    }
}


void output_last_ten()
{
    string s = find_path() + (char)92 + (char)92 + "Stats" + (char)92 + (char)92 + "history.txt";
    // cout<<s;
    ifstream A(s);
    int i = 0;
    string p;
    clean();
    cout << "Last 10 games : \n\n";
    while (i < 20)
    {
        getline(A, p);
        cout << p << "\n";

        i++;
    }
    A.close();

    cout << "\nPress any key to continue";
    char q = getch();
}


void save_data(string player_name, string time, string result, string file_name, string date)
{

    auto start = std::chrono::system_clock::now();
    // Some computation here
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    string gably, t;
    ifstream B("Stats\\history.txt");
    while (getline(B, t))
    {

        gably = gably + t + "\n";
    }
    B.close();
    ofstream A("Stats\\history.txt");

    A << player_name;
    A << "    " << file_name;
    A << "    " << result;
    A << "    " << time[0] << time[1] << time[2] << time[3] << " s";
    A << "    " << std::ctime(&end_time);
    A << "\n"
      << gably;
    A.close();
    string user_path = player_name;
    user_path = "Users\\" + user_path + ".txt";
    gably = "";
    ifstream D(user_path);
    while (getline(D, t))
    {

        gably = gably + t + "\n";
    }
    D.close();

    ofstream C(user_path);
    C << player_name;
    C << "    " << file_name;
    C << "    " << result;
    C << "    " << time[0] << time[1] << time[2] << time[3] << " s";
    C << "    " << std::ctime(&end_time);
    C << "\n"
      << gably;
    C.close();
}


void users_list()
{
    clean();
    int index;
    string s;
    string path = find_path() + (char)92 + (char)92 + "Users";
    int i = 0;
    while (i != ul.size())
    {
        ul.pop_back();
    }

    struct stat sb;
    ul.push_back(make_pair(0, "Back to menu"));
    int iii = 1;
    for (const auto &entry : fs::directory_iterator(path))
    {
        iii++;
        filesystem::path outfilename = entry.path();
        string outfilename_str = outfilename.string();
        const char *path = outfilename_str.c_str();
        if (stat(path, &sb) == 0 && !(sb.st_mode & S_IFDIR))
        {
            index = outfilename_str.find("Users", 5);
            s = outfilename_str.substr(index + 6);
            ul.push_back(make_pair(iii, s));
            // cout<<s;
        }
    }
    i = 0;
    output_list_user(0);
    char q = 'm';
    // cout<<"FGFHF";
    // cin>>q;

    while ((int)q != 13)
    {
        q = getch();
        if ((int)q == 72 && i - 1 >= 0)
        {
            i--;
        }
        else if ((int)q == 80 && (i + 1) < iii)
        {
            i++;
        }

        clean();

        output_list_user(i);
    }
    if (ul[i].second == "Back to menu")
    {
        return;
    }

    // cout<<"here";
    string f = "";
    // cin>>f;
    f = "Users";
    f = f + (char)92;
    f = f + ul[i].second;
    output_amar(f);
    clean();
}


void output_list_user(int i)
{
    int ii = 0;
    while (ii != ul.size())
    {

        if (i == ii)
        {
            print(ul[ii].second, color_green, color_black);
            cout << "\n";
        }
        else
        {
            cout << ul[ii].second << "\n";
        }
        ii++;
    }
}


void output_amar(string s)
{
    clean();
    ifstream A(s);
    string t;
    int i = 0, j = 0;
    while (getline(A, t))
    {
        i++;
    }
    A.close();
    ifstream B(s);
    double time, tt = 0, times;
    int wc = 0;
    string date;
    bool flag = 1;
    while (j != i / 2)
    {
        B >> t >> t >> t;
        if (t == "WON")
        {
            wc++;
        }
        B >> time;

        tt += time;
        B >> t;

        B >> t;
        if (flag)
        {
            date = date + " " + t;
        }
        B >> t;
        if (flag)
        {
            date = date + " " + t;
        }
        B >> t;
        if (flag)
        {
            date = date + " " + t;
        }
        B >> t;
        if (flag)
        {
            date = date + " " + t;
        }

        B >> t;
        if (flag)
        {
            date = date + " " + t;
            flag = 0;
        }
        j++;
    }
    B.close();

    cout << "Total games : " << i / 2;

    cout << "\nGames won : " << wc;
    cout << "\nTotal time : " << tt;
    cout << "\nLast date : " << date;
    cout << "\nPress any key to continue";
    char q = getch();
}


void leaderboard()
{
    clean();
    string s;
    string path = find_path() + (char)92 + (char)92 + "Users";
    int i = 0;
    while (i != users.size())
    {
        users.pop_back();
    }

    struct stat sb;
    int iii = 1;
    for (const auto &entry : fs::directory_iterator(path))
    {
        iii++;
        filesystem::path outfilename = entry.path();
        string outfilename_str = outfilename.string();
        const char *path = outfilename_str.c_str();
        if (stat(path, &sb) == 0 && !(sb.st_mode & S_IFDIR))
        {
            users.push_back(make_pair(iii, outfilename_str));
        }
    }
    int oo = 0;
    char q = 'm';
    info all[users.size()];
    while (oo != users.size())
    {

        ifstream A(users[oo].second);
        string t;
        int i = 0, j = 0;
        while (getline(A, t))
        {
            i++;
        }
        A.close();
        ifstream B(users[oo].second);
        double time, tt = 0, times;
        int wc = 0;
        while (j != i / 2)
        {
            B >> t;
            all[oo].name = t;
            B >> t >> t;
            if (t == "WON")
            {
                wc++;
            }
            all[oo].wr = wc;
            B >> time;
            tt += time;
            B >> t >> t >> t;
            B >> t >> t >> t;
            j++;
        }
        all[oo].tt = tt;
        B.close();
        oo++;
    }
    oo = 0;
    int fs = 0, ss = 0, ts = 0;
    //     while (oo != users.size())
    //     {
    // cout<<all[oo].name<<"     Win rate : "<<all[oo].wr<<"     Total time : "<<all[oo].tt<<"\n";
    //         oo++;
    //     }
    oo = 0;
    while (oo != users.size())
    {
        if ((all[oo].wr > all[fs].wr || (all[oo].wr == all[fs].wr && all[oo].tt < all[fs].tt)) && oo != fs && oo != ss)
        {
            fs = oo;
        }
        // cout<<fs;
        oo++;
    }
    oo = 0;
    while (oo != users.size())
    {
        if ((all[oo].wr > all[ss].wr || (all[oo].wr == all[ss].wr && all[oo].tt < all[ss].tt)) && oo != fs && oo != ss)
        {
            ss = oo;
        }
        // cout<<ss;
        oo++;
    }
    oo = 0;
    while (oo != users.size())
    {
        if ((all[oo].wr > all[ts].wr || (all[oo].wr == all[ts].wr && all[oo].tt < all[ts].tt)) && oo != fs && oo != ss)
        {
            ts = oo;
        }
        // cout<<ts;
        oo++;
    }
    cout << all[fs].name << "     Win rate : " << all[fs].wr << "     Total time : " << all[fs].tt << "\n\n";
    if (users.size() > 1)
    {

        cout << all[ss].name << "     Win rate : " << all[ss].wr << "     Total time : " << all[ss].tt << "\n\n";
    }
    if (users.size() > 2)
    {
        cout << all[ts].name << "     Win rate : " << all[ts].wr << "     Total time : " << all[ts].tt << "\n\n";
    }
    cout << "\nPress any key to continue";
    q = getch();

    clean();
}


bool give_path(int **&path, int l, int x, int y, int xx, int yy, int h)
{

    // int najafi = rand() % 4;

    // cout<<"\n"<<xx<<" "<<yy<<" "<<h<<"\n";
    // r = 0;
    if (h == l)
    {
        if (xx == x - 1 && yy == y - 1)
        {
            // cout<<"inja??";
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (xx - 1 >= 0 && !is_on_the_path(path, xx - 1, yy, l))
    {
        xx = xx - 1;
        path[h][0] = xx;
        path[h][1] = yy;
        h++;
        if (give_path(path, l, x, y, xx, yy, h))
        {
            return 1;
        }
        // cout<<h<<" ";
        h--;
        path[h][0] = x;
        path[h][1] = y;
        xx++;
    }
    if (yy + 1 < y && !is_on_the_path(path, xx, yy + 1, l))
    {

        yy = yy + 1;
        path[h][0] = xx;
        path[h][1] = yy;
        h++;
        if (give_path(path, l, x, y, xx, yy, h))
        {
            return 1;
        }
        // cout<<h<<" ";
        h--;
        path[h][0] = x;
        path[h][1] = y;
        yy--;
    }
    if (xx + 1 < x && !is_on_the_path(path, xx + 1, yy, l))
    {
        xx = xx + 1;
        path[h][0] = xx;
        path[h][1] = yy;
        h++;
        if (give_path(path, l, x, y, xx, yy, h))
        {
            return 1;
        }
        // cout<<h<<" ";
        h--;
        path[h][0] = x;
        path[h][1] = y;
        xx--;
    }
    if (yy - 1 >= 0 && !is_on_the_path(path, xx, yy - 1, l))
    {
        yy = yy - 1;
        path[h][0] = xx;
        path[h][1] = yy;
        h++;
        if (give_path(path, l, x, y, xx, yy, h))
        {
            return 1;
        }
        // cout<<h<<" ";
        h--;
        path[h][0] = x;
        path[h][1] = y;
        yy++;
    }
    // cout<<"kifkd";
    return 0;
}


int input_number(string s)
{
    int i = s.size() - 1, n = 1, num = 0;
    while (i != -1)
    {
        if (isdigit(s[i]))
        {
            num = num + (s[i] - '0') * n;
            // cout << num << "\n";

            n = n * 10;
        }
        else
        {
            return -1;
        }

        i--;
    }
    return num;
}


bool gand(int **path, int xx, int yy, int l, int x, int y)
{
    if ((is_on_the_path(path, xx + 1, yy, l) || xx + 1 >= x) && (is_on_the_path(path, xx - 1, yy, l) || xx - 1 < 0) && (is_on_the_path(path, xx, yy + 1, l) || yy + 1 >= y) && (is_on_the_path(path, xx, yy - 1, l) || yy - 1 < 0))
    {
        return 1;
    }
    return 0;
}


string find_path()
{
    char tmp[256];
    getcwd(tmp, 256);
    string s = tmp, q;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == (char)92)
        {
            q += s[i];
        }
        q += s[i];
    }
    return q;
}


void map_output(int x, int y, int **table, int xx, int yy, int **path, int l)
{
    int max_l = to_string(table[0][0]).size();
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (to_string(table[i][j]).size() > max_l)
            {
                max_l = to_string(table[i][j]).size();
            }
        }
    }

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

                        cout << char(186) << "  ";
                    }
                    else
                    {
                        cout << "  " << char(186) << "  ";
                    }
                }
                else
                {
                    bool flag2 = 1;
                    string out = to_string(table[(i - 1) / 2][(j - 1) / 2]);
                    while (out.size() < max_l)
                    {
                        if (flag2)
                        {
                            out = out + ' ';
                            flag2 = 0;
                        }
                        else
                        {
                            out = ' ' + out;
                            flag2 = 1;
                        }
                    }

                    bool flag = 1;
                    for (size_t h = 0; h < l; h++)
                    {
                        if (path[h][0] == (i - 1) / 2 && path[h][1] == (j - 1) / 2)
                        {
                            flag = 0;
                            print(out, color_green, color_black);
                        }
                    }

                    if ((i - 1) / 2 == xx && (j - 1) / 2 == yy)
                    {
                        print(out, color_pink, color_black);
                    }
                    else if (table[(i - 1) / 2][(j - 1) / 2] == 0 && ((i - 1) / 2 != x - 1 || (j - 1) / 2 != y - 1))
                    {
                        // cout<<x<<y;
                        print(out, color_red, color_black);
                    }
                    else if (flag == 1)
                    {
                        print(out, color_white, color_black);
                    }
                }
            }
        }
        else
        {
            for (int j = 0; j < y * (5 + max_l) + 1; j++)
            {

                if (j % (5 + max_l) == 0)
                {
                    if (i == 0)
                    {

                        if (j == 0)
                        {
                            cout << char(201);
                        }
                        else if (j == y * (5 + max_l))
                        {
                            cout << char(187);
                        }
                        else
                        {
                            cout << char(203);
                        }
                    }
                    else if (i == 2 * x)
                    {
                        if (j == 0)
                        {
                            cout << char(200);
                        }
                        else if (j == y * (5 + max_l))
                        {
                            cout << char(188);
                        }
                        else
                        {
                            cout << char(202);
                        }
                    }
                    else
                    {
                        if (j == 0)
                        {
                            cout << char(204);
                        }
                        else if (j == y * (5 + max_l))
                        {
                            cout << char(185);
                        }
                        else
                        {
                            cout << char(206);
                        }
                    }
                }
                else
                {
                    cout << char(205);
                }
            }
        }
    }
}


string map_save(int x, int y, int **table, int xx, int yy, int **path, int l)
{
    string s;

    int max_l = to_string(table[0][0]).size();
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (to_string(table[i][j]).size() > max_l)
            {
                max_l = to_string(table[i][j]).size();
            }
        }
    }

    for (int i = 0; i < x * 2 + 1; i++)
    {
        s += "\n";

        if (i % 2 != 0)
        {

            for (int j = 0; j < y * 2 + 1; j++)
            {
                if (j % 2 == 0)
                {
                    if (j == 0)
                    {
                        s += "|  ";
                    }
                    else
                    {
                        s += "  |  ";
                    }
                }
                else
                {
                    bool flag2 = 1;
                    string out = to_string(table[(i - 1) / 2][(j - 1) / 2]);
                    while (out.size() < max_l)
                    {
                        if (flag2)
                        {
                            out = out + ' ';
                            flag2 = 0;
                        }
                        else
                        {
                            out = ' ' + out;
                            flag2 = 1;
                        }
                    }

                    bool flag = 1;
                    for (size_t h = 0; h < l; h++)
                    {
                        if (path[h][0] == (i - 1) / 2 && path[h][1] == (j - 1) / 2)
                        {
                            flag = 0;
                            s += out;
                        }
                    }

                    if ((i - 1) / 2 == xx && (j - 1) / 2 == yy)
                    {
                        s += out;
                    }
                    else if (table[(i - 1) / 2][(j - 1) / 2] == 0 && ((i - 1) / 2 != x - 1 || (j - 1) / 2 != y - 1))
                    {
                        // cout<<x<<y;
                        s += out;
                    }
                    else if (flag == 1)
                    {
                        s += out;
                    }
                }
            }
        }
        else
        {
            for (int j = 0; j < y * (5 + max_l) + 1; j++)
            {
                s += "-";
            }
        }
    }
    return s;
}


void create_map(string s)
{
    char q;
    int x = -1, y = -1, l = -1;
    int xx = 0, yy = 0;
    int max_value = -1, min_value = -1, max_block = -1, min_block = -1;
    string map, input;

    cout << "\nPress (Backspace) to return to menu";
    if (s == "Easy")
    {
        cout << "\nPress any key to create an " << s << " map";
    }
    if (s == "Hard")
    {
        cout << "\nPress any key to create a " << s << " map";
    }
    q = getch();
    if (q == 8)
    {
        return;
    }
    clean();
    cout << "\nEnter number of lines : ";
    bool f = 0;
    while (x == -1)
    {
        // cout << ":";
        cin >> input;
        x = input_number(input);
        if (x == -1)
        {
            f = 1;
        }
        else
        {
            break;
        }
        if (f)
        {
            cout << "\nIncorrect format!! please try again.";
        }
        f = 1;
    }
    // cin>>x;
    cout << "\nEnter number of columns : ";
    f = 0;
    while (y == -1)
    {
        cin >> input;
        y = input_number(input);
        if (y == -1)
        {
            f = 1;
        }
        else
        {
            break;
        }
        if (f)
        {
            cout << "\nIncorrect format!! please try again.";
        }
        f = 1;
    }
    if (s != "Easy")
    {
        cout << "\nEnter length of the path : ";
        f = 0;
        while (l == -1)
        {
            cin >> input;
            l = input_number(input);
            if (l == -1)
            {
                f = 1;
            }
            else
            {
                break;
            }
            if (f)
            {
                cout << "\nIncorrect format!! please try again.";
            }
            f = 1;
        }
        cout << "\nEnter minimum value of numbers : ";
        f = 0;
        while (min_value == -1)
        {
            cin >> input;
            min_value = input_number(input);
            if (min_value == -1)
            {
                f = 1;
            }
            else
            {
                break;
            }
            if (f)
            {
                cout << "\nIncorrect format!! please try again.";
            }
            f = 1;
        }
        cout << "\nEnter maximum value of numbers : ";
        f = 0;
        while (max_value == -1)
        {
            cin >> input;
            max_value = input_number(input);
            if (max_value == -1)
            {
                f = 1;
            }
            else
            {
                break;
            }
            if (f)
            {
                cout << "\nIncorrect format!! please try again.";
            }
            f = 1;
        }
        cout << "\nEnter minimum number of blocks : ";
        f = 0;
        while (min_block == -1)
        {
            cin >> input;
            min_block = input_number(input);
            if (min_block == -1)
            {
                f = 1;
            }
            else
            {
                break;
            }
            if (f)
            {
                cout << "\nIncorrect format!! please try again.";
            }
            f = 1;
        }
        cout << "\nEnter maximum number of blocks : ";
        f = 0;
        while (max_block == -1)
        {
            cin >> input;
            max_block = input_number(input);
            if (max_block == -1)
            {
                f = 1;
            }
            else
            {
                break;
            }
            if (f)
            {
                cout << "\nIncorrect format!! please try again.";
            }
            f = 1;
        }
    }
    else
    {
        l = x + y - 2;
        min_value = -3;
        max_value = 3;
        min_block = 2;
        max_block = 5;
    }
    if ((x + y) % 2 != l % 2)
    {
        cerr << "\nInvalid path length!!";
        cout << "\nPress any key to continue";
        q = getch();
        return;
    }
    if (l > x * y - 1)
    {
        cerr << "\nInvalid path length!!";
        cout << "\nPress any key to continue";
        q = getch();
        return;
    }
    if (l < x + y - 2)
    {
        cerr << "\nInvalid path length!!";
        cout << "\nPress any key to continue";
        q = getch();
        return;
    }
    if (l + min_block + 1 > x * y)
    {
        cerr << "\nInvalid number of blocks!!";
        cout << "\nPress any key to continue";
        q = getch();
        return;
    }
    if (min_block > max_block)
    {
        cerr << "\nInvalid minimum and maximum blocks!!";
        cout << "\nPress any key to continue";
        q = getch();
        return;
    }
    if (min_block < 0)
    {
        cerr << "\nInvalid minimum blocks!!";
        cout << "\nPress any key to continue";
        q = getch();
        return;
    }
    if (min_value > max_value)
    {
        cerr << "\nInvalid minimum and maximum values!!";
        cout << "\nPress any key to continue";
        q = getch();
        return;
    }

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

    make_path(path, xx, yy, l, x, y, table, max_value, min_value, max_block, min_block);
    map = map_save(x, y, table, xx, yy, path, l);
    string name, addres;

    cout << "\nMap creation was successful\nPlease enter a name for your map : ";
    cin >> name;

    cout << "\nYour map has been saved as " << '"' << s << '_' << name << ".txt" << '"';
    addres = (char)92 + s + '_' + name + '.' + "txt";
    addres = "Maps" + addres;
    // cout << name;
    ofstream A(addres);
    A << map;
    A << "\nMap name : " << name;
    A << "\nMap level : " << s;
    A << "\nPath length : " << l;

    A.close();
    cout << "\nPress any key to continue";
    q = getch();
}


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


void read_file(string s, string ss)
{

    bool flag = 1;
    char q;
    string t;
    int x = 0, y = -1, l;
    ifstream A(s);
    if (A.fail() == 1)
    {
        cerr << "\nInvalid address";
        cout << "\nPress any key to continue";
        q = getch();
        return;
    }
    while (1)
    {
        getline(A, t);

        if (t[0] == '|')
        {
            x++;
            if (flag == 1)
            {
                for (int i = 0; i < t.size(); i++)
                {
                    if (t[i] == '|')
                    {
                        y++;
                    }
                }
                flag = 0;
            }
        }
        if (t[0] == 'M')
        {
            getline(A, t);
            A >> t >> t >> t >> l;

            break;
        }
    }

    A.close();
    ifstream B(s);
    int **table = new int *[x];
    for (int i = 0; i < x; i++)
    {
        *(table + i) = new int[y];
        for (int j = 0; j < y; j++)
        {
            table[i][j] = 0;
        }
    }
    // cout<<l;
    int i = 0, j = 0, ii = 0, jj = 0;
    string temp;
    while (ii != x)
    {
        getline(B, t);

        if (t[0] == '|')
        {
            while (j != t.size())
            {
                if (t[j] == '|')
                {
                }
                else if (t[j] == ' ')
                {
                    if (isdigit(t[j - 1]) == 1)
                    {
                        // cout<<"\n"<<temp;
                        table[ii][jj] = stoi(temp);
                        temp = "";
                        jj++;
                    }
                }
                else
                {
                    temp += t[j];
                }
                j++;
            }

            ii++;
        }
        jj = 0;
        j = 0;
        i += 2;
    }

    B.close();
    if (ss == "find")
    {
        int **path = new int *[l];
        for (int i = 0; i < l; i++)
        {
            *(path + i) = new int[2];
            for (int j = 0; j < 2; j++)
            {
                path[i][j] = x;
            }
        }
        if (!find(table, l, x, y, 0, 0, 0, path, table[0][0], 0))
        {
            cout << "There is no any path";
            cout << "\nPress any key to continue";
            q = getch();
        }
        // cout << "\npress any key to continue";
        // q = getch();
    }
    if (ss == "play")
    {
        string name;
        int i = s.size();
        while (i != 0)
        {
            if (s[i] == (char)92)
            {
                break;
            }
            name = s[i] + name;
            i--;
        }
        playground(table, l, x, y, name);
    }
}


void playground(int **table, int l, int x, int y, string file_name)
{
    char q;
    int xx = 0, yy = 0;
    int **path = new int *[l];
    for (int i = 0; i < l; i++)
    {
        *(path + i) = new int[2];
        for (int j = 0; j < 2; j++)
        {
            path[i][j] = x;
        }
    }
    string player_name;
    cout << "Enter your name : ";
    cin >> player_name;

    string result, time, date;

    auto start = chrono::steady_clock::now();
    map_output(x, y, table, xx, yy, path, l);

    int sum = table[0][0];
    for (size_t i = 0; i < l;)
    {
        cout << "\nYour path sum : " << sum;
        cout << "\nYour path length : " << i;
        cout << "\nTarget path length : " << l;
        if ((is_on_the_path(path, xx + 1, yy, l) || xx + 1 >= x || (table[xx + 1][yy] == 0 && xx != x - 1 && yy != y - 1)) && (is_on_the_path(path, xx - 1, yy, l) || xx - 1 < 0 || (table[xx - 1][yy] == 0 && xx != x - 1 && yy != y - 1)) && (is_on_the_path(path, xx, yy + 1, l) || yy + 1 >= y || (table[xx][yy + 1] == 0 && xx != x - 1 && yy != y - 1)) && (is_on_the_path(path, xx, yy - 1, l) || yy - 1 < 0 || (table[xx][yy - 1] == 0 && xx != x - 1 && yy != y - 1)))
        {
            clean();
            map_output(x, y, table, xx, yy, path, l);
            print("\nYOU LOST!!", color_red, color_black);

            cout << "\nYour path sum : " << sum;
            cout << "\nYour path length : " << i;
            cout << "\nTarget path length : " << l;
            auto end = chrono::steady_clock::now();
            auto diff = end - start;
            cout << "\nTime spending: " << fixed << setprecision(2) << chrono::duration<double>(diff).count() << " s";
            time = to_string(chrono::duration<double>(diff).count());
            save_data(player_name, time, result, file_name, date);
            break;
        }
        q = getch();
        clean();
        // cout<<int(q);
        if ((int)q == 72 && xx - 1 >= 0 && !is_on_the_path(path, xx - 1, yy, l) && (table[xx - 1][yy] != 0 || (xx - 1 == x - 1 && yy == y - 1)))
        {
            path[i][0] = xx;
            path[i][1] = yy;
            xx = xx - 1;
            map_output(x, y, table, xx, yy, path, l);
            sum += table[xx][yy];
            i++;
        }
        else if ((int)q == 80 && (xx + 1) < x && !is_on_the_path(path, xx + 1, yy, l) && (table[xx + 1][yy] != 0 || (xx + 1 == x - 1 && yy == y - 1)))
        {
            path[i][0] = xx;
            path[i][1] = yy;
            xx = xx + 1;
            map_output(x, y, table, xx, yy, path, l);
            sum += table[xx][yy];
            i++;
        }
        else if ((int)q == 77 && yy + 1 < y && !is_on_the_path(path, xx, yy + 1, l) && (table[xx][yy + 1] != 0 || (xx == x - 1 && yy + 1 == y - 1)))
        {
            path[i][0] = xx;
            path[i][1] = yy;
            yy = yy + 1;
            map_output(x, y, table, xx, yy, path, l);
            sum += table[xx][yy];
            i++;
        }
        else if ((int)q == 75 && yy - 1 >= 0 && !is_on_the_path(path, xx, yy - 1, l) && (table[xx][yy - 1] != 0 || (xx == x - 1 && yy - 1 == y - 1)))
        {
            path[i][0] = xx;
            path[i][1] = yy;
            yy = yy - 1;
            map_output(x, y, table, xx, yy, path, l);
            sum += table[xx][yy];
            i++;
        }
        else
        {

            map_output(x, y, table, xx, yy, path, l);
            print("\nInvalid move!!\nPlease try again", color_red, color_black);
        }
        if ((xx == x - 1 && yy == y - 1) || (i == l))
        {
            auto end = chrono::steady_clock::now();
            auto diff = end - start;
            if (i == l && (float)sum / 2.0 == table[x - 1][y - 1])
            {
                cout << "\n";
                print("YOU WON!!", color_green, color_black);
                cout << "\nYour sum : " << sum - table[x - 1][y - 1];
                cout << "\nYour path length : " << i;
                cout << "\nTarget path length : " << l;
                result = "WON";
            }
            else
            {
                print("\nYOU LOST!!", color_red, color_black);
                cout << "\nYour sum : " << sum - table[x - 1][y - 1];
                cout << "\nYour path length : " << i;
                cout << "\nTarget path length : " << l;
                result = "LOST";
            }
            cout << "\nTime spending: " << fixed << setprecision(2) << chrono::duration<double>(diff).count() << " s";
            time = to_string(chrono::duration<double>(diff).count());
            save_data(player_name, time, result, file_name, date);
            break;
        }
    }
    cout << "\nPress any key to continue";
    q = getch();
}


bool is_on_the_path(int **path, int xx, int yy, int l)
{

    for (size_t h = 0; h < l; h++)
    {
        if (path[h][0] == xx && path[h][1] == yy)
        {
            return 1;
        }
    }
    return 0;
}


bool make_path(int **path, int xx, int yy, int l, int x, int y, int **table, int maxv, int minv, int maxb, int minb)
{
    srand(time(0));
    int r = 0;
    int sum = 0;
    while (r == 0)
    {
        if (minv != maxv)
        {
            r = rand() % (maxv - minv + 1) + minv;
        }
        else
        {
            r = minv;
        }
    }
    table[0][0] = r;
    sum += r;

    for (size_t i = 0; i < l; i++)
    {
        path[i][0] = x;
        path[i][1] = y;
    }
inja:
    xx = 0;
    yy = 0;
    int lc = 0, rc = y - 1, uc = 0, dc = x - 1, llc = 0, rrc = y - 1, ddc = x - 1, uuc = 0;
    int ezafe = (l - (x + y - 2)) / 2;
    for (int i = 0; i < ezafe; i++)
    {
        int najafi = rand() % 2;
        if (najafi % 2 == 0)
        {
            ddc++;
            uuc++;
        }
        if (najafi % 2 == 1)
        {
            llc++;
            rrc++;
        }
    }
    lc = llc;
    rc = rrc;
    dc = ddc;
    uc = uuc;

    for (size_t i = 0; i < l; i++)
    {
        path[i][0] = 0;
        path[i][1] = 0;
    }
    int h = 0;

    while (true)
    {
        int najafi = rand() % 4;
        r = 0;
        if (najafi == 0 && uc > 0 && xx - 1 >= 0 && !is_on_the_path(path, xx - 1, yy, l))
        {
            xx = xx - 1;
            path[h][0] = xx;
            path[h][1] = yy;

            uc--;
            h++;
        }
        else if (najafi == 1 && rc > 0 && yy + 1 < y && !is_on_the_path(path, xx, yy + 1, l))
        {

            yy = yy + 1;
            path[h][0] = xx;
            path[h][1] = yy;

            rc--;
            h++;
        }
        else if (najafi == 2 && dc > 0 && xx + 1 < x && !is_on_the_path(path, xx + 1, yy, l))
        {
            xx = xx + 1;
            path[h][0] = xx;
            path[h][1] = yy;

            dc--;
            h++;
        }
        else if (najafi == 3 && lc > 0 && yy - 1 >= 0 && !is_on_the_path(path, xx, yy - 1, l))
        {
            yy = yy - 1;
            path[h][0] = xx;
            path[h][1] = yy;
            lc--;
            h++;
        }
        if (h == l)
        {
            break;
        }
        if (gandz(path, xx, yy, l, x, y, uc, rc, dc, lc))
        {
            goto inja;
        }
    }
    for (size_t i = 0; i < l - 1; i++)
    {
        r = 0;
        while (r == 0)
        {
            if (minv != maxv)
            {
                r = rand() % (maxv - minv + 1) + minv;
            }
            else
            {
                r = minv;
            }
        }

        table[path[i][0]][path[i][1]] = r;
        sum += r;
    }
    table[x - 1][y - 1] = sum;
    for (size_t i = 0; i < x; i++)
    {
        for (size_t j = 0; j < y; j++)
        {
            if (!is_on_the_path(path, i, j, l) && (i != 0 || j != 0))
            {
                r = 0;
                while (r == 0)
                {
                    if (minv != maxv)
                    {
                        r = rand() % (maxv - minv + 1) + minv;
                    }
                    else
                    {
                        r = minv;
                    }
                }

                table[i][j] = r;
            }
        }
    }

    r = -1;
    while (r == -1)
    {
        if (minb != maxb)
        {
            r = rand() % (maxb - minb + 1) + minb;
        }
        else
        {
            r = minb;
        }

        if (r + l + 1 > x * y)
        {
            r = -1;
        }
    }
    int nb = r, e;
    for (size_t i = 0; i < nb;)
    {
        r = rand() % x;
        e = rand() % y;
        if (!is_on_the_path(path, r, e, l) && (r != 0 || e != 0) && table[r][e] != 0)
        {
            table[r][e] = 0;
            i++;
        }
    }

    return 1;
}


bool gandz(int **path, int xx, int yy, int l, int x, int y, int uc, int rc, int dc, int lc)
{
    if ((is_on_the_path(path, xx + 1, yy, l) || xx + 1 >= x || dc == 0) && (is_on_the_path(path, xx - 1, yy, l) || xx - 1 < 0 || uc == 0) && (is_on_the_path(path, xx, yy + 1, l) || yy + 1 >= y || rc == 0) && (is_on_the_path(path, xx, yy - 1, l) || yy - 1 < 0 || lc == 0))
    {
        return 1;
    }
    return 0;
}


void menu(int n)
{
    print("1. ", color_red, color_black);
    cout << "Create a new map\n";
    print("  -1.1 ", color_red, color_black);
    if (n == 1)
    {
        print("  Easy\n", color_green, color_black);
    }
    else
    {
        print("  Easy\n", color_white, color_black);
    }
    print("  -1.2 ", color_red, color_black);
    if (n == 2)
    {
        print("  Hard\n", color_green, color_black);
    }
    else
    {
        print("  Hard\n", color_white, color_black);
    }
    print("2. ", color_red, color_black);
    cout << "Playground\n";
    print("  -2.1 ", color_red, color_black);
    if (n == 3)
    {
        print("  Choose from existing maps\n", color_green, color_black);
    }
    else
    {
        print("  Choose from existing maps\n", color_white, color_black);
    }
    print("  -2.2 ", color_red, color_black);
    if (n == 4)
    {
        print("  Import a custom map\n", color_green, color_black);
    }
    else
    {
        print("  Import a custom map\n", color_white, color_black);
    }
    print("3. ", color_red, color_black);
    cout << "Solve a maze\n";
    print("  -3.1 ", color_red, color_black);
    if (n == 5)
    {
        print("  Choose from existing maps\n", color_green, color_black);
    }
    else
    {
        print("  Choose from existing maps\n", color_white, color_black);
    }
    print("  -3.2 ", color_red, color_black);
    if (n == 6)
    {
        print("  Import a custom map\n", color_green, color_black);
    }
    else
    {
        print("  Import a custom map\n", color_white, color_black);
    }
    print("4. ", color_red, color_black);
    if (n == 7)
    {
        print("History\n", color_green, color_black);
    }
    else
    {
        print("History\n", color_white, color_black);
    }
    print("5. ", color_red, color_black);
    if (n == 8)
    {
        print("Leaderboard\n", color_green, color_black);
    }
    else
    {
        print("Leaderboard\n", color_white, color_black);
    }
    print("6. ", color_red, color_black);
    if (n == 9)
    {
        print("Exit\n", color_green, color_black);
    }
    else
    {
        print("Exit\n", color_white, color_black);
    }
}


void select_file(string ss)
{
    int index;
    string s;
    string path = find_path() + (char)92 + (char)92 + "Maps";
    int i = 0;
    while (i != ps.size())
    {
        ps.pop_back();
    }

    struct stat sb;
    ps.push_back(make_pair(0, "Back to menu"));
    int iii = 1;
    for (const auto &entry : fs::directory_iterator(path))
    {
        iii++;
        filesystem::path outfilename = entry.path();
        string outfilename_str = outfilename.string();
        const char *path = outfilename_str.c_str();
        if (stat(path, &sb) == 0 && !(sb.st_mode & S_IFDIR))
        {
            index = outfilename_str.find("Maps");
            s = outfilename_str.substr(index + 5);
            ps.push_back(make_pair(iii, s));
        }
    }
    i = 0;
    output_list(0);
    char q = 'm';

    while ((int)q != 13)
    {
        q = getch();
        if ((int)q == 72 && i - 1 >= 0)
        {
            i--;
        }
        else if ((int)q == 80 && (i + 1) < iii)
        {
            i++;
        }

        clean();

        output_list(i);
    }
    if (ps[i].second == "Back to menu")
    {
        return;
    }

    string f = "";
    f = "Maps";
    f = f + (char)92;
    f = f + ps[i].second;
    clean();
    if (ss == "find")
    {
        read_file(f, "find");
    }
    if (ss == "play")
    {
        // cout << f;
        // cin >> f;
        read_file(f, "play");
    }
}


void output_list(int i)
{
    int ii = 0;
    while (ii != ps.size())
    {

        if (i == ii)
        {
            print(ps[ii].second, color_green, color_black);
            cout << "\n";
        }
        else
        {
            cout << ps[ii].second << "\n";
        }
        ii++;
    }
}