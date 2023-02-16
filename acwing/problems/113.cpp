// Forward declaration of compare API.
// bool compare(int a, int b);
// return bool means whether a is less than b.
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> tmp;
    void merge_sort(vector<int>& ans, int l, int r) {
        if(l >= r) return;
        int mid = l + r >> 1;
        merge_sort(ans, l, mid);
        merge_sort(ans, mid+1, r);
        int i = l, j = mid + 1, k = 0;
        while(i <= mid && j <= r)
        {
            if(compare(ans[i], ans[j])) tmp[k++] = ans[i++];
            else tmp[k++] = ans[j++];
        }
        while(i <= mid) tmp[k++] = ans[i++];
        while(j <= r) tmp[k++] = ans[j++];
        for(int i=l, j=0;i<=r;i++, j++) ans[i] = tmp[j];
    };
    vector<int> specialSort(int N) {
        vector<int> ans(N);
        tmp.resize(N);
        for(int i=0;i<N;i++) ans[i] = i + 1;
        merge_sort(ans, 0, N-1);
        return ans;
    }
};
