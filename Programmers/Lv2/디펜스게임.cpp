#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    std::multiset<int> card;
    for (int i = 0; i < enemy.size(); ++i)
    {
        if (k > 0)
        {
            k--;
            card.insert(enemy[i]);
        }
        else
        {
            if (enemy[i] > *card.begin())
            {
                n -= *card.begin();
                card.erase(card.begin());
                card.insert(enemy[i]);
            }
            else
            {
                n -= enemy[i];
            }

            if (n < 0)
            {
                break;
            }
        }
        answer++;
    }
    return answer;

}