class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int total_distance=0;
        while(mainTank>=5&&additionalTank!=0){
            total_distance+=50;
            mainTank-=5;
            additionalTank--;
            mainTank+=1;
        }
        total_distance=total_distance+mainTank*10;
        return total_distance;
    }
};