#include <cstdio>
#include <cstring>
#include <algorithm>

char s[1000010];
int ans[1000010];
int n;

using namespace std;

void z() {
    int left = 0;
    int right = 0;
    for (int i = 1; i < n; i++) {
        ans[i] = max(0, min(right - i, ans[i - left]));
        while (i + ans[i] < n && s[ans[i]] == s[i + ans[i]]) {
            ans[i]++;
        }
        if (i + ans[i] >= right) {
            left = i;
            right = i + ans[i];
        }
    }
}

int main() {
    freopen("z.in",  "r", stdin);
    freopen("z.out", "w", stdout);

    scanf("%s", s);
    n = strlen(s);
    z();

    for (int i = 1; i < n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}
