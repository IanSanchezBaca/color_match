#include <iostream>
#include <random>

using namespace std;

void change_color(char input);
vector<vector<char>> grid; // eh im too lazy not figure out how to make not be a global variable



int main()
{
    char input;
    char current;
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

    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            cout << grid[x][y];
        }
        cout << endl;
    }

    // input
    // char input;
    current = grid[0][0]; 
    cout << "\nEnter a color.\n";
    cout << "w r b y g p\n";

    cin >> input;


    // logic
    // cout << "logic\n";
    change_color(input);

    // execute
    // cout << "execute\n";

    return 0;
}

void change_color(char input){
cout << grid[0][0];
}

// there are six different colors

/* this is how to create random numbers */

// while (true)
// {
//     cout << dist(rand) << endl;
// }