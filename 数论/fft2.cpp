namespace FFT {
#define O (262200*2)
    struct Comp {
        double Re, Im;
        inline Comp operator +(const Comp& _)const {
            return (Comp) { Re + _.Re, Im + _.Im };
        }
        inline Comp operator -(const Comp& _)const {
            return (Comp) { Re - _.Re, Im - _.Im };
        }
        inline Comp operator *(const Comp& _)const {
            return (Comp) { Re* _.Re - Im * _.Im, Re* _.Im + Im * _.Re };
        }
        inline Comp operator *(const double& _)const {
            return (Comp) { Re* _, Im* _ };
        }
    }a[O], b[O], c[O], d[O], w[O];
    int n, Rev[O];
    void DFT(Comp* A, int p) {
        int i, j, k;
        for (i = 0; i < n; i++) {
            if (i < Rev[i]) {
                swap(A[i], A[Rev[i]]);
            }
        }
        w[0] = (Comp){ 1,0 };
        for (i = 1; i < n; i <<= 1) {
            Comp wn = (Comp){ cos(Pi / i),p * sin(Pi / i) };
            for (j = i - 2; j >= 0; j -= 2) {
                w[j] = w[j >> 1];
                w[j + 1] = wn * w[j];
            }
            for (j = 0; j < n; j += (i << 1)) {
                Comp* f = A + j, * g = A + j + i;
                for (k = 0; k < i; k++) {
                    Comp x = w[k] * g[k];
                    g[k] = f[k] - x;
                    f[k] = f[k] + x;
                }
            }
        }
    }
    void Solve(int* A, int* B, long long* C, int m1, int m2) {
        int i, L = -1;
        for (n = 1; n < m1 + m2 - 1; n <<= 1) {
            L++;
        }
        for (i = 0; i < n; i++) {
            Rev[i] = (Rev[i >> 1] >> 1) | ((i & 1) << L);
        }
        memset(a, 0, sizeof(Comp) * 1 * n);
        memset(b, 0, sizeof(Comp) * 1 * n);
        for (i = 0; i < m1; i++) {
            a[i] = (Comp){ (double)(A[i] & 32767),(double)(A[i] >> 15) };
        }
        for (i = 0; i < m2; i++) {
            b[i] = (Comp){ (double)(B[i] & 32767),(double)(B[i] >> 15) };
        }
        DFT(a, 1), DFT(b, 1);
        for (i = 0; i < n; i++) {
            int j = (i == 0 ? 0 : n - i);
            c[j] = (Comp){ a[i].Re + a[j].Re,a[i].Im - a[j].Im }*0.5 * b[i];
            d[j] = (Comp){ a[i].Im + a[j].Im,a[j].Re - a[i].Re }*0.5 * b[i];
        }
        DFT(c, 1), DFT(d, 1);
        for (i = 0; i < n; i++) {
            long long x = round(c[i].Re / n);
            long long y = round(c[i].Im / n);
            long long u = round(d[i].Re / n);
            long long v = round(d[i].Im / n);
            C[i] = (x + ((y + u) << 15) + (v << 30));
        }
    }
};