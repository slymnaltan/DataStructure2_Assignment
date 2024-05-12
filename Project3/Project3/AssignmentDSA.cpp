#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;
/*HW - 1 GREEDY ALGORITM*/
//struct Meeting {
//    int start;
//    int end;
//};
//
//bool compareMeetings(const Meeting& a, const Meeting& b) {
//    return a.end < b.end;
//}
//
//
//int maxMeetings(int N, vector<int>& start, vector<int>& end) {
//    vector<Meeting> meetings(N);
//    for (int i = 0; i < N; ++i) {
//        meetings[i].start = start[i];
//        meetings[i].end = end[i];
//    }
//
//    sort(meetings.begin(), meetings.end(), compareMeetings);
//
//    vector<Meeting> selectedMeetings;
//    selectedMeetings.push_back(meetings[0]);
//    int finishTime = meetings[0].end;
//
//    for (int i = 1; i < N; ++i) {
//        if (meetings[i].start >= finishTime) {
//            selectedMeetings.push_back(meetings[i]);
//            finishTime = meetings[i].end;
//        }
//    }
//
//    return selectedMeetings.size();
//}
//
//int main() {
//    int N = 6;
//    vector<int> start = { 1, 3, 0, 5, 8, 5 };
//    vector<int> end = { 2, 4, 6, 7, 9, 9 };
//    cout << maxMeetings(N, start, end) << endl; 
//    return 0;
//}


/* HW-2 GREEDY ALGORITM*/
//struct Job {
//    int id;
//    int deadline;
//    int profit;
//};
//
//bool compareJobs(const Job& a, const Job& b) {
//    return a.profit > b.profit;
//}
//
//pair<int, int> maxProfit(int N, vector<Job>& jobs) {
//    sort(jobs.begin(), jobs.end(), compareJobs);
//
//    vector<bool> slot(N, false);
//
//    int totalProfit = 0;
//    int jobsDone = 0;
//
//    for (const Job& job : jobs) {
//        for (int i = min(N, job.deadline) - 1; i >= 0; --i) {
//            if (!slot[i]) {
//                slot[i] = true;
//                totalProfit += job.profit;
//                ++jobsDone;
//                break;
//            }
//        }
//    }
//
//    return make_pair(jobsDone, totalProfit);
//}
//
//int main() {
//    int N = 4;
//    vector<Job> jobs = { {1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30} };
//    pair<int, int> result = maxProfit(N, jobs);
//    cout << result.first << " " << result.second << endl;
//    return 0;
//}


/*HW - 3 RETURN DYNAMIC PROGRAM HW-2 */
//struct Job {
//    int id;
//    int deadline;
//    int profit;
//};
//
//bool compareJobs(const Job& a, const Job& b) {
//    return a.deadline < b.deadline;
//}
//
//pair<int, int> maxProfitDP(int N, vector<Job>& jobs) {
//    sort(jobs.begin(), jobs.end(), compareJobs);
//
//    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
//
//    for (int i = 1; i <= N; ++i) {
//        for (int j = 1; j <= N; ++j) {
//            if (jobs[i - 1].deadline >= j) {
//                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + jobs[i - 1].profit);
//            }
//            else {
//                dp[i][j] = dp[i - 1][j];
//            }
//        }
//    }
//
//    int maxProfit = 0;
//    int jobsDone = 0;
//    for (int i = 1; i <= N; ++i) {
//        maxProfit = max(maxProfit, dp[N][i]);
//        if (dp[N][i] > 0)
//            jobsDone++;
//    }
//
//    return make_pair(jobsDone, maxProfit);
//}
//
//int main() {
//    int N = 4;
//    vector<Job> jobs = { {1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30} };
//    pair<int, int> result = maxProfitDP(N, jobs);
//    cout << result.first << " " << result.second << endl;
//    return 0;
//}


/*HW - 4 GREEDY ALGORITM */
//struct Pair {
//    int first;
//    int second;
//};
//
//bool comparePairs(const Pair& a, const Pair& b) {
//    return a.second < b.second;
//}
//
//int longestChain(int N, vector<Pair>& pairs) {
//    sort(pairs.begin(), pairs.end(), comparePairs);
//
//    int chainLength = 0;
//    int lastEnd = INT_MIN;
//
//    for (const Pair& p : pairs) {
//        if (p.first > lastEnd) {
//            ++chainLength;
//            lastEnd = p.second;
//        }
//    }
//
//    return chainLength;
//}
//
//int main() {
//    int N = 5;
//    vector<Pair> pairs = { {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };
//    cout << longestChain(N, pairs) << endl;
//    return 0;
//}


