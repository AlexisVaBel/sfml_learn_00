/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/

//The headers
//#include "SDL2/SDL.h"
//#include "SDL2/SDL_image.h"
#include "game.h"

#include <string>
#include <fstream>
#include <iostream>
#include <list>


//The dimensions of the level
const int LEVEL_WIDTH  = 1280;
const int LEVEL_HEIGHT = 960;

//Tile constants
const int TILE_WIDTH = 80;
const int TILE_HEIGHT = 80;
const int TOTAL_TILES = 192;
const int TILE_SPRITES = 12;

//The different tile sprites
const int TILE_RED = 0;
const int TILE_GREEN = 1;
const int TILE_BLUE = 2;
const int TILE_CENTER = 3;
const int TILE_TOP = 4;
const int TILE_TOPRIGHT = 5;
const int TILE_RIGHT = 6;
const int TILE_BOTTOMRIGHT = 7;
const int TILE_BOTTOM = 8;
const int TILE_BOTTOMLEFT = 9;
const int TILE_LEFT = 10;
const int TILE_TOPLEFT = 11;

const int TOTAL_PARTICLES = 20;

class Solution {
public:

    bool getIsEven(int ival){
        int icnt = 0;
        while(ival > 0){
            ival /= 10;
            std::cout << ival <<std::endl;
            ++icnt;
        }
        std::cout << "ICnt is " << icnt <<std::endl;
        return (icnt % 2) == 0;
    }

    std::vector<int> sortedSquares(std::vector<int>& nums) {
            std::vector<int> nsquares;
            std::vector<int> absSquares;
            nsquares.reserve(nums.size());
            absSquares.reserve(nums.size());

            int ipos = 0;

            for(int i = 0; i < nums.size(); ++i){
                if(nums[i] >= 0) {
                    break;
                }
                else {
                    absSquares.push_back(nums[i]*nums[i]);
                    ++ipos;
                }
            }

            auto itAbs = absSquares.rbegin();
            uint num = 0;


            while (true) {
                if(itAbs != absSquares.rend()){
                    if(ipos >= nums.size()){

                        nsquares.push_back(*itAbs);
                        ++itAbs;
                    }
                    else{
                        num = nums[ipos] * nums[ipos];
                        if(*itAbs < num){
                            nsquares.push_back(*itAbs);
                            ++itAbs;
                        }else
                        {

                            nsquares.push_back(num);
                            ++ipos;
                        }
                    }
                    continue;
                }

                if(ipos >= nums.size()) break;

                num = nums[ipos] * nums[ipos];
                nsquares.push_back(num);
                ++ipos;

            }

            return nsquares;
    }


    void duplicateZeros(std::vector<int>& arr) {
            int arrsize = arr.size();
            std::list<int> tmp;
            bool bFoundZero = false;
            for(int i = 0; i < arrsize; ++i){
                if(bFoundZero){
                    tmp.push_back(arr[i]);
                    arr[i] = tmp.front();
                    tmp.pop_front();
                    bFoundZero = false;
                    continue;
                }

               if(arr[i] == 0){
                   if(i < arrsize - 1){
                       ++i;
                       tmp.push_back(arr[i]);

                       arr[i] = 0;
                       bFoundZero = true;
                   }
               }
            }
    }

    int findNumbers(std::vector<int>& nums) {
        int icnt = 0;
        auto it = nums.begin();
        nums[1];

        while(it != nums.end()){
            if(getIsEven(*it)) ++icnt;
            ++it;
        }
        return icnt;
    }

    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        std::list<int> waitedLst;

        int nums2Cnt   = 0;
        int nums1Cnt   = 0;
        for(int i = 0; i < (m + n) ; ++i){
            if(nums1Cnt < m && nums2Cnt < n){
                if(nums1[nums1Cnt] < nums2[nums2Cnt] ){
                    waitedLst.push_back(nums1[nums1Cnt++]);
                    continue;
                }else{
                    waitedLst.push_back(nums2[nums2Cnt++]);
                    continue;
                }
            }
        }
        while(nums1Cnt < m){
            waitedLst.push_back(nums1[nums1Cnt++]);
        };
        while(nums2Cnt < n){
            waitedLst.push_back(nums2[nums2Cnt++]);
        }

