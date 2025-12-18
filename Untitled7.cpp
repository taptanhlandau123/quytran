#include <iostream>
#include <cmath>
using namespace std;

int *nhap(int*a,int &n){
	cout<<"Nhap N: ";
	cin >> n;
	a = new int[n];
	for (int i=0;i<n;i++){
		cout<<"a["<<i<<"]=";
		cin >>*(a+i);
	}
	return a;
}
void xuat(int*a,int n){
	cout<<"Cac phan tu cua mang:\n";
	for(int i=0;i<n;i++)
		cout<<" "<<*(a+i);
}
//tim min'
int timmin(int*a,int n){
	int m = *(a);
	for(int i =1;i<n;i++){
		if(m >= *(a+i)) m = *(a+i);
	}
	return m;
}
//TIM MAX
int timmax (int*a,int n){
	int m =*(a);
	for(int i=0;i<n;i++){
		if (m <= *(a+i)) m = *(a+i);
	}
	return m;
}
//Tim vi tri max
void vitriMax(int*a,int n){
	int m = timmax(a,n);
	cout<<"\nVi tri max:";
	for (int i = 0;i<n;i++){
		if (*(a+i) == m) cout<<" "<<i;
	}
}
//Tim vi tri min
void vitriMin(int*a,int n){
	int m = timmin(a,n);
	cout<<"\nVi tri min:";
	for(int i=0;i<n;i++){
		if(*(a+i) == m) cout<<" "<<i;
	}
}
//NHapk,xoa phan tu khoi vi tri k
void xoataiK(int*a,int &n,int k){
	cout<<"\nNhap k:";
	cin>>k;
	if (k<0 || k>=n){
		cout<<"\nk khong hop le";
		return;
	}
	for(int i=k;i<n-1;i++){
		*(a+i) = *(a+i+1);
	}
	n--;
}
//Nhapk, them phan tu x vao sau vi tri k
void themSauK(int *&a, int &n, int k, int x){
	cout<<"\nNhap k:";
	cin>>k;
	
    if(k < 0 || k >= n){
        cout << "\nVi tri k khong hop le!";
        return;
    }
    cout<<"\nNhap x:";
	cin>>x;
    int *b = new int[n + 1];
    for(int i = 0; i <= k; i++)
        *(b + i) = *(a + i);
	
    *(b + k + 1) = x;

    for(int i = k + 1; i < n; i++)
        *(b + i + 1) = *(a + i);
    a = b;
    n++;
}
// Xoa cac phan tu co gia tri = x
void xoaGiaTriX(int *&a, int &n, int x){
	cout << "\n\nNhap X de xoa cac phan tu bang X: ";
    cin >> x;
    for(int i = 0; i < n; i++){
        if(*(a + i) == x){
            xoataiK(a, n, i);
            i--;            
        }
    }
}
//nhap k, them phan tu x vao truoc vi tri k
int main(){
	int *a,n,k,x;
	
	a = nhap(a,n);
	xuat(a,n);
	
	cout<<"\nPhan tu nho nhat:"<<timmin(a,n);
	
	cout<<"\nPhan tu lon nhat:"<<timmax(a,n);
	
	vitriMax(a,n);
	
	vitriMin(a,n);
	
	xoataiK(a,n,k);
	xuat(a,n);
	themSauK(a,n,k,x);
	xuat(a,n);
	xoaGiaTriX(a, n, x);
    xuat(a, n);
	
	return 0;
}