/*HW - 5 RETURN DYNAMIC PROGRAM HW-4*/
//struct Pair {
//    int first;
//    int second;
//};
//
//bool comparePairs(const Pair& a, const Pair& b) {
//    return a.second < b.second;
//}
//
//int longestChainDP(int N, vector<Pair>& pairs) {
//    sort(pairs.begin(), pairs.end(), comparePairs);
//
//    vector<int> dp(N, 1);
//
//    for (int i = 1; i < N; ++i) {
//        for (int j = 0; j < i; ++j) {
//            if (pairs[i].first > pairs[j].second && dp[i] < dp[j] + 1) {
//                dp[i] = dp[j] + 1;
//            }
//        }
//    }
//
//    int maxLength = 0;
//    for (int i = 0; i < N; ++i) {
//        maxLength = max(maxLength, dp[i]);
//    }
//
//    return maxLength;
//}
//
//int main() {
//    int N = 5;
//    vector<Pair> pairs = { {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };
//    cout << longestChainDP(N, pairs) << endl;
//    return 0;
//}


/*HW - 6  BACKTRACKING*/
//bool isValidMove(int x, int y, int N, vector<vector<int>>& matrix, vector<vector<bool>>& visited) {
//    return (x >= 0 && x < N && y >= 0 && y < N && matrix[x][y] == 1 && !visited[x][y]);
//}
//
//void explorePaths(int x, int y, int N, vector<vector<int>>& matrix, vector<vector<bool>>& visited, string& path, vector<string>& result) {
//    if (x == N - 1 && y == N - 1) {
//        result.push_back(path);
//        return;
//    }
//
//    visited[x][y] = true;
//
//    if (isValidMove(x + 1, y, N, matrix, visited)) {
//        path.push_back('D');
//        explorePaths(x + 1, y, N, matrix, visited, path, result);
//        path.pop_back();
//    }
//    if (isValidMove(x - 1, y, N, matrix, visited)) {
//        path.push_back('U');
//        explorePaths(x - 1, y, N, matrix, visited, path, result);
//        path.pop_back();
//    }
//    if (isValidMove(x, y + 1, N, matrix, visited)) {
//        path.push_back('R');
//        explorePaths(x, y + 1, N, matrix, visited, path, result);
//        path.pop_back();
//    }
//    if (isValidMove(x, y - 1, N, matrix, visited)) {
//        path.push_back('L');
//        explorePaths(x, y - 1, N, matrix, visited, path, result);
//        path.pop_back();
//    }
//
//    visited[x][y] = false;
//}
//
//vector<string> findAllPaths(int N, vector<vector<int>>& matrix) {
//    vector<string> result;
//    if (matrix[0][0] == 0 || matrix[N - 1][N - 1] == 0) {
//        result.push_back("-");
//        return result;
//    }
//
//    vector<vector<bool>> visited(N, vector<bool>(N, false));
//    string path;
//    explorePaths(0, 0, N, matrix, visited, path, result);
//
//    return result;
//}
//
//int main() {
//    int N = 4;
//    vector<vector<int>> matrix = { {1, 0, 0, 0},
//                                   {1, 1, 0, 1},
//                                   {1, 1, 0, 0},
//                                   {0, 1, 1, 1} };
//    vector<string> paths = findAllPaths(N, matrix);
//    for (const string& path : paths) {
//        cout << path << " ";
//    }
//    cout << endl;
//    return 0;
//}


