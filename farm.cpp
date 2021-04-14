#include <iostream>

using namespace std;

int main() {
    int a, b, n, w;
    cin >> a >> b >> n >> w;
    int min = a, max = b;
    if (a > b) { min = b; max = a;}
    int diff = max - min;

    if (a == b) cout << -1 << endl;
    else if (n % 2 == 0) {
        if ((a+b)*n/2 == w) cout << n/2 << " " << n/2 << endl;
        else if ((a+b)*n/2 < w) {
            int temp = (w - ((a+b)*n/2)) / diff;
            if (n/2-temp == 0 || n/2+temp == 0) cout << -1 << endl;
            else if (min == a) {
                if (a*(n/2-temp) + b*(n/2+temp) != w) cout << -1 << endl;
                else cout << n/2-temp << " " << n/2+temp << endl;
            } 
            else {
                if (a*(n/2+temp) + b*(n/2-temp) != w) cout << -1 << endl;
                else if (n/2-temp == 0 || n/2+temp == 0) cout << -1 << endl;
                else cout << n/2+temp << " " << n/2-temp << endl;
            }
        }
        else {
            int temp = (((a+b)*n/2) - w) / diff;
            if (n/2-temp == 0 || n/2+temp == 0) cout << -1 << endl;
            else if (min == a) {
                if (a*(n/2+temp) + b*(n/2-temp) != w) cout << -1 << endl;               
                else cout << n/2+temp << " " << n/2-temp << endl;
            }
            else {
                if (a*(n/2-temp) + b*(n/2+temp) != w) cout << -1 << endl;
                else cout << n/2-temp << " " << n/2+temp << endl;
            }
        }
    }
    else {
        if (a*(n/2+1) + b*(n/2) == w) cout << n/2+1 << " " << n/2 << endl;
        else if (a*(n/2) + b*(n/2+1) == w) cout << n/2 << " " << n/2+1 << endl;
        else if (a*(n/2+1) + b*(n/2) < w) {
            if (min == a) {
                int i=n/2+1, j=n/2;
                while (a*i + b*j < w && i > 1) { i--; j++; }
                if (a*i + b*j == w) cout << i << " " << j << endl;
                else cout << -1 << endl;
            }
            else {
                int i=n/2+1, j=n/2;
                while (a*i + b*j < w && j > 1) { i++; j--; }
                if (a*i + b*j == w) cout << i << " " << j << endl;
                else cout << -1 << endl;
            }
        }
        else {
            if (min == a) {
                int i=n/2+1, j=n/2;
                while (a*i + b*j > w && i > 1) { i++; j--; }
                if (a*i + b*j == w) cout << i << " " << j << endl;
                else cout << -1 << endl;
            }
            else {
                int i=n/2+1, j=n/2;
                while (a*i + b*j > w && j > 1) { i--; j++; }
                if (a*i + b*j == w) cout << i << " " << j << endl;
                else cout << -1 << endl;
            }
        }
    }
    
}