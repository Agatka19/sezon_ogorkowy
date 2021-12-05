#include <bits/stdc++.h>
#include <iostream>
#include <cmath>

using namespace std;

int n, m, k;
int x_1, y_1, x_2, y_2;
int lenx, leny, lx, ly;
int po_y, po_x;

struct Q {
    int x_11, y_11, x_22, y_22;
};

Q q;
vector<Q> queries;

void build_query() {
    q.x_11 = x_1;
    q.y_11 = y_1;
    q.x_22 = x_2;
    q.y_22 = y_2;
    queries.push_back(q);
    lenx = x_2 - x_1 + 1;
    leny = y_2 - y_1 + 1;
    lx = log2(lenx);
    ly = log2(leny);
    po_y = pow(2, ly);
    po_x = pow(2, lx);
}

void read_query(int i) {
    x_1 = queries[i].x_11;
    y_1 = queries[i].y_11;
    x_2 = queries[i].x_22;
    y_2 = queries[i].y_22;
    lenx = x_2 - x_1 + 1;
    leny = y_2 - y_1 + 1;
    lx = log2(lenx);
    ly = log2(leny);
    po_y = pow(2, ly);
    po_x = pow(2, lx);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    vector<int> mins;
    int ln = log2(n);
    int lm = log2(m);
    int sparse[1 + ln][n][1 + lm][m];
    for (int ir = 0; ir < n; ++ir) {
        for (int ic = 0; ic < m; ++ic) {
            cin >> sparse[0][ir][0][ic];
        }
    }
    for (int ir = 0; ir < n; ++ir) {
        for (int jc = 1; jc <= log2(m); ++jc) {
            int po = pow(2, (jc - 1));
            for (int ic = 0; (ic + po) < m; ++ic) {
                sparse[0][ir][jc][ic] =
                        min(sparse[0][ir][jc - 1][ic], sparse[0][ir][jc - 1][ic + po]);
            }
        }
    }
    // building the sparse table for min
    for (int jr = 1; jr <= log2(n); ++jr) {
        int po = pow(2, jr - 1);
        for (int ir = 0; ir < n; ++ir) {
            for (int jc = 0; jc <= log2(m); ++jc) {
                for (int ic = 0; ic < m; ++ic) {
                    sparse[jr][ir][jc][ic] =
                            min(sparse[jr - 1][ir][jc][ic], sparse[jr - 1][ir + po][jc][ic]);
                }
            }
        }
    }

    for (int i = 0; i < k; ++i) {
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        build_query();
        int min1 = min(sparse[lx][x_1][ly][y_1], sparse[lx][x_1][ly][y_2 + 1 - po_y]);
        int min2 = min(sparse[lx][x_2 + 1 - po_x][ly][y_1], sparse[lx][x_2 + 1 - po_x][ly][y_2 + 1 - po_y]);
        mins.push_back(min(min1, min2));
    }

    ////////////////////////////////////////

    for (int ir = 0; ir < n; ++ir) {
        for (int jc = 1; jc <= log2(m); ++jc) {
            int po = pow(2, (jc - 1));
            for (int ic = 0; (ic + po) < m; ++ic) {
                sparse[0][ir][jc][ic] =
                        max(sparse[0][ir][jc - 1][ic], sparse[0][ir][jc - 1][ic + po]);
            }
        }
    }
    // building the sparse table for max
    for (int jr = 1; jr <= log2(n); ++jr) {
        int po = pow(2, jr - 1);
        for (int ir = 0; ir < n; ++ir) {
            for (int jc = 0; jc <= log2(m); ++jc) {
                for (int ic = 0; ic < m; ++ic) {
                    sparse[jr][ir][jc][ic] =
                            max(sparse[jr - 1][ir][jc][ic], sparse[jr - 1][ir + po][jc][ic]);
                }
            }
        }
    }
    for (int i = 0; i < k; ++i) {
        read_query(i);
        int max1 = max(sparse[lx][x_1][ly][y_1], sparse[lx][x_1][ly][y_2 + 1 - po_y]);
        int max2 = max(sparse[lx][x_2 + 1 - po_x][ly][y_1], sparse[lx][x_2 + 1 - po_x][ly][y_2 + 1 - po_y]);
        int m1 = max(max1, max2);
        cout << m1 - mins[i] << "\n";
    }
    return 0;
}