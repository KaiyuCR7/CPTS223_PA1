#include <map>
#include "TwitterData.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    // Schema: UserName,Last,First,Email,NumTweets,MostViewedCategory
    string raw_data[5][6] = { {"rangerPower", "Smit", "Rick", "smitRick@gmail.com", "1117", "power lifting"},
                             {"kittyKat72", "Smith", "Kathryn", "kat@gmail.com", "56", "health"},
                             {"lexi5", "Anderson", "Alexis", "lexi5@gmail.com", "900", "education"},
                             {"savage1", "Savage", "Ken", "ksavage@gmail.com", "17", "president"},
                             {"smithMan", "Smith", "Rick", "rick@hotmail.com", "77", "olympics"} };
    TwitterData* twitter_data = new TwitterData[5];
    for (int i = 0; i < 5; ++i)
    {
        twitter_data[i].setUserName(raw_data[i][0]);
        twitter_data[i].setActualName(raw_data[i][2] + " " + raw_data[i][1]);
        twitter_data[i].setEmail(raw_data[i][3]);
        twitter_data[i].setNumTweets(stoi(raw_data[i][4]));
        twitter_data[i].setCategory(raw_data[i][5]);
    }

    map<string, TwitterData> userMap;
    map<string, TwitterData> emailMap;

    for (int i = 0; i < 5; ++i)
    {
        userMap.insert(pair<string, TwitterData>(raw_data[i][0], twitter_data[i]));
    }

    cout << " First Printing for Scenario 1: \n\n";
    for (map<string, TwitterData>::iterator it = userMap.begin(); it != userMap.end(); it++) {
        cout << "Key Username: " << it->first << endl;
        cout << "Values: " << endl;
        cout << "Real Name: " << it->second.getActualName() << endl;
        cout << "Email: " << it->second.getEmail() << endl;
        cout << "Number of Tweets: " << it->second.getNumTweets() << endl;
        cout << "Favorite Category: " << it->second.getCategory() << endl;
        cout << endl;
    }
    cout << endl;

    userMap.erase("savage1");

    cout << "After Erasing: \n\n";
    for (map<string, TwitterData>::iterator it = userMap.begin(); it != userMap.end(); it++) {
        cout << "Key Username: " << it->first << endl;
        cout << "Values: " << endl;
        cout << "Real Name: " << it->second.getActualName() << endl;
        cout << "Email: " << it->second.getEmail() << endl;
        cout << "Number of Tweets: " << it->second.getNumTweets() << endl;
        cout << "Favorite Category: " << it->second.getCategory() << endl;
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < 5; ++i)
    {
        emailMap.insert(pair<string, TwitterData>(raw_data[i][3], twitter_data[i]));
    }

    cout << "First Printing for Scenario 2: \n\n";
    for (map<string, TwitterData>::iterator it = emailMap.begin(); it != emailMap.end(); it++) {
        cout << "Key Email: " << it->first << endl;
        cout << "Values: " << endl;
        cout << "Real Name: " << it->second.getActualName() << endl;
        cout << "Username: " << it->second.getUserName() << endl;
        cout << "Number of Tweets: " << it->second.getNumTweets() << endl;
        cout << "Favorite Category: " << it->second.getCategory() << endl;
        cout << endl;
    }
    cout << endl;

    emailMap.erase("kat@gmail.com");

    cout << "After Erasing: \n\n";
    for (map<string, TwitterData>::iterator it = emailMap.begin(); it != emailMap.end(); it++) {
        cout << "Key Email: " << it->first << endl;
        cout << "Values: " << endl;
        cout << "Real Name: " << it->second.getActualName() << endl;
        cout << "Username: " << it->second.getUserName() << endl;
        cout << "Number of Tweets: " << it->second.getNumTweets() << endl;
        cout << "Favorite Category: " << it->second.getCategory() << endl;
        cout << endl;
    }
    cout << endl;

    return 0;
}