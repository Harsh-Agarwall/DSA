#include<iostream>
using namespace std;
class op{
private:
int ios;
public:
    op(int i){
        ios=i;
    }op(){}
op operator + (op const &a){
    op res;
    res.ios=ios/a.ios;
    return res;
}
void display(){
    cout<<ios;
}
};
int main(){
op g(15),h(3);
op k=g+h;
k.display();

    return 0;
}