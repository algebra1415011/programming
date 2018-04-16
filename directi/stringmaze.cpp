#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
bool check(int x, int y, int n, int m, char grid[128][128])
{
    if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] =='#')
        return false;
    return true;
}
 
bool find_word(char grid[128][128], int x, int y, int n, int m, char word[32], int counter)
{
    if(counter==strlen(word))
        return true;
    if(grid[x][y] == word[counter])
        counter++;
    else
        return false;
    char temp = grid[x][y];
    grid[x][y] = '#';
    bool ans = false;
    if(!ans&&check(x + 1, y, n, m, grid))
        ans = find_word(grid, x + 1, y, m, n, word, counter);
    if(!ans&&check(x - 1, y, n, m, grid))
        ans = find_word(grid, x - 1, y, m, n, word, counter);
    if(!ans&&check(x, y + 1, n, m, grid))
        ans = find_word(grid, x, y + 1, m, n, word, counter);
    if(!ans&&check(x, y - 1, n, m, grid))
        ans = find_word(grid, x, y - 1, m, n, word, counter);
    if(!ans&&check(x - 1, y - 1, n, m, grid))
        ans = find_word(grid, x - 1, y - 1, m, n, word, counter);
    if(!ans&&check(x + 1, y - 1, n, m, grid))
        ans = find_word(grid, x + 1, y - 1, m, n, word, counter);
    if(!ans&&check(x - 1, y + 1, n, m, grid))
        ans = find_word(grid, x - 1, y + 1, m, n, word, counter);
    if(!ans&&check(x + 1, y + 1, n, m, grid))
        ans = find_word(grid, x + 1, y + 1, m, n, word, counter);
    grid[x][y] = temp;
    return ans;
}
 
bool findWordInAGrid(char grid[128][128], int n, int m, char word[32])
{
    bool ans = false;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            {
                ans = find_word(grid, i, j, n, m, word, 0);
                if(ans)
                    return ans;
            }
    return false;
}
 
int main() {
    int m, n;
    char grid[128][128];
    int k;
    char word[32];
    int i, j;
 
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++) scanf("%s",grid[i]);
    scanf("%d",&k);
    while(k--) {
        scanf("%s",word);
        printf("%s\n",findWordInAGrid(grid, m, n, word) ? "true" : "false");
    }
    return 0;
}
 