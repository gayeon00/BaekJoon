#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    for(long long i = left; i <= right; i++)
    {
        long long quotient = i / n;
        long long remainder = i % n;

        if(quotient < remainder)
        {
            answer.push_back(remainder + 1);
        }
        else
        {
            answer.push_back(quotient + 1);
        }
    }

    return answer;
}