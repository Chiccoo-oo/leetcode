#include <bits/stdc++.h>
using namespace std;

int main()
{
    string patch, designerWords;
    cin >> patch >> designerWords;

    int patchLen = patch.length();
    int wordsLen = designerWords.length();

    vector<int> bestSequence; // Store the best (lexicographically smallest) sequence
    bool possible = false;

    // Try all possible sequences by considering multiple patch applications
    for (int start = 0; start < wordsLen; start++)
    {
        vector<int> sequence;           // Current sequence of indices
        string current = designerWords; // Copy of designerWords to modify
        int pos = 0;                    // Start from the beginning to build sequence
        bool canForm = true;
        int lastPos = -patchLen - 1; // Track the last position used to avoid overlap

        while (pos < wordsLen && canForm)
        {
            // Find the next position to apply patch, starting from or after 'pos'
            bool found = false;
            int nextPos = pos;

            while (nextPos < wordsLen)
            {
                // Try to match patch starting at nextPos
                bool match = true;
                int j = 0;       // Position in patch
                int k = nextPos; // Position in current

                if (k - lastPos < 0) // Allow minimal overlap for flexibility
                {
                    match = false;
                }
                else
                {
                    // Check if patch can match any prefix or full string starting here
                    while (j < patchLen && k < wordsLen)
                    {
                        if (patch[j] != current[k])
                        {
                            match = false;
                            break;
                        }
                        j++;
                        k++;
                    }
                    // If patch matches fully
                    if (j == patchLen && k <= wordsLen)
                    {
                        found = true;
                        sequence.push_back(nextPos); // Add this starting position to sequence
                        lastPos = nextPos;           // Update last position
                        pos = k;                     // Move to next position after match
                        // Remove matched portion from current for next iteration
                        current = current.substr(0, nextPos) + string(patchLen, ' ') + current.substr(nextPos + patchLen);
                        break;
                    }
                }
                nextPos++;
            }

            if (!found)
            {
                canForm = false;
                break;
            }
        }

        if (canForm && pos == wordsLen) // Successfully formed designerWords
        {
            possible = true;
            // Update bestSequence if this is lexicographically smaller
            if (bestSequence.empty() || sequence < bestSequence)
            {
                bestSequence = sequence;
            }
        }
    }

    // Output the result
    if (possible)
    {
        for (size_t i = 0; i < bestSequence.size(); i++)
        {
            cout << bestSequence[i];
            if (i < bestSequence.size() - 1)
                cout << " ";
        }
    }
    else
    {
        cout << "-1";
    }

    return 0;
}