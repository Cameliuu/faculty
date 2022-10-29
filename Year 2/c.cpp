#include<iostream>

int getReverse(int x)
    {
        int v=0,p=1;
        while(x>0)
        {
            v=v*p+x%10;
    	std::cout<<v<<std::endl<<p<<std::endl<<x<<std::endl;
            p*=10;
            x/=10;
        }
        return v;
    };

int main(){
	std::cout<<getReverse(121);
	return 0;
}
