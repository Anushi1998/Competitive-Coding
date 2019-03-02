namespace FFT{
    namespace{
        const int bits=20;
        const int mod=(1<<bits)*7 + 1;
        const int root=5;
        const int rootInv=4404020;
        const double pi=acos(-1);
        int inline mul(int x,int y){int res=(x*1LL*y)%mod;return res<0?res+mod:res;}
        int inline add(int x,int y){int res=(x+y)%mod;return res<0?res+mod:res;}
        int power(int x,int y){
            int res=1; //x^y
            while(y){
                if(y&1) res=mul(res,x);
                x=mul(x,x);
                y=y>>1;
            }
            return res;
        }
    }
    // Recursive FFT Implementation
    void fft(std::vector<std::complex<double> > &a,bool inv){
        int n=a.size();
        if(n==1) return;

        std::vector<std::complex<double> >a0(n>>1),a1(n>>1);
        for(int i=0;i<(n>>1);i++) a0[i]=a[i+i],a1[i]=a[i+i+1];
        fft(a0,inv),fft(a1,inv);

        double theta=(2.0*pi/n)*(inv?-1:1);
        std::complex<double> w(cos(0),sin(0)),wn(cos(theta),sin(theta));
        for(int i=0;i<(n>>1);i++){
            a[i]=a0[i]+(w*a1[i]);
            a[i+(n>>1)]=a0[i]-(w*a1[i]);
            if(inv) a[i].operator/=(2.0),a[i+(n>>1)].operator/=(2.0);
            w=w*wn;
        }
    }

    /** @In-place computation - Iterative
        It requires O(n) space as compared to O(nlogn) in fft, also faster :)
     */
    void FFT(std::vector<std::complex<double> > &a,bool inv){
        int n=a.size(),bit;
        for (int i=1,j=0;i<n;i++) {
            bit=n>>1;
            for(;j&bit;bit>>=1)j^=bit;j^=bit;
            if(i<j) swap(a[i], a[j]);
        }
        for(int len=2;len<n;len<<=1){
            double theta=(2*pi/len)*(inv?-1:1);
            std::complex<double> wn(cos(theta),sin(theta));
            for(int i=0;i<n;i+=len){
                std::complex<double> w(1,0);
                for(int j=i;j<i+(len>>1);j++){
                    std::complex<double> temp=(w*a[j+(len>>1)]);
                    a[j+(len>>1)]=a[j]-temp;a[j]=a[j]+temp;
                    w*=wn;
                }
            }
        }
        if(inv) for(auto &x:a) x.operator/=(n);
    }

    void NTT(std::vector<int> &a,bool inv){
        int n=a.size(),bit;
        for (int i=1,j=0;i<n;i++) {
            bit=n>>1;
            for(;j&bit;bit>>=1)j^=bit;j^=bit;
            if(i<j) std::swap(a[i], a[j]);
        }
        for(int len=2;len<n;len<<=1){
            int wn=(inv)?rootInv:root;
            for(int i=len;i<(1<<bits);i<<=1) wn=mul(wn,wn);
            for(int i=0;i<n;i+=len){
                int w=1;
                for(int j=i;j<i+(len>>1);j++){
                    int temp=mul(w,a[j+(len>>1)]);
                    a[j+(len>>1)]=add(a[j],-temp),a[j]=add(a[j],temp);
                    w=mul(w,wn);
                }
            }
        }
        if(inv) {
            int nInv=power(n,mod-2);
            for(auto &x:a) x=mul(x,nInv);
        }
    }

    namespace Applications{

        template<typename T,
                typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
        std::vector<T> mulPoly(std::vector<T> const& a,std::vector<T> const& b){
            std::vector<std::complex<double> >fa(a.begin(),a.end()),fb(b.begin(),b.end());
            int n=1;
            while(n<a.size()+b.size()) n<<=1;
            fa.resize(n),fb.resize(n);
            FFT::FFT(fa,0),FFT::FFT(fb,0);
            for(int i=0;i<n;i++) fa[i]*=fb[i];
            FFT::FFT(fa,1);
            std::vector<T> result(n);
            for(int i=0;i<n;i++) result[i]=(std::is_same<T, int>::value)?round(fa[i].real()):fa[i].real();
        }

        std::vector<int> mulBigInt(std::vector<int> const& a,std::vector<int> const& b){
            std::vector<int> result=mulPoly<int>(a,b);
            int carry=0;
            for(int i=0;i<result.size();i++) result[i]+=carry,carry=(result[i]/10),result[i]%=10;
            return result;
        }
    }
};
