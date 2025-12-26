/*
 * Project: The Signal Decoder
 * Description: A program to remove noise (perfect squares), sort, and analyze an integer array.
 * Author: Rangerr
 */

#include <bits/stdc++.h>
using namespace std;

// --- Function Prototypes ---
void input(int a[], int n);
void removeNoise(int a[], int &n);
void specialSort(int a[], int n);
void analysis(int a[], int n);

int main()
{
    const int MAX = 100;
    int n, a[MAX];

    // 1. Input Loop: Validate n (0 < n <= 100)
    do
    {
        cout << "Nhap so phan tu trong mang :";
        cin >> n;
    } while (n <= 0 || n > MAX);

    // 2. Input Array Elements
    input(a, n);
    cout << "Mang ban dau la: \n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    // 3. Remove Noise (Perfect Squares)
    removeNoise(a, n);
    cout << "\nMang sau khi loai bo nhieu la: \n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    // 4. Special Sort (Odd Increasing, Even Descending)
    cout << "\nMang sau khi sap xep la: \n";
    specialSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";

    // 5. Analyze (Find Pythagorean Triplet)
    analysis(a, n);

    return 0;
}

// Function to input array elements
void input(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap mang thu " << i << " :";
        cin >> a[i];
    }
}

// Function to remove Perfect Squares (1, 4, 9, 16...) from the array
void removeNoise(int a[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        // Check if a[i] is a perfect square
        if ((int)sqrt(a[i]) * (int)sqrt(a[i]) == a[i])
        {
            // Shift elements to the left to delete a[i]
            for (int j = i; j < n - 1; j++)
            {
                a[j] = a[j + 1];
            }
            n--; // Decrease array size
            i--; // Re-check the current index after shifting
        }
    }
}

// Function to sort Odds to front (Ascending) and Evens to back (Descending)
void specialSort(int a[], int n)
{
    // Step 1: Partition Odds and Evens using Two Pointers
    int start = 0, end = n - 1, le = 0;
    while (start < end)
    {
        if (a[start] % 2 != 0) // If odd, keep it at start
        {
            start++;
        }
        else if (a[start] % 2 == 0 && a[end] % 2 != 0) // If start is even and end is odd, swap
        {
            swap(a[start], a[end]);
            end--;
            start++;
        }
        else // If end is even, keep it at end
        {
            end--;
        }
    }

    // Count the number of Odd elements
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
            le++;
    }

    // Step 2: Sort the Odd section (Ascending)
    for (int i = 0; i < le - 1; i++)
    {
        for (int j = 0; j < le - 1; j++)
        {
            if (a[i] < a[i + 1]) // NOTE: Sorting logic based on index i
            {
                swap(a[i], a[i + 1]);
            }
        }
    }

    // Step 3: Sort the Even section (Descending)
    for (int i = le; i < n - 1; i++)
    {
        for (int j = le; j < n - 1; j++)
        {
            if (a[i] < a[i + 1]) // NOTE: Sorting logic based on index i
            {
                swap(a[i], a[i + 1]);
            }
        }
    }
}

// Function to find the first Pythagorean Triplet (a^2 + b^2 = c^2)
void analysis(int a[], int n)
{
    // Brute-force using 3 nested loops
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                // Check Pythagorean theorem condition
                if (a[i] * a[i] + a[j] * a[j] == a[k] * a[k] ||
                    a[i] * a[i] + a[k] * a[k] == a[j] * a[j] ||
                    a[j] * a[j] + a[k] * a[k] == a[i] * a[i])
                {
                    cout << "Bo 3 Pythagoras tim thay: " << a[i] << ", " << a[j] << ", " << a[k] << "\n";
                    return; // Found one, exit function
                }
            }
        }
    }
}