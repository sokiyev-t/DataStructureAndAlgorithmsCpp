#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <algorithm>

namespace fs = std::filesystem;

void printNames(const fs::path &dirPath)
{
    std::vector<fs::directory_entry> entries;

    // Собираем все записи в текущей папке
    for (const auto &entry : fs::directory_iterator(dirPath))
    {
        entries.push_back(entry);
    }

    // Сортировка по имени
    std::sort(entries.begin(), entries.end(), [](const auto &a, const auto &b)
              { return a.path().filename().string() < b.path().filename().string(); });

    for (const auto &entry : entries)
    {
        if (fs::is_regular_file(entry.path()))
        {
            std::cout << entry.path().filename().string() << std::endl;
        }
        else if (fs::is_directory(entry.path()))
        {
            printNames(entry.path()); // рекурсивный вызов
        }
    }
}

int main()
{
    printNames("/Users/temursokiev/Documents/"); // начальная папка
    return 0;
}