        for(int i = 0; i < (m + n) ; ++i){
            nums1[i] = waitedLst.front();
            waitedLst.pop_front();
        }
    }

    int removeElement(std::vector<int>& nums, int val) {
        nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end());
        nums.shrink_to_fit();
        return nums.size();
    }

    int removeDuplicates(std::vector<int>& nums) {
        auto it = nums.begin();
        auto el = nums.begin();
        while (it != nums.end()) {
            el = it;
            el++;
            while(el != nums.end()){
                if(*el == *it){
                    el = nums.erase(el);
                    continue;
                }
                ++el;
            }
            ++it;
        }
        return nums.size();
    }

    bool checkIfExist(std::vector<int>& arr) {
        //
        auto it = arr.begin();
        auto el = arr.begin();
        while (it != arr.end()) {
            el = it;
            el++;
            while(el != arr.end()){
                if(*it == 2 *(*el) || *el == 2 *(*it)) return  true;
                ++el;
            }
            ++it;
        }
        return false;
    }

    bool validMountainArray(std::vector<int>& arr) {
        if(arr.size() < 3) return false;
        bool asc = true;
        int  prevVal = 0;
        auto it = arr.begin();
        while(it != arr.end()){
            if(it == arr.begin()) prevVal = *it;
            else{
                if(asc) asc = prevVal < *it;
                if((!asc && prevVal <= *it) || ((it-1) == arr.begin() && !asc)) return false;
                prevVal = *it;
            }
            ++it;
        }

        return !asc;
    }

    std::vector<int> replaceElements(std::vector<int>& arr) {
        std::vector<int> someVct;
        someVct.resize((arr.size()));
        int  i = 0;
        auto it = arr.begin();
        auto itend = arr.end();
        --itend;
        int maxres =0;
        while (it != itend) {
            maxres = *(std::max_element(it+1, arr.end()));
            someVct[i++] = maxres;
            ++it;
        }
        someVct[arr.size()-1] = -1;
        return someVct;
    }


    void moveZeroes(std::vector<int>& nums) {
        auto it     = nums.begin();
        auto itZero = it;
        while (it != nums.end()) {
            if(*it == 0){
                itZero = it + 1;
                while ((itZero != nums.end()) && (*itZero == 0)) {
                    ++itZero;
                };
                if(itZero == nums.end()) return;
                *it = *itZero;
                *itZero = 0;
            }
            ++it;
        }
    }

    struct {
        bool operator() (int a, int b) const {
            return ( ((a % 2 == 0) && (b % 2 == 0) && (a < b))
                     ||
                     ((a % 2 == 0) && (b % 2 != 0))
                   );
        }
    } evenNextOdd;

    std::vector<int> sortArrayByParity(std::vector<int>& A) {
        std::vector<int> vct;
        vct.reserve(A.size());
        std::copy(A.begin(), A.end(), std::back_inserter(vct));
        std::sort(vct.begin(), vct.end(), evenNextOdd);
        return  vct;
    }

    int heightChecker(std::vector<int>& heights) {
        std::pair<int, int> valIdx = std::make_pair<int,int>(0,0);
        int iCnt   = 0;
        int prevVal = heights.at(0);
        valIdx.first = 65535;
        for(int i = 1; i < heights.size(); ++i){
            if(heights[i] < prevVal){
                printf("%d < %d got vaidx %d\n", heights[i], prevVal, valIdx.first);
                if(valIdx.first > heights[i]){
                    printf("putting %d with idx %d\n", heights[i-1], i-1);
                    valIdx.first = prevVal;
                    valIdx.second = i-1;
                    ++iCnt;
                }
            }
            prevVal = heights[i];
        }

        return iCnt;
    }




    int thirdMax(std::vector<int>& nums) {
        int imin = -2147483648;
        int arr[3] = {imin, imin, imin};

        int  icnt = 0;
        auto it   = nums.begin();
        bool bFindUnique = false;

        //unique enplacement
        while (it != nums.end() && icnt < 3) {
            arr[icnt] = *it;
            ++it;
            for(int i = 0; i < icnt; ++i){
                if(arr[i] == arr[icnt]) bFindUnique = true;
            }
            if(!bFindUnique)
            ++icnt;
            bFindUnique = false;

        }
        std::sort(std::begin(arr), std::end(arr));

        int tmp, tmp2;

        while (it != nums.end()) {
            if(*it > arr[2]){
               tmp = arr[2];
               arr[2] = *it;
               if(tmp != arr[1]){
                   tmp2 = arr[1];
                   arr[1] = tmp;
                   tmp   = tmp2;
               };
               if(tmp != arr[0]){
                   arr[0] = tmp;
               };

            }else
                if( *it > arr[1] && *it != arr[2]){
                    tmp    = arr[1];
                    arr[1] = *it;

                    if(tmp != arr[0]){
                        arr[0] = tmp;
                    };
                }
                else
                if( *it > arr[0] && *it != arr[1] && *it != arr[2]){
                    arr[0] = *it;
                }
            ++it;
        }


        if(icnt == 3) return  arr[0];
        else
            return arr[2];
    }

};

int main(int argc, char ** argv){    
    Game *game = new Game();
    game->run();
    delete  game;

//      std::vector<int> vct2 = {2,2,3,1};
//    std::vector<int> vct2 = {1,3,1,2};
//    std::vector<int> vct2 = {1,-2147483648,2};
//    std::vector<int> vct2 = { 1,2 , 2, 5, 3,  5};
//    std::vector<int> vct = { 1,1,4,2,1,3};
//    std::vector<int> vct = {-7};
//    Solution slt;
//    std::cout << slt.thirdMax(vct2) << std::endl;

//    for(auto i = 0; i < vct3.size(); ++i){
//        std::cout << vct3[i] << std::endl;
//    }

    return 0;
}
