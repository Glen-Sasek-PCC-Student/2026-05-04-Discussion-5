#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function prototypes
void manualEntryPath();
void randomPath();
void darkSidePath();
void displayStats(int count, int sum, int min, int max);

int main()
{
    srand((unsigned)time(0));

    int choice = 0;

    cout << "Welcome, young Padawan. Strong with the Force, numbers are.\n";

    while (choice != 4)
    {
        cout << "\nChoose your path, you must:\n";
        cout << "1 - Enter numbers, you will\n";
        cout << "2 - Random numbers, trust in the Force\n";
        cout << "3 - Dark Side, embrace you may\n";
        cout << "4 - Exit, your training ends\n";

        cout << "Your choice, what is it? ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Confused, you are. Try again, you must.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            manualEntryPath();
            break;
        case 2:
            randomPath();
            break;
        case 3:
            darkSidePath();
            break;
        case 4:
            cout << "Training complete. Strong you have become.\n";
            break;
        default:
            cout << "Confused, you are. Try again, you must.\n";
        }
    }

    cout << "May the Force be with you.\n";
    return 0;
}

// =========================
// Manual Entry
// =========================
void manualEntryPath()
{
    int number;
    int count = 0, sum = 0, min = 0, max = 0;

    cout << "Numbers, you will enter. End with -9999, you must.\n";

    while (true)
    {
        cout << "A number, give me: ";
        cin >> number;

        if (number == -9999)
            break;

        if (count == 0)
        {
            min = max = number;
        }
        else
        {
            if (number < min) min = number;
            if (number > max) max = number;
        }

        sum += number;
        count++;
    }

    displayStats(count, sum, min, max);
}

// =========================
// Light Side Random
// =========================
void randomPath()
{
    int n;

    cout << "How many numbers shall the Force generate? ";
    cin >> n;

    int count = 0, sum = 0, min = 0, max = 0;

    for (int i = 0; i < n; i++)
    {
        int number = rand() % 100 + 1; // 1–100

        cout << "Generated, this number was: " << number << "\n";

        if (count == 0)
        {
            min = max = number;
        }
        else
        {
            if (number < min) min = number;
            if (number > max) max = number;
        }

        sum += number;
        count++;
    }

    displayStats(count, sum, min, max);
}

// =========================
// DARK SIDE PATH 😈
// =========================
void darkSidePath()
{
    int n;

    cout << "Power you seek? How many numbers shall the Dark Side create? ";
    cin >> n;

    int count = 0, sum = 0, min = 0, max = 0;

    for (int i = 0; i < n; i++)
    {
        int number = -(rand() % 100 + 1); // -1 to -100

        cout << "From the shadows, comes: " << number << "\n";

        if (count == 0)
        {
            min = max = number;
        }
        else
        {
            if (number < min) min = number;
            if (number > max) max = number;
        }

        sum += number;
        count++;
    }

    displayStats(count, sum, min, max);

    cout << "The Dark Side grows stronger within you...\n";
}

// =========================
// Display Stats
// =========================
void displayStats(int count, int sum, int min, int max)
{
    if (count == 0)
    {
        cout << "No numbers, you entered. Learn, you must.\n";
        return;
    }

    double average = (double)sum / count;

    cout << "\nYour training results, these are:\n";
    cout << "Count: " << count << "\n";
    cout << "Sum: " << sum << "\n";
    cout << "Average: " << average << "\n";
    cout << "Minimum: " << min << "\n";
    cout << "Maximum: " << max << "\n";

    if (average > 50)
        cout << "Strong with the Force, you are.\n";
    else if (average < 0)
        cout << "Consumed by the Dark Side, you have become.\n";
    else
        cout << "More training, you require.\n";
}
