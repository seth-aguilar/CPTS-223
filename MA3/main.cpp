#include <map>
#include "TwitterData.hpp"
using namespace std;

int main(int argc, char *argv[])
{
    // Schema: UserName,Last,First,Email,NumTweets,MostViewedCategory
    string raw_data[5][6] = {{"rangerPower", "Smit", "Rick", "smitRick@gmail.com", "1117", "power lifting"},
                             {"kittyKat72", "Smith", "Kathryn", "kat@gmail.com", "56", "health"},
                             {"lexi5", "Anderson", "Alexis", "lexi5@gmail.com", "900", "education"},
                             {"savage1", "Savage", "Ken", "ksavage@gmail.com", "17", "president"},
                             {"smithMan", "Smith", "Rick", "rick@hotmail.com", "77", "olympics"}};
    TwitterData *twitter_data = new TwitterData[5];
    for (int i = 0; i < 5; ++i)
    {
        twitter_data[i].setUserName(raw_data[i][0]);
        twitter_data[i].setActualName(raw_data[i][2] + " " + raw_data[i][1]);
        twitter_data[i].setEmail(raw_data[i][3]);
        twitter_data[i].setNumTweets(stoi(raw_data[i][4]));
        twitter_data[i].setCategory(raw_data[i][5]);
    }


    // Map Scenario 1: Search based on UserName
    map<string, TwitterData> mapByUsername;
    for (int i = 0; i < 5; ++i)
    {
        mapByUsername[twitter_data[i].getUserName()] = twitter_data[i];
    }
    cout << "Print searchbyName map: " << endl;
    for (const auto& pair : mapByUsername)
    {
        cout << "Key: " << pair.first << ", Value: " << pair.second.print() << " " << endl;
    }
    cout << endl;
    auto it1 = mapByUsername.find("savage1");
    if (it1 != mapByUsername.end())
    {
        cout << "Search for key: savage1 Value: " << it1->second.print() << endl;
        mapByUsername.erase(it1);
    }

    // Map Scenario 2: Search based on EmailAddress
    map<string, TwitterData> mapByEmail;
    for (int i = 0; i < 5; ++i)
    {
        mapByEmail[twitter_data[i].getEmail()] = twitter_data[i];
    }
    cout << "Print searchByEmail map: " << endl;
    for (const auto& pair : mapByEmail)
    {
        cout << "Key: " << pair.first << ", Value: " << pair.second.print() << " " << endl;
    }
    cout << endl;
    auto it2 = mapByEmail.find("kat@gmail.com");
    if (it2 != mapByEmail.end())
    {
        cout << "Search for key: kat@gmail.com Value: " << it2->second.print() << endl;
        mapByEmail.erase(it2);
    }

    delete[] twitter_data;    
    
    return 0;
}