
public class Test {

    /**
     * @param a 结点不被匹配的概率，下标为 [0, n)，n为数据量（结点数）
     * @param b 结点被匹配的概率，下标为 [1, n]
     * @param m i到j的最优平均检索次数，也就是平均最优搜索值
     * @param s 保存i到j的最优根节点，就是确定i到j把哪一个结点作为根结点最优
     * @param w 区间[i, j]之间所有结点和空隙的命中概率。公式为：w[i][j] = a[i-1]+b[i]+...+b[j]+a[j]
     */
    public static void optimalBinarySearchTree(float[] a, float[] b, float[][] m, int[][] s, float[][] w) {
        // 数据个数，即结点个数
        int n = a.length - 1;
        // 赋初始值
        for (int i = 0; i <= n; i++) {
            /*
            这个初始值之后会被用到。
            这里只有a[i]，是因为大多数情况下a都会比b多一个元素，
            比如w[i][j] = a[i-1] + b[i] + a[i] + ... + b[j] + a[j]，
            可以看到除了第一个a[i-1]，其余都可以在一个for循环中相加得到
            此外，我们也可以发现w[i][j]对应a[i-1]，所以下方，下标也是错开的
            */
            w[i + 1][i] = a[i];
            m[i + 1][i] = 0;
        }

        // r表示[i,j]区间的长度
        for (int r = 0; r < n; r++) {
            /*
                下方的for循环中，r表示[i,j]区间的长度，i,j关系对应如下：
                [1,1] [2,2] ... [n,n]
                [1,2] [2,3] ... [n-1,n]
                [1,3] [2,4] ... [n-2,n]
                ...
             */
            for (int i = 1; i <= n - r; i++) {
                int j = i + r;
                /*
                w的递推公式为：w[i][j] = a[i-1]+b[i]+...+b[j]+a[j] = w[i][j-1] + b[j] + a[j]
                当r=0时，
                    j=i，则w[i][i-1]的值为0，其初始值已经在上方给出
                    所以当r=0时，w[i][j]=w[i][i]=a[i-1]+b[i]+a[i]
                当r=1时，
                    w[i][j] = w[i][i+1] = w[i][i] + a[i+1] + b[i+1]
                                        = a[i-1] + b[i] + a[i] +  b[i+1] + a[i+1]
                    也就是在w[i][i]的基础上加上新增的a和b，
                    这样子就把[i,i+1]这个区间的概率都加进来了
                 */
                w[i][j] = w[i][j - 1] + a[j] + b[j];
                // 这里先计算出一个值来，后续可以用于找出最小值。不然的话，数组元素默认值为0，不好比较
                m[i][j] = m[i][i - 1] + m[i + 1][j];
                s[i][j] = i;

                // 上面的操作是针对[i][j]的，下面的操作都是发送在[i, j]区间内的

                // k表示令第k个结点作为根节点。
                // 在for循环中，要求以k为根节点的最优比较次数
                for (int k = i + 1; k <= j; k++) {
                    /*
                    m[i][j] = min{ m[i][k-1] + m[k+1][j] + w[i][j] } (i <= k <= j)
                    每次都要+w[i][j]是因为：
                        因为在对左右子问题进行求解后，并上新的根结点x_k时，
                        左右子树的结点的深度都会增加1。而此时，对子树的每个结点的影响，
                        就是每个子树的比较次数都会增加1，那么就相当于概率加了一次。
                        而每个结点的概率都加1，再加上新增的根节点的概率，合起来就相当于加了一个w[i][j]

                    上式又可推导出
                    m[i][j] = w[i][j] + min(m[i][k-1] + m[k+1][j])  (1 <= k <= j)
                     */
                    // 下方先求出min(m[i][k-1] + m[k+1][j])，得到一个min值
                    float min = m[i][k - 1] + m[k + 1][j];
                    if (min < m[i][j]) {
                        m[i][j] = min;
                        // 保存最优的根节点方案
                        s[i][j] = k;
                    }
                    // min值再加上w，得到m[i][j]
                    m[i][j] += w[i][j];
                }
            }
        }
    }

    public static void optimalBinarySearchTree(float[] a, float[] b) {
        if (a.length == b.length + 1) {
            float[] b2 = new float[b.length + 1];
            System.arraycopy(b, 0, b2, 1, b.length);
            b = b2;
        }
        int n = b.length;
        float[][] m = new float[n + 1][n + 1];
        int[][] s = new int[n + 1][n + 1];
        float[][] w = new float[n + 1][n + 1];
        optimalBinarySearchTree(a, b, m, s, w);
        display(m);
        display(s);
        display(w);
    }


    public static void main(String[] args) {
        float[] b = {0.1F, 0.3F, 0.1F, 0.2F, 0.1F};
        float[] a = {0.04F, 0.02F, 0.02F, 0.05F, 0.06F, 0.01F};
        optimalBinarySearchTree(a, b);
    }

    public static <T> void display(float[][] arr) {
        for (float[] ts : arr) {
            for (float t : ts) {
                System.out.print(t + "\t");
            }
            System.out.println();
        }
        System.out.println();
    }

    public static <T> void display(int[][] arr) {
        for (int[] ts : arr) {
            for (int t : ts) {
                System.out.print(t + " ");
            }
            System.out.println();
        }
        System.out.println();
    }
}


