const double pi=acos(-1);

void fft(vector<complex<double> > &a,bool inv){
    int n=a.size();
    if(n==1) return;

    vector<complex<double> >a0(n>>1),a1(n>>1);
    for(int i=0;i<(n>>1);i++) a0[i]=a[i+i],a1[i]=a[i+i+1];
    fft(a0,inv),fft(a1,inv);

    double theta=(2.0*pi/n)*(inv?-1:1);
    complex<double> w(cos(0),sin(0)),wn(cos(theta),sin(theta));
    for(int i=0;i<(n>>1);i++){
        a[i]=a0[i]+(w*a1[i]);
        a[i+(n>>1)]=a0[i]-(w*a1[i]);
        if(inv) a[i].operator/=(2.0),a[i+(n>>1)].operator/=(2.0);
        w=w*wn;
    }
}

template<typename T,
         typename = typename enable_if<is_arithmetic<T>::value, T>::type>
vector<T> mulPoly(vector<T> const& a,vector<T> const& b){
    vector<complex<double> >fa(a.begin(),a.end()),fb(b.begin(),b.end());
    int n=1;
    while(n<a.size()+b.size()) n<<=1;
    fa.resize(n),fb.resize(n);
    fft(fa,0),fft(fb,0);
    for(int i=0;i<n;i++) fa[i]*=fb[i];
    fft(fa,1);
    vector<T> result(n);
    for(int i=0;i<n;i++) result[i]=(is_same<T, int>::value)?round(fa[i].real()):fa[i].real();
}

vector<int> mulBigInt(vector<int> const& a,vector<int> const& b){
    vector<int> result=mulPoly<int>(a,b);
    int carry=0;
    for(int i=0;i<result.size();i++) result[i]+=carry,carry=(result[i]/10),result[i]%=10;
    return result;
}
