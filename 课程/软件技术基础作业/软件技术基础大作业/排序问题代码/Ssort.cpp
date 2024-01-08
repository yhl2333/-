#include "Ssort.h"


int main()
{
    clock_t startTime1;
    clock_t endTime1;
    clock_t startTime2; 
    clock_t endTime2; 
    clock_t startTime3; 
    clock_t endTime3;
    clock_t startTime4;
    clock_t endTime4;

    Ssort* ssort = new Ssort();


    //vector<int> arr1e3 = ssort->generateRandomArray(1e7);
    cout << "10µÄ7´Î·½¼¶" << endl;

    //startTime3 = clock();
    //ssort->Bubble_sort(arr1e3);
    //endTime3 = clock();
    //cout << "The Ã°ÅÝÅÅÐò run time is: " << (double)(endTime3 - startTime3) / CLOCKS_PER_SEC << "s" << endl;

    ////²åÈëÅÅÐò
    //vector<int> arr1e1 = ssort->generateRandomArray(1e5);
    //startTime1 = clock();
    //ssort->Insert_sort(arr1e1);
    //endTime1 = clock();
    //cout << "The ²åÈëÅÅÐò run time is: " << (double)(endTime1 - startTime1) / CLOCKS_PER_SEC << "s" << endl;


    vector<int> arr1e2 = ssort->generateRandomArray(1e7);
    startTime2 = clock();
    ssort->Shell_sort(arr1e2);
    endTime2 = clock();
    cout << "The Ï£¶ûÅÅÐò run time is: " << (double)(endTime2 - startTime2) / CLOCKS_PER_SEC << "s" << endl;


    vector<int> arr1e4 = ssort->generateRandomArray(1e7);
    startTime4 = clock();
    ssort->Quick_sort(arr1e4);
    endTime4 = clock();
    cout << "The ¿ìËÙÅÅÐò run time is: " << (double)(endTime4 - startTime4) / CLOCKS_PER_SEC << "s" << endl;

    cout << "10µÄ8´Î·½¼¶" << endl;

    vector<int> arr1e1 = ssort->generateRandomArray(1e8);
    startTime2 = clock();
    ssort->Shell_sort(arr1e1);
    endTime2 = clock();
    cout << "The Ï£¶ûÅÅÐò run time is: " << (double)(endTime2 - startTime2) / CLOCKS_PER_SEC << "s" << endl;


    vector<int> arr1e3 = ssort->generateRandomArray(1e8);
    startTime4 = clock();
    ssort->Quick_sort(arr1e3);
    endTime4 = clock();
    cout << "The ¿ìËÙÅÅÐò run time is: " << (double)(endTime4 - startTime4) / CLOCKS_PER_SEC << "s" << endl;




}