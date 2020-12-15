#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;

int a[maxn], b[maxn], res[maxn];

string add(string s1, string s2) {  // under condition: s1,s2>=0
    // 初始化部分
    int n = s1.length(), m = s2.length();
    for (int i = 0; i < n; i ++) a[i] = s1[n-1-i] - '0';
    for (int i = 0; i < m; i ++) b[i] = s2[m-1-i] - '0';
    int len = max(n, m) + 1;
    for (int i = n; i < len; i ++) a[i] = 0;
    for (int i = m; i < len; i ++) b[i] = 0;
    for (int i = 0; i < len; i ++) res[i] = 0;
    // 处理部分
    for (int i = 0; i < len; i ++) {
        res[i] += a[i] + b[i];
        if (res[i] >= 10) {
            res[i+1] += res[i] / 10;
            res[i] %= 10;
        }
    }
    // 返回部分
    int i = len-1;
    while (res[i] == 0 && i > 0) i --;
    string s = "";
    for (; i >= 0; i --) {
        char c = (char) (res[i] + '0');
        s += c;
    }
    return s;
}

string sub(string s1, string s2) {  // under condition: s1>=s2>=0
    // 初始化部分
    int n = s1.length(), m = s2.length();
    for (int i = 0; i < n; i ++) a[i] = s1[n-1-i] - '0';
    for (int i = 0; i < m; i ++) b[i] = s2[m-1-i] - '0';
    int len = max(n, m);
    for (int i = n; i < len; i ++) a[i] = 0;
    for (int i = m; i < len; i ++) b[i] = 0;
    for (int i = 0; i < len; i ++) res[i] = 0;
    // 处理部分
    for (int i = 0; i < len; i ++) {
        res[i] += a[i] - b[i];
        if (res[i] < 0) {
            res[i+1] --;
            res[i] += 10;
        }
    }
    // 返回部分
    int i = len-1;
    while (res[i] == 0 && i > 0) i --;
    string s = "";
    for (; i >= 0; i --) {
        char c = (char) (res[i] + '0');
        s += c;
    }
    return s;
}

bool cmp(string s1, string s2) {    // under condition: s1,s2 >= 0
    int n = s1.length(), m = s2.length();
    int i;
    for (i = 0; i < n-1 && s1[i] == '0'; i ++);
    s1 = s1.substr(i);
    for (i = 0; i < m-1 && s2[i] == '0'; i ++);
    s2 = s2.substr(i);
    if (s1.length() != s2.length()) return s1.length() < s2.length();
    return s1 < s2;
}

string Add(string s1, string s2) {
    if (s1[0] == '-' && s2[0] == '-') {
        return "-" + add(s1.substr(1), s2.substr(1));
    }
    else if (s1[0] == '-') {
        s1 = s1.substr(1);
        if (cmp(s1, s2) == true) {
            return sub(s2, s1);
        } else {
            return "-" + sub(s1, s2);
        }
    }
    else if (s2[0] == '-') {
        s2 = s2.substr(1);
        if (cmp(s1, s2) == true) {
            return "-" + sub(s2, s1);
        } else {
            return sub(s1, s2);
        }
    }
    else {
        return add(s1, s2);
    }
}

string Sub(string s1, string s2) {
    if (s2[0] == '-') {
        s2 = s2.substr(1);
        return Add(s1, s2);
    }
    else {
        return Add(s1, "-" + s2);
    }
}

string multi(string s1, string s2) {    // under condition: s1,s2>=0
    // 初始化部分
    int n = s1.length(), m = s2.length();
    for (int i = 0; i < n; i ++) a[i] = s1[n-1-i] - '0';
    for (int i = 0; i < m; i ++) b[i] = s2[m-1-i] - '0';
    int len = n + m;
    for (int i = n; i < len; i ++) a[i] = 0;
    for (int i = m; i < len; i ++) b[i] = 0;
    for (int i = 0; i < len; i ++) res[i] = 0;
    // 处理部分
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
            res[i+j] += a[i] * b[j];
    for (int i = 0; i < len; i ++) {
        res[i+1] += res[i] / 10;
        res[i] %= 10;
    }
    // 返回部分
    int i = len-1;
    while (res[i] == 0 && i > 0) i --;
    string s = "";
    for (; i >= 0; i --) {
        char c = (char) (res[i] + '0');
        s += c;
    }
    return s;
}

pair<string, string> divide(string s1, string s2) { // under condition: s1>=0,s2>0
    string s = "", t = "";
    int n = s1.length(), m = s2.length();
    bool flag = false;
    for (int i = 0; i < n; i ++) {
        s += s1[i];
        int num = 0;
        while (cmp(s, s2) == false) {
            num ++;
            s = sub(s, s2);
        }
        if (num > 0) {
            flag = true;
            char c = (char)(num + '0');
            t += c;
        }
        else if (flag) {
            t += '0';
        }
    }
    if (t.length() == 0) t = "0";
    while (s[0] == '0' && s.length() > 1) s = s.substr(1);
    return make_pair(t, s);
}

string s1, s2;

int main() {
    while (cin >> s1 >> s2) {
        cout << "add:\t" << Add(s1, s2) << endl;
        cout << "sub:\t" << Sub(s1, s2) << endl;
        cout << "multi:\t" << multi(s1, s2) << endl;
        pair<string, string> divide_pair = divide(s1, s2);
        cout << "divide:\t" << divide_pair.first << " ...... " << divide_pair.second << endl;
    }
    return 0;
}