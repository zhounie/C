#include <bits/stdc++.h>
using namespace std;

class GaussElimination {
public:
    GaussElimination(int n) : n(n), a(n, vector<double>(n + 1)), ans(n) {}

    // 读入矩阵
    void Read() {
        printf("请输入线性方程组增广矩阵：\n");
        for (int i = 0; i < n; i++) {
            printf("请输入第 %d 行的系数和常数项，以空格分隔：", i + 1);
            for (int j = 0; j <= n; j++) {
                scanf("%lf", &a[i][j]);
            }
        }
    }

    // 高斯消元求解
    bool Solve() {
        int rank = 0;
        for (int i = 0; i < n; i++) {
            int pivot = -1;
            for (int j = rank; j < n; j++) { // 选主元
                if (fabs(a[j][i]) > 1e-8) {
                    pivot = j;
                    break;
                }
            }
            if (pivot == -1) continue; // 主元为 0，跳过
            if (pivot != rank) swap(a[pivot], a[rank]); // 将主元移至对角线上
            for (int j = rank + 1; j < n; j++) { // 消元
                double f = a[j][i] / a[rank][i];
                for (int k = i; k <= n; k++) {
                    a[j][k] -= f * a[rank][k];
                }
            }
            rank++;
        }

        if (rank < n) throw runtime_error("矩阵无唯一解"); // 矩阵秩小于行数，抛出异常

        for (int i = n - 1; i >= 0; i--) { // 回代求解
            ans[i] = a[i][n];
            for (int j = i + 1; j < n; j++) {
                ans[i] -= a[i][j] * ans[j];
            }
            if (fabs(a[i][i]) < 1e-8) throw runtime_error("计算过程中出现除以 0 的情况"); // 判断并处理除以 0 的情况
            ans[i] /= a[i][i];
        }
        return true;
    }

    // 输出解
    void Print() {
        printf("线性方程组的解为：");
        for (int i = 0; i < n; i++) {
            printf("%.2lf ", round(ans[i] * 100) / 100);
        }
        printf("\n");
    }

private:
    int n; // 矩阵的大小
    vector<vector<double>> a; // 增广矩阵
    vector<double> ans; // 解向量
};

int main() {
    int n;
    printf("请输入线性方程组的未知数个数：");
    scanf("%d", &n);

    GaussElimination ge(n); // 创建高斯消元对象
    try {
        ge.Read(); // 读入矩阵
        ge.Solve(); // 求解线性方程组
        ge.Print(); // 输出解向量
    } catch (exception& e) {
        printf("运行时错误：%s\n", e.what()); // 捕获和处理异常
    }
    return 0;
}