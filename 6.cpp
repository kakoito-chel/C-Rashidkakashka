#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    const int MAX_LINES = 100;
    const int MAX_WORDS = 50;

    string text[MAX_LINES];
    int lineCount = 0;
    int upperCount = 0;

    cout << "Введите строки (для окончания ввода введите stop):\n";

    // Ввод строк
    while (true) {
        getline(cin, text[lineCount]);

        if (text[lineCount] == "stop")
            break;

        // Подсчёт заглавных букв
        for (int i = 0; i < text[lineCount].length(); i++) {
            if (isupper(text[lineCount][i]))
                upperCount++;
        }

        lineCount++;
    }

    cout << "\nКоличество заглавных символов во всём тексте: "
         << upperCount << endl;

    cout << "\n--- Анализ строк ---\n";

    // Обработка каждой строки
    for (int i = 0; i < lineCount; i++) {
        string words[MAX_WORDS];
        int wordCount = 0;
        string s = text[i];
        string current = "";

        // Разбиение строки на слова
        for (int j = 0; j <= s.length(); j++) {
            if (j < s.length() && !isspace(s[j])) {
                current += s[j];
            } else if (!current.empty()) {
                words[wordCount++] = current;
                current = "";
            }
        }

        // Поиск самого короткого и длинного слова
        int minLen = words[0].length();
        int maxLen = words[0].length();

        for (int j = 1; j < wordCount; j++) {
            if (words[j].length() < minLen)
                minLen = words[j].length();
            if (words[j].length() > maxLen)
                maxLen = words[j].length();
        }

        cout << "\nСтрока " << i + 1 << ":\n";
        cout << "Самое короткое слово: ";
        for (int j = 0; j < wordCount; j++)
            if (words[j].length() == minLen)
                cout << words[j] << " ";

        cout << "\nСамое длинное слово: ";
        for (int j = 0; j < wordCount; j++)
            if (words[j].length() == maxLen)
                cout << words[j] << " ";

        cout << "\n";

        // Сортировка слов по длине (пузырёк)
        for (int a = 0; a < wordCount - 1; a++) {
            for (int b = 0; b < wordCount - 1 - a; b++) {
                if (words[b].length() > words[b + 1].length()) {
                    string temp = words[b];
                    words[b] = words[b + 1];
                    words[b + 1] = temp;
                }
            }
        }

        // Вывод отформатированной строки
        cout << "Отформатированная строка:\n";
        for (int j = 0; j < wordCount; j++) {
            cout << words[j];
            for (int k = words[j].length(); k < maxLen; k++)
                cout << ' ';
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}
