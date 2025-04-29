#include <map>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{

    map<string, vector<string>> graph;
    graph["You"] = {"Alice", "Bob", "Claire"};
    graph["Bob"] = {"Anuj", "Peggy"};
    graph["Alice"] = {"Peggy"};
    graph["Anuj"] = {};
    graph["Peggy"] = {};
    graph["Tom"] = {};
    graph["Johnny"] = {};

    // Lambda to check if a person is a mango seller.
    auto person_is_seller = [](const string &name) -> bool
    {
        // Example criteria: if the name ends with 'm'
        return !name.empty() && name.back() == 'b';
    };

    // Lambda that performs a breadth-first search on the graph.
    auto search = [&](const string &start) -> bool
    {
        deque<string> search_queue;
        // Add the starting person's neighbors.
        for (const auto &neighbor : graph[start])
            search_queue.push_back(neighbor);
        vector<string> searched;
        while (!search_queue.empty())
        {
            string person = search_queue.front();
            search_queue.pop_front();
            // Only check this person if not already searched.
            if (find(searched.begin(), searched.end(), person) == searched.end())
            {
                if (person_is_seller(person))
                {
                    cout << person << " продавец манго!" << endl;
                    return true;
                }
                else
                {
                    // Add all neighbors of the current person.
                    for (const auto &n : graph[person])
                        search_queue.push_back(n);
                    searched.push_back(person);
                }
            }
        }
        return false;
    };

    // Start the search from "вы".
    search("You");
}