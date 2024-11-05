//Author: Shane Wilkerson
//Date: 11-1-2024

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int nrows = 3;
    int ncols = 4;
    if (argc > 1)
        nrows = atoi(argv[1]);
    if (argc > 2)
        ncols = atoi(argv[2]);

    cout << "Lab-8 add up large numbers" << endl;
    cout << "--------------------------" << endl;
    cout << "Enter rows and columns: " << nrows << " " << ncols << endl;
    cout << endl;


    vector<vector<int> > numbers(nrows, vector<int>(ncols)); //creates a 2D vector, with nrows and each row has a vector of ncols
    
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            numbers[i][j] = rand() % 10; //generates the random number 
            cout << numbers[i][j];
        }
        cout << endl;
    }

    vector<int> result(ncols + 1, 0); //creates a vector called result with ncols + 1 to create room for carryover, the 0 initializes all of them to 0
    int carry = 0;

    for (int j = ncols - 1; j >= 0; j--) { //outer loop that starts from right most column
        int column_sum = carry;            //sum for each column
        for (int i = 0; i < nrows; i++) { //inner loop to go through each row
            column_sum += numbers[i][j];  //adds all the numbers in the same column
        }
        result[j + 1] = column_sum % 10;  //mod by 10 to get the number that stays (j + 1 to shift to the right)
        carry = column_sum / 10; //get the number that will be carried over
    }
    result[0] = carry; //after all columns are done, this will be carried over to the first index of the vector

    for (int j = 0; j < ncols + 1; j++) {
        cout << "-";
    }
    cout << endl;

    for(std::vector<int>::size_type i = 0; i < result.size(); i++) { //for loop to display each index of vector
        cout << result[i];
    }
    cout << endl;

    return 0;
}