/*HW - 7  BACKTRACKING MAP COLORING*/
//bool isSafe(int vertex, int color, vector<vector<int>>& graph, vector<int>& colors, int N) {
//    for (int i = 0; i < N; ++i) {
//        if (graph[vertex][i] && colors[i] == color) {
//            return false;
//        }
//    }
//    return true;
//}
//
//bool graphColoringUtil(int vertex, int M, vector<vector<int>>& graph, vector<int>& colors, int N) {
//    if (vertex == N) {
//        return true;
//    }
//
//    for (int color = 1; color <= M; ++color) {
//        if (isSafe(vertex, color, graph, colors, N)) {
//            colors[vertex] = color;
//            if (graphColoringUtil(vertex + 1, M, graph, colors, N)) {
//                return true;
//            }
//            colors[vertex] = 0;
//        }
//    }
//    return false;
//}
//
//int graphColoring(int N, int M, int E, vector<pair<int, int>>& edges) {
//    vector<vector<int>> graph(N, vector<int>(N, 0));
//    for (int i = 0; i < E; ++i) {
//        int u = edges[i].first;
//        int v = edges[i].second;
//        graph[u][v] = 1;
//        graph[v][u] = 1;
//    }
//
//    vector<int> colors(N, 0);
//
//    if (graphColoringUtil(0, M, graph, colors, N)) {
//        return 1;
//    }
//    else {
//        return 0;
//    }
//}
//
//int main() {
//    int N = 4;
//    int M = 3;
//    int E = 5;
//    vector<pair<int, int>> edges = { {0,1},{1,2},{2,3},{3,0},{0,2} };
//    cout << graphColoring(N, M, E, edges) << endl;
//
//    return 0;
//}


/*HW - 8  BACKTRACKING*/
//bool isValidSegment(const string& segment) {
//    if (segment.empty() || segment.size() > 3 || (segment.size() > 1 && segment[0] == '0')) {
//        return false;
//    }
//    int num = stoi(segment);
//    return num >= 0 && num <= 255;
//}
//
//void generateAddresses(string& s, int start, int part, string& current, vector<string>& result) {
//    if (part == 4 && start == s.size()) {
//        result.push_back(current);
//        return;
//    }
//    if (part == 4 || start == s.size()) {
//        return;
//    }
//
//    for (int i = 1; i <= 3 && start + i <= s.size(); ++i) {
//        string segment = s.substr(start, i);
//        if (isValidSegment(segment)) {
//            if (part < 3) {
//                segment += ".";
//            }
//            current += segment;
//            generateAddresses(s, start + i, part + 1, current, result);
//            for (int j = 0; j < i; ++j) {
//                current.pop_back();
//            }
//        }
//    }
//}
//
//vector<string> genIp(string& s) {
//    vector<string> result;
//    if (s.size() < 4 || s.size() > 12) {
//        return result;
//    }
//
//    string current;
//    generateAddresses(s, 0, 0, current, result);
//    return result;
//}
//
//int main() {
//    string S = "1111";
//    vector<string> addresses = genIp(S);
//    for (const string& address : addresses) {
//        cout << address << endl;
//    }
//
//    return 0;
//}


/*HW - 9 BACKTRACKING*/
//class TrieNode {
//public:
//    vector<TrieNode*> children;
//    bool isEndOfWord;
//
//    TrieNode() : children(26, nullptr), isEndOfWord(false) {}
//};
//
//class Trie {
//public:
//    TrieNode* root;
//
//    Trie() {
//        root = new TrieNode();
//    }
//
//    void insert(const string& word) {
//        TrieNode* current = root;
//        for (char c : word) {
//            int index = c - 'A';
//            if (!current->children[index]) {
//                current->children[index] = new TrieNode();
//            }
//            current = current->children[index];
//        }
//        current->isEndOfWord = true;
//    }
//};
//
//bool isWordInDictionary(const string& word, Trie& dictionary) {
//    TrieNode* current = dictionary.root;
//    for (char c : word) {
//        int index = c - 'A';
//        if (!current->children[index]) {
//            return false;
//        }
//        current = current->children[index];
//    }
//    return current && current->isEndOfWord;
//}
//
//void findWordsDFS(int i, int j, int R, int C, vector<vector<char>>& board, Trie& dictionary, string& currentWord, unordered_set<string>& foundWords, vector<vector<bool>>& visited) {
//    if (i < 0 || j < 0 || i >= R || j >= C || visited[i][j]) {
//        return;
//    }
//
//    currentWord.push_back(board[i][j]);
//    visited[i][j] = true;
//
//    if (isWordInDictionary(currentWord, dictionary)) {
//        foundWords.insert(currentWord);
//    }
//
//    for (int x = -1; x <= 1; ++x) {
//        for (int y = -1; y <= 1; ++y) {
//            findWordsDFS(i + x, j + y, R, C, board, dictionary, currentWord, foundWords, visited);
//        }
//    }
//
//    currentWord.pop_back();
//    visited[i][j] = false;
//}
//
//vector<string> findWords(vector<string>& dictionary, int R, int C, vector<vector<char>>& board) {
//    Trie trie;
//    for (const string& word : dictionary) {
//        trie.insert(word);
//    }
//
//    unordered_set<string> foundWords;
//    vector<vector<bool>> visited(R, vector<bool>(C, false));
//    string currentWord;
//
//    for (int i = 0; i < R; ++i) {
//        for (int j = 0; j < C; ++j) {
//            findWordsDFS(i, j, R, C, board, trie, currentWord, foundWords, visited);
//        }
//    }
//
//    return vector<string>(foundWords.begin(), foundWords.end());
//}
//
//int main() {
//    vector<string> dictionary = { "GEEKS","FOR","QUIZ","GO" };
//    int R = 3, C = 3;
//    vector<vector<char>> board = { {'G','I','Z'},{'U','E','K'},{'Q','S','E'} };
//    vector<string> words = findWords(dictionary, R, C, board);
//    for (const string& word : words) {
//        cout << word << " ";
//    }
//    cout << endl;
//    return 0;
//}


