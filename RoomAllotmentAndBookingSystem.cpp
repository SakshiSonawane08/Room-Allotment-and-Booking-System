#include <bits/stdc++.h>
using namespace std;

static int p = 0;

class Room
{
  int roomNumber;
  string host, sessionStartTime, sessionEndTime, chair[8][4];

  void vline(char ch)
  {
    for (int i = 40; i > 0; i--)
      cout << ch;
  }

public:
  void install()
  {
    roomNumber = p + 1;
    cout << "Enter Host's name: ";
    cin >> host;
    cout << "Session Start time: ";
    cin >> sessionStartTime;
    cout << "Session Ends at: ";
    cin >> sessionEndTime;
    empty();
    p++;

    cout << "\nAlloted room number: " << roomNumber;
  }

  void allotment()
  {
    int chairNumber;
    cout << "Enter Chair Number: ";
    cin >> chairNumber;
    if (chairNumber > 32)
      cout << "\nThere are only 32 Chair available in this Room.";
    else
    {
      if (chair[chairNumber / 4][(chairNumber % 4) - 1] == "Empty") // Checks if the chair is taken or not
      {
        cout << "Enter traveller's name: ";
        cin >> chair[chairNumber / 4][(chairNumber % 4) - 1];
      }
      else
        cout << "\nThe Chair is already reserved.";
    }
  }

  void empty()
  {
    for (int i = 0; i < 8; i++)
      for (int j = 0; j < 4; j++)
        chair[i][j] = "Empty";
  }

  void show()
  {
    vline('*');
    cout << "\nRoom no: " << roomNumber
         << "\nHost: " << host << "\nSession Start Time: "
         << sessionStartTime << "\nSession End time: " << sessionEndTime << "\n";
    vline('*');

    position();

    int a = 1;
    for (int i = 0; i < 8; i++)
      for (int j = 0; j < 4; j++)
      {
        a++;
        if (chair[i][j] != "Empty")
          cout << "\nThe Chair no " << (a - 1) << " is reserved for " << chair[i][j] << ".";
      }
  }

  void avail()
  {
    vline('-');
    cout << "\nRoom no: " << roomNumber << "\nHost: " << host
         << "\nsession Start Time: " << sessionStartTime << "\nEnd Time: "
         << sessionEndTime << "\n";
    vline('-');
  }

  void position()
  {
    int s = 0;
    int totalEmptyChairs = 0;
    for (int i = 0; i < 8; i++)
    {
      cout << "\n";
      for (int j = 0; j < 4; j++)
      {
        s++;
        if (chair[i][j] == "Empty")
        {
          cout.width(5);
          cout.fill(' ');
          cout << s << ".";
          cout.width(10);
          cout.fill(' ');
          cout << chair[i][j];
          totalEmptyChairs++;
        }
        else
        {
          cout.width(5);
          cout.fill(' ');
          cout << s << ".";
          cout.width(10);
          cout.fill(' ');
          cout << chair[i][j];
        }
      }
    }
    cout << "\nThere are " << totalEmptyChairs << " Chairs empty in Room No: " << roomNumber;
  }
};

int main()
{
  // system("cls");
  Room room[10];
  int w;
  while (true)
  {
    int number;
    cout << "\n\n";
    cout << "\n1.Install"
         << "\n2.Reservation"
         << "\n3.Show"
         << "\n4.Available Rooms"
         << "\n5.Exit";
    cout << "\nEnter your choice:-> ";
    cin >> w;
    switch (w)
    {
    case 1: // selects and updates Rooms' metadata.
      room[p].install();
      break;
    case 2:
      cout << "Enter Room no: ";
      cin >> number;
      room[number - 1].allotment();
      break;
    case 3:
      cout << "Enter Room no: ";
      cin >> number;
      room[number - 1].show();
      break;
    case 4:
      for (int n = 0; n < p; n++)
        room[n].avail();
      break;
    case 5:
      exit(0);
    }
  }
  return 0;
}