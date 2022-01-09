#include <bits/stdc++.h>
using namespace std;

int main()
{

    int bag_size;
    int number_of_items;
    cin >> bag_size >> number_of_items;
    int value[number_of_items + 1], weight[number_of_items + 1];

    for (int i = 1; i <= number_of_items; i++)
    {
        cin >> value[i] >> weight[i];
    }

    int table[number_of_items + 1][bag_size + 1];
    memset(table, 0, sizeof(table));

    for (int r = 1; r <= number_of_items; r++)
    {
        for (int c = 1; c <= bag_size; c++)
        {
            if ( c < weight[r])
            {
                table[r][c] = table[r - 1][c];
            }
            else
            {
                table[r][c] = max(table[r - 1][c], value[r] + table[r - 1][c - weight[r]]); //* 7+1
            }
        }
    }

    for (int r = 0; r <= number_of_items; r++)
    {
        for (int c = 0; c <= bag_size; c++)
        {
            cout << table[r][c] << " ";
        }
        cout << endl;
    }

    cout << "Maximum Profit: " << table[number_of_items][bag_size] << endl;


    int i = number_of_items;
    int j = bag_size;

    while(table[i][j] != 0) {
        if(table[i][j] != table[i-1][j]) {
            cout << "Item :" << i << " value : " << value[i] << " weight : " << weight[i] << endl;
            j = j - weight[i];
        }
        i--;
    }

    return 0;
}