/*HW - 10  DIVIDE AND CONQUER*/
//int kthElement(vector<int>& arr1, vector<int>& arr2, int k) {
//    int N = arr1.size();
//    int M = arr2.size();
//    int i = 0, j = 0;
//
//    while (i < N && j < M) {
//        if (arr1[i] < arr2[j]) {
//            k--;
//            if (k == 0) {
//                return arr1[i];
//            }
//            i++;
//        }
//        else {
//            k--;
//            if (k == 0) {
//                return arr2[j];
//            }
//            j++;
//        }
//    }
//
//    while (i < N) {
//        k--;
//        if (k == 0) {
//            return arr1[i];
//        }
//        i++;
//    }
//
//    while (j < M) {
//        k--;
//        if (k == 0) {
//            return arr2[j];
//        }
//        j++;
//    }
//
//    return -1; 
//}
//
//int main() {
//    vector<int> arr1 = { 2, 3, 6, 7, 9 };
//    vector<int> arr2 = { 1, 4, 8, 10 };
//    int k = 5;
//    cout << kthElement(arr1, arr2, k) << endl; 
//    return 0;
//}


/* HW - 11 */
//bool isValidAllocation(vector<int>& books, int students, int maxPages) {
//    int count = 1;
//    int pages = 0;
//    for (int i = 0; i < books.size(); ++i) {
//        pages += books[i];
//        if (pages > maxPages) {
//            count++;
//            pages = books[i];
//        }
//        if (count > students) {
//            return false;
//        }
//    }
//    return true;
//}
//
//int findMinSumOfMaxPages(vector<int>& books, int students) {
//    if (students > books.size()) {
//        return -1;
//    }
//
//    int totalPages = 0;
//    int maxPages = 0;
//    for (int pages : books) {
//        totalPages += pages;
//        maxPages = max(maxPages, pages);
//    }
//
//    int low = maxPages;
//    int high = totalPages;
//    int result = -1;
//
//    while (low <= high) {
//        int mid = low + (high - low) / 2;
//        if (isValidAllocation(books, students, mid)) {
//            result = mid;
//            high = mid - 1;
//        }
//        else {
//            low = mid + 1;
//        }
//    }
//
//    return result;
//}
//
//int main() {
//    vector<int> books = { 12, 34, 67, 90 };
//    int students = 2;
//    cout << findMinSumOfMaxPages(books, students) << endl; 
//    return 0;
//}


/* HW - 12 DIVIDE AND CONQUER */
//int countSpecialSequences(int m, int n) {
//    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
//
//    for (int j = 1; j <= m; ++j) {
//        dp[1][j] = 1;
//    }
//
//    for (int i = 2; i <= n; ++i) {
//        for (int j = 1; j <= m; ++j) {
//            for (int k = j / 2; k > 0; --k) {
//                dp[i][j] += dp[i - 1][k];
//            }
//        }
//    }
//
//    int totalCount = 0;
//    for (int j = 1; j <= m; ++j) {
//        totalCount += dp[n][j];
//    }
//
//    return totalCount;
//}
//
//int main() {
//    int m1 = 10, n1 = 4;
//    cout << "For m = " << m1 << ", n = " << n1 << ", Special Sequences: " << countSpecialSequences(m1, n1) << endl;
//
//    return 0;
//}

