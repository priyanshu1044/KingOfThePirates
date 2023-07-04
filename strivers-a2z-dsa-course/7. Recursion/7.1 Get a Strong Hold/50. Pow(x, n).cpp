// class Solution {
// public:
//     double myPow(double x, int n) {
//         double res = 1.0;
//         long long nn=n;
//         if(nn<0)nn=-1*nn;
//         while(nn){
//             if(nn%2){//odd power
//                 res=res*x;
//                 nn=nn-1;
//             }else{
//                 x=x*x;
//                 nn/=2;
//             }
//         }
//         if(n<0)res=double(1.0)/double(res);
//         return res;
//     }

// //         while (n) {
// //             if (n % 2) res = n > 0 ? res * x : res / x;
// //             x = x * x;
// //             n /= 2;
// //         }
// //         return res;
// //     }

// };
class Solution {
public:
    double myPow(double x, int n) {
        return myPow(x, 1L * n);
    }
    double myPow(double x, long n) {
            if (n == 0)
                return 1;
            if (n < 0)
                return myPow(1 / x, -n);
            return n % 2 == 0 ? myPow(x * x, n / 2) : x * myPow(x * x, n / 2);
        }
};




        

