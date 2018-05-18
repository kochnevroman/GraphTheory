#include <iostream>
#include <vector>

using namespace std;

int compute(int length, vector<int>& arrayOfLengths)
{
    int result = 0;
    for (int i(0); i < arrayOfLengths.size(); i += 1) {
        result += arrayOfLengths[i] / length;
    }
    return result;
}

void binarySearch(int K, vector<int>& arrayOfLengths)
{
    int l = 0, r = 1e8 + 1;
    int length = 0;
    while (l <= r)
    {
        int m = (l + r) >> 1;
        if (m == 0) {
        l = m + 1;
        continue;
        }

        int temporary = compute(m, arrayOfLengths);
        if (temporary < K) {
        r = m - 1;
        }

        else if (temporary >= K) {
        l = m + 1;
        length = max(length, m);
        }
    }

    cout << length;
}
int main()
{
    int N, K;
    vector<int> arrayOfLengths;

    cin >> N >> K;
    arrayOfLengths.resize(N);

    for (int i(0); i < N; i += 1) {
        cin >> arrayOfLengths[i];
    }

    binarySearch(K, arrayOfLengths);

    return 0;
}