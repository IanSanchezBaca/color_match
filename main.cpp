#include <iostream>
#include <random>

using namespace std;

void change_color(int, int);
void print_grid();

vector<vector<char>> grid; // eh im too lazy not figure out how to make not be a global variable

char current;
char input;
bool dead = false;

int main()
{
    int chances = 25;
    // setup
    random_device rand;
    uniform_int_distribution<int> dist(0, 5);

    grid.resize(10);

    // cout << grid.size() << endl;

    for (int x = 0; x < 10; x++)
    {
        grid[x].resize(10);

        for (int y = 0; y < 10; y++)
        {
            // dist(rand);
            switch (dist(rand))
            {
            case 0:
                // cout << 'w';
                grid[x][y] = 'w';
                break;
            case 1:
                // cout << 'r';
                grid[x][y] = 'r';
                break;
            case 2:
                // cout << 'b';
                grid[x][y] = 'b';
                break;
            case 3:
                // cout << 'y';
                grid[x][y] = 'y';
                break;
            case 4:
                // cout << 'g';
                grid[x][y] = 'g';
                break;
            case 5:
                // cout << 'p';
                grid[x][y] = 'p';
                break;

            default:
                cout << "broken\n";
                break;
            }
            // cout << endl;
        }
    }

    print_grid();

    while (!dead)
    {
        // input
        cout << "\nEnter a color.\n";
        cout << "w r b y g p\n";
        cout << "chances left: " << chances << endl;

        cin >> input;
        chances--;

        if((input != 'w') && (input != 'r') && (input != 'b') && (input != 'y') && (input != 'g') && (input != 'p')){
            cout << "not an option!\n";
            exit(1);
        }

        // logic
        if(chances == 0){
            dead = true;
        }
        current = grid[0][0];
        change_color(0, 0);


        // print
        system("clear");
        print_grid();
    }
    return 0;
} // main

void change_color(int x, int y)
{
    grid[x][y] = input;
    if(x != 9){ // check right
        if(grid[x+1][y] == current){
            change_color(x+1, y);
        }
    }
    if(y != 9){// check down
        if(grid[x][y+1] == current){
            change_color(x, y+1);
        }
    }
    if(x != 0){// check left
        if(grid[x-1][y] == current){
            change_color(x-1, y);
        }
    }
    if(y != 0){// check up
        if(grid[x][y-1] == current){
            change_color(x, y-1);
        }
    }
}// change_color

void print_grid()
{
    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            cout << grid[x][y] << " ";
        }
        cout << endl;
    }
} // print_grid

// there are six different colors

/* this is how to create random numbers */

// while (true)
// {
//     cout << dist(rand) << endl;
// }